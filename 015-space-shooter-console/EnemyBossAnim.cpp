/*******************************************************************************
* タイトル:		ボスアニメーションプログラム
* プログラム名:	EnemyBossAnim.cpp
* 作成者:		大槻海斗
* 作成日:		2024/02/22
********************************************************************************/
#define CONIOEX
/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include <stdio.h>
#include "conioex.h"
#include "EnemyRedAnim.h"
#include "main.h"
#include "EnemyBoss.h"

/*******************************************************************************
* グローバル変数
*******************************************************************************/
ANIMATION BossAnim;

/*******************************************************************************
* ボスのアニメーション初期化関数
*******************************************************************************/
void BossAnimInit(void)
{
	BossAnim.posx = 0;
	BossAnim.posy = 0;
	BossAnim.frame = 0;
	BossAnim.use = 0;
}

/*******************************************************************************
* Bossのアニメーション終了処理関数
*******************************************************************************/
void BossAnimUninit(void)
{
	const BOSSSHAPE* BossShape = GetBossShape();
	BOSS* Boss = GetBoss();

	//useフラグオフ
	BossAnim.use = 0;

	//表示削除
	for (int y = 0; y < BossShape->height; y++)
		for (int x = 0; x < BossShape->width; x++)
		{
			// プレイヤーの形状が1でなければスキップ
			if (BossShape->pattern[y][x] != 1)
				continue;

			gotoxy(floatToInt(BossAnim.posx) * 2 + x * 2 + 1, floatToInt(BossAnim.posy) + y);
			printf("　");
		}
}

/*******************************************************************************
* Bossのアニメーション更新処理関数
*******************************************************************************/
void BossAnimUpdate(void)
{

}

/*******************************************************************************
* Bossのアニメーション描画処理関数
*******************************************************************************/
void BossAnimDraw(void)
{
	if (BossAnim.use == 0)
		return;

	const BOSSSHAPE* BossShape = GetBossShape();
	BOSS* Boss = GetBoss();

	if (Boss->HP > 0)
	{
		textcolor(RED);

		for (int y = 0; y < BossShape->height; y++)
			for (int x = 0; x < BossShape->width; x++)
				if (BossShape->pattern[y][x])
				{
					gotoxy(floatToInt(BossAnim.posx) * 2 + x * 2 + 1, floatToInt(BossAnim.posy) + y);

					if (BossAnim.frame < 3)
						printf("□");
					else if (BossAnim.frame < 6)
						printf("■");
					else if (BossAnim.frame < 8)
						printf("□");
				}

		//時間経過で表示を消す
		if (BossAnim.frame > 8)
		{
			//useフラグオフ
			BossAnim.use = 0;

			//再描画
			ReDrawBoss();
		}

	}
	else
	{

		textcolor(WHITE);

		for (int y = 0; y < BossShape->height; y++)
			for (int x = 0; x < BossShape->width; x++)
				if (BossShape->pattern[y][x] == 1)
				{
					gotoxy(floatToInt(BossAnim.posx) * 2 + x * 2 + 1, floatToInt(BossAnim.posy) + y);

					if (BossAnim.frame < 4)
						printf("■");

				}

		//時間経過で表示を消す
		if (BossAnim.frame > 4)
		{
			//useフラグオフ
			BossAnim.use = 0;

			//表示削除
			for (int y = 0; y < BossShape->height; y++)
				for (int x = 0; x < BossShape->width; x++)
				{
					// プレイヤーの形状が1でなければスキップ
					if (BossShape->pattern[y][x] != 1)
						continue;

					gotoxy(floatToInt(BossAnim.posx) * 2 + x * 2 + 1, floatToInt(BossAnim.posy) + y);
					printf("　");
				}
		}

	}

	textcolor(WHITE);

	BossAnim.frame++;
}

/*******************************************************************************
* Bossのアニメーション開始関数
*******************************************************************************/
void BossAnimStart(float x, float y)
{
	if (BossAnim.use == 1)
		return;

	BossAnim.posx = x;
	BossAnim.posy = y;
	BossAnim.frame = 0;//経過時間をリセットする
	BossAnim.use = 1;//useフラグオン
}