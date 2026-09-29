/*******************************************************************************
* タイトル:		時間アニメーション制御
* プログラム名:	countTime.cpp
* 作成者:		大槻海斗
* 作成日:		2024/09/05〜
* 更新日		2024/09/05
*******************************************************************************/

/*******************************************************************************
*　インクルードファイル
*******************************************************************************/
#include "manager.h"
#include "sprite.h"		//ポリゴン表示ヘッダー
#include "countTime.h"		//時間表示ヘッダー
#include "score.h"		//スコア表示ヘッダー



/*******************************************************************************
*　マクロ定義
*******************************************************************************/
#define TIME_DISIT (2)					// 時間の桁
#define TIME_NUMBER_GAP (30)					// 間の距離
#define TIME_PATTERN_NUM_W (5)									// 横パターン数
#define TIME_PATTERN_NUM_H (2)									// 縦パターン数
#define TIME_PATTERN_SIZE_W (1.0f / TIME_PATTERN_NUM_W)	// 横パターンサイズ
#define TIME_PATTERN_SIZE_H (1.0f / TIME_PATTERN_NUM_H)	// 縦パターンサイズ

/*******************************************************************************
*　グローバル変数
*******************************************************************************/
static SCORE Time[5];			// スコアアニメーション実体
static ID3D11ShaderResourceView* TextureID[TIME_TYPE_MAX] = {};	//TIME と　数字

/*******************************************************************************
*　時間アニメーションの　初期化
*******************************************************************************/

void InitCountTime(void)
{
	Time[0].pos = XMFLOAT3(1255.0f, 25.0f, 0.0f);
	Time[0].size = XMFLOAT2(50.0f, 50.0f);
	Time[0].color = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	Time[0].value = 0;
	Time[0].use = true;

	Time[1].pos = XMFLOAT3(Time[0].pos.x - 70.0f, 25.0f, 0.0f);
	Time[1].size = XMFLOAT2(50.0f, 50.0f);
	Time[1].color = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	Time[1].value = 0;
	Time[1].use = true;

	Time[2].pos = XMFLOAT3(Time[1].pos.x - 70.0f, 25.0f, 0.0f);
	Time[2].size = XMFLOAT2(50.0f, 50.0f);
	Time[2].color = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	Time[2].value = 0;
	Time[2].use = true;

	Time[3].pos = XMFLOAT3(Time[0].pos.x - 50.0f, 25.0f, 0.0f);
	Time[3].size = XMFLOAT2(30.0f, 30.0f);
	Time[3].color = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	Time[3].value = 0;
	Time[3].use = true;

	Time[4].pos = XMFLOAT3(Time[1].pos.x - 50.0f, 25.0f, 0.0f);
	Time[4].size = XMFLOAT2(30.0f, 30.0f);
	Time[4].color = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	Time[4].value = 0;
	Time[4].use = true;

	//テクスチャ読み込み
	TexMetadata metadata;
	ScratchImage image;

	//数字
	LoadFromWICFile(L"asset\\texture\\TNum.png", WIC_FLAGS_NONE, &metadata, image);
	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &TextureID[0]);
	assert(TextureID[0]);

	//time画像
	LoadFromWICFile(L"asset\\texture\\time.png", WIC_FLAGS_NONE, &metadata, image);
	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &TextureID[1]);
	assert(TextureID[1]);

	//コロン画像
	LoadFromWICFile(L"asset\\texture\\コロン.png", WIC_FLAGS_NONE, &metadata, image);
	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &TextureID[2]);
	assert(TextureID[2]);
}

/*******************************************************************************
*　時間アニメーションの　更新
*******************************************************************************/
void UpdateCountTime(void)
{
	if (Time[0].use)
	{
		static int tfream = 0;
		tfream++;

		if (tfream >= 60 && Time[0].use)	//1秒経過
		{
			Time[0].value++;
			tfream = 0;

			if (Time[0].value >= 60)	//1分経過
			{
				Time[1].value++;
				Time[0].value = 0;

				if (Time[1].value >= 60)	//1時間経過
				{
					Time[2].value++;
					Time[1].value = 0;
				}
			}
		}	
	}
}

/*******************************************************************************
*　時間アニメーションの　描画
*******************************************************************************/
void DrawCountTime(void)
{
	// マトリクス設定 
	SetWorldViewProjection2D();

	//time画像出力
	GetDeviceContext()->PSSetShaderResources(0, 1, &TextureID[1]);

	static XMFLOAT3 p = XMFLOAT3(Time[2].pos.x - 130.0f, Time[2].pos.y, 0.0f);
	static XMFLOAT2 s = XMFLOAT2(150.0f, Time[2].size.y);

	//ポリゴンの表示
	DrawSprite(p, s, Time[2].color);

	//数字出力
	for (int i = 0; i < 3; i++)
	{
		int t = Time[i].value;

		for (int j = 0; j < TIME_DISIT; j++)
		{
			int num = 0;

			//１の位の数値を取り出す
			num = t % 10;

			//一桁右にずらす
			t /= 10;

			GetDeviceContext()->PSSetShaderResources(0, 1, &TextureID[0]);

			DrawSpriteQuadAnim(
				Time[i].pos.x - TIME_NUMBER_GAP * j,
				Time[i].pos.y,
				Time[i].size.x,
				Time[i].size.y,
				num % TIME_PATTERN_NUM_W * TIME_PATTERN_SIZE_W,
				num / TIME_PATTERN_NUM_W * TIME_PATTERN_SIZE_H,
				TIME_PATTERN_SIZE_W,
				TIME_PATTERN_SIZE_H
			);
		}
	}

	//コロンの表示
	GetDeviceContext()->PSSetShaderResources(0, 1, &TextureID[2]);
	DrawSprite(Time[3].pos, Time[3].size, Time[3].color);
	DrawSprite(Time[4].pos, Time[4].size, Time[4].color);
}

/*******************************************************************************
*　時間アニメーションの　終了処理
*******************************************************************************/
void UninitCountTime(void)
{
	for (int i = 0; i < TIME_TYPE_MAX; i++)
	{
		TextureID[i]->Release();	//テクスチャの解放
	}
}
