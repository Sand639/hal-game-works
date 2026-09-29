/*******************************************************************************
* タイトル:		キューブの表示
* プログラム名:	collision.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/11/19 〜
* 最終変更日:	2024/11/19
********************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "collision.h"

/*******************************************************************************
* 引数付きコンストラクタ
*******************************************************************************/
AABB::AABB(const XMFLOAT3& min, const XMFLOAT3& max)
    :m_Min(min), m_Max(max)
{
    //m_Center.x = (max.x + min.x) * 0.5f;
    //m_Center.y = (max.y + min.y) * 0.5f;
    //m_Center.z = (max.z + min.z) * 0.5f;

    m_Center.x = min.x + (max.x - min.x) * 0.5f;
    m_Center.y = min.y + (max.y - min.y) * 0.5f;
    m_Center.z = min.z + (max.z - min.z) * 0.5f;
}

/*******************************************************************************
* AABBの移動値を足す
*******************************************************************************/
AABB AABB::Trancelation(const XMVECTOR& move) const
{
    AABB aabb;
    XMStoreFloat3(&aabb.m_Min, XMLoadFloat3(&m_Min) + move);
    XMStoreFloat3(&aabb.m_Max, XMLoadFloat3(&m_Max) + move);
    XMStoreFloat3(&aabb.m_Center, XMLoadFloat3(&m_Center) + move);
    return aabb;
}

/*******************************************************************************
* AABBとAABBが衝突しているかどうか
*******************************************************************************/
bool AABB::isOverlap(const AABB& aabb) const
{
    return 
        m_Min.x < aabb.m_Max.x &&
        m_Max.x > aabb.m_Min.x &&
        m_Min.y < aabb.m_Max.y &&
        m_Max.y > aabb.m_Min.y &&
        m_Min.z < aabb.m_Max.z &&
        m_Max.z > aabb.m_Min.z;
}

/*******************************************************************************
* AABBとPointが衝突しているかどうか
*******************************************************************************/
bool AABB::isOverlap(const Point& point) const
{
    return
        m_Min.x <= point.GetPosition().x &&
        m_Max.x >= point.GetPosition().x &&
        m_Min.y <= point.GetPosition().y &&
        m_Max.y >= point.GetPosition().y &&
        m_Min.z <= point.GetPosition().z &&
        m_Max.z >= point.GetPosition().z;

}

/*******************************************************************************
* Sphereの移動値を足す
*******************************************************************************/
Sphere Sphere::Trancelation(const XMVECTOR& move) const
{
    XMFLOAT3 center;
    XMStoreFloat3(&center, XMLoadFloat3(&m_Center) + move);

    return { center,m_Radius };
}

/*******************************************************************************
* SphereとPointが衝突しているかどうか
*******************************************************************************/
bool Sphere::isOverlap(const Point& point) const
{
    XMVECTOR StoP = XMLoadFloat3(&point.GetPosition()) - XMLoadFloat3(&m_Center);

    //return XMVector3LengthSq(StoP) < m_Radius * m_Radius;

    return false;
}

