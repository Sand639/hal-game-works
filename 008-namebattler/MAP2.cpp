#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>	//Key入力処理
#include "main.h"

//プロトタイプ宣言

//初期化関数
void Init();
void InitPosition();
void InitEnemy();

//キー入力
int KEY2();

//キャラの移動前の位置を保存しておく
void OldPos();

//移動後の場所が障害物かチェックする
int Obstacle2();
void CollisionEnter();
void EnemyMove();

//マップ描画
void DrawFiled2();


//グローバル変数
MAP2VARIVABLE V2;	//map2の変数
POSITION Ppos2;		//プレイヤー座標
POSITION E2pos;		//敵2の座標
POSITION E3pos;		//敵3の座標
ENEMY E2;			//敵2の能力
ENEMY E3;			//敵3の能力

/*******************************************************************************
* マップ2プログラム
*******************************************************************************/
void MAP2()
{
	PLAYER* player = GetPlayer();

	if (player->SaveSwitch == 0)
	{
		Init();	//初期化
	}

	int con = 0;		//continue関数を動作させるかどうか

	printf("\nEnterを押してください\n");

	//フロア2
	while (V2.loop < 1)
	{
		//セーブ後最初を無視する
		if (player->SaveSwitch == 0)
		{
			//キャラの移動前の位置を保存しておく
			OldPos();

			//キー入力移動
			con = KEY2();
			if (con == 1)	continue;		//移動以外のキーだった場合continueでスキップ

			//移動後の場所が障害物かチェックする
			V2.loop = Obstacle2();
			if (V2.loop >= 1)	continue;

			//プレイヤーと敵の衝突処理
			CollisionEnter();

			//敵移動
			EnemyMove();

			//マップ描画
			DrawFiled2();

			//プレイヤーと敵の衝突処理
			CollisionEnter();

			//戦闘画面に遷移
			if (E2pos.survival == 2)
			{
				con = E2Battle();	//敵2戦闘処理

				printf("\nEnterを押してください\n");

				if (con == 1)	continue;
			}

			//戦闘画面に遷移
			if (E3pos.survival == 2)
			{
				con = E3Battle();	//敵3戦闘処理

				printf("\nまだ作成途中です...\n");
				printf("\nEnterを押してください\n");
				E3pos.survival = 0;
				if (con == 1)	continue;
			}



		}

		printf("\nWASDを押してください\n");

		player->SaveSwitch = 0;
	}
}

//初期化関数
void Init()
{	InitPosition();
	InitEnemy();
}

//座標初期化
void InitPosition()
{
	//プレイヤー座標の初期化
	Ppos2.x = 2;	//x座標
	Ppos2.y = 2;	//y座標

	//敵2座標の初期化
	E2pos.x = 4;	//x座標
	E2pos.y = 10;	//y座標

	//敵3座標の初期化
	E3pos.x = 10;	//x座標
	E3pos.y = 10;	//y座標

	OldPos();
}

//敵能力初期化
void InitEnemy()
{
	//敵2の初期化
	strcpy(E2.name, "ポルターガイスト");
	E2.EH = 150;
	E2.EA = 50;
	E2.Evasion = 70;

	//敵3の初期化
	strcpy(E3.name, "ロストソウル");
	E3.EH = 300;
	E3.EA = 30;
	E3.Evasion = 80;

}

//移動前の位置
void OldPos()
{
	//プレイヤー座標
	Ppos2.old_x = Ppos2.x;
	Ppos2.old_y = Ppos2.y;

	//敵2座標
	E2pos.old_x = E2pos.x;
	E2pos.old_y = E2pos.y;

	//敵3座標
	E3pos.old_x = E3pos.x;
	E3pos.old_y = E3pos.y;

}

//key入力
int KEY2()
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
		Ppos2.y--;
		break;
	case 'A':
	case 'a':
		Ppos2.x--;
		break;
	case 'S':
	case 's':
		Ppos2.y++;
		break;
	case 'D':
	case 'd':
		Ppos2.x++;
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
		Save2();
		break;
	default:
		return 1;
		break;
	}

	if (con == 1)	return 1;

	return 0;
}


//移動後の場所が障害物かチェックする
int Obstacle2()
{
	PLAYER* P = GetPlayer();
	int IronSword = 50;

	char yesno = 'y';
	int i = 0;

	switch (V2.field[Ppos2.y][Ppos2.x])
	{
	case 1:		//壁だった
		Ppos2.x = Ppos2.old_x;	//移動前の場所に戻る
		Ppos2.y = Ppos2.old_y;
		break;

	case 2:		//階段
		Ppos2.x = Ppos2.old_x;	//移動前の場所に戻る
		Ppos2.y = Ppos2.old_y;

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

	case 3:
		printf("%sはアイアンソードを手に入れた\n", P->name);
		V2.field[Ppos2.y][Ppos2.x] = 0;	//手に入れたから0にしちゃう

		printf("%sの攻撃力が%d上がった\nEnterで進む\n", P->name,IronSword);
		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		P->AT += IronSword;
		break;
	}
	return 0;

}

