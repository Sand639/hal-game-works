/*******************************************************************************
* タイトル:		タイトルシーンのバックグラウンド制御ヘッダー
* プログラム名:	resultBG.cpp
* 作成者:		大槻海斗
* 作成日:		2024/06/10〜
* 更新日		2024/07/08
********************************************************************************/

/*******************************************************************************
*　インクルードファイル
*******************************************************************************/
#include "main.h"
#include "sprite.h"
#include "BG.h"
#include "resultBG.h"
#include "keyboard.h"
#include "manager.h"


/*******************************************************************************
*　グローバル変数
*******************************************************************************/
static BG resultBG[5];
static int choiceNum = 0;

/*******************************************************************************
*　初期化
*******************************************************************************/
void InitResultBG()
{

	//現在の選択している番号
	choiceNum = 0;

	//ゲームをはじめる01
	resultBG[1].pos = XMFLOAT3(SCREEN_WIDTH / 2 - 300.0f, 600.0f, 0.0f);
	resultBG[1].size = XMFLOAT2(500.0f, 200.0f);

	//ゲームをはじめる02
	resultBG[2].pos = XMFLOAT3(SCREEN_WIDTH / 2 - 300.0f, 600.0f, 0.0f);
	resultBG[2].size = XMFLOAT2(500.0f, 200.0f);
	resultBG[2].use = true;

	//ゲームをやめる01
	resultBG[3].pos = XMFLOAT3(SCREEN_WIDTH / 2 + 300.0f, 600.0f, 0.0f);
	resultBG[3].size = XMFLOAT2(500.0f, 200.0f);

	//ゲームをやめる02
	resultBG[4].pos = XMFLOAT3(SCREEN_WIDTH / 2 + 300.0f, 600.0f, 0.0f);
	resultBG[4].size = XMFLOAT2(500.0f, 200.0f);
	resultBG[4].use = false;


	//テクスチャ読み込み
	//Windows Imaging Componentで対応する画像(bmp,png,jpg)などを読み込む
	TexMetadata metadata;
	ScratchImage image;

	LoadFromWICFile(L"asset\\texture\\RBG.png", WIC_FLAGS_NONE, &metadata, image);
	//読み込んだ画像データをDirectXへ渡してテクスチャとして管理させる

	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &resultBG[0].TextureID);

	//なにか失敗した時に警告を出す
	assert(resultBG[0].TextureID);


	//ゲームをはじめる01
	LoadFromWICFile(L"asset\\texture\\ゲームをはじめる01.png", WIC_FLAGS_NONE, &metadata, image);
	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &resultBG[1].TextureID);
	assert(resultBG[1].TextureID);

	//ゲームをはじめる02
	LoadFromWICFile(L"asset\\texture\\ゲームをはじめる02.png", WIC_FLAGS_NONE, &metadata, image);
	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &resultBG[2].TextureID);
	assert(resultBG[2].TextureID);

	//ゲームをやめる01
	LoadFromWICFile(L"asset\\texture\\ゲームをやめる01.png", WIC_FLAGS_NONE, &metadata, image);
	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &resultBG[3].TextureID);
	assert(resultBG[3].TextureID);

	//ゲームをやめる02
	LoadFromWICFile(L"asset\\texture\\ゲームをやめる02.png", WIC_FLAGS_NONE, &metadata, image);
	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &resultBG[4].TextureID);
	assert(resultBG[4].TextureID);

}

/*******************************************************************************
*　描画
*******************************************************************************/
void DrawResultBG()
{
	// マトリクス設定 
	SetWorldViewProjection2D();

	bool input = false;

	if (Keyboard_IsKeyDownTrigger(KK_A) || Keyboard_IsKeyDownTrigger(KK_LEFT))
	{
		if (choiceNum > 0)
		{
			choiceNum--;
			input = true;
		}
	}
	else if (Keyboard_IsKeyDownTrigger(KK_D) || Keyboard_IsKeyDownTrigger(KK_RIGHT))
	{
		if (choiceNum < 1)
		{
			choiceNum++;
			input = true;
		}
	}

	//ここのポーズ画面で選択肢表示
	//選択しているところは光らせたりなんかする
	if (input)
	{
		resultBG[2].use = false;
		resultBG[4].use = false;


		switch (choiceNum)
		{
		case 0:
			resultBG[2].use = true;
			break;
		case 1:
			resultBG[4].use = true;
			break;
		default:break;
		}
	}


	if (Keyboard_IsKeyDownTrigger(KK_ENTER))
	{
		//機能ごとに操作を追加
		switch (choiceNum)
		{
		case 0:		//はじめる
			SetScene(SCENE_GAME);
			break;

		case 1:		//ゲームをやめる
			exit(0);
			break;
		default:break;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (!resultBG[i].use)
			continue;

		// マトリクス設定 
		SetWorldViewProjection2D();

		//使用するテクスチャをセット
		GetDeviceContext()->PSSetShaderResources(0, 1, &resultBG[i].TextureID);

		//ポリゴンの表示
		DrawSprite(resultBG[i].pos, resultBG[i].size, resultBG[i].col);

	}


}