/*******************************************************************************
* タイトル:		ワールドクラス
* プログラム名:	World.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/12/02 ～
* 最終変更日:	2024/12/02
********************************************************************************/

/*******************************************************************************
* インクルードファイル
********************************************************************************/
#include "stdafx.h"
#include "World.h"
#include "GameObject.h"

/*******************************************************************************
* ゲームオブジェクトを登録
********************************************************************************/
void World::Register(GameObject* pObject)
{
	//最後尾にゲームオブジェクトを登録する
	m_pGameObjects.emplace_back(pObject);
	m_pGameObjects.back()->SetWorld(this);

	//pObject->SetWorld(this);

}

/*******************************************************************************
* 更新処理
********************************************************************************/
void World::Update()
{
	//世界の更新...つまり世界に存在するゲームオブジェクト全てを更新する
	for (const auto &pObject : m_pGameObjects) {
		pObject->Update();
	}
}

/*******************************************************************************
* 描画処理
********************************************************************************/
void World::Draw() const
{
	//世界の描画...つまり世界に存在するゲームオブジェクト全てを描画する
	for (const auto& pObject : m_pGameObjects) {
		pObject->Draw();
	}

}

/*******************************************************************************
* 更新後不必要になったゲームオブジェクトを破棄する
********************************************************************************/
void World::Cleanup()
{
	//更新後不要になったゲームオブジェクトを破棄する
	m_pGameObjects.remove_if([](const auto& pObject) {return pObject->IsDestroy();});
}

/*******************************************************************************
* タグを見つける
********************************************************************************/
GameObjects World::GetGameObjects(const std::string tag)
{
	//このコードでも数えられる
	//int count = std::count_if(m_pGameObjects.begin(), m_pGameObjects.end(),
	//	[tag](const GameObject* pObject) {return pObject->GetTag() == tag;});

	GameObjects ret;

	//対象を追加する
	for (const auto& pObject : m_pGameObjects) {
		if (pObject->GetTag() == tag) {
			ret.push_back(pObject.get());
		}
	}

	return ret;
}

/*******************************************************************************
* 当たり判定内のオブジェクトを見つける
********************************************************************************/
GameObjects World::GetGameObjects(const Circle& collision)
{

	//int count = std::count_if(m_pGameObjects.begin(), m_pGameObjects.end(),
	//[collision](const GameObject* pObject) {return collision.intersects(pObject->GetCollision()); });

	GameObjects ret;

	//対象を追加する
	for (const auto& pObject : m_pGameObjects) {
		if (collision.intersects(pObject->GetCollision())) {
			ret.push_back(pObject.get());
		}
	}

	return ret;
}
