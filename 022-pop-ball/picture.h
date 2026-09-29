/*******************************************************************************
* タイトル:		画像クラスヘッダー
* プログラム名:	picture.h
* 作成者:		大槻海斗
* 作成日:		2024/12/20〜
* 更新日		2024/12/20
********************************************************************************/
#pragma once
/*******************************************************************************
*　インクルードファイル
*******************************************************************************/
#include "main.h"
#include "texture.h"
#include "sprite.h"
#include "renderer.h"

/*******************************************************************************
*　構造体宣言
*******************************************************************************/
class Picture
{
private:

	XMFLOAT3 m_position;	// 座標
	XMFLOAT2 m_size;		// サイズ
	XMFLOAT4 m_color;		// 移動値
	bool m_isActive;		// 使用フラグ
	int m_textureId;		//テクスチャ

public:

	Picture(int textureId = -1, XMFLOAT3 pos = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f },
		XMFLOAT2 size = { SCREEN_WIDTH, SCREEN_HEIGHT },
		XMFLOAT4 col = { 1.0f, 1.0f, 1.0f, 1.0f }, bool isActive = true):
		m_textureId(textureId), m_position(pos),m_size(size),m_color(col),m_isActive(isActive){ }

	~Picture() = default;

	int GetTextureId() { return m_textureId; }

	bool GetIsActive() { return m_isActive; }
	void SetIsActive(bool isActive) { m_isActive = isActive; }

	void SetTextureSize(XMFLOAT2 scale = {1.0f,1.0f}) {
		m_size.x = (float)TextureGetWidth(m_textureId) * scale.x;
		m_size.y = (float)TextureGetHeight(m_textureId) * scale.y;
	}

	void Draw() const {

		if (!m_isActive)
			return;

		// マトリクス設定 
		SetWorldViewProjection2D();
		SetDepthEnable(false);
		SetPixelShader2d();

		//使用するテクスチャをセット
		SetTexture(m_textureId);

		//ポリゴンの表示
		DrawSprite(m_position, m_size, m_color);

	}
};


