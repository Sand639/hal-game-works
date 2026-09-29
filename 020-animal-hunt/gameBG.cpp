/*******************************************************************************
* タイトル:		ゲームシーンのバックグラウンド制御ヘッダー
* プログラム名:	gameBG.cpp
* 作成者:		大槻海斗
* 作成日:		2024/06/10〜
* 更新日		2024/07/08
********************************************************************************/

/*******************************************************************************
*　インクルードファイル
*******************************************************************************/
#include "main.h"
#include "sprite.h"
#include "BG.h"
#include "gameBG.h"

/*******************************************************************************
*　グローバル変数
*******************************************************************************/
static BG gameBG;
static BG Next;

/*******************************************************************************
*　初期化
*******************************************************************************/
void InitGameBG()
{
	//ネクスト
	Next.pos = XMFLOAT3(SCREEN_WIDTH / 2 + 250.0f, 150.0f, 0.0f);
	Next.size = XMFLOAT2(100.0f, 200.0f);
	Next.col = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);

	//テクスチャ読み込み
	//Windows Imaging Componentで対応する画像(bmp,png,jpg)などを読み込む
	TexMetadata metadata;
	ScratchImage image;

	//背景
	LoadFromWICFile(L"asset\\texture\\BG.png", WIC_FLAGS_NONE, &metadata, image);
	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &gameBG.TextureID);
	assert(gameBG.TextureID);

	//ネクスト
	LoadFromWICFile(L"asset\\texture\\NEXT.png", WIC_FLAGS_NONE, &metadata, image);
	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &Next.TextureID);
	assert(Next.TextureID);

}

/*******************************************************************************
*　描画
*******************************************************************************/
void DrawGameBG()
{
	// マトリクス設定 
	SetWorldViewProjection2D();

	//背景
	GetDeviceContext()->PSSetShaderResources(0, 1, &gameBG.TextureID);
	DrawSprite(gameBG.pos, gameBG.size, gameBG.col);

	//ネクスト
	GetDeviceContext()->PSSetShaderResources(0, 1, &Next.TextureID);
	DrawSprite(Next.pos, Next.size, Next.col);
}