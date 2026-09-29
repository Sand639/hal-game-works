//ヘッダーをインクルードする
#include <stdio.h>	//標準入出力ヘッダー
#include <stdlib.h>	//標準ライブラリヘッダー
#include <string.h>	//文字列操作ヘッダー
#include <time.h>	//時間ヘッダー
#include <conio.h>	//コンソール入出力ヘッダー
#include <windows.h>
#include "Screen.h"

//定数を宣言する
#define FIELD_WIDTH (10 + 2)	//フィールドの幅を定義する
#define FIELD_HEIGHT (20 + 1)	//フィールドの高さを定義する

#define BLOCK_WIDTH_MAX  (4)//ブロックの形状の最大幅を定義する
#define BLOCK_HEIGHT_MAX (4)//ブロックの形状の最大高さを定義する

#define FPS			(2)				//1秒あたりの描画頻度を定義する
#define INTERVAL	(1000 / FPS)	//描画間隔(ミリ秒)を定義する

//列挙定数を宣言する

//落下ブロックの種類を宣言する
enum {
	BLOCK_SHAPE_I,	//I型
	BLOCK_SHAPE_O,	//O型
	BLOCK_SHAPE_S,	//S型
	BLOCK_SHAPE_Z,	//Z型
	BLOCK_SHAPE_J,	//J型
	BLOCK_SHAPE_L,	//L型
	BLOCK_SHAPE_T,	//T型
	BLOCK_SHAPE_MAX	//落下ブロックの種類の数
};

//構造体を宣言する

//落下ブロックの形状の構造体
struct BLOCKSHAPE{
	int width,height;	//幅と高さ
	int pattern[BLOCK_HEIGHT_MAX][BLOCK_WIDTH_MAX];//形状
};

//落下ブロックの構造体を宣言する
struct BLOCK{
	int x, y;			//座標
	BLOCKSHAPE shape;	//形状
};

//グローバル変数

//落下ブロックの形状を宣言する
const BLOCKSHAPE blockShapes[BLOCK_SHAPE_MAX] = {
	//BLOCK_TYPE_I,	//I型
	{
		4,4,//int width,height		幅と高さ
		//const char* pattern;	形状
		{
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0},
			{0,0,0,0}
		}
	},
	//BLOCK_TYPE_O,	//O型
	{
		2,2,//int width,height		幅と高さ
		//const char* pattern;	形状
		{
			{1,1,0,0},
			{1,1,0,0},
			{0,0,0,0},
			{0,0,0,0}
		}
	},
	//BLOCK_TYPE_S,	//S型
	{
		3,3,//int width,height		幅と高さ
		//const char* pattern;	形状
		{
			{0,1,1,0},
			{1,1,0,0},
			{0,0,0,0},
			{0,0,0,0}
		}
	},
	//BLOCK_TYPE_Z,	//Z型
	{
		3,3,//int width,height		幅と高さ
		//const char* pattern;	形状
		{
			{1,1,0,0},
			{0,1,1,0},
			{0,0,0,0},
			{0,0,0,0}
		}
	},

	//BLOCK_TYPE_J,	//J型
	{
		3,3,//int width,height		幅と高さ
		//const char* pattern;	形状
		{
			{1,0,0,0},
			{1,1,1,0},
			{0,0,0,0},
			{0,0,0,0}
		}
	},

	//BLOCK_TYPE_L,	//L型
	{
		3,3,//int width,height		幅と高さ
		//const char* pattern;	形状
		{
			{0,0,1,0},
			{1,1,1,0},
			{0,0,0,0},
			{0,0,0,0}
		}
	},
	//BLOCK_TYPE_T,	//T型
	{
		3,3,//int width,height		幅と高さ
		//const char* pattern;	形状
		{
			{0,1,0,0},
			{1,1,1,0},
			{0,0,0,0},
			{0,0,0,0},
		}
	},
};

int combineBuffer	[FIELD_HEIGHT][FIELD_WIDTH];	//合成バッファを宣言する
int field			[FIELD_HEIGHT][FIELD_WIDTH];	//フィールドを宣言する

BLOCK block;	//落下ブロックを宣言する

//フィールドを描画する関数を宣言する
void DrawField()
{
	//フィールドを合成バッファにコピーする
	memcpy(combineBuffer, field, sizeof field);

	//落下ブロックを合成バッファに書き込む
	for (int y = 0; y < BLOCK_HEIGHT_MAX; y++)
		for (int x = 0; x < BLOCK_WIDTH_MAX; x++)
			combineBuffer[block.y + y][block.x + x] |= block.shape.pattern[y][x];

	//フィールドの全てのマスを反復する
	for (int y = 0; y < FIELD_HEIGHT; y++)
	{
		for (int x = 0; x < FIELD_WIDTH; x++)
			printf("%s", combineBuffer[y][x] ? "■" : "　");
		printf("\n");	//1行描画する毎に改行する
	}
}

//落下ブロックをリセットする関数
void ResetBlock()
{
	//落下ブロックの形状をランダムな形状で初期化する
	block.shape = blockShapes[rand() % BLOCK_SHAPE_MAX];

	//落下ブロックの列を中心に設定する
	block.x = (FIELD_WIDTH - BLOCK_WIDTH_MAX) / 2;

	//落下ブロックの行を先頭にする
	block.y = 0;
}



