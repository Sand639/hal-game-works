/*******************************************************************************
* タイトル:		警戒してチェイスする敵クラス
* プログラム名:	EnemyPatrolChaser.h
* 作成者:		大槻　海斗
* 作成日:		2025/02/10 ～
* 最終変更日:	2025/02/10
* 詳細	:		警戒(プレイヤーを見つけるために特定の動きをおこなう)
*				チェイス(墺レイヤーを発見したら追従する)
********************************************************************************/
#pragma once

/*******************************************************************************
* インクルードファイル
********************************************************************************/
#include "Enemy.h"
#include <memory>
#include <vector>

/*******************************************************************************
* 前方宣言
********************************************************************************/
class EnemyState;

/*******************************************************************************
* 警戒してチェイスする敵クラス
********************************************************************************/
class EnemyPatrolChaser : public Enemy{

private:
	std::unique_ptr<EnemyState> m_pState;
	std::unique_ptr<EnemyState> m_pNextState;
	std::vector<Float2> m_PatrolPoints;

public:
	EnemyPatrolChaser(const std::vector<Float2>& patrolPoints);
	EnemyPatrolChaser() = delete;
	virtual ~EnemyPatrolChaser() = default;

	void Update() override;

	const std::vector<Float2>& GetPatrolPoints() const { return m_PatrolPoints; }

	void ChangeStatePatrol(int targetPointIndex);
	void ChangeStateChase();

	Circle GetTerritory() const { return { GetLocation(), 120 }; }

};
