/*******************************************************************************
* タイトル:		敵Red死亡アニメーションプログラム
* プログラム名:	EnemyRedAnim.cpp
* 作成者:		大槻海斗
* 作成日:		2024/02/22
********************************************************************************/
#define CONIOEX
/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include <stdio.h>			//標準入出力ヘッダー
#include "conioex.h"		//コンソール系ヘッダー
#include "main.h"			//メインヘッダー
#include "EnemyRed.h"
#include "EnemyRedAnim.h"//敵Red死亡アニメーションヘッダー

/*******************************************************************************
* グローバル変数
*******************************************************************************/

ANIMATION ERedAnim[NUM_ENEMYRED];

/*******************************************************************************
* 敵Redのアニメーション初期化関数
*******************************************************************************/
void EnemyRedAnimInit(void)
{
	for (int i = 0; i < NUM_ENEMYRED; i++)
	{
		ERedAnim[i].posx = 0;
		ERedAnim[i].posy = 0;
		ERedAnim[i].frame = 0;
		ERedAnim[i].use = 0;
	}
}

/*******************************************************************************
* 敵Redのアニメーション終了処理関数
*******************************************************************************/
void EnemyRedAnimUninit(void)
{
	const BLOCKSHAPE* EnemyShape = GetEnemyRedShape();

	for (int i = 0; i < NUM_ENEMYRED; i++)
	{
		//useフラグがオンであれば描画を行う
		if (ERedAnim[i].use == 0)
			continue;

		//useフラグオフ
		ERedAnim[i].use = 0;

		//表示削除
		for (int y = 0; y < EnemyShape->height; y++)
			for (int x = 0; x < EnemyShape->width; x++)
				switch (EnemyShape->pattern[y][x])
				{
				case 1:
				case 2:
					gotoxy(floatToInt(ERedAnim[i].posx) * 2 + x * 2 + 1, floatToInt(ERedAnim[i].posy) + y);
					printf("　");
				default:
					break;
				}
	}
}

/*******************************************************************************
* 敵Redのアニメーション更新処理関数
*******************************************************************************/
void EnemyRedAnimUpdate(void)
{

}

/*******************************************************************************
* 敵Redのアニメーション描画処理関数
*******************************************************************************/
void EnemyRedAnimDraw(void)
{
	const BLOCKSHAPE* EnemyShape = GetEnemyRedShape();

	for (int i = 0; i < NUM_ENEMYRED; i++)
	{
		//useフラグがオンであれば描画を行う
		if (ERedAnim[i].use == 0)
			continue;

		for (int y = 0; y < EnemyShape->height; y++)
			for (int x = 0; x < EnemyShape->width; x++)
				switch (EnemyShape->pattern[y][x])
				{
				case 1:
					gotoxy(floatToInt(ERedAnim[i].posx) * 2 + x * 2 + 1, floatToInt(ERedAnim[i].posy) + y);

					if (ERedAnim[i].frame < 2)
						printf("□");
					else if (ERedAnim[i].frame < 4)
						printf("■");
					else if (ERedAnim[i].frame < 6)
						printf("□");
					else if (ERedAnim[i].frame < 8)
						printf("■");
					else if (ERedAnim[i].frame < 10)
						printf("□");
					else if (ERedAnim[i].frame < 13)
						printf("＊");
					else if (ERedAnim[i].frame < 15)
						printf("―");

					break;
				case 2:
					gotoxy(floatToInt(ERedAnim[i].posx) * 2 + x * 2 + 1, floatToInt(ERedAnim[i].posy) + y);

					if (ERedAnim[i].frame < 2)
						printf("▽");
					else if (ERedAnim[i].frame < 4)
						printf("▼");
					else if (ERedAnim[i].frame < 6)
						printf("▽");
					else if (ERedAnim[i].frame < 8)
						printf("▼");
					else if (ERedAnim[i].frame < 10)
						printf("▽");
					else if (ERedAnim[i].frame < 13)
						printf("＊");
					else if (ERedAnim[i].frame < 15)
						printf("―");

				default:
					break;
				}


		//時間経過
		ERedAnim[i].frame++;

		//時間経過で表示を消す
		if (ERedAnim[i].frame > 15)
		{
			//useフラグオフ
			ERedAnim[i].use = 0;

			//表示削除
			for (int y = 0; y < EnemyShape->height; y++)
				for (int x = 0; x < EnemyShape->width; x++)
					switch (EnemyShape->pattern[y][x])
					{
					case 1:
					case 2:
						gotoxy(floatToInt(ERedAnim[i].posx) * 2 + x * 2 + 1, floatToInt(ERedAnim[i].posy) + y);
						printf("　");
					default:
						break;
					}
		}
	}
}

/*******************************************************************************
* 敵Redのアニメーション開始関数
*******************************************************************************/
void EnemyRedAnimStart(float posx, float posy)
{
	for (int i = 0; i < NUM_ENEMYRED; i++)
	{
		//現在アニメーションを実行していないなら新しくセットする
		if (ERedAnim[i].use == 1)
			continue;

		ERedAnim[i].posx = posx;
		ERedAnim[i].posy = posy;
		ERedAnim[i].frame = 0;//経過時間をリセットする
		ERedAnim[i].use = 1;//useフラグオン

		return;
	}
}