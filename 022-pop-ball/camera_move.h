/*******************************************************************************
* タイトル:		カメラの設定
* プログラム名:	camera_move.h
* 作成者:		大槻　海斗
* 作成日:		2024/10/30 〜
* 最終変更日:	2024/10/30
********************************************************************************/

/*******************************************************************************
*　インクルードファイル
*******************************************************************************/
#include "camera.h"

#ifndef CAMERA_MOVE_H
#define CAMERA_MOVE_H


class MovingCamera : public Camera
{
private:

	XMVECTOR m_VecFront = { 0.0f,0.0f,1.0f };
	XMVECTOR m_VecRight = { 1.0f,0.0f,0.0f };
	XMVECTOR m_VecTop   = { 0.0f,1.0f,0.0f };

public:
	MovingCamera(){}

	MovingCamera(const XMVECTOR& position) { SetPosition(position); }

	void Update() override;


};

#endif	//CAMERA_MOVE_H