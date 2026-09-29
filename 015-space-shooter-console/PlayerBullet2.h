#pragma once
/*******************************************************************************
* マクロ定義
*******************************************************************************/
#define NUM_TBULLET (30)	//プレイヤーの出せる弾丸の数

/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
void PlayerBullet2Init(void);	//弾丸初期化関数
void PlayerBullet2Uninit(void);	//弾丸終了関数
void PlayerBullet2Update(void);	//弾丸更新関数
void PlayerBullet2Draw(void);	//弾丸描画関数

void PlayerBullet2Shot(float player_x, float player_y);	//弾丸座標設定関数
void PlayerBullet2Delete(int index, int index2);		//弾丸削除関数

BULLET(*GetPlayerBullet2())[3];	//弾丸の構造体取得関数
