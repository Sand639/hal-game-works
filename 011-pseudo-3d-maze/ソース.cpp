#define _CRT_SECURE_NO_WARNINGS

//ヘッダーをインクルード
#include <stdio.h>	//標準入出力ヘッダー
#include <stdlib.h>	//標準ライブラリヘッダー
#include <time.h>	//時間ヘッダー
#include <conio.h>	//キーボード入出力ヘッダー
#include <vector>	//ベクターヘッダー
#include <Windows.h>
#include "screen.h"

//定数を定義
#define MAZE_WIDTH  (8)	//迷路の幅を定義する
#define MAZE_HEIGHT (8)	//迷路の高さを定義する

//列挙定数を定義する

//方向の種類を定義する
enum 
{
	DIRECTION_NORTH,	//北
	DIRECTION_WEST,		//西
	DIRECTION_SOUTH,	//南
	DIRECTION_EAST,		//東
	DIRECTION_MAX		//方位の数
};

//プレイヤーからの相対位置を定義する
enum
{
	LOCATION_FRONT_LEFT,	//左前
	LOCATION_FRONT_RIGHT,	//右前
	LOCATION_FRONT,			//前
	LOCATION_LEFT,			//左
	LOCATION_RIGHT,			//右
	LOCATION_CENTER,		//中心
	LOCATION_MAX			//位置の数

};

//構造体を宣言

//ベクトルの構造体を宣言する
typedef struct {
	int x, y;	//座標
}VEC2;

//マップのマスを宣言する
typedef struct 
{
	bool walls[DIRECTION_MAX];	//各方位の壁の有無



}TILE;

//プレイヤーの構造体を宣言する
typedef struct{
	VEC2 position;
	int direction;
}CHARACTER;

//変数を宣言

//方位を宣言する
VEC2 directions[] =
{
	{ 0,-1},		//DIRECTION_NORTH,	//北
	{-1, 0},		//DIRECTION_WEST,	//西
	{ 0, 1},		//DIRECTION_SOUTH,	//南
	{ 1, 0}		//DIRECTION_EAST,	//東
};

//基準となるアスキーアートを宣言する
const char* all =
"L       /\n"
"#L     /#\n"
"#|L _ /|#\n"
"#|#|#|#|#\n"
"#|#|_|#|#\n"
"#|/   L|#\n"
"#/     L#\n"
"/       L\n"
;

//左前の北の壁のアスキーアートを宣言する
const char* frontLeftNorth =
"         \n"
"         \n"
"  _      \n"
" |#|     \n"
" |_|     \n"
"         \n"
"         \n"
"         \n"
;

//右前の北の壁アスキーアートを宣言する
const char* frontRightNorth =
"         \n"
"         \n"
"      _  \n"
"     |#| \n"
"     |_| \n"
"         \n"
"         \n"
"         \n"
;


//前の北の壁のアスキーアートを宣言する
const char* frontNorth =
"         \n"
"         \n"
"    _    \n"
"   |#|   \n"
"   |_|   \n"
"         \n"
"         \n"
"         \n"
;

//前の西の壁のアスキーアートを宣言する
const char* frontWest =
"         \n"
"         \n"
" |L      \n"
" |#|     \n"
" |#|     \n"
" |/      \n"
"         \n"
"         \n"
;


//前の東の壁のアスキーアートを宣言する
const char* frontEast =
"         \n"
"         \n"
"      /| \n"
"     |#| \n"
"     |#| \n"
"      L| \n"
"         \n"
"         \n"
;


//左の北の壁アスキーアートを宣言する
const char* leftNorth =
"         \n"
"_        \n"
"#|       \n"
"#|       \n"
"#|       \n"
"_|       \n"
"         \n"
"         \n"
;

//右の北の壁のアスキーアートを宣言する
const char* rightNorth =
"         \n"
"        _\n"
"       |#\n"
"       |#\n"
"       |#\n"
"       |_\n"
"         \n"
"         \n"
;

//北の壁のアスキーアートを宣言する
const char* north =
"         \n"
" ______  \n"
" |#####| \n"
" |#####| \n"
" |#####| \n"
" |_____| \n"
"         \n"
"         \n"
;

