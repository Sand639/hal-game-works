#pragma once

//座標構造体
struct POSITION
{
	int x = 2;	//x座標
	int y = 2;	//y座標

	//移動前の位置
	int old_x = x;
	int old_y = y;

	int survival = 1;		//敵１の生存確認	1生存　2戦闘　3死亡
};
//座標構造体ポインタゲット関数
POSITION* GetPpos();	//プレイヤー
POSITION* GetE1pos();	//敵1(シャド)

//プレイヤー構造体
struct PLAYER	//プレイヤーパラメータ
{
	char name[24] = "ああああ";	//名前
	int HP = 500;			//体力
	int MaxHP = 500;		//最大体力値
	int MP = 50;			//マジックポイント
	int MaxMP = 50;			//最大マジックポイント
	int AT = 50;			//攻撃力
	int VIT = 50;			//防御力
	int VIT2 = 0;			//ランダム防御力
	int SaveSwitch = 0;		//セーブされているかどうか
	int MAP = 0;			//マップ何にいるか
};
PLAYER* GetPlayer();	//プレイヤー構造体ポインタゲット関数

//ポーション構造体
struct POTION	//回復薬
{
	int HPplus = 3;			//回復薬の個数
	int MPplus = 1;			//MP回復薬の個数
};
POTION* Getpotion();	//ポーション構造体ポインタゲット関数

//MAP1変数構造体
struct MAPVARIVABLE
{
	int loop = 0;	//while分のループ処理

	//map1
	int field[10][10] = {
			1,1,1,1,1,1,1,1,1,1,
			1,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,2,0,1,
			1,0,0,0,0,0,0,0,0,1,
			1,1,1,1,1,1,1,1,1,1,
	};

};
MAPVARIVABLE* GetMAP1();

//敵構造体
struct ENEMY
{
	char name[24] = "";		//名前
	int EH = 100;			//HP
	int EA = 30;			//Attack
	int Evasion = 90;		//回避成功率
	int defense = 0;		//防御率
	int Init = 0;			//初期化
	int ad = 0;				//アドバンテージ
};
ENEMY* GetE1();

//MAP2変数構造体
struct MAP2VARIVABLE
{
	int loop = 0;	//while分のループ処理

	//map2
	int field[15][15] = {
			1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
			1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
			1,0,0,0,0,0,0,0,3,0,1,0,2,0,1,
			1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
			1,0,0,0,1,1,1,1,1,1,1,1,0,1,1,
			1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
			1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
			1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};
};


//プロトタイプ宣言

//MAP2ポインタゲット関数
POSITION* GetPpos2();
POSITION* GetE2pos();
POSITION* GetE3pos();
MAP2VARIVABLE* GetMAP2();
ENEMY* GetE2();
ENEMY* GetE3();

//マップ
void MAP1();
void MAP2();

//一画面表示
void title(void);		//タイトル
void GameOver(void);	//ゲームオーバー
void GameClear(void);	//ゲームクリア

//main.cpp　短縮関数
void CreateName(void);		//名前作成

//マップ部品
int Explanation();		//操作説明＆表記説明

int Recovery();			//回復使用
int Recovery0();

int HolyWater();		//聖水使用
int HolyWater0();

//中断セーブ
int Save();		//マップ1
int Save2();	//マップ2

//戦闘プログラム部品
int Heal();				//プレイヤー回復魔法
int Inventory(int num);			//持ち物欄
void PHP0(int HP);		//プレイヤーHP0判定
float RandomFloat();	//1.5〜2の間をランダムで決定


//戦闘プログラム
int EnemyBattle();		//敵1戦闘処理
int E2Battle();			//敵2戦闘処理
int E3Battle();			//敵3戦闘処理
