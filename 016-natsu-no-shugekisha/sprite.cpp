
#include "main.h"
#include "sprite.h"


//==================================//
// マクロ定義						//
//==================================//
#define NUM_SPRITEVERTEX (10000)


//==================================//
// プロトタイプ宣言					//
//==================================//

//==================================//
// グローバル変数					//
//==================================//
static ID3D11Buffer* g_VertexBuffer = NULL;
static XMFLOAT2 ScrollOffset;	//スクロールさせる量


//==================================//
// 初期化処理						//
//==================================//
HRESULT InitSprite()
{
	ID3D11Device* pDevice = GetDevice();


	// 頂点バッファ生成 
	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DYNAMIC;
	bd.ByteWidth = sizeof(VERTEX_3D) * NUM_SPRITEVERTEX;	//バッファサイズ　構造体サイズ * 頂点数分
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	GetDevice()->CreateBuffer(&bd, NULL, &g_VertexBuffer);

	return S_OK;
}

//==================================//
// 終了処理							//
//==================================//
void UninitSprite()
{
	// 頂点バッファの解放 
	if (g_VertexBuffer)
	{
		g_VertexBuffer->Release();	//作った頂点バッファを開放する
		g_VertexBuffer = NULL;
	}
}


//=================================
// 描画処理
//=================================

void DrawSprite(XMFLOAT3 position, XMFLOAT2 size, XMFLOAT4 color)
{

	D3D11_MAPPED_SUBRESOURCE msr;

	GetDeviceContext()->Map(
		g_VertexBuffer,				//頂点データのポインタ
		0,							//サブの頂点データのポインタ
		D3D11_MAP_WRITE_DISCARD,	//マップタイプ
		0,							//マップのフラグ
		&msr);						//マップデータのポインタ

	VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;

	FLOAT size_W = size.x * 0.5f;
	FLOAT size_H = size.y * 0.5f;

	//四角形の中心を(0,0)と考えた4つの座標を作る

	//左上
	vertex[0].Position = XMFLOAT3(-size_W, -size_H, 0.0f);
	vertex[0].Diffuse = color;
	vertex[0].TexCoord = XMFLOAT2(0.0f,0.0f);

	//右上
	vertex[1].Position = XMFLOAT3(size_W, -size_H, 0.0f);
	vertex[1].Diffuse = color;
	vertex[1].TexCoord = XMFLOAT2(1.0f,0.0f);

	//左下
	vertex[2].Position = XMFLOAT3(-size_W, size_H, 0.0f);
	vertex[2].Diffuse = color;
	vertex[2].TexCoord = XMFLOAT2(0.0f,1.0f);

	//右下
	vertex[3].Position = XMFLOAT3(size_W, size_H, 0.0f);
	vertex[3].Diffuse = color;
	vertex[3].TexCoord = XMFLOAT2(1.0f,1.0f);

	//平行移動処理
	for (int i = 0; i < 4; i++)
	{
		vertex[i].Position.x += position.x;
		vertex[i].Position.y += position.y;
	}

	GetDeviceContext() ->Unmap (g_VertexBuffer, 0);

	// 頂点バッファ設定 
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	GetDeviceContext()->IASetVertexBuffers(0, 1, &g_VertexBuffer, &stride, &offset);

	// プリミティブトポロジ設定 
	GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	// マテリアル設定 
	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	SetMaterial(material);

	// ポリゴン描画 
	GetDeviceContext()->Draw(4, 0);
}

