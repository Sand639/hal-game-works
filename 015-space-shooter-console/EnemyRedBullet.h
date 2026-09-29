#pragma once
#include "PlayerBullet1.h"
/*******************************************************************************
* マクロ定義
*******************************************************************************/
#define NUM_ENEMY_BULLET (30)	//敵の出せる弾の数

/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
void EnemyRedBulletInit(void);
void EnemyRedBulletUninit(void);
void EnemyRedBulletUpdate(void);
void EnemyRedBulletDraw(void);
void EnemyRedBulletShot(float x, float y);
void EnemyRedBulletDelete(int index);
BULLET* GetEnemyRedBullet();