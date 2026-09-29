/*******************************************************************************
* タイトル:		追従カメラの設定
* プログラム名:	camera_follow.h
* 作成者:		大槻　海斗
* 作成日:		2024/11/14 〜
* 最終変更日:	2024/11/14
********************************************************************************/

/*******************************************************************************
*　インクルードファイル
*******************************************************************************/
#include "camera.h"

#ifndef CAMERA_FOLLOW
#define CAMERA_FOLLOW


class Following_Camera : public Camera
{
private:

	XMVECTOR m_VecFront = { 0.0f,0.0f,1.0f };
	XMVECTOR m_VecRight = { 1.0f,0.0f,0.0f };
	XMVECTOR m_VecTop = { 0.0f,1.0f,0.0f };
	XMVECTOR m_Position = { 0.0f,3.0f,-10.0f };

public:
	Following_Camera() {}

	void Update() override;


};

#endif	//CAMERA_FOLLOW