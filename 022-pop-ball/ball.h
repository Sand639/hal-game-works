/*******************************************************************************
* タイトル:		ボールの表示
* プログラム名:	ball.h
* 作成者:		大槻　海斗
* 作成日:		2024/11/19 〜
* 最終変更日:	2024/11/19
********************************************************************************/

#ifndef _ball_H_
#define _ball_H_
/*******************************************************************************
* インクルード
*******************************************************************************/
#include "collision.h"
#include "model.h"

/*******************************************************************************
* クラス定義
*******************************************************************************/
class Ball
{
private:
	XMVECTOR m_Position;
	XMVECTOR m_Acceleration = { 0.0f,0.0f,0.0f };
	MODEL* m_pModel = nullptr;
	bool m_isOverlap = false;
	int m_frame = 0;
public:
	//コンストラクタ
	Ball() = default;
	Ball(const XMVECTOR& position) : m_Position(position){}

	//デストラクタ
	~Ball() {
		ModelRelease();
	}

	//モデルの読み込み
	void ModelLoad();

	//モデルの解放
	void ModelRelease();

	void Update();
	void Draw() const;

	bool IsStopped() const {
		return XMVectorGetX(XMVector3LengthEst(m_Acceleration)) < 0.002f;
		//return XMVectorGetX(XMVector3Length(m_Acceleration)) <= 0.001f * 0.3f;
	}

	void AddForce(const XMVECTOR& force) {
		m_Acceleration += force;
	}

	XMVECTOR GetPosition() const {
		return m_Position;
	}

	void SetPosition(const XMVECTOR& position) {
		m_Position = position;
	}


	AABB GetAABB()const {
		return m_pModel->aabb.Trancelation(m_Position);
	}

	void OnOverlap() { m_isOverlap = true; };

	bool OnHit(const AABB& aabb);
};

#endif	//_ball_H_


