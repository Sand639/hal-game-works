/*******************************************************************************
* タイトル:		フェード制御
* プログラム名:	fade.cpp
* 作成者:		大槻海斗
* 作成日:		2024/06/17〜
* 更新日		2024/07/08
********************************************************************************/

/*******************************************************************************
*　インクルードファイル
*******************************************************************************/
#include "main.h"		//メインヘッダー
#include "sprite.h"
#include "Scene_Manager.h"
#include "fade.h"		//フェードヘッダー

/*******************************************************************************
*　デストラクタ
*******************************************************************************/
FADE::~FADE()
{
	if (TextureID == nullptr)
		return;

	TextureID->Release();	//テクスチャの解放
}

/*******************************************************************************
*　初期化
*******************************************************************************/
void FADE::InitFade(void)
{
	mode = FADE_NONE;			// 現在のフェードモード
	pos = XMFLOAT3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f);	// 座標
	size = XMFLOAT2(SCREEN_WIDTH, SCREEN_HEIGHT); 			// サイズ
	col = XMFLOAT4(0.0f, 0.0f, 0.0f, 1.0f);	//色は黒
	frame = 30;
	use = false;		// 使用フラグ
	TextureID = NULL;

	//テクスチャ読み込み
	TexMetadata metadata;
	ScratchImage image;

	//背景
	LoadFromWICFile(L"asset\\texture\\fade.bmp", WIC_FLAGS_NONE, &metadata, image);
	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &TextureID);
	assert(TextureID);
}

/*******************************************************************************
*　更新処理
*******************************************************************************/
void FADE::UpdateFade(void)
{
	if (!use)
		return;

	switch (mode)
	{
	case FADE_NONE:	//何もしない
		return;
		break;

	case FADE_IN:

		col.w -= (1.0f / frame);

		if (col.w <= 0.0f)
		{
			mode = FADE_NONE;
			col.w = 0.0f;
			use = false;
		}

		break;


	case FADE_OUT:

		col.w += (1.0f / frame);

		if (col.w >= 1.0f)
		{
			//mode = FADE_IN;
			mode = FADE_NONE;
			col.w = 1.0f;
			use = false;


			// シーン切り替え
			//SCENE s = GetScene(); // 現在のシーンを取得
			//switch (s)
			//{
			//case SCENE_TITLE:
			//	SetScene(SCENE_GAME);
			//	break;
			//case SCENE_GAME:
			//	SetScene(SCENE_RESULT);
			//	break;
			//case SCENE_RESULT:
			//	SetScene(SCENE_TITLE);
			//	break;
			//default:break;
			//}
		}
		break;
	default:break;
	}

}

/*******************************************************************************
*　描画処理
*******************************************************************************/
void FADE::DrawFade(void)
{
	if (!use)
		return;

	// マトリクス設定 
	SetWorldViewProjection2D();
	GetDeviceContext()->PSSetShaderResources(0, 1, &TextureID);
	DrawSprite(pos, size, col);
}

/*******************************************************************************
*　フェードスタート
*******************************************************************************/
void FADE::StartFade(FADE_STATE state)
{
	InitFade();

	mode = state;
	//α値をリセット
	if (mode == FADE_IN)
	{
		col.w = 1.0f;
	}
	else
	{
		col.w = 0.0f;
	}

	use = true;
}

/*******************************************************************************
*　フェード処理状態の取得
*******************************************************************************/
FADE_STATE FADE::GetFadeState()
{
	return mode;
}



