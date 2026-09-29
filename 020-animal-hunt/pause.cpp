/*******************************************************************************
* タイトル:		ポーズ画像制御
* プログラム名:	pause.cpp
* 作成者:		大槻海斗
* 作成日:		2024/08/28〜
* 更新日		2024/08/28
*******************************************************************************/

/*******************************************************************************
*　インクルードファイル
*******************************************************************************/
#include "main.h"
#include "keyboard.h"
#include "sprite.h"
#include "pause.h"//ポーズ画像制御
#include "game.h"		//ゲームシーンヘッダー
#include "BG.h"
#include "manager.h"


/*******************************************************************************
*　グローバル変数
*******************************************************************************/
static BG pause[PAUSE_MAX];				//画像の実体
static int choiceNum = 0;

/*******************************************************************************
*　画像　初期化
*******************************************************************************/
void InitPause(void)
{
	//現在の選択している番号
	choiceNum = 0;

	//背景
	pause[0].col = XMFLOAT4(0.0f, 0.0f, 0.3f, 0.4f);

	//ポーズ画像
	pause[1].pos = XMFLOAT3(SCREEN_WIDTH / 2, 150.0f, 0.0f);
	pause[1].size = XMFLOAT2(500.0f, 200.0f);

	//ゲームをつづける01
	pause[2].pos = XMFLOAT3(SCREEN_WIDTH / 2, 350.0f, 0.0f);
	pause[2].size = XMFLOAT2(500.0f, 150.0f);

	//ゲームをつづける02
	pause[3].pos = XMFLOAT3(SCREEN_WIDTH / 2, 350.0f, 0.0f);
	pause[3].size = XMFLOAT2(500.0f, 150.0f);
	pause[3].use = true;

	//はじめからやりなおす01
	pause[4].pos = XMFLOAT3(SCREEN_WIDTH / 2, 500.0f, 0.0f);
	pause[4].size = XMFLOAT2(500.0f, 150.0f);

	//はじめからやりなおす02
	pause[5].pos = XMFLOAT3(SCREEN_WIDTH / 2, 500.0f, 0.0f);
	pause[5].size = XMFLOAT2(500.0f, 150.0f);
	pause[5].use = false;

	//ゲームをやめる01
	pause[6].pos = XMFLOAT3(SCREEN_WIDTH / 2, 650.0f, 0.0f);
	pause[6].size = XMFLOAT2(500.0f, 150.0f);

	//ゲームをやめる02
	pause[7].pos = XMFLOAT3(SCREEN_WIDTH / 2, 650.0f, 0.0f);
	pause[7].size = XMFLOAT2(500.0f, 150.0f);
	pause[7].use = false;

	//テクスチャ読み込み
	TexMetadata metadata;
	ScratchImage image;

	//背景
	LoadFromWICFile(L"asset\\texture\\White.png", WIC_FLAGS_NONE, &metadata, image);
	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &pause[0].TextureID);
	assert(pause[0].TextureID);

	//ポーズ画像
	LoadFromWICFile(L"asset\\texture\\ポーズ.png", WIC_FLAGS_NONE, &metadata, image);
	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &pause[1].TextureID);
	assert(pause[1].TextureID);

	//ゲームをつづける01
	LoadFromWICFile(L"asset\\texture\\ゲームをつづける01.png", WIC_FLAGS_NONE, &metadata, image);
	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &pause[2].TextureID);
	assert(pause[2].TextureID);

	//ゲームをつづける02
	LoadFromWICFile(L"asset\\texture\\ゲームをつづける02.png", WIC_FLAGS_NONE, &metadata, image);
	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &pause[3].TextureID);
	assert(pause[3].TextureID);

	//はじめからやりなおす01
	LoadFromWICFile(L"asset\\texture\\はじめからやりなおす01.png", WIC_FLAGS_NONE, &metadata, image);
	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &pause[4].TextureID);
	assert(pause[4].TextureID);

	//はじめからやりなおす02
	LoadFromWICFile(L"asset\\texture\\はじめからやりなおす02.png", WIC_FLAGS_NONE, &metadata, image);
	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &pause[5].TextureID);
	assert(pause[5].TextureID);

	//ゲームをやめる01
	LoadFromWICFile(L"asset\\texture\\ゲームをやめる01.png", WIC_FLAGS_NONE, &metadata, image);
	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &pause[6].TextureID);
	assert(pause[6].TextureID);

	//ゲームをやめる02
	LoadFromWICFile(L"asset\\texture\\ゲームをやめる02.png", WIC_FLAGS_NONE, &metadata, image);
	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &pause[7].TextureID);
	assert(pause[7].TextureID);

}

/*******************************************************************************
*　画像　更新
*******************************************************************************/
void UpdatePause(void)
{
	bool input = false;

	if (Keyboard_IsKeyDownTrigger(KK_W) || Keyboard_IsKeyDownTrigger(KK_UP))
	{
		if (choiceNum > 0)
		{
			choiceNum--;
			input = true;
		}
	}
	else if (Keyboard_IsKeyDownTrigger(KK_S) || Keyboard_IsKeyDownTrigger(KK_DOWN))
	{
		if (choiceNum < CHOICE_MAX - 1)
		{
			choiceNum++;
			input = true;
		}
	}

	//ここのポーズ画面で選択肢表示
	//選択しているところは光らせたりなんかする
	if (input)
	{
		pause[3].use = false;
		pause[5].use = false;
		pause[7].use = false;

		switch (choiceNum)
		{
		case 0:
			pause[3].use = true;
			break;
		case 1:
			pause[5].use = true;
			break;
		case 2:
			pause[7].use = true;
			break;
		default: break;
		}
	}


	if (Keyboard_IsKeyDownTrigger(KK_ENTER))
	{
		//機能ごとに操作を追加
		switch (choiceNum)
		{
		case 0:		//つづきから
			PauseFalse();
			break;

		case 1:		//やりなおす
			UninitGame();
			InitGame();
			break;

		case 2:		//ゲームをやめる
			exit(0);
			break;

		default:break;
		}
	}


}

/*******************************************************************************
*　画像　描画
*******************************************************************************/
void DrawPause(void)
{
	for (int i = 0; i < PAUSE_MAX; i++)
	{
		if (!pause[i].use)
			continue;

		// マトリクス設定 
		SetWorldViewProjection2D();

		//使用するテクスチャをセット
		GetDeviceContext()->PSSetShaderResources(0, 1, &pause[i].TextureID);

		//ポリゴンの表示
		DrawSprite(pause[i].pos, pause[i].size, pause[i].col);

	}
}

/*******************************************************************************
*　画像　終了処理
*******************************************************************************/
void UninitPause(void)
{

}
