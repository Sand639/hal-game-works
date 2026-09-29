/*******************************************************************************
* タイトル:		メニュープログラム
* プログラム名:	Menu.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/07/10 〜
* 最終変更日:	2024/07/10
********************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "Menu.h"
#include "Guild.h"
#include "Character.h"
#include "Battle.h"

/*******************************************************************************
* グローバル変数
*******************************************************************************/
Guild guild(10);

/*******************************************************************************
* コンストラクタ
*******************************************************************************/
Menu::Menu() 
{
	//プロローグ
	Prologue();

}


/*******************************************************************************
* デストラクタ
*******************************************************************************/
Menu::~Menu()
{



}


/*******************************************************************************
* プロローグ
*******************************************************************************/
void Menu::Prologue()
{
	std::cout << "\n　ようこそお越しくださいました！\n" ;

	Sleep(1000);

	std::cout << "\n　ここは、バトルコロシアム！\n" ;

	Sleep(1000);

	std::cout << "\n　この世界で、真の最強を決めるべく建てられた、強者たちの集まる場所！！\n";

	Sleep(1000);

	std::cout << "\n　己の感情がぶつかり合う、熱き戦いをご覧ください！\n";
	std::cout << "\n　Press Enter >> ";

	std::cin.seekg(0);	//	←キー入力情報をクリアする
	std::cin.get();		//	←キー入力待ち

	system("cls");
}


/*******************************************************************************
* ギルドメンバーの追加
*******************************************************************************/
void Menu::AddGuildMember()
{
	int select = 0;
	int id = 0;

	std::cout << "\n　新しい選手のエントリーですね！\n";
	std::cout << "\n　それではこちらの紙にエントリー情報をご記入ください！\n\n";
	std::cout << "\n　1.エントリーする";	
	std::cout << "\n　2.今回はやめておく\n　選択肢 : ";

	std::cin >> select;
	std::cin.seekg(0);	//	←キー入力情報をクリアする

	switch (select)
	{
	case 1:

		system("cls");
		std::cout << "\n　適当に記入したらその記入のまま、\n　出場になってしまうので、気を付けてください！\n";

		break;
	case 2:
	default:

		system("cls");
		std::cout << "\n　そうですか...次はエントリーしてくださいね！ <Enter>";

		std::cin.get();		//	←キー入力待ち
		return;

		break;
	}

	//変数
	select = 0;
	std::string Name;
	std::string Gen;
	std::string Job;
	int Lv;
	int HP;
	int MP;
	int ATK;
	int DEF;
	int AGI;
	int DEX;
	int Intel;
	int PIE;



	std::cout << "　<出場選手の名前を入力してください>" << std::endl;
	std::cin >> Name;

	std::cout << "　<出場選手の性別を入力してください>" << std::endl;
	std::cin >> Gen;

	std::cout << "　<出場選手の職業を選択してください>" << std::endl;
	std::cout << "\n　1.魔法使い";
	std::cout << "\n　2.弓使い";
	std::cout << "\n　3.剣士\n　選択肢 : ";
	std::cin >> select;

	switch (select)
	{
	case 1:
		Job = "魔法使い";
		break;
	case 2:
		Job = "弓使い";
		break;
	case 3:
		Job = "剣士";
		break;
	default:
		std::cout << "\n　選択範囲外が入力されたため職業が「駆け出し冒険者」になります。\n";
		select = 0;
		Job = "駆け出し冒険者";
		break;
	}

	std::cout << "\n　<出場選手のレベルを入力してください>" << std::endl;
	std::cin >> Lv;

	std::cout << "　<出場選手の体力を入力してください>" << std::endl;
	std::cin >> HP;

	std::cout << "　<出場選手の魔力を入力してください>" << std::endl;
	std::cin >> MP;

	system("cls");

	std::cout << "　<出場選手の攻撃力を入力してください>" << std::endl;
	std::cin >> ATK;

	std::cout << "　<出場選手の防御力を入力してください>" << std::endl;
	std::cin >> DEF;

	std::cout << "　<出場選手の素早さを入力してください>" << std::endl;
	std::cin >> AGI;

	std::cout << "　<出場選手の器用さを入力してください>" << std::endl;
	std::cin >> DEX;

	std::cout << "　<出場選手の賢さを入力してください>" << std::endl;
	std::cin >> Intel;

	std::cout << "　<出場選手の信仰度を入力してください>" << std::endl;
	std::cin >> PIE;

	std::cout << "　出場選手の追加が完了しました！ <Enter>" << std::endl;

	//メンバー追加
	id = guild.AddMember(Name, Gen, Job, HP, MP, ATK, DEF, Lv, AGI, DEX, Intel, PIE, select);

	std::cin.seekg(0);	//	←キー入力情報をクリアする
	std::cin.get();		//	←キー入力待ち

	system("cls");

	//入力情報の表示
	guild.ViewCharacter(id + 1);

	std::cin.get();		//	←キー入力待ち

}


