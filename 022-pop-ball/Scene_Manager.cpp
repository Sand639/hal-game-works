/*******************************************************************************
* タイトル:		シーン管理
* プログラム名:	manager.cpp
* 作成者:		大槻海斗
* 作成日:		2024/09/05〜
* 更新日		2024/09/05
*******************************************************************************/

/*******************************************************************************
*　インクルードファイル
*******************************************************************************/
#include "Scene_Manager.h"
#include "Scene_Title.h"
#include "Scene_Game.h"
#include "Scene_Result.h"
#include "main.h"
#include "fade.h"
#include "UI_time.h"

/*******************************************************************************
*　グローバル変数
*******************************************************************************/
static SCENE Scene = SCENE_NONE;	//現在のシーン変数
static FADE fade;
static Time g_pTime;

/*******************************************************************************
*　初期化処理
*******************************************************************************/
void InitManager()
{
	fade.InitFade();

	//開始シーンのセット
	SetScene(SCENE_TITLE);	//ゲームシーンからスタート

	fade.StartFade(FADE_IN);
}

/*******************************************************************************
*　終了処理
*******************************************************************************/
void UninitManager()
{
	SetScene(SCENE_NONE);
}

/*******************************************************************************
*　更新処理
*******************************************************************************/
void UpdateManager()
{
	fade.UpdateFade();
	//シーンごとの更新処理
	switch (Scene)
	{
	case SCENE_NONE:
		break;
	case SCENE_TITLE:
		UpdateTitle();
		break;
	case SCENE_GAME:
		UpdateGame();
		break;
	case SCENE_RESULT:
		UpdateResult();
		break;
	default:break;
	}

}

/*******************************************************************************
*　描画処理
*******************************************************************************/
void DrawManager()
{
	//シーンごとの描画処理
	switch (Scene)
	{
	case SCENE_NONE:
		break;
	case SCENE_TITLE:
		DrawTitle();
		break;
	case SCENE_GAME:
		DrawGame();
		break;
	case SCENE_RESULT:
		DrawResult();
		break;
	default:break;
	}

	fade.DrawFade();
}

/*******************************************************************************
*　シーンの取得
*******************************************************************************/
SCENE GetScene(void)
{
	return Scene;
}

/*******************************************************************************
*　シーンの切替
*******************************************************************************/
void SetScene(SCENE scene)
{
	//現シーンの終了
	switch (Scene)
	{
	case SCENE_NONE:
		break;
	case SCENE_TITLE:
		UninitTitle();
		break;
	case SCENE_GAME:
		UninitGame();
		break;
	case SCENE_RESULT:
		UninitResult();
		break;
	default:break;
	}

	Scene = scene;	//次シーンをセット

	//次シーンの初期化
	switch (Scene)
	{
	case SCENE_NONE:
		break;
	case SCENE_TITLE:
		InitTitle();
		break;
	case SCENE_GAME:
		InitGame();
		break;
	case SCENE_RESULT:
		InitResult();
		break;
	default:break;
	}
}

/*******************************************************************************
*　タイムのセット
*******************************************************************************/
void SetTime(const Time* time) {
	g_pTime = *time;
}

/*******************************************************************************
*　タイムのゲッター
*******************************************************************************/
Time GetTime() {
	return g_pTime;
}