//DrawSprite改造版
void DrawSprite(XMFLOAT2 size, XMFLOAT4 color)
{

	D3D11_MAPPED_SUBRESOURCE msr;

	GetDeviceContext()->Map(
		g_VertexBuffer,				//頂点データのポインタ
		0,							//サブの頂点データのポインタ
		D3D11_MAP_WRITE_DISCARD,	//マップタイプ
		0,							//マップのフラグ
		&msr);						//マップデータのポインタ

	VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;

	FLOAT size_W = size.x * 0.5f;
	FLOAT size_H = size.y * 0.5f;

	//四角形の中心を(0,0)と考えた4つの座標を作る

	//左上
	vertex[0].Position = XMFLOAT3(-size_W, -size_H, 0.0f);
	vertex[0].Diffuse = color;
	vertex[0].TexCoord = XMFLOAT2(0.0f, 0.0f);

	//右上
	vertex[1].Position = XMFLOAT3(size_W, -size_H, 0.0f);
	vertex[1].Diffuse = color;
	vertex[1].TexCoord = XMFLOAT2(1.0f, 0.0f);

	//左下
	vertex[2].Position = XMFLOAT3(-size_W, size_H, 0.0f);
	vertex[2].Diffuse = color;
	vertex[2].TexCoord = XMFLOAT2(0.0f, 1.0f);

	//右下
	vertex[3].Position = XMFLOAT3(size_W, size_H, 0.0f);
	vertex[3].Diffuse = color;
	vertex[3].TexCoord = XMFLOAT2(1.0f, 1.0f);

	GetDeviceContext()->Unmap(g_VertexBuffer, 0);

	// 頂点バッファ設定 
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	GetDeviceContext()->IASetVertexBuffers(0, 1, &g_VertexBuffer, &stride, &offset);

	// プリミティブトポロジ設定 
	GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	// マテリアル設定 
	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	SetMaterial(material);

	// ポリゴン描画 
	GetDeviceContext()->Draw(4, 0);
}


//==================================//
// 回転する四角形					//
//==================================//
void DrawSpriteRotate(XMFLOAT3 position, XMFLOAT2 size, XMFLOAT4 color, FLOAT radian)
{

	//頂点の作成
	D3D11_MAPPED_SUBRESOURCE msr;
	GetDeviceContext()->Map(g_VertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);

	VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;

	float size_W = size.x * 0.5f;
	float size_H = size.y * 0.5f;

	//左上 中心からサイズの半分の場所で座標を作る
	vertex[0].Position = XMFLOAT3(-size_W, -size_H, 0.0f);
	vertex[0].Diffuse = color;
	vertex[0].TexCoord = XMFLOAT2(0.0f, 0.0f);
	//右上 中心からサイズの半分の場所で座標を作る
	vertex[1].Position = XMFLOAT3(size_W, -size_H, 0.0f);
	vertex[1].Diffuse = color;
	vertex[1].TexCoord = XMFLOAT2(1.0f, 0.0f);
	//左下 中心からサイズの半分の場所で座標を作る
	vertex[2].Position = XMFLOAT3(-size_W, size_H, 0.0f);
	vertex[2].Diffuse = color;
	vertex[2].TexCoord = XMFLOAT2(0.0f, 1.0f);
	//右下 中心からサイズの半分の場所で座標を作る
	vertex[3].Position = XMFLOAT3(size_W, size_H, 0.0f);
	vertex[3].Diffuse = color;
	vertex[3].TexCoord = XMFLOAT2(1.0f, 1.0f);

	//回転処理
	float co = sinf(radian);//時計回りにするためにsinとcosをひっくり返す
	float si = cosf(radian);
	for (int i = 0; i < 4; i++)
	{
		float x = vertex[i].Position.x;
		float y = vertex[i].Position.y;
		vertex[i].Position.x = (x * co - y * si) + position.x;
		vertex[i].Position.y = (x * si + y * co) + position.y;
	}

	GetDeviceContext()->Unmap(g_VertexBuffer, 0);


	// 頂点バッファ設定
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	GetDeviceContext()->IASetVertexBuffers(0, 1, &g_VertexBuffer, &stride, &offset);

	// プリミティブトポロジ設定
	GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	// マテリアル設定
	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	SetMaterial(material);

	// ポリゴン描画
	GetDeviceContext()->Draw(4, 0);

}


