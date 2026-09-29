#pragma once
/*******************************************************************************
* マクロ定義
*******************************************************************************/
#define NUM_BULLET (10)	//プレイヤーの出せる弾丸の数

/*******************************************************************************
* 構造体定義
*******************************************************************************/

//弾丸構造体
struct BULLET
{
	float posx;//現在のX座標
	float posy;//現在のY座標
	float pos_oldx;//前回のX座標
	float pos_oldy;//前回のY座標

	float speedx;//横への移動速度
	float speedy;//縦への移動速度

	int use;//使用しているか使用していないかのフラグ
};

/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
void PlayerBullet1Init(void);		//弾丸初期化関数
void PlayerBullet1Uninit(void);	//弾丸終了関数
void PlayerBullet1Update(void);	//弾丸更新関数
void PlayerBullet1Draw(void);		//弾丸描画関数

void PlayerBullet1Shot(float player_x, float player_y);	//弾丸座標設定関数
void PlayerBullet1Delete(int index);						//弾丸削除関数

BULLET* GetPlayerBullet1();		//弾丸の構造体取得関数




