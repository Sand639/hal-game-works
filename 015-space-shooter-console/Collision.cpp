/*******************************************************************************
* タイトル:		当たり判定プログラム
* プログラム名:	Collision.cpp
* 作成者:		大槻海斗
* 作成日:		2024/02/24
********************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "Player.h"			//プレイヤーヘッダー
#include "EnemyRed.h"		//敵ヘッダー
#include "EnemyRedBullet.h"
#include "PlayerBullet1.h"	//弾丸ヘッダー
#include "PlayerBullet2.h"	//弾丸ヘッダー
#include "Scene.h"
#include "Collision.h"
#include "EnemyRedAnim.h"
#include "ItemHeal.h"
#include "ItemLevelUp.h"
#include "EnemyBoss.h"
#include "EnemyBossBullet.h"

/*******************************************************************************
* 当たり判定
*******************************************************************************/
void CollisionDetection(void)
{
	CollisionPandE();		//プレイヤーと敵

	CollisionPB1andE();		//プレイヤーの弾と敵

	CollisionPB2andE();		//プレイヤーの弾2と敵

	CollisionPandEB();		//プレイヤーと敵の弾

	CollisionPB1andEB();	//プレイヤーの弾と敵の弾

	CollisionPB2andEB();	//プレイヤーの弾2と敵の弾

	CollisionPandIHeal();	//プレイヤーと回復アイテム

	CollisionPandILevel();	//プレイヤーとレベルアップアイテム

	CollisionPandBoss();	//プレイヤーとボス

	CollisionPB1andBoss();	//プレイヤーの弾とボス

	CollisionPB2andBoss();	//プレイヤーの弾2とボス

	//CollisonBossandI();	//ボスとアイテム

	CollisionPandBossB();	//プレイヤーとボスの弾

	CollisionPB1andBossB();	//プレイヤーの弾1とボスの弾

	CollisionPB2andBossB();	//プレイヤーの弾2とボスの弾
}

//プレイヤーと敵
void CollisionPandE(void)
{
	PLAYER* P = GetPlayer();
	ENEMY* E = GetEnemyRed();

	const BLOCKSHAPE* EnemyShape = GetEnemyRedShape();
	const BLOCKSHAPE* PlayerShape = GetPlayerShape();

	// プレイヤーと敵との当たり判定
	for (int i = 0; i < NUM_ENEMYRED; i++)
	{
		// すでに消えている敵とは当たり判定をしない
		if (E[i].use == 0 || E[i].use == 2)
			continue;

		// プレイヤーと敵の形状を走査
		for (int py = 0; py < PlayerShape->height; py++)
		{
			for (int px = 0; px < PlayerShape->width; px++)
			{
				// プレイヤーの形状が1でなければスキップ
				if (PlayerShape->pattern[py][px] != 1)
					continue;

				for (int ey = 0; ey < EnemyShape->height; ey++)
				{
					for (int ex = 0; ex < EnemyShape->width; ex++)
					{
						// 敵の形状が1以上でなければスキップ
						if (EnemyShape->pattern[ey][ex] < 1)
							continue;

						// プレイヤーと敵の座標が一致するかを確認
						if ((floatToInt(P->posx) + px == floatToInt(E[i].posx) + ex) &&
							(floatToInt(P->posy) + py == floatToInt(E[i].posy) + ey))
						{
							// 当たり判定があれば体当たり成功で敵を消す
							EnemyRedDelete(i);

							// プレイヤーがダメージを受ける
							PlayerDamage();
						}
					}
				}
			}
		}
	}

}

