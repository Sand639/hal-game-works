/*******************************************************************************
* タイトル:		プレイヤー制御
* プログラム名:	player.cpp
* 作成者:		大槻海斗
* 作成日:		2024/09/04〜
* 更新日		2024/09/04
*******************************************************************************/

/*******************************************************************************
*　インクルードファイル
*******************************************************************************/
#include "manager.h"	//シーン管理
#include "player.h"
#include "keyboard.h"
#include "Block.h"
#include "Audio.h"
#include "score.h"

/*******************************************************************************
*　マクロ定義
*******************************************************************************/
#define	PLAYER_MOVE_AXCEL (1.5f)

/*******************************************************************************
*　グローバル変数
*******************************************************************************/
static ID3D11ShaderResourceView* TextureID[BLOCK_TYPE_MAX] = {};
static PLAYER Player;	//落ちてくるブロック
static PLAYER Next;		//ネクスト
static PLAYER_STATE PlayerState;	//プレイヤーステート
static int PlayerStateCount = 0;	//ステート切替カウンター

//サウンドを表す変数
static int SE_ID;

/*******************************************************************************
*　初期化
*******************************************************************************/
void InitPlayer()
{
	//サウンドデータの読み込み
	SE_ID = LoadAudio("asset\\Audio\\wan.wav");

	PlayerState = PLAYER_STATE_MOVE;

	//テクスチャ読み込み
	TexMetadata metadata;
	ScratchImage image;

	//豚
	LoadFromWICFile(L"asset\\texture\\pig.png", WIC_FLAGS_NONE, &metadata, image);
	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &TextureID[0]);
	//なにか失敗した時に警告を出す
	assert(TextureID[0]);

	//猿
	LoadFromWICFile(L"asset\\texture\\monkey.png", WIC_FLAGS_NONE, &metadata, image);
	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &TextureID[1]);
	//なにか失敗した時に警告を出す
	assert(TextureID[1]);

	//オウム
	LoadFromWICFile(L"asset\\texture\\parrot.png", WIC_FLAGS_NONE, &metadata, image);
	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &TextureID[2]);
	//なにか失敗した時に警告を出す
	assert(TextureID[2]);

	//パンダ
	LoadFromWICFile(L"asset\\texture\\panda.png", WIC_FLAGS_NONE, &metadata, image);
	CreateShaderResourceView(GetDevice(), image.GetImages(),
		image.GetImageCount(), metadata, &TextureID[3]);
	//なにか失敗した時に警告を出す
	assert(TextureID[3]);

	//ネクストの作成
	
	//出現座標
	Next.pos = { SCREEN_WIDTH / 2 + 250.0f, 120.0f};	 //とりあえず
	Next.newPos = Next.pos;
	Next.vel.x = 0.0f;
	Next.vel.y = 0.0f;

	for (int i = 0; i < 3; i++)
	{
		Next.Type[i] = rand() % 4;
	}

	//プレイヤーの作成
	CreatePlayer();
}

/*******************************************************************************
*　終了処理
*******************************************************************************/
void UninitPlayer()
{
	//テクスチャの開放
	for (int i = 0; i < BLOCK_TYPE_MAX; i++)
	{
		TextureID[i]->Release();
	}

	//サウンドの開放
	UnloadAudio(SE_ID);	//BGMをループ再生
}

/*******************************************************************************
*　更新処理
*******************************************************************************/
void UpdatePlayer()
{
	//状態による分岐
	switch(PlayerState)
	{
	case PLAYER_STATE_IDLE:	//何もしない

		break;

	case PLAYER_STATE_MOVE:	//落下中

		MovePlayer();

		break;

	case PLAYER_STATE_GROUND_IDLE:	//着地中

		PlayerStateCount++;//待ち時間カウント

		if (PlayerStateCount >= TIME_DELAY)//約1秒待つ
		{
			PlayerState = PLAYER_STATE_IDLE;
			PlayerStateCount = 0;

			EraseBlock();
		}
		break;

	case PLAYER_STATE_MISS_IDLE:	//ミス発生

		PlayerStateCount++;//待ち時間カウント
		if (PlayerStateCount >= TIME_DELAY)
		{	
			SetScene(SCENE_RESULT);	//リザルトへ
		}

		break;

	default:
		break;
	}
}

/*******************************************************************************
*　描画処理
*******************************************************************************/
void DrawPlayer()
{
	// マトリクス設定 
	SetWorldViewProjection2D();

	//ネクストを描画
	for (int i = 0; i < 3; i++)
	{
		//Type[i]のテクスチャをセット
		GetDeviceContext()->PSSetShaderResources(0, 1, &TextureID[Next.Type[i]]);
		//座標を作成
		XMFLOAT3 pos = XMFLOAT3(Next.pos.x, Next.pos.y + BLOCK_HIGHT * i, 0.0f);
		//サイズを作成
		XMFLOAT2 size = XMFLOAT2(BLOCK_WIDTH, BLOCK_HIGHT);
		//色を作成
		XMFLOAT4 color = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
		//ネクストを描画
		DrawSprite(pos, size, color);
	}

	//移動中のみ表示
	if ((PlayerState == PLAYER_STATE_IDLE) || (PlayerState == PLAYER_STATE_GROUND_IDLE))
		return;

	//プレイヤーを描画
	for (int i = 0; i < 3; i++)
	{
		//Type[i]のテクスチャをセット
		GetDeviceContext()->PSSetShaderResources(0, 1, &TextureID[Player.Type[i]]);
		//座標を作成
		XMFLOAT3 pos = XMFLOAT3(Player.pos.x, Player.pos.y + BLOCK_HIGHT * i , 0.0f);
		//サイズを作成
		XMFLOAT2 size = XMFLOAT2(BLOCK_WIDTH, BLOCK_HIGHT);
		//色を作成
		XMFLOAT4 color = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
		//プレイヤーを描画
		DrawSpriteScroll(pos, size, color);
	}
}

