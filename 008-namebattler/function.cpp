#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include "main.h"

//名前作成関数
void CreateName(void)
{
	PLAYER*player = GetPlayer();

	int i = 0;
	char yesno = 'y';
	//名前入力
	while (i < 1)
	{
		printf("\n名前を入力してね：");
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%s", player->name);

		printf("%sでよろしいですか？\nY/N入力：", player->name);
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%c", &yesno);

		if ((yesno == 'Y') || (yesno == 'y'))
		{
			//ループ抜け出し
			i += 1;
		}
		system("cls");
	}
}


//操作説明＆表記説明
int Explanation()
{
	system("cls");

	printf("\n操作説明\nW：上方向に移動\nA：左方向に移動\nS：下方向に移動\nD：右方向に移動\nEnter:1ターン見送り\n\n");
	printf("Q：セーブ・中断\nH：回復薬を使用\nB：聖水を使用\n\n");
	printf("マップ内表記説明\n■：壁\nＥ：敵\n□：階段\n\nEnter：この画面を閉じる");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	return 0;
}


//プレイヤーHP0判定
void PHP0(int HP)
{
	PLAYER* player = GetPlayer();

	if (HP <= 0) {

		printf("勇者%sは倒れてしまった…\n", player->name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		void GameOver();

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		//ここでプレーヤー構造体のみをファイルに書き込む


		exit(-1);
	}
}