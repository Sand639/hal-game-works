/*******************************************************************************
* タイトル:		メインプログラム
* プログラム名:	main.cpp
* 作成者:		大槻海斗
* 作成日:		2023/06/20
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
#include <time.h>

/*******************************************************************************
* マクロ定義
*******************************************************************************/


/*******************************************************************************
* 構造体定義
*******************************************************************************/


/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
void choice(void);
void title(void);
void GameOver(void);
void GameClear(void);


/*******************************************************************************
* グローバル変数
*******************************************************************************/


/*******************************************************************************
 関数名:	int main( void )
 引数　:	void
 戻り値:	正常終了: int型の 0
 説明　:	メイン関数
*******************************************************************************/
int main( void )
{	
	/*
	ゴブリン戦でたまに	
	スローエラー
	ハンドルエラー	
	になります
	　
	stadio.hにとばされるので原因がわからないです
	*/

/*******************************************************************************
* 乱数
*******************************************************************************/

	//ランダムの初期化	(これは起動時に1回しか行わない）
	srand((unsigned)time(NULL));

	//コピペ用
	
	//int defense = 1 + rand() % 100;
			
	//キャラごとに適当な範囲で

/*******************************************************************************
* 変数
*******************************************************************************/

	//選択肢
	int num;
	int i = 0;

	//キャラ攻撃力
	char name[256];
	int Slime = 5;			//スライム
	int Boar = 25;			//トツゲキイノシシ
	int Goblin = 20;		//ゴブリン
	int BTiger = 40;		//ブラックタイガー
	int SoulKnight = 50;	//ソウルナイト
	int Blast = 100;			//ライトニングズガドーン
	int Devil = 200;		//魔王

	//キャラ体力
	int SlimeH = 15;		//スライム
	int BoarH = 30;			//トツゲキイノシシ
	int GoblinH = 50;		//ゴブリン
	int BTigerH = 500;		//ブラックタイガー
	int SoulKnightH = 250;	//ソウルナイト
	int BlastH = 1000;		//ライトニングズガドーン
	int DevilH = 1000;		//魔王

	//自分のパラメータ
	int HP = 1000;			//体力
	int AT = 0;				//攻撃力
	int VIT = 0;			//防御力
	int Damage;				//ダメ計算
	int Point = 0;			//なんか分岐
	int ad = 0;				//優勢かどうか

	//防具（HP強化)
	int IronArmor =500;
	int SteelArmor = 2000;

	//武器攻撃力
	int IronSword = 10;
	int clubA = 50;
	int Katana = 50;
	int SteelSword = 100;

	//盾防御力
	int IronShield = 10;
	int SteelShield = 100;

	//ループ数
	int loop = 0;
	int loopA = 0;

	//変数
	int A = 0;


	//防御力
	/*
	int IronArmor = 10;
	int SteelArmor = 30;
	int Vit2 = 0;
	*/
	
	/*
	時間あったら鎧を防御力に置き換え
	HP = HP - Damage-Vit2;
	*/

/*******************************************************************************
* プロローグ
*******************************************************************************/

	//とりあえずタイトル
	title();

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	system("cls");


	printf("\n名前を入力してね：");
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)scanf("%s", &name);

	system("cls");

	printf("\n王様「勇者%sよ、先日の魔王討伐ご苦労であった…」\n",name);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("王様「しかし…どうやら魔王が命を取り留めていたようじゃ。」\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("王様「最近、この王国の近くの洞窟から魔物がたくさん目撃されたようじゃ。」\n");
	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("王様「そこで、勇者%sには洞窟に行って魔王にとどめを刺してほしいのじゃ。」\n",name);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	choice();

	system("cls");

	printf("\n勇者%sよ、恩に着るぞ\n", name);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち
	
	printf("本当は資金を使って支援をしたいのじゃが、先日の魔王による被害で街が壊れてしまい\nそのための復興に多くの資金を使ってしまったのじゃ。\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	/*
	時間あったら鎧を防御力に置き換え
	HP = HP - Damage-Vit2;
	*/
	printf("こんな物しかないのだが、お主に鉄の剣と鉄の盾、鉄の鎧を授けよう。\n剣は攻撃力、盾はカウンター防御、鎧はHP強化の効果があるぞ\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("%sは王様から鉄の剣、鉄の盾、鉄の鎧を受け取った。\n", name);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	AT += IronSword;
	VIT += IronShield;
	HP +=IronArmor;

	printf("場所はこもれび森をこえたところにあるカナリア洞窟。\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("そこからモンスターたちがあふれかえっているようじゃ。\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("王様「では、勇者%sよ頼んだぞ」\n",name);
	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("%sはこもれび森に向かった\n", name);
	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	system("cls");

/*******************************************************************************
* ここから戦闘
*******************************************************************************/

	printf("\nどうやらこもれび森にまでモンスターが来ているようだ\n");
	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("スライムが現れた\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	system("cls");

	//こもれび森入口

	printf("\nスライムとの戦闘が始まった\nHP%d", HP);
	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("\n\nスライムは攻撃の準備をしている\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	
	
/*******************************************************************************
* スライム戦
*******************************************************************************/
	

	ad = 0;
	while (SlimeH >= 0) {
		//switchの中にrand入れるとエラーになる

		A = (SlimeH / 5)+1;

		int defense = 1 + rand() % A;

		if (ad > 0)
		{
			defense -= 10;
		}

		printf("1攻撃\n2回避\n3カウンター\n選択肢入力：");
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%d", &num);

		system("cls");

		switch (num) 
		{
		case 1:

			printf("%sの攻撃\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			//ダメージ計算
			Damage = AT - defense;

			if (Damage >= 0) {
				SlimeH -= Damage;

				printf("スライムに%dダメージ\n", Damage);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち	
			}

			//敵HP0判定
			if (SlimeH <= 0) 
			{
				printf("スライムは倒れた\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				break;
			}

			printf("スライムの体当たり\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			//戦闘ダメ計算
			Damage = Slime;


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

				GameOver();

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				exit(-1);
			}

			break;

		case 2:
			printf("%sの回避\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("スライムの体当たり\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("しかし、%sには当たらなかった\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("スライムは周りを見渡してる\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			ad++;

			break;

		case 3:
			printf("%sのカウンター\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("スライムの体当たり\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち


			//戦闘ダメ計算
			Damage = Slime-VIT;

			//勇者
			if (Damage >= 0) {
				HP -= Damage;

				printf("%sに%dダメージ\n", name, Damage);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち	

				printf("%sの残りHPは%dだ\n", name, HP);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

			}
			else
			{
				printf("%sにダメージを与えられなかった\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち	
			}
			

			if (HP < 0) {

				printf("勇者%sは倒れてしまった…\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				GameOver();

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				exit(-1);
			}

			printf("%sの居合斬り\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			//ダメージ計算
			Damage = AT*2 - defense;

			if (Damage >= 0) {
				SlimeH -= Damage;

				printf("スライムに%dダメージ\n", Damage);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち	
			}

			//敵HP0判定
			if (SlimeH <= 0)
			{
				printf("スライムは倒れた\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				break;
			}

			break;

		default:

			printf("選択肢の入力方式が間違っています。\n1～3で入力してください。\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			break;
		}
		system("cls");

		if (SlimeH >= 0) {
			printf("\n\nスライムは攻撃の準備をしている\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}

		loop++;
	}
	loopA += loop;

	system("cls");

	printf("\n%sはこもれび森に入っていった\n", name);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("この先で魔物の気配がする…\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	loop = 0;

	while (loop == 1)
	{
		printf("このまま進みますか？\n１：はい\n２：迂回してカナリア洞窟に向かう\n選択肢入力：");
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%d", &num);

		system("cls");

		switch (num)
		{
		case 1:

			printf("\n%sはこのまま進むことにした\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			Point++;
			loop = 1;
			break;

		case 2:

			printf("\n%sは迂回してカナリア洞窟に向かった\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			loop = 1;

			break;

		default:

			printf("選択肢の入力方式が間違っています。\n1～2で入力してください。\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち


			break;
		}
	}

/*******************************************************************************
* トツゲキイノシシ戦
*******************************************************************************/
	
	if (Point == 1)
	{

		printf("刀を咥えたトツゲキイノシシが現れた\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		system("cls");

		//こもれび森中央

		printf("\nトツゲキイノシシとの戦闘が始まった\nHP%d", HP);
		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("\n\nトツゲキイノシシはこちらに向かってきてる\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		A = 0;
		loop = 1;
		ad = 0;
		while (BoarH >= 0) {

			A = (BoarH / 5)+1;
			
			int defense = 1 + rand() % A;
			int Ran = 1 + rand() % 100;

			if (ad > 0)
			{
				defense -= 10;
			}
			else if (ad == -1)
			{
				Boar += 10;

				ad = 0;
			}

			if (loop%3 == 0)
			{
				printf("トツゲキイノシシは怒り狂っている\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				Boar += 10;

				printf("トツゲキイノシシの攻撃力は10上がった\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち
			}
			else
			{
				printf("トツゲキイノシシは%sをロックオンしている\n",name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち
			}



			printf("1攻撃\n2回避\n3カウンター\n選択肢入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%d", &num);

			system("cls");

			switch (num)
			{
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

					GameOver();

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					exit(-1);
				}


				printf("%sの攻撃\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				//ダメージ計算
				Damage = AT - defense;

				if (Damage >= 0) {
					BoarH -= Damage;

					printf("トツゲキイノシシに%dダメージ\n", Damage);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	
				}

				//敵HP0判定
				if (BoarH <= 0)
				{
					printf("トツゲキイノシシは倒れた\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					break;
				}

				break;
			case 2:
				printf("トツゲキイノシシの突進\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("%sの回避\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち


				printf("しかし、%sは避けられない\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

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

					GameOver();

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					exit(-1);
				}

				if (Ran <= 30)
				{
					printf("%sは怯んでしまった\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					ad--;
				}

				break;
			case 3:
				printf("%sのカウンター\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("トツゲキイノシシの突進\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				//戦闘ダメ計算  カウンター
				Damage = Boar - VIT;

				//勇者
				if (Damage >= 0) {
					HP -= Damage;

					printf("%sに%dダメージ\n", name, Damage);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	

					printf("%sの残りHPは%dだ\n", name, HP);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

				}
				else
				{
					printf("%sにダメージを与えられなかった\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	
				}


				if (HP < 0) {

					printf("勇者%sは倒れてしまった…\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					GameOver();

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					exit(-1);
				}

				printf("%sの一刀両断\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				//ダメージ計算
				Damage = AT * 2 - defense;

				if (Damage >= 0) {
					BoarH -= Damage;

					printf("トツゲキイノシシに%dダメージ\n", Damage);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	
				}

				//敵HP0判定
				if (BoarH <= 0)
				{
					printf("トツゲキイノシシは倒れた\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					break;
				}

				break;

			default:

				printf("選択肢の入力方式が間違っています。\n１～３で入力してください。\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				break;
			}

			loop++;

			system("cls");

		}

		printf("%sはトツゲキイノシシの咥えていた刀を手に入れた\n", name);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		AT = Katana;
	}
	loopA += loop;


	printf("\n%sはカナリア洞窟に向かっていった\n", name);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

/*******************************************************************************
*	ゴブリン戦
*******************************************************************************/

	A = 0;
	int club = 1;
	ad = 0;
	if (Point == 0)
	{
		printf("ガサッ、ガサッ\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("ガサガサと物音がしている\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		printf("\n１：走って進む\n２：音を立てないように進む\n３：身を固める\n選択肢入力：");
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%d", &num);

		system("cls");

		switch (num)
		{
		case 1:

			printf("\n%sは走ってこもれび森を抜けることにした\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ズバッ!!\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("後ろから矢で射貫かれた\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			//戦闘ダメ計算
			Damage = Goblin*2;


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

				GameOver();

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				exit(-1);
			}


			break;

		case 2:

			printf("%sは音を立てないようにしてこもれび森を抜けることにした\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ガキーン!!\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ゴブリンの攻撃を盾で防いだ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			//戦闘ダメ計算
			Damage = Goblin - VIT;

			//勇者
			if (Damage >= 0) {
				HP -= Damage;

				printf("%sに%dダメージ\n", name, Damage);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち	

				printf("%sの残りHPは%dだ\n", name, HP);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

			}
			else
			{
				printf("%sにダメージを与えられなかった\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち	
			}
			if (HP < 0) {

				printf("勇者%sは倒れてしまった…\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				GameOver();

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				exit(-1);
			}

			break;
		case 3:
			printf("\n%sは身を固めて、様子を見ることにした\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ガサガサ!!\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("どうやらゴブリンがいるようだ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			ad++;

			break;
		default:

			printf("選択肢の入力方式が間違っています。\n１～３で入力してください。\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち


			break;
		}

		printf("ゴブリンが現れた\n");

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		system("cls");

		printf("ゴブリンとの戦闘が始まった\nHP%d", HP);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち

		loop = 1;
		while (GoblinH >= 0) {

			A = (GoblinH / 5)+1;

			int defense = 1 + rand() % A;
			int Ran = 1 + rand() % 100;

			if (ad > 0)
			{
				defense -= 10;
			}
			else if (ad == -1)
			{
				Goblin += 10;

				ad = 0;
			}

			if (loop%4 == 0)
			{
				printf("ゴブリンは%sの弱点を見極めた\n",name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				Goblin += 50;

				printf("ゴブリンの攻撃力は50上がった\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

			}
			else
			{
				printf("ゴブリンは%sを観察している\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち
			}



			printf("1攻撃\n2回避\n3カウンター\n選択肢入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%d", &num);

			system("cls");

			switch (num)
			{
			case 1:


				if (club == 1)
				{
					printf("%sの攻撃\n", name);

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

					//勇者が受けたダメージ
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

						GameOver();

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						exit(-1);
					}

					if (Ran < 10)
					{
						printf("ゴブリンは何かをつかんだ\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						Goblin += 10;

						printf("ゴブリンの攻撃力が上がった\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち
					}

				}
				else
				{
					printf("%sの攻撃\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち


					//敵が受けたダメージ
					Damage = AT - defense;

					if (Damage >= 0) {
						GoblinH -= Damage;

						printf("ゴブリンに%dダメージ\n", Damage);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち	
					}

					//敵HP0判定
					if (GoblinH <= 0)
					{
						printf("ゴブリンは倒れた\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						break;
					}

					printf("ゴブリンの弓矢攻撃\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					//勇者が受けたダメージ
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

						GameOver();

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						exit(-1);
					}

				}

				break;
			case 2:

				printf("%sの回避", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち
				
				printf("ゴブリンの攻撃\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("しかし%sには当たらなかった\n", name);


				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				if (club == 1)
				{
					printf("ゴブリンはすかさずに%sにこん棒を投げつけた", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("%sにこん棒が直撃！", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち


					//勇者が受けたダメージ
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

						GameOver();

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						exit(-1);
					}

					club--;

				}
				else
				{
					printf("ゴブリンは弓に矢を装填している\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

						//2回目でダメージ入れないとスローエラー回避

						printf("%sのクイックアタック", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						//敵が受けたダメージ
						Damage = AT / 3;

						if (Damage >= 0) {
							GoblinH -= Damage;

							printf("ゴブリンに%dダメージ\n", Damage);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち	
						}

						//敵HP0判定
						if (GoblinH <= 0)
						{
							printf("ゴブリンは倒れた\n");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							break;
						}
					ad++;
				}

				break;
			case 3:

				printf("%sのカウンター", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ゴブリンの攻撃\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				//勇者が受けたダメージ  カウンターしたあとの攻撃
				Damage = Goblin - VIT;

				//勇者
				if (Damage >= 0) {
					HP -= Damage;

					printf("%sに%dダメージ\n", name, Damage);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	

					printf("%sの残りHPは%dだ\n", name, HP);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

				}
				else
				{
					printf("%sにダメージを与えられなかった\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	
				}


				if (HP < 0) {

					printf("勇者%sは倒れてしまった…\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					GameOver();

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					exit(-1);
				}

				printf("%sの居合斬り\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				if (club == 0)
				{

					//ダメージ計算
					Damage = AT * 2 - defense;

					if (Damage >= 0) {
						GoblinH -= Damage;

						printf("ゴブリンに%dダメージ\n", Damage);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち	
					}

					//敵HP0判定
					if (GoblinH <= 0)
					{
						printf("ゴブリンは倒れた\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						break;
					}
				}
				else 
				{
					printf("ゴブリンはこん棒で攻撃を防いだ\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("ゴブリンはこん棒を失った\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					club--;
					
				}

				break;

			default:

				printf("選択肢の入力方式が間違っています。\n１～３で入力してください。\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				break;
			}

			loop++;

			system("cls");

		}

			printf("%sはゴブリンのこん棒を見つけた\n",name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			AT = clubA;

	}
	loopA += loop;


/*******************************************************************************
*	カナリア洞窟前		ソウルナイト戦
*******************************************************************************/

	system("cls");

	printf("\nどうやらカナリア洞窟に着いたようだ\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("\nカナリア洞窟の前に魔物が立ちふさがっている\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("ソウルナイト「私はソウルナイト!!魔王様の命令で、この先に魔物以外の種族は通させない！」\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("ソウルナイトが現れた\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	system("cls");

	//こもれび森中央

	printf("\nソウルナイトとの戦闘が始まった\nHP%d", HP);
	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	Point = 0;
	i = 0;
	A = 0;
	loop = 1;
	ad = 0;
	while (SoulKnightH >= 0) {

		A = (SoulKnightH / 5) + 1;

		int defense = 1 + rand() % A;
		int Ran = 1 + rand() % 100;

		if (ad > 0)
		{
			defense -= 20;
		}
		else if (ad == -1)
		{
			SoulKnight += 20;

			ad = 0;
		}

		//3の倍数時のみ発動
		if (loop%3 == 0)
		{
			printf("ソウルナイトのビルドアップ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			SoulKnight += 20;

			printf("ソウルナイトの攻撃力は20上がった\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

		}
		else if (i == 1)
		{
			printf("ソウルナイトは剣を構えている\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}
		else if (SoulKnight >= 100)
		{
			printf("ソウルナイト「時は満ちた」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("ソウルナイトは剣を構えている\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち


			i = 1;
		}
		else
		{
			printf("ソウルナイトは盾を構えている\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}


		if (i == 0)
		{
			printf("1攻撃\n2回避\n3カウンター\n4無視して洞窟の中に入る\n選択肢入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%d", &num);

			system("cls");

			switch (num)
			{
			case 1:

				printf("%sの攻撃\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ソウルナイトの防御\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				//敵が受けたダメージ
				Damage = AT - (defense * 2);

				if (Damage >= 0) {
					SoulKnightH -= Damage;

					printf("ソウルナイトに%dダメージ\n", Damage);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	
				}
				else
				{
					printf("ソウルナイトにダメージを与えられなかった\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	

					printf("ソウルナイト「無意味な攻撃!!このまま行けば魔王様の復活は目前!!」\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	

				}

				//敵HP0判定
				if (SoulKnightH <= 0)
				{
					printf("ソウルナイトは倒れた\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("ソウルナイト「時間はかせげた…」\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					break;
				}

				break;
			case 2:

				printf("%sの回避\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("しかしソウルナイトは攻撃してこない\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ソウルナイト「私の使命は時間をかせぐこと」\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				break;
			case 3:

				printf("%sのカウンター\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("しかしソウルナイトは攻撃してこない\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ソウルナイト「私の使命は時間をかせぐこと」\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				break;
			case 4:
				printf("%sはソウルナイトを無視して洞窟に入ることにした\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ソウルナイト「この先には行かせない!!」\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ソウルナイト「どうしてもというのならこの私を倒してからにするがいい」\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				i = 1;

				break;
			default:

				printf("選択肢の入力方式が間違っています。\n１～４で入力してください。\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				break;
			}

			loop++;

			system("cls");
		}
		else if(i==1)
		{
			printf("1攻撃\n2回避\n3カウンター\n選択肢入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%d", &num);

			system("cls");

			switch (num)
			{
			case 1:

				printf("%sの攻撃\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				//敵が受けたダメージ
				Damage = AT - defense ;

				if (Damage >= 0) {
					SoulKnightH -= Damage;

					printf("ソウルナイトに%dダメージ\n", Damage);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	
				}
				else
				{
					printf("ソウルナイトにダメージを与えられなかった\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

				}
				//敵HP0判定
				if (SoulKnightH <= 0)
				{
					printf("ソウルナイトは倒れた\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("ソウルナイト「時間はかせげた…」\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					break;
				}

				printf("ソウルナイトのソウルブレイク\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				//勇者が受けたダメージ
				Damage = SoulKnight;


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

					GameOver();

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					exit(-1);
				}

				break;
			case 2:

				printf("%sの回避\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ソウルナイトのソウルブレイク\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				if (Ran > 30)
				{
					printf("しかし%sには当たらない\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("ソウルナイトはバランスを崩している\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					ad++;
				}
				else
				{
					printf("%sは避けきれない\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("ソウルナイトのソウルブレイク\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					//勇者が受けたダメージ
					Damage = SoulKnight;


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

						GameOver();

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						exit(-1);
					}

					ad--;
				}
				
				break;
			case 3:

				printf("%sのカウンター\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				if (Ran < 50 && Point == 0)
				{
					printf("ソウルナイトの甲冑割り\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち



					//勇者が受けたダメージ  カウンターしたあとの攻撃
					Damage = SoulKnight*2 - VIT;

					if (Damage >= 0) {
						HP -= Damage;

						printf("%sに%dダメージ\n", name, Damage);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち	

						printf("%sの残りHPは%dだ\n", name, HP);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

					}
					else
					{
						printf("%sにダメージを与えられなかった\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち	
					}
					if (HP < 0) {

						printf("勇者%sは倒れてしまった…\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						GameOver();

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						exit(-1);
					}

					printf("%sの鉄の盾は割られてしまった\n",name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					VIT = 0;

					Point = 1;

					printf("%sは怯んで動けない\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					ad--;

				}
				else
				{
					printf("ソウルナイトのソウルブレイク\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					//勇者が受けたダメージ  カウンターしたあとの攻撃
					Damage = SoulKnight - VIT;

					if (Damage >= 0) {
						HP -= Damage;

						printf("%sに%dダメージ\n", name, Damage);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち	

						printf("%sの残りHPは%dだ\n", name, HP);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

					}
					else
					{
						printf("%sにダメージを与えられなかった\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち	
					}

					if (HP < 0) {

						printf("勇者%sは倒れてしまった…\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						GameOver();

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						exit(-1);
					}

					printf("%sの一刀両断!!\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					//ダメージ計算
					Damage = AT * 2 - defense;

					if (Damage >= 0) {
						SoulKnightH -= Damage;

						printf("ソウルナイトに%dダメージ\n", Damage);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち	
					}

					//敵HP0判定
					if (SoulKnightH <= 0)
					{
						printf("ソウルナイトは倒れた\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						break;
					}
				}

				break;
			default:

				printf("選択肢の入力方式が間違っています。\n１～３で入力してください。\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				break;
			}

			loop++;

			system("cls");

		}
	}

	loopA += loop;


	printf("ソウルナイトは鋼の剣、鋼の盾、鋼の鎧を落としていった\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	AT = SteelSword;
	VIT = SteelShield;
	HP += SteelArmor;

	printf("%sは防具を着てHPが増えた\n",name);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("%sのHPは%dHPになった\n",name,HP);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち


/*******************************************************************************
*	カナリア洞窟中盤		ブラックタイガー戦
*******************************************************************************/

	printf("\n%sはカナリア洞窟に入っていった\n", name);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	system("cls");

	printf("どうやら洞窟内にも魔物がいるようだ\n\n魔物に洞窟の行き先をふさがれている\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("ブラックタイガーが現れた\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	system("cls");

	//こもれび森中央

	printf("\nブラックタイガーとの戦闘が始まった\nHP%d", HP);
	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("\n\nブラックタイガーは%sを睨んでいる\n",name);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	Point = 0;
	i = 0;
	A = 0;
	loop = 0;
	ad = 0;
	while (BTigerH >= 0) {

		A = (BTigerH / 5) + 1;

		int defense = 1 + rand() % A;
		int Ran = 1 + rand() % 100;

		if (ad > 0)
		{
			defense -= 20;
		}
		else if (ad == -1)
		{
			BTiger += 10;

			ad = 0;
		}

		if (loop == 3)
		{
			printf("ブラックタイガーは武者震いしている\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			i = 1;
		}
		else
		{
			printf("ブラックタイガーは唸っている\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}

		if (i == 0)
		{

			printf("1攻撃\n2回避\n3カウンター\n選択肢入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%d", &num);

			system("cls");

			switch (num)
			{
			case 1:

				printf("ブラックタイガーの噛みつく\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				//勇者が受けたダメージ
				Damage = BTiger;


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

					GameOver();

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					exit(-1);
				}

				printf("%sの攻撃\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				//敵が受けたダメージ
				Damage = AT - defense;

				if (Damage >= 0) {
					BTigerH -= Damage;

					printf("ブラックタイガーに%dダメージ\n", Damage);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	
				}

				//敵HP0判定
				if (BTigerH <= 0)
				{
					printf("ブラックタイガーは倒れた\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					break;
				}

				break;
			case 2:
				printf("%sの回避\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ブラックタイガーの噛みつく\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("しかし、%sには当たらなかった\n",name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ブラックタイガーはバランスを崩した\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				ad++;

				printf("ブラックタイガーは怒り狂っている\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				BTiger += 5;

				printf("ブラックタイガーの攻撃力は5上がった\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				break;
			case 3:

				printf("%sのカウンター\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ブラックタイガーの噛みつく\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち


				//勇者が受けたダメージ  カウンターしたあとの攻撃
				Damage = BTiger - VIT;

				if (Damage >= 0) {
					HP -= Damage;

					printf("%sに%dダメージ\n", name, Damage);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	

					printf("%sの残りHPは%dだ\n", name, HP);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

				}
				else
				{
					printf("%sにダメージを与えられなかった\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	
				}

				if (HP < 0) {

					printf("勇者%sは倒れてしまった…\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					GameOver();

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					exit(-1);
				}

				printf("%sの一刀両断!!\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				//ダメージ計算
				Damage = AT * 2 - defense;

				if (Damage >= 0) {
					BTigerH -= Damage;

					printf("ブラックタイガーに%dダメージ\n", Damage);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	
				}

				//敵HP0判定
				if (BTigerH <= 0)
				{
					printf("ブラックタイガーは倒れた\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					break;
				}

				break;
			default:

				printf("選択肢の入力方式が間違っています。\n１～３で入力してください。\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				break;
			}

			loop++;

			system("cls");

		}
		else
		{
			printf("1攻撃\n2回避\n3カウンター\n選択肢入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%d", &num);

			system("cls");

			switch (num)
			{
			case 1:

				printf("ブラックタイガーの乱れひっかき\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				if (Ran > 50)
				{
					//勇者が受けたダメージ
					Damage = BTiger;


					printf("%sに%dダメージ\n", name, Damage);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					HP = HP - Damage;

					//勇者が受けたダメージ
					Damage = BTiger;


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

						GameOver();

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						exit(-1);
					}
				}
				else
				{
					//勇者が受けたダメージ
					Damage = BTiger;


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

						GameOver();

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						exit(-1);
					}
				}
				

				printf("%sの攻撃\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				//敵が受けたダメージ
				Damage = AT - defense;

				if (Damage >= 0) {
					BTigerH -= Damage;

					printf("ブラックタイガーに%dダメージ\n", Damage);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	
				}

				//敵HP0判定
				if (BTigerH <= 0)
				{
					printf("ブラックタイガーは倒れた\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					break;
				}

				break;
			case 2:


				printf("%sの回避\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ブラックタイガーの乱れひっかき\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				if (Ran > 95)
				{
					printf("%sはブラックタイガーの攻撃をよけきれない\n",name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					//勇者が受けたダメージ
					Damage = BTiger;


					printf("%sに%dダメージ\n", name, Damage);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					HP = HP - Damage;

					//勇者が受けたダメージ
					Damage = BTiger;


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

						GameOver();

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						exit(-1);
					}
				}
				else if (Ran>80)
				{
					printf("%sはブラックタイガーの攻撃をよけきれない\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					//勇者が受けたダメージ
					Damage = BTiger;


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

						GameOver();

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						exit(-1);
					}
				}
				else
				{

					printf("しかし、%sには当たらない\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("ブラックタイガーはバランスを崩した\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					ad++;

					printf("ブラックタイガーは怒り狂っている\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					BTiger += 5;

					printf("ブラックタイガーの攻撃力は5上がった\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち


				}

				break;
			case 3:

				printf("%sのカウンター\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ブラックタイガーの乱れひっかき\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち


				//勇者が受けたダメージ  カウンターしたあとの攻撃
				Damage = BTiger*2 - VIT*2;

				if (Damage >= 0) {
					HP -= Damage;

					printf("%sに%dダメージ\n", name, Damage);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	

					printf("%sの残りHPは%dだ\n", name, HP);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

				}
				else
				{
					printf("%sにダメージを与えられなかった\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	
				}


				if (HP < 0) {

					printf("勇者%sは倒れてしまった…\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					GameOver();

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					exit(-1);
				}

				printf("%sの一刀両断!!\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				//ダメージ計算
				Damage = AT * 2 - defense;

				if (Damage >= 0) {
					BTigerH -= Damage;

					printf("ブラックタイガーに%dダメージ\n", Damage);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	
				}

				//敵HP0判定
				if (BTigerH <= 0)
				{
					printf("ブラックタイガーは倒れた\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					break;
				}

				break;

			default:

				printf("選択肢の入力方式が間違っています。\n１～３で入力してください。\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				break;
			}

			loop++;

			system("cls");


		}
		

	}

	loopA += loop;

/*******************************************************************************
*	カナリア洞窟魔王の扉前		ライトニングズガドーン戦
*******************************************************************************/

	//printf("\n%sはカナリア洞窟の奥に進んでいった\n", name);

	//// キー入力待ち
	//rewind(stdin);		// ←キー入力情報をクリアする
	//(void)getchar();	// キー入力待ち

	//system("cls");

	//printf("洞窟の奥底で大きな扉を見つけた\n\nしかし、扉の前で魔物が立ちふさがっている\n");

	//// キー入力待ち
	//rewind(stdin);		// ←キー入力情報をクリアする
	//(void)getchar();	// キー入力待ち

	//printf("ライトニングズガドーン「ここまで来るとは、やるな勇者！」\n");

	//// キー入力待ち
	//rewind(stdin);		// ←キー入力情報をクリアする
	//(void)getchar();	// キー入力待ち

	//printf("ライトニングズガドーン「だけどここから先には進めないぜ！」\n");

	//// キー入力待ち
	//rewind(stdin);		// ←キー入力情報をクリアする
	//(void)getchar();	// キー入力待ち

	//printf("ライトニングズガドーンが現れた\n");

	//// キー入力待ち
	//rewind(stdin);		// ←キー入力情報をクリアする
	//(void)getchar();	// キー入力待ち

	//system("cls");

	////こもれび森中央

	//printf("\nライトニングズガドーンとの戦闘が始まった\nHP%d", HP);
	//// キー入力待ち
	//rewind(stdin);		// ←キー入力情報をクリアする
	//(void)getchar();	// キー入力待ち

	//

	//Point = 0;
	//i = 0;
	//A = 0;
	//loop = 1;
	//ad = 0;
	//while (Blast >= 0) {

	//	A = (Blast / 5) + 1;

	//	int defense = 1 + rand() % A;
	//	int Ran = 1 + rand() % 100;

	//	if (ad > 0)
	//	{
	//		defense -= 50;
	//	}
	//	else if (ad == -1)
	//	{
	//		Blast += 10;

	//		ad = 0;
	//	}

	//	if (loop%3 == 0)
	//	{
	//		printf("ライトニングズガドーンの魔力が強まった\n");

	//		// キー入力待ち
	//		rewind(stdin);		// ←キー入力情報をクリアする
	//		(void)getchar();	// キー入力待ち

	//		Blast += 10;

	//		printf("ライトニングズガドーンの攻撃力が10上がった\n");

	//		// キー入力待ち
	//		rewind(stdin);		// ←キー入力情報をクリアする
	//		(void)getchar();	// キー入力待ち

	//	}
	//	else
	//	{
	//		printf("\n\nライトニングズガドーンは魔力をためている\n");

	//		// キー入力待ち
	//		rewind(stdin);		// ←キー入力情報をクリアする
	//		(void)getchar();	// キー入力待ち
	//	}

	//	if (i == 0)
	//	{
	//		printf("1攻撃\n2回避\n3カウンター\n選択肢入力：");
	//		rewind(stdin);		// ←キー入力情報をクリアする
	//		(void)scanf("%d", &num);

	//		system("cls");

	//		switch (num)
	//		{
	//		case 1:



	//			break;
	//		case 2:
	//			
	//			break;
	//		case 3:

	//			

	//			break;
	//		default:

	//			printf("選択肢の入力方式が間違っています。\n１～３で入力してください。\n");

	//			// キー入力待ち
	//			rewind(stdin);		// ←キー入力情報をクリアする
	//			(void)getchar();	// キー入力待ち

	//			break;
	//		}

	//		loop++;

	//		system("cls");

	//	}

	//}

	//loopA += loop;






/*******************************************************************************
*	カナリア洞窟中		魔王サタン戦
*******************************************************************************/

printf("\nどうやら%sはカナリア洞窟の一番奥まで来たようだ\n", name);

// キー入力待ち
rewind(stdin);		// ←キー入力情報をクリアする
(void)getchar();	// キー入力待ち


system("cls");

printf("大きな扉がある\n\nこの先に魔王がいそうだ\n");

// キー入力待ち
rewind(stdin);		// ←キー入力情報をクリアする
(void)getchar();	// キー入力待ち

printf("%sは扉を開いた\n",name);

// キー入力待ち
rewind(stdin);		// ←キー入力情報をクリアする
(void)getchar();	// キー入力待ち

printf("大きな扉がある\n\nこの先に魔王がいそうだ\n");

// キー入力待ち
rewind(stdin);		// ←キー入力情報をクリアする
(void)getchar();	// キー入力待ち

printf("魔王「勇者%sか。遅かったな!!」\n",name);

// キー入力待ち
rewind(stdin);		// ←キー入力情報をクリアする
(void)getchar();	// キー入力待ち

printf("魔王「護衛隊が時間を稼いでくれたおかげで我は復活した!!」\n");

// キー入力待ち
rewind(stdin);		// ←キー入力情報をクリアする
(void)getchar();	// キー入力待ち

printf("魔王「いや、以前倒された時よりも、強くなっているぞ!」\n");

// キー入力待ち
rewind(stdin);		// ←キー入力情報をクリアする
(void)getchar();	// キー入力待ち

printf("魔王「勇者%sよいざ、勝負だ!!」\n",name);

// キー入力待ち
rewind(stdin);		// ←キー入力情報をクリアする
(void)getchar();	// キー入力待ち


system("cls");

printf("魔王が現れた\n");

// キー入力待ち
rewind(stdin);		// ←キー入力情報をクリアする
(void)getchar();	// キー入力待ち

printf("\n魔王サタンとの戦闘が始まった\nHP%d", HP);
// キー入力待ち
rewind(stdin);		// ←キー入力情報をクリアする
(void)getchar();	// キー入力待ち

	Point = 0;
	i = 0;
	A = 0;
	loop = 1;
	ad = 0;
	while (DevilH >= 0) {

		printf("魔王の残りHPは%dだ\n", DevilH);

		// キー入力待ち
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)getchar();	// キー入力待ち


		A = (Devil / 10) + 1;

		int defense = 1 + rand() % A;
		int Ran = 1 + rand() % 100;

		if (ad > 0)
		{
			defense=defense -(ad* 50);

			AT = ad * 50;

			ad = 0;
		}
		else if (ad == -1)
		{
			Devil += 10;

			ad = 0;
		}

		if (loop == 3)
		{
			printf("魔王の力が強まっている\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("魔王「力が溢れ出してくる」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("魔王「負ける気がしない！」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			Devil += 50;

			printf("魔王の攻撃力が50上がった\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			i=1;

		}
		else if(loop == 8)
		{
			printf("魔王の力が強まっている\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("魔王「勇者%s…闇に葬ってやる!!」\n",name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("魔王「我に逆らったこと後悔するがいい！」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			Devil += 50;

			printf("魔王の攻撃力が50上がった\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			i=2;
		}
		else if (loop == 13)
		{
			printf("魔王の力が強まっている\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("魔王「勇者%s…ここまで化け物とは思わなかったぞ。」\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("魔王「我が攻撃をここまで耐えるとは…」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("魔王「全力で叩きのめしてくれるわ!!」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			Devil += 50;

			printf("魔王の攻撃力が50上がった\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			i=3;
		}
		else if (loop == 20)
		{
			printf("魔王の力が強まっている\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("魔王「勇者%sよ！ここまでよく耐え抜いたな」\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("魔王「全てを無に還す禁忌の呪文の呪文の準備が完了した！」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("魔王「これで全て終わらせてやる！」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			Devil += 500;

			printf("魔王の攻撃力が500上がった\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			i=4;
		}
		else if (loop == 21)
		{
			printf("魔王「なっ、なに⁈なぜ、なぜだ？なぜ、生きていられる！」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("魔王「我が最高魔力の呪文を…」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("魔王「魔王は動揺している」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			ad += 2;

			i = 5;
		}
		else if (i == 6)
		{
			printf("魔王「クッ、我が最高魔力の呪文効かぬはずがあるわけない。」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("魔王「倒れぬのなら、倒れるまで撃つだけ！」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}
		else
		{
			printf("魔王は魔力をためている\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}


		if (i == 0)
		{
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



			printf("1攻撃\n2回避\n3カウンター\n選択肢入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%d", &num);

			system("cls");

			switch (num)
			{
			case 1:

				printf("魔王のレストインピース\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

					printf("%sの攻撃\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					//敵が受けたダメージ
					Damage = AT - defense;

					if (Damage >= 0) {
						DevilH -= Damage;

						printf("魔王に%dダメージ\n", Damage);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち	

						printf("魔王の残りHPは%dだ\n", DevilH);
					}

					//敵HP0判定
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

						printf("サタン「この力を得てしても勇者には勝てないというのか…」\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("勇者は魔王を倒した!!\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						GameClear();

						break;
					}

					if (Ran > 70)
					{
						printf("魔王のレストインピース\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("魔王「眠りに堕ちろ」\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						//勇者が受けたダメージ
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

							GameOver();

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							exit(-1);
						}
					}
					else
					{
						printf("魔王は魔力を溜めなおしている\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						ad++;
					}


				break;
			case 2:
				
				if (Ran > 30)
				{
					printf("%sの回避\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("魔王のレストインピース\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("%sは魔王の攻撃を避けきれない\n",name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち


					printf("魔王「眠りに堕ちろ」\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					//勇者が受けたダメージ
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

						GameOver();

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						exit(-1);
					}
				}
				else
				{
					printf("%sの回避\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("魔王のレストインピース\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("しかし、%sには当たらない\n",name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち
					
					printf("魔王は魔力を溜めなおしている\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					ad++;

				}

				break;
			case 3:

				printf("%sのカウンター\n",name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

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

				//勇者が受けたダメージ
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

					GameOver();

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					exit(-1);
				}

				break;
			default:

				printf("%sはコマンド入力に失敗した\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔王のレストインピース\n");

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

				if (HP < 0) {

					printf("勇者%sは倒れてしまった…\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					GameOver();

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					exit(-1);
				}

				printf("%sの残りHPは%dだ\n", name, HP);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				


				break;
			}

			system("cls");

		}
		else if (i == 1)
		{
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

			printf("1.攻撃\n2.回避\n3.カウンター\n選択肢入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%d", &num);

			system("cls");

			switch (num)
			{
			case 1:

				printf("%sの攻撃\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔王のシャドウエッジ\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				//確率攻撃
				if (Ran > 70)
				{
					printf("魔王の攻撃のほうが速い\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("魔王「闇の刃に切り裂かれろ！」\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					//勇者が受けたダメージ
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

						GameOver();

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						exit(-1);
					}

					printf("%sの攻撃\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					//魔王が受けたダメージ
					Damage = AT - defense;

					if (Damage >= 0) {
						DevilH -= Damage;

						printf("魔王に%dダメージ\n", Damage);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち	

						printf("魔王の残りHPは%dだ\n", DevilH);
					}

					//魔王HP0判定
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

						printf("サタン「この力を得てしても勇者には勝てないというのか…」\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("勇者は魔王を倒した!!\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						GameClear();

						break;
					}
				}
				else
				{
					printf("刃と刃がぶつかり合って攻撃が相殺された\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち
				}

				break;
			case 2:

				//確率攻撃
				if (Ran > 90)
				{
					printf("%sの回避\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("魔王のシャドウエッジ\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("%sは魔王の攻撃を避けきれない\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち


					printf("魔王「闇の刃に切り裂かれろ！」\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					//勇者が受けたダメージ
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

						GameOver();

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						exit(-1);
					}
				}
				else
				{
					printf("%sの回避\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("魔王のシャドウエッジ\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("しかし、%sには当たらない\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("魔王は魔力を溜めなおしている\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					ad++;

				}

				break;
			case 3:

				printf("%sのカウンター\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

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

				//勇者が受けたダメージ
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

					GameOver();

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					exit(-1);
				}

				break;
			default:

				printf("%sはコマンド入力に失敗した\n", name);

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

					GameOver();

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					exit(-1);
				}


				break;
			}


		}
		else if(i == 2)
		{
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

			printf("1.攻撃\n2.回避\n3.カウンター\n選択肢入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%d", &num);

			system("cls");

			switch (num)
			{
			case 1:

				printf("魔王のジャガーノート\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("%sの攻撃\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				//確率攻撃
				if (Ran > 20)
				{
					printf("魔王の攻撃のほうが速い\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("魔王「我が力は止められぬ!!」\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					//勇者が受けたダメージ
					Damage = Devil;


					printf("%sに%dダメージ\n", name, Damage);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					HP = HP - Damage;

					if (HP < 0) {

						printf("勇者%sは倒れてしまった…\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						GameOver();

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						exit(-1);
					}

					printf("%sの残りHPは%dだ\n", name, HP);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("%sの攻撃\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					//魔王が受けたダメージ
					Damage = AT - defense;

					if (Damage >= 0) {
						DevilH -= Damage;

						printf("魔王に%dダメージ\n", Damage);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち	

						printf("魔王の残りHPは%dだ\n", DevilH);
					}

					//魔王HP0判定
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

						printf("サタン「この力を得てしても勇者には勝てないというのか…」\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("勇者は魔王を倒した!!\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						GameClear();

						break;
					}
				}
				else
				{
					printf("%sの攻撃\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					//魔王が受けたダメージ
					Damage = AT - defense;

					if (Damage >= 0) {
						DevilH -= Damage;

						printf("魔王に%dダメージ\n", Damage);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち	

						printf("魔王の残りHPは%dだ\n", DevilH);
					}

					//魔王HP0判定
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

						printf("サタン「この力を得てしても勇者には勝てないというのか…」\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("勇者は魔王を倒した!!\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						GameClear();

						break;
					}

					printf("魔王は怯んでいる\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					ad++;

				}

				break;
			case 2:

				//確率攻撃
				if (Ran > 20)
				{
					printf("%sの回避\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

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

					//勇者が受けたダメージ
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

						GameOver();

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						exit(-1);
					}
				}
				else
				{
					printf("%sの回避\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("魔王のジャガーノート\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("しかし、%sには当たらない\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("魔王は魔力を溜めなおしている\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					ad++;

				}

				break;
			case 3:

				printf("%sのカウンター\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔王のジャガーノート\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("目にも止まらぬ速さだ\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("%sは魔王の刀を弾いた\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				// 勇者が受けたダメージ  カウンターしたあとの攻撃
					Damage =	Devil - VIT;

				if (Damage >= 0) {
					HP -= Damage;

					printf("%sに%dダメージ\n", name, Damage);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	

					if (HP < 0) {

						printf("勇者%sは倒れてしまった…\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						GameOver();

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						exit(-1);
					}


					printf("%sの残りHPは%dだ\n", name, HP);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

				}
				else
				{
					printf("%sにダメージを与えられなかった\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	
				}

				
				printf("%sの雷鳴鉄槌斬り\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				//ダメージ計算
				Damage = AT * 2 - defense;

				if (Damage >= 0) {
					DevilH -= Damage;

					printf("魔王に%dダメージ\n", Damage);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	
				}

				//敵HP0判定
				if (DevilH <= 0)
				{
					printf("魔王は倒れた\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					break;
				}
				
				break;
			default:

				printf("%sはコマンド入力に失敗した\n", name);

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

					GameOver();

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					exit(-1);
				}


				break;
			}
		}
		else if (i == 3)
		{
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


			printf("1.攻撃\n2.回避\n3.カウンター\n選択肢入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%d", &num);

			system("cls");

			switch (num)
			{
			case 1:

				printf("%sの攻撃\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔王のカタストロフィ\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				//確率攻撃
				if (Ran > 70)
				{
					printf("魔王の攻撃のほうが速い\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("魔王のカタストロフィ\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち


					printf("魔王「今こそ破滅の時‼」\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					//勇者が受けたダメージ
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

						GameOver();

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						exit(-1);
					}

					printf("%sの攻撃\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					//魔王が受けたダメージ
					Damage = AT - defense;

					if (Damage >= 0) {
						DevilH -= Damage;

						printf("魔王に%dダメージ\n", Damage);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち	

						printf("魔王の残りHPは%dだ\n", DevilH);
					}

					//魔王HP0判定
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

						printf("サタン「この力を得てしても勇者には勝てないというのか…」\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("勇者は魔王を倒した!!\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						GameClear();

						break;
					}
				}
				else
				{
					printf("%sの攻撃のほうが速い\n",name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("%sの攻撃\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					//魔王が受けたダメージ
					Damage = AT - defense;

					if (Damage >= 0) {
						DevilH -= Damage;

						printf("魔王に%dダメージ\n", Damage);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち	

						printf("魔王の残りHPは%dだ\n", DevilH);
					}

					//魔王HP0判定
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

						printf("サタン「この力を得てしても勇者には勝てないというのか…」\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("勇者は魔王を倒した!!\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						GameClear();

						break;
					}

					printf("魔王は怯んで魔法を出せない\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					ad++;
				}

				break;
			case 2:

				//確率攻撃
				if (Ran > 30)
				{
					printf("%sの回避\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("魔王のカタストロフィ\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("%sは魔王の攻撃を避けきれない\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち


					printf("魔王「今こそ破滅の時‼」\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					//勇者が受けたダメージ
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

						GameOver();

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						exit(-1);
					}
				}
				else
				{
					printf("%sの回避\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("魔王のカタストロフィ\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("しかし、%sには当たらない\n", name);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("魔王は魔力を溜めなおしている\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					ad++;

				}

				break;
			case 3:

				printf("%sのカウンター\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔王のカタストロフィ\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔法攻撃はカウンターできない！\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔王「今こそ破滅の時‼」\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				//勇者が受けたダメージ
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

					GameOver();

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					exit(-1);
				}

				break;
			default:

				printf("%sはコマンド入力に失敗した\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔王のカタストロフィ\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔王「今こそ破滅の時‼」\n");

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

					GameOver();

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					exit(-1);
				}

				break;
			}

		}
		else if (i == 4)
		{

			printf("魔王のシャットダウン\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("滅びの呪文だ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち


			printf("1.雷鳴鉄槌斬り\n2.回避\n3.カウンター\n選択肢入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%d", &num);

			system("cls");

			switch (num)
			{
			case 1:

				printf("%sの雷鳴鉄槌斬り\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				//魔王が受けたダメージ
				Damage = AT*2 - defense;

				if (Damage >= 0) {
					DevilH -= Damage;

					printf("魔王に%dダメージ\n", Damage);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	

					printf("魔王の残りHPは%dだ\n", DevilH);
				}

				//魔王HP0判定
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

					printf("サタン「この力を得てしても勇者には勝てないというのか…」\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("勇者は魔王を倒した!!\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					GameClear();

					break;
				}

				printf("魔王のシャットダウン\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔王「全て崩れ落ちろ」\n");

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

					GameOver();

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					exit(-1);
				}

				break;
			case 2:

				printf("%sの回避\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("しかし、回避できない\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔王のシャットダウン\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔王「全て崩れ落ちろ」\n");

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

					GameOver();

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					exit(-1);
				}

				break;
			case 3:

				printf("%sのカウンター\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("しかし、カウンターできない\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔王のシャットダウン\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔王「全て崩れ落ちろ」\n");

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

					GameOver();

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					exit(-1);
				}

				break;
			default:

				printf("%sはコマンド入力に失敗した\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔王のシャットダウン\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔王「全て崩れ落ちろ」\n");

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

					GameOver();

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					exit(-1);
				}

				break;
			}


		}
		else if (i == 5)
		{
			printf("魔王は動揺している\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち


			printf("1.雷鳴鉄槌斬り\n選択肢入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%d", &num);

			system("cls");

			switch (num)
			{
			case 1:

				printf("勇者%sの雷鳴鉄槌斬り\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				//魔王が受けたダメージ
				Damage = AT * 3 - defense;

				if (Damage >= 0) {
					DevilH -= Damage;

					printf("魔王に%dダメージ\n", Damage);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	

					printf("魔王の残りHPは%dだ\n", DevilH);
				}

				//魔王HP0判定
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

					printf("サタン「この力を得てしても勇者には勝てないというのか…」\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("勇者は魔王を倒した!!\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					GameClear();

					break;
				}

				printf("魔王は動揺して動けない\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち


				break;
			default:

				printf("%sはコマンド入力に失敗した\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔王は動揺して動けない\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				break;
			}

			i = 6;

		}
		else if (i == 6)
		{

			printf("魔王のシャットダウン\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("滅びの呪文だ\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち


			printf("1.雷鳴鉄槌斬り\n2.回避\n3.カウンター\n選択肢入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%d", &num);

			system("cls");

			switch (num)
			{
			case 1:

				printf("%sの雷鳴鉄槌斬り\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				//魔王が受けたダメージ
				Damage = AT * 2 - defense;

				if (Damage >= 0) {
					DevilH -= Damage;

					printf("魔王に%dダメージ\n", Damage);

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち	

					printf("魔王の残りHPは%dだ\n", DevilH);
				}

				//魔王HP0判定
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

					printf("サタン「この力を得てしても勇者には勝てないというのか…」\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("勇者は魔王を倒した!!\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					break;
				}

				printf("魔王のシャットダウン\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔王「全て崩れ落ちろ」\n");

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

					GameOver();

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					exit(-1);
				}

				break;
			case 2:

				printf("%sの回避\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("しかし、回避できない\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔王のシャットダウン\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔王「全て崩れ落ちろ」\n");

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

					GameOver();

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					exit(-1);
				}

				break;
			case 3:

				printf("%sのカウンター\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("しかし、カウンターできない\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔王のシャットダウン\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔王「全て崩れ落ちろ」\n");

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

					GameOver();

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					exit(-1);
				}

				break;
			default:

				printf("%sはコマンド入力に失敗した\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔王のシャットダウン\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("魔王「全て崩れ落ちろ」\n");

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

					GameOver();

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					exit(-1);
				}

				break;
			}

		}

		loop++;

		system("cls");

	}

	printf("%sは無事に魔王を倒し、フエルサ王国に平和をもたらした\n", name);

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	GameClear();






















	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	/* 終了 */
	return 0;



}

void choice(void)
{
	char yesno;
	int loop = 0;
	int i = 0;

	while (loop < 1)
	{
		printf("魔王の討伐依頼を承諾しますか?\nY/N入力：");
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%c", &yesno);

		if ((yesno == 'N') || (yesno == 'n'))
		{
			i++;

			if (i == 3)
			{
				//GameOverルート
				printf("王様「そうか…」 \n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("王様「残念じゃ…」 \n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("力を取り戻した魔王に王国は滅ぼされてしまった…\n");

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
			else
			{

				printf("王様「...」 \n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("王様「フエルサ王国は先日の魔王襲来の復興で資金に余裕がないのじゃ…」 \n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("王様「資金を使って防壁を強化することも、兵器を開発することもできぬ…」 \n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("王様「この王国を救えるのはお主しかおらぬのじゃ。どうか、魔王を倒しに行ってはくれぬか？」 \n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

			}
		}
		else
		{
			loop++;
		}
	}

}

void title(void)
{
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　□　　  □　　　　　　　　　　　　　　　　　　　　　　　　　　　          \n");
	printf("　　□□  □□　　　　　　　    □□　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　 □　□□  □　   □□    　□　　　　　□　　　□□□　　 □　□　　　　   \n");
	printf("　 □　 □   □　 □　　□　　□□□　　□□□　□　　□□　 □□　　　　   　\n");
	printf("　□　　  　  □　□　　□　　　  □　　　□　　□　　□□　 □　　　　　　   \n");
	printf("　□　　　　  □　　□□　　　□□　　　　□　　　□□　 □　□　　　　　　 　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　  \n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　□□□□　　　　                  □          □□□　　　　\n");
	printf("　　　　　　　　　□　　　□　               □□   □         □    □　　　 \n");
	printf("　　　　　　　　　□      □　　□　  □   □       □□□        　□　　    \n");
	printf("　　　　　　　　　□□□□　    □    □   □□□   □    □     □□ 　　 　 \n");
	printf("　　　　　　　　　□　  □  　  □    □       □   □    □    □  　　　　  \n");
	printf("　　　　　　　　  □　  　□　　 □□□    □□     □    □   □□□□   　  \n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　  　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("操作方法\n");
	printf("enter：次の文へ進む\n");
	printf("選択肢：数字か文字を入力してenterで次の文に進みます");

}

void GameOver(void)
{

	system("cls");

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

}

void GameClear(void)
{
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
	printf("　　　　　□□□　□　　　　□□□□□□　　　 □　　　 □□□□　　　　　　\n");
	printf("　　　　□　　　　□　　　　□　　　　　　　　□□　　　□　　　□　　　　　\n");
	printf("　　　　□　　　　□　　　　□□□□□□　　 □　□　　 □　　　□　　　　\n");
	printf("　　　　□　　　　□　　　　□　　　　　　  □□□□　　□□□□　　　　　\n");
	printf("　　　　□　　　　□　　　　□　　　　　　 □　　　□　 □　　□　　　　　\n");
	printf("　　　　　□□□　□□□□　□□□□□□  □　　　　□　□　　　□　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");

}