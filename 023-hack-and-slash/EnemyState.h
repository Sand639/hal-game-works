/*******************************************************************************
* タイトル:		敵状態クラス
* プログラム名:	EnemyState.h
* 作成者:		大槻　海斗
* 作成日:		2025/02/10 ～
* 最終変更日:	2025/02/10
********************************************************************************/
#pragma once

/*******************************************************************************
* 前方宣言
********************************************************************************/
class EnemyPatrolChaser;

/*******************************************************************************
* 敵状態クラス
********************************************************************************/
class EnemyState {

private:
	EnemyPatrolChaser* m_pOwner = nullptr;

public:
	EnemyState(EnemyPatrolChaser* pOwner) : m_pOwner(pOwner){}
	virtual ~EnemyState() = default;

	virtual void Update() = 0;

protected:
	EnemyPatrolChaser* GetOwner() const { return m_pOwner; }

};


class EnemyStatePatrol :public EnemyState {

private:
	int m_TargetPointIndex = 0;

public:
	EnemyStatePatrol(EnemyPatrolChaser* pOwner, int targetPointIndex)
		: EnemyState(pOwner), m_TargetPointIndex(targetPointIndex) {}

	void Update() override;
};

class EnemyStateChase : public EnemyState {

private:
	double m_LostTime = 0.0;


public:
	EnemyStateChase(EnemyPatrolChaser* pOwner) : EnemyState(pOwner){}

	void Update() override;

private:
	void returnToNearestLocation();


};