/*******************************************************************************
* ギルドメンバーの閲覧
*******************************************************************************/
void Menu::ViewGuildMember()
{

	//while脱出
	bool loop = true;

	while (loop)
	{
		//選択肢
		int select = 0;

		std::cout << "\n　出場選手の閲覧ですね！\n";
		std::cout << "\n　現在できることは下記の通りでございます。\n\n";

		std::cout << "　1.出場選手の一覧表示\n";	//簡易表示
		std::cout << "　2.出場選手の詳細表示\n";	//名前検索・ID検索
		std::cout << "　3.閲覧を終了する\n";		
		std::cout << "　選択肢 : ";
		std::cin >> select;

		std::cin.seekg(0);	//	←キー入力情報をクリアする
		system("cls");

		//ID検索用変数
		int id = 0;
		//名前検索用変数
		std::string name = "あ";

		switch (select)	// switch 1
		{
		case 1:	//ギルドメンバーの一覧表示

			guild.ViewMembers();

			break;	//switch 1 case 1


		case 2:	//ギルドメンバーの詳細表示
			std::cout << "\n　詳細表示では一人の出場選手のステータスを詳しく見ることができます。\n";
			std::cout << "\n　下記の方法で一人の出場選手の選択できます。\n\n";
			std::cout << "　1.ID検索\n";
			std::cout << "　2.名前検索\n";
			std::cout << "　3.戻る\n";
			std::cout << "　選択肢 : ";
			std::cin >> select;

			std::cin.seekg(0);	//	←キー入力情報をクリアする
			system("cls");

			switch (select)	// switch 2
			{
			case 1:	//ID検索
				std::cout << "\n　ID検索\n\n";
				std::cout << "\n　IDを入力してください\n";
				std::cout << "　ID : ";
				std::cin >> id;

				std::cin.seekg(0);	//	←キー入力情報をクリアする
				system("cls");

				//ID検索用詳細表示
				id = guild.ViewCharacter(id);

				if (id == -1)
				{
					std::cout << "そのIDでヒットした出場選手はいませんでした...";
				}


				break;
			case 2:	//名前検索
				std::cout << "\n　名前検索\n\n";
				std::cout << "\n　名前を入力してください\n";
				std::cout << "　名前 : ";
				std::cin >> name;

				std::cin.seekg(0);	//	←キー入力情報をクリアする
				system("cls");

				//名前検索
				id = guild.GetMemberByName(name);

				if (id == -1)
				{
					std::cout << "その名前でヒットした出場選手はいませんでした...";
				}
				else
				{
					//ID検索用詳細表示
					guild.ViewCharacter(id + 1);
				}

				break;
			case 3:
			default:
				continue;
				break;
			}	// End switch 2

			break;	//switch 1 case 2


		case 3:	//終了する
			loop = false;
			return;
			break;
		default://入力ミス
			std::cout << "\n　選択肢の入力方式が間違っています。\n　半角数字1〜3で入力してください\n";
			std::cin.get();		//	←キー入力待ち
			system("cls");
			continue;
			break;	//switch 1 case 3

		}	// End switch 1

		std::cin.get();		//	←キー入力待ち
		system("cls");

	}	// End while

}


/*******************************************************************************
* ギルドメンバーの削除
*******************************************************************************/
void Menu::DeleteGuildMember()
{
	int id = 0;

	std::cout << "\n　バトルコロシアムの棄権ですね\n";
	std::cout << "\n　出場選手のIDは閲覧から確認できます。\n";
	std::cout << "\n　棄権する出場選手のIDを入力してください\n　ID ： " << std::endl;
	std::cin >> id;

	guild.DeleteMember(id - 1);

	guild.ViewMembers();

	std::cout << "\n　棄権手続きが完了しました。\n";
	std::cout << "\n　次はぜひ出場してくださいね！\n";

	std::cin.seekg(0);	//	←キー入力情報をクリアする
	std::cin.get();		//	←キー入力待ち

}



