/*==============================================================================

   共通ヘッダー [main.h]
                                                         Author : 
                                                         Date   : 
--------------------------------------------------------------------------------

==============================================================================*/
#pragma once


#pragma warning(push)
#pragma warning(disable:4005)

#define _CRT_SECURE_NO_WARNINGS			// scanf のwarning防止
#include <stdio.h>

#include <d3d11.h>
#include <d3dcompiler.h>

#define DIRECTINPUT_VERSION 0x0800		// 警告対処
#include "dinput.h"
#include "mmsystem.h"

#pragma warning(pop)



#include <DirectXMath.h>
using namespace DirectX;

#include "DirectXTex.h"

//デバッグビルドかリリースビルドでリンクするライブラリを選択する
#if _DEBUG
#pragma comment(lib, "DirectXTex_Debug.lib")    //デバッグ用
#else
#pragma comment(lib, "DirectXTex_Release.lib")  //リリース用
#endif

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define SCREEN_WIDTH	(1920)				// ウインドウの幅
#define SCREEN_HEIGHT	(1080)				// ウインドウの高さ

/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/

float getRandomFloat(float min, float max);
HWND GetHWnd();