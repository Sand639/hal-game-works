// ===================================================
// player.h プレイヤー制御
// 
// 制作者：大槻海斗		日付：2024/06/17
// ===================================================
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "main.h"

// ===================================================
// 構造体宣言
// ===================================================
class PLAYER {		// プレイヤー構造体
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
void InitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);
void UninitPlayer(void);
PLAYER* GetPlayer(void);


#endif
