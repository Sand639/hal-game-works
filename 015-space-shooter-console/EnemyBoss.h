#pragma once
/*******************************************************************************
* マクロ定義
*******************************************************************************/
//ブロックの大きさを定義する
#define BOSS_WIDTH  (11)//ブロックの形状の最大幅を定義する
#define BOSS_HEIGHT (9)//ブロックの形状の最大高さを定義する

#define BOSS_HP (50)


/*******************************************************************************
* 構造体定義
*******************************************************************************/

//敵データ構造体
struct BOSS
{
	float posx;		//現在のX座標
	float posy;		//現在のY座標
	float pos_oldx;	//前回のX座標
	float pos_oldy;	//前回のY座標

	float speedx;	//横への移動速度
	float speedy;	//縦への移動速度

	int fream;		//弾丸を撃てるまでの時間
	int Dmage_fream;//ダメージを受けた後の無敵時間

	int HP;			//体力

	int use;//使用しているか使用していないかのフラグ
};

//ブロックの形状の構造体
struct BOSSSHAPE {
	int width, height;	//幅と高さ
	int pattern[BOSS_HEIGHT][BOSS_WIDTH];//形状
};



/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/

void BossInit(void);		//敵初期化関数
void BossUninit(void);		//敵終了関数
void BossUpdate(void);		//敵更新関数
void BossDraw(void);		//敵描画関数

void BossDelete(void);	//敵削除関数

BOSS* GetBoss();			//敵構造体取得関数

int BossGetLive(void);		//敵の生存数取得関数
void BossFlagON(void);			//敵出現関数

void BossDamage(void);

//敵のの形状を取得する関数
const BOSSSHAPE* GetBossShape(void);

void ReDrawBoss(void);