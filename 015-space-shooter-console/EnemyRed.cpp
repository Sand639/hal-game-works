/*******************************************************************************
* タイトル:		敵Redプログラム
* プログラム名:	EnemyRed.cpp
* 作成者:		大槻海斗
* 作成日:		2024/02/22
********************************************************************************/
#define CONIOEX
/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include <stdio.h>		//標準入出力ヘッダー
#include "EnemyRed.h"	//敵Redヘッダー
#include "main.h"		//メインヘッダー
#include "conioex.h"	//コンソール系ヘッダー
#include "EnemyRedBullet.h"

/*******************************************************************************
* グローバル変数
*******************************************************************************/

ENEMY ERed[NUM_ENEMYRED];		//敵用データ

//敵形状
const BLOCKSHAPE EnemyRedShape = {
	1,2,	//幅と高さ
	//形状
	{
		{1,0,0},
		{2,0,0},
		{0,0,0},
	}
};

//一定時間後に敵の生存フラグをオン
int EnemyRed_fream = 0;

//SE
int DamageEnemyRedSE;

/*******************************************************************************
* 敵Red初期化関数
*******************************************************************************/
void EnemyRedInit(void)
{
	DamageEnemyRedSE = opensound((char*)"mini_bomb1.mp3");

	//敵を一番上の列にランダムセットする
	for (int i = 0; i < NUM_ENEMYRED; i++)
	{
		//敵の初期位置
		ERed[i].posx = (rand() % (SCREEN_RIGHT - SCREEN_LEFT - 1)) + SCREEN_LEFT;
		ERed[i].posy = SCREEN_TOP;

		//移動前の敵座標
		ERed[i].pos_oldx = ERed[i].posx;
		ERed[i].pos_oldy = ERed[i].posy;

		//敵スピード
		ERed[i].speedx = 0.005f;
		ERed[i].speedy = 0.01f;

		ERed[i].use = 2;	//生存フラグ準備中

		EnemyRed_fream = 0;//敵フレーム数
	}
}

/*******************************************************************************
* 敵終了処理関数
*******************************************************************************/
void EnemyRedUninit(void)
{
	closesound(DamageEnemyRedSE);
}

/*******************************************************************************
* 敵更新処理関数
*******************************************************************************/
void EnemyRedUpdate(void)
{
	for (int i = 0; i < NUM_ENEMYRED; i++)
	{
		//i番目の敵の生存フラグがオフなら何もしない
		if (ERed[i].use == 0 || ERed[i].use == 2)
			continue;

		//前回座標を保存する
		ERed[i].pos_oldx = ERed[i].posx;
		ERed[i].pos_oldy = ERed[i].posy;

		//エネミー座標をg_Enemy.speedのぶん増やす
		ERed[i].posx += ERed[i].speedx;
		ERed[i].posy += ERed[i].speedy;

		//SCREEN_RIGHTかSCREEN_LEFTで跳ね返る
		if (ERed[i].posx >= SCREEN_RIGHT - EnemyRedShape.width || ERed[i].posx < SCREEN_LEFT)
		{
			//Xの移動方向を反転させる
			ERed[i].speedx *= -1;
		}

		//下の壁(より敵の座標が大きくなった
		if (floatToInt(ERed[i].posy) > SCREEN_BOTTOM)
		{
			EnemyRedDelete(i);
		}

		ERed[i].fream++;

		if (ERed[i].fream > 200)
		{
			EnemyRedBulletShot(ERed[i].posx, ERed[i].posy);
			ERed[i].fream = 0;
		}
	}

	//敵の最大数を超えていないかどうか
	if (EnemyRed_fream <= (NUM_ENEMYRED - 1) * APPEARARCE_TIME)
	{
		//もしEnemy_flagが500になったら敵の生存フラグをオン
		if (EnemyRed_fream % APPEARARCE_TIME == 0)
		{
			FlagON(EnemyRed_fream / APPEARARCE_TIME);

		}
	}

	EnemyRed_fream++;
}

