/*******************************************************************************
* タイトル:		三方向弾丸プログラム
* プログラム名:	PlayerBullet2.cpp
* 作成者:		大槻海斗
* 作成日:		2024/02/26
********************************************************************************/
#define CONIOEX
/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "PlayerBullet1.h"	//レベル1弾丸ヘッダー
#include "PlayerBullet2.h"	//レベル2弾丸ヘッダー
#include "main.h"			//メインヘッダー
#include "conioex.h"		//コンソール系ヘッダー

/*******************************************************************************
* グローバル変数
*******************************************************************************/
BULLET PB2[NUM_BULLET][3];	//弾丸用データ

/*******************************************************************************
* 弾丸の初期化関数
*******************************************************************************/
void PlayerBullet2Init(void)
{
	for (int i = 0; i < NUM_BULLET; i++)
		for (int j = 0; j < 3; j++)
		{
			PB2[i][j].posx = 0;
			PB2[i][j].posy = 0;
			PB2[i][j].pos_oldx = PB2[i][j].posx;
			PB2[i][j].pos_oldy = PB2[i][j].posy;
			PB2[i][j].speedx = 0.0f;
			PB2[i][j].use = 0;//最初は表示されていないのでフラグオフ

			//弾のベクトルを指定
			if (j == 0)
			{
				PB2[i][j].speedy = -0.5f;
				PB2[i][j].speedx = -0.5f;
			}
			else if (j == 1)
			{
				PB2[i][j].speedy = -0.5f;
			}
			else if (j == 2)
			{
				PB2[i][j].speedy = -0.5f;
				PB2[i][j].speedx = +0.5f;
			}

			PlayerBullet2Delete(i, j);
		}
}

/*******************************************************************************
* 弾丸の終了処理関数
*******************************************************************************/
void PlayerBullet2Uninit(void)
{
	PlayerBullet2Init();
}

/*******************************************************************************
* 弾丸の更新処理関数
*******************************************************************************/
void PlayerBullet2Update(void)
{
	for (int i = 0; i < NUM_BULLET; i++)
		for (int j = 0; j < 3; j++)
		{
			//前回値の保存
			PB2[i][j].pos_oldx = PB2[i][j].posx;
			PB2[i][j].pos_oldy = PB2[i][j].posy;

			//弾の座標更新
			if (PB2[i][j].use == 2)
			{
				if (j == 0)
				{
					PB2[i][j].posy += PB2[i][j].speedy;
					PB2[i][j].posx += PB2[i][j].speedx;
				}
				else if (j == 1)
				{
					PB2[i][j].posy += PB2[i][j].speedy;
				}
				else if (j == 2)
				{
					PB2[i][j].posy += PB2[i][j].speedy;
					PB2[i][j].posx += PB2[i][j].speedx;
				}
			}
		}
}

/*******************************************************************************
* 弾丸の描画処理関数
*******************************************************************************/
void PlayerBullet2Draw(void)
{
	for (int i = 0; i < NUM_BULLET; i++)
		for (int j = 0; j < 3; j++)
		{
			if (PB2[i][j].use == 0)
				continue;

			//1フレーム待つ
			if (PB2[i][j].use == 1)
			{
				PB2[i][j].use++;
			}

			else if (PB2[i][j].use == 2)
			{
				//上の壁に当たったら
				if (floatToInt(PB2[i][j].posy) < SCREEN_TOP)
				{
					PlayerBullet2Delete(i, j);	//壁に当たったので弾を消す
					continue;
				}
				//左の壁に当たったら
				if (floatToInt(PB2[i][j].posx) <= SCREEN_LEFT)
				{
					PlayerBullet2Delete(i, j);	//壁に当たったので弾を消す
					continue;
				}
				//右の壁に当たったら
				if (floatToInt(PB2[i][j].posx) >= SCREEN_RIGHT)
				{
					PlayerBullet2Delete(i, j);	//壁に当たったので弾を消す
					continue;
				}

				//もし座標が更新されていたら描画を行う
				if ((floatToInt(PB2[i][j].pos_oldx) != floatToInt(PB2[i][j].posx)) ||
					(floatToInt(PB2[i][j].pos_oldy) != floatToInt(PB2[i][j].posy)))
				{
					//ひとつ前の場所
					gotoxy(floatToInt(PB2[i][j].pos_oldx) * 2 + 1, floatToInt(PB2[i][j].pos_oldy));
					printf("　");

					textcolor(LIGHTCYAN);

					//現在の場所
					gotoxy(floatToInt(PB2[i][j].posx) * 2 + 1, floatToInt(PB2[i][j].posy));
					printf("○");

					textcolor(WHITE);
				}

			}
		}
}

/*******************************************************************************
* 弾丸発射関数
*******************************************************************************/
void PlayerBullet2Shot(float player_x, float player_y)
{
	for (int i = 0; i < NUM_BULLET; i++)
	{
		//弾が使用中の場合は実行しない
		if (PB2[i][0].use == 0 && PB2[i][1].use == 0 && PB2[i][2].use == 0)
		{
			textcolor(LIGHTCYAN);

			PB2[i][0].use = 1;							//弾のステータスを発射中に変更する
			PB2[i][0].posx = floatToInt(player_x) + 1;	//プレイヤーのx座標を取得
			PB2[i][0].posy = floatToInt(player_y) - 1;	//プレイヤーのy座標を取得

			//現在の場所
			gotoxy(floatToInt(PB2[i][0].posx) * 2 + 1, floatToInt(PB2[i][0].posy));
			printf("○");

			PB2[i][1].use = 1;							//弾のステータスを発射中に変更する
			PB2[i][1].posx = floatToInt(player_x) + 1;	//プレイヤーのx座標を取得
			PB2[i][1].posy = floatToInt(player_y) - 1;	//プレイヤーのy座標を取得

			//現在の場所
			gotoxy(floatToInt(PB2[i][1].posx) * 2 + 1, floatToInt(PB2[i][0].posy));
			printf("○");

			PB2[i][2].use = 1;							//弾のステータスを発射中に変更する
			PB2[i][2].posx = floatToInt(player_x) + 1;	//プレイヤーのx座標を取得
			PB2[i][2].posy = floatToInt(player_y) - 1;	//プレイヤーのy座標を取得

			//現在の場所
			gotoxy(floatToInt(PB2[i][2].posx) * 2 + 1, floatToInt(PB2[i][0].posy));
			printf("○");

			textcolor(WHITE);

			break;	//弾を一発撃ったらループを抜ける
		}
	}
}

/*******************************************************************************
* 弾丸削除関数
*******************************************************************************/
void PlayerBullet2Delete(int index, int index2)
{
	//弾のステータスを未使用状態に更新する
	PB2[index][index2].use = 0;

	//弾の表示を強制的に削除
	gotoxy(floatToInt(PB2[index][index2].pos_oldx) * 2 + 1, floatToInt(PB2[index][index2].pos_oldy));
	printf("　");

}

/*******************************************************************************
* 弾丸データゲット関数
*******************************************************************************/
BULLET(*GetPlayerBullet2(void))[3]
	{
		return PB2;
	}
