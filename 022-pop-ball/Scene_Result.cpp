/*******************************************************************************
* タイトル:		リザルトシーン管理ヘッダー
* プログラム名:	Scene_Result.cpp
* 作成者:		大槻海斗
* 作成日:		2024/09/05〜
* 更新日		2024/09/05
*******************************************************************************/

/*******************************************************************************
*　インクルードファイル
*******************************************************************************/
#include "Scene_Manager.h"	//シーン管理
#include "sprite.h"
#include "Scene_Result.h"
#include "keyboard.h"
#include "Result_BG.h"
#include "UI_time.h"
#include "UI_resultTime.h"
#include "Audio.h"

/*******************************************************************************
*　グローバル変数
*******************************************************************************/
//サウンドを表す変数
static int BGM_ID;

static Time g_pTime;
static Result_Time g_pResultTime;;

void InitResult()
{
	InitResultBG();
	g_pTime = GetTime();

	g_pResultTime.SetValue(g_pTime.GetMin(), g_pTime.GetSec(), g_pTime.GetMilSec());

	//サウンドデータの読み込み
	BGM_ID = LoadAudio("asset\\Audio\\Astral_Pulse.wav");
	PlayAudio(BGM_ID, true);	//BGMをループ再生

	
	PlayAudio(LoadAudio("asset\\Audio\\回復魔法1.wav"));

}

void UninitResult()
{
	UnloadAudio(BGM_ID);
}

void UpdateResult()
{

}

void DrawResult()
{
	SetUVMatrix(XMMatrixIdentity());
	DrawResultBG();
	g_pResultTime.Draw();

}