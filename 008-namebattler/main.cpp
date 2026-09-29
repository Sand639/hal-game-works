/*******************************************************************************
* タイトル:		課題6 NAME BATTLER
* プログラム名:	メインプログラム
* 作成者:		大槻海斗
* 作成日:		2023/11/30
********************************************************************************/

//scanf のwarning防止
#define _CRT_SECURE_NO_WARNINGS

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <Windows.h>
#include<string.h>
#include<math.h>
#include <conio.h>	//Key入力処理
#include "main.h"

/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
void Opening();
void Load();
void PlayerParameters();

/*******************************************************************************
* グローバル変数
*******************************************************************************/
PLAYER player;


/*******************************************************************************
*修正点
*******************************************************************************/
//バトルプログラムのメモを綺麗にする
//MAP1.cppで作った関数を別のMAP.cppでも使えるようにする（構造体が違っていても）
// ↑プレイヤーだけでも省略できそう
//ヘッダーを分けて見やすくする



int main(void)
{
	//ランダムの初期化
	srand((unsigned)time(NULL));

/*******************************************************************************
* 変数宣言
*******************************************************************************/
	int num = 0;
	char yesno = 'y';


/*******************************************************************************
* メインプログラム
*******************************************************************************/
	PLAYER* player = GetPlayer();

	//タイトル画面表示
	title();


	//はじめから,続きからの選択肢,続きからならセーブデータをロード
	printf("1:はじめから\n2:続きから\n選択肢:");
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)scanf("%d",&num);

	//続きから
	if (num == 2)
	{
		//セーブデータの読み込み
		Load();
	}
	//初めから
	else
	{
		system("cls");

		printf("\nオープニングが始まります、スキップしますか？\n※オープニングには名前入力も含まれています\nY/N:");
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%c", &yesno);

		system("cls");

		if ((yesno == 'N') || (yesno == 'n'))
		{
			//オープニング
			Opening();
		}
		player->MAP = 1;
	}

	system("cls");

	//フロア1関数
	if (player->MAP == 1)
	{
		MAP1();
		player->MAP = 2;
	}

	//フロア2関数
	if (player->MAP == 2)
	{
		MAP2();
		player->MAP = 3;
	}

	//フロア3関数
	if (player->MAP == 3)
	{

	}


	printf("\nThank you for playing\nまだ作成途中です...\n次回に続く...");
	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	getchar();	// キー入力待ち

	/*終了*/
	return 0;
}

//プレイヤーゲット関数
PLAYER* GetPlayer()
{
	return &player;
}

//セーブデータロード
void Load()
{
	FILE* fp = NULL;

	//ファイルの読み込み
	fp = fopen("savedata.dat", "rb");
	if (fp == NULL)
	{
		printf("データファイルのオープンに失敗しました\n");
		exit(0);
	}

	PLAYER* player = GetPlayer();
	fread(player, sizeof(*player), 1, fp);	//プレイヤー構造体

	//マップ1にプレイヤーがいる
	if (player->MAP == 1)
	{
		POTION* potion = Getpotion();
		ENEMY* E1 = GetE1();
		POSITION* Ppos = GetPpos();
		POSITION* E1pos = GetE1pos();
		MAPVARIVABLE* V1 = GetMAP1();

		//読み込み
		fread(potion, sizeof(*potion), 1, fp);	//ポーション構造体
		fread(E1, sizeof(*E1), 1, fp);			//敵1構造体
		fread(Ppos, sizeof(*Ppos), 1, fp);		//プレイヤー座標
		fread(E1pos, sizeof(*E1pos), 1, fp);	//敵1座標
		fread(V1, sizeof(*V1), 1, fp);			//map1変数
	}

	if (player->MAP == 2)
	{
		POTION* potion = Getpotion();
		ENEMY* E2 = GetE2();
		ENEMY* E3 = GetE3();
		POSITION* Ppos = GetPpos2();
		POSITION* E2pos = GetE2pos();
		POSITION* E3pos = GetE3pos();
		MAP2VARIVABLE* V2 = GetMAP2();

		//読み込み
		fread(potion, sizeof(*potion), 1, fp);	//ポーション構造体
		fread(E2, sizeof(*E2), 1, fp);			//敵2構造体
		fread(E3, sizeof(*E3), 1, fp);			//敵3構造体
		fread(Ppos, sizeof(*Ppos), 1, fp);		//プレイヤー座標
		fread(E2pos, sizeof(*E2pos), 1, fp);	//敵2座標
		fread(E3pos, sizeof(*E3pos), 1, fp);	//敵3座標
		fread(V2, sizeof(*V2), 1, fp);			//map2変数

	}

	if (player->MAP == 3)
	{

	}

		printf("ロードが完了しました\nEnterKeyで開始します");

		fclose(fp);  // ファイルを閉じる

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち
}

