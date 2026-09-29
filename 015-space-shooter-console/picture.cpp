/*******************************************************************************
* タイトル:		アスキーアート
* プログラム名:	Picture.cpp
* 作成者:		大槻海斗
* 作成日:		2024/01/30
********************************************************************************/
#define CONIOEX
/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include <stdio.h>		//標準入出力ヘッダー
#include <Windows.h>	//Windowsヘッダー
#include "picture.h"	//アスキーアート出力ヘッダー
#include "conioex.h"	//コンソール系ヘッダー
#include "Scene.h"


void GameClear(void)
{
	textcolor(YELLOW);

	system("cls");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　■■■　　　　　 ■　　　　 ■　　  ■　　■■■■■　　　　\n");
	printf("　　　　■　　　■　　　　■■　　　　■■　■■　　■　　　　　　　　\n");
	printf("　　　　■　　　　　　　 ■　■　　　■　■■　■　 ■■■■■　　　　\n");
	printf("　　　　■　■■■■　　■■■■　　 ■　 ■　 ■　 ■　　　　　　　　\n");
	printf("　　　　■　　■　■　 ■　  　■　 ■　　　　　■　■　　　　　　　　\n");
	printf("　　　　　■■■　■　■　　  　■　■　　　　　■　■■■■■　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　■■■　■　　　　■■■■■　　　 ■　　　 ■■■■　\n");
	printf("　　　　　　　■　　　　■　　　　■　　　　　　　■■　　　■　　　■\n");
	printf("　　　　　　　■　　　　■　　　　■■■■■　　 ■　■　　 ■　　　■\n");
	printf("　　　　　　　■　　　　■　　　　■　　　　　  ■■■■　　■■■■　\n");
	printf("　　　　　　　■　　　　■　　　　■　　　　　 ■　　　■　 ■　　■　\n");
	printf("　　　　　　　　■■■　■■■■　■■■■■  ■　　　　■　■　　　■\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("\nTHANK YOU FOR PLAYING!!\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	textcolor(BLUE);
	printf("SCORE:%06d", GetScore());
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");

	textcolor(WHITE);

	printf("Rボタンでタイトル画面へ　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("BackSpaceキーでゲーム終了　　　　　　　　　　　　　　　　　　　　　　　\n");

}

void GameOver(void)
{
	textcolor(LIGHTRED);

	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　■■■　　　　　 ■　　　　 ■　　  ■　　■■■■■■　　　　\n");
	printf("　　　　■　　　■　　　　■■　　　　■■　■■　　■　　　　　　　　　\n");
	printf("　　　　■　　　　　　　 ■　■　　　■　■■　■　 ■■■■■■　　　　\n");
	printf("　　　　■　■■■■　　■■■■　　 ■　 ■　 ■　 ■　　　　　　　　　\n");
	printf("　　　　■　　■　■　 ■　  　■　 ■　　　　　■　■　　　　　　　　　\n");
	printf("　　　　　■■■　■　■　　  　■　■　　　　　■　■■■■■■　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　■■■　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　■　　　■　■　　　■　　　■■　　　■　■■　　\n");
	printf("　　　　　　　　　　　■　　　■　 ■　　■　　 ■  　■　　■■　　　　\n");
	printf("　　　　　　　　　　　■　　　■　　■　■　　　■■■■　　■　　　　　\n");
	printf("　　　　　　　　　　　■　　　■　　 ■■　　　 ■　　　　　■　　　　　\n");
	printf("　　　　　　　　　　　　■■■　　　　■　　　　　■■■　　■　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	textcolor(BLUE);
	printf("SCORE:%06d", GetScore());
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");

	textcolor(WHITE);

	printf("Rボタンでタイトル画面へ　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("BackSpaceキーでゲーム終了　　　　　　　　　　　　　　　　　　　　　　　\n");

	textcolor(WHITE);

}

void GameTitle(void)
{	//文字色を変える
	textcolor(LIGHTCYAN);

	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　■■　　■■■　　　■　　　　■■■■　■■■■\n");
	printf("　■　　■　■　　■　 ■■　　　■　　　　 ■　　　\n");
	printf("　■　　　　■　　■　■　■　　■　　　　　■　　　\n");
	printf("　　■■　　■■■　 ■　　■　 ■　　　　　■■■■\n");
	printf("　　　　■　■　　　■■■■■　■　　　　　■　　　\n");
	printf("　■　　■　■　　 ■　　　　■　■　　　　 ■　　　\n");
	printf("　　■■　　■　　■　　　　　■　■■■■　■■■■\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　■■　　■　　■　　■■　　　　■■　　■■■■■　■■■■　■■■■ \n");
	printf("　■　　■　■　　■  ■　　■　　■　　■　　　■　　　■　　　　■　　 ■\n");
	printf("　■　　　　■　　■ ■　　　■　■　　　■　　 ■　　　■　　　　■　　 ■\n");
	printf("　　■■　　■■■■ ■　　　■　■　　　■　　 ■　　　■■■■　■■■■ \n");
	printf("　　　　■　■　　■ ■　　　■　■　　　■　　 ■　　　■　　　　■　 ■　\n");
	printf("　■　　■　■　　■　■　　■　　■　　■　　  ■　　　■　　　　■　  ■ \n");
	printf("　　■■　　■　　■　　■■　　　　■■　　　　■　　　■■■■　■　　 ■\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");

	textcolor(WHITE);

	printf("Enterキーでスタート　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
}

void CountDown(void)
{
	int CountSE;
	int StartSE;

	CountSE = opensound((char*)"ビープ音5.mp3");
	StartSE = opensound((char*)"メニューを開く4.mp3");


	textcolor(BLUE);

	system("cls");

	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　■■■■■■■■■■　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　■■■■■■■■■■　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　■■■■■■■■■■　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　■■■■■■■■■■　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　■■■■■■■■■■　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　■■■■■■■■■■　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");

	playsound(CountSE, 0);

	Sleep(1000);
	system("cls");

	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　■■■■■■■■■■　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　■■■■■■■■■■　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　■■■■■■■■■■　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　■■■■■■■■■■　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　■■　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　■■　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　■■　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　■■■■■■■■■■　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　■■■■■■■■■■　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");

	playsound(CountSE, 0);

	Sleep(1000);
	system("cls");

	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　■■■■■　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　■■■■■　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　■■　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　■■■■■■■■■■　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　■■■■■■■■■■　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");

	playsound(CountSE, 0);

	Sleep(1000);
	system("cls");

	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　■■■■■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("■■　　　■■　　　■■　　　　　　　　　　　　　　　　　　　　　　　 ■■\n");
	printf("■■　　　　　　　　■■　　　　　　　　　　　　　　　　　　　　　　　 ■■\n");
	printf("■■　　　　　　　　■■　　　　　　　　　　　　　　　 　　　　　　　　■■\n");
	printf("■■　　　　　　■■■■■■　　 ■■■　　　　　　　■■　■■■　■■■■■■\n");
	printf("　■■■■■　　■■■■■■　　■■■■■　　　　 　■■■■■■　■■■■■■\n");
	printf("　　■■■■■　　　■■　　　■■　　 ■■　　　　  ■■■　　　　　　■■\n");
	printf("　　　　　■■　　　■■　　 ■■　　　 ■■　　　　 ■■　　　　　　　■■\n");
	printf("　　　　　■■　　　■■　　 ■■　　　 ■■■　　　 ■■　　　　　　　■■\n");
	printf("　　　　　■■　　　■■　　 ■■　　■■　■■　　　■■　　　　　　　■■\n");
	printf("■■　　　■■　　　■■　　　■■■■■　　 ■■　　■■　　　　　　　■■\n");
	printf("　■■■■■　　　　■■　　　　■■■　　　   ■■　■■　　　　　　　■■\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");

	playsound(StartSE, 0);

	Sleep(900);
	system("cls");

	closesound(CountSE);
	closesound(StartSE);

}