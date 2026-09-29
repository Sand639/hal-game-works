/*******************************************************************************
* タイトル:		ワールドクラス
* プログラム名:	World.h
* 作成者:		大槻　海斗
* 作成日:		2024/12/02 ～
* 最終変更日:	2024/12/02
********************************************************************************/

#ifndef WORLD_H
#define WORLD_H

/*******************************************************************************
* インクルードファイル
********************************************************************************/
#include <string>
#include <list>
#include <vector>
#include <memory>

//前方宣言
class GameObject;

//型エイリアス
using GameObjects = std::list <GameObject*>;

/*******************************************************************************
* ワールドクラス
********************************************************************************/
class World
{
private:
	std::list<std::unique_ptr<GameObject>> m_pGameObjects;

public:

	World() = default;
	~World() = default;

	void Register(GameObject* pObject);

	void Update();
	void Draw() const;

	void Cleanup();

	GameObjects GetGameObjects(const std::string tag);
	GameObjects GetGameObjects(const Circle& collision);
};

#endif	//WORLD_H
