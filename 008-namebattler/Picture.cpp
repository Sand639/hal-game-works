#include <stdio.h>
#include <Windows.h>
#include "main.h"

void title(void)
{
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　□　　　□　　　　□　　　　 □　　　□　　□□□□□　　　　　　　\n");
	printf("　□□　　□　　　 □□　　　　□□　□□　　□　　　　　　　　　　　\n");
	printf("　□ □　 □　　　□　□　　　□　□□　□　 □□□□□　　　　　　　\n");
	printf("　□　 □ □　 　□□□□　　 □　 □　 □　 □　　　　　　　　　　　\n");
	printf("　□　  □□　　□　　　□　 □　　　　　□　□　　　　　　　　　　　\n");
	printf("　□　　  □ 　□　　　　□　□　　　　　□　□□□□□　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　□□□　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　□　 □　　  □　　□□□□□　□□□□□　□　　　　□□□　□□□　　\n");
	printf("　　□   □　　 □□　　　 □　　　　　□　　　□　　　　□　　　□　　□　\n");
	printf("　　□□□　　 □　□　　　□　　　　　□　　　□　　　　□□□　□　　□　\n");
	printf("　　□　 □　 □□□□ 　　□　　　　　□　　　□　　　　□　　　□□□　　\n");
	printf("　　□   □　□　 　 □　　□　　　　　□　　　□　　　　□　　　□　□　　\n");
	printf("　　□□□　□　　　　□　 □　　　　　□　　　□□□□　□□□　□　　□　\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("Enter：次へ進む\n");
	printf("\n");
	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();
	system("cls");
}

void GameClear(void)
{
	system("cls");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　□□□　　　　　 □　　　　 □　　  □　　□□□□□　　　　　　　　\n");
	printf("　□　　　□　　　　□□　　　　□□　□□　　□　　　　　　　　　　　　\n");
	printf("　□　　　　　　　 □　□　　　□　□□　□　 □□□□□　　　　　　　　\n");
	printf("　□　□□□□　　□□□□　　 □　 □　 □　 □　　　　　　　　　　　　\n");
	printf("　□　　□　□　 □　  　□　 □　　　　　□　□　　　　　　　　　　　　\n");
	printf("　　□□□　□　□　　  　□　□　　　　　□　□□□□□　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　□□□　□　　　　□□□□□　　　 □　　　 □□□□　　　　\n");
	printf("　　　　□　　　　□　　　　□　　　　　　　□□　　　□　　　□　　　\n");
	printf("　　　　□　　　　□　　　　□□□□□　　 □　□　　 □　　　□　　　\n");
	printf("　　　　□　　　　□　　　　□　　　　　  □□□□　　□□□□　　　　\n");
	printf("　　　　□　　　　□　　　　□　　　　　 □　　　□　 □　　□　　　　\n");
	printf("　　　　　□□□　□□□□　□□□□□  □　　　　□　□　　　□　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("\n\n\nTHANK YOU FOR PLAYING!!\n");
}

void GameOver(void)
{
	PLAYER* player = GetPlayer();

	system("cls");

	printf("勇者%sは倒れてしまった…\n", player->name);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　□□□　　　　　 □　　　　 □　　  □　　□□□□□□　　　　　　\n");
	printf("　□　　　□　　　　□□　　　　□□　□□　　□　　　　　　　　　　　\n");
	printf("　□　　　　　　　 □　□　　　□　□□　□　 □□□□□□　　　　　　\n");
	printf("　□　□□□□　　□□□□　　 □　 □　 □　 □　　　　　　　　　　　\n");
	printf("　□　　□　□　 □　  　□　 □　　　　　□　□　　　　　　　　　　　\n");
	printf("　　□□□　□　□　　  　□　□　　　　　□　□□□□□□　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　□□□　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　□　　　□　□　　　□　　　□□　　　□　□□　　　　\n");
	printf("　　　　　　　　□　　　□　 □　　□　　 □  　□　　□□　　　　　　\n");
	printf("　　　　　　　　□　　　□　　□　□　　　□□□□　　□　　　　　　　\n");
	printf("　　　　　　　　□　　　□　　 □□　　　 □　　　　　□　　　　　　　\n");
	printf("　　　　　　　　　□□□　　　　□　　　　　□□□　　□　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	exit(-1);
}