//プレイヤーの弾と敵
void CollisionPB1andE(void)
{
	ENEMY* E = GetEnemyRed();
	BULLET* B = GetPlayerBullet1();

	const BLOCKSHAPE* EnemyShape = GetEnemyRedShape();

	//プレイヤーの弾と敵の当たり判定
	for (int i = 0; i < NUM_BULLET; i++)
	{
		//発射されていない弾とは当たり判定をしない
		if (B[i].use == 0)
			continue;

		//弾と敵の当たり判定
		for (int j = 0; j < NUM_ENEMYRED; j++)
		{
			//すでに消えている敵とは当たり判定をしない
			if (E[j].use == 0 || E[j].use == 2)
				continue;

			//弾と敵の形状を走査
			for (int ey = 0; ey < EnemyShape->height; ey++)
			{
				for (int ex = 0; ex < EnemyShape->width; ex++)
				{
					// 敵の形状が1以上でなければスキップ
					if (EnemyShape->pattern[ey][ex] < 1)
						continue;

					//弾と敵の座標が重なっているか判定する
					if ((floatToInt(B[i].posx) == floatToInt(E[j].posx) + ex) &&
						(floatToInt(B[i].posy) == floatToInt(E[j].posy) + ey))
					{
						//スコアを追加
						AddScore(100);

						//同じであれば撃ち落とせたので弾と敵を消す
						EnemyRedDelete(j);
						PlayerBullet1Delete(i);

						//爆発アニメーション
						EnemyRedAnimStart(E[j].posx, E[j].posy);

						int Random = ((rand() % 4) + 1);

						if (Random == 1)	//四分の一
						{
							Random = ((rand() % 2) + 1);
							switch (Random)
							{
								case 1:
									HealCreate(E[j].posx, E[j].posy);
									break;
								case 2:
									LevelItemCreate(E[j].posx, E[j].posy);
									break;
							}
						}

					}
				}
			}
		}
	}

}

//プレイヤーと敵の弾
void CollisionPandEB(void)
{
	PLAYER* P = GetPlayer();
	BULLET* EB = GetEnemyRedBullet();

	const BLOCKSHAPE* PlayerShape = GetPlayerShape();

	//プレイヤーと敵の弾の当たり判定
	for (int i = 0; i < NUM_BULLET; i++)
	{
		//発射されていない弾とは当たり判定をしない
		if (EB[i].use == 0)
			continue;

		for (int py = 0; py < PlayerShape->height; py++)
		{
			for (int px = 0; px < PlayerShape->width; px++)
			{
				// プレイヤーの形状が1でなければスキップ
				if (PlayerShape->pattern[py][px] != 1)
					continue;
				//弾と敵の座標が重なっているか判定する
				if ((floatToInt(EB[i].posx) == floatToInt(P->posx) + px) &&
					(floatToInt(EB[i].posy) == floatToInt(P->posy) + py))
				{
					PlayerDamage();

					EnemyRedBulletDelete(i);
				}
			}
		}
	}

}

//プレイヤーの弾と敵の弾
void CollisionPB1andEB(void)
{
	BULLET* B = GetPlayerBullet1();
	BULLET* EB = GetEnemyRedBullet();

	//敵の弾とプレイヤーの弾の当たり判定
	for (int i = 0; i < NUM_BULLET; i++)
	{
		//発射されていない弾とは当たり判定をしない
		if (B[i].use == 0)
			continue;

		//弾と敵の当たり判定
		for (int j = 0; j < NUM_ENEMYRED; j++)
		{
			//発射されていない弾とは当たり判定をしない
			if (EB[i].use == 0)
				continue;

			//弾と敵の座標が重なっているか判定する
			if ((floatToInt(B[i].posx) == floatToInt(EB[j].posx)) &&
				(floatToInt(B[i].posy) == floatToInt(EB[j].posy)))
			{
				//同じであれば撃ち落とせたので弾を消す
				PlayerBullet1Delete(i);
				EnemyRedBulletDelete(j);
			}
		}
	}
}

//プレイヤーと回復アイテム
void CollisionPandIHeal(void)
{
	PLAYER* P = GetPlayer();
	ITEM* I = GetHealItem();
	const BLOCKSHAPE* PlayerShape = GetPlayerShape();

	//プレイヤーとアイテムの当たり判定
	for (int i = 0; i < NUM_HEAL; i++)
	{	//すでに消えているアイテムとは当たり判定をしない
		if (I[i].use == 0)
			continue;

		for (int py = 0; py < PlayerShape->height; py++)
		{
			for (int px = 0; px < PlayerShape->width; px++)
			{
				// プレイヤーの形状が1でなければスキップ
				if (PlayerShape->pattern[py][px] != 1)
					continue;
				//プレイヤーと回復アイテムが重なっているか判定する
				if ((floatToInt(I[i].posx) == floatToInt(P->posx) + px) &&
					(floatToInt(I[i].posy) == floatToInt(P->posy) + py))
				{
					//プレイヤーのHPを回復する
					PlayerHeal();

					//アイテムを消す
					HealDelete(i);
				}
			}
		}
	}
}