//西の壁のアスキーアートを宣言する
const char* west =
"L        \n"
"#L       \n"
"#|       \n"
"#|       \n"
"#|       \n"
"#|       \n"
"#/       \n"
"/        \n"
;

//東の壁のアスキーアートを宣言する
const char* east =
"        /\n"
"       /#\n"
"       |#\n"
"       |#\n"
"       |#\n"
"       |#\n"
"       L#\n"
"        L\n"
;


//アスキーアートのテーブルを宣言する
const char *aaTable[LOCATION_MAX][DIRECTION_MAX] =
{
	//LOCATION_FRONT_LEFT,	//左前
	{
		frontLeftNorth,	//DIRECTION_NORTH,	//北
		NULL,			//DIRECTION_WEST,	//西
		NULL,			//DIRECTION_SOUTH,	//南
		NULL			//DIRECTION_EAST,	//東
	},

	//LOCATION_FRONT_RIGHT,	//右前
	{
		frontRightNorth,//DIRECTION_NORTH,	//北
		NULL,			//DIRECTION_WEST,	//西
		NULL,			//DIRECTION_SOUTH,	//南
		NULL			//DIRECTION_EAST,	//東
	},

	//LOCATION_FRONT,			//前
	{
		frontNorth,		//DIRECTION_NORTH,	//北
		frontWest,		//DIRECTION_WEST,	//西
		NULL,			//DIRECTION_SOUTH,	//南
		frontEast		//DIRECTION_EAST,	//東
	},

	//LOCATION_LEFT,			//左
	{
		leftNorth,		//DIRECTION_NORTH,	//北
		NULL,			//DIRECTION_WEST,	//西
		NULL,			//DIRECTION_SOUTH,	//南
		NULL			//DIRECTION_EAST,	//東
	},

	//LOCATION_RIGHT,			//右
	{
		rightNorth,		//DIRECTION_NORTH,	//北
		NULL,			//DIRECTION_WEST,	//西
		NULL,			//DIRECTION_SOUTH,	//南
		NULL			//DIRECTION_EAST,	//東
	},

	//LOCATION_CENTER,		//中心
	{
		north,			//DIRECTION_NORTH,	//北
		west,			//DIRECTION_WEST,	//西
		NULL,			//DIRECTION_SOUTH,	//南
		east			//DIRECTION_EAST,	//東
	},
};

//プレイヤーからの相対座標のテーブルを宣言する
VEC2 locations[DIRECTION_MAX][LOCATION_MAX] =
{
	//DIRECTION_NORTH,		//北
	{	{-1,-1},	//LOCATION_FRONT_LEFT,	//左前
		{ 1,-1},	//LOCATION_FRONT_RIGHT,	//右前
		{ 0,-1},	//LOCATION_FRONT,		//前
		{-1, 0},	//LOCATION_LEFT,		//左
		{ 1, 0},	//LOCATION_RIGHT,		//右
		{ 0, 0},	//LOCATION_CENTER,		//中心
	},
	//DIRECTION_WEST,	//西
	{	{-1, 1},	//LOCATION_FRONT_LEFT,	//左前
		{-1,-1},	//LOCATION_FRONT_RIGHT,	//右前
		{-1, 0},	//LOCATION_FRONT,		//前
		{ 0, 1},	//LOCATION_LEFT,		//左
		{ 0,-1},	//LOCATION_RIGHT,		//右
		{ 0, 0},	//LOCATION_CENTER,		//中心
	},
	//DIRECTION_SOUTH,	//南
	{	{ 1, 1},	//LOCATION_FRONT_LEFT,	//左前
		{-1, 1},	//LOCATION_FRONT_RIGHT,	//右前
		{ 0, 1},	//LOCATION_FRONT,		//前
		{ 1, 0},	//LOCATION_LEFT,		//左
		{-1, 0},	//LOCATION_RIGHT,		//右
		{ 0, 0},	//LOCATION_CENTER,		//中心
	},
	//DIRECTION_EAST,	//東
	{	{ 1,-1},	//LOCATION_FRONT_LEFT,	//左前
		{ 1, 1},	//LOCATION_FRONT_RIGHT,	//右前
		{ 1, 0},	//LOCATION_FRONT,		//前
		{ 0,-1},	//LOCATION_LEFT,		//左
		{ 0, 1},	//LOCATION_RIGHT,		//右
		{ 0, 0},	//LOCATION_CENTER,		//中心
	},
};

