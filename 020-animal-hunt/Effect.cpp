#include "Effect.h"
/*******************************************************************************
* タイトル:		爆発エフェクトプログラム
* プログラム名:	Effect.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/07/18 〜
* 最終変更日:	2024/07/18
********************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "main.h"
#include "renderer.h"
#include "sprite.h"
#include "Effect.h"
#include "block.h"



/*******************************************************************************
* マクロ定義
*******************************************************************************/
//エフェクトオブジェクト
#define EFFECT_MAX (100)


/*******************************************************************************
* グローバル変数
*******************************************************************************/
static ID3D11ShaderResourceView* g_Texture;
static EFFECT g_Effect[EFFECT_MAX];


/*******************************************************************************
* 初期化処理
*******************************************************************************/
void InitEffect()
{
	//オブジェクトの初期化
	for (int i = 0; i < EFFECT_MAX; i++)
	{
		g_Effect[i].Enable = false;
	}

	//テクスチャの読み込み
	TexMetadata metadata;
	ScratchImage image;

	//爆発エフェクト
	LoadFromWICFile(L"asset\\SampleTexture\\Explosion.png", WIC_FLAGS_NONE, &metadata, image);
	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &g_Texture);
	assert(g_Texture);

}


/*******************************************************************************
* 終了処理
*******************************************************************************/
void UninitEffect()
{
	//テクスチャの解放
	g_Texture->Release();
}


/*******************************************************************************
* 更新処理
*******************************************************************************/
void UpdateEffect()
{
	//アニメーション処理
	for (int i = 0; i < EFFECT_MAX; i++)
		if (g_Effect[i].Enable)
		{
			g_Effect[i].FrameCount++;	//カウンターインクリメント

			if (g_Effect[i].FrameCount > 30)
				g_Effect[i].Enable = false;//30フレーム後に消滅
		}
}

/*******************************************************************************
* 描画処理
*******************************************************************************/
void DrawEffect()
{
	//テクスチャセット
	GetDeviceContext()->PSSetShaderResources(0, 1, &g_Texture);

	//オブジェクトの表示
	for (int i = 0; i < EFFECT_MAX; i++)
		if (g_Effect[i].Enable)
		{
			int PtNo = (int)(g_Effect[i].FrameCount / 30.0f * 16.0f);

			XMFLOAT4 col(1.0f, 1.0f, 1.0f, 1.0f);
			XMFLOAT2 size(BLOCK_WIDTH * 1.6f, BLOCK_HIGHT * 1.6f);


			DrawSpriteRotateUVScroll(g_Effect[i].Position, size, col, 0,
				PtNo, 4, 4);
		}
}


/*******************************************************************************
* エフェクト作成
*******************************************************************************/
void CreateEffect(XMFLOAT3 Position)
{
	for (int i = 0; i < EFFECT_MAX; i++)
		if (!g_Effect[i].Enable)
		{
			g_Effect[i].Enable = true;
			g_Effect[i].Position = Position;
			g_Effect[i].FrameCount = 0;

			break;
		}
}
