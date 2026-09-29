/*******************************************************************************
* タイトル:		当たり判定制御
* プログラム名:	collision.cpp
* 作成者:		大槻海斗
* 作成日:		2024/06/17〜
* 更新日		2024/07/08
********************************************************************************/

/*******************************************************************************
*　インクルードファイル
*******************************************************************************/
#include "main.h"		//メインヘッダー
#include "collision.h"	//当たり判定ヘッダー

/*******************************************************************************
*　バウンディングボックスの当たり判定
*
*  引数:
*  	矩形Ａの中心座標
*  	矩形Ｂの中心座標
*  	矩形Ａのサイズ
*  	矩形Ｂのサイズ
*
*  戻り値
*   true：当たっている
*  	false：当たっていない
*******************************************************************************/

bool CheckBoxCollider(XMFLOAT2 PosA, XMFLOAT2 PosB, XMFLOAT2 SizeA, XMFLOAT2 SizeB)
{
	FLOAT ATop = PosA.y - SizeA.y / 2;	// Aの上端
	FLOAT ABottom = PosA.y + SizeA.y / 2;	// Aの下端
	FLOAT ARight = PosA.x + SizeA.x / 2;	// Aの右端
	FLOAT ALeft = PosA.x - SizeA.x / 2;	// Aの左端

	FLOAT BTop = PosB.y - SizeB.x / 2;	// Bの上端
	FLOAT BBottom = PosB.y + SizeB.x / 2;	// Bの下端
	FLOAT BRight = PosB.x + SizeB.y / 2;	// Bの右端
	FLOAT BLeft = PosB.x - SizeB.y / 2;	// Bの左端

	if ((ARight >= BLeft) &&		// Aの右端 > Bの左端
		(ALeft <= BRight) &&		// Aの左端 < Bの右端
		(ABottom >= BTop) &&		// Aの下端 > Bの上端
		(ATop <= BBottom))			// Aの上端 < Bの下端
	{
		// 当たっている
		return true;
	}

	// 当たっていない
	return false;
}

