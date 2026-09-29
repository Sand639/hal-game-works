/*******************************************************************************
* タイトル:		カメラの設定
* プログラム名:	camera_rotation.h
* 作成者:		大槻　海斗
* 作成日:		2024/10/30 〜
* 最終変更日:	2024/10/30
********************************************************************************/

/*******************************************************************************
*　インクルードファイル
*******************************************************************************/
#include "camera.h"

#ifndef CAMERA_ROTATION_H
#define CAMERA_ROTATION_H


class RotationCamera : public Camera
{
private:

	XMVECTOR m_Target = { 0.0f,0.0f,0.0f };
	float m_Length = 10.0f;
	float m_PositionHeight = 10.0f;
	float m_Angle = 0.0f;

public:
	RotationCamera() = default;

	void Update() override;

	void SetTarget(const XMVECTOR& target) { m_Target = target; }
	
};

#endif	//CAMERA_ROTATION_H
