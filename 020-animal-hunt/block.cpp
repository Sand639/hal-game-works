/*******************************************************************************
* タイトル:		フィールド・マップチップ制御
* プログラム名:	block.cpp
* 作成者:		大槻海斗
* 作成日:		2024/09/04〜
* 更新日		2024/09/09
*******************************************************************************/

/*******************************************************************************
*　インクルードファイル
*******************************************************************************/
#include "main.h"
#include "sprite.h"
#include "block.h"
#include "player.h"
#include "Effect.h"
#include "score.h"		//スコア表示ヘッダー
#include "game.h"
#include "Audio.h"


/*******************************************************************************
*　グローバル変数
*******************************************************************************/
static ID3D11ShaderResourceView* TextureID[BLOCK_TYPE_MAX] = {};
static BLOCK_STATE BlockState;	//ブロックステート　現在のモード
static int BlockStateCount = 0;	//モード切替待ち時間
static BLOCK Block[BLOCK_NUM_Y][BLOCK_NUM_X] = {};	//MapTip
static int SE_ID[BLOCK_TYPE_MAX];

/*******************************************************************************
*　初期化
*******************************************************************************/
void InitBlock()
{
	//ブロック初期化
	for (int y = 0; y < BLOCK_NUM_Y; y++)
		for (int x = 0; x < BLOCK_NUM_X; x++)
		{
			Block[y][x].Enable = false;
			Block[y][x].Erase = false;
			Block[y][x].Type = rand() % 4;
		}

	BlockState = BLOCK_STATE_IDLE;	//待機モード

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

	//サウンド初期化
	SE_ID[0] = LoadAudio("asset\\Audio\\Pig.wav");
	SE_ID[1] = LoadAudio("asset\\Audio\\Monkey.wav");
	SE_ID[2] = LoadAudio("asset\\Audio\\Bird.wav");
	SE_ID[3] = LoadAudio("asset\\Audio\\Panda.wav");

}

/*******************************************************************************
*　終了処理
*******************************************************************************/
void UninitBlock()
{
	//テクスチャの開放
	for (int i = 0; i < BLOCK_TYPE_MAX; i++)
	{
		TextureID[i]->Release();
	}
}

/*******************************************************************************
*　更新処理
*******************************************************************************/
void UpdateBlock()
{
	switch (BlockState)
	{
	case 	BLOCK_STATE_IDLE:		//何もしない

		break;

	case BLOCK_STATE_ERASE_IDLE:	//消滅中

		BlockStateCount++;//待ち時間カウント

		if (BlockStateCount >= TIME_DELAY)//約1秒待つ
		{
			//ブロック落とす処理
			StackBlock();
		}

		break;
	case BLOCK_STATE_STACK_IDLE:	//落下中
		BlockStateCount++;
		if (BlockStateCount >= TIME_DELAY)
		{
			//消滅チェック
			EraseBlock();
		}

		break;
	default:
		break;
	}
}

/*******************************************************************************
*　描画処理
*******************************************************************************/
void DrawBlock()
{
	for (int y = 0; y < BLOCK_NUM_Y; y++)
		for (int x = 0; x < BLOCK_NUM_X; x++)
		{
			//ブロックが無いならcontinue
			if (!Block[y][x].Enable)
				continue;

			// マトリクス設定 
			SetWorldViewProjection2D();

			//Type[i]のテクスチャをセット
			GetDeviceContext()->PSSetShaderResources(0, 1, &TextureID[Block[y][x].Type]);

			//ブロックを描画
						//座標を作成
			XMFLOAT3 pos = XMFLOAT3((BLOCK_WIDTH * x) + BLOCK_WIDTH * 0.5f,
				(BLOCK_HIGHT * y) + BLOCK_HIGHT * 0.5f, 0.0f);

			//サイズを作成
			XMFLOAT2 size = XMFLOAT2(BLOCK_WIDTH, BLOCK_HIGHT);

			//色を作成
			XMFLOAT4 color = XMFLOAT4(1.0f, 1.0f, 1.0f, 1.0f);
			DrawSpriteScroll(pos, size, color);

		}
}

/*******************************************************************************
*　ブロックセット
*******************************************************************************/
void SetBlock(int x, int y, int type)
{
	//配列外にチェック
	if ((x < 0) || (x >= BLOCK_NUM_X)) return;
	if ((y < 0) || (y >= BLOCK_NUM_Y)) return;

	Block[y][x].Enable = true;
	Block[y][x].Erase = false;
	Block[y][x].Type = type;
}

