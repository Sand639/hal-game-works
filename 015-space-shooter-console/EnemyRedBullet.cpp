/*******************************************************************************
* タイトル:		敵Red弾丸プログラム
* プログラム名:	EnemyRedBullet.cpp
* 作成者:		大槻海斗
* 作成日:		2024/02/24
********************************************************************************/
#define CONIOEX
/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "PlayerBullet1.h"	//弾丸ヘッダー
#include "EnemyRedBullet.h"	//弾丸ヘッダー
#include "main.h"			//メインヘッダー
#include "conioex.h"		//コンソール系ヘッダー
#include "EnemyRed.h"		//敵ヘッダー

/*******************************************************************************
* グローバル変数
*******************************************************************************/

BULLET ERedB[NUM_ENEMY_BULLET];	//敵弾丸用データ

void EnemyRedBulletInit(void)
{
	for (int i = 0; i < NUM_ENEMY_BULLET; i++)
	{
		//弾丸座標をプレイヤーのy座標-1にセットする
		ERedB[i].posx = 0;
		ERedB[i].posy = 0;
		ERedB[i].pos_oldx = ERedB[i].posx;
		ERedB[i].pos_oldy = ERedB[i].posy;
		ERedB[i].speedx = 0.0f;
		ERedB[i].speedy = 0.1f;

		EnemyRedBulletDelete(i);
	}
}

void EnemyRedBulletUninit(void)
{
	EnemyRedBulletInit();
}

void EnemyRedBulletUpdate(void)
{
	for (int i = 0; i < NUM_ENEMY_BULLET; i++)
	{
		//前回値の保存
		ERedB[i].pos_oldx = ERedB[i].posx;
		ERedB[i].pos_oldy = ERedB[i].posy;

		//弾の座標更新
		if (ERedB[i].use == 2)
		{
			ERedB[i].posy += ERedB[i].speedy;
		}
	}
}

void EnemyRedBulletDraw(void)
{
	for (int i = 0; i < NUM_ENEMY_BULLET; i++)
	{
		//1フレーム待つ
		if (ERedB[i].use == 1)
		{
			ERedB[i].use++;
		}
		//弾が発射中であれば描画を行う
		else if (ERedB[i].use == 2)
		{
			//下の壁より弾の座標が小さくなった
			if (floatToInt(ERedB[i].posy) > SCREEN_BOTTOM)
			{
				EnemyRedBulletDelete(i);	//壁に当たったので弾を消す
			}
			else
			{
				//もし座標が更新されていたら描画を行う
				if ((floatToInt(ERedB[i].pos_oldx) != floatToInt(ERedB[i].posx)) ||
					(floatToInt(ERedB[i].pos_oldy) != floatToInt(ERedB[i].posy)))
				{
					//ひとつ前の場所
					gotoxy(floatToInt(ERedB[i].pos_oldx) * 2 + 1, floatToInt(ERedB[i].pos_oldy));
					printf("　");

					textcolor(RED);

					//現在の場所
					gotoxy(floatToInt(ERedB[i].posx) * 2 + 1, floatToInt(ERedB[i].posy));
					printf("||");

					textcolor(WHITE);
				}
			}
		}
	}
}

void EnemyRedBulletShot(float x, float y)
{
	const BLOCKSHAPE* EnemyShape = GetEnemyRedShape();

	for (int i = 0; i < NUM_ENEMY_BULLET; i++)
	{
		//弾が使用中の場合は実行しない
		if (ERedB[i].use == 0)
		{
			ERedB[i].use = 1;										//弾のステータスを発射中に変更する
			ERedB[i].posx = floatToInt(x);							//敵ののx座標を取得
			ERedB[i].posy = floatToInt(y) + EnemyShape->height + 1;	//敵ののy座標を取得

			textcolor(RED);

			//現在の場所
			gotoxy(floatToInt(ERedB[i].posx) * 2 + 1, floatToInt(ERedB[i].posy));
			printf("||");

			textcolor(WHITE);

			break;	//弾を一発撃ったらループを抜ける
		}
	}
}

void EnemyRedBulletDelete(int index)
{
	//弾のステータスを未使用状態に更新する
	ERedB[index].use = 0;

	//弾の表示を強制的に削除
	gotoxy(floatToInt(ERedB[index].pos_oldx) * 2 + 1, floatToInt(ERedB[index].pos_oldy));
	printf("　");
}

//BULLET Bのゲッター関数
BULLET* GetEnemyRedBullet()
{
	return ERedB;
}
