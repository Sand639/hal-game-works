/*******************************************************************************
* タイトル:		警戒してチェイスする敵クラス
* プログラム名:	EnemyPatrolChaser.cpp
* 作成者:		大槻　海斗
* 作成日:		2025/02/10 ～
* 最終変更日:	2025/02/10
********************************************************************************/

/*******************************************************************************
* インクルードファイル
********************************************************************************/
#include "stdafx.h"
#include "EnemyPatrolChaser.h"
#include "EnemyState.h"

/*******************************************************************************
* コンストラクタ
********************************************************************************/
EnemyPatrolChaser::EnemyPatrolChaser(const std::vector<Float2>& patrolPoints)
	:Enemy(patrolPoints.front()), m_PatrolPoints(patrolPoints), m_pState(new EnemyStatePatrol(this, 1))
{

}

/*******************************************************************************
* 更新処理
********************************************************************************/
void EnemyPatrolChaser::Update()
{

	if (m_pNextState) {
		m_pState = std::move(m_pNextState);
	}

	m_pState->Update();

}

/*******************************************************************************
* 目的地点を変更
********************************************************************************/
void EnemyPatrolChaser::ChangeStatePatrol(int targetPointIndex)
{
	m_pNextState = std::make_unique<EnemyStatePatrol>(this, targetPointIndex);
}

/*******************************************************************************
* 状態を変更
********************************************************************************/
void EnemyPatrolChaser::ChangeStateChase()
{
	m_pNextState = std::make_unique<EnemyStateChase>(this);
	//m_pNextState.reset(new EnemyStateChase(this));
}
