// ===================================================
// player.h プレイヤー制御
// 
// 制作者：大岡優剛		日付：2024/08/30
// ===================================================
#ifndef _SUNLIGHT_H_
#define _SUNLIGHT_H_

#include "main.h"

// ===================================================
// 構造体宣言
// ===================================================
class SUNLIGHT {		// プレイヤー構造体
public:
	XMFLOAT3 pos;		// 座標
	XMFLOAT3 oldpos;	// 1フレーム前の座標
	XMFLOAT2 vel;		// 速度
	XMFLOAT2 size;	// サイズ
	bool use;		// 使用フラグ
};

// ===================================================
// プロトタイプ宣言
// ===================================================
void InitSunlight(void);
void UpdateSunlight(void);
void DrawSunlight(void);
void UninitSunlight(void);

#endif