/*******************************************************************************
*　配列の情報を取得
*******************************************************************************/
BLOCK GetBlock(int x, int y)
{
	return Block[y][x];
}

/*******************************************************************************
*　ブロック消去処理
*******************************************************************************/
void EraseBlock()
{
	bool erase = false;	//ブロック消滅フラグ

	//縦方向チェック
	int type = -1;	//調べるブロックの種類
	int count = 0;	//同じ種類のブロックが並んでいる数
	static int combo = 0;	//連鎖数

	//配列を横にチェックするループ
	for (int x = 0; x < BLOCK_NUM_X; x++)
	{	//配列を縦にチェックするループ
		for (int y = 0; y < BLOCK_NUM_Y; y++)
		{
			//ブロックが配列内にあるか？
			if (!Block[y][x].Enable)
			{
				EraseBlocks(count, x, y, erase, true, false, combo, type);	//消せるかチェック

				//配列にブロックが無かった場合はリセット
				type = -1;
				count = 0;

				continue;//スキップ
			}

			//配列のブロックのtypeとtypeを比較する
			if (type == Block[y][x].Type)
			{	//同じ種類だったらcount++
				count++;

				if (!(y == BLOCK_NUM_Y - 1))
					continue;
			}
			else //異なるブロックの種類だった場合
			{
				EraseBlocks(count, x, y, erase, true, false, combo, type);
				type = Block[y][x].Type;	//調べるブロック種類を入れ替え
				count = 0;
				continue;//スキップ
			}

			EraseBlocks(count, x, y, erase, true, true, combo, type);	//消せるかチェック

		}
		type = -1;
		count = 0;
	}

	type = -1;
	count = 0;

	//横方向チェック
	for (int y = 0; y < BLOCK_NUM_Y; y++)
	{
		for (int x = 0; x < BLOCK_NUM_X; x++)
		{
			//ブロックが配列内にあるか？
			if (!Block[y][x].Enable)
			{
				EraseBlocks(count, x, y, erase, false, false, combo, type);	//消せるかチェック
				//配列にブロックが無かった場合はリセット
				type = -1;
				count = 0;

				continue;//スキップ
			}

			//配列のブロックのtypeとtypeを比較する
			if (type == Block[y][x].Type)
			{	//同じ種類だったらcount++
				count++;
				if (!(x == BLOCK_NUM_X - 1))
					continue;

			}
			else //異なるブロックの種類だった場合
			{
				EraseBlocks(count, x, y, erase, false, false, combo, type);	//消せるかチェック

				type = Block[y][x].Type;	//調べるブロック種類を入れ替え
				count = 0;
				continue;//スキップ
			}

			EraseBlocks(count, x, y, erase, false, true, combo, type);	//消せるかチェック

		}
		type = -1;
		count = 0;
	}

	type = -1;
	count = 0;

	//左上から右下の斜めチェック
	for (int y = 0; y < BLOCK_NUM_Y; y++)
	{
		bool eraseFlags[BLOCK_NUM_Y][BLOCK_NUM_X] = { false };

		for (int x = 0; x < BLOCK_NUM_X; x++)
		{
			//ブロックが配列内にあるか？
			if (!Block[y][x].Enable || eraseFlags[y][x] == true)
			{
				type = -1;
				count = 0;
				continue;
			}

			type = Block[y][x].Type;	//調べるブロック種類を入れ替え
			count = 0;

			for (int i = 0; i < BLOCK_NUM_X; i++)
			{	//マップ外ならループ終了 または　存在しないならループ終了
				if (y + i < 0 || y + i >= BLOCK_NUM_Y || 
					x + i < 0 || x + i >= BLOCK_NUM_X || !Block[y + i][x + i].Enable)
					break;
				if (type == Block[y + i][x + i].Type)
					count++;	//同じtypeならcountを増やす
				else
					break;
			}

			if (count >= 3)
			{
				for (int i = 0; i < count; i++)
				{
					Block[y + i][x + i].Erase = true;
					eraseFlags[y + i][x + i] = true;
				}

				erase = true;

				//スコア計算　countの数によってスコアを加算
				int score = (combo >= 1) ? count * 10 * combo * 8 : count * 10;
				AddScore(score);
				PlayAudio(SE_ID[type], false);
			}

			type = -1;
			count = 0;
		}
	}

	

	//右上から左下の斜めチェック
	for (int y = 0; y < BLOCK_NUM_Y; y++)
	{
		bool eraseFlags[BLOCK_NUM_Y][BLOCK_NUM_X] = { false };

		for (int x = 0; x < BLOCK_NUM_X; x++)
		{
			//ブロックが配列内にあるか？
			if (!Block[y][x].Enable || eraseFlags[y][x] == true)
			{
				type = -1;
				count = 0;
				continue;
			}

			type = Block[y][x].Type;	//調べるブロック種類を入れ替え
			count = 0;

			for (int i = 0; i < BLOCK_NUM_X; i++)
			{	//マップ外ならループ終了 または　存在しないならループ終了
				if (y + i < 0 || y + i >= BLOCK_NUM_Y ||
					x - i < 0 || x - i >= BLOCK_NUM_X || !Block[y + i][x - i].Enable)
					break;
				if (type == Block[y + i][x - i].Type)
					count++;	//同じtypeならcountを増やす
				else
					break;
			}

			if (count >= 3)
			{
				for (int i = 0; i < count; i++)
				{
					Block[y + i][x - i].Erase = true;
					eraseFlags[y + i][x - i] = true;
				}

				erase = true;
				//スコア計算　countの数によってスコアを加算
				int score = (combo >= 1) ? count * 10 * combo * 8 : count * 10;
				AddScore(score);
				PlayAudio(SE_ID[type], false);
			}

			type = -1;
			count = 0;

		}
	}

	//消滅するブロックのEnableフラグをfalseにする
	for (int y = 0; y < BLOCK_NUM_Y; y++)
		for (int x = 0; x < BLOCK_NUM_X; x++)
			if (Block[y][x].Erase)//ブロックは消滅予定
			{
				Block[y][x].Enable = false;
				Block[y][x].Erase = false;

				//消えたブロックの位置にエフェクト作成
				XMFLOAT3 position(0, 0, 0);
				position.x = (x * BLOCK_WIDTH + BLOCK_WIDTH * 0.5f);
				position.y = (y * BLOCK_HIGHT + BLOCK_HIGHT * 0.5f);

				CreateEffect(position);
			}

	if (erase)
	{	//消滅処理へ移行
		BlockState = BLOCK_STATE_ERASE_IDLE;
		BlockStateCount = 0;
		combo++;
	}
	else
	{	//消滅処理無し
		CreatePlayer();	//プレイヤー作成
		BlockState = BLOCK_STATE_IDLE;
		BlockStateCount = 0;
		combo = 0;
	}

}


