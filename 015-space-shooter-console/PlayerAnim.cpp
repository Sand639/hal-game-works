/*******************************************************************************
* タイトル:		プレイヤーアニメーションプログラム
* プログラム名:	PlayerAnim.cpp
* 作成者:		大槻海斗
* 作成日:		2024/02/22
********************************************************************************/
#define CONIOEX
/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include <stdio.h>			//標準入出力ヘッダー
#include "conioex.h"		//コンソール系ヘッダー
#include "Player.h"			//プレイヤーヘッダー
#include "PlayerBullet.h"	//弾丸ヘッダー
#include "main.h"			//メインヘッダー
#include "EnemyRedAnim.h"	//敵Redアニメーションヘッダー

/*******************************************************************************
* グローバル変数
*******************************************************************************/

ANIMATION PAnim;

/*******************************************************************************
* プレイヤーのアニメーション初期化関数
*******************************************************************************/
void PAnimInit(void)
{
	PAnim.posx = 0;
	PAnim.posy = 0;
	PAnim.frame = 0;
	PAnim.use = 0;
}

/*******************************************************************************
* プレイヤーのアニメーション終了処理関数
*******************************************************************************/
void PAnimUninit(void)
{

}

/*******************************************************************************
* プレイヤーのアニメーション更新処理関数
*******************************************************************************/
void PAnimUpdate(void)
{

}

/*******************************************************************************
* プレイヤーのアニメーション描画処理関数
*******************************************************************************/
void PAnimDraw(void)
{
	if (PAnim.use == 0)
		return;

	const BLOCKSHAPE* PlayerShape = GetPlayerShape();
	PLAYER* P = GetPlayer();

	if (P->HP > 0)
	{
		for (int y = 0; y < PlayerShape->height; y++)
			for (int x = 0; x < PlayerShape->width; x++)
			{
				// プレイヤーの形状が1でなければスキップ
				if (PlayerShape->pattern[y][x] != 1)
					continue;

				//textbackground(RED);
				textcolor(RED);

				gotoxy(floatToInt(PAnim.posx) * 2 + x * 2 + 1, floatToInt(PAnim.posy) + y);

				if (PAnim.frame < 3)
					printf("□");
				else if (PAnim.frame < 6)
					printf("■");
				else if (PAnim.frame < 8)
					printf("□");
			}

		//時間経過で表示を消す
		if (PAnim.frame > 8)
		{
			//useフラグオフ
			PAnim.use = 0;

			//表示削除
			for (int y = 0; y < PlayerShape->height; y++)
				for (int x = 0; x < PlayerShape->width; x++)
				{
					// プレイヤーの形状が1でなければスキップ
					if (PlayerShape->pattern[y][x] != 1)
						continue;

					gotoxy(floatToInt(PAnim.posx) * 2 + x * 2 + 1, floatToInt(PAnim.posy) + y);
					printf("　");

				}

			//再描画
			ReDrawPlayer();
		}
	}
	else
	{
		for (int y = 0; y < PlayerShape->height; y++)
			for (int x = 0; x < PlayerShape->width; x++)
			{
				// プレイヤーの形状が1でなければスキップ
				if (PlayerShape->pattern[y][x] != 1)
					continue;

				textcolor(WHITE);

				gotoxy(floatToInt(PAnim.posx) * 2 + x * 2 + 1, floatToInt(PAnim.posy) + y);

				if (PAnim.frame < 2)
					printf("□");
				else if (PAnim.frame < 4)
					printf("■");
				else if (PAnim.frame < 6)
					printf("□");
				else if (PAnim.frame < 8)
					printf("■");
			}

		//時間経過で表示を消す
		if (PAnim.frame > 8)
		{
			//useフラグオフ
			PAnim.use = 0;

			//表示削除
			for (int y = 0; y < PlayerShape->height; y++)
				for (int x = 0; x < PlayerShape->width; x++)
				{
					// プレイヤーの形状が1でなければスキップ
					if (PlayerShape->pattern[y][x] != 1)
						continue;

					gotoxy(floatToInt(PAnim.posx) * 2 + x * 2 + 1, floatToInt(PAnim.posy) + y);
					printf("　");

				}
		}
	}

	textbackground(BLACK);
	textcolor(WHITE);

	PAnim.frame++;
}

/*******************************************************************************
* プレイヤーのアニメーション開始関数
*******************************************************************************/
void PAnimStart(float x, float y)
{
	if (PAnim.use == 1)
		return;

	PAnim.posx = x;
	PAnim.posy = y;
	PAnim.frame = 0;//経過時間をリセットする
	PAnim.use = 1;//useフラグオン
}