//プレイヤーとレベルアイテム
void CollisionPandILevel(void)
{
	PLAYER* P = GetPlayer();
	ITEM* I = GetLevelItem();
	const BLOCKSHAPE* PlayerShape = GetPlayerShape();

	//プレイヤーとアイテムの当たり判定
	for (int i = 0; i < NUM_HEAL; i++)
	{	//すでに消えているアイテムとは当たり判定をしない
		if (I[i].use == 0)
			continue;

		for (int py = 0; py < PlayerShape->height; py++)
		{
			for (int px = 0; px < PlayerShape->width; px++)
			{
				// プレイヤーの形状が1でなければスキップ
				if (PlayerShape->pattern[py][px] != 1)
					continue;
				//プレイヤーとレベルアイテムが重なっているか判定する
				if ((floatToInt(I[i].posx) == floatToInt(P->posx) + px) &&
					(floatToInt(I[i].posy) == floatToInt(P->posy) + py))
				{
					//プレイヤーのレベルを上げる
					PlayerLevelUp();

					//アイテムを消す
					LevelItemDelete(i);
				}
			}
		}
	}
}


//プレイヤーとボス
void CollisionPandBoss(void)
{
	BOSS* Boss = GetBoss();

	if (Boss->use == 0 || Boss->use == 2)
		return;

	PLAYER* P = GetPlayer();
	const BLOCKSHAPE* PlayerShape = GetPlayerShape();

	const BOSSSHAPE* BossShape = GetBossShape();

	// プレイヤーと敵の形状を走査
	for (int py = 0; py < PlayerShape->height; py++)
	{
		for (int px = 0; px < PlayerShape->width; px++)
		{
			// プレイヤーの形状が1でなければスキップ
			if (PlayerShape->pattern[py][px] != 1)
				continue;

			for (int ey = 0; ey < BossShape->height; ey++)
			{
				for (int ex = 0; ex < BossShape->width; ex++)
				{
					// 敵の形状が1以上でなければスキップ
					if (BossShape->pattern[ey][ex] < 1)
						continue;

					// プレイヤーと敵の座標が一致するかを確認
					if ((floatToInt(P->posx) + px == floatToInt(Boss->posx) + ex) &&
						(floatToInt(P->posy) + py == floatToInt(Boss->posy) + ey))
					{
						//ボスがダメージを受ける
						BossDamage();

						// プレイヤーがダメージを受ける
						PlayerDamage();

						ReDrawBoss();
					}
				}
			}
		}
	}


}

//プレイヤーの弾とボス
void CollisionPB1andBoss(void)
{
	BOSS* Boss = GetBoss();

	if (Boss->use == 0 || Boss->use == 2)
		return;

	BULLET* B = GetPlayerBullet1();
	const BOSSSHAPE* BossShape = GetBossShape();

	for (int i = 0; i < NUM_BULLET; i++)
	{
		//発射されていない弾とは当たり判定をしない
		if (B[i].use == 0)
			continue;

		//弾と敵の形状を走査
		for (int ey = 0; ey < BossShape->height; ey++)
		{
			for (int ex = 0; ex < BossShape->width; ex++)
			{
				// 敵の形状が1以上でなければスキップ
				if (BossShape->pattern[ey][ex] < 1)
					continue;

				//弾と敵の座標が重なっているか判定する
				if ((floatToInt(B[i].posx) == floatToInt(Boss->posx) + ex) &&
					(floatToInt(B[i].posy) == floatToInt(Boss->posy) + ey))
				{
					//スコアを追加
					AddScore(100);

					//同じであれば撃ち落とせたので弾と敵を消す
					BossDamage();
					PlayerBullet1Delete(i);
				}
			}
		}
	}
}

