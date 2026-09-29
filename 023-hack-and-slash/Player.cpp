/*******************************************************************************
* タイトル:		プレイヤークラス
* プログラム名:	Player.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/12/02 ～
* 最終変更日:	2024/12/02
********************************************************************************/

/*******************************************************************************
* インクルードファイル
********************************************************************************/
#include "stdafx.h"
#include "Player.h"
#include "World.h"
#include "Attack.h"
#include "Attack_Bat.h"
#include "Attack_Archer.h"
#include "Attack_Explosion.h"

Player::Player(const Float2& location) : GameObject("PLAYER", location) 
{

}

/*******************************************************************************
* 更新処理
********************************************************************************/
void Player::Update()
{
	float MOVE_SPEED_BY_SEC = static_cast<float>(Scene::DeltaTime() * GetSpeed());

	//// 上下左右キーで移動する
	//if (KeyW.pressed())
	//{
	//	SetLocation(GetLocation() + Float2{ 0.0f,-MOVE_SPEED_BY_SEC });
	//}

	//if (KeyA.pressed())
	//{
	//	SetLocation(GetLocation() + Float2{ -MOVE_SPEED_BY_SEC, 0.0f });
	//}

	//if (KeyS.pressed())
	//{
	//	SetLocation(GetLocation() + Float2{ 0.0f, MOVE_SPEED_BY_SEC });
	//}

	//if (KeyD.pressed())
	//{
	//	SetLocation(GetLocation() + Float2{ MOVE_SPEED_BY_SEC, 0.0f });
	//}


	if (KeyA.pressed())
	{
		static const double ATTACK_TIME_SPAN = 1.0;

		if (Scene::Time() - m_CoolTime04 >= ATTACK_TIME_SPAN) {

			//攻撃エフェクト発生
			//GetWorld()->Register(new Attack(GetLocation()));
			if (m_pEquipmentWeapon) {
				m_pEquipmentWeapon->Attack();
			}
			m_CoolTime04 = Scene::Time();
		}

	}

	if (KeyQ.pressed())
	{
		static const double ATTACK_TIME_SPAN = 1.0;

		if (Scene::Time() - m_CoolTime01 >= ATTACK_TIME_SPAN) {

			//攻撃エフェクト発生
			GetWorld()->Register(new Attack_Bat(GetLocation()));
			m_CoolTime01 = Scene::Time();
		}

	}

	if (KeyW.pressed())
	{
		static const double ATTACK_TIME_SPAN = 2.0;

		if (Scene::Time() - m_CoolTime02 >= ATTACK_TIME_SPAN) {

			//攻撃エフェクト発生
			GetWorld()->Register(new Attack_Archer(GetLocation()));
			m_CoolTime02 = Scene::Time();
		}

	}



	if (KeyE.pressed())
	{
		static const double ATTACK_TIME_SPAN = 2.0;

		if (Scene::Time() - m_CoolTime03 >= ATTACK_TIME_SPAN) {

			//攻撃エフェクト発生
			GetWorld()->Register(new DropPoint());
			m_CoolTime03 = Scene::Time();
		}
	}

	if (KeyS.pressed())
	{
		m_Vel = {0.0f, 0.0f};
	}



	//lol式移動
	if (MouseR.pressed()) //右クリックで移動
	{
		m_WillPos = Cursor::Pos();

		if ((m_WillPos.x - GetLocation().x) <= 0.0f) {
			m_Vel.x = -MOVE_SPEED_BY_SEC;
		}
		else {
			m_Vel.x = MOVE_SPEED_BY_SEC;
		}

		if ((m_WillPos.y - GetLocation().y) <= 0.0f) {
			m_Vel.y = -MOVE_SPEED_BY_SEC;
		}
		else {
			m_Vel.y = MOVE_SPEED_BY_SEC;
		}
	}
	else {
		if (abs(GetLocation().x - m_WillPos.x) <= 1.0f) {
			m_Vel *= {0.0f,1.0f};
		}
		else if (abs(GetLocation().y - m_WillPos.y) <= 1.0f) {
			m_Vel *= {1.0f, 0.0f};
		}

		if (m_Vel.x < 0.0f) {
			SetDirection(DIRECTION_LEFT);
		}
		else if(m_Vel.x > 0.0f){
			SetDirection(DIRECTION_RIGHT);

		}
	}

	SetCollision({ GetLocation(), m_texture.size().x });

	//攻撃範囲に敵がいるか？
	GameObjects objects = GetWorld()->GetGameObjects(GetCollision());

	static const double DAMAGE_TIME_SPAN = 2.0;

	//プレイヤーと敵接触でダメージ
	if (Scene::Time() - m_DamegeCoolTime >= DAMAGE_TIME_SPAN) {
		for (auto it : objects) {
			if (it->GetTag() == "ENEMY") {
				Damage(10);
				m_DamegeCoolTime = Scene::Time();
				break;
			}
		}
	}


	SetLocation(GetLocation() + m_Vel);

}

/*******************************************************************************
* 描画処理
********************************************************************************/
void Player::Draw() const
{
	m_texture.drawAt(GetLocation());

	if (m_pEquipmentWeapon) {
		m_pEquipmentWeapon->Draw();
	}
}

void Player::Damage(int damage)
{
	SetHP(GetHP() - damage);

	if (GetHP() <= 0) {
		//ゲームオーバー

	}
}

void Player::Heal()
{
	SetHP(GetHP() + 30);
	if (MAX_HP <= GetHP()) {
		SetHP(MAX_HP);
	}

}

