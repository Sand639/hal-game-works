/*******************************************************************************
* タイトル:		ボールショット
* プログラム名:	ball_shot.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/12/10 〜
* 最終変更日:	2024/12/10
********************************************************************************/
#define NOMINMAX
/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "ball_shot.h"
#include "keyboard.h"
#include "model.h"
#include <algorithm>

/*******************************************************************************
* グローバル変数
*******************************************************************************/
static Ball *g_pBall = nullptr;
static XMVECTOR g_Velocity = { 0.0f,0.0f,0.0f };
static XMVECTOR g_Direction;
static XMMATRIX g_Matrix = XMMatrixIdentity();
static MODEL* m_pModel = nullptr;
static float g_XAngle = 0.0f;
static float g_YAngle = 0.0f;

void InitBallShot()
{
	//モデルを読み込み
	m_pModel = ModelLoad("asset/model/Arrow.fbx");

}

void UninitBallShot()
{
	if (m_pModel)
	{
		ModelRelease(m_pModel);
		m_pModel = nullptr;
	}
}

void SetBallShot(Ball* pBall)
{
	g_pBall = pBall;
}

void SetBallShotMatrix(const XMMATRIX& matrix)
{
	g_Matrix = matrix;
}

void UpdateBallShot()
{
	//XMFLOAT4X4 matrix;
	//XMStoreFloat4x4(&matrix, g_Matrix);
	////平行移動成分をカット
	//matrix._41 = matrix._42 = matrix._43 = 0.0f;
	//g_Matrix = XMLoadFloat4x4(&matrix);

	//XMMATRIX rotation = XMMatrixIdentity();

	XMMATRIX rotation = XMMatrixIdentity();

	if (Keyboard_IsKeyDown(KK_D)) {
		//rotation = XMMatrixRotationY(XM_PI / 180);
		g_XAngle += XMConvertToRadians(1.0f);
	}

	if (Keyboard_IsKeyDown(KK_A)) {
		//rotation = XMMatrixRotationY(-XM_PI / 180);
		g_XAngle -= XMConvertToRadians(1.0f);
	}

	if (Keyboard_IsKeyDown(KK_W)) {
		//rotation = XMMatrixRotationAxis({ 0.0f,1.0f,0.0f }, -XM_PI / 180);
		g_YAngle -= XMConvertToRadians(1.0f);
		g_YAngle = std::max(g_YAngle, XMConvertToRadians(-90.0f));

	}

	if (Keyboard_IsKeyDown(KK_S)) {
		//rotation = XMMatrixRotationAxis({ 0.0f,1.0f,0.0f }, XM_PI / 180);
		g_YAngle += XMConvertToRadians(1.0f);
		g_YAngle = std::min(g_YAngle, XMConvertToRadians(0.0f));
	}

	g_Matrix = XMMatrixRotationRollPitchYaw(g_YAngle, g_XAngle, 0.0f);

	//XMMATRIX x = XMMatrixRotationX(g_YAngle);
	//XMMATRIX y = XMMatrixRotationY(g_XAngle);
	//g_Matrix = x * y;

	g_Direction = XMVector3TransformNormal({ 0.0f,0.0f,1.0f }, g_Matrix);
	g_Velocity = XMVector3Normalize(g_Direction) * 0.1f;

}

void DrawBallShot()
{
	//矢印の描画

	//サイズ設定
	XMMATRIX s = XMMatrixScaling(0.3f, 0.3f, 0.3f);


	XMMATRIX t1 = XMMatrixTranslationFromVector(g_pBall->GetPosition());
	XMMATRIX t0 = XMMatrixTranslation(0.0f, 0.0f, 0.7f);
	XMMATRIX world = s * t0 * g_Matrix * t1;

	ModelDraw(m_pModel, world);

}

const XMVECTOR& GetBallShotVelocity()
{
	return g_Velocity;
}
