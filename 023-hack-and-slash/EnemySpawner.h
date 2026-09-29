/*******************************************************************************
* タイトル:		敵スポナークラス
* プログラム名:	EnemySpawner.h
* 作成者:		大槻　海斗
* 作成日:		2024/12/02 ～
* 最終変更日:	2024/12/02
********************************************************************************/

#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H

/*******************************************************************************
* インクルードファイル
********************************************************************************/
#include "GameObject.h"

/*******************************************************************************
* エネミースポナークラス
********************************************************************************/
class EnemySpawner : public GameObject
{
private:
	const Texture m_Texture{ 0xF0BCA_icon, 64 };
	double m_SpawnTime = 0.0;

public:

	EnemySpawner(const Float2& location) : GameObject("ENEMYSPAWNER", location) {}
	EnemySpawner() : EnemySpawner({ 0.0f,0.0f }) {};


	void Update() override;
	void Draw() const override;


};

#endif // ENEMYSPAWNER_H
