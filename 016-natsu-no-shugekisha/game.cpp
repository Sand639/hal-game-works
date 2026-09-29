//=========================================
// game.cpp ゲームシーン制作
//
// 制作者 : 大槻海斗	日付 : 2024/06/03
//=========================================

//=========================================
// インクルード
//=========================================
#include "field.h"
#include "player.h"
#include "people.h"
#include "score.h"		//スコア表示ヘッダー
#include "time.h"		//時間表示ヘッダー
#include "sunlight.h"

//=========================================
// ゲームシーン初期化
//=========================================
void InitGame(void)
{
	InitField();

	InitPlayer();

	InitPeople();

	InitScore();

	InitTime();

	InitSunlight();

}

//=========================================
// ゲームシーン更新
//=========================================
void UpdateGame(void)
{
	People* people = GetPeople();

	UpdateField();

	UpdatePlayer();

	//モブ処理
	for (int i = 0; i < PEOPLE_MAX; i++)
	{
		if (!people[i].use)
			continue;

		people[i].Update();
	}

	UpadatePeople();

	UpdateScore();

	UpdateTime();

	UpdateSunlight();


}

//=========================================
// ゲームシーン描画
//=========================================
void DrawGame(void)
{
	People* people = GetPeople();

	DrawField();	//フィールドを描画

	DrawSunlight();

	DrawPlayer();

	//モブ処理
	for (int i = 0; i < PEOPLE_MAX; i++)
	{
		if (!people[i].use)
			continue;

		people[i].Draw();
	}

	DrawScore();

	DrawTime();

	
}

//=========================================
// ゲームシーン終了処理
//=========================================
void UninitGame(void)
{
	UninitSunlight();

	UninitTime();

	UninitPeople();

	UninitPlayer();

	UninitField();


}
