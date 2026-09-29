# include <Siv3D.hpp> // Siv3D v0.6.15
#include "world.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemySpawner.h"
#include "EnemySpawnerPatrolChaser.h"

#include "Attack.h"
#include "UI_HP.h"


void Main()
{
	//ウィンドウのサイズを設定
	Window::Resize(1280, 720);

	// 背景の色を設定する | Set the background color
	Scene::SetBackground(ColorF{ 0.6, 0.8, 0.7 });

	//テクスチャの管理予約
	TextureAsset::Register(U"Attack", 0xF04E5_icon, 64);

	World world;

	std::vector<Float2> patrol_points_a{
		{Scene::Size() * 0.1f},					//左上
		{Scene::Size() * Float2 { 0.9f,0.1f }},	//右上
		{Scene::Size() * 0.9f},					//右下
		{Scene::Size() * Float2 { 0.1f,0.9f }}	//左下
	};

	std::vector<Float2> patrol_points_b{
		{Scene::Size() * 0.9f},					//右下
		{Scene::Size() * Float2 { 0.1f,0.9f }},	//左下
		{Scene::Size() * 0.1f},					//左上
		{Scene::Size() * Float2 { 0.9f,0.1f }}	//右上
	};

	world.Register(new Player({ Scene::Size() * 0.5f }));
	world.Register(new EnemySpawnerPatrolChaser{ patrol_points_a });
	world.Register(new EnemySpawnerPatrolChaser{ patrol_points_b });
	world.Register(new UI_HP());


	while (System::Update())
	{
		world.Update();

		world.Draw();

		world.Cleanup();
	}


}
