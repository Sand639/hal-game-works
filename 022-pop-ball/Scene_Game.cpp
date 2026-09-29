/*******************************************************************************
* タイトル:		ゲームシーン処理
* プログラム名:	Scene_Game.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/10/16 〜
* 最終変更日:	2024/10/16
********************************************************************************/

/*******************************************************************************
*　インクルードファイル
*******************************************************************************/
#include "Scene_Game.h"
//#include "Game_CountDown.h"
#include "Game_Main.h"
//#include "Game_finish"
#include "texture.h"
#include "sprite.h"
#include "fade.h"

/*******************************************************************************
*　グローバル定数
*******************************************************************************/
static constexpr float DEGREE = XM_PI / 180;
static GAMESCENE Scene = GAME_NONE;	//現在のシーン変数
static FADE fade;
static bool transitioning = false;

/*******************************************************************************
*　グローバル変数
*******************************************************************************/
static int g_TextureId = -1;
static int g_TextureId2 = -1;
static int g_TextureId3 = -1;

/*******************************************************************************
*　初期化処理
*******************************************************************************/
void InitGame(void)
{
	fade.InitFade();

	//開始シーンのセット
	SetGameScene(GAME_MAIN);	//ゲームシーンからスタート

	fade.StartFade(FADE_IN);

}

/*******************************************************************************
*　終了処理
*******************************************************************************/
void UninitGame(void)
{
	SetGameScene(GAME_NONE);
}


/*******************************************************************************
*　更新処理
*******************************************************************************/
void UpdateGame(void)
{
	fade.UpdateFade();

	if (transitioning) return;

	//シーンごとの更新処理
	switch (Scene)
	{
	case GAME_NONE:
		break;

	case GAME_COUNTDOWN:

		break;

	case GAME_MAIN:
		UpdateGameMain();
		break;

	case GAME_FINISH:

		break;
	case GAME_RESTART:
		SetGameScene(GAME_MAIN);

	default:break;
	}

	transitioning = false; // 遷移完了後に解除
}

/*******************************************************************************
*　描画処理
*******************************************************************************/
void DrawGame(void)
{

	//シーンごとの描画処理
	switch (Scene)
	{
	case GAME_NONE:
		break;

	case GAME_COUNTDOWN:

		break;

	case GAME_MAIN:
		DrawGameMain();
		break;

	case GAME_FINISH:

		break;
	case GAME_RESTART:

	default:break;
	}

	fade.DrawFade();

}

/*******************************************************************************
*　シーンの取得
*******************************************************************************/
GAMESCENE GetGameScene(void)
{
	return Scene;
}

/*******************************************************************************
*　シーンの切替
*******************************************************************************/
void SetGameScene(GAMESCENE scene)
{
	//現シーンの終了
	switch (Scene)
	{
	case GAME_NONE:
		break;

	case GAME_COUNTDOWN:

		break;

	case GAME_MAIN:
		UninitGameMain();
		break;

	case GAME_FINISH:

		break;
	case GAME_RESTART:

	default:break;
	}

	Scene = scene;	//次シーンをセット

	//次シーンの初期化
	switch (Scene)
	{
	case GAME_NONE:
		break;

	case GAME_COUNTDOWN:

		break;

	case GAME_MAIN:
		InitGameMain();
		break;

	case GAME_FINISH:

		break;
	case GAME_RESTART:

	default:break;
	}
}
