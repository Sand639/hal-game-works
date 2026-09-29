//=====================================//
// result.cpp
// 大槻海斗
// 2024/06/13〜
//=====================================//

//=====================================//
// インクルード
//=====================================//
#include "main.h"
#include "sprite.h"
#include "result.h"
#include "keyboard.h"
#include "score.h"		//スコア表示ヘッダー
#include "resultscore.h"		//スコア表示ヘッダー

//=====================================//
// グローバル変数
//=====================================//

//テクスチャID
static ID3D11ShaderResourceView* TextureID = NULL;

void InitResult()
{
	//テクスチャ読み込み
	//Windows Imaging Componentで対応する画像(bmp,png,jpg)などを読み込む
	TexMetadata metadata;
	ScratchImage image;

	LoadFromWICFile(L"asset\\texture\\result.png", WIC_FLAGS_NONE, &metadata, image);
	//読み込んだ画像データをDirectXへ渡してテクスチャとして管理させる

	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &TextureID);

	//なにか失敗した時に警告を出す
	assert(TextureID);

	InitRScore();

}

void UninitResult()
{
	TextureID->Release();	//テクスチャの解放

	UninitScore();

	UninitRScore();
}

void UpdateResult()
{
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
	// マトリクス設定 
	SetWorldViewProjection2D();

	XMFLOAT3 position = XMFLOAT3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f);
	XMFLOAT2 size = XMFLOAT2(SCREEN_WIDTH, SCREEN_HEIGHT);
	XMFLOAT4 color = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);

	//使用するテクスチャをセット
	GetDeviceContext()->PSSetShaderResources(0, 1, &TextureID);
	//ポリゴンの表示
	DrawSprite(position, size, color);

	DrawRScore();

}