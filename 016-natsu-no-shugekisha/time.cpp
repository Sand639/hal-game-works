/*******************************************************************************
* タイトル:		時間アニメーション制御
* プログラム名:	time.cpp
* 作成者:		大槻海斗
* 作成日:		2024/08/23〜
* 更新日		2024/08/23
*******************************************************************************/

/*******************************************************************************
*　インクルードファイル
*******************************************************************************/
#include "main.h"		//メインヘッダー
#include "sprite.h"		//ポリゴン表示ヘッダー
#include "time.h"		//時間表示ヘッダー
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
static SCORE Time;			// スコアアニメーション実体
static ID3D11ShaderResourceView* TextureID[TIME_TYPE_MAX] = {};	//TIME と　数字
static int t = TIME_MAX;

/*******************************************************************************
*　時間アニメーションの　初期化
*******************************************************************************/

void InitTime(void)
{
	Time.pos = XMFLOAT3(935.0f, 25.0f , 0.0f);
	Time.size = XMFLOAT2(50.0f, 50.0f);
	Time.color = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	Time.value = 0;
	Time.use = true;
	t = TIME_MAX;

	//テクスチャ読み込み
	TexMetadata metadata;
	ScratchImage image;

	LoadFromWICFile(L"asset\\texture\\TNum.png", WIC_FLAGS_NONE, &metadata, image);
	//読み込んだ画像データをDirectXへ渡してテクスチャとして管理させる

	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &TextureID[0]);

	//なにか失敗した時に警告を出す
	assert(TextureID[0]);

	LoadFromWICFile(L"asset\\texture\\time.png", WIC_FLAGS_NONE, &metadata, image);
	//読み込んだ画像データをDirectXへ渡してテクスチャとして管理させる

	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &TextureID[1]);

	//なにか失敗した時に警告を出す
	assert(TextureID[1]);
}

/*******************************************************************************
*　時間アニメーションの　更新
*******************************************************************************/
void UpdateTime(void)
{
	if (Time.use)
	{

	}
}

/*******************************************************************************
*　時間アニメーションの　描画
*******************************************************************************/
void DrawTime(void)
{
	// マトリクス設定 
	SetWorldViewProjection2D();

	static int tfream = 0;
	tfream++;

	if (tfream > 60 && Time.use)
	{
		t--;
		tfream = 0;
	}

	if (t <= 0)
	{
		tfream = 0;
		Time.use = false;
		SetScene(SCENE_RESULT);
	}

	int value = t;

	//time画像出力
	GetDeviceContext()->PSSetShaderResources(0, 1, &TextureID[1]);

	static XMFLOAT3 p = XMFLOAT3(Time.pos.x - 130.0f, Time.pos.y, 0.0f);
	static XMFLOAT2 s = XMFLOAT2(150.0f, Time.size.y);

	//ポリゴンの表示
	DrawSprite(p, s, Time.color);


	for (int i = 0; i < TIME_DISIT; i++)
	{
		int num = 0;

		//１の位の数値を取り出す
		num = value % 10;

		//一桁右にずらす
		value /= 10;

		GetDeviceContext()->PSSetShaderResources(0, 1, &TextureID[0]);

		DrawSpriteQuadAnim(
			Time.pos.x - TIME_NUMBER_GAP * i,
			Time.pos.y,
			Time.size.x,
			Time.size.y,
			num % TIME_PATTERN_NUM_W * TIME_PATTERN_SIZE_W,
			num / TIME_PATTERN_NUM_W * TIME_PATTERN_SIZE_H,
			TIME_PATTERN_SIZE_W,
			TIME_PATTERN_SIZE_H
		);
	}


}

/*******************************************************************************
*　時間アニメーションの　終了処理
*******************************************************************************/
void UninitTime(void)
{
	for (int i = 0; i < TIME_TYPE_MAX; i++)
	{
		TextureID[i]->Release();	//テクスチャの解放
	}
}

/*******************************************************************************
*　時間の加算
*******************************************************************************/
void AddTime(int value)
{
	Time.value += value;
}

/*******************************************************************************
*　時間フラグのゲッター
*******************************************************************************/
bool GetTimeUse(void)
{
	//falseでTimeUp
	return Time.use;
}


