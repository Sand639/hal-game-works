/*******************************************************************************
* タイトル:		プレイヤープログラム
* プログラム名:	Player.cpp
* 作成者:		大槻海斗
* 作成日:		2024/02/22
********************************************************************************/

//main.cpp以外のすべての.cppでconioexを使うときは#define CONIOEXを追加する
#define CONIOEX

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include <stdio.h>			//標準入出力ヘッダー
#include "conioex.h"		//コンソール系ヘッダー
#include "Player.h"			//プレイヤーヘッダー
#include "PlayerBullet.h"	//弾丸ヘッダー
#include "main.h"			//メインヘッダー
#include "PlayerAnim.h"

/*******************************************************************************
* グローバル変数
*******************************************************************************/

PLAYER P;	//プレイヤー用データ

//プレイヤー形状
const BLOCKSHAPE PlayerShape = {
	3,2,	//幅と高さ
	//形状
	{
		{0,1,0},
		{1,1,1},
		{0,0,0},
	}
};

int BulletShotSE;
int DamageSE;
int HealSE;
int LevelUpSE;

/*******************************************************************************
* プレイヤー初期化関数
*******************************************************************************/
void PlayerInit(void)
{
	BulletShotSE = opensound((char*)"poka02.mp3");
	DamageSE = opensound((char*)"小パンチ.mp3");
	HealSE = opensound((char*)"回復魔法_中.mp3");
	LevelUpSE = opensound((char*)"8bit獲得5.mp3");

	//プレイヤーの初期位置
	P.posx = (FIELD_WIDTH - PlayerShape.width) / 2;
	P.posy = FIELD_HEIGHT / 4 * 3.5;

	//移動前のプレイヤー座標
	P.pos_oldx = P.posx;
	P.pos_oldy = P.posy;

	//プレイヤースピード
	P.speedx = 0.2f;
	P.speedy = 0.2f;

	//プレイヤーHP
	P.MaxHP = 5;
	P.HP = P.MaxHP;

	//フレームリセット
	P.fream = 0;
	P.Dmage_fream = 0;

	//レベルリセット
	P.levelMax = 2;
	P.level = 1;

	textcolor(LIGHTCYAN);

	//初期位置に描画
	ReDrawPlayer();

	textcolor(WHITE);

}

/*******************************************************************************
* プレイヤー終了処理関数
*******************************************************************************/
void PlayerUninit(void)
{
	closesound(BulletShotSE);
	closesound(DamageSE);
	closesound(HealSE);
	closesound(LevelUpSE);
}

/*******************************************************************************
* プレイヤー更新処理関数
*******************************************************************************/
void PlayerUpdate(void)
{
	//前回座標を保存する
	P.pos_oldx = P.posx;
	P.pos_oldy = P.posy;


	/*******************************************************************************
	* WASD移動
	*******************************************************************************/

	//キーボードのAが押された	左
	if (inport(PK_A))
	{
		P.posx -= P.speedx;
	}
	//画面から出ていかない様に補正する
	if (P.posx < SCREEN_LEFT)
	{
		P.posx = SCREEN_LEFT;
	}

	//キーボードのDが押された	右
	if (inport(PK_D))
	{
		P.posx += P.speedx;
	}
	//画面から出ていかない様に補正する
	if (P.posx >= SCREEN_RIGHT - PlayerShape.width)
	{
		P.posx = SCREEN_RIGHT - PlayerShape.width;
	}

	//キーボードのWが押された	上
	if (inport(PK_W))
	{
		P.posy -= P.speedy;
	}
	//画面から出ていかない様に補正する
	if (P.posy < SCREEN_TOP + 1)
	{
		P.posy = SCREEN_TOP + 1;
	}

	//キーボードのSが押された	下
	if (inport(PK_S))
	{
		P.posy += P.speedy;
	}
	//画面から出ていかない様に補正する
	if (P.posy > SCREEN_BOTTOM)
	{
		P.posy = SCREEN_BOTTOM;
	}


	/*******************************************************************************
	*弾丸発射
	*******************************************************************************/
	//スペースキーで弾を発射する
	if (inport(PK_SP) && P.fream > WAITING_TIME)
	{
		//弾丸発射関数をここで呼び出す
		//BulletShot(P.posx, P.posy);

		PBulletShot(P.posx, P.posy);

		playsound(BulletShotSE, 0);

		P.fream = 0;
	}

	P.fream++;
	P.Dmage_fream++;
}

