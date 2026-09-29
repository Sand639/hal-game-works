
#include "sunlight.h"
#include "player.h"
#include "main.h"
#include "sprite.h"
#include "keyboard.h"
#include "people.h"
#include "collision.h"	//当たり判定ヘッダー
#include "score.h"


// ===================================================
// マクロ定義
// ===================================================
#define	SUNLIGHT_MOVE_AXCEL (1.5f)


// ===================================================
// グローバル変数
// ===================================================
SUNLIGHT sunlight;	// プレイヤー実体
static ID3D11ShaderResourceView* TextureID = NULL;

void InitSunlight(void)
{
	PLAYER* player = GetPlayer();

	sunlight.pos = XMFLOAT3(player->pos.x, player->pos.y + 100.0f, 0.0f);
	sunlight.oldpos = sunlight.pos;
	sunlight.vel = XMFLOAT2(0.0f, 0.0f);
	sunlight.size = XMFLOAT2(50.0f, 200.0f);
	sunlight.use = true;
}

void UpdateSunlight(void)
{
	if (!sunlight.use)
		return;

	// 変更前の座標を格納
	sunlight.oldpos = sunlight.pos;

	//WASD移動
	if (Keyboard_IsKeyDown(KK_W) || Keyboard_IsKeyDown(KK_UP))
	{
		sunlight.vel.y -= SUNLIGHT_MOVE_AXCEL;
	}
	if (Keyboard_IsKeyDown(KK_A) || Keyboard_IsKeyDown(KK_LEFT))
	{
		sunlight.vel.x -= SUNLIGHT_MOVE_AXCEL;
	}
	if (Keyboard_IsKeyDown(KK_S) || Keyboard_IsKeyDown(KK_DOWN))
	{
		sunlight.vel.y += SUNLIGHT_MOVE_AXCEL;
	}
	if (Keyboard_IsKeyDown(KK_D) || Keyboard_IsKeyDown(KK_RIGHT))
	{
		sunlight.vel.x += SUNLIGHT_MOVE_AXCEL;
	}

	// 抵抗力
	sunlight.vel.x -= sunlight.vel.x * 0.1f;
	sunlight.vel.y -= sunlight.vel.y * 0.1f;

	sunlight.pos.x += sunlight.vel.x;
	sunlight.pos.y += sunlight.vel.y;

	People* people = GetPeople();
	XMFLOAT2 PA = XMFLOAT2(sunlight.pos.x, sunlight.pos.y);
	XMFLOAT2 PB[PEOPLE_MAX] = {};

	for (int i = 0; i < PEOPLE_MAX; i++)
	{
		if (!people[i].use)
			continue;

		PB[i] = XMFLOAT2(people[i].pos.x, people[i].pos.y);

		if(CheckBoxCollider(PA, PB[i], sunlight.size, people[i].size))
		{
			people[i].MinusHP();
			AddScore(10);
		}


	}

}

void DrawSunlight(void)
{
	PLAYER* player = GetPlayer();

	//四角形テスト表示
	static XMFLOAT3 position = XMFLOAT3(player->pos.x, player->pos.y + 100.0f, 0.0f);
	static XMFLOAT2 size = XMFLOAT2(50.0f, 200.0f);
	static XMFLOAT4 color = XMFLOAT4(1.0f, 0.0f, 0.0f, 0.2f);
	DrawSprite(sunlight.pos, sunlight.size, color);
}

void UninitSunlight(void)
{

}

//SUNLIGHT* GetSunlight(void)
//{
//	return &sunlight;
//}
