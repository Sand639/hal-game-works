
#include "main.h"
#include "audio.h"
#include <list>
#include <random>
#include <iterator>
#include <thread>




static IXAudio2* g_Xaudio{};
static IXAudio2MasteringVoice* g_MasteringVoice{};


void InitAudio()
{
	// XAudio生成
	XAudio2Create(&g_Xaudio, 0);

	// マスタリングボイス生成
	g_Xaudio->CreateMasteringVoice(&g_MasteringVoice);
}


void UninitAudio()
{
	g_MasteringVoice->DestroyVoice();
	g_Xaudio->Release();
}









struct AUDIO
{
	IXAudio2SourceVoice*	SourceVoice{};
	BYTE*					SoundData{};

	int						Length{};
	int						PlayLength{};
};

#define AUDIO_MAX 100
static AUDIO g_Audio[AUDIO_MAX]{};



int LoadAudio(const char *FileName)
{
	int index = -1;

	for (int i = 0; i < AUDIO_MAX; i++)
	{
		if (g_Audio[i].SourceVoice == nullptr)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
		return -1;




	// サウンドデータ読込
	WAVEFORMATEX wfx = { 0 };

	{
		HMMIO hmmio = NULL;
		MMIOINFO mmioinfo = { 0 };
		MMCKINFO riffchunkinfo = { 0 };
		MMCKINFO datachunkinfo = { 0 };
		MMCKINFO mmckinfo = { 0 };
		UINT32 buflen;
		LONG readlen;


		hmmio = mmioOpen((LPSTR)FileName, &mmioinfo, MMIO_READ);
		assert(hmmio);

		riffchunkinfo.fccType = mmioFOURCC('W', 'A', 'V', 'E');
		mmioDescend(hmmio, &riffchunkinfo, NULL, MMIO_FINDRIFF);

		mmckinfo.ckid = mmioFOURCC('f', 'm', 't', ' ');
		mmioDescend(hmmio, &mmckinfo, &riffchunkinfo, MMIO_FINDCHUNK);

		if (mmckinfo.cksize >= sizeof(WAVEFORMATEX))
		{
			mmioRead(hmmio, (HPSTR)&wfx, sizeof(wfx));
		}
		else
		{
			PCMWAVEFORMAT pcmwf = { 0 };
			mmioRead(hmmio, (HPSTR)&pcmwf, sizeof(pcmwf));
			memset(&wfx, 0x00, sizeof(wfx));
			memcpy(&wfx, &pcmwf, sizeof(pcmwf));
			wfx.cbSize = 0;
		}
		mmioAscend(hmmio, &mmckinfo, 0);

		datachunkinfo.ckid = mmioFOURCC('d', 'a', 't', 'a');
		mmioDescend(hmmio, &datachunkinfo, &riffchunkinfo, MMIO_FINDCHUNK);



		buflen = datachunkinfo.cksize;
		g_Audio[index].SoundData = new unsigned char[buflen];
		readlen = mmioRead(hmmio, (HPSTR)g_Audio[index].SoundData, buflen);


		g_Audio[index].Length = readlen;
		g_Audio[index].PlayLength = readlen / wfx.nBlockAlign;


		mmioClose(hmmio, 0);
	}


 // サウンドソース生成（コールバックを設定）
    static AudioCallback audioCallback;
    HRESULT hr = g_Xaudio->CreateSourceVoice(&g_Audio[index].SourceVoice, &wfx, 0, XAUDIO2_DEFAULT_FREQ_RATIO, &audioCallback);
    assert(SUCCEEDED(hr));

	return index;
}




void UnloadAudio(int Index)
{
	g_Audio[Index].SourceVoice->Stop();
	g_Audio[Index].SourceVoice->DestroyVoice();

	delete[] g_Audio[Index].SoundData;
	g_Audio[Index].SoundData = nullptr;
}





void PlayAudio(int Index, bool Loop)
{
	g_Audio[Index].SourceVoice->Stop();
	g_Audio[Index].SourceVoice->FlushSourceBuffers();


	// バッファ設定
	XAUDIO2_BUFFER bufinfo;

	memset(&bufinfo, 0x00, sizeof(bufinfo));
	bufinfo.AudioBytes = g_Audio[Index].Length;
	bufinfo.pAudioData = g_Audio[Index].SoundData;
	bufinfo.PlayBegin = 0;
	bufinfo.PlayLength = g_Audio[Index].PlayLength;

	// ループ設定
	if (Loop)
	{
		bufinfo.LoopBegin = 0;
		bufinfo.LoopLength = g_Audio[Index].PlayLength;
		bufinfo.LoopCount = XAUDIO2_LOOP_INFINITE;
	}

	g_Audio[Index].SourceVoice->SubmitSourceBuffer(&bufinfo, NULL);


	// 再生
	g_Audio[Index].SourceVoice->Start();

}

// 再生中の曲を追跡するグローバル変数
static int currentAudioIndex = -1;

void PlayAudio(std::list<int> audioList, bool Loop)
{
	static AudioCallback audioCallback;

	// ランダム数生成器
	std::random_device rd;
	std::mt19937 gen(rd());

	// 再生可能な曲がなければ終了
	if (audioList.empty()) {
		std::cerr << "Audio list is empty!" << std::endl;
		return;
	}

	// ランダムに曲を選択し、現在の曲をスキップ
	int randomIndex = -1;
	do {
		std::uniform_int_distribution<size_t> dist(0, audioList.size() - 1);
		auto it = audioList.begin();
		std::advance(it, dist(gen));
		randomIndex = *it;
	} while (randomIndex == currentAudioIndex);

	// 選ばれた曲のインデックスを更新
	currentAudioIndex = randomIndex;

	// 選ばれた曲のバッファを設定
	g_Audio[randomIndex].SourceVoice->Stop();
	g_Audio[randomIndex].SourceVoice->FlushSourceBuffers();

	XAUDIO2_BUFFER bufinfo{};
	bufinfo.AudioBytes = g_Audio[randomIndex].Length;
	bufinfo.pAudioData = g_Audio[randomIndex].SoundData;
	bufinfo.PlayBegin = 0;
	bufinfo.PlayLength = g_Audio[randomIndex].PlayLength;

	if (Loop) {
		bufinfo.LoopBegin = 0;
		bufinfo.LoopLength = g_Audio[randomIndex].PlayLength;
		bufinfo.LoopCount = XAUDIO2_LOOP_INFINITE;
	}

	g_Audio[randomIndex].SourceVoice->SubmitSourceBuffer(&bufinfo, NULL);
	g_Audio[randomIndex].SourceVoice->Start();

	// OnBufferEndで再び呼び出し
	std::thread([audioList, Loop]() {
		WaitForSingleObject(audioCallback.hBufferEndEvent, INFINITE);
		PlayAudio(audioList, Loop); // 次の曲を再生
		}).detach();
}