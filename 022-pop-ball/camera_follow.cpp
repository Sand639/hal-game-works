/*******************************************************************************
* タイトル:		追従カメラの設定
* プログラム名:	camera_follow.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/11/14 〜
* 最終変更日:	2024/11/14
********************************************************************************/
#define NOMINMAX

/*******************************************************************************
*　インクルードファイル
*******************************************************************************/
#include "camera_follow.h"
#include "keyboard.h"
#include "Game_Main.h"
#include <algorithm>

static float g_XAngle = XMConvertToRadians(180.0f);
static float g_YAngle = 0.0f;


void Following_Camera::Update()
{
	static float direction = -10.0f;
	static float maxAngle = 60.0f;
	static float minAngle = -100.0f;

	Ball*  player = GetBallPointer();
	
	//回転
	if (Keyboard_IsKeyDown(KK_UP)) {
		g_YAngle += XMConvertToRadians(1.0f);

		//m_VecFront = XMVector3TransformNormal(m_VecFront, XMMatrixRotationAxis(m_VecRight, -XM_PI / 180));
		//m_VecRight = XMVector3Cross({ 0.0f,1.0f,0.0f }, m_VecFront);

	}

	if (Keyboard_IsKeyDown(KK_LEFT)) {
		g_XAngle -= XMConvertToRadians(1.0f);
		//m_VecFront = XMVector3TransformNormal(m_VecFront, XMMatrixRotationY(-XM_PI / 180));
		//m_VecRight = XMVector3Cross({ 0.0f,1.0f,0.0f }, m_VecFront);
	}

	if (Keyboard_IsKeyDown(KK_DOWN)) {
		g_YAngle -= XMConvertToRadians(1.0f);

		//m_VecFront = XMVector3TransformNormal(m_VecFront, XMMatrixRotationAxis(m_VecRight, XM_PI / 180));
		//m_VecRight = XMVector3Cross({ 0.0f,1.0f,0.0f }, m_VecFront);


	}

	if (Keyboard_IsKeyDown(KK_RIGHT)) {
		g_XAngle += XMConvertToRadians(1.0f);
		//m_VecFront = XMVector3TransformNormal(m_VecFront, XMMatrixRotationY(XM_PI / 180));
		//m_VecRight = XMVector3Cross({ 0.0f,1.0f,0.0f }, m_VecFront);
	}



	//カメラを近づける
	if (Keyboard_IsKeyDown(KK_Q)) {
		direction += 0.05f;
		direction = std::min(direction, -3.0f);
	}

	//カメラを遠ざける
	if (Keyboard_IsKeyDown(KK_E)) {
		direction -= 0.05f;
		direction = std::max(direction, -15.0f);
	}

	g_YAngle = std::min(g_YAngle, XMConvertToRadians(maxAngle - (direction + 10.0f) * 3.0f));
	g_YAngle = std::max(g_YAngle, XMConvertToRadians(minAngle - (direction + 10.0f) * 3.0f));

	m_VecFront = XMVector3Normalize(m_VecFront);
	m_VecRight = XMVector3Normalize(m_VecRight);



	XMFLOAT3 f_OfsetPosition = { 0.0f, 3.0f, direction };

	XMVECTOR position = XMVectorSet(
		f_OfsetPosition.x,
		f_OfsetPosition.y,
		f_OfsetPosition.z,
		1.0f
	);

	static XMMATRIX g_Matrix = XMMatrixIdentity();

	g_Matrix = XMMatrixRotationRollPitchYaw(g_YAngle, g_XAngle, 0.0f);


	//ターゲットの座標
	XMMATRIX translation = XMMatrixTranslationFromVector(player->GetPosition());

	//
	position = XMVector3TransformCoord(position, g_Matrix * translation);

	//カメラ
	XMMATRIX view = XMMatrixLookAtLH(position, player->GetPosition(), {0.0,1.0f,0.0f});

	//四推台
	XMMATRIX perspective = XMMatrixPerspectiveFovLH(XM_PI / 3.0f, (float)SCREEN_WIDTH / SCREEN_HEIGHT, 0.01f, 1000.0f);

	SetMatrixView(view);
	SetMatrixPerspective(perspective);

}
