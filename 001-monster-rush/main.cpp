/*******************************************************************************
* タイトル:		メインプログラム
* プログラム名:	main.cpp
* 作成者:		大槻海斗
* 作成日:		2023/05/29
********************************************************************************

/*******************************************************************************
* scanf のwarning防止
*******************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*******************************************************************************
* マクロ定義
*******************************************************************************/


/*******************************************************************************
* 構造体定義
*******************************************************************************/


/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/


/*******************************************************************************
* グローバル変数
*******************************************************************************/


/*******************************************************************************
 関数名:	int main( void )
 引数　:	void
 戻り値:	正常終了: int型の 0
 説明　:	メイン関数
*******************************************************************************/
int main(void)
{
	//ifとswitch
	int num;
	char yesno;

	//キャラ
	char name[256];
	int Slime;
	int Boar;
	int Goblin;
	int Ostrich;
	int Orc;
	int BTiger;
	int SoulKnight;
	int Devil;

	//攻撃力
	Slime = 5;
	Boar = 25;
	Goblin = 15;
	Ostrich = 20;
	Orc = 30;
	BTiger = 40;
	SoulKnight = 60;
	Devil = 100;

	//ヘルス
	int HP;
	int AT;
	int Damage;
	int GoodPoint;
	int DevilH;

	//定義
	HP = 300;
	AT = 100;
	GoodPoint = 0;
	DevilH = 1000;
	
	printf("\n名前を入力してね：");
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)scanf("%s", &name);

	printf("\n王様「勇者%sよ、我がフエルサ王国に魔物の大群を引き連れて魔王が攻めに来るようじゃ。」\n",&name);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("王様「そこで、勇者%sには攻めてくる魔王を返り討ちにして欲しいのじゃ。」\n",&name);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("魔王を返り討ちにしますか？\nY/N入力");
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)scanf("%c",&yesno);

	if ((yesno == 'N') || (yesno == 'n'))
	{

		printf("王様「そうか…」 \n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("王様「ワシらはお主に頼りきっていたのかもしれぬな」 \n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("王様「お主が戦わなくてもワシはお主を責めたりはしないよ…」 \n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王に王国を滅ぼされてしまった \n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		system("cls");


		printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
		printf("　　□□□　　　　　 □　　　　 □　　  □　　□□□□□□　　　　　　\n");
		printf("　□　　　□　　　　□□　　　　□□　□□　　□　　　　　　　　　　　　\n");
		printf("　□　　　　　　　 □　□　　　□　□□　□　 □□□□□□　　　　　　　\n");
		printf("　□　□□□□　　□□□□　　 □　 □　 □　 □　　　　　　　　　　　　\n");
		printf("　□　　□　□　 □　  　□　 □　　　　　□　□　　　　　　　　　　　　\n");
		printf("　　□□□　□　□　　  　□　□　　　　　□　□□□□□□　　　　　　　　\n");
		printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
		printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
		printf("　　　　　　　　　□□□　　　　　　　　　　　　　　　　　　　　　　　　　\n");
		printf("　　　　　　　　□　　　□　□　　　□　　　□□　　　□　□□　　　　\n");
		printf("　　　　　　　　□　　　□　 □　　□　　 □  　□　　□□　　　　　　　　　\n");
		printf("　　　　　　　　□　　　□　　□　□　　　□□□□　　□　　　　　　　　　　　\n");
		printf("　　　　　　　　□　　　□　　 □□　　　 □　　　　　□　　　　　　　\n");
		printf("　　　　　　　　　□□□　　　　□　　　　　□□□　　□　　　　　　　　　\n");
		printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		exit(-1);
	}

	printf("王様「勇者%sには最上級の武器と防具を授けよう。」\n",&name);
	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("%sは王様から炎の剣と鋼の鎧を受け取った。\n",&name);
	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("王様「では、勇者%sよ頼んだぞ」\n",&name);
	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	system("cls");

	//Monster Rush に置き換え
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　□　　  □　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　□□  □□　　　　　　　    □□　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　 □　□□  □　   □□    　□　　　　　□　　　□□□　　 □　□　　　　\n");
	printf("　 □　 □   □　 □　　□　　□□□　　□□□　□　　□□　 □□　　　　　\n");
	printf("　□　　  　  □　□　　□　　　  □　　　□　　□　　□□　 □　　　　　　   \n");
	printf("　□　　　　  □　　□□　　　□□　　　　□　　　□□　 □　□　　　　　　 　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　  \n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　 　□□□□　　　　                  □           　\n");
	printf("　　　　　　　　　　　　　 □　　　□　               □□   □              \n");
	printf("　　　　　　　　　　　　　 □      □　　□　  □   □       □□□          \n");
	printf("　　　　　　　　　　　　　 □□□□　    □    □   □□□   □    □        \n");
	printf("　　　　　　　　　　　　　 □　  □  　  □    □       □   □    □         \n");
	printf("　　　　　　　　 　　　　　□　  　□　　 □□□    □□     □    □      　 \n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　  　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	
	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	system("cls");

	printf("\nフエルサ王国にモンスターの大群が攻めてきた\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("モンスターの大群から王国を守ろう\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	//ラウンド１



	printf("ラウンド1\nHP%d\n\n",HP);
	
	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("スライムが現れた\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	system("cls");

	printf("\nスライムとの戦闘が始まった\nHP%d",HP);
	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("\n\nスライムは%sの様子をうかがっている\n",name);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("スライムは戦いたくなさそうにしている");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("1攻撃\n2見逃す\n選択肢入力：");
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)scanf("%d", &num);

	switch (num) {

	case 1:

		printf("%sの攻撃\n",name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		Damage = AT * 1;

		printf("スライムに%dダメージ\n",Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("スライムは倒れた\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		break;

	case 2:

		printf("スライムは%sから逃げていった\n",name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		GoodPoint++;

		break;

	default:
		printf("1,2で入力されなかったため、選択肢１が選択されました\n");


		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("%sの攻撃\n", name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		Damage = AT * 1;

		printf("スライムに%dダメージ\n", Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("スライムは倒れた\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		break;

	}

	system("cls");

	//ラウンド２



	printf("ラウンド2\nHP%d\n\n", HP);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("トツゲキイノシシが現れた\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	system("cls");

	printf("\nトツゲキイノシシとの戦闘が始まった\nHP%d", HP);
	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("1.攻撃\n2.カウンター\n3.回避\n選択肢入力：");
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)scanf("%d", &num);

	switch (num) {

	case 1:
		printf("トツゲキイノシシの突進\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち


		//戦闘ダメ計算

		Damage = Boar;


		printf("%sに%dダメージ\n", name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		HP = HP - Damage;

		printf("%sの残りHPは%dだ\n", name, HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (HP < 0) {

			printf("勇者%sは倒れてしまった…\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("GAMEOVER");	//GAMEOVER専用の画面をつくってもいいかも

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			exit(-1);
		}

		printf("%sの火炎斬り\n", name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("トツゲキイノシシに250ダメージ\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("トツゲキイノシシはマルヤキイノシシになった\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("勇者はマルヤキイノシシを食べてHP10回復した\n");

		HP = HP + 10;

		printf("%sの残りHPは%dだ\n", name, HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		break;

	case 2:

		printf("トツゲキイノシシの突進\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("%sのカウンター\n", name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("一刀両断!!\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("トツゲキイノシシに500ダメージ\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("トツゲキイノシシは倒れた\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		break;

	case 3:

		printf("トツゲキイノシシの突進\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("しかし勇者には当たらなかった\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("1火炎斬り\n2一刀両断\n選択肢入力：");
		(void)scanf("%d", &num);

		switch (num)
		{
		case 1:
			printf("%sの火炎斬り\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("トツゲキイノシシに250ダメージ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("トツゲキイノシシはマルヤキイノシシになった\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("勇者はマルヤキイノシシを食べてHP10上がった\n");

			HP = HP + 10;

			printf("%sの残りHPは%dだ\n", name, HP);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			break;

		case 2:
			printf("%sの一刀両断!!\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("トツゲキイノシシに500ダメージ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("トツゲキイノシシは倒れた\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
			break;

		default:
			printf("1,2で入力されなかったため、選択肢１が選択されました\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("%sの火炎斬り\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("トツゲキイノシシに250ダメージ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("トツゲキイノシシはマルヤキイノシシになった\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("勇者はマルヤキイノシシを食べてHP10上がった\n");

			HP = HP + 10;

			printf("%sの残りHPは%dだ\n", name, HP);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			break;
		}

		break;

	default:

		printf("1～3で入力されなかったため、選択肢１が選択されました\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("トツゲキイノシシの突進\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち


		//戦闘ダメ計算

		Damage = Boar;


		printf("%sに%dダメージ\n", name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		HP = HP - Damage;

		printf("%sの残りHPは%dだ\n", name, HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (HP < 0) {

			printf("勇者%sは倒れてしまった…\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("GAMEOVER");	//GAMEOVER専用の画面をつくってもいいかも

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			exit(-1);
		}

		printf("%sの火炎斬り\n", name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("トツゲキイノシシに250ダメージ\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("トツゲキイノシシはマルヤキイノシシになった\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("勇者はマルヤキイノシシを食べてHP10回復した\n");

		HP = HP + 10;

		printf("%sの残りHPは%dだ\n", name, HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		break;

	}

	system("cls");



	printf("魔王「この国の勇者はなかなかやるようだな…」\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("魔王「だが、我が軍はまだまだたくさんいるぞ!!」\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	//ラウンド３



	printf("ラウンド3\nHP%d\n\n", HP);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("ゴブリンが現れた\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	system("cls");

	printf("ゴブリンとの戦闘が始まった\nHP%d", HP);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

		
	printf("1攻撃\n2カウンター\n3回避\n選択肢入力：");
		
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)scanf("%d", &num);

	switch (num)
	{
	case 1:
	printf("%sの火炎斬り\n",name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("しかしゴブリンに避けられた\n");
	
		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("ゴブリンの攻撃\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		//戦闘ダメ計算

		Damage = Goblin;


		printf("%sに%dダメージ\n", name, Damage);

			// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		HP = HP - Damage;

		printf("%sの残りHPは%dだ\n", name, HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (HP < 0) {

			printf("勇者%sは倒れてしまった…\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("GAMEOVER");	//GAMEOVER専用の画面をつくってもいいかも

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			exit(-1);
		}





		printf("1カウンター\n2回避\n選択肢入力：");
		(void)scanf("%d", &num);

		switch (num) {
		case 1:
			printf("ゴブリンの攻撃\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("%sのカウンター", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("%sの一刀両断!!\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ゴブリンはこん棒で攻撃を防いだ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ゴブリンはこん棒をなくしたため逃げていった\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			break;

		case 2:
			printf("ゴブリンの攻撃\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("しかし%sには当たらなかった\n", name);


			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ゴブリンはすかさずに%sにこん棒を投げつけた", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("%sにこん棒が直撃！", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			//戦闘ダメ計算

			Damage = Goblin;


			printf("%sに%dダメージ\n", name, Damage);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			HP = HP - Damage;

			printf("%sの残りHPは%dだ\n", name, HP);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			if (HP < 0) {

				printf("勇者%sは倒れてしまった…\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("GAMEOVER");	//GAMEOVER専用の画面をつくってもいいかも

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				exit(-1);
			}

			printf("ゴブリンはこん棒をなくしたため逃げていった\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち


			break;

		default:
			printf("1,2で入力されなかったため、選択肢１が選択されました\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ゴブリンの攻撃\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("%sのカウンター", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("%sの一刀両断!!\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ゴブリンはこん棒で攻撃を防いだ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ゴブリンはこん棒をなくしたため逃げていった\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			break;

		}

		break;

	case 2:
		printf("ゴブリンの攻撃\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("%sのカウンター", name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("%sの一刀両断!!\n", name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("ゴブリンはこん棒で攻撃を防いだ\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("ゴブリンはこん棒をなくしたため逃げていった\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち
		break;

	case 3:
		printf("ゴブリンの攻撃\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("しかし%sには当たらなかった\n", name);


		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("ゴブリンはすかさずに%sにこん棒を投げつけた", name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("%sにこん棒が直撃！", name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		//戦闘ダメ計算

		Damage = Goblin;


		printf("%sに%dダメージ\n", name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		HP = HP - Damage;

		printf("%sの残りHPは%dだ\n", name, HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (HP < 0) {

			printf("勇者%sは倒れてしまった…\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("GAMEOVER");	//GAMEOVER専用の画面をつくってもいいかも

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			exit(-1);
		}

		printf("ゴブリンはこん棒をなくしたため逃げていった\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち
		break;

	default:

		printf("1～3で入力されなかったため、選択肢１が選択されました\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("%sの火炎斬り\n", name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("しかしゴブリンに避けられた\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("ゴブリンの攻撃\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		//戦闘ダメ計算

		Damage = Goblin;


		printf("%sに%dダメージ\n", name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		HP = HP - Damage;

		printf("%sの残りHPは%dだ\n", name, HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (HP < 0) {

			printf("勇者%sは倒れてしまった…\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("GAMEOVER");	//GAMEOVER専用の画面をつくってもいいかも

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			exit(-1);
		}





		printf("1カウンター\n2回避\n選択肢入力：");
		(void)scanf("%d", &num);

		switch (num) {
		case 1:
			printf("ゴブリンの攻撃\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("%sのカウンター", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("%sの一刀両断!!\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ゴブリンはこん棒で攻撃を防いだ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ゴブリンはこん棒をなくしたため逃げていった\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			break;

		case 2:
			printf("ゴブリンの攻撃\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("しかし%sには当たらなかった\n", name);


			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ゴブリンはすかさずに%sにこん棒を投げつけた", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("%sにこん棒が直撃！", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			//戦闘ダメ計算

			Damage = Goblin;


			printf("%sに%dダメージ\n", name, Damage);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			HP = HP - Damage;

			printf("%sの残りHPは%dだ\n", name, HP);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			if (HP < 0) {

				printf("勇者%sは倒れてしまった…\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("GAMEOVER");	//GAMEOVER専用の画面をつくってもいいかも

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				exit(-1);
			}

			printf("ゴブリンはこん棒をなくしたため逃げていった\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち


			break;

		default:
			printf("1,2で入力されなかったため、選択肢１が選択されました\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ゴブリンの攻撃\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("%sのカウンター", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("%sの一刀両断!!\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ゴブリンはこん棒で攻撃を防いだ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ゴブリンはこん棒をなくしたため逃げていった\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			break;

		}

		break;

		break;
		
		}

	system("cls");

	//ラウンド4



	printf("ラウンド4\nHP%d\n\n", HP);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("ダダダチョウが現れた\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	system("cls");

	printf("\nダダダチョウとの戦闘が始まった\nHP%d", HP);
	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("1.攻撃\n2.カウンター\n3.回避\n選択肢入力：");
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)scanf("%d", &num);

	switch (num)
	{
	case 1:
		printf("%sの攻撃\n",name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("しかし、走り回っているダダダチョウには当たらない\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("ダダダチョウのダッシュアタック\n");

		//戦闘ダメ計算

		Damage = Ostrich;


		printf("%sに%dダメージ\n", name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		HP = HP - Damage;

		printf("%sの残りHPは%dだ\n", name, HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (HP < 0) {

			printf("勇者%sは倒れてしまった…\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("GAMEOVER");	//GAMEOVER専用の画面をつくってもいいかも

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			exit(-1);
		}

		printf("1.カウンター\n2.回避\n選択肢入力：");
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%d", &num);

		switch (num)
		{
		case 1:

			printf("%sのカウンター\n",name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("しかし、ダダダチョウは走り回っているだけだ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ダダダチョウは走りすぎて疲れたようだ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ダダダチョウは住処に帰りたいようだ\nダダダチョウを住処にかえしますか？Y/N入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%c", &yesno);

			if ((yesno == 'Y') || (yesno == 'y'))
			{
				printf("ダダダチョウは歩いて住処に帰っていった\n");
				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				GoodPoint++;
			}
			else
			{
				printf("%sの火炎斬り\n", name);
				
				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ダダダチョウに250ダメージ\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ダダダチョウは倒れた\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

			}
		case 2:
			printf("%sの回避\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("しかし、ダダダチョウは走り回っているで攻撃してこない\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ダダダチョウは走りすぎて疲れたようだ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ダダダチョウは住処に帰りたいようだ\nダダダチョウを住処にかえしますか？Y/N入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%c", &yesno);

			if ((yesno == 'Y') || (yesno == 'y'))
			{
				printf("ダダダチョウは歩いて住処に帰っていった\n");
				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				GoodPoint++;
			}
			else
			{
				printf("%sの火炎斬り\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ダダダチョウに250ダメージ\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ダダダチョウは倒れた\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

			}
			break;
			
		default:
			printf("1,2で入力されなかったため、選択肢１が選択されました\n");


			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち


			printf("%sのカウンター\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("しかし、ダダダチョウは走り回っているだけだ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ダダダチョウは走りすぎて疲れたようだ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ダダダチョウは住処に帰りたいようだ\nダダダチョウを住処にかえしますか？Y/N入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%c", &yesno);

			if ((yesno == 'Y') || (yesno == 'y'))
			{
				printf("ダダダチョウは歩いて住処に帰っていった\n");
				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				GoodPoint++;
			}
			else
			{
				printf("%sの火炎斬り\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ダダダチョウに250ダメージ\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ダダダチョウは倒れた\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

			}

			break;

		}

		break;

	case 2:
		printf("%sのカウンター\n", name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("しかし、ダダダチョウは走り回っているだけだ\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("ダダダチョウは走りすぎて疲れたようだ\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("ダダダチョウは住処に帰りたいようだ\nダダダチョウを住処にかえしますか？Y/N入力：");
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%c", &yesno);

		if ((yesno == 'Y') || (yesno == 'y'))
		{
			printf("ダダダチョウは歩いて住処に帰っていった\n");
			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			GoodPoint++;
		}
		else
		{
			printf("%sの火炎斬り\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ダダダチョウに250ダメージ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ダダダチョウは倒れた\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

		}
		break;

	case 3:
		printf("%sの回避\n", name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("しかし、ダダダチョウは走り回っているで攻撃してこない\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("ダダダチョウは走りすぎて疲れたようだ\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("ダダダチョウは住処に帰りたいようだ\nダダダチョウを住処にかえしますか？Y/N入力：");
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%c", &yesno);

		if ((yesno == 'Y') || (yesno == 'y'))
		{
			printf("ダダダチョウは歩いて住処に帰っていった\n");
			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			GoodPoint++;
		}
		else
		{
			printf("%sの火炎斬り\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ダダダチョウに250ダメージ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ダダダチョウは倒れた\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

		}
		break;

	default:
		printf("1～3で入力されなかったため、選択肢１が選択されました\n");

		printf("%sの攻撃\n", name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("しかし、走り回っているダダダチョウには当たらない\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("ダダダチョウのダッシュアタック\n");

		//戦闘ダメ計算

		Damage = Ostrich;


		printf("%sに%dダメージ\n", name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		HP = HP - Damage;

		printf("%sの残りHPは%dだ\n", name, HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (HP < 0) {

			printf("勇者%sは倒れてしまった…\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("GAMEOVER");	//GAMEOVER専用の画面をつくってもいいかも

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			exit(-1);
		}

		printf("1.カウンター\n2.回避\n選択肢入力：");
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%d", &num);

		switch (num)
		{
		case 1:

			printf("%sのカウンター\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("しかし、ダダダチョウは走り回っているだけだ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ダダダチョウは走りすぎて疲れたようだ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ダダダチョウは住処に帰りたいようだ\nダダダチョウを住処にかえしますか？Y/N入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%c", &yesno);

			if ((yesno == 'Y') || (yesno == 'y'))
			{
				printf("ダダダチョウは歩いて住処に帰っていった\n");
				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				GoodPoint++;
			}
			else
			{
				printf("%sの火炎斬り\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ダダダチョウに250ダメージ\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ダダダチョウは倒れた\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

			}
		case 2:
			printf("%sの回避\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("しかし、ダダダチョウは走り回っているで攻撃してこない\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ダダダチョウは走りすぎて疲れたようだ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ダダダチョウは住処に帰りたいようだ\nダダダチョウを住処にかえしますか？Y/N入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%c", &yesno);

			if ((yesno == 'Y') || (yesno == 'y'))
			{
				printf("ダダダチョウは歩いて住処に帰っていった\n");
				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				GoodPoint++;
			}
			else
			{
				printf("%sの火炎斬り\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ダダダチョウに250ダメージ\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ダダダチョウは倒れた\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

			}
			break;

		default:
			printf("1,2で入力されなかったため、選択肢１が選択されました\n");


			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち


			printf("%sのカウンター\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("しかし、ダダダチョウは走り回っているだけだ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ダダダチョウは走りすぎて疲れたようだ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ダダダチョウは住処に帰りたいようだ\nダダダチョウを住処にかえしますか？Y/N入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%c", &yesno);

			if ((yesno == 'Y') || (yesno == 'y'))
			{
				printf("ダダダチョウは歩いて住処に帰っていった\n");
				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				GoodPoint++;
			}
			else
			{
				printf("%sの火炎斬り\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ダダダチョウに250ダメージ\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ダダダチョウは倒れた\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

			}

			break;

		}


		break;
	
	}	
		
	system("cls");

	//ラウンド5

	printf("魔王「…憎き勇者め!!」\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("魔王「ここからの敵はそう簡単には倒せないぞ！」\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("ラウンド5\nHP%d\n\n", HP);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("オークが現れた\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	system("cls");

	printf("\nオークとの戦闘が始まった\nHP%d", HP);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("1.攻撃\n2.カウンター\n3.回避\n選択肢入力：");
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)scanf("%d", &num);

	switch (num)
	{
	case 1:
		printf("%sの火炎斬り",name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("オークのカウンター\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("五月雨突き!!\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("5ダメージ\n");
		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち
		printf("10ダメージ");
		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち
		printf("15ダメージ");
		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		Damage = Orc;


		printf("%sに%dダメージ\n", name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		HP = HP - Damage;

		printf("%sの残りHPは%dだ\n", name, HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (HP < 0) {

			printf("勇者%sは倒れてしまった…\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("GAMEOVER");	//GAMEOVER専用の画面をつくってもいいかも

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			exit(-1);
		}

		printf("1.カウンター\n2.回避\n選択肢入力：");
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%d", &num);

		switch (num)
		{
		case 1:
			printf("オークの五月雨突き\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("%sのカウンター\n",name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("%sは槍を切り落とした\n",name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("オークは怯んでいる\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("オークは戦意喪失している\nオークを逃がしますか？Y/N入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%c", &yesno);

			if ((yesno == 'Y') || (yesno == 'y'))
			{
				printf("オークは驚きながら逃げていった\n");
				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				GoodPoint++;
			}
			else
			{
				printf("%sの火炎斬り\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("オークに250ダメージ\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("オークは倒れた\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

			}


			break;

		case 2:
			printf("オークの五月雨突き\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("勇者の回避\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("0ダメージ\n");
			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
			printf("10ダメージ");
			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
			printf("0ダメージ");
			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("一回当たってしまった\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			Damage = 10;


			printf("%sに%dダメージ\n", name, Damage);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			HP = HP - Damage;

			printf("%sの残りHPは%dだ\n", name, HP);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			if (HP < 0) {

				printf("勇者%sは倒れてしまった…\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("GAMEOVER");	//GAMEOVER専用の画面をつくってもいいかも

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				exit(-1);
			}

			printf("1.攻撃\n2.カウンター\n選択肢入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%d", &num);

			switch (num)
			{
			case 1:
				printf("%sの火炎斬り\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("オークに250ダメージ\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("オークは倒れた\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち
				break;

			case 2:
				printf("オークの五月雨突き\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("%sのカウンター\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("%sは槍を切り落とした\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("オークは怯んでいる\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("オークは戦意喪失している\nオークを逃がしますか？Y/N入力：");
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)scanf("%c", &yesno);

				if ((yesno == 'Y') || (yesno == 'y'))
				{
					printf("オークは驚きながら逃げていった\n");
					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					GoodPoint++;
				}
				else
				{
					printf("%sの火炎斬り\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("オークに250ダメージ\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("オークは倒れた\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

				}

				break;

			default:
				printf("1,2で入力されなかったため、選択肢１が選択されました\n");


				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち


				printf("%sの火炎斬り\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("オークに250ダメージ\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("オークは倒れた\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち
				break;

			}

			break;

		default:
			printf("1,2で入力されなかったため、選択肢１が選択されました\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
			printf("オークの五月雨突き\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("%sのカウンター\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("%sは槍を切り落とした\n",name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("オークは怯んでいる\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("オークは戦意喪失している\nオークを逃がしますか？Y/N入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%c", &yesno);

			if ((yesno == 'Y') || (yesno == 'y'))
			{
				printf("オークは驚きながら逃げていった\n");
				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				GoodPoint++;
			}
			else
			{
				printf("%sの火炎斬り\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("オークに250ダメージ\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("オークは倒れた\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

			}

			break;

		}

		break;

	case 2:
		printf("オークの五月雨突き\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("%sのカウンター\n", name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("%sは槍を切り落とした\n", name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("オークは怯んでいる\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("オークは戦意喪失している\nオークを逃がしますか？Y/N入力：");
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%c", &yesno);

		if ((yesno == 'Y') || (yesno == 'y'))
		{
			printf("オークは驚きながら逃げていった\n");
			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			GoodPoint++;
		}
		else
		{
			printf("%sの火炎斬り\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("オークに250ダメージ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("オークは倒れた\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

		}
		break;

	case 3:
		printf("オークの五月雨突き\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("勇者の回避\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("0ダメージ\n");
		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち
		printf("10ダメージ");
		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち
		printf("0ダメージ");
		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("一回当たってしまった\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		Damage = 10;


		printf("%sに%dダメージ\n", name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		HP = HP - Damage;

		printf("%sの残りHPは%dだ\n", name, HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (HP < 0) {

			printf("勇者%sは倒れてしまった…\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("GAMEOVER");	//GAMEOVER専用の画面をつくってもいいかも

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			exit(-1);
		}

		printf("1.攻撃\n2.カウンター\n選択肢入力：");
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%d", &num);

		switch (num)
		{
		case 1:
			printf("%sの火炎斬り\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("オークに250ダメージ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("オークは倒れた\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
			break;

		case 2:
			printf("オークの五月雨突き\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("%sのカウンター\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("%sは槍を切り落とした\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("オークは怯んでいる\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("オークは戦意喪失している\nオークを逃がしますか？Y/N入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%c", &yesno);

			if ((yesno == 'Y') || (yesno == 'y'))
			{
				printf("オークは驚きながら逃げていった\n");
				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				GoodPoint++;
			}
			else
			{
				printf("%sの火炎斬り\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("オークに250ダメージ\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("オークは倒れた\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

			}

			break;

		default:
			printf("1,2で入力されなかったため、選択肢１が選択されました\n");


			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち


			printf("%sの火炎斬り\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("オークに250ダメージ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("オークは倒れた\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
			break;

		}

		break;


	default:
		printf("1～3で入力されなかったため、選択肢１が選択されました\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち
		printf("%sの火炎斬り", name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("オークのカウンター\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("五月雨突き!!\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("5ダメージ\n");
		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち
		printf("10ダメージ");
		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち
		printf("15ダメージ");
		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		Damage = Orc;


		printf("%sに%dダメージ\n", name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		HP = HP - Damage;

		printf("%sの残りHPは%dだ\n", name, HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (HP < 0) {

			printf("勇者%sは倒れてしまった…\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("GAMEOVER");	//GAMEOVER専用の画面をつくってもいいかも

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			exit(-1);
		}

		printf("1.カウンター\n2.回避\n選択肢入力：");
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%d", &num);

		switch (num)
		{
		case 1:
			printf("オークの五月雨突き\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("%sのカウンター\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("%sは槍を切り落とした\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("オークは怯んでいる\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("オークは戦意喪失している\nオークを逃がしますか？Y/N入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%c", &yesno);

			if ((yesno == 'Y') || (yesno == 'y'))
			{
				printf("オークは驚きながら逃げていった\n");
				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				GoodPoint++;
			}
			else
			{
				printf("%sの火炎斬り\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("オークに250ダメージ\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("オークは倒れた\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

			}


			break;

		case 2:
			printf("オークの五月雨突き\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("勇者の回避\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("0ダメージ\n");
			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
			printf("10ダメージ");
			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
			printf("0ダメージ");
			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("一回当たってしまった\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			Damage = 10;


			printf("%sに%dダメージ\n", name, Damage);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			HP = HP - Damage;

			printf("%sの残りHPは%dだ\n", name, HP);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			if (HP < 0) {

				printf("勇者%sは倒れてしまった…\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("GAMEOVER");	//GAMEOVER専用の画面をつくってもいいかも

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				exit(-1);
			}

			printf("1.攻撃\n2.カウンター\n選択肢入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%d", &num);

			switch (num)
			{
			case 1:
				printf("%sの火炎斬り\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("オークに250ダメージ\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("オークは倒れた\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち
				break;

			case 2:
				printf("オークの五月雨突き\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("%sのカウンター\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("%sは槍を切り落とした\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("オークは怯んでいる\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("オークは戦意喪失している\nオークを逃がしますか？Y/N入力：");
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)scanf("%c", &yesno);

				if ((yesno == 'Y') || (yesno == 'y'))
				{
					printf("オークは驚きながら逃げていった\n");
					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					GoodPoint++;
				}
				else
				{
					printf("%sの火炎斬り\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("オークに250ダメージ\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("オークは倒れた\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

				}

				break;

			default:
				printf("1,2で入力されなかったため、選択肢１が選択されました\n");


				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち


				printf("%sの火炎斬り\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("オークに250ダメージ\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("オークは倒れた\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち
				break;

			}

			break;

		default:
			printf("1,2で入力されなかったため、選択肢１が選択されました\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
			printf("オークの五月雨突き\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("%sのカウンター\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("%sは槍を切り落とした\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("オークは怯んでいる\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("オークは戦意喪失している\nオークを逃がしますか？Y/N入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%c", &yesno);

			if ((yesno == 'Y') || (yesno == 'y'))
			{
				printf("オークは驚きながら逃げていった\n");
				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				GoodPoint++;
			}
			else
			{
				printf("%sの火炎斬り\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("オークに250ダメージ\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("オークは倒れた\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

			}

			break;

		}

		break;
	}

	//system("cls");

	//printf("ラウンド6\nHP%d\n\n", HP);

	//// キー入力待ち
	//rewind(stdin);		// ←キー入力情報をクリアする
	//(void)getchar();	// キー入力待ち

	//printf("ブラックタイガーが現れた\n");

	//// キー入力待ち
	//rewind(stdin);		// ←キー入力情報をクリアする
	//(void)getchar();	// キー入力待ち

	//system("cls");

	//printf("\nブラックタイガーとの戦闘が始まった\nHP%d", HP);

	//// キー入力待ち
	//rewind(stdin);		// ←キー入力情報をクリアする
	//(void)getchar();	// キー入力待ち

	//printf("1.攻撃\n2.カウンター\n3.回避\n選択肢入力：");
	//rewind(stdin);		// ←キー入力情報をクリアする
	//(void)scanf("%d", &num);

	//switch(num)
	//{

	//}

	system("cls");

	//ラウンド魔王

	printf("魔王「よくも我が軍を痛めつけてくれたな！！」\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("魔王「勇者よ。この私、魔王[サタン]と勝負だ!!」\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("最終決戦!!\nHP%d\n\n", HP);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("魔王サタンが現れた\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	system("cls");

	printf("\n魔王サタンとの戦闘が始まった\nHP%d", HP);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("魔王の残りHPは%dだ\n", DevilH);

	//一回目

	printf("魔王の魔法攻撃\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("魔王のレストインピース\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("範囲型の魔法のようだ\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("1.攻撃\n2.カウンター\n3.回避\n選択肢入力：");
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)scanf("%d", &num);

	switch (num)
	{
	case 1:
		printf("魔王のレストインピース\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("%sの火炎斬り\n",name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王に250ダメージ\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		DevilH = DevilH - 250;

		printf("魔王の残りHPは%dだ\n",DevilH);


		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち


		//魔王のHP
		if (DevilH<=0)
		{
			printf("\nサタン「グハッ!!」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("サタン「そんなはずは…」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("サタン「たった一人の人間に…」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("勇者は魔王を倒した!!\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			//gameclearの画面

			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　□□□　　　　　 □　　　　 □　　  □　　□□□□□□　　　　　　\n");
			printf("　□　　　□　　　　□□　　　　□□　□□　　□　　　　　　　　　　　　\n");
			printf("　□　　　　　　　 □　□　　　□　□□　□　 □□□□□□　　　　　　　\n");
			printf("　□　□□□□　　□□□□　　 □　 □　 □　 □　　　　　　　　　　　　\n");
			printf("　□　　□　□　 □　  　□　 □　　　　　□　□　　　　　　　　　　　　\n");
			printf("　　□□□　□　□　　  　□　□　　　　　□　□□□□□□　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　□□□　□　　　　□□□□□□　　　 □　　　 □□□□　　　　　　\n");
			printf("　　　　□　　　　□　　　　□　　　　　　　　□□　　　□　　　□　　　　　\n");
			printf("　　　　□　　　　□　　　　□□□□□□　　 □　□　　 □　　　□　　　　\n");
			printf("　　　　□　　　　□　　　　□　　　　　　  □□□□　　□□□□　　　　　\n");
			printf("　　　　□　　　　□　　　　□　　　　　　 □　　　□　 □　　□　　　　　\n");
			printf("　　　　　□□□　□□□□　□□□□□□  □　　　　□　□　　　□　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}



		break;

	case 2:

		printf("魔王のレストインピース\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔法攻撃はカウンターできない！\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王「眠りに堕ちろ」\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち



		//勇者ダメージ計算
		Damage = Devil;

		printf("%sに%dダメージ\n", name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		HP = HP - Damage;

		printf("%sの残りHPは%dだ\n", name, HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (HP < 0) {

			printf("勇者%sは倒れてしまった…\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			system("cls");

			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　□□□　　　　　 □　　　　 □　　  □　　□□□□□□　　　　　　\n");
			printf("　□　　　□　　　　□□　　　　□□　□□　　□　　　　　　　　　　　　\n");
			printf("　□　　　　　　　 □　□　　　□　□□　□　 □□□□□□　　　　　　　\n");
			printf("　□　□□□□　　□□□□　　 □　 □　 □　 □　　　　　　　　　　　　\n");
			printf("　□　　□　□　 □　  　□　 □　　　　　□　□　　　　　　　　　　　　\n");
			printf("　　□□□　□　□　　  　□　□　　　　　□　□□□□□□　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　□　　　□　　　□□　　　□　□□　　　　\n");
			printf("　　　　　　　　□　　　□　 □　　□　　 □  　□　　□□　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　□　□　　　□□□□　　□　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　 □□　　　 □　　　　　□　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　□　　　　　□□□　　□　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			exit(-1);
		}
		//勇者ダメージ計算

		break;

	case 3:

		printf("魔王のレストインピース\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("範囲型魔法は避けきれない\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王「眠りに堕ちろ」\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		//勇者ダメージ計算
		Damage = Devil;

		printf("%sに%dダメージ\n", name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		HP = HP - Damage;

		printf("%sの残りHPは%dだ\n", name, HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (HP < 0) {

			printf("勇者%sは倒れてしまった…\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			system("cls");

			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　□□□　　　　　 □　　　　 □　　  □　　□□□□□□　　　　　　\n");
			printf("　□　　　□　　　　□□　　　　□□　□□　　□　　　　　　　　　　　　\n");
			printf("　□　　　　　　　 □　□　　　□　□□　□　 □□□□□□　　　　　　　\n");
			printf("　□　□□□□　　□□□□　　 □　 □　 □　 □　　　　　　　　　　　　\n");
			printf("　□　　□　□　 □　  　□　 □　　　　　□　□　　　　　　　　　　　　\n");
			printf("　　□□□　□　□　　  　□　□　　　　　□　□□□□□□　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　□　　　□　　　□□　　　□　□□　　　　\n");
			printf("　　　　　　　　□　　　□　 □　　□　　 □  　□　　□□　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　□　□　　　□□□□　　□　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　 □□　　　 □　　　　　□　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　□　　　　　□□□　　□　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			exit(-1);
		}
		//勇者ダメージ計算
		break;

	default:
		printf("魔王のレストインピース\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("%sはコマンド入力に失敗した\n",name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王「眠りに堕ちろ」\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		//勇者ダメージ計算
		Damage = Devil;

		printf("%sに%dダメージ\n", name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		HP = HP - Damage;

		printf("%sの残りHPは%dだ\n", name, HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (HP < 0) {

			printf("勇者%sは倒れてしまった…\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			system("cls");

			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　□□□　　　　　 □　　　　 □　　  □　　□□□□□□　　　　　　\n");
			printf("　□　　　□　　　　□□　　　　□□　□□　　□　　　　　　　　　　　　\n");
			printf("　□　　　　　　　 □　□　　　□　□□　□　 □□□□□□　　　　　　　\n");
			printf("　□　□□□□　　□□□□　　 □　 □　 □　 □　　　　　　　　　　　　\n");
			printf("　□　　□　□　 □　  　□　 □　　　　　□　□　　　　　　　　　　　　\n");
			printf("　　□□□　□　□　　  　□　□　　　　　□　□□□□□□　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　□　　　□　　　□□　　　□　□□　　　　\n");
			printf("　　　　　　　　□　　　□　 □　　□　　 □  　□　　□□　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　□　□　　　□□□□　　□　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　 □□　　　 □　　　　　□　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　□　　　　　□□□　　□　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			exit(-1);
		}
		//勇者ダメージ計算

		break;

	}

	system("cls");


	//ダメージによって変わる会話
	if (DevilH == 750) {

		printf("魔王「中々やるようだな！」\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王「だが、まだ始まったばかりだ！」\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

	}
	else {

		printf("魔王「我が魔法を受けて立っていられるとは…」\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王「本当に人間か？」\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

	}
	

	//二回目

	system("cls");

	printf("魔王の残りHPは%dだ\n", DevilH);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち


	printf("\n魔王サタンは次の攻撃の準備をしている\nHP%d", HP);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("魔王の魔法攻撃\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("魔王のシャドウエッジ\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("一点集中魔法のようだ\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("1.攻撃\n2.カウンター\n3.回避\n選択肢入力：");
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)scanf("%d", &num);

	switch (num)
	{
	case 1:
		printf("%sの火炎斬り\n",name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王のシャドウエッジ\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("刃と刃がぶつかり合って攻撃が相殺された\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち
		break;

	case 2:
		printf("魔王のシャドウエッジ\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔法攻撃はカウンターできない！\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王「闇の刃に切り裂かれろ！」\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		//勇者ダメージ計算
		Damage = Devil;

		printf("%sに%dダメージ\n", name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		HP = HP - Damage;

		printf("%sの残りHPは%dだ\n", name, HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (HP < 0) {

			printf("勇者%sは倒れてしまった…\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			system("cls");

			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　□□□　　　　　 □　　　　 □　　  □　　□□□□□□　　　　　　\n");
			printf("　□　　　□　　　　□□　　　　□□　□□　　□　　　　　　　　　　　　\n");
			printf("　□　　　　　　　 □　□　　　□　□□　□　 □□□□□□　　　　　　　\n");
			printf("　□　□□□□　　□□□□　　 □　 □　 □　 □　　　　　　　　　　　　\n");
			printf("　□　　□　□　 □　  　□　 □　　　　　□　□　　　　　　　　　　　　\n");
			printf("　　□□□　□　□　　  　□　□　　　　　□　□□□□□□　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　□　　　□　　　□□　　　□　□□　　　　\n");
			printf("　　　　　　　　□　　　□　 □　　□　　 □  　□　　□□　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　□　□　　　□□□□　　□　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　 □□　　　 □　　　　　□　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　□　　　　　□□□　　□　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			exit(-1);
		}
		//勇者ダメージ計算



		break;

	case 3:

		printf("魔王のシャドウエッジ\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("しかし、%sには当たらなかった\n",name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("1攻撃\n2カウンター\n選択肢入力：");
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%d", &num);

		switch (num)
		{
		case 1:
			printf("%sの火炎斬り\n",name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("魔王に250ダメージ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
			break;

			DevilH = DevilH - 250;

			printf("魔王の残りHPは%dだ\n", DevilH);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			//魔王のHP
			if (DevilH <= 0)
			{
				printf("\nサタン「グハッ!!」\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("サタン「そんなはずは…」\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("サタン「たった一人の人間に…」\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("勇者は魔王を倒した!!\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				//gameclearの画面

				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
				printf("　　□□□　　　　　 □　　　　 □　　  □　　□□□□□□　　　　　　\n");
				printf("　□　　　□　　　　□□　　　　□□　□□　　□　　　　　　　　　　　　\n");
				printf("　□　　　　　　　 □　□　　　□　□□　□　 □□□□□□　　　　　　　\n");
				printf("　□　□□□□　　□□□□　　 □　 □　 □　 □　　　　　　　　　　　　\n");
				printf("　□　　□　□　 □　  　□　 □　　　　　□　□　　　　　　　　　　　　\n");
				printf("　　□□□　□　□　　  　□　□　　　　　□　□□□□□□　　　　　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
				printf("　　　　　□□□　□　　　　□□□□□□　　　 □　　　 □□□□　　　　　　\n");
				printf("　　　　□　　　　□　　　　□　　　　　　　　□□　　　□　　　□　　　　　\n");
				printf("　　　　□　　　　□　　　　□□□□□□　　 □　□　　 □　　　□　　　　\n");
				printf("　　　　□　　　　□　　　　□　　　　　　  □□□□　　□□□□　　　　　\n");
				printf("　　　　□　　　　□　　　　□　　　　　　 □　　　□　 □　　□　　　　　\n");
				printf("　　　　　□□□　□□□□　□□□□□□  □　　　　□　□　　　□　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち
			}

		case 2:
			printf("魔王は慌てて刀を振り下ろす\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("%sの一刀両断!!\n",name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("魔王に500ダメージ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			DevilH = DevilH - 500;

			printf("魔王の残りHPは%dだ\n", DevilH);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			//魔王のHP
			if (DevilH <= 0)
			{
				printf("\nサタン「グハッ!!」\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("サタン「そんなはずは…」\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("サタン「たった一人の人間に…」\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("勇者は魔王を倒した!!\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				//gameclearの画面

				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
				printf("　　□□□　　　　　 □　　　　 □　　  □　　□□□□□□　　　　　　\n");
				printf("　□　　　□　　　　□□　　　　□□　□□　　□　　　　　　　　　　　　\n");
				printf("　□　　　　　　　 □　□　　　□　□□　□　 □□□□□□　　　　　　　\n");
				printf("　□　□□□□　　□□□□　　 □　 □　 □　 □　　　　　　　　　　　　\n");
				printf("　□　　□　□　 □　  　□　 □　　　　　□　□　　　　　　　　　　　　\n");
				printf("　　□□□　□　□　　  　□　□　　　　　□　□□□□□□　　　　　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
				printf("　　　　　□□□　□　　　　□□□□□□　　　 □　　　 □□□□　　　　　　\n");
				printf("　　　　□　　　　□　　　　□　　　　　　　　□□　　　□　　　□　　　　　\n");
				printf("　　　　□　　　　□　　　　□□□□□□　　 □　□　　 □　　　□　　　　\n");
				printf("　　　　□　　　　□　　　　□　　　　　　  □□□□　　□□□□　　　　　\n");
				printf("　　　　□　　　　□　　　　□　　　　　　 □　　　□　 □　　□　　　　　\n");
				printf("　　　　　□□□　□□□□　□□□□□□  □　　　　□　□　　　□　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち
			}

			break;

		default:
			printf("%sはコマンド入力に失敗した\n",name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("魔王は体制を立て直した\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
			break;
		}

		break;

	default:
		printf("%sはコマンド入力に失敗した\n",name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王のシャドウエッジ\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王「闇の刃に切り裂かれろ！」\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		//勇者ダメージ計算
		Damage = Devil;

		printf("%sに%dダメージ\n", name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		HP = HP - Damage;

		printf("%sの残りHPは%dだ\n", name, HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (HP < 0) {

			printf("勇者%sは倒れてしまった…\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			system("cls");

			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　□□□　　　　　 □　　　　 □　　  □　　□□□□□□　　　　　　\n");
			printf("　□　　　□　　　　□□　　　　□□　□□　　□　　　　　　　　　　　　\n");
			printf("　□　　　　　　　 □　□　　　□　□□　□　 □□□□□□　　　　　　　\n");
			printf("　□　□□□□　　□□□□　　 □　 □　 □　 □　　　　　　　　　　　　\n");
			printf("　□　　□　□　 □　  　□　 □　　　　　□　□　　　　　　　　　　　　\n");
			printf("　　□□□　□　□　　  　□　□　　　　　□　□□□□□□　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　□　　　□　　　□□　　　□　□□　　　　\n");
			printf("　　　　　　　　□　　　□　 □　　□　　 □  　□　　□□　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　□　□　　　□□□□　　□　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　 □□　　　 □　　　　　□　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　□　　　　　□□□　　□　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			exit(-1);
		}
		//勇者ダメージ計算



		break;

	}

	system("cls");

	//HPによって変わる会話
	switch(DevilH) {

	case 1000:
		printf("魔王「なっ…なぜ立っていられる?!」\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		break;

	case 750:
		printf("魔王「中々の強さ…だが負けたりはしない！」\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		break;

	case 500:

		printf("魔王「勇者%s…これほどとは…」\n",name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		break;

	case 250:

		printf("魔王「…」\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王は弱っている\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		break;

	default:

		break;

	}
	 
	system("cls");

	//三回目

	printf("魔王の残りHPは%dだ\n", DevilH);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("\n魔王サタンは次の攻撃の準備をしている\nHP%d", HP);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("魔王の攻撃\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("魔王のジャガーノート\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("魔王は刀を構えている\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("1.攻撃\n2.カウンター\n3.回避\n選択肢入力：");
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)scanf("%d", &num);

	switch (num)
	{
	case 1:
		printf("魔王のジャガーノート\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("%sの火炎斬り\n",name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王の攻撃のほうが速い\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王「我が力は止められぬ!!」\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		//勇者ダメージ計算
		Damage = Devil;

		printf("%sに%dダメージ\n", name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		HP = HP - Damage;

		printf("%sの残りHPは%dだ\n", name, HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (HP < 0) {

			printf("勇者%sは倒れてしまった…\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			system("cls");

			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　□□□　　　　　 □　　　　 □　　  □　　□□□□□□　　　　　　\n");
			printf("　□　　　□　　　　□□　　　　□□　□□　　□　　　　　　　　　　　　\n");
			printf("　□　　　　　　　 □　□　　　□　□□　□　 □□□□□□　　　　　　　\n");
			printf("　□　□□□□　　□□□□　　 □　 □　 □　 □　　　　　　　　　　　　\n");
			printf("　□　　□　□　 □　  　□　 □　　　　　□　□　　　　　　　　　　　　\n");
			printf("　　□□□　□　□　　  　□　□　　　　　□　□□□□□□　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　□　　　□　　　□□　　　□　□□　　　　\n");
			printf("　　　　　　　　□　　　□　 □　　□　　 □  　□　　□□　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　□　□　　　□□□□　　□　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　 □□　　　 □　　　　　□　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　□　　　　　□□□　　□　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			exit(-1);
		}
		//勇者ダメージ計算

		break;

	case 2:

		printf("魔王のジャガーノート\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("目にも止まらぬ速さだ\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("%sは魔王の刀を弾いた\n",name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王はバランスを崩している\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("1.火炎斬り\n2.一刀両断\n選択肢入力：");
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%d", &num);

		switch (num)
		{
		case 1:
			printf("%sの火炎斬り\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("魔王に250ダメージ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			DevilH = DevilH - 250;

			printf("魔王の残りHPは%dだ\n", DevilH);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			//魔王のHP
			if (DevilH <= 0)
			{
				printf("\nサタン「グハッ!!」\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("サタン「そんなはずは…」\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("サタン「たった一人の人間に…」\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("勇者は魔王を倒した!!\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				//gameclearの画面

				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
				printf("　　□□□　　　　　 □　　　　 □　　  □　　□□□□□□　　　　　　\n");
				printf("　□　　　□　　　　□□　　　　□□　□□　　□　　　　　　　　　　　　\n");
				printf("　□　　　　　　　 □　□　　　□　□□　□　 □□□□□□　　　　　　　\n");
				printf("　□　□□□□　　□□□□　　 □　 □　 □　 □　　　　　　　　　　　　\n");
				printf("　□　　□　□　 □　  　□　 □　　　　　□　□　　　　　　　　　　　　\n");
				printf("　　□□□　□　□　　  　□　□　　　　　□　□□□□□□　　　　　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
				printf("　　　　　□□□　□　　　　□□□□□□　　　 □　　　 □□□□　　　　　　\n");
				printf("　　　　□　　　　□　　　　□　　　　　　　　□□　　　□　　　□　　　　　\n");
				printf("　　　　□　　　　□　　　　□□□□□□　　 □　□　　 □　　　□　　　　\n");
				printf("　　　　□　　　　□　　　　□　　　　　　  □□□□　　□□□□　　　　　\n");
				printf("　　　　□　　　　□　　　　□　　　　　　 □　　　□　 □　　□　　　　　\n");
				printf("　　　　　□□□　□□□□　□□□□□□  □　　　　□　□　　　□　　　　\n");
				printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち
			}

			break;

		case 2:
			printf("%sの一刀両断\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("魔王は慌てて体制を整える\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("魔王に攻撃を防がれた\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			break;

		default:
			printf("%sはコマンド入力に失敗した\n",name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("魔王は体制を立て直した\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
			break;

		}

		break;

	case 3:
		printf("魔王のジャガーノート\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("目にも止まらぬ速さだ\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("%sは避けられない\n", name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王「我が力は止められぬ!!」\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		//勇者ダメージ計算
		Damage = Devil;

		printf("%sに%dダメージ\n", name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		HP = HP - Damage;

		printf("%sの残りHPは%dだ\n", name, HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (HP < 0) {

			printf("勇者%sは倒れてしまった…\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			system("cls");

			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　□□□　　　　　 □　　　　 □　　  □　　□□□□□□　　　　　　\n");
			printf("　□　　　□　　　　□□　　　　□□　□□　　□　　　　　　　　　　　　\n");
			printf("　□　　　　　　　 □　□　　　□　□□　□　 □□□□□□　　　　　　　\n");
			printf("　□　□□□□　　□□□□　　 □　 □　 □　 □　　　　　　　　　　　　\n");
			printf("　□　　□　□　 □　  　□　 □　　　　　□　□　　　　　　　　　　　　\n");
			printf("　　□□□　□　□　　  　□　□　　　　　□　□□□□□□　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　□　　　□　　　□□　　　□　□□　　　　\n");
			printf("　　　　　　　　□　　　□　 □　　□　　 □  　□　　□□　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　□　□　　　□□□□　　□　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　 □□　　　 □　　　　　□　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　□　　　　　□□□　　□　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			exit(-1);
		}
		//勇者ダメージ計算

		break;

	default:
		printf("%sはコマンド入力に失敗した\n",name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王のジャガーノート\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王「我が力は止められぬ!!」\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		//勇者ダメージ計算
		Damage = Devil;

		printf("%sに%dダメージ\n", name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		HP = HP - Damage;

		printf("%sの残りHPは%dだ\n", name, HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (HP < 0) {

			printf("勇者%sは倒れてしまった…\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			system("cls");

			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　□□□　　　　　 □　　　　 □　　  □　　□□□□□□　　　　　　\n");
			printf("　□　　　□　　　　□□　　　　□□　□□　　□　　　　　　　　　　　　\n");
			printf("　□　　　　　　　 □　□　　　□　□□　□　 □□□□□□　　　　　　　\n");
			printf("　□　□□□□　　□□□□　　 □　 □　 □　 □　　　　　　　　　　　　\n");
			printf("　□　　□　□　 □　  　□　 □　　　　　□　□　　　　　　　　　　　　\n");
			printf("　　□□□　□　□　　  　□　□　　　　　□　□□□□□□　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　□　　　□　　　□□　　　□　□□　　　　\n");
			printf("　　　　　　　　□　　　□　 □　　□　　 □  　□　　□□　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　□　□　　　□□□□　　□　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　 □□　　　 □　　　　　□　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　□　　　　　□□□　　□　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			exit(-1);
		}
		//勇者ダメージ計算

		break;

	}

	system("cls");

	//四回目

	printf("魔王「…」\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("魔王「勇者%s。ここで終わらせてやる!!」\n",name);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	system("cls");

	printf("魔王の残りHPは%dだ\n", DevilH);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("\n魔王サタンは次の攻撃の準備をしている\nHP%d", HP);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("魔王の魔法攻撃\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("魔王のカタストロフィ\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("範囲型の魔法のようだ\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("1.火炎斬り\n2.一刀両断\n3.カウンター\n選択肢入力：");
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("魔王のカタストロフィ\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("%sの火炎斬り\n",name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王に250ダメージ\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王は魔法をうてなかった\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		DevilH = DevilH - 250;

		printf("魔王の残りHPは%dだ\n", DevilH);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		//魔王のHP
		if (DevilH <= 0)
		{
			printf("\nサタン「グハッ!!」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("サタン「そんなはずは…」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("サタン「たった一人の人間に…」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("勇者は魔王を倒した!!\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			//gameclearの画面

			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　□□□　　　　　 □　　　　 □　　  □　　□□□□□□　　　　　　\n");
			printf("　□　　　□　　　　□□　　　　□□　□□　　□　　　　　　　　　　　　\n");
			printf("　□　　　　　　　 □　□　　　□　□□　□　 □□□□□□　　　　　　　\n");
			printf("　□　□□□□　　□□□□　　 □　 □　 □　 □　　　　　　　　　　　　\n");
			printf("　□　　□　□　 □　  　□　 □　　　　　□　□　　　　　　　　　　　　\n");
			printf("　　□□□　□　□　　  　□　□　　　　　□　□□□□□□　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　□□□　□　　　　□□□□□□　　　 □　　　 □□□□　　　　　　\n");
			printf("　　　　□　　　　□　　　　□　　　　　　　　□□　　　□　　　□　　　　　\n");
			printf("　　　　□　　　　□　　　　□□□□□□　　 □　□　　 □　　　□　　　　\n");
			printf("　　　　□　　　　□　　　　□　　　　　　  □□□□　　□□□□　　　　　\n");
			printf("　　　　□　　　　□　　　　□　　　　　　 □　　　□　 □　　□　　　　　\n");
			printf("　　　　　□□□　□□□□　□□□□□□  □　　　　□　□　　　□　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}

		break;

	case 2:
		printf("魔王のカタストロフィ\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("%sの一刀両断\n", name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王の攻撃のほうが速かった\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王「今こそ破滅の時!!」\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		//勇者ダメージ計算
		Damage = Devil;

		printf("%sに%dダメージ\n", name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		HP = HP - Damage;

		printf("%sの残りHPは%dだ\n", name, HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (HP < 0) {

			printf("勇者%sは倒れてしまった…\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			system("cls");

			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　□□□　　　　　 □　　　　 □　　  □　　□□□□□□　　　　　　\n");
			printf("　□　　　□　　　　□□　　　　□□　□□　　□　　　　　　　　　　　　\n");
			printf("　□　　　　　　　 □　□　　　□　□□　□　 □□□□□□　　　　　　　\n");
			printf("　□　□□□□　　□□□□　　 □　 □　 □　 □　　　　　　　　　　　　\n");
			printf("　□　　□　□　 □　  　□　 □　　　　　□　□　　　　　　　　　　　　\n");
			printf("　　□□□　□　□　　  　□　□　　　　　□　□□□□□□　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　□　　　□　　　□□　　　□　□□　　　　\n");
			printf("　　　　　　　　□　　　□　 □　　□　　 □  　□　　□□　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　□　□　　　□□□□　　□　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　 □□　　　 □　　　　　□　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　□　　　　　□□□　　□　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			exit(-1);
		}
		//勇者ダメージ計算

		break;

	case 3:
		printf("魔王のカタストロフィ\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔法攻撃はカウンターできない！\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王「今こそ破滅の時!!」\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		//勇者ダメージ計算
		Damage = Devil;

		printf("%sに%dダメージ\n", name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		HP = HP - Damage;

		printf("%sの残りHPは%dだ\n", name, HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (HP < 0) {

			printf("勇者%sは倒れてしまった…\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			system("cls");

			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　□□□　　　　　 □　　　　 □　　  □　　□□□□□□　　　　　　\n");
			printf("　□　　　□　　　　□□　　　　□□　□□　　□　　　　　　　　　　　　\n");
			printf("　□　　　　　　　 □　□　　　□　□□　□　 □□□□□□　　　　　　　\n");
			printf("　□　□□□□　　□□□□　　 □　 □　 □　 □　　　　　　　　　　　　\n");
			printf("　□　　□　□　 □　  　□　 □　　　　　□　□　　　　　　　　　　　　\n");
			printf("　　□□□　□　□　　  　□　□　　　　　□　□□□□□□　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　□　　　□　　　□□　　　□　□□　　　　\n");
			printf("　　　　　　　　□　　　□　 □　　□　　 □  　□　　□□　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　□　□　　　□□□□　　□　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　 □□　　　 □　　　　　□　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　□　　　　　□□□　　□　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			exit(-1);
		}
		//勇者ダメージ計算

		break;

	default:
		printf("%sはコマンド入力に失敗した\n",name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王のカタストロフィ\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王「今こそ破滅の時!!」\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		//勇者ダメージ計算
		Damage = Devil;

		printf("%sに%dダメージ\n", name, Damage);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		HP = HP - Damage;

		printf("%sの残りHPは%dだ\n", name, HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (HP < 0) {

			printf("勇者%sは倒れてしまった…\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			system("cls");

			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　□□□　　　　　 □　　　　 □　　  □　　□□□□□□　　　　　　\n");
			printf("　□　　　□　　　　□□　　　　□□　□□　　□　　　　　　　　　　　　\n");
			printf("　□　　　　　　　 □　□　　　□　□□　□　 □□□□□□　　　　　　　\n");
			printf("　□　□□□□　　□□□□　　 □　 □　 □　 □　　　　　　　　　　　　\n");
			printf("　□　　□　□　 □　  　□　 □　　　　　□　□　　　　　　　　　　　　\n");
			printf("　　□□□　□　□　　  　□　□　　　　　□　□□□□□□　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　□　　　□　　　□□　　　□　□□　　　　\n");
			printf("　　　　　　　　□　　　□　 □　　□　　 □  　□　　□□　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　□　□　　　□□□□　　□　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　 □□　　　 □　　　　　□　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　□　　　　　□□□　　□　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			exit(-1);
		}
		//勇者ダメージ計算

		break;

	}

	//五回目

	system("cls");

	printf("魔王「勇者%s。ここまで互角に戦えること誉めてやろう」\n",name);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("魔王「我が全力を放つ!!」\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	system("cls");

	printf("魔王の残りHPは%dだ\n", DevilH);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("\n魔王サタンは滅びの呪文の準備をしている\nHP%d", HP);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("魔王のシャットダウン\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("滅びの呪文だ！\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("ここで決めるしかない\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("1.火炎斬り\n2.一刀両断\n\n選択肢入力：");
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("%sの火炎斬り\n",name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王に250ダメージ\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		//魔王のHP
		DevilH = DevilH - 250;

		printf("魔王の残りHPは%dだ\n", DevilH);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (DevilH <= 0)
		{
			printf("\nサタン「グハッ!!」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("サタン「そんなはずは…」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("サタン「たった一人の人間に…」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("勇者は魔王を倒した!!\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			//gameclearの画面

			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　□□□　　　　　 □　　　　 □　　  □　　□□□□□□　　　　　　\n");
			printf("　□　　　□　　　　□□　　　　□□　□□　　□　　　　　　　　　　　　\n");
			printf("　□　　　　　　　 □　□　　　□　□□　□　 □□□□□□　　　　　　　\n");
			printf("　□　□□□□　　□□□□　　 □　 □　 □　 □　　　　　　　　　　　　\n");
			printf("　□　　□　□　 □　  　□　 □　　　　　□　□　　　　　　　　　　　　\n");
			printf("　　□□□　□　□　　  　□　□　　　　　□　□□□□□□　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　□□□　□　　　　□□□□□□　　　 □　　　 □□□□　　　　　　\n");
			printf("　　　　□　　　　□　　　　□　　　　　　　　□□　　　□　　　□　　　　　\n");
			printf("　　　　□　　　　□　　　　□□□□□□　　 □　□　　 □　　　□　　　　\n");
			printf("　　　　□　　　　□　　　　□　　　　　　  □□□□　　□□□□　　　　　\n");
			printf("　　　　□　　　　□　　　　□　　　　　　 □　　　□　 □　　□　　　　　\n");
			printf("　　　　　□□□　□□□□　□□□□□□  □　　　　□　□　　　□　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			exit(-1);
		}
		break;

	case 2:
		printf("%sの一刀両断\n", name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王に500ダメージ\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		//魔王のHP
		DevilH = DevilH - 500;

		printf("魔王の残りHPは%dだ\n", DevilH);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (DevilH <= 0)
		{
			printf("\nサタン「グハッ!!」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("サタン「そんなはずは…」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("サタン「たった一人の人間に…」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("勇者は魔王を倒した!!\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			//gameclearの画面

			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　□□□　　　　　 □　　　　 □　　  □　　□□□□□□　　　　　　\n");
			printf("　□　　　□　　　　□□　　　　□□　□□　　□　　　　　　　　　　　　\n");
			printf("　□　　　　　　　 □　□　　　□　□□　□　 □□□□□□　　　　　　　\n");
			printf("　□　□□□□　　□□□□　　 □　 □　 □　 □　　　　　　　　　　　　\n");
			printf("　□　　□　□　 □　  　□　 □　　　　　□　□　　　　　　　　　　　　\n");
			printf("　　□□□　□　□　　  　□　□　　　　　□　□□□□□□　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　□□□　□　　　　□□□□□□　　　 □　　　 □□□□　　　　　　\n");
			printf("　　　　□　　　　□　　　　□　　　　　　　　□□　　　□　　　□　　　　　\n");
			printf("　　　　□　　　　□　　　　□□□□□□　　 □　□　　 □　　　□　　　　\n");
			printf("　　　　□　　　　□　　　　□　　　　　　  □□□□　　□□□□　　　　　\n");
			printf("　　　　□　　　　□　　　　□　　　　　　 □　　　□　 □　　□　　　　　\n");
			printf("　　　　　□□□　□□□□　□□□□□□  □　　　　□　□　　　□　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}
		break;

	default:
		printf("%sはコマンド入力に失敗した\n",name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("魔王「中々強かったぞ勇者%sよ」\n",name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち


		printf("魔王「シャットダウン!!」\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		if (HP < 0) {

			printf("勇者%sは倒れてしまった…\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			system("cls");

			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　□□□　　　　　 □　　　　 □　　  □　　□□□□□□　　　　　　\n");
			printf("　□　　　□　　　　□□　　　　□□　□□　　□　　　　　　　　　　　　\n");
			printf("　□　　　　　　　 □　□　　　□　□□　□　 □□□□□□　　　　　　　\n");
			printf("　□　□□□□　　□□□□　　 □　 □　 □　 □　　　　　　　　　　　　\n");
			printf("　□　　□　□　 □　  　□　 □　　　　　□　□　　　　　　　　　　　　\n");
			printf("　　□□□　□　□　　  　□　□　　　　　□　□□□□□□　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　　　　　　　　　　　　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　□　　　□　　　□□　　　□　□□　　　　\n");
			printf("　　　　　　　　□　　　□　 □　　□　　 □  　□　　□□　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　□　□　　　□□□□　　□　　　　　　　　　　　\n");
			printf("　　　　　　　　□　　　□　　 □□　　　 □　　　　　□　　　　　　　\n");
			printf("　　　　　　　　　□□□　　　　□　　　　　□□□　　□　　　　　　　　　\n");
			printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			exit(-1);
		}
		//勇者ダメージ計算

		break;

	}

	system("cls");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("魔王「中々強かったぞ勇者%sよ」\n", name);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち


	printf("魔王「シャットダウン!!」\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

		printf("勇者%sは倒れてしまった…\n", name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		system("cls");

		printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
		printf("　　□□□　　　　　 □　　　　 □　　  □　　□□□□□□　　　　　　\n");
		printf("　□　　　□　　　　□□　　　　□□　□□　　□　　　　　　　　　　　　\n");
		printf("　□　　　　　　　 □　□　　　□　□□　□　 □□□□□□　　　　　　　\n");
		printf("　□　□□□□　　□□□□　　 □　 □　 □　 □　　　　　　　　　　　　\n");
		printf("　□　　□　□　 □　  　□　 □　　　　　□　□　　　　　　　　　　　　\n");
		printf("　　□□□　□　□　　  　□　□　　　　　□　□□□□□□　　　　　　　　\n");
		printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
		printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
		printf("　　　　　　　　　□□□　　　　　　　　　　　　　　　　　　　　　　　　　\n");
		printf("　　　　　　　　□　　　□　□　　　□　　　□□　　　□　□□　　　　\n");
		printf("　　　　　　　　□　　　□　 □　　□　　 □  　□　　□□　　　　　　　　　\n");
		printf("　　　　　　　　□　　　□　　□　□　　　□□□□　　□　　　　　　　　　　　\n");
		printf("　　　　　　　　□　　　□　　 □□　　　 □　　　　　□　　　　　　　\n");
		printf("　　　　　　　　　□□□　　　　□　　　　　□□□　　□　　　　　　　　　\n");
		printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		exit(-1);


	
// キー入力待ち
rewind(stdin);		// ←キー入力情報をクリアする
(void)getchar();	// キー入力待ち

return 0;
}