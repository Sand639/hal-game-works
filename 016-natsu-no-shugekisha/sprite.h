#pragma once

#include "main.h"
#include "renderer.h"

//==================================//
// マクロ定義						//
//==================================//
#define ScrollAdjustX (SCREEN_WIDTH / 2 - (PIECE_WIDTH * 2.5))
#define ScrollAdjustY (60.0f)

//#define ScrollAdjustX (PIECE_WIDTH * 9.8f)
//#define ScrollAdjustY (PIECE_HEIGHT * 0.7f)

//==================================//
// プロトタイプ宣言					//
//==================================//
HRESULT InitSprite();
void UninitSprite();
void DrawSprite(XMFLOAT3 position, XMFLOAT2 size, XMFLOAT4 color);
void DrawSpriteRotate(XMFLOAT3 position, XMFLOAT2 size, XMFLOAT4 color, FLOAT radian);
void DrawSpriteRotateUV(XMFLOAT3 position, XMFLOAT2 size,
						XMFLOAT4 color, FLOAT radian,
						int PtNo, int XPtnCnt, int YPtnCnt);

//スプライト表示　行列使用版
void DrawSprite(XMFLOAT2 size, XMFLOAT4 color);

//行列使用版
void DrawSpriteRotateUV(XMFLOAT2 size, XMFLOAT4 color,
	int PtNo, int XPtnCnt, int YPtnCnt);

//スクロール対応版
void DrawSpriteScroll(XMFLOAT3 position, XMFLOAT2 size, XMFLOAT4 color);

//スクロール対応版
void DrawSpriteRotateUVScroll(XMFLOAT3 position, XMFLOAT2 size,
	XMFLOAT4 color, FLOAT radian,
	int PtNo, int XPtnCnt, int YPtnCnt);

//四角形の描画 + UV
void DrawSpriteQuadAnim(
	float x, float y, float w, float h,
	float u, float v, float tw, float th);
