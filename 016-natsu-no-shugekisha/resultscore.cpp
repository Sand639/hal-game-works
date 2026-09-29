/*******************************************************************************
* タイトル:		スコアアニメーション制御
* プログラム名:	score.cpp
* 作成者:		大槻海斗
* 作成日:		2024/06/24〜
* 更新日		2024/07/08
*******************************************************************************/


/*******************************************************************************
*　インクルードファイル
*******************************************************************************/
#include "main.h"		//メインヘッダー
#include "sprite.h"		//ポリゴン表示ヘッダー
#include "score.h"		//スコア表示ヘッダー
#include "resultscore.h"		//スコア表示ヘッダー

/*******************************************************************************
*　マクロ定義
*******************************************************************************/
#define SCORE_DISIT (6)					// スコアの桁
#define SCORE_NUMBER_GAP (60)					// 間の距離
#define SCORE_PATTERN_NUM_W (5)									// 横パターン数
#define SCORE_PATTERN_NUM_H (2)									// 縦パターン数
#define SCORE_PATTERN_SIZE_W (1.0f / SCORE_PATTERN_NUM_W)	// 横パターンサイズ
#define SCORE_PATTERN_SIZE_H (1.0f / SCORE_PATTERN_NUM_H)	// 縦パターンサイズ

/*******************************************************************************
*　グローバル変数
*******************************************************************************/
static SCORE score;			// スコアアニメーション実体
static ID3D11ShaderResourceView* TextureID = NULL;


/*******************************************************************************
*　スコアアニメーションの　初期化
*******************************************************************************/
void InitRScore(void)
{
	score.pos = XMFLOAT3(SCREEN_WIDTH / 2 + 130.0f, SCREEN_HEIGHT / 2, 0.0f);
	score.size = XMFLOAT2(100.0f, 100.0f);
	score.color = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	score.value = GetScore();
	score.use = true;

	//テクスチャ読み込み
	TexMetadata metadata;
	ScratchImage image;

	LoadFromWICFile(L"asset\\texture\\TNum.png", WIC_FLAGS_NONE, &metadata, image);
	//読み込んだ画像データをDirectXへ渡してテクスチャとして管理させる

	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &TextureID);

	//なにか失敗した時に警告を出す
	assert(TextureID);
}

/*******************************************************************************
*　スコアアニメーションの　更新
*******************************************************************************/
void UpdateRScore(void)
{
	if (score.use)
	{

	}
}

/*******************************************************************************
*　スコアアニメーションの　描画
*******************************************************************************/
void DrawRScore(void)
{
	// マトリクス設定 
	SetWorldViewProjection2D();

	if (score.use)
	{
		int value = score.value;

		for (int i = 0; i < SCORE_DISIT; i++)
		{
			int num = 0;

			//１の位の数値を取り出す
			num = value % 10;

			//一桁右にずらす
			value /= 10;

			//使用するテクスチャをセット
			GetDeviceContext()->PSSetShaderResources(0, 1, &TextureID);

			DrawSpriteQuadAnim(
				score.pos.x - SCORE_NUMBER_GAP * i,
				score.pos.y,
				score.size.x,
				score.size.y,
				num % SCORE_PATTERN_NUM_W * SCORE_PATTERN_SIZE_W,
				num / SCORE_PATTERN_NUM_W * SCORE_PATTERN_SIZE_H,
				SCORE_PATTERN_SIZE_W,
				SCORE_PATTERN_SIZE_H
			);

		}
	}
}

/*******************************************************************************
*　スコアアニメーションの　終了処理
*******************************************************************************/
void UninitRScore(void)
{
	TextureID->Release();	//テクスチャの解放
}