//========================================--==//
// スプライト表示テクスチャアニメーション対応版
// 
// PtNo		パターン番号
// XPtnCnt	横のパターン分割数
// YPtnCnt	縦のパターン分割数
//============================================//
void DrawSpriteRotateUV(XMFLOAT3 position, XMFLOAT2 size,
	XMFLOAT4 color, FLOAT radian,
	int PtNo, int XPtnCnt, int YPtnCnt)
{
	//頂点の作成
	D3D11_MAPPED_SUBRESOURCE msr;
	GetDeviceContext()->Map(g_VertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);

	VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;


	//wとhを計算しておく
	float w = 1.0f / XPtnCnt;
	float h = 1.0f / YPtnCnt;

	//始点パターンの左上のテクスチャ座標を計算しておく
	float u = (PtNo % XPtnCnt) * w;
	float v = (PtNo / YPtnCnt) * h;

	//ここから下はDrawSpriteRotate()関数と同じ
	//TexCoordの値のみuとvとwとhを使って計算して格納する

	float size_W = size.x * 0.5f;
	float size_H = size.y * 0.5f;

	//左上 中心からサイズの半分の場所で座標を作る
	vertex[0].Position = XMFLOAT3(-size_W, -size_H, 0.0f);
	vertex[0].Diffuse = color;
	vertex[0].TexCoord = XMFLOAT2(u, v);
	//右上 中心からサイズの半分の場所で座標を作る
	vertex[1].Position = XMFLOAT3(size_W, -size_H, 0.0f);
	vertex[1].Diffuse = color;
	vertex[1].TexCoord = XMFLOAT2(u + w, v);
	//左下 中心からサイズの半分の場所で座標を作る
	vertex[2].Position = XMFLOAT3(-size_W, size_H, 0.0f);
	vertex[2].Diffuse = color;
	vertex[2].TexCoord = XMFLOAT2(u, v + h);
	//右下 中心からサイズの半分の場所で座標を作る
	vertex[3].Position = XMFLOAT3(size_W, size_H, 0.0f);
	vertex[3].Diffuse = color;
	vertex[3].TexCoord = XMFLOAT2(u + w, v + h);

	//回転処理
	float co = cosf(radian);
	float si = sinf(radian);
	for (int i = 0; i < 4; i++)
	{
		float x = vertex[i].Position.x;
		float y = vertex[i].Position.y;
		vertex[i].Position.x = (x * co - y * si) + position.x;
		vertex[i].Position.y = (x * si + y * co) + position.y;
	}

	GetDeviceContext()->Unmap(g_VertexBuffer, 0);


	// 頂点バッファ設定
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	GetDeviceContext()->IASetVertexBuffers(0, 1, &g_VertexBuffer, &stride, &offset);

	// プリミティブトポロジ設定
	GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	// マテリアル設定
	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	SetMaterial(material);

	// ポリゴン描画
	GetDeviceContext()->Draw(4, 0);


}
//========================================--==//
// スプライト表示テクスチャアニメーション対応版
// 
// PtNo		パターン番号
// XPtnCnt	横のパターン分割数
// YPtnCnt	縦のパターン分割数
//============================================//
void DrawSpriteRotateUV(XMFLOAT2 size,XMFLOAT4 color,
	int PtNo, int XPtnCnt, int YPtnCnt)
{
	//頂点の作成
	D3D11_MAPPED_SUBRESOURCE msr;
	GetDeviceContext()->Map(g_VertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);

	VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;


	//wとhを計算しておく
	float w = 1.0f / XPtnCnt;
	float h = 1.0f / YPtnCnt;

	//始点パターンの左上のテクスチャ座標を計算しておく
	float u = (PtNo % XPtnCnt) * w;
	float v = (PtNo / YPtnCnt) * h;

	//ここから下はDrawSpriteRotate()関数と同じ
	//TexCoordの値のみuとvとwとhを使って計算して格納する

	float size_W = size.x * 0.5f;
	float size_H = size.y * 0.5f;

	//左上 中心からサイズの半分の場所で座標を作る
	vertex[0].Position = XMFLOAT3(-size_W, -size_H, 0.0f);
	vertex[0].Diffuse = color;
	vertex[0].TexCoord = XMFLOAT2(u, v);
	//右上 中心からサイズの半分の場所で座標を作る
	vertex[1].Position = XMFLOAT3(size_W, -size_H, 0.0f);
	vertex[1].Diffuse = color;
	vertex[1].TexCoord = XMFLOAT2(u + w, v);
	//左下 中心からサイズの半分の場所で座標を作る
	vertex[2].Position = XMFLOAT3(-size_W, size_H, 0.0f);
	vertex[2].Diffuse = color;
	vertex[2].TexCoord = XMFLOAT2(u, v + h);
	//右下 中心からサイズの半分の場所で座標を作る
	vertex[3].Position = XMFLOAT3(size_W, size_H, 0.0f);
	vertex[3].Diffuse = color;
	vertex[3].TexCoord = XMFLOAT2(u + w, v + h);

	GetDeviceContext()->Unmap(g_VertexBuffer, 0);


	// 頂点バッファ設定
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	GetDeviceContext()->IASetVertexBuffers(0, 1, &g_VertexBuffer, &stride, &offset);

	// プリミティブトポロジ設定
	GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	// マテリアル設定
	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	SetMaterial(material);

	// ポリゴン描画
	GetDeviceContext()->Draw(4, 0);
}




