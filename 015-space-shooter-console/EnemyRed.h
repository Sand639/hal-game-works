#pragma once
#include "main.h"
/*******************************************************************************
* マクロ定義
*******************************************************************************/
#define NUM_ENEMYRED (10)		//敵の数を定義する
#define APPEARARCE_TIME (150)	//敵の出現時間

/*******************************************************************************
* 構造体定義
*******************************************************************************/

//敵データ構造体
struct ENEMY
{
	float posx;		//現在のX座標
	float posy;		//現在のY座標
	float pos_oldx;	//前回のX座標
	float pos_oldy;	//前回のY座標

	float speedx;	//横への移動速度
	float speedy;	//縦への移動速度

	int fream;		//弾丸を撃てるまでの時間

	int use;//使用しているか使用していないかのフラグ
};

/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/

void EnemyRedInit(void);		//敵初期化関数
void EnemyRedUninit(void);		//敵終了関数
void EnemyRedUpdate(void);		//敵更新関数
void EnemyRedDraw(void);		//敵描画関数

void EnemyRedDelete(int id);	//敵削除関数

ENEMY* GetEnemyRed();			//敵構造体取得関数

int EnemyRedGetLive(void);		//敵の生存数取得関数
void FlagON(int i);				//敵出現関数

//敵のの形状を取得する関数
const BLOCKSHAPE* GetEnemyRedShape(void);
