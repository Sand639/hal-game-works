#pragma once

/*******************************************************************************
* 構造体定義
*******************************************************************************/

//爆発アニメーション構造体
struct ANIMATION
{
	float posx;//現在のX座標
	float posy;//現在のY座標

	int frame;//経過フレーム(時間)

	int use;//使用しているか使用していないかのフラグ
};

/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
void EnemyRedAnimInit(void);
void EnemyRedAnimUninit(void);
void EnemyRedAnimUpdate(void);
void EnemyRedAnimDraw(void);

void EnemyRedAnimStart(float posx, float posy);