//=================================
// スクロール対応版
//=================================
void DrawSpriteScroll(XMFLOAT3 position, XMFLOAT2 size, XMFLOAT4 color)
{
	//スクロール処理
	position.x += ScrollOffset.x;
	position.y += ScrollOffset.y;

	D3D11_MAPPED_SUBRESOURCE msr;

	GetDeviceContext()->Map(
		g_VertexBuffer,				//頂点データのポインタ
		0,							//サブの頂点データのポインタ
		D3D11_MAP_WRITE_DISCARD,	//マップタイプ
		0,							//マップのフラグ
		&msr);						//マップデータのポインタ

	VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;

	FLOAT size_W = size.x * 0.5f;
	FLOAT size_H = size.y * 0.5f;

	//四角形の中心を(0,0)と考えた4つの座標を作る

	//左上
	vertex[0].Position = XMFLOAT3(-size_W, -size_H, 0.0f);
	vertex[0].Diffuse = color;
	vertex[0].TexCoord = XMFLOAT2(0.0f, 0.0f);

	//右上
	vertex[1].Position = XMFLOAT3(size_W, -size_H, 0.0f);
	vertex[1].Diffuse = color;
	vertex[1].TexCoord = XMFLOAT2(1.0f, 0.0f);

	//左下
	vertex[2].Position = XMFLOAT3(-size_W, size_H, 0.0f);
	vertex[2].Diffuse = color;
	vertex[2].TexCoord = XMFLOAT2(0.0f, 1.0f);

	//右下
	vertex[3].Position = XMFLOAT3(size_W, size_H, 0.0f);
	vertex[3].Diffuse = color;
	vertex[3].TexCoord = XMFLOAT2(1.0f, 1.0f);

	//平行移動処理
	for (int i = 0; i < 4; i++)
	{
		vertex[i].Position.x += position.x;
		vertex[i].Position.y += position.y;
	}

	GetDeviceContext()->Unmap(g_VertexBuffer, 0);

	// 頂点バッファ設定 
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	GetDeviceContext()->IASetVertexBuffers(0, 1, &g_VertexBuffer, &stride, &offset);

	// プリミティブトポロジ設定 
	GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	// マテリアル設定 
	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	SetMaterial(material);

	// ポリゴン描画 
	GetDeviceContext()->Draw(4, 0);
}

