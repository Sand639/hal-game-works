/*******************************************************************************
* タイトル:		衝突判定
* プログラム名:	collision.h
* 作成者:		大槻　海斗
* 作成日:		2024/11/19 〜
* 最終変更日:	2024/11/19
********************************************************************************/

#ifndef _collision_H_
#define _collision_H_

/*******************************************************************************
* インクルード
*******************************************************************************/
#include "renderer.h"

/*******************************************************************************
* クラス定義
*******************************************************************************/

class AABB;
class Point;
class Sphere;

class Collision 
{
public:
	virtual bool isOverlap(const AABB& aabb) const = 0;
	virtual bool isOverlap(const Point& point) const = 0;
	virtual bool isOverlap(const Sphere& sphere) const = 0;

};

class AABB : public Collision 
{
private:
	XMFLOAT3 m_Min = { 0.0f,0.0f,0.0f };
	XMFLOAT3 m_Max = { 0.0f,0.0f,0.0f };
	XMFLOAT3 m_Center = { 0.0f,0.0f,0.0f };

public:
	//コンストラクタ
	AABB() = default;
	AABB(const XMFLOAT3& min, const XMFLOAT3& max);

	//ゲッター
	const XMFLOAT3& GetMinVertex()const {
		return m_Min;
	}

	const XMFLOAT3& GetMaxVertex()const {
		return m_Max;
	}

	const XMFLOAT3& GetCenterVertex()const {
		return m_Center;
	}

	AABB Trancelation(const XMVECTOR& move) const;

	bool isOverlap(const AABB& aabb) const override;

	bool isOverlap(const Point& point) const override;

	bool isOverlap(const Sphere& sphere) const override {
		return false;
	}

};

class Point :public Collision {
private:
	XMFLOAT3 m_Position = { 0.0f,0.0f,0.0f };

public:

	//コンストラクタ
	Point() = default;
	Point(const XMFLOAT3& position) : m_Position(position){}

	void SetPosition(const XMFLOAT3& position) {
		m_Position = position;
	}

	const XMFLOAT3& GetPosition() const { return m_Position; }

	bool isOverlap(const AABB& aabb) const override {
		return aabb.isOverlap(*this);
	}

	bool isOverlap(const Point& point) const override {
		return false;
	}

	bool isOverlap(const Sphere& sphere) const override {
		return false;
	}

};

class Sphere : public Collision {
private:
	XMFLOAT3 m_Center = { 0.0f,0.0f,0.0f };
	float m_Radius = 1.0f;

public:

	Sphere() = default;
	Sphere(const XMFLOAT3& center, float radius)
		:m_Center(center), m_Radius(radius){}

	Sphere Trancelation(const XMVECTOR& move) const;

	bool isOverlap(const AABB& aabb) const override {
		return false;
	}

	bool isOverlap(const Point& point) const override;

	bool isOverlap(const Sphere& sphere) const override {
		return false;
	}

};

#endif	//_collision_H_



