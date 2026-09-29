/*******************************************************************************
* タイトル:		敵クラス
* プログラム名:	Enemy.h
* 作成者:		大槻　海斗
* 作成日:		2024/12/02 ～
* 最終変更日:	2024/12/02
********************************************************************************/

#ifndef ENEMY_H
#define ENEMY_H

/*******************************************************************************
* インクルードファイル
********************************************************************************/
#include "GameObject.h"

/*******************************************************************************
* 敵クラス
********************************************************************************/
class Enemy : public GameObject
{
private:
	const Texture m_Texture{ 0xF11EA_icon, 48 };

	int m_HP = 100;

public:

	Enemy(const Float2& location) : GameObject("ENEMY", location) {}
	Enemy() : Enemy({ 0.0f,0.0f }) {};
	virtual ~Enemy() = default;

	void Update() override;
	void Draw() const override;

	Circle GetCollision() const override { return { GetLocation(),24 }; }
	void Damage(int) override;

};

#endif // ENEMY_H
