/*******************************************************************************
* タイトル:		マップパーツインターフェイス
* プログラム名:	MapParts.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/11/24 〜
* 最終変更日:	2024/11/24
********************************************************************************/
#ifndef MapParts_H
#define MapParts_H

/*******************************************************************************
* インクルード
*******************************************************************************/
#include "model.h"

/*******************************************************************************
* クラス定義
*******************************************************************************/
//マップパーツインターフェイスクラス
class MapParts {

protected:

	MODEL* m_Models[4] = {};

	XMMATRIX s = XMMatrixScaling(0.2f, 0.2f, 0.2f);
	XMMATRIX r = XMMatrixRotationY(0);
	XMMATRIX t = XMMatrixTranslation(0.2f, 0.5f, 0.0f);

	XMFLOAT4 m_col = { 1.0f,1.0f,1.0f,1.0f };
	int m_TextureID[4] = { -1,-1,-1,-1 };

public:

	MapParts() = default;

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw(const XMMATRIX& MtxWorld) = 0;

	MODEL* GetmapParts(int i) {
		return m_Models[i];
	}
};

#endif	//MapParts_H