//ゲームをリセットする関数
void Reset()
{
	//フィールドをクリアする
	memset(field, 0, sizeof field);

	//フィールドの左右に壁を作る
	for (int y = 0; y < FIELD_HEIGHT; y++)
		field[y][0] =
		field[y][FIELD_WIDTH - 1] = 1;
	
	//フィールドの下に床を作る
	for (int x = 0; x < FIELD_WIDTH; x++)
		field[FIELD_HEIGHT - 1][x] = 1;

	//ブロックをリセットする関数を呼びだす
	ResetBlock();
} 

//ブロックとフィールドの当たり判定をする関数を宣言する
bool BlockIntersectField()
{
	//ブロックの全てのマスを反復する
	for (int y = 0; y < BLOCK_HEIGHT_MAX; y++)
		for (int x = 0; x < BLOCK_WIDTH_MAX; x++)
			//ブロックとフィールドの当たり判定をする
			if (block.shape.pattern[y][x] && field[block.y + y][block.x + x])
				return true;//当たったという結果を返す

	return false;	//当たらなかったという結果を返す
}

//揃ったブロックを削除する関数
void EraseBlocks()
{	//全ての行を反復する
	for (int y = 0; y < FIELD_HEIGHT - 1; y++)
	{	//その行が揃ったかどうかのフラグを宣言する
		bool completed = true;

		//左右の壁の内側の列を反復する
		for (int x = 1; x < FIELD_WIDTH - 1; x++)
		{	//対象のマスにブロックがないかどうか判定する
			if (!field[y][x])
			{
				completed = false;	//揃わなかった
				break;//その行のチェックを抜ける
			}
		}

		//その行が揃ったかどうか判定する
		if (completed)
		{
			//左右の壁の内側の列を反復する
			for (int x = 1; x < FIELD_WIDTH - 1; x++)
				//対象の列のブロックを削除する
				field[y][x] = 0;

			//消えた行から上の行を反復する
			for (int y2 = y; y2 > 0; y2--)
				//左右の壁の内側の列を反復する
				for (int x = 1; x < FIELD_WIDTH - 1; x++)
					//上のマスを下のマスにコピーする
					field[y2][x] = field[y2 - 1][x];

			//左右の壁の内側の列を反復する
			for (int x = 1; x < FIELD_WIDTH - 1; x++)
				//先頭行のブロックを消す
				field[0][x] = 0;
		}
	}
}



//プログラム実行の開始点を宣言する
int main()
{
	Init();

	//ゲームをリセットする関数を呼びだす
	Reset();

	DrawField();			//フィールドを描画する関数をよびだす



	clock_t lastClock = clock();	//前回の経過時間を宣言する
	//メインループ
	while (1)
	{
		clock_t newClock = clock();	//現在の時刻を宣言する

		//待機時間を経過したら
		if (newClock >= lastClock + INTERVAL)
		{
			BLOCK lastBlock = block;//ブロックの移動前のバックアップを宣言する

			block.y++;	//ブロックを落下させる

			//ブロックとフィールドが重なったかどうか判定する
			if (BlockIntersectField())
			{
				block = lastBlock;	//ブロックを移動前の状態に戻す

				for (int y = 0; y < BLOCK_HEIGHT_MAX; y++)
					for (int x = 0; x < BLOCK_WIDTH_MAX; x++)
						//ブロックをフィールドに書き込む
						field[block.y + y][block.x + x] |= block.shape.pattern[y][x];

				//揃ったブロックを削除する関数を呼びだす
				EraseBlocks();

				//ブロックを初期化する関数を呼びだす
				ResetBlock();
				
				//ブロックとフィールドが重なったかどうか判定する
				if (BlockIntersectField())
				{
					Reset();
				}

			}

			system("cls");	//画面をクリアする
			DrawField();	//フィールドを描画する関数をよびだす

			lastClock = newClock;	//前回の時間を現在の時間で更新する
		}

		//キーボード入力があったかどうかを判定する
		if (_kbhit())
		{
			BLOCK lastBlock = block;//ブロックの移動前のバックアップを宣言する

			//入力されたキーによって分岐する
			switch (_getch())
			{
			case'w':				break;	//wキーが押されても何もしない
			case's':	block.y++;	break;	//sキーが押されたら下に移動する
			case'a':	block.x--;	break;	//aキーが押されたら左に移動する
			case'd':	block.x++;	break;	//dキーが押されたら右に移動する
			default://上記以外のキーが押されたら
				{
					//回転後のブロックを宣言する
					BLOCK rotateBlock = block;

					//落下ブロックの全てのマスを反復する
					for (int y = 0; y < BLOCK_HEIGHT_MAX; y++)
						for (int x = 0; x < BLOCK_HEIGHT_MAX; x++)
						{	//回転後のブロックの形状を作成する
							rotateBlock.shape.pattern[BLOCK_WIDTH_MAX - 1 - x][y] =
									block.shape.pattern[y][x];
						}

					//回転後のブロックを適用する
					block = rotateBlock;
				}
				break;
			}

			//ブロックとフィールドが重なったかどうか判定する
			if (BlockIntersectField())
				block = lastBlock;	//ブロックを移動前の状態に戻す		
			else //ブロックとフィールドが重ならなければ
			{
				system("cls");	//画面をクリアする
				DrawField();	//フィールドを描画する関数をよびだす
			}
		}

	}


	Uninit();
}