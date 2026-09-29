/*******************************************************************************
* タイトル:		ボスプログラム
* プログラム名:	EnemyBoss.cpp
* 作成者:		大槻海斗
* 作成日:		2024/02/25
********************************************************************************/
#define CONIOEX
/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include <stdio.h>		//標準入出力ヘッダー
#include "EnemyBoss.h"	//ボスヘッダー
#include "main.h"		//メインヘッダー
#include "conioex.h"	//コンソール系ヘッダー
#include "EnemyBossAnim.h"
#include "EnemyBossBullet.h"
#include "Scene.h"

/*******************************************************************************
* グローバル変数
*******************************************************************************/

BOSS Boss;		//敵用データ

//敵形状
const BOSSSHAPE BossShape = {
	BOSS_WIDTH,BOSS_HEIGHT,	//幅と高さ
	//形状
	{
		{0,0,0,0,0,2,0,0,0,0,0},
		{0,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,1,1,1,0,0,0,0},
		{0,0,1,1,3,3,3,1,1,0,0},
		{0,1,3,3,3,3,3,3,3,1,0},
		{1,3,3,3,3,3,3,3,3,3,1},
		{1,1,1,1,1,1,1,1,1,1,1},
		{0,1,2,2,1,0,1,2,2,1,0},
		{0,0,1,1,0,0,0,1,1,0,0}
	}
};

int BreakBossSE;

/*******************************************************************************
* ボス初期化関数
*******************************************************************************/
void BossInit(void)
{
	BreakBossSE = opensound((char*)"mini_bomb1.mp3");

	//ボスのx座標を万名kにセット
	Boss.posx = SCREEN_RIGHT / 2 - BOSS_WIDTH / 2;
	//ボスのy座標を上から一個下にセット
	Boss.posy = SCREEN_TOP + 1;

	//移動前のボス座標
	Boss.pos_oldx = Boss.posx;
	Boss.pos_oldy = Boss.posy;

	Boss.use = 2;	//生存フラグ準備中

	Boss.HP = BOSS_HP;

	Boss.fream = 200;	//攻撃までの時間
	Boss.Dmage_fream = 0;
}

/*******************************************************************************
* ボス終了処理関数
*******************************************************************************/
void BossUninit(void)
{
	closesound(BreakBossSE);
}

/*******************************************************************************
* ボス更新処理関数
*******************************************************************************/
void BossUpdate(void)
{
	if (Boss.use == 0 || Boss.use == 2)
		return;

	//ボスの攻撃 これから作成
	if (Boss.fream > 300)
	{
		BossBulletShot();
		Boss.fream = 0;
	}

	Boss.fream++;
	Boss.Dmage_fream++;
}

/*******************************************************************************
* ボス描画処理関数
*******************************************************************************/
void BossDraw(void)
{
	if (Boss.use == 0 || Boss.use == 2)
		return;

	//もし座標が更新されていたら描画を行う
	if ((floatToInt(Boss.pos_oldx) != floatToInt(Boss.posx)) ||
		(floatToInt(Boss.pos_oldy) != floatToInt(Boss.posy)))
	{
		//ひとつ前の場所
		for (int y = 0; y < BossShape.height; y++)
			for (int x = 0; x < BossShape.width; x++)
				switch (BossShape.pattern[y][x])
				{
				case 1:
				case 2:
				case 3:
					gotoxy(floatToInt(Boss.pos_oldx) * 2 + x * 2 + 1, floatToInt(Boss.pos_oldy) + y);
					printf("　");
				default:
					break;
				}

		//現在の場所
		ReDrawBoss();
	}
	else
	{
		ReDrawBoss();
	}
}


/*******************************************************************************
* ボス削除関数
*******************************************************************************/
void BossDelete(void)
{
	//生存フラグをオフにする
	Boss.use = 0;

	//敵の表示を強制的に削除
	for (int y = 0; y < BossShape.height; y++)
		for (int x = 0; x < BossShape.width; x++)
			switch (BossShape.pattern[y][x])
			{
			case 1:
			case 2:
			case 3:
				gotoxy(floatToInt(Boss.pos_oldx) * 2 + x * 2 + 1, floatToInt(Boss.pos_oldy) + y);
				printf("　");
			default:
				break;
			}
	playsound(BreakBossSE, 0);
}

/*******************************************************************************
* ボスデータ取得関数
*******************************************************************************/
BOSS* GetBoss()
{
	return &Boss;
}

/*******************************************************************************
* ボス生存数取得関数
*******************************************************************************/
int BossGetLive(void)
{
	//bossが生きてるか返す
	return Boss.use;
}

/*******************************************************************************
* ボス生存フラグオン関数
*******************************************************************************/
void BossFlagON(void)
{
	Boss.use = 1;

	ReDrawBoss();
}

/*******************************************************************************
* ボスダメージ計算関数
*******************************************************************************/
void BossDamage(void)
{
	if (Boss.Dmage_fream <= 20)
		return;

	//playsound();	//ボスのダメージ音

							//スコアを追加
	AddScore(100);

	Boss.HP--;

	BossAnimStart(Boss.posx, Boss.posy);

	if (Boss.HP <= 0)
	{
		//ボスの破壊音

		BossDelete();
		return;
	}

	Boss.Dmage_fream = 0;
}


/*******************************************************************************
* ボス形状取得関数
*******************************************************************************/
const BOSSSHAPE* GetBossShape(void) {
	return &BossShape;
}

/*******************************************************************************
* ボス再描画関数
*******************************************************************************/
void ReDrawBoss(void)
{
	for (int y = 0; y < BossShape.height; y++)
		for (int x = 0; x < BossShape.width; x++)
		{
			switch (BossShape.pattern[y][x])
			{
			case 1:
				textcolor(DARKGRAY);
				gotoxy(floatToInt(Boss.posx) * 2 + x * 2 + 1, floatToInt(Boss.posy) + y);
				printf("■");
				break;
			case 2:
				textcolor(YELLOW);
				gotoxy(floatToInt(Boss.posx) * 2 + x * 2 + 1, floatToInt(Boss.posy) + y);
				printf("■");
				break;
			case 3:
				textcolor(LIGHTGRAY);
				gotoxy(floatToInt(Boss.posx) * 2 + x * 2 + 1, floatToInt(Boss.posy) + y);
				printf("■");
			default:
				break;
			}

			textcolor(WHITE);
		}
}