//ボスとアイテム
//void CollisonBossandI(void)
//{
//	BOSS* Boss = GetBoss();
//
//	if (Boss->use == 0 || Boss->use == 2)
//		return;
//
//	const BOSSSHAPE* BossShape = GetBossShape();
//	ITEM* I = GetHealItem();
//
//	for (int i = 0; i < NUM_HEAL; i++)
//	{	//すでに消えているアイテムとは当たり判定をしない
//		if (I[i].use == 0)
//			continue;
//
//		//弾と敵の形状を走査
//		for (int ey = 0; ey < BossShape->height; ey++)
//		{
//			for (int ex = 0; ex < BossShape->width; ex++)
//			{
//				// 敵の形状が1以上でなければスキップ
//				if (BossShape->pattern[ey][ex] < 1)
//					continue;
//
//				//弾と敵の座標が重なっているか判定する
//				if ((floatToInt(I[i].posx) == floatToInt(Boss->posx) + ex) &&
//					(floatToInt(I[i].posy) == floatToInt(Boss->posy) + ey))
//				{
//					ReDrawBoss();
//				}
//			}
//		}
//	}
//
//}

//プレイヤーの弾2と敵
void CollisionPB2andE(void)
{
	ENEMY* E = GetEnemyRed();
	BULLET(*TB)[3] = GetPlayerBullet2();

	const BLOCKSHAPE* EnemyShape = GetEnemyRedShape();

	for (int i = 0; i < NUM_BULLET; i++)
		for (int j = 0; j < 3; j++)
		{
			//発射されていない弾とは当たり判定をしない
			if (TB[i][j].use == 0)
				continue;

			for (int k = 0; k < NUM_ENEMYRED; k++)
			{
				//すでに消えている敵とは当たり判定をしない
				if (E[k].use == 0 || E[k].use == 2)
					continue;

				for (int ey = 0; ey < EnemyShape->height; ey++)
				{
					for (int ex = 0; ex < EnemyShape->width; ex++)
					{
						// 敵の形状が1以上でなければスキップ
						if (EnemyShape->pattern[ey][ex] < 1)
							continue;

						//弾と敵の座標が重なっているか判定する
						if ((floatToInt(TB[i][j].posx) == floatToInt(E[k].posx) + ex) &&
							(floatToInt(TB[i][j].posy) == floatToInt(E[k].posy) + ey))
						{
							//スコアを追加
							AddScore(100);

							//同じであれば撃ち落とせたので弾と敵を消す
							EnemyRedDelete(k);
							PlayerBullet2Delete(i, j);

							//爆発アニメーション
							EnemyRedAnimStart(E[k].posx, E[k].posy);

							int Random = ((rand() % 4) + 1);

							if (Random == 1)
							{
								Random = ((rand() % 2) + 1);
								switch (Random)
								{
								case 1:
									HealCreate(E[k].posx, E[k].posy);
									break;
								case 2:
									LevelItemCreate(E[k].posx, E[k].posy);
									break;
								}
							}
						}
					}
				}
			}
		}
}

//プレイヤーの弾2と敵の弾
void CollisionPB2andEB(void)
{
	BULLET(*TB)[3] = GetPlayerBullet2();
	BULLET* EB = GetEnemyRedBullet();


	for (int i = 0; i < NUM_BULLET; i++)
		for (int j = 0; j < 3; j++)
		{
			//発射されていない弾とは当たり判定をしない
			if (TB[i][j].use == 0)
				continue;

			//弾と敵の当たり判定
			for (int k = 0; k < NUM_ENEMYRED; k++)
			{
				//発射されていない弾とは当たり判定をしない
				if (EB[k].use == 0)
					continue;

				//弾と敵の座標が重なっているか判定する
				if ((floatToInt(TB[i][j].posx) == floatToInt(EB[k].posx)) &&
					(floatToInt(TB[i][j].posy) == floatToInt(EB[k].posy)))
				{
					//同じであれば撃ち落とせたので弾を消す
					PlayerBullet2Delete(i, j);
					EnemyRedBulletDelete(k);
				}
			}
		}
}

