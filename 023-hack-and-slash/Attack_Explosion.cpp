/*******************************************************************************
* タイトル:		爆発クラス
* プログラム名:	Attack_Explosion.cpp
* 作成者:		大槻　海斗
* 作成日:		2025/01/24 ～
* 最終変更日:	2025/01/24
********************************************************************************/

/*******************************************************************************
* インクルードファイル
********************************************************************************/
#include "stdafx.h"
#include "Attack_Explosion.h"
#include "World.h"

static constexpr float PI = 3.141519;

/*******************************************************************************
* 更新処理
********************************************************************************/
void DropPoint::Update()
{
	SetLocation(Cursor::Pos());

	static const double ATTACK_TIME = 1.0;

	//左クリックで爆発
	if (MouseL.pressed()){
		GetWorld()->Register(new Attack_Explosion(GetLocation()));
		SetDestroy(true);
	}
	
	
}

/*******************************************************************************
* 描画処理
********************************************************************************/
void DropPoint::Draw() const
{

	m_texture.resized(m_texture.size() * 3).drawAt(GetLocation());
}


/*******************************************************************************
* 更新処理
********************************************************************************/
void Attack_Explosion::Update()
{

	SetCollision({ GetLocation(),m_texture.size().x * 2});

	GameObjects objects = GetWorld()->GetGameObjects(GetCollision());

	//GameObjectが"PLAYER"タグでなかったら攻撃を加える
	for (auto it : objects) {
		if (it->GetTag() == "PLAYER") { continue; }
		it->Damage(1);
	}

	static const double ATTACK_TIME = 1.5;

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
void Attack_Explosion::Draw() const
{
	m_texture.resized(m_texture.size() * 3).drawAt(GetLocation());
}
