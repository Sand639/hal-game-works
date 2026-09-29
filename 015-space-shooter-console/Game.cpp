/*******************************************************************************
* タイトル:		ゲームシーンプログラム
* プログラム名:	Scene.cpp
* 作成者:		大槻海斗
* 作成日:		2024/02/29
********************************************************************************/
#define CONIOEX
/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include <stdlib.h>		//標準ライブラリヘッダー
#include "CreateField.h"//フィールド作成関数
#include "Scene.h"		//シーン遷移ヘッダー
#include "main.h"		//メインヘッダー
#include "Game.h"		//ゲームシーンヘッダー
#include "conioex.h"	//コンソール系ヘッダー
#include "Player.h"		//プレイヤーヘッダー
#include "PlayerAnim.h"
#include "PlayerBullet.h"
#include "ItemHeal.h"
#include "ItemLevelUp.h"
#include "Collision.h"
#include "EnemyBoss.h"
#include "EnemyRed.h"
#include "EnemyRedBullet.h"
#include "EnemyBossBullet.h"
#include "EnemyRedAnim.h"
#include "EnemyBossAnim.h"

/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
void UIDraw(void);				//UI表示
void Judgement(void);			//ゲーム終了判定
void PhaseUpdate(void);
void PhaseDraw(void);
void ChangePhase(GamePhase next);

/*******************************************************************************
* グローバル変数
*******************************************************************************/
int GameBGM;
int Phase_Boss_SE;

GamePhase Phase = PHASE1;	//現在動作中のシーン


/*******************************************************************************
* ゲームシーンの初期化関数
*******************************************************************************/
void GameInit(void)
{
	Phase = PHASE1;

	GameBGM = opensound((char*)"BeasTrap.mp3");
	Phase_Boss_SE = opensound((char*)"サイレン音.mp3");

	playsound(GameBGM, 1);

	//プレイヤー
	PlayerInit();	//プレイヤーを初期化

	PAnimInit();	//プレイヤーアニメーション初期化
	
	PBulletInit();	//弾丸の初期化

	//アイテム
	HealInit();		//回復アイテム初期化

	LevelItemInit();//レベルアイテム初期化

	//敵Red
	EnemyRedInit();			//敵Red初期化

	EnemyRedBulletInit();	//敵Red弾丸初期化

	EnemyRedAnimInit();		//敵Redアニメーション初期化

	//ボス
	BossInit();			//ボス初期化

	BossBulletInit();	//ボス弾丸初期化

	BossAnimInit();		//ボスアニメーション初期化

	//UI
	ResetScore();	//点数の初期化
	
	StartTimer();	//タイマースタート
	
	CreateField();	//フィールド作成関数
}

/*******************************************************************************
* ゲームシーンの終了処理関数
*******************************************************************************/
void GameUninit(void)
{


	//ボス
	BossAnimUninit();	//ボスアニメーション初期化

	BossBulletUninit();	//ボス弾丸初期化

	BossUninit();		//ボス初期化

	//敵Red
	EnemyRedAnimUninit();	//敵Redアニメーション終了処理

	EnemyRedBulletUninit();	//敵Red弾丸終了処理

	EnemyRedUninit();		//敵Red終了処理

	//アイテム
	LevelItemUninit();	//レベルアイテム終了処理

	HealUninit();		//回復アイテム終了処理

	//プレイヤー
	PBulletUninit();	//プレイヤーの弾丸終了処理

	PAnimUninit();		//プレイヤーアニメーション終了処理

	PlayerUninit();		//プレイヤー終了処理

	//音声
	closesound(GameBGM);

	closesound(Phase_Boss_SE);
}

/*******************************************************************************
* ゲームシーンの更新処理関数
*******************************************************************************/
void GameUpdate(void)
{
	//	プレイヤー
	PlayerUpdate();		//プレイヤーデータ更新

	PBulletUpdate();	//プレイヤー弾丸更新

	PAnimUpdate();		//プレイヤーアニメーション更新

	//アイテム
	HealUpdate();		//回復アイテム更新

	LevelItemUpdate();	//レベルアイテム更新

	//フェイズ
	PhaseUpdate();


	//処理
	CollisionDetection();	//全ての当たり判定当たり判定

	//プレイヤーのレベルが変わったら弾丸強化
	CheakLevel();

	//ゲーム終了判定
	Judgement();

	//時々壁がこわれてしまうので更新処理に追加
	CreateField();		//フィールド作成関数
}

