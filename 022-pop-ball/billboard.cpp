/*******************************************************************************
* タイトル:		ビルボード
* プログラム名:	billboard.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/12/17 〜
* 最終変更日:	2024/12/17
********************************************************************************/

/*******************************************************************************
* インクルード
*******************************************************************************/
#include "billboard.h"
#include "main.h"		//メインヘッダー
#include "renderer.h"	//レンダラーヘッダー
#include "texture.h"	//テクスチャヘッダー
#include "light.h"

/*******************************************************************************
* マクロ定義
*******************************************************************************/
static constexpr int NUM_LINE_NUM_X = 4;

/*******************************************************************************
* グローバル変数
*******************************************************************************/
static ID3D11Buffer* g_VertexBuffer = NULL;	//頂点情報
static XMMATRIX g_BillboardMatrix;

/*******************************************************************************
*　初期化処理
*******************************************************************************/
void InitBillboard(void)
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
		{ { -0.5f,  0.5f,  0.0f },{0.0f, 0.0f,-1.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.0f, 0.0f} },
		{ {  0.5f,  0.5f,  0.0f },{0.0f, 0.0f,-1.0f},{1.0f, 1.0f, 1.0f, 1.0f},{1.0f, 0.0f} },
		{ { -0.5f, -0.5f,  0.0f },{0.0f, 0.0f,-1.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.0f, 1.0f} },
		{ {  0.5f, -0.5f,  0.0f },{0.0f, 0.0f,-1.0f},{1.0f, 1.0f, 1.0f, 1.0f},{1.0f, 1.0f} },

	};

	D3D11_SUBRESOURCE_DATA data;
	data.pSysMem = v;
	data.SysMemPitch = 0;
	data.SysMemSlicePitch = 0;

	GetDevice()->CreateBuffer(&bd, &data, &g_VertexBuffer);


}

/*******************************************************************************
*　終了処理
*******************************************************************************/
void UninitBillboard(void)
{

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
void DrawBillboard(int textureId, const XMFLOAT2& offset,const XMVECTOR& position, const XMFLOAT2& scale, float angle,
	float tx, float ty, float tw, float th)
{

	SetTexture(textureId);

	SetPixelShader2d();

	XMMATRIX mtx_offset = XMMatrixTranslation(offset.x, offset.y, 0.0f);

	XMMATRIX mtx_scale = XMMatrixScaling(scale.x, scale.y, 1.0f);

	XMMATRIX mtx_translate = XMMatrixTranslationFromVector(position);

	XMMATRIX mtx_rotation = XMMatrixRotationZ(angle);

	SetWorldMatrix(mtx_rotation * mtx_offset * mtx_scale *  g_BillboardMatrix * mtx_translate);

	float sx = tw / TextureGetWidth(textureId);
	float sy = th / TextureGetHeight(textureId);
	float u = tx / TextureGetWidth(textureId);
	float v = ty / TextureGetHeight(textureId);

	XMMATRIX uvScale = XMMatrixScalingFromVector({ sx,sy,1.0f });
	XMMATRIX uvTranslate = XMMatrixTranslation(u, v, 0.0f);
	//XMMATRIX uvRotate = XMMatrixRotationZ(angle);

	//XMMATRIX uvOff = XMMatrixTranslation(-0.1f, -0.25f, 0.0f);
	//XMMATRIX uvOffInv = XMMatrixTranslation(0.1f, 0.25f, 0.0f);

	SetUVMatrix(uvScale * uvTranslate);

	//SetUVMatrix(XMMatrixIdentity());


	// 頂点バッファ設定 
	UINT stride = sizeof(VERTEX_3D);	//頂点のサイズ
	UINT voffset = 0;	//頂点の読み込み開始位置
	GetDeviceContext()->IASetVertexBuffers(0, 1, &g_VertexBuffer, &stride, &voffset);

	//インデックスバッファ設定
	//GetDeviceContext()->IASetIndexBuffer(NULL, DXGI_FORMAT_R16_UINT, 0);

	// プリミティブトポロジ設定 
	GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	// マテリアル設定 
	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	SetMaterial(material);

	//SetLight(world);
	

	// ポリゴン描画 
	GetDeviceContext()->Draw(NUM_LINE_NUM_X, 0);


}

void CalculateBillboardMatrix(const XMMATRIX& mtxView)
{
	//転地行列
	XMMATRIX view_inverse = XMMatrixTranspose(mtxView);

	XMFLOAT4X4 matrix;
	XMStoreFloat4x4(&matrix, view_inverse);
	//平行移動成分をカット
	matrix._14 = matrix._24 = matrix._34 = 0.0f;

	g_BillboardMatrix = XMLoadFloat4x4(&matrix);

}
