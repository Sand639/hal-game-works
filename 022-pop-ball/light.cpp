/*******************************************************************************
* タイトル:		カメラの管理
* プログラム名:	light.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/11/12 〜
* 最終変更日:	2024/11/12
********************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "light.h"		//ライト管理ヘッダー
#include "renderer.h"	//レンダラーヘッダー

/*******************************************************************************
  ライト構造体
  XMFLOAT4 ローカルベクター
  XMFLOAT4 ライトの色
  XMFLOAT4 自然光
*******************************************************************************/
struct Light {
	XMFLOAT4 localLightVector;
	XMFLOAT4 lightColor;
	XMFLOAT4 ambientColor;
};

/*******************************************************************************
* グローバル変数
*******************************************************************************/
static XMVECTOR g_WorldLightVector;
static Light g_Light;
static ID3D11Buffer* g_LightBuffer = NULL;

/*******************************************************************************
* 初期化処理
*******************************************************************************/
void InitLight(void)
{

	D3D11_BUFFER_DESC hBufferDesc = {};
	hBufferDesc.ByteWidth = sizeof(Light);
	hBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	hBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	hBufferDesc.CPUAccessFlags = 0;
	hBufferDesc.MiscFlags = 0;
	hBufferDesc.StructureByteStride = sizeof(float);

	GetDevice()->CreateBuffer(&hBufferDesc, NULL, &g_LightBuffer);
	//ピクセルシェーダー
	GetDeviceContext()->PSSetConstantBuffers(3, 1, &g_LightBuffer);

}

/*******************************************************************************
* 終了処理処理
*******************************************************************************/
void UninitLight(void)
{
	if (g_LightBuffer) { GetDeviceContext()->Release(); }
}

/*******************************************************************************
* 終了処理処理
*******************************************************************************/
void SetDirectionalLight(const XMVECTOR& wolrdLightDir, const XMFLOAT4& color)
{
	g_WorldLightVector = XMVector3Normalize(wolrdLightDir);
	g_Light.lightColor = color;

}

/*******************************************************************************
* 終了処理処理
*******************************************************************************/
void SetAmbientColor(const XMFLOAT4& color)
{
	g_Light.ambientColor = color;
}

/*******************************************************************************
* ライトをセット
*******************************************************************************/
void SetLight(const XMMATRIX& world)
{

	XMVECTOR localLightVector = XMVector3TransformNormal(g_WorldLightVector, XMMatrixInverse(nullptr, world));

	XMStoreFloat4(&g_Light.localLightVector, XMVector3Normalize(localLightVector));

	GetDeviceContext()->UpdateSubresource(g_LightBuffer, 0, NULL, &g_Light.localLightVector, 0, 0);

}
