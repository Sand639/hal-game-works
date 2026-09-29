/*******************************************************************************
* タイトル:		敵クラス
* プログラム名:	Enemy.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/12/02 ～
* 最終変更日:	2024/12/02
********************************************************************************/

/*******************************************************************************
* インクルードファイル
********************************************************************************/
#include "stdafx.h"
#include "Enemy.h"
#include "world.h"
#include "Item_Heal.h"
#include "Item_Speeder.h"

/*******************************************************************************
* 更新処理
********************************************************************************/
void Enemy::Update()
{
	float MOVE_SPEED_BY_SEC = static_cast<float>(Scene::DeltaTime() * 50.0);

	GameObjects objects = GetWorld()->GetGameObjects("PLAYER");

	//プレイヤーは世界に存在しているか？
	if (objects.empty()) {
		return;
	}

	//プレイヤーはどこ？
	Float2 player_location = objects.front()->GetLocation();

	//自分からプレイヤーへのベクトル
	Float2 to_player = (player_location - GetLocation()).normalized();

	//プレイヤーに向かって移動
	SetLocation(GetLocation() + to_player * MOVE_SPEED_BY_SEC);
}
/*******************************************************************************
* 描画処理
********************************************************************************/
void Enemy::Draw() const
{
	m_Texture.drawAt(GetLocation(), Palette::Red);
}

void Enemy::Damage(int damage)
{
	m_HP -= damage;

	if (m_HP < 0) {

		int random = (rand() % 100 + 1);

		if (random <= 40) {
			random = (rand() % 100 + 1);

			if (random <= 50) {
				GetWorld()->Register(new Item_Heal(GetLocation()));
			}
			else {
				GetWorld()->Register(new Item_Speeder(GetLocation()));
			}
		}

		SetDestroy(true);
	}

}
