//=====================================//
// title.cpp
// 大槻海斗
// 2024/06/13〜
//=====================================//

//=====================================//
// インクルード
//=====================================//
#include "manager.h"	//シーン管理
#include "sprite.h"
#include "title.h"
#include "keyboard.h"
#include "titleBG.h"


//=====================================//
// グローバル変数
//=====================================//

//テクスチャID
static ID3D11ShaderResourceView* TextureID = NULL;

void InitTitle()
{
	InitTitleBG();
}

void UninitTitle()
{
	
}

void UpdateTitle()
{
	if (Keyboard_IsKeyDownTrigger(KK_ESCAPE))
	{
		exit(0);
	}

}

void DrawTitle()
{
	DrawTitleBG();
}