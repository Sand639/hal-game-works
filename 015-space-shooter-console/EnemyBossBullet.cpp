/*******************************************************************************
* タイトル:		boss弾丸プログラム
* プログラム名:	BossBullet.cpp
* 作成者:		大槻海斗
* 作成日:		2024/02/26
********************************************************************************/
#define CONIOEX
/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "PlayerBullet1.h"		//弾丸ヘッダー
#include "main.h"		//メインヘッダー
#include <stdio.h>		//標準入出力ヘッダー
#include "conioex.h"	//コンソール系ヘッダー
#include "EnemyBoss.h"	//敵ヘッダー
#include "EnemyBossBullet.h"


/*******************************************************************************
* グローバル変数
*******************************************************************************/
BULLET BossB[NUM_BULLET][5];

/*******************************************************************************
* 弾丸の初期化関数
*******************************************************************************/
void BossBulletInit(void)
{
	for (int i = 0; i < NUM_BULLET; i++)
		for (int j = 0; j < 5; j++)
		{
			BossB[i][j].posx = (rand() % (SCREEN_RIGHT - SCREEN_LEFT - 1)) + SCREEN_LEFT;
			BossB[i][j].posy = SCREEN_TOP;
			BossB[i][j].pos_oldx = BossB[i][j].posx;
			BossB[i][j].pos_oldy = BossB[i][j].posy;

			BossB[i][j].speedx = (float)((rand() % 1000) + 300) / 5000;
			BossB[i][j].speedy = (float)((rand() % 1000) + 300) / 5000;

			if ((rand() % 2 + 1) == 1)
			{
				BossB[i][j].speedx *= -1;
			}

			BossBulletDelete(i, j);
		}
}

/*******************************************************************************
* 弾丸の終了処理関数
*******************************************************************************/
void BossBulletUninit(void)
{
	BossBulletInit();
}

/*******************************************************************************
* 弾丸の更新処理関数
*******************************************************************************/
void BossBulletUpdate(void)
{
	for (int i = 0; i < NUM_BULLET; i++)
		for (int j = 0; j < 5; j++)
		{
			if (BossB[i][j].use == 0)
				continue;

			//前回値の保存
			BossB[i][j].pos_oldx = BossB[i][j].posx;
			BossB[i][j].pos_oldy = BossB[i][j].posy;

			//弾の座標更新
			if (BossB[i][j].use == 2)
			{
				BossB[i][j].posy += BossB[i][j].speedy;
				BossB[i][j].posx += BossB[i][j].speedx;

				//SCREEN_RIGHTかSCREEN_LEFTで跳ね返る
				if (BossB[i][j].posx > SCREEN_RIGHT || BossB[i][j].posx < SCREEN_LEFT)
				{
					//Xの移動方向を反転させる
					BossB[i][j].speedx *= -1;
				}
			}
		}
}

/*******************************************************************************
* 弾丸の描画処理関数
*******************************************************************************/
void BossBulletDraw(void)
{
	for (int i = 0; i < NUM_BULLET; i++)
		for (int j = 0; j < 5; j++)
		{
			if (BossB[i][j].use == 0)
				continue;

			//1フレーム待つ
			if (BossB[i][j].use == 1)
			{
				BossB[i][j].use++;
			}

			else if (BossB[i][j].use == 2)
			{
				//下の壁に当たったら
				if (BossB[i][j].posy > SCREEN_BOTTOM)
				{
					BossBulletDelete(i , j);
					continue;
				}

				//もし座標が更新されていたら描画を行う
				if ((floatToInt(BossB[i][j].pos_oldx) != floatToInt(BossB[i][j].posx)) ||
					(floatToInt(BossB[i][j].pos_oldy) != floatToInt(BossB[i][j].posy)))
				{
					//ひとつ前の場所
					gotoxy(floatToInt(BossB[i][j].pos_oldx) * 2 + 1, floatToInt(BossB[i][j].pos_oldy));
					printf("　");

					ColorBullet();

					//現在の場所
					gotoxy(floatToInt(BossB[i][j].posx) * 2 + 1, floatToInt(BossB[i][j].posy));
					printf("×");

					textcolor(WHITE);
				}
			}
		}
}

/*******************************************************************************
* 弾丸発射関数
*******************************************************************************/
void BossBulletShot()
{
	for (int i = 0; i < NUM_BULLET; i++)
	{
		//弾が使用中の場合は実行しない
		if (BossB[i][0].use >= 1 || BossB[i][1].use >= 1 || BossB[i][2].use >= 1 ||
			BossB[i][3].use >= 1 || BossB[i][4].use >= 1)
			continue;

		for (int j = 0; j < 5; j++)
		{
			BossB[i][j].use = 1;

			BossB[i][j].posx = (rand() % (SCREEN_RIGHT - SCREEN_LEFT - 1)) + SCREEN_LEFT;
			BossB[i][j].posy = SCREEN_TOP;

			BossB[i][j].speedx = (float)(rand() % 1000) / 5000;
			BossB[i][j].speedy = (float)(rand() % 1000) / 5000;

			if ((rand() % 2 + 1) == 1)
			{
				BossB[i][j].speedx *= -1;
			}

			ColorBullet();

			gotoxy(floatToInt(BossB[i][j].posx) * 2 + 1, floatToInt(BossB[i][j].posy));
			printf("×");

			textcolor(WHITE);
		}

		break;	//弾を一発撃ったらループを抜ける

	}
}

/*******************************************************************************
* 弾丸削除関数
*******************************************************************************/
void BossBulletDelete(int index, int index2)
{
	//弾のステータスを未使用状態に更新する
	BossB[index][index2].use = 0;

	//弾の表示を強制的に削除
	gotoxy(floatToInt(BossB[index][index2].pos_oldx) * 2 + 1, floatToInt(BossB[index][index2].pos_oldy));
	printf("　");

}

/*******************************************************************************
* 弾丸データゲット関数
*******************************************************************************/
//BULLET Bのゲッター関数
BULLET(*GetBossBullet(void))[5]
{
	return BossB;
}

/*******************************************************************************
* 弾丸色変え関数
*******************************************************************************/
void ColorBullet(void)
{ 
	int Random = ((rand() % 15) + 1);

	switch (Random)
	{
	case 1:
		textcolor(WHITE);
		break;
	case 2:
		textcolor(BLUE);
		break;
	case 3:
		textcolor(GREEN);
		break;
	case 4:
		textcolor(CYAN);
		break;
	case 5:
		textcolor(RED);
		break;
	case 6:
		textcolor(MAGENTA);
		break;
	case 7:
		textcolor(BROWN);
		break;
	case 8:
		textcolor(LIGHTGRAY);
		break;
	case 9:
		textcolor(DARKGRAY);
		break;
	case 10:
		textcolor(LIGHTBLUE);
		break;
	case 11:
		textcolor(LIGHTGREEN);
		break;
	case 12:
		textcolor(LIGHTCYAN);
		break;
	case 13:
		textcolor(LIGHTRED);
		break;
	case 14:
		textcolor(LIGHTMAGENTA);
		break;
	case 15:
		textcolor(YELLOW);
		break;
	}
}
