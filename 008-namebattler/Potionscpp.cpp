#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <Windows.h>
#include "main.h"

//グローバル変数
POTION potion;


//ポーションゲット関数
POTION *Getpotion()
{
	return &potion;
}


//回復薬
int Recovery()
{

	PLAYER* P = GetPlayer();

	int con = 0;
	char yesno = 'y';

	system("cls");

	printf("回復薬を使用しますか？\nY/N入力：");
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)scanf("%c", &yesno);

	if ((yesno == 'Y') || (yesno == 'y'))
	{
		if (potion.HPplus >= 1)
		{
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
				printf("%sは回復薬を使った\n", P->name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				P->HP += 150;

				if (P->MaxHP <= P->HP)
				{
					P->HP = P->MaxHP;
				}

				printf("%sのHPは%dになった", P->name, P->HP);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				potion.HPplus -= 1;
			}

		}
		else
		{
			printf("回復薬が足りないようだ…");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			return 1;
		}

	}
	return 0;
}

int Recovery0()
{
	PLAYER* P = GetPlayer();

	if (potion.HPplus >= 1)
	{
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
			printf("%sは回復薬を使った\n", P->name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			P->HP += 150;

			if (P->MaxHP <= P->HP)
			{
				P->HP = P->MaxHP;
			}

			printf("%sのHPは%dになった", P->name, P->HP);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			potion.HPplus -= 1;
		}

	}
	else
	{
		printf("回復薬が足りないようだ…");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		return 1;
	}
	return 0;
}


//聖水
int HolyWater()
{
	PLAYER* P = GetPlayer();

	char yesno = 'y';

	system("cls");

	printf("聖水を使用しますか？\nY/N入力：");
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)scanf("%c", &yesno);

	if ((yesno == 'Y') || (yesno == 'y'))
	{
		if (potion.MPplus >= 1)
		{
			if (P->HP == P->MaxHP)
			{
				printf("MPが満タンのようだ");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				return 1;
			}
			else
			{

				printf("%sは聖水を使った\n", P->name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				P->MP += 50;

				if (P->MaxMP <= P->MP)
				{
					P->MP = P->MaxMP;
				}

				printf("%sのMPは%dになった", P->name, P->MP);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				potion.MPplus -= 1;
			}
		}
		else
		{
			printf("聖水が足りないようだ…");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			return 1;
		}
	}
	return 0;
}


int HolyWater0()
{
	PLAYER* P = GetPlayer();

	if (potion.MPplus >= 1)
	{
		if (P->HP == P->MaxHP)
		{
			printf("MPが満タンのようだ");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			return 1;
		}
		else
		{

			printf("%sは聖水を使った\n", P->name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			P->MP += 50;

			if (P->MaxMP <= P->MP)
			{
				P->MP = P->MaxMP;
			}

			printf("%sのMPは%dになった", P->name, P->MP);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			potion.MPplus -= 1;
		}
	}
	else
	{
		printf("聖水が足りないようだ…");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		return 1;
	}
	return 0;
}

