/*******************************************************************************
* タイトル:		弓矢クラス
* プログラム名:	Attack_Archer.h
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
class Attack_Archer : public GameObject
{
private:
	double m_AttackTime = Scene::Time();
	const Texture m_texture{ U"asset/弓.png" };
	int m_freamCounter = 0;

public:

	Attack_Archer(const Float2& location);
	Attack_Archer() : Attack_Archer({ 0.0f,0.0f }) {};


	void Update() override;
	void Draw() const override;

};


class Arrow : public GameObject {

	double m_AttackTime = Scene::Time();
	const Texture m_texture{ U"asset/矢.png" };
	int m_freamCounter = 0;
	Float2 m_PosA = { 0.0f,0.0f };
	Float2 m_PosB = { 0.0f,0.0f };

public:

	Arrow(const Float2& location) : GameObject("ATTACK_ARROW", location){}
	Arrow() : Arrow({ 0.0f,0.0f }) {};


	void Update() override;
	void Draw() const override;


};
