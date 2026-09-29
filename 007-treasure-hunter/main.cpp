/*******************************************************************************
* タイトル:		メインプログラム
* プログラム名:	main.cpp
* 作成者:		大槻海斗
* 作成日:		2023/09/05
********************************************************************************/

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
#include <Windows.h>
#include <conio.h>	//Key入力処理　その2

/*******************************************************************************
* マクロ定義
*******************************************************************************/


/*******************************************************************************
* 構造体定義
*******************************************************************************/


/*******************************************************************************
* プロトタイプ宣言(関数の取説)
*******************************************************************************/
void title(void);
void GameOver(void);
void GameClear(void);


/*******************************************************************************
* グローバル変数
*******************************************************************************/
//map1
int field[10][10] = {
		1,1,1,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,4,0,1,
		1,0,0,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,1,1,
	};

//map2
int field2[15][15] = {
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
		1,0,0,0,0,0,0,0,3,0,1,0,4,0,1,
		1,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
		1,0,0,0,1,1,1,1,1,1,1,1,0,1,1,
		1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

//map3
int field3[20][20] = {
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
	1,1,1,1,0,0,0,1,1,1,1,1,1,1,1,1,1,0,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,3,0,1,0,6,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

//　1　プレイヤー座標
int py = 2;		//２行目
int px = 2;		//２列目

int Ey = 4;
int Ex = 5;

int Ey1 = 10;
int Ex1 = 10;

int Ey2 = 15;
int Ex2 = 15;

int Ey3 = 15;
int Ex3 = 15;

int Ey4 = 15;
int Ex4 = 17;


//プレイヤー名
char name[256];

/*******************************************************************************
 関数名:	int main( void )
 引数　:	void
 戻り値:	正常終了: int型の 0
 説明　:	メイン関数
*******************************************************************************/
int main( void )
{
/*******************************************************************************
* 乱数
*******************************************************************************/

//ランダムの初期化	(これは起動時に1回しか行わない）
	srand((unsigned)time(NULL));

	//コピペ用

	//int defense = 1 + rand() % 100;

/*******************************************************************************
* 変数
*******************************************************************************/
	
	//選択肢
	int num = 0;
	char yesno;
	int i = 0;	//分岐点　階段とか
	int Z = 0;	//操作説明&表記説明
	int H = 0;	//回復画面
	int B = 0;	//回復画面

	//ループ数
	int loop = 0;

	////プレイヤー
	//パラメータ
	int HP = 500;			//体力
	int MaxHP = 500;		//最大体力値
	int MP = 50;			//マジックポイント
	int MaxMP = 50;			//最大マジックポイント
	int AT = 10;			//攻撃力
	int VIT = 10;			//防御力
	int Damage;				//ダメ計算
	int Point = 0;			//なんか分岐
	int ad = 0;				//優勢かどうか

	//武器攻撃力
	int IronSword = 30;
	int SteelSword = 70;

	//防御力
	int IronArmor = 30;
	int SteelArmor = 50;

	//回復薬
	int HPplus = 3;			//回復薬の個数
	int MPplus = 1;			//MP回復薬の個数

	////敵キャラ
	//キャラ攻撃力
	int Slime = 20;			//スライム
	int Boar = 30;			//トツゲキイノシシ
	int GD = 20;			//ガーディアン
	int Dr = 30;			//ドローン
	int Dr2 = 30;		//ドローン
	int Dr3 = 30;		//ドローン
	int Golem = 50;			//ゴーレム
	int ELIZA = 50;		//イライザ　ボス

	//キャラ体力
	int SlimeH = 10;		//スライム
	int BoarH = 100;		//トツゲキイノシシ
	int GDH = 150;			//ガーディアン
	int DrH = 100;		//ドローン		倒された数で攻撃力アップ
	int DrH2 = 100;		//ドローン
	int DrH3 = 100;		//ドローン
	int GolemH = 500;		//ゴーレム
	int ELIZAH = 700;		//イライザ　ボス
	
	int A = 0;
	int C = 0;

	//敵生存確認
	int E1 = 1;
	int E2 = 1;
	int E3 = 1;
	int E4 = 1;
	int E5 = 1;

	//戦闘
	int PC = 0;				//プレイヤー選択肢
	int EC = 0;				//敵選択肢
	int BD = 0;				//逃げる

	//分岐変数
	int A4 = 0;
	int Br = 0;
	int GDB = 0;
	int DRB = 0;
	int loopA = 0;

	//場所
	int old_px;	//移動前の位置を保存しておく
	int old_py;

	//敵
	int old_Ex;	//移動前の位置を保存しておく
	int old_Ey;

	int old_Ex1;//移動前の位置を保存しておく
	int old_Ey1;

	int old_Ex2;//移動前の位置を保存しておく
	int old_Ey2;

	int old_Ex3;//移動前の位置を保存しておく
	int old_Ey3;

/*******************************************************************************
* プロローグ
*******************************************************************************/

	//とりあえずタイトル
	title();

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	system("cls");

	//名前入力
	while (i < 1)
	{
		printf("\n名前を入力してね：");
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%s", &name);

		printf("%sでよろしいですか？\nY/N入力：",name);
		rewind(stdin);		// ←キー入力情報をクリアする
		(void)scanf("%c", &yesno);

		if ((yesno == 'Y') || (yesno == 'y'))
		{
			//ループ抜け出し
			i += 1;
		}
		system("cls");
	}
	 i = 0;

	 printf("\n俺の名前は%s。凄腕と名高いトレジャーハンターだ。\n", name);

	 // キー入力待ち
	 rewind(stdin);		// ←キー入力情報をクリアする
	 (void)getchar();	// キー入力待ち

	 printf("今日はここ、サハーラダンジョンの奥深くにあるといわれている\nオリハルコンの王冠を手に入れに来た！\n");

	 // キー入力待ち
	 rewind(stdin);		// ←キー入力情報をクリアする
	 (void)getchar();	// キー入力待ち

	 printf("魔物達が住みついているらしく探索が難航しているらしい\n");

	 // キー入力待ち
	 rewind(stdin);		// ←キー入力情報をクリアする
	 (void)getchar();	// キー入力待ち

	 printf("探索をしているのはこの街に訪れた冒険者…\nダンジョン攻略は素人だ\n");

	 // キー入力待ち
	 rewind(stdin);		// ←キー入力情報をクリアする
	 (void)getchar();	// キー入力待ち

	 printf("同業のやつらはまだ目を付けていない。\n宝を手に入れるのはこの俺だ！\n");

	 // キー入力待ち
	 rewind(stdin);		// ←キー入力情報をクリアする
	 (void)getchar();	// キー入力待ち

/*******************************************************************************
* フロア1
*******************************************************************************/

	//Sleepを最後にいれるとちらつきが減る
	while (loop < 1)
	{
		Z = 0;
		H = 0;
		B = 0;

		printf("\nWASDを押してください\n");

		//プレイヤー
		old_px = px;	//移動前の位置を保存しておく
		old_py = py;

		//敵
		old_Ex = Ex;	//移動前の位置を保存しておく
		old_Ey = Ey;

		//key入力
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
			py--;
			break;
		case 'A':
		case 'a':
			px--;
			break;
		case 'S':
		case 's':
			py++;
			break;
		case 'D':
		case 'd':
			px++;
			break;
		case 'Z':
		case 'z':
			Z = 1;
			break;
		case 'H':
		case 'h':
			H = 1;
			break;
		case 'B':
		case 'b':
			B = 1;
			break;
		}

		//操作説明＆表記説明
		if (Z == 1)
		{
			system("cls");

			printf("\nW：上方向に移動\nA：左方向に移動\nS：下方向に移動\nD：右方向に移動\nH：回復薬を使用\nB：聖水を使用\n\nマップ内表記説明\n■：壁\nＥ：敵\n□：階段\n\nEnter：この画面を閉じる");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}

		//回復薬使用
		if (H == 1)
		{
			system("cls");

			printf("回復薬を使用しますか？\nY/N入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%c", &yesno);

			if ((yesno == 'Y') || (yesno == 'y'))
			{
				if (HPplus >= 1)
				{
					if (HP == MaxHP)
					{
						printf("HPが満タンのようだ");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						continue;
					}
					else
					{

						printf("%sは回復薬を使った\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						HP += 150;

						if (MaxHP <= HP)
						{
							HP = MaxHP;
						}

						printf("%sのHPは%dになった", name, HP);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						HP -= 1;
					}

				}
				else
				{
					printf("回復薬が足りないようだ…");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					continue;
				}

			}

		}

		//聖水使用
		if (B == 1)
		{
			system("cls");

			printf("聖水を使用しますか？\nY/N入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%c", &yesno);

			if ((yesno == 'Y') || (yesno == 'y'))
			{
				if (MPplus >= 1)
				{
					if (HP == MaxHP)
					{
						printf("MPが満タンのようだ");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						continue;
					}
					else
					{

						printf("%sは聖水を使った\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						MP += 25;

						if (MaxMP <= MP)
						{
							MP = MaxMP;
						}

						printf("%sのMPは%dになった", name, MP);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						MPplus -= 1;
					}

				}
				else
				{
					printf("聖水が足りないようだ…");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					continue;
				}

			}
			
		}

		//移動後の場所が障害物かチェックする　マップ内処理
		switch (field[py][px])
		{
		case 1:		//壁だった
			px = old_px;	//移動前の場所に戻る
			py = old_py;
			break;

		case 4:		//階段
			i = 0;

			px = old_px;	//移動前の場所に戻る
			py = old_py;

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
					loop += 1;
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
		}

		//プレイヤーと敵の衝突判定
		if (py == Ey && px == Ex)			//敵
		{
			system("cls");

			printf("\n敵が現れた\nEnterで進む\n");
			E1 = 2;
			Ex = -1;
			Ey = -1;

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}

		//敵移動	スライム
		if (E1 == 1)
		{
			int Ran = 1 + rand() % 100;

			if (Ran <=	15)
			{
				Ey--;
			}
			else if (Ran <= 30)
			{
				Ex--;
			}
			else if (Ran <= 45)
			{
				Ey++;
			}
			else if (Ran <= 60)
			{
				Ex++;
			}
			else if (Ran <= 100);
			{

			}

			//敵衝突判定
			switch (field[Ey][Ex])
			{
			case 1:		//壁だった
				Ex = old_Ex;	//移動前の場所に戻る
				Ey = old_Ey;
				break;
			case 4:		//階段
				Ex = old_Ex;	//移動前の場所に戻る
				Ey = old_Ey;
				break;
			}
		}

		//マップ　と UI
		if (loop == 0)
		{
			//マップ画面
			system("cls");
			int UI = 0;
			for (int y = 0; y < 10; y++)
			{
				for (int x = 0; x < 10; x++)
				{
					//　プレイヤー表示
					if ((x == px) && (y == py))
					{
						printf("Ｐ");
						continue;	//Pを表示してスキップ
					}

					if (E1 == 1)
					{
						if ((x == Ex) && (y == Ey))
						{
							printf("Ｅ");	//敵
							continue;	//Pを表示してスキップ
						}
					}
					
					switch (field[y][x])
					{
					case 0:
						printf("　");	//移動可能床
						break;

					case 1:
						printf("■");	//壁
						break;

					case 2:
						printf("＄");	//お金
						break;

					case 3:

						break;

					case 4:
						printf("□");	//階段
						break;
					case 5:
						printf("Ｓ");	//ショップ
						break;

					}
				}

				//　UI　右画面に表示
				if (UI == 0)
				{
					printf("　　HP:%d", HP);
				}
				else if (UI == 1)
				{
					printf("　　MP:%d", MP);
				}
				else if (UI == 3)
				{
					printf("　　回復薬:%d個", HPplus);
				}
				else if (UI == 4)
				{
					printf("　　聖　水:%d個", MPplus);
				}
				else if (UI == 6)
				{
					printf("　　Zボタンで操作説明&表記説明");
				}
				UI++;
				printf("\n");
			}
		}


		//プレイヤーと敵の衝突判定
		if (py == Ey && px == Ex)			//敵
		{
			printf("\n敵が現れた\nEnterで進む\n");
			E1 = 2;
			Ex = -1;
			Ey = -1;

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			//ここで戦闘画面に遷移 モンスターラッシュ２からプログラムを引っ張てくる
			//グローバル関数で呼びだし
			system("cls");


		}

		//戦闘画面に遷移
		if (E1 == 2)
		{
			system("cls");
			printf("スライムが現れた\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("\nスライムとの戦闘が始まった\nHP%dMP%d", HP,MP);
			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("\n\nスライムは攻撃の準備をしている\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			system("cls");


			BD = 0;
			//スライム戦闘プログラム
			while ((SlimeH >= 0) && (HP >= 0) && (BD < 1))
			{
				//敵ディフェンス設定
				A = (SlimeH / 5) + 1;
				int defense = 1 + rand() % A;
				int VIT2 = 1 + rand() % VIT;

				//敵の選択肢
				int Ran = 1 + rand() % 100;
				if (Ran <= 30)
				{
					//攻撃
					EC = 1;
				}
				else if (Ran <= 50)
				{
					//必殺技
					EC = 2;
				}
				else if (Ran <= 100)
				{
					//回避　or 様子見
					EC = 3;
				}

				printf("\nHP%dMP%d\n\n1攻撃\n\n2持ち物\n\n3逃げる\n\n選択肢入力：",HP,MP);
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)scanf("%d", &PC);

				system("cls");

				//プレイヤー選択肢行動
				switch (PC)
				{
				case 1:			//攻撃　と　MP攻撃　と魔法攻撃に分岐

					printf("\n1通常攻撃\n\n2火炎斬り(MP5消費)\n\n3フレームストーム(MP10消費)\n\n4戻る\n\n選択肢入力：");
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)scanf("%d", &num);

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
						else
						{
							printf("しかしスライムにダメージを与えられない\n");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち	
						}

						break;

					case 2:
						if (MP >= 5)
						{

							printf("%sの火炎斬り\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							//ダメージ計算
							Damage = AT * 1.5 - defense;

							if (Damage >= 0) {
								SlimeH -= Damage;

								printf("スライムに%dダメージ\n", Damage);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}
							else
							{
								printf("しかしスライムにダメージを与えられない\n");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}

							MP -= 5;
						}
						else
						{
							printf("MPが足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}

						break;

					case 3:
						if (MP >= 10)
						{

							printf("%sのフレームストーム\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							//ダメージ計算
							Damage = AT * 2 - defense;

							if (Damage >= 0) {
								SlimeH -= Damage;

								printf("スライムに%dダメージ\n", Damage);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}
							else
							{
								printf("しかしスライムにダメージを与えられない\n");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}

							MP -= 10;
						}
						else
						{
							printf("MPが足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}

						break;

					default:

						printf("選択肢の入力方式が間違っています。\n1～4で入力してください。\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

					case 4:
						//戦闘中のwhileまで戻る
						system("cls");
						continue;
						break;
					}

					break;
					
				case 2:			//持ち物欄を開きたい

					system("cls");

					printf("\n1回復薬\n\n2聖水\n\n3戻る\n\n選択肢:");
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)scanf("%d", &num);

					switch (num)
					{
					case 1:

						if (HPplus >= 1)
						{
							if (HP == MaxHP)
							{
								printf("HPが満タンのようだ");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								continue;
							}
							else
							{

								printf("%sは回復薬を使った\n", name);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								HP += 150;

								if (MaxHP <= HP)
								{
									HP = MaxHP;
								}

								printf("%sのHPは%dになった", name, HP);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								HPplus -= 1;
							}						

						}
						else
						{
							printf("回復薬が足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}
						break;

					case 2:

						if (MPplus >= 1)
						{
							if (HP == MaxHP)
							{
								printf("MPが満タンのようだ");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								continue;
							}
							else
							{

								printf("%sは聖水を使った\n", name);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								MP += 25;

								if (MaxMP <= MP)
								{
									MP = MaxMP;
								}

								printf("%sのMPは%dになった", name, MP);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								MPplus -= 1;
							}
							
						}
						else
						{
							printf("聖水が足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}
						break;

					default:

						printf("選択肢の入力方式が間違っています。\n1～3で入力してください。\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

					case 3:
						//戦闘中のwhileまで戻る
						system("cls");
						continue;
						break;
					}

					break;

				case 3:		//逃げ確率

					if (EC == 1)	//攻撃
					{
						printf("スライムの体当たり\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("%sは逃げ出した\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						int BP = 1 + rand() % 100;
						if (BP <= 30)
						{
							Ex = old_Ex;
							Ey = old_Ey;
							px = old_px;
							py = old_py;
							E1 = 1;
							BD = 1;
						}
						else
						{
							printf("しかし、%sは逃げられなかった\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち
						}

					}
					else if (EC == 2)	//必殺技
					{
						printf("スライムのパワータックル\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("%sは逃げ出した\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						int BP = 1 + rand() % 100;
						if (BP <= 50)
						{
							Ex = old_Ex;
							Ey = old_Ey;
							px = old_px;
							py = old_py;
							E1 = 1;
							BD = 1;
						}
						else
						{
							printf("しかし、%sは逃げられなかった\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち
						}
					}
					else if (EC == 3)	//回避　or　様子を見る
					{
						printf("スライムは様子を見ている\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("%sは逃げ出した\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						Ex = old_Ex;	
						Ey = old_Ey;
						px = old_px;
						py = old_py;
						E1 = 1;
						BD = 1;
					}

					break;

				default:

					printf("選択肢の入力方式が間違っています。\n1～3で入力してください。\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち
					continue;
					break;
				}

				//敵選択肢行動
				if ((BD == 0)&&(SlimeH > 0))
				{
					if (EC == 1)
					{
						printf("スライムの体当たり\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						//戦闘ダメ計算
						Damage = Slime - VIT2;

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
					}
					else if (EC == 2)
					{
						printf("スライムのパワータックル\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						//戦闘ダメ計算
						Damage = Slime * 1.5 - VIT2;

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
					}
					else if (EC == 3)
					{
						printf("スライムは様子を見ている\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち
					}
				}
			}

			//敵HP0判定
			if (SlimeH <= 0)
			{
				E1 = 0;
				printf("スライムは倒れた\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち
			}

			//プレイヤーHP0判定
			if (HP <= 0) {

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
			BD = 0;
		}
		
		Sleep(3);
	}
	
/*******************************************************************************
* フロア2
*******************************************************************************/

	//値再設定
	loop = 0;
	px = 2;
	py = 2;
	E1 = 1;
	Ex = 4;
	Ey = 10;


	while (loop < 1)
	{
		Z = 0;
		H = 0;
		B = 0;

		printf("\nWASDを押してください\n");

		//プレイヤー
		old_px = px;	//移動前の位置を保存しておく
		old_py = py;

		//敵
		old_Ex = Ex;	//移動前の位置を保存しておく
		old_Ey = Ey;

		old_Ex1 = Ex1;	//移動前の位置を保存しておく
		old_Ey1 = Ey1;

		//key入力
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
			py--;
			A4 = 1;
			break;
		case 'A':
		case 'a':
			px--;
			A4 = 2;
			break;
		case 'S':
		case 's':
			py++;
			A4 = 3;
			break;
		case 'D':
		case 'd':
			px++;
			A4 = 4;
			break;
		case 'Z':
		case 'z':
			Z = 1;
			break;
		case 'H':
		case 'h':
			H = 1;
			break;
		case 'B':
		case 'b':
			B = 1;
			break;
		}

		//操作説明＆表記説明
		if (Z == 1)
		{
			system("cls");

			printf("\nW：上方向に移動\nA：左方向に移動\nS：下方向に移動\nD：右方向に移動\nH：回復薬を使用\nB：聖水を使用\n\nマップ内表記説明\n■：壁\nＥ：敵\n□：階段\n\nEnter：この画面を閉じる");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}

		//回復薬使用
		if (H == 1)
		{
			system("cls");

			printf("回復薬を使用しますか？\nY/N入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%c", &yesno);

			if ((yesno == 'Y') || (yesno == 'y'))
			{
				if (HPplus >= 1)
				{
					if (HP == MaxHP)
					{
						printf("HPが満タンのようだ");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						continue;
					}
					else
					{

						printf("%sは回復薬を使った\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						HP += 150;

						if (MaxHP <= HP)
						{
							HP = MaxHP;
						}

						printf("%sのHPは%dになった", name, HP);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						HPplus -= 1;
					}

				}
				else
				{
					printf("回復薬が足りないようだ…");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					continue;
				}

			}

		}

		//聖水使用
		if (B == 1)
		{
			system("cls");

			printf("聖水を使用しますか？\nY/N入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%c", &yesno);

			if ((yesno == 'Y') || (yesno == 'y'))
			{
				if (MPplus >= 1)
				{
					if (HP == MaxHP)
					{
						printf("MPが満タンのようだ");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						continue;
					}
					else
					{

						printf("%sは聖水を使った\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						MP += 25;

						if (MaxMP <= MP)
						{
							MP = MaxMP;
						}

						printf("%sのMPは%dになった", name, MP);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						MPplus -= 1;
					}

				}
				else
				{
					printf("聖水が足りないようだ…");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					continue;
				}

			}

		}

		//移動後の場所が障害物かチェックする　マップ内処理
		switch (field2[py][px])
		{
		case 1:		//壁だった
			px = old_px;	//移動前の場所に戻る
			py = old_py;
			break;
		case 3:

			printf("%sはアイアンソードを手に入れた\n",name);
			field2[py][px] = 0;	//手に入れたから0にしちゃう

			printf("%sの攻撃力が上がった\nEnterで進む\n",name);
			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			AT = IronSword;
			break;

		case 4:		//階段
			i = 0;

			px = old_px;	//移動前の場所に戻る
			py = old_py;

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
					loop += 1;
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
		}

		//プレイヤーと敵の衝突判定 トツゲキイノシシ
		if (py == Ey && px == Ex)			//敵
		{
			printf("敵が現れた\nEnterで進む\n");
			E1 = 2;
			Ex = -1;
			Ey = -1;

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}

		//プレイヤーと敵の衝突判定	ガーディアン
		if (py == Ey1 && px == Ex1)			//敵
		{
			printf("敵が現れた\nEnterで進む\n");
			E2 = 2;
			Ex1 = -1;
			Ey1 = -1;

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}

		//敵移動	トツゲキイノシシ
		if (E1 == 1)
		{
			int Ran = 1 + rand() % 100;
			Br++;
			if (Br == 5)
			{
				Br = 0;
			}
			else
			{
				if ((px < Ex) && (py < Ey))
				{

					if (Ran <= 50)
					{
						Ey--;
					}
					else if (Ran <= 100)
					{
						Ex--;
					}

				}
				else if ((px < Ex) && (py > Ey))
				{
					if (Ran <= 50)
					{
						Ey++;
					}
					else if (Ran <= 100)
					{
						Ex--;
					}
				}
				else if ((px > Ex) && (py < Ey))
				{
					if (Ran <= 50)
					{
						Ey--;
					}
					else if (Ran <= 100)
					{
						Ex++;
					}
				}
				else if ((px > Ex) && (py > Ey))
				{
					if (Ran <= 50)
					{
						Ey++;
					}
					else if (Ran <= 100)
					{
						Ex++;
					}
				}
				else
				{

				}

			}
			
			//敵衝突判定
			switch (field2[Ey][Ex])
			{
			case 1:		//壁だった
				Ex = old_Ex;	//移動前の場所に戻る
				Ey = old_Ey;
				break;
			case 3:		//はてな
				Ex = old_Ex;	//移動前の場所に戻る
				Ey = old_Ey;
				break;
			case 4:		//階段
				Ex = old_Ex;	//移動前の場所に戻る
				Ey = old_Ey;
				break;
			}
		}

		//敵移動	ガーディアン
		if (E2 == 1)
		{
			int Ran = 1 + rand() % 100;

			if (A4 == 1) //W
			{
				if (Ran <= 50)
				{
					Ey1--;
				}
				else if (Ran <= 60)
				{
					Ex1--;
				}
				else if (Ran <= 90)
				{
					Ey1++;
				}
				else if (Ran <= 100)
				{
					Ex1++;
				}
			}
			else if (A4 == 2) //A
			{
				if (Ran <= 10)
				{
					Ey1--;
				}
				else if (Ran <= 60)
				{
					Ex1--;
				}
				else if (Ran <= 70)
				{
					Ey1++;
				}
				else if (Ran <= 100)
				{
					Ex1++;
				}
			}
			else if (A4 == 3) //S
			{
				if (Ran <= 30)
				{
					Ey1--;
				}
				else if (Ran <= 40)
				{
					Ex1--;
				}
				else if (Ran <= 90)
				{
					Ey1++;
				}
				else if (Ran <= 100)
				{
					Ex1++;
				}
			}
			else if (A4 == 4) //D
			{
				if (Ran <= 10)
				{
					Ey1--;
				}
				else if (Ran <= 40)
				{
					Ex1--;
				}
				else if (Ran <= 50)
				{
					Ey1++;
				}
				else if (Ran <= 100)
				{
					Ex1++;
				}
			}
			else
			{

			}

			//敵衝突判定
			switch (field2[Ey1][Ex1])
			{
			case 1:		//壁だった
				Ex1 = old_Ex1;	//移動前の場所に戻る
				Ey1 = old_Ey1;
				break;
			case 3:		//はてな
				Ex1 = old_Ex;	//移動前の場所に戻る
				Ey1 = old_Ey;
				break;
			case 4:		//階段
				Ex1 = old_Ex1;	//移動前の場所に戻る
				Ey1 = old_Ey1;
				break;
			}
		}

		//マップ　と UI	
		if (loop == 0)
		{
			//マップ画面
			system("cls");
			int UI = 0;
			for (int y = 0; y < 15; y++)
			{
				for (int x = 0; x < 15; x++)
				{
					//　プレイヤー表示
					if ((x == px) && (y == py))
					{
						printf("Ｐ");
						continue;	//Pを表示してスキップ
					}

					if (E1 == 1)
					{
						if ((x == Ex) && (y == Ey))
						{
							printf("Ｅ");	//敵
							continue;						}
					}

					if (E2 == 1)
					{
						if ((x == Ex1) && (y == Ey1))
						{
							printf("Ｅ");	//敵
							continue;
						}
					}

					switch (field2[y][x])
					{
					case 0:
						printf("　");	//移動可能床
						break;

					case 1:
						printf("■");	//壁
						break;

					case 2:
						printf("＄");	//お金
						break;

					case 3:
						printf("？");	//今回は剣
						break;

					case 4:
						printf("□");	//階段
						break;
					case 5:
						printf("Ｓ");	//ショップ
						break;

					}
				}

				//　UI　右画面に表示
				if (UI == 0)
				{
					printf("　　HP:%d", HP);
				}
				else if (UI == 1)
				{
					printf("　　MP:%d", MP);
				}
				else if (UI == 3)
				{
					printf("　　回復薬:%d個", HPplus);
				}
				else if (UI == 4)
				{
					printf("　　聖　水:%d個", MPplus);
				}
				else if (UI == 6)
				{
					printf("　　Zボタンで操作説明&表記説明");
				}
				UI++;
				printf("\n");
			}
		}


		//プレイヤーと敵の衝突判定
		if (py == Ey && px == Ex)			//敵
		{
			printf("敵が現れた\nEnterで進む\n");
			E1 = 2;
			Ex = -1;
			Ey = -1;

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			//ここで戦闘画面に遷移 モンスターラッシュ２からプログラムを引っ張てくる
			//グローバル関数で呼びだし
			system("cls");


		}

		//プレイヤーと敵の衝突判定	ガーディアン
		if (py == Ey1 && px == Ex1)			//敵
		{
			printf("敵が現れた\nEnterで進む\n");
			E2 = 2;
			Ex1 = -1;
			Ey1 = -1;

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}



		//戦闘画面に遷移 トツゲキイノシシ
		if (E1 == 2)
		{
			system("cls");
			printf("トツゲキイノシシが現れた\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("\nトツゲキイノシシとの戦闘が始まった\nHP%dMP%d", HP,MP);
			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("\n\nトツゲキイノシシは走り回っている\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			system("cls");

			BD = 0;
			ad = 0;
			//トツゲキイノシシ戦闘プログラム
			while ((BoarH >= 0) && (HP >= 0) && (BD < 1))
			{
				//敵ディフェンス設定
				A = (BoarH / 5) + 1;
				int defense = 1 + rand() % A;
				int VIT2 = 1 + rand() % VIT;

				if (ad >= 1)
				{
					defense /= 2;
				}

				//敵の選択肢
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

				system("cls");

				printf("\nHP%dMP%d\n\n1攻撃\n\n2持ち物\n\n3逃げる\n\n選択肢入力：",HP,MP);
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)scanf("%d", &PC);

				system("cls");

				//プレイヤー選択肢行動
				switch (PC)
				{
				case 1:			//攻撃　と　MP攻撃　と魔法攻撃に分岐

					printf("\n1通常攻撃\n\n2火炎斬り(MP5消費)\n\n3フレームストーム(MP10消費)\n\n4戻る\n\n選択肢入力：");
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)scanf("%d", &num);

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
							BoarH -= Damage;

							printf("トツゲキイノシシに%dダメージ\n", Damage);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち	
						}
						else
						{
							printf("しかしトツゲキイノシシにダメージを与えられない\n");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち	
						}

						break;

					case 2:
						if (MP >= 5)
						{

							printf("%sの火炎斬り\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							//ダメージ計算
							Damage = AT * 1.5 - defense;

							if (Damage >= 0) {
								BoarH -= Damage;

								printf("トツゲキイノシシに%dダメージ\n", Damage);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}
							else
							{
								printf("しかしトツゲキイノシシにダメージを与えられない\n");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}

							MP -= 5;
						}
						else
						{
							printf("MPが足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}

						ad++;
						break;

					case 3:
						if (MP >= 10)
						{

							printf("%sのフレームストーム\n", name);

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
							else
							{
								printf("しかしトツゲキイノシシにダメージを与えられない\n");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}

							MP -= 10;
						}
						else
						{
							printf("MPが足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}

						ad++;
						break;

					default:

						printf("選択肢の入力方式が間違っています。\n1～4で入力してください。\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

					case 4:
						//戦闘中のwhileまで戻る
						system("cls");
						continue;
						break;
					}

					break;

				case 2:			//持ち物欄を開きたい

					system("cls");

					printf("\n1回復薬\n\n2聖水\n\n3戻る\n\n選択肢:");
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)scanf("%d", &num);

					switch (num)
					{
					case 1:

						if (HPplus >= 1)
						{
							if (HP == MaxHP)
							{
								printf("HPが満タンのようだ");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								continue;
							}
							else
							{

								printf("%sは回復薬を使った\n", name);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								HP += 150;

								if (MaxHP <= HP)
								{
									HP = MaxHP;
								}

								printf("%sのHPは%dになった", name, HP);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								HPplus -= 1;
							}

						}
						else
						{
							printf("回復薬が足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}
						break;

					case 2:

						if (MPplus >= 1)
						{
							if (HP == MaxHP)
							{
								printf("MPが満タンのようだ");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								continue;
							}
							else
							{

								printf("%sは聖水を使った\n", name);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								MP += 25;

								if (MaxMP <= MP)
								{
									MP = MaxMP;
								}

								printf("%sのMPは%dになった", name, MP);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								MPplus -= 1;
							}

						}
						else
						{
							printf("聖水が足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}
						break;

					default:

						printf("選択肢の入力方式が間違っています。\n1～3で入力してください。\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

					case 3:
						//戦闘中のwhileまで戻る
						system("cls");
						continue;
						break;
					}

					break;

				case 3:		//逃げ確率

					if (EC == 1)	//攻撃
					{
						printf("トツゲキイノシシの突進\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("%sは逃げ出した\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						int BP = 1 + rand() % 100;
						if (BP <= 30)
						{
							Ex = old_Ex;
							Ey = old_Ey;
							px = old_px;
							py = old_py;
							E1 = 1;
							BD = 1;
						}
						else
						{
							printf("しかし、%sは逃げられなかった\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち
						}

					}
					else if (EC == 2)	//必殺技
					{
						printf("トツゲキイノシシの猪突猛進\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("%sは逃げ出した\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						int BP = 1 + rand() % 100;
						if (BP <= 10)
						{
							Ex = old_Ex;
							Ey = old_Ey;
							px = old_px;
							py = old_py;
							E1 = 1;
							BD = 1;
						}
						else
						{
							printf("しかし、%sは逃げられなかった\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち
						}
					}
					else if (EC == 3)	//回避　or　様子を見る
					{
						printf("トツゲキイノシシは走り回っている\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("%sは逃げ出した\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち
						int BP = 1 + rand() % 100;
						if (BP <= 50)
						{
							Ex = old_Ex;
							Ey = old_Ey;
							px = old_px;
							py = old_py;
							E1 = 1;
							BD = 1;
						}
						else
						{
							printf("しかし、%sは逃げられなかった\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち
						}
					}

					break;

				default:

					printf("選択肢の入力方式が間違っています。\n1～3で入力してください。\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち
					continue;
					break;
				}

				//敵選択肢行動
				if ((BD == 0) && (BoarH > 0))
				{
					if (EC == 1)
					{
						printf("トツゲキイノシシの突進\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						//戦闘ダメ計算
						Damage =Boar - VIT2;

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
					}
					else if (EC == 2)
					{
						printf("トツゲキイノシシの猪突猛進\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						//戦闘ダメ計算
						Damage = Boar * 1.5 - VIT2;

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
					}
					else if (EC == 3)
					{
						printf("トツゲキイノシシは走り回っている\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち
					}
				}

				if ((BD == 0) && (BoarH > 0) && (ad == 1))
				{
					printf("トツゲキイノシシは火炎攻撃によって弱っている\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち
				}
			}

			//敵HP0判定
			if (BoarH <= 0)
			{
				E1 = 0;
				printf("トツゲキイノシシは倒れた\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち
			}

			//プレイヤーHP0判定
			if (HP <= 0) {

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
			BD = 0;
		}

		//戦闘画面に遷移 ガーディアン
		if (E2 == 2)
		{
			system("cls");
			printf("ガーディアンが現れた\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("\n\nガーディアン「生体認証失敗…侵入者、捕獲対象、ここから立ち去らない場合、収容プログラム実行します」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("\n\n%s「っ?!、ガーディアン…古代に侵入者から城や金庫などを守るために使われていたロストテクノロジー…」\n",name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
			
			printf("\n\n%s「この先にお宝が存在する確率が上がったな！」\n",name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("\nガーディアンとの戦闘が始まった\nHP%d", HP);
			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			system("cls");

			BD = 0;
			ad = 0;
			GD  = 20;
			//ガーディアン戦闘プログラム
			while ((GDH >= 0) && (HP >= 0) && (BD < 1))
			{
				//敵ディフェンス設定
				A = (GDH / 5) + 1;
				int defense = 1 + rand() % A;
				int VIT2 = 1 + rand() % VIT;

				if (ad >= 1)
				{
					GD += 10;
					ad = 0;
				}

				//敵の選択肢
				int Ran = 1 + rand() % 100;
				if (Ran <= 60)
				{
					//攻撃
					EC = 1;
				}
				else if (Ran <= 90)
				{
					//必殺技
					EC = 2;
				}
				else if (Ran <= 100)
				{
					//攻撃プラスシステム
					EC = 3;
				}

				system("cls");

				printf("\nHP%dMP%d\n\n1攻撃\n\n2持ち物\n\n3逃げる\n\n選択肢入力：",HP,MP);
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)scanf("%d", &PC);

				system("cls");

				//プレイヤー選択肢行動
				switch (PC)
				{
				case 1:			//攻撃　と　MP攻撃　と魔法攻撃に分岐

					printf("\n1通常攻撃\n\n2火炎斬り(MP5消費)\n\n3フレームストーム(MP10消費)\n\n4戻る\n\n選択肢入力：");
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)scanf("%d", &num);

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
							GDH -= Damage;

							printf("ガーディアンに%dダメージ\n", Damage);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち	
						}
						else
						{
							printf("しかしガーディアンにダメージを与えられない\n");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち	
						}

						break;

					case 2:
						if (MP >= 5)
						{

							printf("%sの火炎斬り\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							//ダメージ計算
							Damage = AT * 1.5 - defense;

							if (Damage >= 0) {
								GDH -= Damage;

								printf("ガーディアンに%dダメージ\n", Damage);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}
							else
							{
								printf("しかしガーディアンにダメージを与えられない\n");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}

							MP -= 5;
						}
						else
						{
							printf("MPが足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}
						break;

					case 3:
						if (MP >= 10)
						{

							printf("%sのフレームストーム\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							//ダメージ計算
							Damage = AT * 2 - defense;

							if (Damage >= 0) {
								GDH -= Damage;

								printf("ガーディアンに%dダメージ\n", Damage);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}
							else
							{
								printf("しかしガーディアンにダメージを与えられない\n");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}

							MP -= 10;
						}
						else
						{
							printf("MPが足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}
						break;

					default:

						printf("選択肢の入力方式が間違っています。\n1～4で入力してください。\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

					case 4:
						//戦闘中のwhileまで戻る
						system("cls");
						continue;
						break;
					}

					break;

				case 2:			//持ち物欄を開きたい

					system("cls");

					printf("\n1回復薬\n\n2聖水\n\n3戻る\n\n選択肢:");
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)scanf("%d", &num);

					switch (num)
					{
					case 1:

						if (HPplus >= 1)
						{
							if (HP == MaxHP)
							{
								printf("HPが満タンのようだ");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								continue;
							}
							else
							{

								printf("%sは回復薬を使った\n", name);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								HP += 150;

								if (MaxHP <= HP)
								{
									HP = MaxHP;
								}

								printf("%sのHPは%dになった", name, HP);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								HPplus -= 1;
							}

						}
						else
						{
							printf("回復薬が足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}
						break;

					case 2:

						if (MPplus >= 1)
						{
							if (HP == MaxHP)
							{
								printf("MPが満タンのようだ");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								continue;
							}
							else
							{

								printf("%sは聖水を使った\n", name);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								MP += 25;

								if (MaxMP <= MP)
								{
									MP = MaxMP;
								}

								printf("%sのMPは%dになった", name, MP);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								MPplus -= 1;
							}

						}
						else
						{
							printf("聖水が足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}
						break;

					default:

						printf("選択肢の入力方式が間違っています。\n1～3で入力してください。\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

					case 3:
						//戦闘中のwhileまで戻る
						system("cls");
						continue;
						break;
					}

					break;

				case 3:		//逃げ確率

					if (EC == 1)	//攻撃
					{
						printf("ガーディアンのロッドスイング\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("%sは逃げ出した\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						int BP = 1 + rand() % 100;
						if (BP <= 20)
						{
							Ex1 = old_Ex1;
							Ey1 = old_Ey1;
							px = old_px;
							py = old_py;
							E2 = 1;
							BD = 1;
						}
						else
						{
							printf("しかし、%sは逃げられなかった\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち
						}

					}
					else if (EC == 2)	//必殺技
					{
						printf("ガーディアンのターボガトリング\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("%sは逃げ出した\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						int BP = 1 + rand() % 100;
						if (BP <= 20)
						{
							Ex1 = old_Ex1;
							Ey1 = old_Ey1;
							px = old_px;
							py = old_py;
							E2 = 1;
							BD = 1;
						}
						else
						{
							printf("しかし、%sは逃げられなかった\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち
						}
					}
					else if (EC == 3)	//回避　or　様子を見る
					{
						printf("ガーディアンのクリーンナップ\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("%sは逃げ出した\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち
						int BP = 1 + rand() % 100;
						if (BP <= 50)
						{
							Ex1 = old_Ex1;
							Ey1 = old_Ey1;
							px = old_px;
							py = old_py;
							E2 = 1;
							BD = 1;
						}
						else
						{
							printf("しかし、%sは逃げられなかった\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち
						}
					}

					break;

				default:

					printf("選択肢の入力方式が間違っています。\n1～3で入力してください。\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち
					continue;
					break;
				}

				//敵選択肢行動
				if ((BD == 0) && (GDH > 0))
				{
					if (EC == 1)
					{
						printf("ガーディアンのロッドスイング\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						//戦闘ダメ計算
						Damage = GD - VIT2;

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
					}
					else if (EC == 2)
					{
						printf("ガーディアンのターボガトリング\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						//戦闘ダメ計算
						Damage = GD * 1.5 - VIT2;

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
					}
					else if (EC == 3)
					{
						printf("ガーディアンのクリーンナップ\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						ad++;
					}
				}

				if ((BD == 0) && (GDH > 0) && (ad == 1))
				{
					printf("ガーディアンは攻撃システムを最適化した\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち
				}
			}

			//敵HP0判定
			if (GDH <= 0)
			{
				E2 = 0;
				printf("ガーディアンは倒れた\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ガーディアンは聖水と鉄の防具を持っていたようだ\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("%sは聖水と鉄の防具を拾った\n",name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				MPplus += 1;
				VIT = IronArmor;

				printf("%sの防御力が上がった\n", name);
				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				GDB++;
			}

			//プレイヤーHP0判定
			if (HP <= 0) {

				printf("勇者%sは倒れてしまった…\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ガーディアン「捕獲完了！」\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				GameOver();

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				exit(-1);
			}
			BD = 0;
		}

		Sleep(10);
	}

/*******************************************************************************
* フロア3 最終フロア
*******************************************************************************/

//値再設定
	loop = 0;
	px = 17;
	py = 7;
	E1 = 1;
	E2 = 1;

	Ex = 4;			//ドローン
	Ey = 16;

	Ex1 = 15;		//ゴーレム
	Ey1 = 12;

	Ex2 = 10;		//ドローン２
	Ey2 = 3;

	Ex3 = 7;		//ドローン３
	Ey3 = 12;
	Br = 0;


	while (loop < 1)
	{
		Z = 0;
		H = 0;
		B = 0;
		A4 = 0;

		if (Br == 8)
		{
			Br = 0;
		}
		Br++;

		printf("\nWASDを押してください\n");

		//プレイヤー
		old_px = px;	//移動前の位置を保存しておく
		old_py = py;

		//敵
		old_Ex = Ex;	//移動前の位置を保存しておく
		old_Ey = Ey;

		old_Ex1 = Ex1;	//移動前の位置を保存しておく
		old_Ey1 = Ey1;

		old_Ex2 = Ex2;	//移動前の位置を保存しておく
		old_Ey2 = Ey2;

		old_Ex3 = Ex3;	//移動前の位置を保存しておく
		old_Ey3 = Ey3;

		//key入力
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
			py--;
			break;
		case 'A':
		case 'a':
			px--;
			break;
		case 'S':
		case 's':
			py++;
			break;
		case 'D':
		case 'd':
			px++;
			break;
		case 'Z':
		case 'z':
			Z = 1;
			break;
		case 'H':
		case 'h':
			H = 1;
			break;
		case 'B':
		case 'b':
			B = 1;
			break;
		}

		//操作説明＆表記説明
		if (Z == 1)
		{
			system("cls");

			printf("\nW：上方向に移動\nA：左方向に移動\nS：下方向に移動\nD：右方向に移動\nH：回復薬を使用\nB：聖水を使用\n\nマップ内表記説明\n■：壁\nＥ：敵\n□：階段\nEnter：この画面を閉じる");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}

		//回復薬使用
		if (H == 1)
		{
			system("cls");

			printf("回復薬を使用しますか？\nY/N入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%c", &yesno);

			if ((yesno == 'Y') || (yesno == 'y'))
			{
				if (HPplus >= 1)
				{
					if (HP == MaxHP)
					{
						printf("HPが満タンのようだ");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						continue;
					}
					else
					{

						printf("%sは回復薬を使った\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						HP += 150;

						if (MaxHP <= HP)
						{
							HP = MaxHP;
						}

						printf("%sのHPは%dになった", name, HP);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						HPplus -= 1;
					}

				}
				else
				{
					printf("回復薬が足りないようだ…");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					continue;
				}

			}

		}

		//聖水使用
		if (B == 1)
		{
			system("cls");

			printf("聖水を使用しますか？\nY/N入力：");
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)scanf("%c", &yesno);

			if ((yesno == 'Y') || (yesno == 'y'))
			{
				if (MPplus >= 1)
				{
					if (MP == MaxHP)
					{
						printf("MPが満タンのようだ");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						continue;
					}
					else
					{

						printf("%sは聖水を使った\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						MP += 25;

						if (MaxMP <= MP)
						{
							MP = MaxMP;
						}

						printf("%sのMPは%dになった", name, MP);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						MPplus -= 1;
					}

				}
				else
				{
					printf("聖水が足りないようだ…");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					continue;
				}

			}

		}


		//移動後の場所が障害物かチェックする　マップ内処理
		switch (field3[py][px])
		{
		case 1:		//壁だった
			px = old_px;	//移動前の場所に戻る
			py = old_py;
			break;

		case 3:		// 鋼の剣

			printf("%sは鋼の剣を手に入れた\n", name);
			field3[py][px] = 0;	//手に入れたから0にしちゃう

			printf("%sの攻撃力が上がった\nEnterで進む\n", name);
			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			AT = SteelSword;

			break;
		case 6:		//お宝

			//次のフロアへ
			system("cls");

			loop += 1;
			break;
		}


		//プレイヤーと敵の衝突判定 ドローン
		if (py == Ey && px == Ex)			//敵
		{
			printf("敵が現れた\nEnterで進む\n");
			E1 = 2;
			Ex = -1;
			Ey = -1;

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}

		//プレイヤーと敵の衝突判定	ゴーレム
		if (py == Ey1 && px == Ex1)			//敵
		{
			printf("敵が現れた\nEnterで進む\n");
			E2 = 2;
			Ex1 = -1;
			Ey1 = -1;

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}

		//プレイヤーと敵の衝突判定	ドローン２
		if (py == Ey2 && px == Ex2)			//敵
		{
			printf("敵が現れた\nEnterで進む\n");
			E3 = 2;
			Ex2 = -1;
			Ey2 = -1;

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}

		//プレイヤーと敵の衝突判定	ドローン3
		if (py == Ey3 && px == Ex3)			//敵
		{
			printf("敵が現れた\nEnterで進む\n");
			E4 = 2;
			Ex3 = -1;
			Ey3 = -1;

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}

		//プレイヤーと敵の衝突判定	イライザ
		if (py == Ey4 && px == Ex4)			//敵
		{
			printf("敵が現れた\nEnterで進む\n");
			E5 = 2;
			Ex4 = -1;
			Ey4 = -1;

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}

		//敵移動	ドローン
		if (E1 == 1)
		{
			if (Br == 1)
			{
				Ey--;
			}
			else if (Br == 2)
			{
				Ey--;
			}
			else if (Br == 3)
			{
				Ex++;
			}
			else if (Br == 4)
			{
				Ex++;
			}
			else if (Br == 5)
			{
				Ey++;
			}
			else if (Br == 6)
			{
				Ey++;
			}
			else if (Br == 7)
			{
				Ex--;
			}
			else if (Br == 8)
			{
				Ex--;
			}

			//敵衝突判定
			switch (field3[Ey][Ex])
			{
			case 1:		//壁だった
				Ex = old_Ex;	//移動前の場所に戻る
				Ey = old_Ey;
				break;
			case 3:		//はてな
				Ex = old_Ex;	//移動前の場所に戻る
				Ey = old_Ey;
				break;
			case 4:		//階段
				Ex = old_Ex;	//移動前の場所に戻る
				Ey = old_Ey;
				break;
			}
		}

		//敵移動	ゴーレム
		if (E2 == 1)
		{
			
			if (py == Ey1)
			{
				
			}
			else if (py > Ey1)
			{
				Ey1++;
			}
			else
			{
				Ey1--;
			}

			//敵衝突判定
			switch (field3[Ey1][Ex1])
			{
			case 1:		//壁だった
				Ex1 = old_Ex1;	//移動前の場所に戻る
				Ey1 = old_Ey1;
				break;
			case 3:		//はてな
				Ex1 = old_Ex;	//移動前の場所に戻る
				Ey1 = old_Ey;
				break;
			case 4:		//階段
				Ex1 = old_Ex1;	//移動前の場所に戻る
				Ey1 = old_Ey1;
				break;
			}
		}


		//敵移動	ドローン2
		if (E3 == 1)
		{
			if (Br == 1)
			{
				Ey2--;
			}
			else if (Br == 2)
			{
				Ey2--;
			}
			else if (Br == 3)
			{
				Ex2++;
			}
			else if (Br == 4)
			{
				Ex2++;
			}
			else if (Br == 5)
			{
				Ey2++;
			}
			else if (Br == 6)
			{
				Ey2++;
			}
			else if (Br == 7)
			{
				Ex2--;
			}
			else if (Br == 8)
			{
				Ex2--;
			}

			//敵衝突判定
			switch (field3[Ey2][Ex2])
			{
			case 1:		//壁だった
				Ex2 = old_Ex2;	//移動前の場所に戻る
				Ey2 = old_Ey2;
				break;
			case 3:		//はてな
				Ex2 = old_Ex2;	//移動前の場所に戻る
				Ey2 = old_Ey2;
				break;
			case 4:		//階段
				Ex2 = old_Ex2;	//移動前の場所に戻る
				Ey2 = old_Ey2;
				break;
			}
		}

		//敵移動	ドローン3
		if (E4 == 1)
		{
			if (Br == 1)
			{
				Ey3--;
			}
			else if (Br == 2)
			{
				Ey3--;
			}
			else if (Br == 3)
			{
				Ex3++;
			}
			else if (Br == 4)
			{
				Ex3++;
			}
			else if (Br == 5)
			{
				Ey3++;
			}
			else if (Br == 6)
			{
				Ey3++;
			}
			else if (Br == 7)
			{
				Ex3--;
			}
			else if (Br == 8)
			{
				Ex3--;
			}

			//敵衝突判定
			switch (field3[Ey3][Ex3])
			{
			case 1:		//壁だった
				Ex3 = old_Ex3;	//移動前の場所に戻る
				Ey3 = old_Ey3;
				break;
			case 3:		//はてな
				Ex3 = old_Ex3;	//移動前の場所に戻る
				Ey3 = old_Ey3;
				break;
			case 4:		//階段
				Ex3 = old_Ex3;	//移動前の場所に戻る
				Ey3 = old_Ey3;
				break;
			}
		}



		//マップ　と UI	
		if (loop == 0)
		{
			//マップ画面
			system("cls");
			int UI = 0;
			for (int y = 0; y < 20; y++)
			{
				for (int x = 0; x < 20; x++)
				{
					//　プレイヤー表示
					if ((x == px) && (y == py))
					{
						printf("Ｐ");
						continue;	//Pを表示してスキップ
					}

					if (E1 == 1)
					{
						if ((x == Ex) && (y == Ey))
						{
							printf("Ｅ");	//敵
							continue;
						}
					}

					if (E2 == 1)
					{
						if ((x == Ex1) && (y == Ey1))
						{
							printf("Ｅ");	//敵
							continue;
						}
					}

					if (E3 == 1)
					{
						if ((x == Ex2) && (y == Ey2))
						{
							printf("Ｅ");	//敵
							continue;
						}
					}

					if (E4 == 1)
					{
						if ((x == Ex3) && (y == Ey3))
						{
							printf("Ｅ");	//敵
							continue;
						}
					}

					if (E5 == 1)
					{
						if ((x == Ex4) && (y == Ey4))
						{
							printf("Ｅ");	//敵
							continue;
						}
					}

					switch (field3[y][x])
					{
					case 0:
						printf("　");	//移動可能床
						break;

					case 1:
						printf("■");	//壁
						break;

					case 3:
						printf("？");	//アイテム　今回は鋼の剣
						break;

					case 4:
						printf("□");	//階段
						break;

					case 5:
						printf("Ｅ");	//イライザ
						break;

					case 6:
						printf("Ｇ");	//お宝
						break;
					}
				}

				//　UI　右画面に表示
				if (UI == 0)
				{
					printf("　　HP:%d", HP);
				}
				else if (UI == 1)
				{
					printf("　　MP:%d", MP);
				}
				else if (UI == 3)
				{
					printf("　　回復薬:%d個", HPplus);
				}
				else if (UI == 4)
				{
					printf("　　聖　水:%d個", MPplus);
				}
				else if (UI == 6)
				{
					printf("　　Zボタンで操作説明&表記説明");
				}
				UI++;
				printf("\n");
			}
		}


		//プレイヤーと敵の衝突判定　ドローン
		if (py == Ey && px == Ex)			//敵
		{
			printf("敵が現れた\nEnterで進む\n");
			E1 = 2;
			Ex = -1;
			Ey = -1;

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			//ここで戦闘画面に遷移 モンスターラッシュ２からプログラムを引っ張てくる
			//グローバル関数で呼びだし
			system("cls");


		}

		//プレイヤーと敵の衝突判定	ゴーレム
		if (py == Ey1 && px == Ex1)			//敵
		{
			printf("敵が現れた\nEnterで進む\n");
			E2 = 2;
			Ex1 = -1;
			Ey1 = -1;

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}

		//プレイヤーと敵の衝突判定	ドローン２
		if (py == Ey2 && px == Ex2)			//敵
		{
			printf("敵が現れた\nEnterで進む\n");
			E3 = 2;
			Ex2 = -1;
			Ey2 = -1;

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}

		//プレイヤーと敵の衝突判定	ドローン3
		if (py == Ey3 && px == Ex3)			//敵
		{
			printf("敵が現れた\nEnterで進む\n");
			E4 = 2;
			Ex3 = -1;
			Ey3 = -1;

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}

		//プレイヤーと敵の衝突判定	イライザ
		if (py == Ey4 && px == Ex4)			//敵
		{
			printf("敵が現れた\nEnterで進む\n");
			E5 = 2;
			Ex4 = -1;
			Ey4 = -1;

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち
		}



		//戦闘画面に遷移 ドローン
		if (E1 == 2)
		{
			system("cls");
			printf("ドローンが現れた\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("\nドローンとの戦闘が始まった\nHP%dMP%d", HP,MP);
			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("\n\nドローンはふわふわと浮いている\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			system("cls");

			BD = 0;
			//ドローン戦闘プログラム
			while ((DrH >= 0) && (HP >= 0) && (BD < 1))
			{
				//ドローン回避率
				int defense = 1 + rand() % 100;
				int VIT2 = 1 + rand() % VIT;

				//敵の選択肢
				int Ran = 1 + rand() % 100;
				if (Ran <= 50)
				{
					//攻撃
					EC = 1;
				}
				else if (Ran <= 90)
				{
					//必殺技
					EC = 2;
				}
				else if (Ran <= 100)
				{
					//回避、回復
					EC = 3;
				}

				if (EC == 3)
				{
					defense += 30;
				}

				system("cls");

				printf("\nHP%dMP%d\n\n1攻撃\n\n2持ち物\n\n3逃げる\n\n選択肢入力：",HP,MP);
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)scanf("%d", &PC);

				system("cls");

				//プレイヤー選択肢行動
				switch (PC)
				{
				case 1:			//攻撃　と　MP攻撃　と魔法攻撃に分岐

					printf("\n1通常攻撃\n\n2火炎斬り(MP5消費)\n\n3フレームストーム(MP10消費)\n\n4戻る\n\n選択肢入力：");
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)scanf("%d", &num);

					switch (num)
					{
					case 1:

						printf("%sの攻撃\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						//ダメージ計算
						Damage = AT;

						if (defense >= 10)
						{
							DrH -= Damage;

							printf("ドローンに%dダメージ\n", Damage);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち	
						}
						else
						{
							printf("しかしドローンに攻撃を避けられた\n");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち	
						}

						break;

					case 2:
						if (MP >= 5)
						{

							printf("%sの火炎斬り\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							//ダメージ計算
							Damage = AT * 1.5;

							if (defense >= 30) {
								DrH -= Damage;

								printf("ドローンに%dダメージ\n", Damage);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}
							else
							{
								printf("しかしドローンに攻撃を避けられた\n");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}

							MP -= 5;
						}
						else
						{
							printf("MPが足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}

						ad++;
						break;

					case 3:
						if (MP >= 10)
						{

							printf("%sのフレームストーム\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							//ダメージ計算
							Damage = AT * 2;

							if (defense >= 50) {
								DrH -= Damage;

								printf("ドローンに%dダメージ\n", Damage);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}
							else
							{
								printf("しかしドローンに攻撃を避けられた\n");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}

							MP -= 10;
						}
						else
						{
							printf("MPが足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}

						ad++;
						break;

					default:

						printf("選択肢の入力方式が間違っています。\n1～4で入力してください。\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

					case 4:
						//戦闘中のwhileまで戻る
						system("cls");
						continue;
						break;
					}

					break;

				case 2:			//持ち物欄を開きたい

					system("cls");

					printf("\n1回復薬\n\n2聖水\n\n3戻る\n\n選択肢:");
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)scanf("%d", &num);

					switch (num)
					{
					case 1:

						if (HPplus >= 1)
						{
							if (HP == MaxHP)
							{
								printf("HPが満タンのようだ");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								continue;
							}
							else
							{

								printf("%sは回復薬を使った\n", name);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								HP += 150;

								if (MaxHP <= HP)
								{
									HP = MaxHP;
								}

								printf("%sのHPは%dになった", name, HP);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								HPplus -= 1;
							}

						}
						else
						{
							printf("回復薬が足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}
						break;

					case 2:

						if (MPplus >= 1)
						{
							if (HP == MaxHP)
							{
								printf("MPが満タンのようだ");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								continue;
							}
							else
							{

								printf("%sは聖水を使った\n", name);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								MP += 25;

								if (MaxMP <= MP)
								{
									MP = MaxMP;
								}

								printf("%sのMPは%dになった", name, MP);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								MPplus -= 1;
							}

						}
						else
						{
							printf("聖水が足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}
						break;

					default:

						printf("選択肢の入力方式が間違っています。\n1～3で入力してください。\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

					case 3:
						//戦闘中のwhileまで戻る
						system("cls");
						continue;
						break;
					}

					break;

				case 3:		//逃げ確率

					if (EC == 1)	//攻撃
					{
						printf("ドローンの誘導ミサイル\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("%sは逃げ出した\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						int BP = 1 + rand() % 100;
						if (BP <= 10)
						{
							Ex = old_Ex;
							Ey = old_Ey;
							px = old_px;
							py = old_py;
							E1 = 1;
							BD = 1;
						}
						else
						{
							printf("しかし、%sは逃げられなかった\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち
						}

					}
					else if (EC == 2)	//必殺技
					{
						printf("ドローンのレーザービーム\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("%sは逃げ出した\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						int BP = 1 + rand() % 100;
						if (BP <= 50)
						{
							Ex = old_Ex;
							Ey = old_Ey;
							px = old_px;
							py = old_py;
							E1 = 1;
							BD = 1;
						}
						else
						{
							printf("しかし、%sは逃げられなかった\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち
						}
					}
					else if (EC == 3)	//回避して回復
					{
						printf("ドローンの修繕システム\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("%sは逃げ出した\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち
						int BP = 1 + rand() % 100;
						if (BP <= 100)
						{
							Ex = old_Ex;
							Ey = old_Ey;
							px = old_px;
							py = old_py;
							E1 = 1;
							BD = 1;
						}
						else
						{
							printf("しかし、%sは逃げられなかった\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち
						}
					}

					break;

				default:

					printf("選択肢の入力方式が間違っています。\n1～3で入力してください。\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち
					continue;
					break;
				}

				//敵選択肢行動
				if ((BD == 0) && (DrH > 0))
				{
					if (EC == 1)
					{
						printf("ドローンの誘導ミサイル\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						//戦闘ダメ計算
						Damage = Dr - VIT2;

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
					}
					else if (EC == 2)
					{
						printf("ドローンのレーザービーム\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						//戦闘ダメ計算
						Damage = Dr * 1.5 - VIT2;

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
					}
					else if (EC == 3)
					{
						printf("ドローンの修繕システム\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						DrH += 50;
					}
				}

			}

			//敵HP0判定
			if (DrH <= 0)
			{
				E1 = 0;
				printf("ドローンは墜落した\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ドローンは回復薬と聖水を落とした\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				HPplus++;
				MPplus++;

				DRB++;
			}

			//プレイヤーHP0判定
			if (HP <= 0) {

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
			BD = 0;
		}

		//戦闘画面に遷移 ゴーレム
		if (E2 == 2)
		{
			system("cls");
			printf("ゴーレムが現れた\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("\n\nゴーレム「敵発見！ここから先は通さない」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("\n\n%s「鉄でできた、ガーディアンか？人間の3倍くらいの大きさはあるぞ…」\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("\n\n%s「こんな化け物がいたら一番奥にはお目当てのお宝よりもすごいものがありそうだな」\n", name);

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("\nゴーレムとの戦闘が始まった\nHP%d", HP);
			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			system("cls");

			BD = 0;
			ad = 0;
			//ゴーレム戦闘プログラム
			while ((GolemH >= 0) && (HP >= 0) && (BD < 1))
			{
				//敵ディフェンス設定
				A = (GolemH / 20) + 1;
				int defense = 1 + rand() % A;
				int VIT2 = 1 + rand() % VIT;

				//敵の選択肢
				int Ran = 1 + rand() % 100;
				if (Ran <= 70)
				{
					//攻撃
					EC = 1;
				}
				else if (Ran <= 100)
				{
					//必殺技
					EC = 2;
				}

				system("cls");

				printf("\nHP%dMP%d\n\n1攻撃\n\n2持ち物\n\n3逃げる\n\n選択肢入力：",HP,MP);
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)scanf("%d", &PC);

				system("cls");

				//プレイヤー選択肢行動
				switch (PC)
				{
				case 1:			//攻撃　と　MP攻撃　と魔法攻撃に分岐

					printf("\n1通常攻撃\n\n2火炎斬り(MP5消費)\n\n3フレームストーム(MP10消費)\n\n4戻る\n\n選択肢入力：");
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)scanf("%d", &num);

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
							GolemH -= Damage;

							printf("ゴーレムに%dダメージ\n", Damage);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち	
						}
						else
						{
							printf("しかしゴーレムにダメージを与えられない\n");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち	

						}

						break;

					case 2:
						if (MP >= 5)
						{

							printf("%sの火炎斬り\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							//ダメージ計算
							Damage = AT * 1.5 - defense;

							if (Damage >= 0) {
								GolemH -= Damage;

								printf("ゴーレムに%dダメージ\n", Damage);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}
							else
							{
								printf("しかしゴーレムにダメージを与えられない\n");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}

							MP -= 5;
						}
						else
						{
							printf("MPが足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}
						break;

					case 3:
						if (MP >= 10)
						{

							printf("%sのフレームストーム\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							//ダメージ計算
							Damage = AT * 2 - defense;

							if (Damage >= 0) {
								GolemH -= Damage;

								printf("ゴーレムに%dダメージ\n", Damage);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}
							else
							{
								printf("しかしゴーレムにダメージを与えられない\n");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}

							MP -= 10;
						}
						else
						{
							printf("MPが足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}
						break;

					default:

						printf("選択肢の入力方式が間違っています。\n1～4で入力してください。\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

					case 4:
						//戦闘中のwhileまで戻る
						system("cls");
						continue;
						break;
					}

					break;

				case 2:			//持ち物欄を開きたい

					system("cls");

					printf("\n1回復薬\n\n2聖水\n\n3戻る\n\n選択肢:");
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)scanf("%d", &num);

					switch (num)
					{
					case 1:

						if (HPplus >= 1)
						{
							if (HP == MaxHP)
							{
								printf("HPが満タンのようだ");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								continue;
							}
							else
							{

								printf("%sは回復薬を使った\n", name);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								HP += 150;

								if (MaxHP <= HP)
								{
									HP = MaxHP;
								}

								printf("%sのHPは%dになった", name, HP);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								HPplus--;
							}

						}
						else
						{
							printf("回復薬が足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}
						break;

					case 2:

						if (MPplus >= 1)
						{
							if (HP == MaxHP)
							{
								printf("MPが満タンのようだ");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								continue;
							}
							else
							{

								printf("%sは聖水を使った\n", name);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								MP += 25;

								if (MaxMP <= MP)
								{
									MP = MaxMP;
								}

								printf("%sのMPは%dになった", name, MP);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								MPplus--;
							}

						}
						else
						{
							printf("聖水が足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}
						break;

					default:

						printf("選択肢の入力方式が間違っています。\n1～3で入力してください。\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

					case 3:
						//戦闘中のwhileまで戻る
						system("cls");
						continue;
						break;
					}

					break;

				case 3:		//逃げ確率

					if (EC == 1)	//攻撃
					{
						printf("ゴーレムのアイアンパンチ\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("%sは逃げ出した\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						int BP = 1 + rand() % 100;
						if (BP <= 50)
						{
							Ex1 = old_Ex1;
							Ey1 = old_Ey1;
							px = old_px;
							py = old_py;
							E2 = 1;
							BD = 1;
						}
						else
						{
							printf("しかし、%sは逃げられなかった\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち
						}

					}
					else if (EC == 2)	//必殺技
					{
						printf("ゴーレムの岩砕き\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("%sは逃げ出した\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						int BP = 1 + rand() % 100;
						if (BP <= 70)
						{
							Ex1 = old_Ex1;
							Ey1 = old_Ey1;
							px = old_px;
							py = old_py;
							E2 = 1;
							BD = 1;
						}
						else
						{
							printf("しかし、%sは逃げられなかった\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち
						}
					}
					else
					{
						printf("しかし、%sは逃げられなかった\n", name);
						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち
					}
					
					break;

				default:

					printf("選択肢の入力方式が間違っています。\n1～3で入力してください。\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち
					continue;
					break;
				}

				//敵選択肢行動
				if ((BD == 0) && (GolemH > 0))
				{
					if (EC == 1)
					{
						printf("ゴーレムのアイアンパンチ\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						//戦闘ダメ計算
						Damage = Golem - VIT2;

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
					}
					else if (EC == 2)
					{
						printf("ゴーレムの岩砕き\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						//戦闘ダメ計算
						Damage = Golem * 1.5 - VIT2;

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
					}
				}

			}

			//敵HP0判定
			if (GolemH <= 0)
			{
				E2 = 0;
				printf("ゴーレムは崩れ落ちた\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ゴーレムは鋼の鎧を持っていたようだ\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("%sは鋼の鎧を拾った\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				VIT = SteelArmor;

				printf("%sの防御力が上がった\n", name);
				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち
			}

			//プレイヤーHP0判定
			if (HP <= 0) {

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
			BD = 0;
		}

		//戦闘画面に遷移 ドローン2
		if (E3 == 2)
		{
			system("cls");
			printf("ドローンが現れた\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("\nドローンとの戦闘が始まった\nHP%d", HP);
			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("\n\nドローンはふわふわと浮いている\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			system("cls");

			BD = 0;
			//ドローン戦闘プログラム
			while ((DrH2 >= 0) && (HP >= 0) && (BD < 1))
			{
				//ドローン回避率
				int defense = 1 + rand() % 100;
				int VIT2 = 1 + rand() % VIT;

				//敵の選択肢
				int Ran = 1 + rand() % 100;
				if (Ran <= 50)
				{
					//攻撃
					EC = 1;
				}
				else if (Ran <= 90)
				{
					//必殺技
					EC = 2;
				}
				else if (Ran <= 100)
				{
					//回避、回復
					EC = 3;
				}

				if (EC == 3)
				{
					defense += 30;
				}

				system("cls");

				printf("\nHP%dMP%d\n\n1攻撃\n\n2持ち物\n\n3逃げる\n\n選択肢入力：",HP,MP);
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)scanf("%d", &PC);

				system("cls");

				//プレイヤー選択肢行動
				switch (PC)
				{
				case 1:			//攻撃　と　MP攻撃　と魔法攻撃に分岐

					printf("\n1通常攻撃\n\n2火炎斬り(MP5消費)\n\n3フレームストーム(MP10消費)\n\n4戻る\n\n選択肢入力：");
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)scanf("%d", &num);

					switch (num)
					{
					case 1:

						printf("%sの攻撃\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						//ダメージ計算
						Damage = AT;

						if (defense >= 10)
						{
							DrH2 -= Damage;

							printf("ドローンに%dダメージ\n", Damage);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち	
						}
						else
						{
							printf("しかしドローンに攻撃を避けられた\n");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち	
						}

						break;

					case 2:
						if (MP >= 5)
						{

							printf("%sの火炎斬り\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							//ダメージ計算
							Damage = AT * 1.5;

							if (defense >= 30) {
								DrH2 -= Damage;

								printf("ドローンに%dダメージ\n", Damage);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}
							else
							{
								printf("しかしドローンに攻撃を避けられた\n");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}

							MP -= 5;
						}
						else
						{
							printf("MPが足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}

						break;

					case 3:
						if (MP >= 10)
						{

							printf("%sのフレームストーム\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							//ダメージ計算
							Damage = AT * 2;

							if (defense >= 50) {
								DrH2 -= Damage;

								printf("ドローンに%dダメージ\n", Damage);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}
							else
							{
								printf("しかしドローンに攻撃を避けられた\n");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}

							MP -= 10;
						}
						else
						{
							printf("MPが足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}

						break;

					default:

						printf("選択肢の入力方式が間違っています。\n1～4で入力してください。\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

					case 4:
						//戦闘中のwhileまで戻る
						system("cls");
						continue;
						break;
					}

					break;

				case 2:			//持ち物欄を開きたい

					system("cls");

					printf("\n1回復薬\n\n2聖水\n\n3戻る\n\n選択肢:");
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)scanf("%d", &num);

					switch (num)
					{
					case 1:

						if (HPplus >= 1)
						{
							if (HP == MaxHP)
							{
								printf("HPが満タンのようだ");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								continue;
							}
							else
							{

								printf("%sは回復薬を使った\n", name);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								HP += 150;

								if (MaxHP <= HP)
								{
									HP = MaxHP;
								}

								printf("%sのHPは%dになった", name, HP);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								HPplus--;
							}

						}
						else
						{
							printf("回復薬が足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}
						break;

					case 2:

						if (MPplus >= 1)
						{
							if (HP == MaxHP)
							{
								printf("MPが満タンのようだ");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								continue;
							}
							else
							{

								printf("%sは聖水を使った\n", name);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								MP += 25;

								if (MaxMP <= MP)
								{
									MP = MaxMP;
								}

								printf("%sのMPは%dになった", name, MP);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								MPplus--;
							}

						}
						else
						{
							printf("聖水が足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}
						break;

					default:

						printf("選択肢の入力方式が間違っています。\n1～3で入力してください。\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

					case 3:
						//戦闘中のwhileまで戻る
						system("cls");
						continue;
						break;
					}

					break;

				case 3:		//逃げ確率

					if (EC == 1)	//攻撃
					{
						printf("ドローンの誘導ミサイル\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("%sは逃げ出した\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						int BP = 1 + rand() % 100;
						if (BP <= 10)
						{
							Ex2 = old_Ex2;
							Ey2 = old_Ey2;
							px = old_px;
							py = old_py;
							E3 = 1;
							BD = 1;
						}
						else
						{
							printf("しかし、%sは逃げられなかった\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち
						}

					}
					else if (EC == 2)	//必殺技
					{
						printf("ドローンのレーザービーム\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("%sは逃げ出した\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						int BP = 1 + rand() % 100;
						if (BP <= 50)
						{
							Ex2 = old_Ex2;
							Ey2 = old_Ey2;
							px = old_px;
							py = old_py;
							E3 = 1;
							BD = 1;
						}
						else
						{
							printf("しかし、%sは逃げられなかった\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち
						}
					}
					else if (EC == 3)	//回避して回復
					{
						printf("ドローンの修繕システム\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("%sは逃げ出した\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち
						int BP = 1 + rand() % 100;
						if (BP <= 100)
						{
							Ex2 = old_Ex2;
							Ey2 = old_Ey2;
							px = old_px;
							py = old_py;
							E3 = 1;
							BD = 1;
						}
						else
						{
							printf("しかし、%sは逃げられなかった\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち
						}
					}

					break;

				default:

					printf("選択肢の入力方式が間違っています。\n1～3で入力してください。\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち
					continue;
					break;
				}

				//敵選択肢行動
				if ((BD == 0) && (DrH2 > 0))
				{
					if (EC == 1)
					{
						printf("ドローンの誘導ミサイル\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						//戦闘ダメ計算
						Damage = Dr2 - VIT2;

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
					}
					else if (EC == 2)
					{
						printf("ドローンのレーザービーム\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						//戦闘ダメ計算
						Damage = Dr2 * 1.5 - VIT2;

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
					}
					else if (EC == 3)
					{
						printf("ドローンの修繕システム\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						DrH2 += 50;
					}
				}

			}

			//敵HP0判定
			if (DrH2 <= 0)
			{
				E3 = 0;
				printf("ドローンは墜落した\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ドローンは回復薬と聖水を落とした\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				HPplus++;
				MPplus++;
				DRB++;
			}

			//プレイヤーHP0判定
			if (HP <= 0) {

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
			BD = 0;
		}

		//戦闘画面に遷移 ドローン3
		if (E4 == 2)
		{
			system("cls");
			printf("ドローンが現れた\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("\nドローンとの戦闘が始まった\nHP%d", HP);
			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("\n\nドローンはふわふわと浮いている\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			system("cls");

			BD = 0;
			//ドローン戦闘プログラム
			while ((DrH3 >= 0) && (HP >= 0) && (BD < 1))
			{
				//ドローン回避率
				int defense = 1 + rand() % 100;
				int VIT2 = 1 + rand() % VIT;

				//敵の選択肢
				int Ran = 1 + rand() % 100;
				if (Ran <= 50)
				{
					//攻撃
					EC = 1;
				}
				else if (Ran <= 90)
				{
					//必殺技
					EC = 2;
				}
				else if (Ran <= 100)
				{
					//回避、回復
					EC = 3;
				}

				if (EC == 3)
				{
					defense += 30;
				}

				system("cls");

				printf("\nHP%dMP%d\n\n1攻撃\n\n2持ち物\n\n3逃げる\n\n選択肢入力：",HP,MP);
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)scanf("%d", &PC);

				system("cls");

				//プレイヤー選択肢行動
				switch (PC)
				{
				case 1:			//攻撃　と　MP攻撃　と魔法攻撃に分岐

					printf("\n1通常攻撃\n\n2火炎斬り(MP5消費)\n\n3フレームストーム(MP10消費)\n\n4戻る\n\n選択肢入力：");
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)scanf("%d", &num);

					switch (num)
					{
					case 1:

						printf("%sの攻撃\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						//ダメージ計算
						Damage = AT;

						if (defense >= 10)
						{
							DrH3 -= Damage;

							printf("ドローンに%dダメージ\n", Damage);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち	
						}
						else
						{
							printf("しかしドローンに攻撃を避けられた\n");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち	
						}

						break;

					case 2:
						if (MP >= 5)
						{

							printf("%sの火炎斬り\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							//ダメージ計算
							Damage = AT * 1.5;

							if (defense >= 30) {
								DrH3 -= Damage;

								printf("ドローンに%dダメージ\n", Damage);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}
							else
							{
								printf("しかしドローンに攻撃を避けられた\n");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}
							MP -= 5;
						}
						else
						{
							printf("MPが足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}

						break;

					case 3:
						if (MP >= 10)
						{

							printf("%sのフレームストーム\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							//ダメージ計算
							Damage = AT * 2;

							if (defense >= 50) {
								DrH3 -= Damage;

								printf("ドローンに%dダメージ\n", Damage);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}
							else
							{
								printf("しかしドローンに攻撃を避けられた\n");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}

							MP -= 10;
						}
						else
						{
							printf("MPが足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}

						break;

					default:

						printf("選択肢の入力方式が間違っています。\n1～4で入力してください。\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

					case 4:
						//戦闘中のwhileまで戻る
						system("cls");
						continue;
						break;
					}

					break;

				case 2:			//持ち物欄を開きたい

					system("cls");

					printf("\n1回復薬\n\n2聖水\n\n3戻る\n\n選択肢:");
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)scanf("%d", &num);

					switch (num)
					{
					case 1:

						if (HPplus >= 1)
						{
							if (HP == MaxHP)
							{
								printf("HPが満タンのようだ");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								continue;
							}
							else
							{

								printf("%sは回復薬を使った\n", name);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								HP += 150;

								if (MaxHP <= HP)
								{
									HP = MaxHP;
								}

								printf("%sのHPは%dになった", name, HP);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								HPplus--;
							}

						}
						else
						{
							printf("回復薬が足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}
						break;

					case 2:

						if (MPplus >= 1)
						{
							if (HP == MaxHP)
							{
								printf("MPが満タンのようだ");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								continue;
							}
							else
							{

								printf("%sは聖水を使った\n", name);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								MP += 25;

								if (MaxMP <= MP)
								{
									MP = MaxMP;
								}

								printf("%sのMPは%dになった", name, MP);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち
								MPplus--;
							}

						}
						else
						{
							printf("聖水が足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}
						break;

					default:

						printf("選択肢の入力方式が間違っています。\n1～3で入力してください。\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

					case 3:
						//戦闘中のwhileまで戻る
						system("cls");
						continue;
						break;
					}

					break;

				case 3:		//逃げ確率

					if (EC == 1)	//攻撃
					{
						printf("ドローンの誘導ミサイル\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("%sは逃げ出した\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						int BP = 1 + rand() % 100;
						if (BP <= 10)
						{
							Ex3 = old_Ex3;
							Ey3 = old_Ey3;
							px = old_px;
							py = old_py;
							E4 = 1;
							BD = 1;
						}
						else
						{
							printf("しかし、%sは逃げられなかった\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち
						}

					}
					else if (EC == 2)	//必殺技
					{
						printf("ドローンのレーザービーム\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("%sは逃げ出した\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						int BP = 1 + rand() % 100;
						if (BP <= 50)
						{
							Ex3 = old_Ex3;
							Ey3 = old_Ey3;
							px = old_px;
							py = old_py;
							E4 = 1;
							BD = 1;
						}
						else
						{
							printf("しかし、%sは逃げられなかった\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち
						}
					}
					else if (EC == 3)	//回避して回復
					{
						printf("ドローンの修繕システム\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("%sは逃げ出した\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち
						int BP = 1 + rand() % 100;
						if (BP <= 100)
						{
							Ex3 = old_Ex3;
							Ey3 = old_Ey3;
							px = old_px;
							py = old_py;
							E4 = 1;
							BD = 1;
						}
						else
						{
							printf("しかし、%sは逃げられなかった\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち
						}
					}

					break;

				default:

					printf("選択肢の入力方式が間違っています。\n1～3で入力してください。\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち
					continue;
					break;
				}

				//敵選択肢行動
				if ((BD == 0) && (DrH3 > 0))
				{
					if (EC == 1)
					{
						printf("ドローンの誘導ミサイル\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						//戦闘ダメ計算
						Damage = Dr3 - VIT2;

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
					}
					else if (EC == 2)
					{
						printf("ドローンのレーザービーム\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						//戦闘ダメ計算
						Damage = Dr3 * 1.5 - VIT2;

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
					}
					else if (EC == 3)
					{
						printf("ドローンの修繕システム\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						DrH3 += 50;
					}
				}

			}

			//敵HP0判定
			if (DrH3 <= 0)
			{
				E4 = 0;
				printf("ドローンは墜落した\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("ドローンは回復薬と聖水を落とした\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				HPplus++;
				MPplus++;

				DRB++;
			}

			//プレイヤーHP0判定
			if (HP <= 0) {

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
			BD = 0;
		}

		//戦闘画面に遷移 イライザ
		if (E5 == 2)
		{
			system("cls");
			printf("イライザが現れた\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			if (GDB == 1)
			{
				printf("\n\nイライザ「ガーディアンからの信号切断を検知」\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち
			}
			else
			{
				printf("\n\nイライザ「ガーディアンから侵入者の信号を確認」\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち
			}

			if (DRB == 1)
			{
				printf("\n\nイライザ「防衛ドローン%d機接続不能を検知」\n",name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち
			}
			else
			{
				printf("\n\nイライザ「防衛ドローンからの侵入者の信号を確認」\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち
			}

			printf("イライザ「目の前の人間型の生命体が侵入者である確率が非常に高いです」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			printf("イライザ「登録完了していない生命体を直ちに排除します」\n");

			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち


			printf("\nイライザとの戦闘が始まった\nHP%d", HP);
			// キー入力待ち
			rewind(stdin);		// ←キー入力情報をクリアする
			(void)getchar();	// キー入力待ち

			system("cls");

			BD = 0;
			ad = 0;
			i = 0;
			//イライザ戦闘プログラム
			while ((ELIZAH >= 0) && (HP >= 0) && (BD < 1))
			{
				Damage = 0;


				//敵ディフェンス設定
				A = (ELIZAH / 20) + 1;
				int defense = 1 + rand() % A;
				int VIT2 = 1 + rand() % VIT;


				//敵の選択肢
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
					//攻撃プラスシステム
					EC = 3;
				}

				if (loopA == 1)
				{
					printf("イライザ「ガーディアン以上の戦闘力を確認」\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("イライザ「戦闘モード起動」\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("イライザの攻撃力が100になった\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					ELIZA = 100;
				}
				else if (loopA == 3)
				{
					printf("イライザ「持久戦になることが予想」\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("イライザ「防御システム展開」\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("イライザの防御力が上がった\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					Point = 1;
				}
				else if (loopA == 6)
				{
					printf("イライザ「緊急事態発生！侵入者の戦闘力が自分を上回ることを確認」\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("イライザ「プログラムを再構築…」\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("イライザ「システム拡張、処理速度を加速。」\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("イライザが攻撃を回避するようになった\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					i = 1;	//プレイヤーの攻撃のところでi=1なら回避率30上げる
				}
				else if (loopA == 10)
				{
					printf("イライザ「コアのオーバーヒートを確認」\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					printf("イライザ「フェールソフトシステムにより一部のプログラムを停止させます」\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					i = 0;
					Point = 2;
					ELIZA = 75;
				}

				if (Point == 1)
				{
					defense += 50;
				}
				else if(Point == 2)
				{
					defense = 0;
				}

				if (i == 1)
				{
					int Ran = 1 + rand() % 100;
					if (Ran <= 20)
					{
						C = 1;
					}
					else
					{
						C = 0;
					}
				}

				system("cls");
				if (EC == 3)
				{
					printf("イライザの防御システム：elmo発動\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち

					ad++;
				}

				

				printf("\nHP%dMP%d\n\n1攻撃\n\n2持ち物\n\n3逃げる\n\n選択肢入力：",HP,MP);
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)scanf("%d", &PC);

				system("cls");

				//プレイヤー選択肢行動
				switch (PC)
				{
				case 1:			//攻撃　と　MP攻撃　と魔法攻撃に分岐

					printf("\n1通常攻撃\n\n2火炎斬り(MP5消費)\n\n3フレームストーム(MP10消費)\n\n4戻る\n\n選択肢入力：");
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)scanf("%d", &num);

					switch (num)
					{
					case 1:

						printf("%sの攻撃\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						//ダメージ計算
						Damage = AT - defense;

						if (C == 1)
						{
							printf("しかしイライザに攻撃を避けられた\n");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち	
						}
						else
						{
							if (EC == 3)
							{

								printf("イライザの防御システム：elmoにより攻撃力が半減される\n");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								Damage / 2;
							}

							if (Damage >= 0) {
								ELIZAH -= Damage;

								printf("イライザに%dダメージ\n", Damage);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}
							else
							{
								printf("しかしイライザにダメージを与えられない\n");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}
						}

						break;

					case 2:
						if (MP >= 5)
						{

							printf("%sの火炎斬り\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							if (C == 1)
							{
								printf("しかしイライザに攻撃を避けられた\n");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}
							else
							{
								//ダメージ計算
								Damage = AT * 1.5 - defense;

								if (EC == 3)
								{

									printf("イライザの防御システム：elmoにより攻撃力が半減される\n");

									// キー入力待ち
									rewind(stdin);		// ←キー入力情報をクリアする
									(void)getchar();	// キー入力待ち

									Damage / 2;
								}

								if (Damage >= 0) {
									ELIZAH -= Damage;

									printf("イライザに%dダメージ\n", Damage);

									// キー入力待ち
									rewind(stdin);		// ←キー入力情報をクリアする
									(void)getchar();	// キー入力待ち	
								}
								else
								{
									printf("しかしイライザにダメージを与えられない\n");

									// キー入力待ち
									rewind(stdin);		// ←キー入力情報をクリアする
									(void)getchar();	// キー入力待ち	
								}
							}

							MP -= 5;
						}
						else
						{
							printf("MPが足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}
						break;

					case 3:
						if (MP >= 10)
						{

							printf("%sのフレームストーム\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							if (C == 1)
							{
								printf("しかしイライザに攻撃を避けられた\n");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち	
							}
							else
							{
								//ダメージ計算
								Damage = AT * 2 - defense;

								if (EC == 3)
								{

									printf("イライザの防御システム：elmoにより攻撃力が半減される\n");

									// キー入力待ち
									rewind(stdin);		// ←キー入力情報をクリアする
									(void)getchar();	// キー入力待ち

									Damage / 2;
								}


								if (Damage >= 0) {
									ELIZAH -= Damage;

									printf("イライザに%dダメージ\n", Damage);

									// キー入力待ち
									rewind(stdin);		// ←キー入力情報をクリアする
									(void)getchar();	// キー入力待ち	
								}
								else
								{
									printf("しかしイライザにダメージを与えられない\n");

									// キー入力待ち
									rewind(stdin);		// ←キー入力情報をクリアする
									(void)getchar();	// キー入力待ち	
								}
							}
							MP -= 10;
						}
						else
						{
							printf("MPが足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}
						break;

					default:

						printf("選択肢の入力方式が間違っています。\n1～4で入力してください。\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

					case 4:
						//戦闘中のwhileまで戻る
						system("cls");
						continue;
						break;
					}

					break;

				case 2:			//持ち物欄を開きたい

					system("cls");

					printf("\n1回復薬\n\n2聖水\n\n3戻る\n\n選択肢:");
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)scanf("%d", &num);

					switch (num)
					{
					case 1:

						if (HPplus >= 1)
						{
							if (HP == MaxHP)
							{
								printf("HPが満タンのようだ");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								continue;
							}
							else
							{

								printf("%sは回復薬を使った\n", name);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								HP += 150;

								if (MaxHP <= HP)
								{
									HP = MaxHP;
								}

								printf("%sのHPは%dになった", name, HP);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								HPplus--;
							}

						}
						else
						{
							printf("回復薬が足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}
						break;

					case 2:

						if (MPplus >= 1)
						{
							if (HP == MaxHP)
							{
								printf("MPが満タンのようだ");

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								continue;
							}
							else
							{

								printf("%sは聖水を使った\n", name);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち

								MP += 25;

								if (MaxMP <= MP)
								{
									MP = MaxMP;
								}

								printf("%sのMPは%dになった", name, MP);

								// キー入力待ち
								rewind(stdin);		// ←キー入力情報をクリアする
								(void)getchar();	// キー入力待ち
								MPplus--;
							}

						}
						else
						{
							printf("聖水が足りないようだ…");

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち

							continue;
						}
						break;

					default:

						printf("選択肢の入力方式が間違っています。\n1～3で入力してください。\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

					case 3:
						//戦闘中のwhileまで戻る
						system("cls");
						continue;
						break;
					}

					break;

				case 3:		//逃げ確率

					if (EC == 1)	//攻撃
					{
						printf("イライザのブラッドストーム\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("%sは逃げ出した\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						int BP = 1 + rand() % 100;
						if (BP <= 20)
						{
							px = old_px;
							py = old_py;
							E5 = 1;
							BD = 1;
						}
						else
						{
							printf("しかし、%sは逃げられなかった\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち
						}

					}
					else if (EC == 2)	//必殺技
					{
						printf("イライザのインフェルノ\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						printf("%sは逃げ出した\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						int BP = 1 + rand() % 100;
						if (BP <= 20)
						{
							px = old_px;
							py = old_py;
							E5 = 1;
							BD = 1;
						}
						else
						{
							printf("しかし、%sは逃げられなかった\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち
						}
					}
					else if (EC == 3)	//回避　or　様子を見る
					{
						printf("%sは逃げ出した\n", name);

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち
						int BP = 1 + rand() % 100;
						if (BP <= 50)
						{
							px = old_px;
							py = old_py;
							E5 = 1;
							BD = 1;
						}
						else
						{
							printf("しかし、%sは逃げられなかった\n", name);

							// キー入力待ち
							rewind(stdin);		// ←キー入力情報をクリアする
							(void)getchar();	// キー入力待ち
						}
					}

					break;

				default:

					printf("選択肢の入力方式が間違っています。\n1～3で入力してください。\n");

					// キー入力待ち
					rewind(stdin);		// ←キー入力情報をクリアする
					(void)getchar();	// キー入力待ち
					continue;
					break;
				}

				//敵選択肢行動
				if ((BD == 0) && (ELIZAH > 0))
				{
					if (EC == 1)
					{
						printf("イライザのブラッドストーム\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						//戦闘ダメ計算
						Damage = ELIZA - VIT2;

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
					}
					else if (EC == 2)
					{
						printf("イライザのインフェルノ\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

						//戦闘ダメ計算
						Damage = ELIZA * 1.5 - VIT2;

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
					}
					else if (EC == 3)
					{
						printf("イライザの防御システム：elmoによるカウンター\n");

						// キー入力待ち
						rewind(stdin);		// ←キー入力情報をクリアする
						(void)getchar();	// キー入力待ち

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
					}

				}

				loopA += 1;
			}

			//敵HP0判定
			if (ELIZAH <= 0)
			{
				E5 = 0;
				printf("イライザは倒れた\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("%s「かなりの強者だったな。」\n",name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("%s「まぁ、幾度も困難を乗り越えてきた凄腕のトレジャーハンターにはかなわないがな」\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("%s「よし、この先にお宝があるはずだ」\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち
			}

			//プレイヤーHP0判定
			if (HP <= 0) {

				printf("勇者%sは倒れてしまった…\n", name);

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				printf("イライザ「侵入者排除完了！」\n");

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				GameOver();

				// キー入力待ち
				rewind(stdin);		// ←キー入力情報をクリアする
				(void)getchar();	// キー入力待ち

				exit(-1);
			}
			BD = 0;
		}


		Sleep(10);
	}


/*******************************************************************************
* エンディング
*******************************************************************************/

	//お宝を手に入れたらここに来る


	printf("これは…\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("オリハルコンの王冠とたくさんの財宝…\n");

	// キー入力待ち
	rewind(stdin);		// ←キー入力情報をクリアする
	(void)getchar();	// キー入力待ち

	printf("%s「今回の探索はだいぶ困難だったがなんとかお宝を手に入れられたぜ！」\n",name);

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

void title(void)
{
	//treasure hunter　にタイトルを変更


	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　□□□□□　□□□　□□□　　　□　　  □□□　□　　□  □□□　　　　　\n");
	printf("　　　　□　　　□　□　□　　　　 □□　　□　　　 □　　□　□　　　　　　　\n");
	printf("　　　　□　　　□□　　□□□　　□　□　  □□□　□　　□　□□□　　　　　\n");
	printf("　　　　□　　　□　□　□　　　 □□□□　　　  □ □　　□　□　　　　　  　\n");
	printf("　　　　□　　　□　□　□□□　□　　　□　□□□　 □□□　 □□□　　　    \n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("　　　　　　　　□　　□　□　　□　□　　□　□□□□□　□□□　□□□　　　\n");
	printf("　　　　　　　　□　　□　□　　□　□□　□　　　□　　　□　　　□  □　　　\n");
	printf("　　　　　　　　□□□□　□　　□　□ □ □　　　□　　　□□□　□□　　　　\n");
	printf("　　　　　　　　□　　□　□　　□　□　□□　　　□　　　□　　　□　□　　  \n");
	printf("　　　　　　　　□　　□　 □□□　 □　　□　　　□　　　□□□　□　□　　　\n");
	printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("Enter：次へ進む\n");
	printf("\n");

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
	printf("THANK YOU FOR PLAYING!!\n");
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

