/*******************************************************************************
* タイトル:		レベルアップアイテムプログラム
* プログラム名:	bullet.cpp
* 作成者:		大槻海斗
* 作成日:		2024/02/26
********************************************************************************/
#define CONIOEX
/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "ItemHeal.h"	//回復アイテムヘッダー
#include "ItemLevelUp.h"//レベルアップアイテムヘッダー
#include "main.h"		//メインヘッダー
#include "conioex.h"	//コンソール系ヘッダー

/*******************************************************************************
* グローバル変数
*******************************************************************************/
ITEM LI[NUM_LEVEL];	//アイテム用データ

void LevelItemInit(void)
{
	for (int i = 0; i < NUM_LEVEL; i++)
	{
		LI[i].posx = 0;
		LI[i].posy = 0;
		LI[i].pos_oldx = LI[i].posx;
		LI[i].pos_oldy = LI[i].posy;
		LI[i].speedx = 0.0f;
		LI[i].speedy = 0.02f;
		LevelItemDelete(i);
	}
}


void LevelItemUninit(void)
{
	LevelItemInit();
}


void LevelItemUpdate(void)
{
	for (int i = 0; i < NUM_LEVEL; i++)
	{
		//前回値の保存
		LI[i].pos_oldx = LI[i].posx;
		LI[i].pos_oldy = LI[i].posy;

		//アイテムの座標更新
		if (LI[i].use == 1)
		{
			LI[i].posy += LI[i].speedy;
		}
	}
}


void LevelItemDraw(void)
{
	for (int i = 0; i < NUM_LEVEL; i++)
	{
		if (LI[i].use == 1)
		{
			//下の壁よりアイテムの座標が大きくなった
			if (floatToInt(LI[i].posy) > SCREEN_BOTTOM)
			{
				LevelItemDelete(i);	//壁に当たったのでアイテムを消す
			}
			else
			{
				//もし座標が更新されていたら描画を行う
				if ((floatToInt(LI[i].pos_oldx) != floatToInt(LI[i].posx)) ||
					(floatToInt(LI[i].pos_oldy) != floatToInt(LI[i].posy)))
				{
					//ひとつ前の場所
					gotoxy(floatToInt(LI[i].pos_oldx) * 2 + 1, floatToInt(LI[i].pos_oldy));
					printf("　");

					textcolor(LIGHTGREEN);

					//現在の場所
					gotoxy(floatToInt(LI[i].posx) * 2 + 1, floatToInt(LI[i].posy));
					printf("＊");

					textcolor(WHITE);
				}
			}
		}
	}
}

void LevelItemCreate(float x, float y)
{
	for (int i = 0; i < NUM_LEVEL; i++)
	{
		//アイテムが使用中の場合は実行しない
		if (LI[i].use == 0)
		{
			LI[i].use = 1;				//弾のステータスを発射中に変更する
			LI[i].posx = floatToInt(x);	//プレイヤーのx座標を取得
			LI[i].posy = floatToInt(y);	//プレイヤーのy座標を取得

			textcolor(LIGHTGREEN);

			//現在の場所
			gotoxy(floatToInt(LI[i].posx) * 2 + 1, floatToInt(LI[i].posy));
			printf("＊");

			textcolor(WHITE);

			break;	//アイテムを作ったらループを抜ける
		}
	}
}

void LevelItemDelete(int id)
{
	//生存フラグをオフにする
	LI[id].use = 0;

	//ひとつ前の場所
	gotoxy(floatToInt(LI[id].pos_oldx) * 2 + 1, floatToInt(LI[id].pos_oldy));
	printf("　");
}


//g_Item[]のゲッター関数
ITEM* GetLevelItem()
{
	return LI;
}

