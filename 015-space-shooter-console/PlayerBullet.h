#pragma once
/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/

void PBulletInit(void);		//弾丸初期化関数
void PBulletUninit(void);	//弾丸終了関数
void PBulletUpdate(void);	//弾丸更新関数
void PBulletDraw(void);		//弾丸描画関数
void PBulletShot(float player_x, float player_y);//弾丸発射関数
void CheakLevel(void);		//プレイヤーレベル確認関数