//オープニング
void Opening()
{
	printf("\nこんにちは!あなたは...\n");	//シナリオ、ここは言葉が力になる世界、言霊世界的な始まりで

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();

	printf("まだ名前が無いんですね!\n");

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();

	printf("それならまだ希望はあるかもしれません!\n");

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();

	printf("...ﾁﾗｯ\n");

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();

	printf("もし、良ければなんですけど、、私に協力してくれないでしょうか?\n");

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();


	printf("もちろん、タダじゃありませんよ\n");

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();

	printf("協力してくださるなら、私ができることは何でもしますよ！\n");

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();

	printf("ほら、例えば...あなたをこの世界の神様にしたり、とか？\n");

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();

	printf("え、神様にはなりたくないって...え〜と、え〜と...\n");

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();

	printf("え、本当ですか！協力してくださるんですね！\n");

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();

	printf("ありがとうございます!それでは何を協力してほしいかを説明しますね！\n");

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();


	system("cls");


	printf("\nこの世界コトソルでは言葉に強さがあり、強い言葉を発することで魔法を使用することができます。\n");

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();

	printf("良い言葉は回復系,悪い言葉は攻撃系の魔法などある程度の区分はされています。\n");

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();


	printf("私たち人間の世界では、お互いが危害を加えぬように悪い言葉は極力使わないように決めていたのです。\n");

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();

	printf("しかし、一人の人間が掟を破り悪い言葉を使ってしまったのです\n");

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();

	printf("その言葉がとても強い言葉で闇を呼びだしてしまったのです\n");

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();

	printf("闇は無機物から人間、様々なものに感染していきます\n");

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();


	printf("感染してしまうと邪悪な気を帯びて目に入るもの全てを破壊しようとしてしまいます\n");

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();


	printf("そこで、あなたに協力してほしいのです！\n");

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();


	printf("闇の支配者ダークネスを倒せば、闇がなくなって感染した人は元に戻ります！\n");

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();


	printf("ぜひ闇の支配者ダークネスを倒してください!\n");

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();


	system("cls");


	printf("あっ、そうでした！あなたにはまだ名前がないんでしたね\n");

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();


	printf("この世界では名前が強さに値します！ぜひ強そうな名前を付けてくださいね！\n");

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();

	system("cls");

	//名前入力
	CreateName();

	//名前パラメータ振り分け
	PlayerParameters();

	printf("%sさん頼みました！\n健闘を祈ります!",player.name);

	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();


}

//名前からパラメータを振り分ける
void PlayerParameters()
{
	PLAYER* P = GetPlayer();
	unsigned int HP = 0;
	unsigned int MP = 0;
	unsigned int AT = 0;
	unsigned int VIT = 0;
	int length = strlen(P->name);

	for (int i = 0; i < length; i++)
	{
		HP += P->name[i];
		MP += P->name[i];
		AT += P->name[i];
		VIT += P->name[i];
	}

	P->HP = HP % 900 + 100;
	P->MP = MP % 160 + 40;
	P->AT = AT % 80 + 20;
	P->VIT = VIT % 50 + 50;

	P->MaxHP = P->HP;
	P->MaxMP = P->MP;

	printf("\n名前によってパラメータが決定しました\n\n");
	printf("HP：%d\nMP：%d\n攻撃力：%d\n防御力：%d\n", P->HP, P->MP, P->AT, P->VIT);
}
