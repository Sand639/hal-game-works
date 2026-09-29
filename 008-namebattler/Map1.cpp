#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>	//Key入力処理
#include "main.h"

//プロトタイプ宣言
void E1_MOVE();
void E1Obstacle();
void DrawFiled1(int E1);
int EChoice(int EC);
int Obstacle();			//移動後の場所が障害物かチェックする　マップ内処理
int CollisionEnter();	//プレイヤーと敵の衝突処理
void EInitPos();		//敵の位置初期化
void Old_Player_Pos();	//移動前のプレイヤー座標保存

//キー入力
int KEY();

//グローバル変数
MAPVARIVABLE V1;//map1の変数
POSITION Ppos;	//プレイヤー座標
POSITION E1pos;	//敵1の座標
/*******************************************************************************
* マップ1プログラム
*******************************************************************************/

void MAP1()
{
	PLAYER* player = GetPlayer();

	if (player->SaveSwitch == 0)
	{
		//敵1の初期化
		EInitPos();
	}

	//変数
	int con;		//continue関数を動作させるかどうか

	printf("\nEnterを押してください\n");

	//フロア1
	while (V1.loop < 1)
	{
		//セーブ後最初を無視する
		if (player->SaveSwitch == 0)
		{
			//プレイヤーの移動前の位置を保存しておく
			Old_Player_Pos();

			//WASD移動とか	詳しくは下のKey入力から
			con = KEY();

			//移動以外のキーだった場合continueでスキップ
			if (con == 1)	continue;


			//移動後の場所が障害物かチェックする
			V1.loop = Obstacle();
			if (V1.loop >= 1)	continue;

			//プレイヤーと敵の衝突判定
			if (Ppos.y == E1pos.y && Ppos.x == E1pos.x)
			{
				E1pos.survival = CollisionEnter();

				//敵をマップから除外
				E1pos.x = -1;
				E1pos.y = -1;
			}


			//敵1移動
			if (E1pos.survival == 1)
			{
				E1_MOVE();

				E1Obstacle();
			}


			//マップ描画
			DrawFiled1(E1pos.survival);


			//プレイヤーと敵の衝突判定
			if (Ppos.y == E1pos.y && Ppos.x == E1pos.x)
			{
				E1pos.survival = CollisionEnter();

				//敵の判定を無効化
				E1pos.x = -1;
				E1pos.y = -1;
			}

		}

		//戦闘画面に遷移
		if (E1pos.survival == 2)
		{
			con = EnemyBattle();	//敵1戦闘処理

			printf("\nEnterを押してください\n");
			if (con == 1)	continue;
		}

		printf("\nWASDを押してください\n");

		player->SaveSwitch = 0;
	}
}

void EInitPos()
{
	E1pos.x = 5;
	E1pos.y = 5;

	E1pos.old_x = E1pos.x;
	E1pos.old_y = E1pos.y;
}

//プレイヤーの移動前の位置を保存しておく
void Old_Player_Pos()
{
	 Ppos.old_x = Ppos.x;
	 Ppos.old_y = Ppos.y;
}


//key入力
int KEY()
{
	int con = 0;
	int Z = 0;
	int H = 0;
	int B = 0;

	int key = _getch();

	if ((key == 0) || (key == 0xe0))
	{
		key = _getch();
	}
	//WASD移動
	switch (key)
	{
	case 'W':
	case 'w':
		Ppos.y--;
		break;
	case 'A':
	case 'a':
		Ppos.x--;
		break;
	case 'S':
	case 's':
		Ppos.y++;
		break;
	case 'D':
	case 'd':
		Ppos.x++;
		break;
	case 'Z':
	case 'z':
		//操作説明＆表記説明
		con = Explanation();
		break;
	case 'H':
	case 'h':
		//回復薬使用
		con = Recovery();
		break;
	case 'B':
	case 'b':
		//聖水使用
		con = HolyWater();
		break;
	case 0x0D:	//EnterKey
		break;
	case 'Q':
	case 'q':
		//セーブ,中断
		Save();
		break;
	default:
		return 1;
		break;
	}

	if (con == 1)	return 1;

	return 0;
}


