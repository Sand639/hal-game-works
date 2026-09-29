/*******************************************************************************
* タイトル:		バットクラス
* プログラム名:	Attack_Bat.cpp
* 作成者:		大槻　海斗
* 作成日:		2025/01/24 ～
* 最終変更日:	2025/01/24
********************************************************************************/

/*******************************************************************************
* インクルードファイル
********************************************************************************/
#include "stdafx.h"
#include "Attack_Bat.h"
#include "World.h"

static constexpr float PI = 3.141519;

Attack_Bat::Attack_Bat(const Float2& location)
	: GameObject("ATTACK_BAT", location)
{

}

/*******************************************************************************
* 更新処理
********************************************************************************/
void Attack_Bat::Update()
{
	GameObjects objects = GetWorld()->GetGameObjects("PLAYER");

	if (m_freamCounter == 0) {
		//最初に出現場所を決める(コンストラクタだとObjectを探せない)
		if (objects.front()->GetDirection() == DIRECTION_RIGHT) {
			SetLocation({ GetLocation().x + 100.0f,GetLocation().y });
		}
		else if (objects.front()->GetDirection() == DIRECTION_LEFT) {
			SetLocation({ GetLocation().x - 100.0f,GetLocation().y });
			m_angle = -m_angle;
		}
		else {

		}
	}

	if (m_angle < 0) {
		m_angle -= 5.0f;
		m_angle = std::max(-120.0f, m_angle);
	}
	else {
		m_angle += 5.0f;
		m_angle = std::min(120.0f, m_angle);
	}

	SetCollision({ GetLocation(), m_texture.size().y - 30.0f});

	objects = GetWorld()->GetGameObjects(GetCollision());

	//GameObjectが"PLAYER"タグでなかったら攻撃を加える
	for (auto it : objects) {
		if (it->GetTag() == "PLAYER") { continue; }
		it->Damage(1);
	}

	static const double ATTACK_TIME = 1.0;

	//1秒経過後削除
	if (Scene::Time() - m_AttackTime >= ATTACK_TIME) {
		//すぐ消える
		SetDestroy(true);
	}

	m_freamCounter++;
}

/*******************************************************************************
* 描画処理
********************************************************************************/
void Attack_Bat::Draw() const
{
	m_texture.rotated(PI / 180 * m_angle).drawAt(GetLocation());
}
