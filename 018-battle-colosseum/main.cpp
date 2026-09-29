/*******************************************************************************
* タイトル:		メインプログラム
* プログラム名:	main.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/06/23 ～
* 最終更新日:	2024/09/06
* 
* 詳細:			CL23_課題06_シンバトルコロシアム
*				バトル処理はネームバトラーのコマンドバトルからとってきて、
*				コマンドをランダム化でオート処理に変更
* 
*やること:		menu.cppを整理
				Battle.hを整理
				//ここがメインの課題
				Battle.cppでオートバトル処理を作る
				Characterクラスを継承したクラスを作る
********************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "menu.h"


/*******************************************************************************
 関数名:	int main( void )
 引数　:	void
 戻り値:	正常終了: int型の 0
 説明　:	メイン関数
*******************************************************************************/
int main()
{
	//現在の時刻で乱数初期化
	srand(static_cast<unsigned>(time(0)));

	Menu menu;

	menu.Load();

	//while脱出
	bool loop = true;

	//メインループ
	while(loop)
	{
		//選択肢
		int select = 0;
		std::cout << "\n　バトルコロシアム受付です！" << std::endl;
		std::cout << "\n　現在できることは下記の通りでございます。\n\n";

		std::cout << "　1.バトルコロシアム\n";			//バトルコロシアム
		std::cout << "　2.出場選手の閲覧\n";			//閲覧・フィルタ・検索機能・ソート機能
		std::cout << "　3.新しい選手のエントリー\n";	//メンバー追加
		std::cout << "　4.出場選手の棄権\n";			//メンバー削除
		std::cout << "　5.出場選手の並び替え\n";		//メンバー並び替え
		std::cout << "　6.バトルコロシアムを出る\n";	//終了する(セーブ)
		std::cout << "　選択肢 : ";
		std::cin >> select;
		
		std::cin.seekg(0);	//	←キー入力情報をクリアする
		system("cls");

		switch (select)
		{
		case 1:	//バトル
			menu.StartBattle();
			break;
		case 2:	//閲覧
			menu.ViewGuildMember();
			break;
		case 3:	//メンバー追加
			menu.AddGuildMember();
			break;
		case 4:	//メンバー削除
			menu.DeleteGuildMember();
			break;
		case 5:	//メンバー整理
			menu.SortGuildMember();
			break;
		case 6:	//終了する
			loop = false;

			std::cout << "\n　これまでの設定を保存しておきますか？\n\n";
			std::cout << "　1.はい\n";	//セーブ
			std::cout << "　2.いいえ\n";//セーブ無し終了
			std::cout << "　選択肢 : ";

			std::cin >> select;

			std::cin.seekg(0);	//	←キー入力情報をクリアする
			system("cls");


			if (select == 1)
			{
				menu.Save();
			}

			break;
		default://入力ミス
			std::cout << "\n　選択肢の入力方式が間違っています。\n　半角数字1～6で入力してください\n";
			std::cin.get();		//	←キー入力待ち
			system("cls");
			continue;
			break;

		}	// End switch

		system("cls");

	}	// End while

	std::cout << "　バトルコロシアムを出ました。\n　Enterキーで完全に終了します";


	std::cin.seekg(0);	//	←キー入力情報をクリアする
	std::cin.get();		//	←キー入力待ち

	return 0;
}