//移動後の場所が障害物かチェックする　マップ内処理
int Obstacle()
{
	char yesno = 'y';
	int i = 0;

	switch (V1.field[Ppos.y][Ppos.x])
	{
	case 1:		//壁だった
		Ppos.x = Ppos.old_x;	//移動前の場所に戻る
		Ppos.y = Ppos.old_y;
		break;

	case 2:		//階段
		Ppos.x = Ppos.old_x;	//移動前の場所に戻る
		Ppos.y = Ppos.old_y;

		//次のフロアに進むか
		while (i < 1)
		{
			printf("階段を見つけた\n次のフロアに進みますか？Y/N：\n");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%c", &yesno);

			if ((yesno == 'Y') || (yesno == 'y'))
			{
				//次のフロアへ
				system("cls");

				//ループ抜け出し
				i += 1;
				return 1;
			}
			else if ((yesno == 'N') || (yesno == 'n'))
			{
				i += 1;
			}
			else
			{
				printf("選択肢の入力方式が間違っています。\nY,y,N,nで入力してください\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち
			}
		}
		break;
	}
	return 0;
}


//プレイヤーと敵の衝突処理
int CollisionEnter()
{
	printf("\n敵が現れた\nEnterで進む\n");

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	system("cls");

	return 2;	//戦闘開始
}


//敵1移動
void E1_MOVE()
{
	E1pos.old_x = E1pos.x;	//敵の移動前の位置を保存しておく
	E1pos.old_y = E1pos.y;

	int Ran = 1 + rand() % 100;

	if (Ran <= 15)
	{
		E1pos.y--;
	}
	else if (Ran <= 30)
	{
		E1pos.x--;
	}
	else if (Ran <= 45)
	{
		E1pos.y++;
	}
	else if (Ran <= 60)
	{
		E1pos.x++;
	}
	else if (Ran <= 100)
	{

	}
}


//敵1衝突判定
void E1Obstacle()
{
	//敵衝突判定
	switch (V1.field[E1pos.y][E1pos.x])
	{
	case 1:		//壁
	case 2:		//階段
		E1pos.x = E1pos.old_x;	//移動前の場所に戻る
		E1pos.y = E1pos.old_y;
		break;
	default:
		break;
	}
}

//マップ1描画
void DrawFiled1(int E1)
{
	PLAYER* player = GetPlayer();
	POTION* potion = Getpotion();

	if (V1.loop == 0)
	{
		//マップ画面
		system("cls");
		int UI = 0;
		for (int y = 0; y < 10; y++)
		{
			for (int x = 0; x < 10; x++)
			{
				//　プレイヤー表示
				if ((x == Ppos.x) && (y == Ppos.y))
				{
					printf("Ｐ");
					continue;	//Pを表示してスキップ
				}

				if (E1 == 1)
				{
					if ((x == E1pos.x) && (y == E1pos.y))
					{
						printf("Ｅ");	//敵
						continue;	//Eを表示してスキップ
					}
				}

				switch (V1.field[y][x])
				{
				case 0:
					printf("　");	//移動可能床
					break;

				case 1:
					printf("■");	//壁
					break;

				case 2:
					printf("□");	//階段
					break;
				default:
					break;
				}
			}

			//　UI　右画面に表示
			if (UI == 0)
			{
				printf("　　HP:%d", player->HP);
			}
			else if (UI == 1)
			{
				printf("　　MP:%d", player->MP);
			}
			else if (UI == 3)
			{
				printf("　　回復薬:%d個", potion->HPplus);
			}
			else if (UI == 4)
			{
				printf("　　聖　水:%d個", potion->MPplus);
			}
			else if (UI == 6)
			{
				printf("　　Zボタンで操作説明&表記説明");
			}
			UI++;
			printf("\n");
		}
	}

}


POSITION* GetPpos()
{
	return &Ppos;
}

POSITION* GetE1pos()
{
	return &E1pos;
}

MAPVARIVABLE* GetMAP1()
{
	return &V1;
}