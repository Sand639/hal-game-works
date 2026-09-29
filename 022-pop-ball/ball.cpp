/*******************************************************************************
* タイトル:		ボールの表示
* プログラム名:	ball.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/11/20 〜
* 最終変更日:	2024/11/20
********************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "ball.h"
#include "Audio.h"

/*******************************************************************************
*　グローバル変数
*******************************************************************************/
//サウンドを表す変数
static int SE_ID;


/*******************************************************************************
* モデルの読み込み
*******************************************************************************/
void Ball::ModelLoad(){

	//C言語の関数名とクラスの関数名が同じになってしまった場合は　::　で対処できる
	m_pModel = ::ModelLoad("asset/model/ball.fbx");

	//サウンドデータの読み込み
	SE_ID = LoadAudio("asset\\Audio\\キックの素振り1.wav");


}

/*******************************************************************************
* モデルの開放
*******************************************************************************/
void Ball::ModelRelease(){

	if (m_pModel) { 
		::ModelRelease(m_pModel);
		m_pModel = nullptr;
	}	


}

/*******************************************************************************
* 更新処理
*******************************************************************************/
void Ball::Update()
{

	m_Position += m_Acceleration;
	m_Acceleration += {0.0f, -0.001f, 0.0f};


	if (m_isOverlap) {
		m_Acceleration = { 0.0f, 0.0f, 0.0f };
	}

	m_isOverlap = false;
}

/*******************************************************************************
* 描画処理
*******************************************************************************/
void Ball::Draw() const
{
	XMMATRIX world =XMMatrixTranslationFromVector(m_Position);
	ModelDraw(m_pModel,world);
}

/*******************************************************************************
* 物体に当たった時の処理
*******************************************************************************/
bool Ball::OnHit(const AABB& aabb)
{
	if (GetAABB().isOverlap(aabb)) {

		//cubeのAABBの中心座標からボールのAABBの中心座標が各軸の一番短いのはどれ？
		XMVECTOR cube_to_ball = XMLoadFloat3(&GetAABB().GetCenterVertex()) - XMLoadFloat3(&aabb.GetCenterVertex());

		float x = XMVectorGetX(cube_to_ball);
		float y = XMVectorGetY(cube_to_ball);
		float z = XMVectorGetZ(cube_to_ball);

		float ax = fabsf(x);
		float ay = fabsf(y);
		float az = fabsf(z);

		bool is_max_length_x = false;
		bool is_max_length_y = false;
		bool is_max_length_z = false;

		if (ax > ay) {
			if (ax > az) {
				is_max_length_x = true;
			}
			else {
				is_max_length_z = true;
			}
		}
		else {
			if (ay > az) {
				is_max_length_y = true;
			}
			else {
				is_max_length_z = true;
			}
		}

		//めり込みを(簡易的に)直す
		float m = 0.0f;

		if (is_max_length_x) {
			if (x > 0) {
				//右から
				m = aabb.GetMaxVertex().x - (GetAABB().GetMinVertex().x - GetAABB().GetCenterVertex().x);
			}
			else {
				//左から
				m = aabb.GetMinVertex().x - (GetAABB().GetMaxVertex().x - GetAABB().GetCenterVertex().x);
			}
			SetPosition(XMVectorSetX(GetPosition(), m));
			m_Acceleration = XMVectorSetX(m_Acceleration, -XMVectorGetX(m_Acceleration));
		}
		else if (is_max_length_y) {
			if (y > 0) {
				//上から
				m = aabb.GetMaxVertex().y - (GetAABB().GetMinVertex().y - GetAABB().GetCenterVertex().y);
			}
			else {
				//下から
				m = aabb.GetMinVertex().y - (GetAABB().GetMaxVertex().y - GetAABB().GetCenterVertex().y);
			}
			SetPosition(XMVectorSetY(GetPosition(), m));
			m_Acceleration = XMVectorSetY(m_Acceleration, -XMVectorGetY(m_Acceleration));

		}
		else {
			if (z > 0) {
				//前から
				m = aabb.GetMaxVertex().z - (GetAABB().GetMinVertex().z - GetAABB().GetCenterVertex().z);
			}
			else {
				//後ろから
				m = aabb.GetMinVertex().z - (GetAABB().GetMaxVertex().z - GetAABB().GetCenterVertex().z);
			}
			SetPosition(XMVectorSetZ(GetPosition(), m));
			m_Acceleration = XMVectorSetZ(m_Acceleration, -XMVectorGetZ(m_Acceleration));
		}

		//物体に当たった時の減衰率
		m_Acceleration *= 0.5f;

		if (XMVectorGetX(XMVector3LengthEst(m_Acceleration)) <= 0.002f) {
			m_Acceleration = XMVECTOR{ 0.0f,0.0f,0.0f };
			m_frame = 0;
		}

		PlayAudio(SE_ID);

		return true;
	}

	return false;
}