/*******************************************************************************
* プレイヤー描画処理関数
*******************************************************************************/
void PlayerDraw(void)
{
	//もし座標が更新されていたら描画を行う
	if ((floatToInt(P.pos_oldx) != floatToInt(P.posx)) ||
		(floatToInt(P.pos_oldy) != floatToInt(P.posy)))
	{
		//ひとつ前の場所
		for (int y = 0; y < PlayerShape.height; y++)
			for (int x = 0; x < PlayerShape.width; x++)
			{
				if (PlayerShape.pattern[y][x])
				{
					gotoxy(floatToInt(P.pos_oldx) * 2 + x * 2 + 1, floatToInt(P.pos_oldy) + y);
					printf("　");
				}
			}

		textcolor(LIGHTCYAN);

		//現在の場所
		ReDrawPlayer();

		textcolor(WHITE);

	}

	PlayerDrawHP();	//プレイヤーHP描画処理関数

}

/*******************************************************************************
* プレイヤーHP描画処理関数
*******************************************************************************/
void PlayerDrawHP(void)
{
	gotoxy(FIELD_WIDTH * 2 + 1, 2);

	textcolor(LIGHTCYAN);

	printf("プレイヤーHP");

	gotoxy(FIELD_WIDTH * 2 + 1, 3);

	textcolor(YELLOW);

	switch (P.HP)
	{
	case 1:
		printf("★　　　　");
		break;
	case 2:
		printf("★★　　　");
		break;
	case 3:
		printf("★★★　　");
		break;
	case 4:
		printf("★★★★　");
		break;
	case 5:
		printf("★★★★★");
		break;
	}

	textcolor(WHITE);
}

/*******************************************************************************
* プレイヤーダメージ計算関数
*******************************************************************************/
void PlayerDamage(void)
{
	if (P.Dmage_fream <= 20)
		return;

	playsound(DamageSE, 0);

	PAnimStart(P.posx, P.posy);

	//プレイヤーのヒットポイントが1減る
	P.HP--;

	P.Dmage_fream = 0;
}


/*******************************************************************************
* プレイヤーHP取得関数
*******************************************************************************/
int PlayerGetHP(void)
{
	//現在のHPを返す
	return P.HP;
}

/*******************************************************************************
* プレイヤーHP回復処理関数
*******************************************************************************/
void PlayerHeal(void)
{
	playsound(HealSE, 0);

	P.HP += 3;
	if (P.HP > P.MaxHP)
	{
		P.HP = P.MaxHP;
	}
}

/*******************************************************************************
* プレイヤーレベル取得関数
*******************************************************************************/
int PlayerGetLevel(void)
{
	//プレイヤーのレベルを返す
	return P.level;
}

/*******************************************************************************
* プレイヤーレベルアップ関数
*******************************************************************************/
void PlayerLevelUp(void)
{
	playsound(LevelUpSE, 0);

	//プレイヤーのレベルがマックスなら音だけ鳴らす
	if (P.level == P.levelMax)
		return;

	//プレイヤーのレベルが1上がる
	P.level++;
}


/*******************************************************************************
* プレイヤーデータ取得関数
*******************************************************************************/
PLAYER* GetPlayer(void)
{
	return &P;
}

/*******************************************************************************
* プレイヤー形状取得関数
*******************************************************************************/
const BLOCKSHAPE* GetPlayerShape(void) {
	return &PlayerShape;
}

/*******************************************************************************
* プレイヤー再描画関数
*******************************************************************************/
void ReDrawPlayer(void)
{
	textcolor(LIGHTCYAN);

	for (int y = 0; y < PlayerShape.height; y++)
		for (int x = 0; x < PlayerShape.width; x++)
		{
			if (PlayerShape.pattern[y][x])
			{
				gotoxy(floatToInt(P.posx) * 2 + x * 2 + 1, floatToInt(P.posy) + y);
				printf("■");
			}
		}
}