/*******************************************************************************
*　ブロック落下処理
*******************************************************************************/
void StackBlock()
{
	bool stack = false;

	for (int y = BLOCK_NUM_Y - 1; y > 0; y--)
	{
		for (int x = 0; x < BLOCK_NUM_X; x++)
		{
			//ブロックがあるならスキップ
			if (Block[y][x].Enable)
				continue;

			for (int ys = y - 1; ys >= 0; ys--)
			{
				//ブロックがないならスキップ
				if (!Block[ys][x].Enable)
					continue;

				//このブロックの上にあるブロックを全て1ずつ下へ動かす
				Block[y][x] = Block[ys][x];

				//下へ移動させたブロックのEnableはfalseにしながら繰り返す
				Block[ys][x].Enable = false;

				stack = true;	//落下処理発生中
				break;
			}
		}
	}

	//落下処理ONなら落下待ちモードへ移行
	if (stack)
	{
		BlockState = BLOCK_STATE_STACK_IDLE;
		BlockStateCount = 0;
	}
	//そうでない場合は新しいプレイヤーを作成
	else
	{
		CreatePlayer();
		BlockState = BLOCK_STATE_IDLE;
		BlockStateCount = 0;
	}

}

/*******************************************************************************
*　ブロック消せるかチェック
*******************************************************************************/
void EraseBlocks(int count, int x, int y, bool& erase,
	bool isVertical, bool isEnd, int combo, int type)
{

	if (count >= 2) {
		int start = isEnd ? 0 : 1;
		int end = isEnd ? count + 1 : count + 2;
		for (int i = start; i < end; i++) {
			if (isVertical) {
				Block[y - i][x].Erase = true;
			}
			else {
				Block[y][x - i].Erase = true;
			}
		}
		erase = true;

		//ここでスコア加算、同時消し、連鎖でスコアを乗算していく
		int score = 0;

		score = (combo >= 1) ? (count + 1) * 10 * combo * 8 : (count + 1) * 10;

		AddScore(score);
		PlayAudio(SE_ID[type], false);
	}
}

