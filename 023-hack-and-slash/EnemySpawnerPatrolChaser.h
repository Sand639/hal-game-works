/*******************************************************************************
* タイトル:		警戒してチェイスする敵のスポナークラス
* プログラム名: EnemySpawnerPatrolChaser.h
* 作成者:		大槻　海斗
* 作成日:		2025/02/10 ～
* 最終変更日:	2025/02/10
********************************************************************************/
#pragma once

/*******************************************************************************
* インクルードファイル
********************************************************************************/
#include "EnemySpawner.h"
#include <vector>

/*******************************************************************************
* 敵状態クラス
********************************************************************************/
class EnemySpawnerPatrolChaser : public EnemySpawner {

private:
	double m_SpawnTime = 0.0;
	std::vector<Float2> m_PatrolPoints;


public:
	EnemySpawnerPatrolChaser(const std::vector<Float2>& patrolPoints)
		: EnemySpawner(patrolPoints.front()), m_PatrolPoints(patrolPoints){}

	void Update() override;

};
