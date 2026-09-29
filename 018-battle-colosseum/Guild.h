/*******************************************************************************
* タイトル:		ギルドヘッダー
* プログラム名:	Guild.h
* 作成者:		大槻　海斗
* 作成日:		2024/06/28 〜
* 最終変更日:	2024/06/28
********************************************************************************/
#ifndef _GUILD_H_
#define _GUILD_H_

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "Character.h"
#include <string>
#include <vector>

/*******************************************************************************
* クラス定義
*******************************************************************************/
//ギルドクラス
class Guild
{
private:
	int m_member_max = 10;	//ギルドメンバーの最大数
	Character** m_members = nullptr;


public:
	Guild(int m_member_max);
	~Guild();

	//メンバーの追加
	//戻り値 : メンバーのID　/ 追加できなかった場合 : -1
	int AddMember(std::string name, std::string gen, std::string job,
		int hp, int mp, int atk, int def, int lv, int agi, int dex, int intel, int pie, int select);

		//メンバーの削除
	void DeleteMember(int id);

	//簡易的な一覧の表示
	void ViewMembers();

	//検索例：名前で検索
	int GetMemberByName(std::string name, int start_id = 0);

	//キャラクターの詳細な情報表示
	int ViewCharacter(int id);

	//キャラクターの取得
	Character* GetCharacter(int id);

	//ソート機能
	void StatusSortGuildMember(int num ,bool flag);

	// ギルドのセーブ
	void SaveGuild(const std::string& filename);

	//ギルドのロード
	void LoadGuild(const std::string& filename);

private:
	//簡易的なキャラクターの情報表示
	void ViewCharacterList(int id);

	//簡易的な一覧の表示(ソート後)
	void ViewSortedMembers(int num);

	//ソート機能中身
	static bool CompareAscByLv(Character* a, Character* b);	//昇順
	static bool CompareDesByLv(Character* a, Character* b);	//降順
	static bool CompareAscByHp(Character* a, Character* b);
	static bool CompareDesByHp(Character* a, Character* b);
	static bool CompareAscByMp(Character* a, Character* b);
	static bool CompareDesByMp(Character* a, Character* b);
	static bool CompareAscByAtk(Character* a, Character* b);
	static bool CompareDesByAtk(Character* a, Character* b);
	static bool CompareAscByDef(Character* a, Character* b);
	static bool CompareDesByDef(Character* a, Character* b);
	static bool CompareAscByAgi(Character* a, Character* b);
	static bool CompareDesByAgi(Character* a, Character* b);
	static bool CompareAscByDex(Character* a, Character* b);
	static bool CompareDesByDex(Character* a, Character* b);
	static bool CompareAscByIntel(Character* a, Character* b);
	static bool CompareDesByIntel(Character* a, Character* b);
	static bool CompareAscByPie(Character* a, Character* b);
	static bool CompareDesByPie(Character* a, Character* b);
	
};


#endif	//GUILD_H

