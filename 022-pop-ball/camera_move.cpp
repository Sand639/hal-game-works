/*******************************************************************************
* タイトル:		カメラの設定
* プログラム名:	camera.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/10/30 〜
* 最終変更日:	2024/10/30
********************************************************************************/
#define NOMINMAX

/*******************************************************************************
*　インクルードファイル
*******************************************************************************/
#include "camera_move.h"
#include "keyboard.h"
#include <algorithm>

/*******************************************************************************
* グローバル変数
*******************************************************************************/
static float g_YAngle = 0.0f;

void MovingCamera::Update()
{

	//移動
	if (Keyboard_IsKeyDown(KK_W)){
		//視点に左右されずに平行移動
		XMVECTOR v = XMVector3Normalize(XMVectorSetY(m_VecFront, 0.0f));
		SetPosition(GetPosition() + v * 0.1f);
	}

	if (Keyboard_IsKeyDown(KK_A)){
		SetPosition(GetPosition() - m_VecRight * 0.1f);
	}

	if (Keyboard_IsKeyDown(KK_S)){
		XMVECTOR v = XMVector3Normalize(XMVectorSetY(m_VecFront, 0.0f));
		SetPosition(GetPosition() - v * 0.1f);
	}

	if (Keyboard_IsKeyDown(KK_D)){
		SetPosition(GetPosition() + m_VecRight * 0.1f);
	}

	//上下
	if (Keyboard_IsKeyDown(KK_Q)){
		SetPosition(GetPosition() + m_VecTop * 0.1f);
	}

	if (Keyboard_IsKeyDown(KK_E)){
		SetPosition(GetPosition() - m_VecTop * 0.1f);
	}

	//視点操作
	if (Keyboard_IsKeyDown(KK_RIGHT)) {
		XMMATRIX rotation = XMMatrixRotationY(XM_PI / 180);
		m_VecFront = XMVector3TransformNormal(m_VecFront, rotation);
		m_VecRight = XMVector3Cross({ 0.0f,1.0f,0.0f }, m_VecFront);
	}

	if (Keyboard_IsKeyDown(KK_LEFT)) {
		XMMATRIX rotation = XMMatrixRotationY(-XM_PI / 180);
		m_VecFront = XMVector3TransformNormal(m_VecFront, rotation);
		m_VecRight = XMVector3Cross({ 0.0f,1.0f,0.0f }, m_VecFront);
	}

	if (Keyboard_IsKeyDown(KK_UP)) {


		XMMATRIX rotation = XMMatrixRotationAxis(m_VecRight, -XM_PI / 180);
		m_VecFront = XMVector3TransformNormal(m_VecFront, rotation);
		m_VecRight = XMVector3Cross({ 0.0f,1.0f,0.0f }, m_VecFront);

		g_YAngle -= XM_PI / 180;
		g_YAngle = std::max(g_YAngle, XMConvertToRadians(-90.0f));

	}

	if (Keyboard_IsKeyDown(KK_DOWN)) {
		XMMATRIX rotation = XMMatrixRotationAxis(m_VecRight, XM_PI / 180);

		m_VecFront = XMVector3TransformNormal(m_VecFront, rotation);
		m_VecRight = XMVector3Cross({ 0.0f,1.0f,0.0f }, m_VecFront);

		g_YAngle += XM_PI / 180;
		g_YAngle = std::min(g_YAngle, XMConvertToRadians(0.0f));


	}

	m_VecFront = XMVector3Normalize(m_VecFront);
	m_VecRight = XMVector3Normalize(m_VecRight);



	static float angle = 0.0f;
	if (Keyboard_IsKeyDown(KK_Z)) {
		angle += 0.01f;
	}

	if (Keyboard_IsKeyDown(KK_C)) {
		angle -= 0.01f;
	}


	//カメラ
	XMMATRIX view =XMMatrixLookAtLH(GetPosition(), GetPosition() + m_VecFront, { 0.0,1.0f,0.0f });

	//四推台
	XMMATRIX perspective = XMMatrixPerspectiveFovLH(XM_PI / 3.0f + angle, (float)SCREEN_WIDTH / SCREEN_HEIGHT, 0.01f, 1000.0f);

	SetMatrixView(view);
	SetMatrixPerspective(perspective);

}