DWORD g_Mode_default;	//元のウィンドウモードを保存しておく場所
HANDLE g_hStdin;		//自分のウィンドウを特定する

TILE maze[MAZE_HEIGHT][MAZE_WIDTH];	//迷路を宣言する

CHARACTER player;	//プレイヤーを宣言する


//関数を宣言

//ベクトルを加算する関数を宣言する
VEC2 VecAdd(VEC2 _v0, VEC2 _v1)
{
	return{
		_v0.x + _v1.x,
		_v0.y + _v1.y
	};
}

//対象の座標がマップの範囲内かどうかを判定する関数
bool InsideMaze(VEC2 _position)
{
	//対象の座標が迷路の範囲内かどうかを返す
	return (_position.x >= 0)
		&& (_position.x < MAZE_WIDTH)
		&& (_position.y >= 0)
		&& (_position.y < MAZE_HEIGHT);
}

//壁を壊す関数を宣言する
void EraseWall(VEC2 _position, int _direction)
{
	//対象の座標が迷路の範囲内化同かを判定する
	if (!InsideMaze(_position))
		return;	//関数を抜ける
	
	//対象の壁を消す
	maze[_position.y][_position.x].walls[_direction] = false;

	//隣のマスの座標を宣言する
	VEC2 nextPosition = VecAdd(_position, directions[_direction]);

	//隣のマスが迷路の範囲内かどうかを判定する
	if (InsideMaze(nextPosition))
	{
		//隣の部屋の消す壁の方向を宣言する
		int nextDirection = (_direction + 2) % DIRECTION_MAX;

		//隣の部屋の壁を消す
		maze[nextPosition.y][nextPosition.x].walls[nextDirection] = false;
	}
}

//対象の壁を消して良いかどうか判定する関数を宣言する
bool CanEraseWall(VEC2 _position, int _direction)
{
	//隣の座標を宣言する
	VEC2 nextPosition = VecAdd(_position, directions[_direction]);

	//隣の座標が迷路の範囲でないでないかどうか判定する
	if (!InsideMaze(nextPosition))
		return false;	//消してはいけないという結果を返す

	//全ての方向を反復する
	for (int i = 0; i < DIRECTION_MAX; i++)
		//壁が消されているかどうか判定する
		if (!maze[nextPosition.y][nextPosition.x].walls[i])
			return false;	//消してはいけないという結果を返す

	return true;	//消しても良いという結果を返す
}

//迷路をランダム生成する関数を宣言する
void GenerateMap()
{
	//マップの全ての行を反復する
	for (int y = 0; y < MAZE_HEIGHT; y++)
		//マップの全ての列を反復する
		for (int x = 0; x < MAZE_WIDTH; x++)
			//マスの全ての方向を反復する
			for (int i = 0; i < DIRECTION_MAX; i++)
				//対象の方向を壁にする
				maze[y][x].walls[i] = true;

	//対象の座標を宣言する
	VEC2 currentPosition = { 0,0 };

	//壁を消すべきマスのリストを宣言する
	std::vector<VEC2> toEraseWallPositions;

	//壁を消すべきマスのリストに現在のマスを加える
	toEraseWallPositions.push_back(currentPosition);

	//無限ループする
	while(1)
	{
		//消す壁の候補リストを宣言する
		std::vector<int> canEraseWalls;

		//全ての包囲を反復する
		for (int i = 0; i < DIRECTION_MAX; i++)
			//対象の方位の壁を消してよいのであれば
			if (CanEraseWall(currentPosition, i))
				//消す壁の候補リストに対象の壁を追加する
				canEraseWalls.push_back(i);

		//消すべき壁があるかどうか判定する
		if (canEraseWalls.size() > 0)
		{
			//消す壁を宣言する
			int eraseWall = canEraseWalls[rand() % canEraseWalls.size()];

			//対象の壁を消す
			EraseWall(currentPosition, eraseWall);

			//消した壁の向こうに移動する
			currentPosition = VecAdd(currentPosition, directions[eraseWall]);


			//壁を消すべきマスの座標リストに現在の座標を加える
			toEraseWallPositions.push_back(currentPosition);

		}
		//消すべき壁がない時
		else
		{
			//壁を消すべきマスのリストから現在のマスを削除する
			toEraseWallPositions.erase(toEraseWallPositions.begin());

			//壁を消すべきマスのリストが空かどうか判定する
			if(toEraseWallPositions.size() <= 0)
			break;	//ループを抜ける

			//壁を消すべきマスのリストの戦闘のマスに移動する
			currentPosition = toEraseWallPositions.front();
		}
	}
}

