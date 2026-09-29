#include "stdafx.h"
#include "EnemyState.h"
#include "EnemyPatrolChaser.h"
#include "World.h"

/*******************************************************************************
* 更新処理
********************************************************************************/
void EnemyStatePatrol::Update()
{
	// パトロール速度
	float MOVE_SPEED_BY_SEC = static_cast<float>(Scene::DeltaTime() * 50.0);

	//移動先座標
	Float2 target = GetOwner()->GetPatrolPoints()[m_TargetPointIndex];

	//自分から移動先までのベクトル(向きだけ:単位ベクトル)を算出
	Float2 toTarget = (target - GetOwner()->GetLocation()).normalized();

	//ターゲットにむかって移動
	GetOwner()->SetLocation(GetOwner()->GetLocation() + toTarget * MOVE_SPEED_BY_SEC);

	/*目的地にたどり着いたか?(目的地店との距離が移動速度よりも短かい)*/
	/*移動距離よりも目的地点と現在地の差が小さかったら目的地に着いた判定にする*/
	if (target.distanceFromSq(GetOwner()->GetLocation()) <= MOVE_SPEED_BY_SEC * MOVE_SPEED_BY_SEC) {
		/*目的地にたどり着いた*/
		size_t point_num = GetOwner()->GetPatrolPoints().size();	//巡回のポイント数
		int next_index = (m_TargetPointIndex + 1) % point_num;	//次の巡回ポイント

		//次の巡回ポイントへ進むステートへ切替
		GetOwner()->ChangeStatePatrol(next_index);
	}

	/*プレイヤーがテリトリーに入った*/

	//プレイヤーの取得
	GameObjects objects = GetOwner()->GetWorld()->GetGameObjects("PLAYER");

	if (objects.empty()) {
		return;	//プレイヤーが世界にいないみたいなので終了
	}

	GameObject* pPlayer = objects.front();	//プレイヤーのポインタ

	//テリトリーにプレイヤーはいるか?
	if (GetOwner()->GetTerritory().intersects(pPlayer->GetCollision())) {
		//プレイヤーを発見!
		GetOwner()->ChangeStateChase();

	}


}



void EnemyStateChase::Update()
{
	float MOVE_SPEED_BY_SEC = static_cast<float>(Scene::DeltaTime() * 60.0);

	GameObjects objects = GetOwner()->GetWorld()->GetGameObjects("PLAYER");

	//プレイヤーは世界に存在しているか？
	if (objects.empty()) {
		return;
	}

	GameObject* pPlayer = objects.front();	//プレイヤーのポインタ

	//プレイヤーはどこ？
	Float2 player_location = pPlayer->GetLocation();

	//自分からプレイヤーへのベクトル
	Float2 to_player = (player_location - GetOwner()->GetLocation()).normalized();

	//移動予定座標
	Float2 to_move = GetOwner()->GetLocation() + to_player * MOVE_SPEED_BY_SEC;

	//プレイヤーに向かって移動
	GetOwner()->SetLocation(to_move);

	/*見失った時間計測*/


	//テリトリーにプレイヤーはいるか?
	if (!GetOwner()->GetTerritory().intersects(pPlayer->GetCollision())) {
		//プレイヤーを見失っているので見失っている時間を加算する
		m_LostTime += Scene::DeltaTime();

		if (m_LostTime >= 3.0) {
			//見失った時間が3秒を超えたので、諦めて巡回に戻る

			//諦めて一番近い巡回ポイントに戻る
			returnToNearestLocation();
		}
	}
	else {
		m_LostTime = 0.0;
	}
}


void EnemyStateChase::returnToNearestLocation()
{
	std::list<Float2> patrol_points;	//ソート用のlist

	//パトロールポイントをソート用コンテナにコピーする
	std::copy(GetOwner()->GetPatrolPoints().begin(), GetOwner()->GetPatrolPoints().end()
		, std::back_inserter(patrol_points));

	Float2 location = GetOwner()->GetLocation();	//エネミーの現在座標

	//エネミーから近い順番にソートする(一番近い巡回ポイントはfrontで取得できる)
	patrol_points.sort([location](const Float2& a, const Float2& b) {
		return location.distanceFromSq(a) < location.distanceFromSq(b);
	});

	//インデックスを調べる
	for (int i = 0; i < GetOwner()->GetPatrolPoints().size(); i++) {
		if (GetOwner()->GetPatrolPoints()[i] == patrol_points.front()) {
			GetOwner()->ChangeStatePatrol(i);	//次の巡回ポイントを指定
			return;
		}
	}

}

