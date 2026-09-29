//=====================================//
// result.cpp
// 大槻海斗
// 2024/06/13〜
//=====================================//

//=====================================//
// インクルード
//=====================================//
#include "manager.h"	//シーン管理
#include "sprite.h"
#include "result.h"
#include "keyboard.h"
#include "score.h"		//スコア表示ヘッダー
#include "resultBG.h"



void InitResult()
{
	InitResultBG();

}

void UninitResult()
{

	UninitScore();
}

void UpdateResult()
{
	UpdateScore();
	if (Keyboard_IsKeyDown(KK_SPACE))
	{
		SetScene(SCENE_TITLE);
	}

	if (Keyboard_IsKeyDown(KK_ESCAPE))
	{
		exit(0);
	}
}

void DrawResult()
{
	DrawResultBG();

	DrawScore();
}