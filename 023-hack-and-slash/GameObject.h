/*******************************************************************************
* タイトル:		ゲームオブジェクトクラス
* プログラム名:	GameObject.h
* 作成者:		大槻　海斗
* 作成日:		2024/11/25 ～
* 最終変更日:	2024/11/25
********************************************************************************/

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
/*******************************************************************************
* インクルードファイル
********************************************************************************/
#include <string>

enum DIRECTION {
	DIRECTION_TOP,
	DIRECTION_RIGHT,
	DIRECTION_BOTTOM,
	DIRECTION_LEFT
};

//前方宣言
class World;

/*******************************************************************************
* ゲームオブジェクトクラス
********************************************************************************/
class GameObject
{
private:
	World* m_pWorld = nullptr;
	Float2 m_Location = { 0.0f,0.0f };
	Float2 m_CenterPos = { 0.0f,0.0f };
	bool m_Destroy = false;
	std::string m_Tag;
	Circle m_Circle{ 20 };
	int m_HP = 100;
	float m_speed = 200.0f;
	const float MAX_SPEED = 500.0f;
	const float MIN_SPEED = 100.0f;

	DIRECTION m_Direction = DIRECTION_RIGHT;
protected:
	void SetDestroy(bool destroy) { m_Destroy = destroy; }

public:

	GameObject() = default;

	GameObject(const std::string& tag) : m_Tag(tag) {}

	GameObject(const Float2& location) : m_Location(location) {}

	GameObject(const std::string& tag, const Float2& location)
		: m_Tag(tag), m_Location(location) {
	}

	virtual ~GameObject() = default;


	virtual void Update() = 0;
	virtual void Draw() const = 0;
	virtual void Damage(int) {};
	virtual void Heal() {};
	virtual void SpeedUp() { m_speed += 50.0f; if (MAX_SPEED <= m_speed) { m_speed = MAX_SPEED; } };
	virtual void SpeedDown() {m_speed -= 50.0f; if (MIN_SPEED >= m_speed) { m_speed = MIN_SPEED; }};

	bool IsDestroy() const { return m_Destroy; }

	//セッター/ゲッター
	void SetLocation(const Float2& location) { m_Location = location; }

	virtual Circle GetCollision() const { return m_Circle; }
	void SetCollision(const Circle& c) { m_Circle = c; }

	void SetWorld(World* pWorld) { m_pWorld = pWorld; }
	World* GetWorld()const { return m_pWorld; }

	void SetTag(const std::string& tag) { m_Tag = tag; }
	const Float2& GetLocation() const { return m_Location; }
	const std::string& GetTag() const { return m_Tag; }
	int GetHP() { return m_HP; }
	void SetHP(int HP) { m_HP = HP; }
	float GetSpeed() { return m_speed; }
	void SetSpeed(float speed) { m_speed = speed; }
	DIRECTION GetDirection() const { return m_Direction; }
	void SetDirection(DIRECTION direction) { m_Direction = direction; }


};


//class GameObjects
//{
//private:
//	GameObject** m_pGameObjects;
//	int m_Count = 0;
//public:
//
//	GameObjects() = default;
//	GameObjects(int num) : m_Count(num) {
//		m_pGameObjects = new GameObject * [num];
//	}
//
//	~GameObjects() {
//		delete[] m_pGameObjects;
//	}
//
//	GameObject* GetGameObject(int index) const {
//		return m_pGameObjects[index];
//	}
//
//	int GetCount() const { return m_Count; }
//
//	void SetGameObject(int index, GameObject* pObject) {
//		m_pGameObjects[index] = pObject;
//	}
//
//};

#endif	//GAMEOBJECT_H