//=================================
// スクロール対応版
//=================================
void DrawSpriteRotateUVScroll(XMFLOAT3 position, XMFLOAT2 size,
	XMFLOAT4 color, FLOAT radian,
	int PtNo, int XPtnCnt, int YPtnCnt)
{
	//スクロール処理
	position.x += ScrollOffset.x;
	position.y += ScrollOffset.y;

	//頂点の作成
	D3D11_MAPPED_SUBRESOURCE msr;
	GetDeviceContext()->Map(g_VertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);

	VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;


	//wとhを計算しておく
	float w = 1.0f / XPtnCnt;
	float h = 1.0f / YPtnCnt;

	//始点パターンの左上のテクスチャ座標を計算しておく
	float u = (PtNo % XPtnCnt) * w;
	float v = (PtNo / YPtnCnt) * h;

	//ここから下はDrawSpriteRotate()関数と同じ
	//TexCoordの値のみuとvとwとhを使って計算して格納する

	float size_W = size.x * 0.5f;
	float size_H = size.y * 0.5f;

	//左上 中心からサイズの半分の場所で座標を作る
	vertex[0].Position = XMFLOAT3(-size_W, -size_H, 0.0f);
	vertex[0].Diffuse = color;
	vertex[0].TexCoord = XMFLOAT2(u, v);
	//右上 中心からサイズの半分の場所で座標を作る
	vertex[1].Position = XMFLOAT3(size_W, -size_H, 0.0f);
	vertex[1].Diffuse = color;
	vertex[1].TexCoord = XMFLOAT2(u + w, v);
	//左下 中心からサイズの半分の場所で座標を作る
	vertex[2].Position = XMFLOAT3(-size_W, size_H, 0.0f);
	vertex[2].Diffuse = color;
	vertex[2].TexCoord = XMFLOAT2(u, v + h);
	//右下 中心からサイズの半分の場所で座標を作る
	vertex[3].Position = XMFLOAT3(size_W, size_H, 0.0f);
	vertex[3].Diffuse = color;
	vertex[3].TexCoord = XMFLOAT2(u + w, v + h);

	//回転処理
	float co = cosf(radian);
	float si = sinf(radian);
	for (int i = 0; i < 4; i++)
	{
		float x = vertex[i].Position.x;
		float y = vertex[i].Position.y;
		vertex[i].Position.x = (x * co - y * si) + position.x;
		vertex[i].Position.y = (x * si + y * co) + position.y;
	}

	GetDeviceContext()->Unmap(g_VertexBuffer, 0);


	// 頂点バッファ設定
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	GetDeviceContext()->IASetVertexBuffers(0, 1, &g_VertexBuffer, &stride, &offset);

	// プリミティブトポロジ設定
	GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	// マテリアル設定
	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	SetMaterial(material);

	// ポリゴン描画
	GetDeviceContext()->Draw(4, 0);


}


/*******************************************************************************
*　四角形の描画 + UV
*******************************************************************************/
void DrawSpriteQuadAnim(
	float x, float y, float w, float h,
	float u, float v, float tw, float th)
{
	//頂点の作成
	D3D11_MAPPED_SUBRESOURCE msr;
	GetDeviceContext()->Map(g_VertexBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &msr);

	VERTEX_3D* vertex = (VERTEX_3D*)msr.pData;

	vertex[0].Position = XMFLOAT3(x - w * 0.5f, y - h * 0.5f, 0.0f);
	vertex[1].Position = XMFLOAT3(x + w * 0.5f, y - h * 0.5f, 0.0f);
	vertex[2].Position = XMFLOAT3(x - w * 0.5f, y + h * 0.5f, 0.0f);
	vertex[3].Position = XMFLOAT3(x + w * 0.5f, y + h * 0.5f, 0.0f);

	vertex[0].Diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[1].Diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[2].Diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	vertex[3].Diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);

	vertex[0].TexCoord = XMFLOAT2(u, v);
	vertex[1].TexCoord = XMFLOAT2(u + tw, v);
	vertex[2].TexCoord = XMFLOAT2(u, v + th);
	vertex[3].TexCoord = XMFLOAT2(u + tw, v + th);

	GetDeviceContext()->Unmap(g_VertexBuffer, 0);


	// 頂点バッファ設定
	UINT stride = sizeof(VERTEX_3D);
	UINT offset = 0;
	GetDeviceContext()->IASetVertexBuffers(0, 1, &g_VertexBuffer, &stride, &offset);

	// プリミティブトポロジ設定
	GetDeviceContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	// マテリアル設定
	MATERIAL material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
	SetMaterial(material);

	// ポリゴン描画
	GetDeviceContext()->Draw(4, 0);

}