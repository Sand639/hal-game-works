#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

//プロトタイプ宣言

//選択肢
int E2Choice(int EC);		//敵
int PlayerChoice2(int PC);	//プレイヤー

//プレイヤーコマンド
int PlayerAttack2(int num);	//攻撃コマンド
void Attack2();				//通常攻撃
int SpAttack2();			//特殊攻撃
void RunAway2();			//逃げる

//敵の攻撃
void EnemyCommand(int EC);	//敵コマンド
void EnemyAttack2();		//攻撃
void EnemySpAttack2();		//特殊攻撃

//グローバル変数


//敵2戦闘処理
int E2Battle()
{
	//ポインタをゲット
	ENEMY *E =  GetE2();
	PLAYER* P = GetPlayer();
	POSITION* Epos = GetE2pos();

	if (P->SaveSwitch == 0)
	{
		system("cls");

		printf("\nポルターガイストが現れた\n");
		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("\nポルターガイストとの戦闘が始まった\nHP%d MP%d\n", P->HP, P->MP);
		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("\n\nポルターガイストは不協和音を出している\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

	}

	int EC = 0;	//敵の選択肢
	int PC = 0;	//プレイヤーの選択肢
	int con = 0;//continueするかどうか

	//戦闘プログラム
	while((E->EH >= 0) && (P->HP >= 0) && (Epos->survival == 2))
	{
		con = 0;

		//敵ディフェンス設定
		int A = (E->EH / 5) + 1;
		E->defense = 1 + rand() % A;
		//プレイヤーディフェンス設定
		P->VIT2 = 1 + rand() % P->VIT;

		//敵の選択肢
		EC = E2Choice(EC);

		if (E->ad >= 1)
		{
			E->defense += 50;
			E->ad = 0;
		}

		system("cls");


		printf("\nHP%dMP%d\n\n1攻撃\n\n2持ち物\n\n3逃げる\n\n4セーブ・中断\n\n選択肢入力：", P->HP, P->MP);
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%d", &PC);

		system("cls");

		//プレイヤー選択肢行動
		con = PlayerChoice2(PC);
		if (con == 1)
		{
			continue;
		}

		//ここから敵の行動
		if ((Epos->survival == 2) && (E->EH > 0))
		{
			EnemyCommand(EC);
		}

		//敵HP0判定
		if (E->EH <= 0)
		{
			Epos->survival = 0;
			printf("ポルターガイストは倒れた\n");

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

//敵の選択肢
int E2Choice(int EC)
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
		//回復
		EC = 3;
	}
	return EC;

}

//プレイヤー選択肢
int PlayerChoice2(int PC)
{
	int num = 0;	//選択肢
	int con = 0;	//continueするかどうか
	switch (PC)
	{
	case 1:		//攻撃　と　MP攻撃　と　魔法回復　に分岐


		printf("\n1通常攻撃\n\n2リダクション(MP10消費)\n\n3ヒール(MP10消費)\n\n4戻る\n\n選択肢入力：");
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%d", &num);

		con = PlayerAttack2(num);
		break;

	case 2:		//持ち物欄		回復薬　と　聖水　に分岐
		system("cls");

		printf("\n1回復薬\n\n2聖水\n\n3戻る\n\n選択肢:");
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%d", &num);

		con = Inventory(num);
		break;
	case 3:		//逃げる
		RunAway2();
		break;

	case 4:
		//中段セーブ
		con = Save2();
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

//プレイヤー攻撃コマンド
int PlayerAttack2(int num)
{
	int con = 0;	//continueするかしないか
	switch (num)
	{
	case 1:
		//通常攻撃
		Attack2();
		break;

	case 2:
		//特殊攻撃
		con = SpAttack2();
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

//プレイヤー通常攻撃
void Attack2()
{
	PLAYER* player = GetPlayer();
	ENEMY* E = GetE2();

	printf("%sの攻撃\n", player->name);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち


	//ダメージ計算
	int Damage = player->AT - E->defense;

	if (Damage >= 0)
	{
		E->EH -= Damage;

		printf("%sに%dダメージ\n", E->name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち	
	}
	else
	{
		printf("しかし%sにダメージを与えられない\n", E->name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち	

	}

}

//プレイヤー特殊攻撃
int SpAttack2()
{
	PLAYER* P = GetPlayer();
	ENEMY* E = GetE2();

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
		int Damage = P->AT * A - E->defense;

		if (Damage >= 0)
		{
			E->EH -= Damage;

			printf("%sに%dダメージ\n", E->name, Damage);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち	
		}
		else
		{
			printf("しかし%sにダメージを与えられない\n", E->name);

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

//回復魔法はE1BATTLE.cpp

//持ち物欄はE1BATTLE.cpp

//逃げる
void RunAway2()
{
	PLAYER* P = GetPlayer();
	ENEMY* E = GetE2();
	POSITION* Ppos = GetPpos2();
	POSITION* Epos = GetE2pos();

	printf("%sは逃げ出した\n", P->name);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	int BP = 1 + rand() % 100;
	if (BP <= E->Evasion)
	{
		Epos->x = Epos->old_x;
		Epos->y = Epos->old_y;
		Ppos->x = Ppos->old_x;
		Ppos->y = Ppos->old_y;
		Epos->survival = 1;
	}
}

//中断セーブ
int Save2()
{
	char yesno = 'y';

	PLAYER* player = GetPlayer();
	POTION* potion = Getpotion();
	ENEMY* E2 = GetE2();
	ENEMY* E3 = GetE3();
	POSITION* Ppos = GetPpos2();
	POSITION* E2pos = GetE2pos();
	POSITION* E3pos = GetE3pos();
	MAP2VARIVABLE* V2 = GetMAP2();

	player->SaveSwitch = 1;
	player->MAP = 2;

	FILE* fp = NULL;

	//ファイルの書き込み
	fp = fopen("savedata.dat", "wb");
	if (fp == NULL)
	{
		printf("データファイルのオープンに失敗しました\n");
		exit(0);
	}

	//書き込み
	fwrite(player, sizeof(*player), 1, fp);	//プレイヤー構造体
	fwrite(potion, sizeof(*potion), 1, fp);	//ポーション構造体
	fwrite(E2, sizeof(*E2), 1, fp);			//敵2構造体
	fwrite(E3, sizeof(*E3), 1, fp);			//敵3構造体
	fwrite(Ppos, sizeof(*Ppos), 1, fp);		//プレイヤー座標
	fwrite(E2pos, sizeof(*E2pos), 1, fp);	//敵2座標
	fwrite(E3pos, sizeof(*E3pos), 1, fp);	//敵3座標
	fwrite(V2, sizeof(*V2), 1, fp);			//map2変数

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

//敵の攻撃
void EnemyCommand(int EC)
{
	ENEMY* E = GetE2();

	switch (EC)
	{
	case 1:	//石礫
		printf("%sのセキレキ\n", E->name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		EnemyAttack2();

		break;

	case 2:	//サイコキネシス
		printf("%sのサイコキネシス\n", E->name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		EnemySpAttack2();
		break;

	case 3:
		printf("%sは様子を見ている\n", E->name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		break;
	}
}

//敵の攻撃
void EnemyAttack2()
{
	ENEMY* E = GetE2();
	PLAYER* player = GetPlayer();

	//ダメージ計算
	int Damage = E->EA - player->VIT2;

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
void EnemySpAttack2()
{
	ENEMY* E = GetE2();
	PLAYER* player = GetPlayer();

	float A = RandomFloat();	//1.5〜2の間をランダムで決定

	//ダメージ計算
	int Damage = E->EA * A - player->VIT2;

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
