/*******************************************************************************
* タイトル:		弓矢クラス
* プログラム名:	Attack_Archer.cpp
* 作成者:		大槻　海斗
* 作成日:		2025/01/24 ～
* 最終変更日:	2025/01/24
********************************************************************************/

/*******************************************************************************
* インクルードファイル
********************************************************************************/
#include "stdafx.h"
#include "Attack_Archer.h"
#include "World.h"

static constexpr float PI = 3.141519;

double easeInBack(double t) {
	return t * t * (2.70158 * t - 1.70158);
}

Attack_Archer::Attack_Archer(const Float2& location)
	: GameObject("ATTACK_ARCHER", location)
{

}

/*******************************************************************************
* 更新処理
********************************************************************************/
void Attack_Archer::Update()
{
	GameObjects objects = GetWorld()->GetGameObjects("PLAYER");

	if (m_freamCounter == 0) {
		//最初に出現場所を決める(コンストラクタだとObjectを探せない)
		if (objects.front()->GetDirection() == DIRECTION_RIGHT) {
			SetLocation({ GetLocation().x + 50.0f,GetLocation().y });
		}
		else if (objects.front()->GetDirection() == DIRECTION_LEFT) {
			SetLocation({ GetLocation().x - 50.0f,GetLocation().y });
		}
		else {

		}
		SetDirection(objects.front()->GetDirection());
	}

	static const double ATTACK_TIME = 1.0;

	//1秒経過後削除
	if (Scene::Time() - m_AttackTime >= ATTACK_TIME) {
		//すぐ消える
		SetDestroy(true);
	}

	if (m_freamCounter == 29) {
		GetWorld()->Register(new Arrow(GetLocation()));
	}

	m_freamCounter++;
}

/*******************************************************************************
* 描画処理
********************************************************************************/
void Attack_Archer::Draw() const
{
	if (GetDirection() == DIRECTION_RIGHT) {
		m_texture.drawAt(GetLocation());

	}
	else {
		m_texture.mirrored().drawAt(GetLocation());
	}

}


/*******************************************************************************
* 更新処理
********************************************************************************/
void Arrow::Update()
{
	static float TurningPos = 0.0f;

	if (m_freamCounter == 0) {

		m_PosA = GetLocation();
		GameObjects objects = GetWorld()->GetGameObjects("ATTACK_ARCHER");

		if (objects.front()->GetDirection() == DIRECTION_RIGHT) {
			m_PosB = { m_PosA.x + 300.0f,m_PosA.y };
			TurningPos = m_texture.size().x / 2;
		}
		else {
			m_PosB = { m_PosA.x - 300.0f,m_PosA.y };
			TurningPos = -m_texture.size().x / 2;
		}
		SetDirection(objects.front()->GetDirection());

	}

	SetCollision({ {GetLocation().x + TurningPos,GetLocation().y},10.0f});

	GameObjects objects = GetWorld()->GetGameObjects(GetCollision());

	//GameObjectが"PLAYER"タグでなかったら攻撃を加える
	for (auto it : objects) {
		if (it->GetTag() == "PLAYER") { continue; }
		it->Damage(50);
	}

	static const double ATTACK_TIME = 1.5;

	//1秒経過後削除
	if (Scene::Time() - m_AttackTime >= ATTACK_TIME) {
		//すぐ消える
		SetDestroy(true);
	}

	float t = (float)m_freamCounter / 90;
	t = easeInBack(t);

	SetLocation(m_PosA + ((m_PosB - m_PosA) * t));
	
	m_freamCounter++;

}

/*******************************************************************************
* 描画処理
********************************************************************************/
void Arrow::Draw() const
{
	if (GetDirection() == DIRECTION_RIGHT) {
		m_texture.drawAt(GetLocation());

	}
	else {
		m_texture.mirrored().drawAt(GetLocation());
	}

}