//プレイヤーの弾2とボス
void CollisionPB2andBoss(void)
{
	BOSS* Boss = GetBoss();

	if (Boss->use == 0 || Boss->use == 2)
		return;

	BULLET(*TB)[3] = GetPlayerBullet2();

	const BOSSSHAPE* BossShape = GetBossShape();

	for (int i = 0; i < NUM_BULLET; i++)
		for (int j = 0; j < 3; j++)
		{
			//発射されていない弾とは当たり判定をしない
			if (TB[i][j].use == 0)
				continue;

			//弾と敵の形状を走査
			for (int ey = 0; ey < BossShape->height; ey++)
			{
				for (int ex = 0; ex < BossShape->width; ex++)
				{
					// 敵の形状が1以上でなければスキップ
					if (BossShape->pattern[ey][ex] < 1)
						continue;

					//弾と敵の座標が重なっているか判定する
					if ((floatToInt(TB[i][j].posx) == floatToInt(Boss->posx) + ex) &&
						(floatToInt(TB[i][j].posy) == floatToInt(Boss->posy) + ey))
					{
						//同じであれば撃ち落とせたので弾と敵を消す
						BossDamage();
						PlayerBullet2Delete(i, j);

						ReDrawBoss();
					}
				}
			}

		}

}

//プレイヤーとボスの攻撃
void CollisionPandBossB(void)
{
	PLAYER* P = GetPlayer();
	const BLOCKSHAPE* PlayerShape = GetPlayerShape();

	BULLET(*BossB)[5] = GetBossBullet();

	for (int i = 0; i < NUM_BULLET; i++)
		for (int j = 0; j < 5; j++)
		{
			//発射されていない弾とは当たり判定をしない
			if (BossB[i][j].use == 0)
				continue;

			for (int py = 0; py < PlayerShape->height; py++)
			{
				for (int px = 0; px < PlayerShape->width; px++)
				{
					// プレイヤーの形状が1でなければスキップ
					if (PlayerShape->pattern[py][px] != 1)
						continue;
					//プレイヤーと回復アイテムが重なっているか判定する
					if ((floatToInt(BossB[i][j].posx) == floatToInt(P->posx) + px) &&
						(floatToInt(BossB[i][j].posy) == floatToInt(P->posy) + py))
					{
						PlayerDamage();

						BossBulletDelete(i,j);
					}
				}
			}
		}
}

//プレイヤーの弾とボスの弾
void CollisionPB1andBossB(void)
{
	BULLET* B = GetPlayerBullet1();
	BULLET(*BossB)[5] = GetBossBullet();

	for (int i = 0; i < NUM_BULLET; i++)
		for (int j = 0; j < 5; j++)
		{
			//発射されていない弾とは当たり判定をしない
			if (BossB[i][j].use == 0)
				continue;

			for (int k = 0; k < NUM_BULLET; k++)
			{
				//発射されていない弾とは当たり判定をしない
				if (B[k].use == 0)
					continue;

				//プレイヤーと回復アイテムが重なっているか判定する
				if ((floatToInt(BossB[i][j].posx) == floatToInt(B[k].posx)) &&
					(floatToInt(BossB[i][j].posy) == floatToInt(B[k].posy)))
				{
					PlayerBullet1Delete(k);

					BossBulletDelete(i, j);
				}
			}
		}
}

//プレイヤーの弾2とボスの弾
void CollisionPB2andBossB(void)
{
	BULLET(*TB)[3] = GetPlayerBullet2();
	BULLET(*BossB)[5] = GetBossBullet();

	for (int i = 0; i < NUM_BULLET; i++)
		for (int j = 0; j < 3; j++)
		{
			//発射されていない弾とは当たり判定をしない
			if (TB[i][j].use == 0)
				continue;

			for (int k = 0; k < NUM_BULLET; k++)
				for (int l = 0; l < 5; l++)
				{
					//発射されていない弾とは当たり判定をしない
					if (BossB[k][l].use == 0)
						continue;

					if ((floatToInt(TB[i][j].posx) == floatToInt(BossB[k][l].posx)) &&
						(floatToInt(TB[i][j].posy) == floatToInt(BossB[k][l].posy)))
					{
						PlayerBullet2Delete(i, j);

						BossBulletDelete(k, l);
					}
				}
		}
}





/*******************************************************************************
* メモ
*******************************************************************************/
/*
プレイヤーが敵を弾丸で倒した場合にのみアイテムをランダム確率で出現させる
*/