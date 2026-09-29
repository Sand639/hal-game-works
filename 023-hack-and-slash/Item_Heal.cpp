/*******************************************************************************
* タイトル:		回復アイテムクラス
* プログラム名:	Item_Heal.cpp
* 作成者:		大槻　海斗
* 作成日:		2025/01/24 ～
* 最終変更日:	2025/01/24
********************************************************************************/

/*******************************************************************************
* インクルードファイル
********************************************************************************/
#include "stdafx.h"
#include "Item_Heal.h"
#include "World.h"
#include "Effect_Heal.h"

Item_Heal::Item_Heal(const Float2& location)
	: GameObject("ITEM_HEAL", location)
{
	SetCollision({ GetLocation(), m_texture.size().x });
}

/*******************************************************************************
* 更新処理
********************************************************************************/
void Item_Heal::Update()
{


	//攻撃範囲にGameObjectがいるか？
	GameObjects objects = GetWorld()->GetGameObjects(GetCollision());

	//GameObjectが"PLAYER"タグでだったら回復させる
	for (auto it : objects) {

		if (it->GetTag() == "PLAYER") {
			it->Heal();
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
void Item_Heal::Draw() const
{
	m_texture.drawAt(GetLocation());
}
