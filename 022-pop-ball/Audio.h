#pragma once

#include <xaudio2.h>
#include <iostream>
#include <list>

void InitAudio();
void UninitAudio();


int LoadAudio(const char* FileName);
void UnloadAudio(int Index);
void PlayAudio(int Index, bool Loop = false);

//void PlayAudio(std::list<int> audioList, bool Loop = false);

class AudioCallback : public IXAudio2VoiceCallback
{
public:
    HANDLE hBufferEndEvent;

    AudioCallback() : hBufferEndEvent(CreateEvent(NULL, FALSE, FALSE, NULL)) {}
    ~AudioCallback() { CloseHandle(hBufferEndEvent); }

    // バッファ終了時のコールバック
    void __stdcall OnBufferEnd(void* pBufferContext) override
    {
        SetEvent(hBufferEndEvent); // イベントをシグナル状態にする
    }

    // 未使用のコールバック
    void __stdcall OnStreamEnd() override {}
    void __stdcall OnVoiceProcessingPassEnd() override {}
    void __stdcall OnVoiceProcessingPassStart(UINT32 BytesRequired) override {}
    void __stdcall OnBufferStart(void* pBufferContext) override {}
    void __stdcall OnLoopEnd(void* pBufferContext) override {}
    void __stdcall OnVoiceError(void* pBufferContext, HRESULT Error) override {}
};