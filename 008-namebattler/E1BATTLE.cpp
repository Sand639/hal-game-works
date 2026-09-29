#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

//プロトタイプ宣言
int EChoice(int EC);			//敵キャラ選択肢
int PlayerChoice(int PC);		//プレイヤー選択
void Attack();					//プレイヤー通常攻撃ダメージ
void E1Init();					//敵1の初期化
int PlayerAttack(int num);		//プレイヤー選択肢の1が選ばれた時
int SpAttack();					//プレイヤー特殊攻撃
void RunAway();					//逃げる
void ShadAttack(int EC);		//シャド選択肢攻撃
void EnemyAttack();				//敵の攻撃
void EnemySpAttack();			//敵の特別攻撃



//グローバル変数
ENEMY E1;


//敵1戦闘処理
int EnemyBattle()
{	PLAYER* P = GetPlayer();
	POSITION* Epos = GetE1pos();

	if (P->SaveSwitch == 0)
	{
		if (E1.Init == 0)
		{
			E1Init();
			E1.Init++;
		}

		system("cls");

		printf("\nシャドが現れた\n");
		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("\nシャドとの戦闘が始まった\nHP%d MP%d\n", P->HP, P->MP);
		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("\n\nシャドはこちらを見て微笑んでいる\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち
	}


	int EC = 0;	//敵の選択肢
	int PC = 0;	//プレイヤーの選択肢
	int con = 0;//continueするかどうか


	//戦闘プログラム
	while ((E1.EH >= 0) && (P->HP >= 0) && (Epos->survival == 2))
	{
		con = 0;

		//敵ディフェンス設定
		int A = (E1.EH / 5) + 1;
		E1.defense = 1 + rand() % A;
		//プレイヤーディフェンス設定
		P->VIT2 = 1 + rand() % P->VIT;

		//敵の選択肢
		EC = EChoice(EC);

		system("cls");

		printf("\nHP%dMP%d\n\n1攻撃\n\n2持ち物\n\n3逃げる\n\n4セーブ・中断\n\n選択肢入力：", P->HP, P->MP);
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%d", &PC);

		system("cls");

		//プレイヤー選択肢行動
		con = PlayerChoice(PC);
		if (con == 1)
		{
			continue;
		}


		//ここから敵の行動
		if ((Epos->survival == 2) && (E1.EH > 0))
		{
			ShadAttack(EC);
		}

		//敵HP0判定
		if (E1.EH <= 0)
		{
			Epos->survival = 0;
			printf("シャドは倒れた\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			return 1;
		}
		//プレイヤーHP0判定
		PHP0(P->HP);
	}

	return 1;
}

//敵1の選択肢
int EChoice(int EC)
{
	int Ran = 1 + rand() % 100;
	if (Ran <= 50)
	{
		//攻撃
		EC = 1;
	}
	else if (Ran <= 80)
	{
		//必殺技
		EC = 2;
	}
	else if (Ran <= 100)
	{
		//回避　or 様子見
		EC = 3;
	}
	return EC;
}


//プレイヤー選択肢
int PlayerChoice(int PC)
{
	int num = 0;	//選択肢
	int con = 0;	//continueするかどうか

	switch (PC)
	{
	case 1:		//攻撃　と　MP攻撃　と　魔法回復　に分岐


		printf("\n1通常攻撃\n\n2リダクション(MP10消費)\n\n3ヒール(MP10消費)\n\n4戻る\n\n選択肢入力：");
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%d", &num);

		con = PlayerAttack(num);
		break;

	case 2:		//持ち物欄		回復薬　と　聖水　に分岐
		system("cls");

		printf("\n1回復薬\n\n2聖水\n\n3戻る\n\n選択肢:");
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%d", &num);

		con = Inventory(num);
		break;
	case 3:		//逃げる
		RunAway();
		break;

	case 4:
		//中段セーブ
		con = Save();
		break;

	default:

		printf("選択肢の入力方式が間違っています。\n1〜4で入力してください。\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち
		con = 1;
		break;

	}
	if (con == 1)
	{
		return 1;
	}

	return 0;
}

//中断セーブ
int Save()
{
	char yesno = 'y';

	PLAYER* player = GetPlayer();
	POTION* potion = Getpotion();
	ENEMY* E1 = GetE1();
	POSITION* Ppos = GetPpos();
	POSITION* E1pos = GetE1pos();
	MAPVARIVABLE* V1 = GetMAP1();

	player->SaveSwitch = 1;
	player->MAP = 1;

	FILE* fp = NULL;

	//ファイルの書き込み
	fp = fopen("savedata.dat", "wb");
	if (fp == NULL)
	{
		printf("データファイルのオープンに失敗しました\n");
		exit(0);
	}

	//書き込み
	fwrite(player,sizeof(*player),1,fp);	//プレイヤー構造体
	fwrite(potion,sizeof(*potion),1,fp);	//ポーション構造体
	fwrite(E1,sizeof(*E1),1,fp);			//敵1構造体
	fwrite(Ppos, sizeof(*Ppos), 1, fp);		//プレイヤー座標
	fwrite(E1pos, sizeof(*E1pos), 1, fp);	//敵1座標
	fwrite(V1, sizeof(*V1), 1, fp);			//map1変数

	printf("セーブが完了しました\nこのまま中断しますか？\nY/N:\n");

	fclose(fp);  // ファイルを閉じる

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)scanf("%c", &yesno);

	if ((yesno == 'Y') || (yesno == 'y'))
	{
		printf("EnterKeyで終了します");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		exit(-1);
	}

	printf("EnterKeyで戻ります");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	return 1;
}

//シャド選択肢攻撃
void ShadAttack(int EC)
{
	switch (EC)
	{
	case 1:	//影討ち
		printf("%sの影討ち\n", E1.name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		EnemyAttack();

		break;

	case 2:	//シャドウダイブ
		printf("%sのシャドウダイブ\n", E1.name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		EnemySpAttack();
		break;

	case 3:
		printf("%sは様子を見ている\n", E1.name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		break;
	}
}

//敵の攻撃
void EnemyAttack()
{
	PLAYER* player = GetPlayer();

	//ダメージ計算
	int Damage = E1.EA - player->VIT2;

	if (Damage >= 0)
	{
		player->HP -= Damage;

		printf("%sに%dダメージ\n", player->name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち	
	}
	else
	{
		printf("しかし%sにダメージを与えられない\n", player->name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち	
	}
}

//敵の特殊攻撃
void EnemySpAttack()
{
	PLAYER* player = GetPlayer();

	float A = RandomFloat();	//1.5〜2の間をランダムで決定

	//ダメージ計算
	int Damage = E1.EA * A - player->VIT2;

	if (Damage >= 0)
	{
		player->HP -= Damage;

		printf("%sに%dダメージ\n", player->name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち	
	}
	else
	{
		printf("しかし%sにダメージを与えられない\n", player->name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち	
	}

}



//逃げる
void RunAway()
{
	PLAYER* P = GetPlayer();
	POSITION* Ppos = GetPpos();
	POSITION* Epos = GetE1pos();

		printf("%sは逃げ出した\n", P->name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		int BP = 1 + rand() % 100;
		if (BP <= 90)
		{
			Epos->x = Epos->old_x;
			Epos->y = Epos->old_y;
			Ppos->x = Ppos->old_x;
			Ppos->y = Ppos->old_y;
			Epos->survival = 1;
		}


}


//持ち物欄
int Inventory(int num)
{
	int con = 0;	//continueするかしないか
	switch (num)
	{
	case 1:
		con = Recovery0();
		break;

	case 2:
		con = HolyWater0();
		break;

	default:

		printf("選択肢の入力方式が間違っています。\n1〜3で入力してください。\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

	case 3:
		//戦闘中のwhileまで戻る
		system("cls");
		con = 1;
		break;
	}

	if (con == 1)
	{
		return 1;
	}
	return 0;
}

//シャドの初期化
void E1Init()
{
	strcpy(E1.name, "シャド");
	E1.EH = 100;
	E1.EA = 30;
	E1.Evasion = 90;

}


//プレイヤー選択肢の1が選ばれた時
int PlayerAttack(int num)
{
	int con = 0;	//continueするかしないか

	switch (num) 
	{
	case 1:
		//通常攻撃
		Attack();
		break;

	case 2:
		//特殊攻撃
		con = SpAttack();
		break;

	case 3:
		//回復魔法
		con = Heal();
		break;

	default:

		printf("選択肢の入力方式が間違っています。\n1〜4で入力してください。\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

	case 4:
		//戦闘中のwhileまで戻る
		system("cls");
		con = 1;
		break;

	} 

	if (con == 1)
	{
		return 1;
	}
	return 0;

}

//プレイヤー回復魔法
int Heal()
{
	PLAYER* P = GetPlayer();

	//MPが10以上あれば
	if (P->MP >= 10)
	{
		printf("%sのヒール\n", P->name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (P->HP == P->MaxHP)
		{
			printf("HPが満タンのようだ");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			return 1;
		}
		else
		{
			P->HP += 150;

			if (P->MaxHP <= P->HP)
			{
				P->HP = P->MaxHP;
			}

			printf("%sのHPは%dになった", P->name, P->HP);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			P->MP -= 10;
		}

	}
	else
	{
		printf("MPが足りないようだ…");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		return 1;
	}
	return 0;
}


//プレイヤー通常攻撃ダメージ
void Attack()
{
	PLAYER* player = GetPlayer();

	printf("%sの攻撃\n", player->name);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち


	//ダメージ計算
	int Damage = player->AT - E1.defense;

	if (Damage >= 0)
	{
		E1.EH -= Damage;

		printf("%sに%dダメージ\n", E1.name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち	
	}
	else
	{
		printf("しかし%sにダメージを与えられない\n", E1.name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち	

	}
}

//プレイヤー特殊攻撃
int SpAttack()
{
	PLAYER* P = GetPlayer();

	//MPが10以上あれば
	if (P->MP >= 10)
	{
		printf("%sのリダクション\n", P->name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		P->MP -= 10;

		float A = RandomFloat();	//1.5〜2の間をランダムで決定

		//ダメージ計算
		int Damage = P->AT * A - E1.defense;

		if (Damage >= 0)
		{
			E1.EH -= Damage;

			printf("%sに%dダメージ\n", E1.name, Damage);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち	
		}
		else
		{
			printf("しかし%sにダメージを与えられない\n", E1.name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち	
		}
	}
	else
	{
		printf("MPが足りないようだ…");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		return 1;
	}
	return 0;
}

//1.5〜2の間をランダムで決定
float RandomFloat()
{
	float A = rand() % 5 + 1;
	float B = ((A / 10) * 2)+1;
	return B;
}


ENEMY* GetE1()
{
	return &E1;
}