/*******************************************************************************
* ゲームシーンの描画処理関数
*******************************************************************************/
void GameDraw(void)
{
	//プレイヤー
	PlayerDraw();		//プレイヤーを描画

	PBulletDraw();		//プレイヤー弾丸描画

	PAnimDraw();		//プレイヤーアニメーション描画

	//アイテム
	HealDraw();		//回復アイテム描画

	LevelItemDraw();	//レベルアイテム描画

	//フェイズ
	PhaseDraw();

	//UI
	UIDraw();			//UIの表示
}

void UIDraw(void)
{
	//UIの表示
	gotoxy(FIELD_WIDTH * 2 + 1, 6);
	textbackground(WHITE);
	textcolor(BLUE);
	printf("スコア:%06d", GetScore());

	gotoxy(FIELD_WIDTH * 2 + 1, 7);
	DWORD elapsedtime = ElapsedTime();
	DWORD second = elapsedtime / 1000;
	DWORD millisecond = (elapsedtime / 10) % 100;
	textcolor(GREEN);
	printf("経過時間:%3d,%02d", second, millisecond);

	//文字色を元に戻す
	textbackground(BLACK);

	textcolor(CYAN);

	gotoxy(FIELD_WIDTH * 2 + 1, 10);
	printf("操作説明");

	gotoxy(FIELD_WIDTH * 2 + 1, 12);
	printf("Wキーで上に移動");
	gotoxy(FIELD_WIDTH * 2 + 1, 13);
	printf("Sキーで下に移動");
	gotoxy(FIELD_WIDTH * 2 + 1, 14);
	printf("Aキーで左に移動");
	gotoxy(FIELD_WIDTH * 2 + 1, 15);
	printf("Dキーで右に移動");

	gotoxy(FIELD_WIDTH * 2 + 1, 16);
	printf("スペースキーで弾を発射");

	textcolor(WHITE);

}



/*******************************************************************************
* ゲーム終了判定
*******************************************************************************/
void Judgement(void)
{
	static int Wait_Time = 0;

	if (EnemyRedGetLive() <= 0)
	{
		Wait_Time++;
	}

	//時間があれば敵の種類とフェーズを増やす
	if (EnemyRedGetLive() <= 0 && Phase == PHASE1 && Wait_Time >= 50)
	{
		playsound(Phase_Boss_SE, 0);

		ChangePhase(PHASE_BOSS);

		BossFlagON();

		Wait_Time = 0;
	}

	if (PlayerGetHP() <= 0 || BossGetLive() <= 0)
	{
		Wait_Time++;
	}

	if (PlayerGetHP() <= 0 && Wait_Time >= 50)
	{
		//シーンをリザルト画面へ切り替える
		SetScene(SCENE_RESULT);

		//ゲームオーバーならクリアフラグに1をセット
		SetClearFlag(1);
	}
	if (BossGetLive() <= 0 && Wait_Time >= 50)
	{
		//シーンをリザルト画面へ切り替える
		SetScene(SCENE_RESULT);

		//ゲームクリアならクリアフラグに2をセット
		SetClearFlag(2);
	}
}

/*******************************************************************************
* フェーズの更新処理関数
*******************************************************************************/
void PhaseUpdate(void)
{
	switch (Phase)
	{
	case PHASE1:
		EnemyRedUpdate();		//敵Red更新

		EnemyRedBulletUpdate();	//敵Red弾丸更新

		EnemyRedAnimUpdate();	//敵Redアニメーション更新

		break;
	case PHASE_BOSS:

		BossUpdate();		//ボス更新

		BossBulletUpdate();	//ボス弾丸更新

		BossAnimUpdate();	//ボスアニメーション

		break;
	}
}


/*******************************************************************************
* フェーズの描画処理関数
*******************************************************************************/
void PhaseDraw(void)
{
	switch (Phase)
	{
	case PHASE1:
		EnemyRedDraw();			//敵Red描画

		EnemyRedBulletDraw();	//敵Red弾丸描画

		EnemyRedAnimDraw();		//敵Redアニメーション描画

		break;
	case PHASE_BOSS:

		BossDraw();			//ボス描画

		BossBulletDraw();	//ボス弾丸描画

		BossAnimDraw();		//ボスアニメーション描画

		break;
	}
}

/*******************************************************************************
* 遷移先フェーズのセット関数
*******************************************************************************/
void ChangePhase(GamePhase next)
{
	Phase = next;
}

