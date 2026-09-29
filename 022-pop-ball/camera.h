#pragma once
/*******************************************************************************
* タイトル:		カメラの設定
* プログラム名:	camera.h
* 作成者:		大槻　海斗
* 作成日:		2024/10/30 〜
* 最終変更日:	2024/12/18
********************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "main.h"

#ifndef CAMERA_H
#define CAMERA_H

class Camera
{
private:

	XMMATRIX m_MtxView = XMMatrixIdentity();
	XMMATRIX m_MtxPerspective = XMMatrixIdentity();
	XMVECTOR m_Position;

protected:

	void SetMatrixView(const XMMATRIX& mtx);
	void SetMatrixPerspective(const XMMATRIX& mtx);

	void SetPosition(const XMVECTOR& position) { m_Position = position; }

public:

	Camera() : m_Position({ 0.0f,0.0f,-5.0f }){}

	virtual void Update();

	const XMMATRIX& GetMatrixView() const { return m_MtxView; }

	const XMMATRIX& GetMatrixPersoective() const { return m_MtxPerspective; }

	const XMMATRIX& GetMatrixCamera() const { return m_MtxView * m_MtxPerspective; }

	const XMVECTOR& GetPosition() const { return m_Position; }


};

#endif	//CAMERA_H