/*******************************************************************************
* ギルドメンバーの並び替え
*******************************************************************************/
void Menu::SortGuildMember()
{

	//while脱出
	bool loop = true;

	while (loop)
	{
		int select = 0;
		bool flag = true;

		std::cout << "\n　出場選手の整理ですね。\n";
		std::cout << "\n　下記の並び替えで出場選手の整理が行えます。\n\n";
		std::cout << "　1.レベル順表示\n";
		std::cout << "　2.HP順表示\n";
		std::cout << "　3.MP順表示\n";
		std::cout << "　4.攻撃力順表示\n";
		std::cout << "　5.防御力順表示\n";
		std::cout << "　6.素早さ順表示\n";
		std::cout << "　7.器用さ順表示\n";
		std::cout << "　8.賢さ順表示\n";
		std::cout << "　9.信仰度順表示\n";
		std::cout << "　10.出場選手の整理を終了する\n";
		std::cout << "　選択肢 : ";

		std::cin >> select;

		std::cin.seekg(0);	//	←キー入力情報をクリアする
		system("cls");

		switch (select)	// switch
		{
		case 1:	//ステータス順
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:

			std::cout << "\n　昇順か、降順か選べます。\n\nどちらにいたしますか？\n\n";
			std::cout << "　1.昇順\n";
			std::cout << "　2.降順\n";
			std::cout << "　3.やっぱりやめる\n";
			std::cout << "　選択肢 : ";

			std::cin >> select;

			std::cin.seekg(0);	//	←キー入力情報をクリアする
			system("cls");


			if (select == 1) flag = true;		//昇順
			else if (select == 2) flag = false;	//降順
			else break;	//選択肢に戻る

			//ソート機能
			guild.StatusSortGuildMember(select, flag);
			//m_guild->ViewMembers();

			std::cout << "\n　並び替えが完了しました！";

			std::cin.get();		//	←キー入力待ち
			system("cls");

			break;
		case 10:
		default:
			return;
			break;
		}	// End switch


	}	// End while
}

/*******************************************************************************
*　バトル
*******************************************************************************/
void Menu::StartBattle()
{

	system("cls");

	int id = 0;

	std::cout << "\n　バトルコロシアムの使用ですね！！\n";
	std::cout << "\n　出場選手のIDは閲覧から確認できます。\n";
	std::cout << "\n　出場する選手のIDを入力してください\n　一人目のID ： " << std::endl;
	std::cin >> id;

	Character* A = guild.GetCharacter(id);

	std::cin.seekg(0);	//	←キー入力情報をクリアする

	if (A == nullptr)
	{
		std::cout << "\n　あれ、このIDの選手は以内みたいですよ\n　IDを確認してからまた来てくださいね！ " << std::endl;
		std::cout << "\n　Enter >>\n";

		std::cin.get();		//	←キー入力待ち

		return;
	}

	std::cout << "\n　出場する選手のIDを入力してください\n　二人目のID ： " << std::endl;
	std::cin >> id;

	Character* B = guild.GetCharacter(id);

	std::cin.seekg(0);	//	←キー入力情報をクリアする

	if (B == nullptr)
	{
		std::cout << "\n　あれ、このIDの選手は以内みたいですよ\n　IDを確認してからまた来てくださいね！ " << std::endl;
		std::cout << "\n　Enter >>\n";

		std::cin.get();		//	←キー入力待ち

		return;
	}

	std::cout << "\n　バトルコロシアムの準備が整いました！\n";
	std::cout << "\n　それでは熱き戦いご覧あれ！\n";
	std::cout << "\n　Enter >>\n";

	std::cin.get();		//	←キー入力待ち

	Battle battle(A, B);

	battle.Fight();

	std::cout << "\n　Enterで受付へ戻る >>\n";
	std::cin.get();		//	←キー入力待ち

}

/*******************************************************************************
* セーブ
*******************************************************************************/
void Menu::Save()
{
	guild.SaveGuild("guild_data.dat");  // これでギルド全体を保存
}

/*******************************************************************************
* ロード
*******************************************************************************/
void Menu::Load()
{
	guild.LoadGuild("guild_data.dat");  // これでギルド全体を読み込み
}

