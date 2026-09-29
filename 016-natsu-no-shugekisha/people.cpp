#include "people.h"
#include "field.h"
#include "sprite.h"
#include "score.h"		//スコア表示ヘッダー

// ===================================================
// マクロ定義
// ===================================================
#define	PEOPLE_MOVE_AXCEL (1.5f)

// ===================================================
// グローバル変数
// ===================================================
static ID3D11ShaderResourceView* TextureID[PEOPLE_TYPE_MAX] = {};
People people[PEOPLE_MAX];

//コンストラクタ
People::People()
{	//デフォルト初期値
	HP = 20;	//20フレーム
	pos = XMFLOAT3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f);
	oldpos = pos;
	vel.x = PEOPLE_MOVE_AXCEL;
	vel.y = PEOPLE_MOVE_AXCEL;
	size = XMFLOAT2(100.0f, 100.0f);
	use = false;
	type = rand() % PEOPLE_TYPE_MAX;
	frm = 0;
	move = false;
}

//デストラクタ
People::~People()
{
	//終了処理
}

void People::Update()
{
	oldpos = pos;	//敵の移動前の位置を保存しておく

	//ランダム

	if (!move)
	{
		value = 1 + rand() % 5;
		move = true;
	}

	if (value == 1)
	{	//上
		pos.y -= vel.y;
	}
	else if (value == 2)
	{	//左
		pos.x -= vel.x;
	}
	else if (value == 3)
	{	//下
		pos.y += vel.y;
	}
	else if (value == 4)
	{	//右
		pos.x += vel.x;
	}
	else
	{
		frm += PEOPLE_MOVE_TIME / 2;
	}

	if (frm >= PEOPLE_MOVE_TIME)
	{
		move = false;
		frm = 0;
	}

	frm++;

}

void People::Draw()
{
	if (!use)
		return;

	// マトリクス設定 
	SetWorldViewProjection2D();

	static XMFLOAT4 color = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);


	GetDeviceContext()->PSSetShaderResources(0, 1, &TextureID[type]);

	//ポリゴンの表示
	DrawSprite(pos, size, color);

}

void People::MinusHP()
{
	HP--;

	if (HP <= 0)
	{
		use = false;
		AddScore(100);
	}
}

void SetPeople()
{
	int Ran = 0;

	for (int i = 0; i < PEOPLE_MAX; i++)
	{
		//現在アニメーションを実行していないなら新しくセットする
		if (people[i].use)
			continue;

		static XMFLOAT3 p = XMFLOAT3(500.0f, 300.0f, 0.0f);
		static XMFLOAT2 s = XMFLOAT2(PEOPLE_WIDTH, PEOPLE_HIGHT);
		static XMFLOAT2 v = XMFLOAT2(1.0f, 1.0f);

		 Ran = 1 + rand() % 10;

		 p.x = 100.0f + (Ran * 50.0f);

		 Ran = 1 + rand() % 5;

		 p.y = 50.0f + (Ran * 50.0f);

		people[i].pos = p;
		people[i].oldpos = people[i].pos;
		people[i].vel = v;
		people[i].size = s;
		people[i].use = true;
		people[i].type = rand() % PEOPLE_TYPE_MAX;
		people[i].HP = 20;	//20フレーム
		people[i].frm = 0;
		people[i].move = false;

		return;
	}
}


void InitPeople(void)
{
	//テクスチャ読み込み
	TexMetadata metadata;
	ScratchImage image;

	LoadFromWICFile(L"asset\\texture\\character_man.png", WIC_FLAGS_NONE, &metadata, image);
	//読み込んだ画像データをDirectXへ渡してテクスチャとして管理させる

	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &TextureID[0]);

	//なにか失敗した時に警告を出す
	assert(TextureID[0]);

	LoadFromWICFile(L"asset\\texture\\character_wizard.png", WIC_FLAGS_NONE, &metadata, image);
	//読み込んだ画像データをDirectXへ渡してテクスチャとして管理させる

	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &TextureID[1]);

	//なにか失敗した時に警告を出す
	assert(TextureID[1]);

	LoadFromWICFile(L"asset\\texture\\character_woman.png", WIC_FLAGS_NONE, &metadata, image);
	//読み込んだ画像データをDirectXへ渡してテクスチャとして管理させる

	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &TextureID[2]);

	//なにか失敗した時に警告を出す
	assert(TextureID[2]);

	SetPeople();
	SetPeople();
	SetPeople();
	SetPeople();
	SetPeople();
	SetPeople();
}

void UpadatePeople(void)
{
	static int fream = 0;

	if (fream >= 30)
	{
		SetPeople();
		fream = 0;
	}

	fream++;
}

void UninitPeople(void)
{
	for (int i = 0; i < PEOPLE_TYPE_MAX; i++)
	{
		TextureID[i]->Release();	//テクスチャの解放
	}
}

People* GetPeople(void)
{
	return people;
}

