#include "player.h"
#include "main.h"
#include "sprite.h"
#include "keyboard.h"

// ===================================================
// マクロ定義
// ===================================================
#define	PLAYER_MOVE_AXCEL (1.5f)

// ===================================================
// グローバル変数
// ===================================================
PLAYER player;	// プレイヤー実体
static ID3D11ShaderResourceView* TextureID = NULL;

void InitPlayer(void)
{
	player.pos = XMFLOAT3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f);
	player.oldpos = player.pos;
	player.vel = XMFLOAT2(0.0f, 0.0f);
	player.size = XMFLOAT2(200.0f, 200.0f);
	player.use = true;

	//テクスチャ読み込み

	TexMetadata metadata;
	ScratchImage image;

	LoadFromWICFile(L"asset\\texture\\taiyou.png", WIC_FLAGS_NONE, &metadata, image);
	//読み込んだ画像データをDirectXへ渡してテクスチャとして管理させる

	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &TextureID);

	//なにか失敗した時に警告を出す
	assert(TextureID);


}

void UpdatePlayer(void)
{
	if (!player.use)
		return;

	// 変更前の座標を格納
	player.oldpos = player.pos;

	//WASD移動
	if (Keyboard_IsKeyDown(KK_W) || Keyboard_IsKeyDown(KK_UP))
	{
		player.vel.y -= PLAYER_MOVE_AXCEL;
	}
	if (Keyboard_IsKeyDown(KK_A) || Keyboard_IsKeyDown(KK_LEFT))
	{
		player.vel.x -= PLAYER_MOVE_AXCEL;
	}
	if (Keyboard_IsKeyDown(KK_S) || Keyboard_IsKeyDown(KK_DOWN))
	{
		player.vel.y += PLAYER_MOVE_AXCEL;
	}
	if (Keyboard_IsKeyDown(KK_D) || Keyboard_IsKeyDown(KK_RIGHT))
	{
		player.vel.x += PLAYER_MOVE_AXCEL;
	}

	// 抵抗力
	player.vel.x -= player.vel.x * 0.1f;
	player.vel.y -= player.vel.y * 0.1f;

	player.pos.x += player.vel.x;
	player.pos.y += player.vel.y;


}

void DrawPlayer(void)
{
	if (!player.use)
		return;

	// マトリクス設定 
	SetWorldViewProjection2D();

	static XMFLOAT4 color = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);

	//使用するテクスチャをセット
	GetDeviceContext()->PSSetShaderResources(0, 1, &TextureID);

	//ポリゴンの表示
	DrawSprite(player.pos, player.size, color);
	



}

void UninitPlayer(void)
{
	TextureID->Release();	//テクスチャの解放
}

PLAYER* GetPlayer(void)
{
	return &player;
}
