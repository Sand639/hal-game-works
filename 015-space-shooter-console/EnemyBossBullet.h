#pragma once
#include "PlayerBullet1.h"
/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
void BossBulletInit(void);		//弾丸初期化関数
void BossBulletUninit(void);	//弾丸終了関数
void BossBulletUpdate(void);	//弾丸更新関数
void BossBulletDraw(void);		//弾丸描画関数

void BossBulletShot();	//弾丸座標設定関数
void BossBulletDelete(int index, int index2);						//弾丸削除関数

BULLET(*GetBossBullet(void))[5];		//弾丸の構造体取得関数

void ColorBullet(void);	//文字色ランダム関数
