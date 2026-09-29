/*******************************************************************************
* タイトル:		キューブの表示
* プログラム名:	cube.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/10/16 〜
* 最終変更日:	2024/10/16
********************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "cube.h"		//キューブ表示ヘッダー
#include "main.h"		//メインヘッダー
#include "renderer.h"	//レンダラーヘッダー
#include "texture.h"	//テクスチャヘッダー
#include "light.h"


/*******************************************************************************
* マクロ定義
*******************************************************************************/
static constexpr int NUM_LINE_NUM_X = 24;
static constexpr int NUM_INDEX_NUM_X = 36;

/*******************************************************************************
* グローバル変数
*******************************************************************************/
static ID3D11Buffer* g_VertexBuffer = NULL;	//頂点情報
static ID3D11Buffer* g_IndexBuffer = NULL;	//インデックス情報

static int g_TextureID = -1;

/*******************************************************************************
*　初期化処理
*******************************************************************************/
void InitCube(void)
{
	ID3D11Device* pDevice = GetDevice();

	// 頂点バッファ生成 
	D3D11_BUFFER_DESC bd = {};
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(VERTEX_3D) * NUM_LINE_NUM_X;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;

	//頂点情報
	VERTEX_3D v[] = {

		//前面
		{ { -0.5f,  0.5f, -0.5f },{0.0f, 0.0f,-1.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.0f, 0.0f} },
		{ {  0.5f,  0.5f, -0.5f },{0.0f, 0.0f,-1.0f},{1.0f, 1.0f, 1.0f, 1.0f},{1.0f, 0.0f} },
		{ { -0.5f, -0.5f, -0.5f },{0.0f, 0.0f,-1.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.0f, 1.0f} },
		{ {  0.5f, -0.5f, -0.5f },{0.0f, 0.0f,-1.0f},{1.0f, 1.0f, 1.0f, 1.0f},{1.0f, 1.0f} },

		//背面
		{ {  0.5f,  0.5f,  0.5f },{0.0f, 0.0f, 1.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.0f, 0.0f} },
		{ { -0.5f,  0.5f,  0.5f },{0.0f, 0.0f, 1.0f},{1.0f, 1.0f, 1.0f, 1.0f},{1.0f, 0.0f} },
		{ {  0.5f, -0.5f,  0.5f },{0.0f, 0.0f, 1.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.0f, 1.0f} },
		{ { -0.5f, -0.5f,  0.5f },{0.0f, 0.0f, 1.0f},{1.0f, 1.0f, 1.0f, 1.0f},{1.0f, 1.0f} },

		//左面
		{ { -0.5f,  0.5f,  0.5f },{-1.0f, 0.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.0f, 0.0f} },
		{ { -0.5f,  0.5f, -0.5f },{-1.0f, 0.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{1.0f, 0.0f} },
		{ { -0.5f, -0.5f,  0.5f },{-1.0f, 0.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.0f, 1.0f} },
		{ { -0.5f, -0.5f, -0.5f },{-1.0f, 0.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{1.0f, 1.0f} },

		//右面
		{ { 0.5f,  0.5f, -0.5f },{1.0f, 0.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.0f, 0.0f} },
		{ { 0.5f,  0.5f,  0.5f },{1.0f, 0.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{1.0f, 0.0f} },
		{ { 0.5f, -0.5f, -0.5f },{1.0f, 0.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.0f, 1.0f} },
		{ { 0.5f, -0.5f,  0.5f },{1.0f, 0.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{1.0f, 1.0f} },

		//上面
		{ { -0.5f,  0.5f,  0.5f },{0.0f, -1.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.0f, 0.0f} },
		{ {  0.5f,  0.5f,  0.5f },{0.0f, -1.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{1.0f, 0.0f} },
		{ { -0.5f,  0.5f, -0.5f },{0.0f, -1.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.0f, 1.0f} },
		{ {  0.5f,  0.5f, -0.5f },{0.0f, -1.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{1.0f, 1.0f} },

		//下面
		{ {  0.5f, -0.5f,  0.5f },{0.0f, 1.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.0f, 0.0f} },
		{ { -0.5f, -0.5f,  0.5f },{0.0f, 1.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{1.0f, 0.0f} },
		{ {  0.5f, -0.5f, -0.5f },{0.0f, 1.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.0f, 1.0f} },
		{ { -0.5f, -0.5f, -0.5f },{0.0f, 1.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{1.0f, 1.0f} },

	};
		
	D3D11_SUBRESOURCE_DATA data;
	data.pSysMem = v;
	data.SysMemPitch = 0;
	data.SysMemSlicePitch = 0;

	GetDevice()->CreateBuffer(&bd, &data, &g_VertexBuffer);

	//頂点を繋げる順番
	unsigned short indices[] = {
	 0,  1,  2,  1,  3,  2,
	 4,  5,  6,  5,  7,  6,
	 8,  9, 10,  9, 11, 10,
	12, 13, 14, 13, 15, 14,
	16, 17, 18, 17, 19, 18,
	20, 21, 22, 21, 23, 22
	};

	// インデックスバッファに変更
	bd.ByteWidth = sizeof(unsigned short) * NUM_INDEX_NUM_X;
	bd.BindFlags = D3D11_BIND_INDEX_BUFFER;

	data.pSysMem = indices;
	data.SysMemPitch = 0;
	data.SysMemSlicePitch = 0;

	GetDevice()->CreateBuffer(&bd, &data, &g_IndexBuffer);

	g_TextureID = TextureLoad(L"asset/texture/black.jpg");

}

/*******************************************************************************
*　終了処理
*******************************************************************************/
void UninitCube(void)
{
	// インデックスバッファの解放 
	if (g_IndexBuffer)
	{
		g_IndexBuffer->Release();	//作った頂点バッファを開放する
		g_IndexBuffer = NULL;
	}

	// 頂点バッファの解放 
	if (g_VertexBuffer)
	{
		g_VertexBuffer->Release();	//作った頂点バッファを開放する
		g_VertexBuffer = NULL;
	}
}

/*******************************************************************************
*　描画処理
*******************************************************************************/
void DrawCube(const XMMATRIX& world, int textureId)
{

	if (textureId == -1) {
		SetTexture(g_TextureID);
	}
	else {
		SetTexture(textureId);
	}

	// 頂点バッファ設定 
	UINT stride = sizeof(VERTEX_3D);	//頂点のサイズ
	UINT offset = 0;	//頂点の読み込み開始位置
	GetDeviceContext()->IASetVertexBuffers(0, 1, &g_VertexBuffer, &stride, &offset);

	//インデックスバッファ設定
	GetDeviceContext()->IASetIndexBuffer(g_IndexBuffer, DXGI_FORMAT_R16_UINT, 0);

	// プリミティブトポロジ設定 
	GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	// マテリアル設定 
	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	SetMaterial(material);

	SetLight(world);
	SetWorldMatrix(world);

	// ポリゴン描画 
	GetDeviceContext()->DrawIndexed(NUM_INDEX_NUM_X, 0, 0);

}
