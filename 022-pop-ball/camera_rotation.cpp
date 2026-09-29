/*******************************************************************************
* タイトル:		カメラの設定
* プログラム名:	camera.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/10/30 〜
* 最終変更日:	2024/10/30
********************************************************************************/

/*******************************************************************************
*　インクルードファイル
*******************************************************************************/
#include "camera_rotation.h"
#include "keyboard.h"



void RotationCamera::Update()
{

	if (Keyboard_IsKeyDown(KK_R)) {
		m_Angle += 0.05f;
	}

	if (Keyboard_IsKeyDown(KK_T)) {
		m_Angle -= 0.05f;
	}


	XMVECTOR position = { 0.0f,m_PositionHeight,m_Length };
	XMMATRIX rotation = XMMatrixRotationY(m_Angle);
	XMMATRIX translation = XMMatrixTranslationFromVector(m_Target);
	position = XMVector3TransformCoord(position, rotation * translation);

	//カメラ
	XMMATRIX view = XMMatrixLookAtLH(position, m_Target, { 0.0,1.0f,0.0f });

	//四推台
	XMMATRIX perspective = XMMatrixPerspectiveFovLH(XM_PI / 3.0f, (float)SCREEN_WIDTH / SCREEN_HEIGHT, 0.01f, 1000.0f);

	SetMatrixView(view);
	SetMatrixPerspective(perspective);

}