//マップを描画する関数
void DrawMap()
{
	//マップの全ての行を反復する
	for (int y = 0; y < MAZE_HEIGHT; y++)
	{
		//マップの全ての列を反復する
		for (int x = 0; x < MAZE_WIDTH; x++)
		{
			//北の壁を描画する
			printf("＋%s＋", maze[y][x].walls[DIRECTION_NORTH] ? "―" : "　");
		}

		printf("\n");	//1行描画する毎に改行する

		//マップの全ての列を反復する
		for (int x = 0; x < MAZE_WIDTH; x++)
		{
			//プレイヤーの座標を描画中なら
			if ((x == player.position.x) && (y == player.position.y))
			{
				//方位のアスキーアートを宣言する
				const char* directionAA[] =
				{
					"↑",//DIRECTION_NORTH,	//北
					"←",//DIRECTION_WEST,	//西
					"↓",//DIRECTION_SOUTH,	//南
					"→"//DIRECTION_EAST,	//東
				};

				//東西の壁を描画する
				printf("%s%s%s",
					maze[y][x].walls[DIRECTION_WEST] ? "｜" : "　",
					directionAA[player.direction],
					maze[y][x].walls[DIRECTION_EAST] ? "｜" : "　");
			}
			else
			{
				//東西の壁を描画する
				printf("%s　%s",
					maze[y][x].walls[DIRECTION_WEST] ? "｜" : "　",
					maze[y][x].walls[DIRECTION_EAST] ? "｜" : "　");
			}
		}

		printf("\n");	//1行描画する毎に改行する

		//マップの全ての列を反復する
		for (int x = 0; x < MAZE_WIDTH; x++)
		{
			//南の壁を描画する
			printf("＋%s＋",maze[y][x].walls[DIRECTION_SOUTH] ? "―" : "　");
		}

		printf("\n");	//1行描画する毎に改行する


	}
}

void Init()
{
	//タイトル用に画面サイズを変更する
	ScreenInit(80, 33, 20);
	const HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hStdin, &g_Mode_default);

}

void Uninit()
{
	//※ゲームの終了時にウィンドウサイズ、フォントサイズの設定を実行前の状態に復元する
	ScreenEnd();
}