/*******************************************************************************
* 敵描画処理関数
*******************************************************************************/
void EnemyRedDraw(void)
{
	for (int i = 0; i < NUM_ENEMYRED; i++)
	{
		//i番目の敵の生存フラグがオフなら何もしない
		if (ERed[i].use == 0 || ERed[i].use == 2)
			continue;

		//もし座標が更新されていたら描画を行う
		if ((floatToInt(ERed[i].pos_oldx) != floatToInt(ERed[i].posx)) ||
			(floatToInt(ERed[i].pos_oldy) != floatToInt(ERed[i].posy)))
		{
			//ひとつ前の場所
			for (int y = 0; y < EnemyRedShape.height; y++)
				for (int x = 0; x < EnemyRedShape.width; x++)
					switch (EnemyRedShape.pattern[y][x])
					{
					case 1:
					case 2:
						gotoxy(floatToInt(ERed[i].pos_oldx) * 2 + x * 2 + 1, floatToInt(ERed[i].pos_oldy) + y);
						printf("　");
					default:
						break;
					}

			textcolor(RED);

			//現在の場所
			for (int y = 0; y < EnemyRedShape.height; y++)
				for (int x = 0; x < EnemyRedShape.width; x++)
					switch (EnemyRedShape.pattern[y][x])
					{
					case 1:
						gotoxy(floatToInt(ERed[i].posx) * 2 + x * 2 + 1, floatToInt(ERed[i].posy) + y);
						printf("■");
						break;
					case 2:
						gotoxy(floatToInt(ERed[i].posx) * 2 + x * 2 + 1, floatToInt(ERed[i].posy) + y);
						printf("▼");
					default:
						break;
					}

			textcolor(WHITE);

		}
	}
}

/*******************************************************************************
* 敵削除関数
*******************************************************************************/
void EnemyRedDelete(int id)
{
	//生存フラグをオフにする
	ERed[id].use = 0;

	//敵の表示を強制的に削除
	for (int y = 0; y < EnemyRedShape.height; y++)
		for (int x = 0; x < EnemyRedShape.width; x++)
			switch (EnemyRedShape.pattern[y][x])
			{
			case 1:
			case 2:
				gotoxy(floatToInt(ERed[id].pos_oldx) * 2 + x * 2 + 1, floatToInt(ERed[id].pos_oldy) + y);
				printf("　");
			default:
				break;
			}

	playsound(DamageEnemyRedSE, 0);

}

/*******************************************************************************
* 敵データ取得関数
*******************************************************************************/
ENEMY* GetEnemyRed()
{
	return ERed;
}

/*******************************************************************************
* 敵生存数取得関数
*******************************************************************************/
int EnemyRedGetLive(void)
{
	int liveCount = 0;//敵の残り生存数

	for (int i = 0; i < NUM_ENEMYRED; i++)
	{
		if (ERed[i].use != 0)
		{
			//生存数を一つ増やす
			liveCount++;
		}
	}

	//生存数を返す
	return liveCount;
}

/*******************************************************************************
* 敵生存フラグオン関数
*******************************************************************************/
void FlagON(int i)
{
	ERed[i].use = 1;

	textcolor(RED);

	//現在の場所
	for (int y = 0; y < EnemyRedShape.height; y++)
		for (int x = 0; x < EnemyRedShape.width; x++)
			switch (EnemyRedShape.pattern[y][x])
			{
			case 1:
				gotoxy(floatToInt(ERed[i].posx) * 2 + x * 2 + 1, floatToInt(ERed[i].posy) + y);
				printf("■");
				break;
			case 2:
				gotoxy(floatToInt(ERed[i].posx) * 2 + x * 2 + 1, floatToInt(ERed[i].posy) + y);
				printf("▼");
			default:
				break;
			}

	textcolor(WHITE);

}

/*******************************************************************************
* 敵形状取得関数
*******************************************************************************/
const BLOCKSHAPE* GetEnemyRedShape(void) {
	return &EnemyRedShape;
}
