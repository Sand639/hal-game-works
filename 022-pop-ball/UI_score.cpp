/*******************************************************************************
* タイトル:		スコア(ボールの高さ)の表示
* プログラム名:	UI_score.h
* 作成者:		大槻　海斗
* 作成日:		2025/01/12 〜
* 最終変更日:	2025/01/12
********************************************************************************/
#define NOMINMAX

/********************************************************************************
* インクルードファイル
********************************************************************************/
#include "UI_score.h"
#include "Game_Main.h"
#include "texture.h"
#include "sprite.h"
#include <iostream>
#include <algorithm>


/********************************************************************************
* グローバル定数
********************************************************************************/
static constexpr int SCORE_DISIT = 3;	//スコアの桁
static constexpr float SCORE_NUMBER_GAP = 45.0f;	//数字の間の距離
static constexpr int SCORE_PATTERN_NUM_W = 5;	//横パターン数
static constexpr int SCORE_PATTERN_NUM_H = 2;	//縦パターン数
static constexpr float SCORE_PATTERN_SIZE_W = (1.0f / SCORE_PATTERN_NUM_W);	// 横パターンサイズ
static constexpr float SCORE_PATTERN_SIZE_H = (1.0f / SCORE_PATTERN_NUM_H);	// 縦パターンサイズ

/*******************************************************************************
*　初期化処理
*******************************************************************************/
void Score::Init()
{
	//プレイヤーのポインターを取得
	m_pball = GetBallPointer();
}

/*******************************************************************************
*　終了処理
*******************************************************************************/
void Score::Uninit()
{
	if (m_pball) {
		m_pball = nullptr;
	}
}
/*******************************************************************************
*　更新処理
*******************************************************************************/
void Score::Update()
{
	XMFLOAT3 pos;
	XMStoreFloat3(&pos, m_pball->GetPosition());

	m_score = pos.y;
	m_score = std::max(m_score, 0.0f);
}

/*******************************************************************************
*　描画処理
*******************************************************************************/
void Score::Draw()
{

	XMFLOAT3 pos = { 120.0f, 20.0f,0.0f };

	XMFLOAT2 size = { 50.0f,50.0f };

	int t = (int)m_score;

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
	//メートルの描画
	SetTexture(TextureLoad(L"asset/texture/m.png"));

	pos = { 200.0f, 20.0f,0.0f };
	size = { 50.0f,50.0f };

	DrawSprite(pos, size);

}
