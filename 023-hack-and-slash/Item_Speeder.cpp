/*******************************************************************************
* タイトル:		スピードブースタークラス
* プログラム名:	Item_Speeder.cpp
* 作成者:		大槻　海斗
* 作成日:		2025/01/24 ～
* 最終変更日:	2025/01/24
********************************************************************************/

/*******************************************************************************
* インクルードファイル
********************************************************************************/
#include "stdafx.h"
#include "Item_Speeder.h"
#include "World.h"
#include "Effect_Heal.h"

Item_Speeder::Item_Speeder(const Float2& location)
	: GameObject("ITEM_SPEEDER", location)
{
	SetCollision({ GetLocation(), m_texture.size().x });
}

/*******************************************************************************
* 更新処理
********************************************************************************/
void Item_Speeder::Update()
{
	//攻撃範囲にGameObjectがいるか？
	GameObjects objects = GetWorld()->GetGameObjects(GetCollision());

	//GameObjectが"PLAYER"タグでだったら回復させる
	for (auto it : objects) {

		if (it->GetTag() == "PLAYER") {
			it->SpeedUp();
			//回復エフェクト
			GetWorld()->Register(new Effect_Heal(GetLocation()));
			
			SetDestroy(true);
			break;
		}
	}
}

/*******************************************************************************
* 描画処理
********************************************************************************/
void Item_Speeder::Draw() const
{
	m_texture.drawAt(GetLocation());
}
