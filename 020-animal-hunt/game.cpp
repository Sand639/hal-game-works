/*******************************************************************************
* タイトル:		ゲームシーン処理
* プログラム名:	Game.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/09/04 〜
* 最終変更日:	2024/09/04
********************************************************************************/

/*******************************************************************************
*　インクルードファイル
*******************************************************************************/
#include "manager.h"	//シーン管理
#include "block.h"
#include "score.h"		//スコア表示ヘッダー
#include "Effect.h"
#include "player.h"
#include "gameBG.h"
#include "countTime.h"		//時間表示ヘッダー
#include "keyboard.h"
#include "pause.h"
#include "Audio.h"
#include "game.h"

/*******************************************************************************
*　グローバル変数
*******************************************************************************/
//ポーズかどうか
static bool pause = false;
//サウンドを表す変数
static int BGM_ID;


/*******************************************************************************
*　初期化処理
*******************************************************************************/
void InitGame(void)
{
	InitGameBG();

	InitBlock();

	InitPlayer();

	InitCountTime();

	InitScore();

	InitEffect();

	InitPause();

	pause = false;

	//サウンドデータの読み込み
	BGM_ID = LoadAudio("asset\\Audio\\bgm.wav");
	PlayAudio(BGM_ID, true);	//BGMをループ再生

}

/*******************************************************************************
*　終了処理
*******************************************************************************/
void UninitGame(void)
{
	UnloadAudio(BGM_ID);

	UninitPause();

	UninitEffect();

	//result.cppのUninit
	//UninitScore();

	UninitCountTime();

	UninitPlayer();

	UninitBlock();

}


/*******************************************************************************
*　更新処理
*******************************************************************************/
void UpdateGame(void)
{
	//エスケープボタンでポーズ
	if (Keyboard_IsKeyDownTrigger(KK_Q))
	{
		if (pause)
			pause = false;
		else
		{
			InitPause();
			pause = true;
		}
	}

	if (pause)
	{
		UpdatePause();
		return;
	}

	UpdateBlock();

	UpdatePlayer();

	UpdateCountTime();

	UpdateEffect();
}

/*******************************************************************************
*　描画処理
*******************************************************************************/
void DrawGame(void)
{
	DrawGameBG();

	DrawBlock();	//フィールドを描画

	DrawPlayer();

	DrawCountTime();

	DrawScore();	//スコア

	DrawEffect();	//エフェクトを描画

	if (pause)
	{
		DrawPause();
		return;
	}

}

/*******************************************************************************
* ポーズをfalseに
*******************************************************************************/
void PauseFalse(void)
{
	pause = false;
}
