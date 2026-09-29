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
#include "camera.h"


void Camera::SetMatrixView(const XMMATRIX& mtx)
{
	m_MtxView = mtx;
}

void Camera::SetMatrixPerspective(const XMMATRIX& mtx)
{
	m_MtxPerspective = mtx;
}

void Camera::Update()
{

	//カメラ
	m_MtxView =
		XMMatrixLookAtLH(
			m_Position,	//カメラの座標
			{ 0.0f,0.0f,0.0f },		//カメラの焦点
			{ 0.0,1.0f,0.0f }		//上ベクトル
		);

	//四推台
	m_MtxPerspective =
		XMMatrixPerspectiveFovLH(
			XM_PI / 3.0f,							//Y軸の角度
			(float)SCREEN_WIDTH / SCREEN_HEIGHT,	//アスペクト
			0.01f,			//near	//カメラが四推台に入ってはいけない
			1000.0f			//far				
		);


}