//プレイヤーと敵の衝突処理
void CollisionEnter()
{
	//プレイヤーと敵2の衝突判定
	if (Ppos2.y == E2pos.y && Ppos2.x == E2pos.x)
	{
		printf("\n敵が現れた\nEnterで進む\n");

		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		system("cls");

		//敵をマップから除外
		E2pos.x = -1;
		E2pos.y = -1;

		E2pos.survival = 2;	//戦闘開始
	}

	//プレイヤーと敵3の衝突判定
	if (Ppos2.y == E3pos.y && Ppos2.x == E3pos.x)
	{
		printf("\n敵が現れた\nEnterで進む\n");

		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		system("cls");

		//敵をマップから除外
		E3pos.x = -1;
		E3pos.y = -1;

		E3pos.survival = 2;	//戦闘開始
	}
}

//敵移動
void EnemyMove()
{
	//敵２
	if (E2pos.survival == 1)
	{
		int Ran = 1 + rand() % 100;
		int Br = 0;
		Br++;
		if (Br == 5)
		{
			Br = 0;
		}
		else
		{
			if ((Ppos2.x < E2pos.x) && (Ppos2.y < E2pos.y))
			{

				if (Ran <= 50)
				{
					E2pos.y--;
				}
				else if (Ran <= 100)
				{
					E2pos.x--;
				}

			}
			else if ((Ppos2.x < E2pos.x) && (Ppos2.y > E2pos.y))
			{
				if (Ran <= 50)
				{
					E2pos.y++;
				}
				else if (Ran <= 100)
				{
					E2pos.x--;
				}
			}
			else if ((Ppos2.x > E2pos.x) && (Ppos2.y < E2pos.y))
			{
				if (Ran <= 50)
				{
					E2pos.y--;
				}
				else if (Ran <= 100)
				{
					E2pos.x++;
				}
			}
			else if ((Ppos2.x > E2pos.x) && (Ppos2.y > E2pos.y))
			{
				if (Ran <= 50)
				{
					E2pos.y++;
				}
				else if (Ran <= 100)
				{
					E2pos.x++;
				}
			}
			else
			{

			}
		}

		//敵衝突判定
		switch (V2.field[E2pos.y][E2pos.x])
		{
		case 1:		//壁
		case 2:		//階段
		case 3:
			E2pos.x = E2pos.old_x;	//移動前の場所に戻る
			E2pos.y = E2pos.old_y;
			break;
		default:
			break;
		}
	}

	//敵3
	if (E3pos.survival == 1)
	{
		int Ran = 1 + rand() % 100;
		if (Ran <= 25)
		{
			E3pos.y--;
		}
		else if (Ran <= 50)
		{
			E3pos.x--;
		}
		else if (Ran <= 75)
		{
			E3pos.y++;
		}
		else if (Ran <= 100)
		{
			E3pos.x++;
		}

		//敵衝突判定
		switch (V2.field[E3pos.y][E3pos.x])
		{
		case 1:		//壁
		case 2:		//階段
		case 3:
			E3pos.x = E3pos.old_x;	//移動前の場所に戻る
			E3pos.y = E3pos.old_y;
			break;
		default:
			break;
		}

	}

}

//マップ描画
void DrawFiled2()
{
	PLAYER* player = GetPlayer();
	POTION* potion = Getpotion();

	if (V2.loop == 0)
	{
		//マップ画面
		system("cls");
		int UI = 0;
		for (int y = 0; y < 15; y++)
		{
			for (int x = 0; x < 15; x++)
			{
				//　プレイヤー表示
				if ((x == Ppos2.x) && (y == Ppos2.y))
				{
					printf("Ｐ");
					continue;	//Pを表示してスキップ
				}

				if (E2pos.survival == 1)
				{
					if ((x == E2pos.x) && (y == E2pos.y))
					{
						printf("Ｅ");	//敵
						continue;	//Eを表示してスキップ
					}
				}

				if (E3pos.survival == 1)
				{
					if ((x == E3pos.x) && (y == E3pos.y))
					{
						printf("Ｅ");	//敵
						continue;	//Eを表示してスキップ
					}
				}

				switch (V2.field[y][x])
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

				case 3:
					printf("？");	//今回は剣
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


//ポインタゲット関数

POSITION* GetPpos2()
{
	return &Ppos2;
}

POSITION* GetE2pos()
{
	return &E2pos;
}

POSITION* GetE3pos()
{
	return &E3pos;
}

MAP2VARIVABLE* GetMAP2()
{

	return &V2;
}

ENEMY* GetE2()
{
	return &E2;
}

ENEMY* GetE3()
{
	return &E3;
}