/*******************************************************************************
*　ピースブロックを作成
*******************************************************************************/
void CreatePlayer()
{
	//出現座標
	Player.pos = { BLOCK_WIDTH * 2.5f, -BLOCK_HIGHT * 1.5f };	 //とりあえず
	Player.newPos = Player.pos;
	Player.vel.x = 0.0f;
	Player.vel.y = 0.0f;

	//ランダムに種類を3つ決める
	for (int i = 0; i < 3; i++)
	{
		//ネクストをプレイヤーに入れる
		Player.Type[i] = Next.Type[i];

		//新しくネクストを作る
		Next.Type[i] = rand() % 4;
	}

	//落下モードへ移行
	PlayerState = PLAYER_STATE_MOVE;

	//ゲームオーバーチェック
	//プレーヤーの一番下のブロック表示座標を配列の位置に変換
	int x = Player.pos.x / BLOCK_WIDTH;
	int y = (Player.pos.y + (BLOCK_HIGHT * 3.0f)) / BLOCK_HIGHT;
	BLOCK block = GetBlock(x, y);

	//ブロックがあったらミスモードへ移行
	if (block.Enable)
	{
		//ミスモードへ移行
		PlayerState = PLAYER_STATE_MISS_IDLE;
		PlayerStateCount = 0;
	}
	//ブロックがなければ落下モードへ移行
	else
	{
		//落下モードへ移行
		PlayerState = PLAYER_STATE_MOVE;
		PlayerStateCount = 0;
	}

}

/*******************************************************************************
*　ピースの移動
*******************************************************************************/
void MovePlayer()
{
	//表示座標を配列内座標へ変換
//(PIECE_HEIGHT * 2.5f)はプレイヤーキャラクターの底面のY座標を取っている
	int x, y;
	x = (int)Player.pos.x / BLOCK_WIDTH;
	y = (int)(Player.pos.y + (BLOCK_HIGHT * 2.5f)) / BLOCK_HIGHT;

	Player.newPos = Player.pos;

	BLOCK block;

	//キー操作で移動
	if (Keyboard_IsKeyDownTrigger(KK_W) || Keyboard_IsKeyDownTrigger(KK_UP))
	{	//ブロックの種類をローテーションさせる
		//1個ずらす

		/*	下回転
		int work = Player.Type[0];

		Player.Type[0] = Player.Type[2];

		Player.Type[2] = Player.Type[1];

		Player.Type[1] = work;
		*/

		//上回転
		int work = Player.Type[2];

		Player.Type[2] = Player.Type[0];

		Player.Type[0] = Player.Type[1];

		Player.Type[1] = work;
	}

	if (Keyboard_IsKeyDownTrigger(KK_A) || Keyboard_IsKeyDownTrigger(KK_LEFT))
	{
		if (x > 0) //配列の1番左より右にいる
		{
			block = GetBlock(x - 1, y);

			if (block.Enable == false)	//左隣りにブロックが無い
			{
				//左移動	ブロック1つ分左へ移動
				Player.newPos.x -= BLOCK_WIDTH;
			}
		}
	}

	if (Keyboard_IsKeyDownTrigger(KK_D) || Keyboard_IsKeyDownTrigger(KK_RIGHT))
	{
		if (x < BLOCK_NUM_X - 1)	//配列の1番右より左にいる
		{
			block = GetBlock(x + 1, y);

			if (block.Enable == false)	//右隣りにブロックが無い
			{
				//右移動	ブロック1つ分右へ移動
				Player.newPos.x += BLOCK_WIDTH;
			}
		}
	}

	//加速
	if (Keyboard_IsKeyDown(KK_S) || Keyboard_IsKeyDown(KK_DOWN))
	{
		Player.vel.y += PLAYER_MOVE_AXCEL;

		static int f = 0;
		f++;
		if (f >= 2)
		{
			AddScore(1);
			f = 0;
		}
	}

	//抵抗力
	Player.vel.y -= Player.vel.y * 0.2f;

	//通常移動
	Player.vel.y += 2.0f;

	//移動先の座標
	Player.newPos.x += Player.vel.x;
	Player.newPos.y += Player.vel.y;

	x = (int)Player.newPos.x / BLOCK_WIDTH;
	y = (int)(Player.newPos.y + (BLOCK_HIGHT * 2.5f)) / BLOCK_HIGHT;

	//着地チェック
	block = GetBlock(x, y);//ブロックの真下のブロック
	//着地フラグ
	bool ground = false;

	if (block.Enable)	//下にブロックがある
	{
		ground = true;
	}
	else if (y >= BLOCK_NUM_Y)	//配列の一番下にいる
	{
		ground = true;
	}

	//着地した時の処理
	if (ground)
	{
		for (int i = 0; i < 3; i++)
		{
			x = (int)Player.newPos.x / BLOCK_WIDTH;
			y = (int)(Player.newPos.y + (BLOCK_HIGHT * i)) / BLOCK_HIGHT;
			SetBlock(x, y, Player.Type[i]);
		}

		//着地後の待ち時間を作る
		PlayerState = PLAYER_STATE_GROUND_IDLE;
		//待ち時間フレーム数リセット
		PlayerStateCount = 0;

		//着地SE再生リクエスト
		PlayAudio(SE_ID, false);	//再生するSEのIDとループフラグ
	}
	else
	{
		//移動
		Player.pos = Player.newPos;
	}

	//通常移動
	Player.vel.y -= 2.0f;
}