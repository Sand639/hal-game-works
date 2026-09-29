/*******************************************************************************
* タイトル:		プレイヤークラス
* プログラム名:	Player.h
* 作成者:		大槻　海斗
* 作成日:		2024/12/02 ～
* 最終変更日:	2024/12/02
********************************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

//前方宣言
class Attack;

//グローバル定数
static constexpr int MAX_HP = 100;

/*******************************************************************************
* インクルードファイル
********************************************************************************/
#include "GameObject.h"
#include <memory>
#include "EquipmentWeapon.h"

/*******************************************************************************
* プレイヤークラス
********************************************************************************/
class Player : public GameObject
{
private:
	const Texture m_texture{ U"asset/p.png" };
	double m_CoolTime01 = 0.0;
	double m_CoolTime02 = 0.0;
	double m_CoolTime03 = 0.0;
	double m_CoolTime04 = 0.0;
	double m_DamegeCoolTime = 0.0;
	Float2 m_WillPos = { 0.0f,0.0f };
	Float2 m_Vel = { 0.0f,0.0f };

	std::unique_ptr<GameObject> m_UI_HP;

	std::unique_ptr<EquipmentWeapon> m_pEquipmentWeapon;

public:

	Player(const Float2& location);
	Player() : Player({0.0f,0.0f}) {};

	Circle GetCollision() const override { return { GetLocation(), 32 }; }

	void Equipment(EquipmentWeapon* pEquipmentWeapon) {
		m_pEquipmentWeapon.reset(pEquipmentWeapon);
	}

	void Update() override;
	void Draw() const override;

	void Damage(int) override;
	void Heal() override;
};

#endif // PLAYER_H