//迷路を疑似3D描画する関数を宣言する
void Draw3D()
{
	//描画用の合成アスキーアートを宣言する
	char conbinedAA[] =

		"         \n"
		"         \n"
		"         \n"
		"         \n"
		"         \n"
		"         \n"
		"         \n"
		"         \n";

	//全ての相対位置を反復する
	for (int i = 0; i < LOCATION_MAX; i++)
	{
		//絶対位置を宣言する
		VEC2 position = VecAdd(player.position, locations[player.direction][i]);

		//絶対位置が迷路の範囲内か判定する
		if (!InsideMaze(position))
			continue;//次の相対位置へスキップする

		//全ての範囲を反復する
		for (int j = 0; j < DIRECTION_MAX; j++)
		{
			//相対方位を宣言する
			int direction = (DIRECTION_MAX + j - player.direction) % DIRECTION_MAX;

			//対象の壁がないかどうか判定する
			if (!maze[position.y][position.x].walls[j])
				continue;	//次の包囲へスキップする


			//合成するアスキーアートを宣言する
			const char* aa = aaTable[i][direction];

			//合成するアスキーアートがないかどうか判定する
			if (!aa)
				continue;	//次の相対位置へスキップする


			//アスキーアートの全ての文字を反復する
			for (int i = 0; i < sizeof(conbinedAA); i++)
			{
				//対象の文字がスペースでないかどうか判定する
				if (aa[i] != ' ')
					//描画用合成アスキーアートに、合成するアスキーアートを書き込む
					conbinedAA[i] = aa[i];
			}

		}
	}

	printf(conbinedAA);

	//半角文字を全角文字へ変換するテーブルを宣言する
	char aa[256][2 + 1];
	
	//基準となるアスキーアートを宣言する
	const char* all =
		"L       /\n"
		"#L     /#\n"
		"#|L _ /|#\n"
		"#|#|#|#|#\n"
		"#|#|_|#|#\n"
		"#|/   L|#\n"
		"#/     L#\n"
		"/       L\n"
		;

	//アスキーアートの全てのもじれつ配列を反復する
	for (int i = 0; i < sizeof(conbinedAA); i++)
		switch (conbinedAA[i])
		{
			//対象の文字で分岐する
			case' ':			//' 'なら
				printf("　"); 	//"　"を描画する
				break;

			case'#':			//'#'なら
				printf("　"); 	//"　"を描画する
				break;

			case'_':			//'_'なら
				printf("＿");	//"＿"を描画する
				break;

			case'|':			//'|'なら
				printf("｜"); 	//"｜"を描画する
				break;

			case'/':			//'/'なら
				printf("／"); 	//"／"を描画する
				break;

			case'L':			//'L'なら
				printf("＼");	//"＼"を描画する
				break;

			default:	//上記以外の文字なら
				//そのまま出力する
				printf("%c", conbinedAA[i]);
				break;
		}
}

//ゲームをリセットする関数を宣言する
void Reset()
{
	GenerateMap();		//迷路をランダムで生成する関数を呼びだす

	//プレイヤーの座標を初期化する
	player.position = { 0,0 };

	//プレイヤーの方位を初期化する
	player.direction = DIRECTION_NORTH;
}

//プログラムの実行開始点を宣言
int main()
{
	//乱数をシャッフルする
	srand((unsigned int)time(NULL));

	//初期化
	Init();

	//ゲームをリセットする関数を呼びだす
	Reset();

	//マップを描画する関数を呼びだす
	DrawMap();

	//メインループ
	while (1)
	{
		//画面をクリアする
		system("cls");

		//迷路を疑似3D描画する関数を呼びだす
		Draw3D();

		//マップを描画する関数を呼びだす
		DrawMap();

		//入力されたキーで分岐する
		switch (_getch())
		{
		case'W':	//Wキーが押されたら
		case'w':
			//プレイヤーの目の前が壁でないかどうかを判定する
			if(!maze[player.position.y][player.position.x].walls[player.direction])
			{
				//前進先の座標を宣言する
				VEC2 nextPosition = VecAdd(player.position, directions[player.direction]);

				//前進先の座標が迷路の範囲内かどうか判定する
				if (InsideMaze(nextPosition))
				{
					//前進先の座標を適用する
					player.position = nextPosition;

					//ゴールに到達したかどうか判定する
					if ((player.position.x == MAZE_WIDTH - 1) 
						&& (player.position.y == MAZE_HEIGHT - 1))
					{
						system("cls");	//画面をクリアする

						//メッセージを表示する
						printf("ＣＯＮＧＲＡＴＵＬＡＴＩＯＮＳ！\n\n"
							"あなたは　ついに　おうけの　まいぞうきんを　はっけんした！\n"
							"おうごんの　かがやきが　きみの　ぼうけんの　きずを　いやしてくれた…\n\n"
							"ＴＨＥ　ＥＮＤ");
						_getch();//キーボード入力を待つ

						Reset();//ゲームをリセットする
					}
				}
			}
			break;
		case'S':	//Sキーが押されたら
		case's':
			player.direction += 2;
			break;
		case'A':	//Aキーが押されたら
		case'a':
			player.direction++;
			break;
		case'D':	//Dキーが押されたら
		case'd':
			player.direction--;
			break;
		default:
			continue;
			break;
		}

		//プレイヤーの向ている方位を範囲内に補正する
		player.direction = (DIRECTION_MAX + player.direction) % DIRECTION_MAX;
	}

	Uninit();

	return 0;
}



