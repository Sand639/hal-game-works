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
#include "sprite.h"		//ポリゴン表示ヘッダー
#include "UI_time.h"		//時間表示ヘッダー
#include "texture.h"

/********************************************************************************
* グローバル定数
********************************************************************************/
static constexpr int SCORE_DISIT = 2;	//スコアの桁
static constexpr float SCORE_NUMBER_GAP = 30.0f;	//数字の間の距離
static constexpr int SCORE_PATTERN_NUM_W = 5;	//横パターン数
static constexpr int SCORE_PATTERN_NUM_H = 2;	//縦パターン数
static constexpr float SCORE_PATTERN_SIZE_W = (1.0f / SCORE_PATTERN_NUM_W);	// 横パターンサイズ
static constexpr float SCORE_PATTERN_SIZE_H = (1.0f / SCORE_PATTERN_NUM_H);	// 縦パターンサイズ

/*******************************************************************************
*　初期化処理
*******************************************************************************/
void Time::Init()
{
}

/*******************************************************************************
*　終了処理
*******************************************************************************/
void Time::Uninit()
{
	m_millisecond = 0;
	m_second = 0;
	m_minute = 0;
}

/*******************************************************************************
*　更新処理
*******************************************************************************/
void Time::Update()
{
	//時間計算
	if (m_millisecond++ >= 60) {
		m_millisecond = 0;
		if (m_second++ >= 60) {
			m_second = 0;
			m_minute++;
		}
	}


}

/*******************************************************************************
*　描画処理
*******************************************************************************/
void Time::Draw()
{
	// マトリクス設定 
	SetWorldViewProjection2D();

	XMFLOAT3 pos = { SCREEN_WIDTH - 305.0f, 25.0f, 0.0f };
	XMFLOAT2 size = { 150.0f, 50.0f };

	//Time文字列描画

	SetTexture(TextureLoad(L"asset/texture/time.png"));
	DrawSprite(pos, size);


	pos = { SCREEN_WIDTH - 35.0f, 25.0f, 0.0f };
	size = { 50.0f,50.0f };

	//秒数描画
	for (int i = 0; i < 3; i++)
	{
		int t = 0;

		if (i == 0) {
			 t = m_millisecond;
		}
		else if (i == 1) {
			t = m_second;
			pos.x -= 70.0f;
		}
		else {
			t = m_minute;
			pos.x -= 70.0f;
		}

		for (int j = 0; j < SCORE_DISIT; j++)
		{
			int num = 0;

			//１の位の数値を取り出す
			num = t % 10;

			//一桁右にずらす
			t /= 10;

			SetTexture(TextureLoad(L"asset/texture/TNum.png"));

			DrawSpriteQuadAnim(
				pos.x - SCORE_NUMBER_GAP * j,
				pos.y,
				size.x,
				size.y,
				num % SCORE_PATTERN_NUM_W * SCORE_PATTERN_SIZE_W,
				num / SCORE_PATTERN_NUM_W * SCORE_PATTERN_SIZE_H,
				SCORE_PATTERN_SIZE_W,
				SCORE_PATTERN_SIZE_H
			);
		}

	}

	//コロン描画
	SetTexture(TextureLoad(L"asset/texture/コロン.png"));
	DrawSprite({ SCREEN_WIDTH  -85.0f, 25.0f,0.0f},{30.0f,30.0f});
	DrawSprite({ SCREEN_WIDTH - 155.0f, 25.0f,0.0f }, { 30.0f,30.0f });

}
