/*******************************************************************************
* タイトル:		グリッドの表示
* プログラム名:	grid.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/10/22 〜
* 最終変更日:	2024/10/22
********************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "grid.h"		//キューブ表示ヘッダー
#include "main.h"		//メインヘッダー
#include "renderer.h"	//レンダラーヘッダー
#include "texture.h"

/*******************************************************************************
* マクロ定義
*******************************************************************************/
static constexpr int GRID_NUM_X = 10;
static constexpr int GRID_NUM_Z = 10;
static constexpr int GRID_LINE_NUM_X = GRID_NUM_X + 1;
static constexpr int GRID_LINE_NUM_Z = GRID_NUM_Z + 1;
static constexpr int GRID_VERTEX_COUNT = (GRID_LINE_NUM_X * 2) + (GRID_LINE_NUM_Z * 2);

/*******************************************************************************
* グローバル変数
*******************************************************************************/
static ID3D11Buffer* g_VertexBuffer = NULL;
static int g_TextureID = -1;

/*******************************************************************************
*　初期化処理
*******************************************************************************/
void InitGrid(void)
{
	ID3D11Device* pDevice = GetDevice();

	// 頂点バッファ生成 
	D3D11_BUFFER_DESC bd = {};
	bd.Usage = D3D11_USAGE_DYNAMIC;
	bd.ByteWidth = sizeof(VERTEX_3D) * GRID_VERTEX_COUNT;	//バッファサイズ　構造体サイズ * 頂点数分
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	GetDevice()->CreateBuffer(&bd, NULL, &g_VertexBuffer);

	//頂点の初期化
	D3D11_MAPPED_SUBRESOURCE msr;

	GetDeviceContext()->Map(
		g_VertexBuffer,				//頂点データのポインタ
		0,							//サブの頂点データのポインタ
		D3D11_MAP_WRITE_DISCARD,	//マップタイプ
		0,							//マップのフラグ
		&msr);						//マップデータのポインタ

	//GPUのVRAMにあるデータをCPUが占有
	VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;

	constexpr float start_x = GRID_NUM_X * -0.5f;
	constexpr float   end_x = GRID_NUM_X *  0.5f;
	constexpr float start_z = GRID_NUM_Z * -0.5f;
	constexpr float   end_z = GRID_NUM_Z *  0.5f;

	int i = 0;
	//for (float x = start_x; x <= end_x; x += 1.0f)
	//{
	//	vertex[i++] = { {x,  0.0, start_z},{0.0f, 0.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.0f, 0.0f} };
	//	vertex[i++] = { {x,  0.0, end_z},{0.0f, 0.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.0f, 0.0f} };	
	//}

	//for (float z = start_z; z <= end_z; z += 1.0f)
	//{
	//	vertex[i++] = { {start_x,  0.0, z},{0.0f, 0.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.0f, 0.0f} };
	//	vertex[i++] = { {end_x,  0.0, z},{0.0f, 0.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.0f, 0.0f} };
	//}

	for (float x = start_x, z = start_z; x <= end_x; x += 1.0f , z += 1.0f)
	{
		vertex[i++] = { {x,  0.0, start_z},{0.0f, 0.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.0f, 0.0f} };
		vertex[i++] = { {x,  0.0, end_z},{0.0f, 0.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.0f, 0.0f} };
		vertex[i++] = { {start_x,  0.0, z},{0.0f, 0.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.0f, 0.0f} };
		vertex[i++] = { {end_x,  0.0, z},{0.0f, 0.0f, 0.0f},{1.0f, 1.0f, 1.0f, 1.0f},{0.0f, 0.0f} };
	}

	//CPUのVRAMの占有を解除
	GetDeviceContext()->Unmap(g_VertexBuffer, 0);


}

/*******************************************************************************
*　終了処理
*******************************************************************************/
void UninitGrid(void)
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
void DrawGrid(void)
{
	g_TextureID = TextureLoad(L"asset/texture/fade.bmp");

	ID3D11ShaderResourceView* srv = GetTexture(g_TextureID);
	GetDeviceContext()->PSSetShaderResources(0, 1, &srv);

	// 頂点バッファ設定 
	UINT stride = sizeof(VERTEX_3D);	//頂点のサイズ
	UINT offset = 0;	//頂点の読み込み開始位置
	GetDeviceContext()->IASetVertexBuffers(0, 1, &g_VertexBuffer, &stride, &offset);

	// プリミティブトポロジ設定 
	GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);

	// マテリアル設定 
	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	SetMaterial(material);

	SetWorldMatrix(XMMatrixIdentity());

	// ポリゴン描画 
	GetDeviceContext()->Draw(GRID_VERTEX_COUNT, 0);


}

