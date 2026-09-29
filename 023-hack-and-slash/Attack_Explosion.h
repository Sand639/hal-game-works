/*******************************************************************************
* タイトル:		爆発クラス
* プログラム名:	Attack_Explosion.h
* 作成者:		大槻　海斗
* 作成日:		2025/01/24 ～
* 最終変更日:	2025/01/24
********************************************************************************/
#pragma once
/*******************************************************************************
* インクルードファイル
********************************************************************************/
#include "GameObject.h"

/*******************************************************************************
* 攻撃クラス
********************************************************************************/
class DropPoint : public GameObject {

	double m_AttackTime = Scene::Time();
	const Texture m_texture{ U"asset/落下地点.png" };

public:

	DropPoint(const Float2& location) : GameObject("DropPoint", location) {}
	DropPoint() : DropPoint({ 0.0f,0.0f }) {};


	void Update() override;
	void Draw() const override;


};

class Attack_Explosion : public GameObject
{
private:
	double m_AttackTime = Scene::Time();
	const Texture m_texture{ U"asset/爆発エフェクト.png" };
	int m_freamCounter = 0;

public:

	Attack_Explosion(const Float2& location) : GameObject("ATTACK_EXPLOSION", location) {}
	Attack_Explosion() : Attack_Explosion({ 0.0f,0.0f }) {};


	void Update() override;
	void Draw() const override;

};
