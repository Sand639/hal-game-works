/*******************************************************************************
* タイトル:		ギルドプログラム
* プログラム名:	Guild.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/06/28 〜
* 最終変更日:	2024/06/28
********************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "Guild.h"
#include "Character.h"
#include "Wizard.h"
#include "Archer.h"
#include "Kenshi.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>




/*******************************************************************************
* コンストラクタ
*******************************************************************************/
Guild::Guild(int member_max)
	: m_member_max(member_max)
{
	m_members = new Character * [m_member_max];

	for (int i = 0; i < m_member_max; i++)
	{
		m_members[i] = nullptr;
	}
}

/*******************************************************************************
* デストラクタ
*******************************************************************************/
Guild::~Guild()
{
	delete[] m_members;
}

/*******************************************************************************
* メンバの追加
*******************************************************************************/
int Guild::AddMember(std::string name, std::string gen, std::string job,
	int hp, int mp, int atk, int def, int lv, int agi, int dex, int intel, int pie ,int select)
{
	//リストから空いている場所を探してキャラクターを追加する
	for (int i = 0; i < m_member_max; i++)
	{
		if (m_members[i] == nullptr) //!m_members[i]でもOK
		{

			switch (select)
			{
			case 0:
				//キャラクターを追加する
				m_members[i] = new Character(name, gen, job, hp, mp, atk, def, lv, agi, dex, intel, pie);
				break;

			case 1:
				m_members[i] = new Wizard(name, gen, job, hp, mp, atk, def, lv, agi, dex, intel, pie);
				break;
			case 2:
				m_members[i] = new Archer(name, gen, job, hp, mp, atk, def, lv, agi, dex, intel, pie);
				break;
			case 3:
				m_members[i] = new Kenshi(name, gen, job, hp, mp, atk, def, lv, agi, dex, intel, pie);
				break;
			}

			//追加したら配列のインデックス(添字)をreturnして終了
			return i;
		}
	}

	return -1;	//いっぱいだった…
}

/*******************************************************************************
* メンバの削除
*******************************************************************************/
void Guild::DeleteMember(int id)
{
	//もし-1だったら何もしないでreturn
	//もし範囲外だったら何もしないでreturn
	if (id < 0 || id >= m_member_max)
		return;

	//※対象のポインタにnullptrが入っていたら何もしないでreturn
	if (m_members[id] == nullptr)
		return;

	//対象を削除する
	delete m_members[id];

	//対処のポインタにnullptrを入れる
	m_members[id] = nullptr;
}

/*******************************************************************************
* 簡易的な一覧の表示
*******************************************************************************/
void Guild::ViewMembers()
{
	for (int i = 0; i < m_member_max; i++)
		ViewCharacterList(i);
}


/*******************************************************************************
* 検索例：名前で検索
*******************************************************************************/
int Guild::GetMemberByName(std::string name, int start_id)
{
	if (start_id < 0 || start_id >= m_member_max)
		return -1;

	for (int i = start_id; i < m_member_max; i++)
	{
		if (m_members[i] == nullptr)
			continue;

		if (m_members[i]->GetName() == name)
			return i;
	}

	return -1;
}

/*******************************************************************************
* キャラクターの詳細な情報表示
*******************************************************************************/
int Guild::ViewCharacter(int id)
{
	if (id < 1 || id > m_member_max)
		return -1;
	if (!m_members[id - 1])
		return -1;

	std::cout << "\n　ID : " << id << std::endl;
	std::cout << "　名前 : " << m_members[id - 1]->GetName() << std::endl;
	std::cout << "　レベル : " << m_members[id - 1]->GetLv() << std::endl;
	std::cout << "　性別 : " << m_members[id - 1]->GetGen() << std::endl;
	std::cout << "　職業 : " << m_members[id - 1]->GetJob() << std::endl;
	std::cout << "　HP : " << m_members[id - 1]->GetHp() << std::endl;
	std::cout << "　MP : " << m_members[id - 1]->GetMp() << std::endl;
	std::cout << "　ATK : " << m_members[id - 1]->GetAtk() << std::endl;
	std::cout << "　DEF : " << m_members[id - 1]->GetDef() << std::endl;
	std::cout << "　速さ : " << m_members[id - 1]->GetAgi() << std::endl;
	std::cout << "　器用度 : " << m_members[id - 1]->GetDex() << std::endl;
	std::cout << "　賢さ : " << m_members[id - 1]->GetIntel() << std::endl;
	std::cout << "　信仰度 : " << m_members[id - 1]->GetPie() << std::endl;

	return id;
}

/*******************************************************************************
* キャラクターの取得
*******************************************************************************/
Character* Guild::GetCharacter(int id)
{
	if (id - 1 < 0) { return nullptr; }

	return m_members[id - 1];
}


/*******************************************************************************
* 簡易的なキャラクターの情報表示
*******************************************************************************/
void Guild::ViewCharacterList(int id)
{
	if (!m_members[id])
	{
		std::cout << id + 1 << " : " << "募集中" << std::endl;
		return;
	}

	std::cout << id + 1 << " : " << m_members[id]->GetName();
	std::cout << " Lv " << m_members[id]->GetLv();
	std::cout << " " << m_members[id]->GetGen();
	std::cout << " " << m_members[id]->GetJob() << std::endl;
}

/*******************************************************************************
* ソート機能
*******************************************************************************/
void Guild::StatusSortGuildMember(int num , bool flag)
{
	//配列の中身を入れ替え
	switch (num) {
	case 1:
		if(flag) std::sort(m_members, m_members + m_member_max, CompareAscByLv);
		else std::sort(m_members, m_members + m_member_max, CompareDesByLv);
		break;
	case 2:
		if (flag) std::sort(m_members, m_members + m_member_max, CompareAscByHp);
		else std::sort(m_members, m_members + m_member_max, CompareDesByHp);		
		break;
	case 3:
		if (flag) std::sort(m_members, m_members + m_member_max, CompareAscByMp);
		else std::sort(m_members, m_members + m_member_max, CompareDesByMp);		
		break;
	case 4:
		if (flag) std::sort(m_members, m_members + m_member_max, CompareAscByAtk);
		else std::sort(m_members, m_members + m_member_max, CompareDesByAtk);		
		break;
	case 5:
		if (flag) std::sort(m_members, m_members + m_member_max, CompareAscByDef);
		else std::sort(m_members, m_members + m_member_max, CompareDesByDef);		
		break;
	case 6:
		if (flag) std::sort(m_members, m_members + m_member_max, CompareAscByAgi);
		else std::sort(m_members, m_members + m_member_max, CompareDesByAgi);		
		break;
	case 7:
		if (flag) std::sort(m_members, m_members + m_member_max, CompareAscByDex);
		else std::sort(m_members, m_members + m_member_max, CompareDesByDex);		
		break;
	case 8:
		if (flag) std::sort(m_members, m_members + m_member_max, CompareAscByIntel);
		else std::sort(m_members, m_members + m_member_max, CompareDesByIntel);		
		break;
	case 9:
		if (flag) std::sort(m_members, m_members + m_member_max, CompareAscByPie);
		else std::sort(m_members, m_members + m_member_max, CompareDesByPie);		
		break;
	}

	// ソート後の一覧表示
	ViewSortedMembers(num);
}

/*******************************************************************************
* ギルド全体のセーブ
*******************************************************************************/
void Guild::SaveGuild(const std::string& filename)
{
	// ファイルを開く
	std::ofstream ofs(filename, std::ios::binary);
	if (!ofs) {
		std::cerr << "ファイルを開けませんでした: " << filename << std::endl;
		return;
	}

	// メンバー数をファイルに書き込む
	ofs.write(reinterpret_cast<const char*>(&m_member_max), sizeof(m_member_max));

	// 各メンバーを順番に保存する
	for (int i = 0; i < m_member_max; ++i) {
		if (m_members[i] != nullptr) {
			bool hasMember = true;
			ofs.write(reinterpret_cast<const char*>(&hasMember), sizeof(hasMember)); // メンバーが存在するかどうかのフラグ
			m_members[i]->SaveCharacter(ofs); // キャラクターを保存する
		}
		else {
			bool hasMember = false;
			ofs.write(reinterpret_cast<const char*>(&hasMember), sizeof(hasMember)); // メンバーがいない場合
		}
	}

	// ファイルを閉じる
	ofs.close();
}

/*******************************************************************************
* ギルド全体のロード
*******************************************************************************/
void Guild::LoadGuild(const std::string& filename)
{
	// ファイルを開く
	std::ifstream ifs(filename, std::ios::binary);
	if (!ifs) {
		std::cerr << "ファイルを開けませんでした: " << filename << std::endl;
		return;
	}

	// メンバー数をファイルから読み込む
	ifs.read(reinterpret_cast<char*>(&m_member_max), sizeof(m_member_max));

	// 既存のメンバーを削除する（メモリリークを防ぐため）
	for (int i = 0; i < m_member_max; ++i) {
		if (m_members[i] != nullptr) {
			delete m_members[i];
			m_members[i] = nullptr;
		}
	}

	// 新しくメンバー用のメモリを確保
	m_members = new Character * [m_member_max];

	// 各メンバーを順番にロードする
	for (int i = 0; i < m_member_max; ++i) {
		bool hasMember = false;
		ifs.read(reinterpret_cast<char*>(&hasMember), sizeof(hasMember)); // メンバーが存在するかどうかのフラグ

		if (hasMember) {
			m_members[i] = new Character(); // 新しいキャラクターオブジェクトを作成
			m_members[i]->LoadCharacter(ifs); // キャラクターをロード
		}
		else {
			m_members[i] = nullptr; // メンバーがいない場合は nullptr を設定
		}
	}

	// ファイルを閉じる
	ifs.close();
}


/*******************************************************************************
* 簡易的な一覧の表示 (ソート後)
*******************************************************************************/
void Guild::ViewSortedMembers(int num)
{
	for (int id = 0; id < m_member_max; id++)
	{
		if (!m_members[id])
		{
			std::cout << id + 1 << " : " << "募集中" << std::endl;
			return;
		}

		std::cout << id + 1 << " : " << m_members[id]->GetName();
		std::cout << " Lv " << m_members[id]->GetLv();
		std::cout << " " << m_members[id]->GetGen();
		std::cout << " " << m_members[id]->GetJob() << std::endl;

	}
}

/*******************************************************************************
* ソート機能中身
*******************************************************************************/
//レベル
bool Guild::CompareAscByLv(Character* a, Character* b) {
	if (!a) return false;
	if (!b) return true;
	return a->GetLv() < b->GetLv();
}
bool Guild::CompareDesByLv(Character* a, Character* b) {
	if (!a) return false;
	if (!b) return true;
	return a->GetLv() > b->GetLv();
}

//HP
bool Guild::CompareAscByHp(Character* a, Character* b) {
	if (!a) return false;
	if (!b) return true;
	return a->GetHp() < b->GetHp();
}
bool Guild::CompareDesByHp(Character* a, Character* b) {
	if (!a) return false;
	if (!b) return true;
	return a->GetHp() > b->GetHp();
}

//MP
bool Guild::CompareAscByMp(Character* a, Character* b) {
	if (!a) return false;
	if (!b) return true;
	return a->GetMp() < b->GetMp();
}
bool Guild::CompareDesByMp(Character* a, Character* b) {
	if (!a) return false;
	if (!b) return true;
	return a->GetMp() > b->GetMp();
}
//ATK
bool Guild::CompareAscByAtk(Character* a, Character* b) {
	if (!a) return false;
	if (!b) return true;
	return a->GetAtk() < b->GetAtk();
}
bool Guild::CompareDesByAtk(Character* a, Character* b) {
	if (!a) return false;
	if (!b) return true;
	return a->GetAtk() > b->GetAtk();
}

//DEF
bool Guild::CompareAscByDef(Character* a, Character* b) {
	if (!a) return false;
	if (!b) return true;
	return a->GetDef() < b->GetDef();
}
bool Guild::CompareDesByDef(Character* a, Character* b) {
	if (!a) return false;
	if (!b) return true;
	return a->GetDef() > b->GetDef();
}

//AGI
bool Guild::CompareAscByAgi(Character* a, Character* b) {
	if (!a) return false;
	if (!b) return true;
	return a->GetAgi() < b->GetAgi();
}
bool Guild::CompareDesByAgi(Character* a, Character* b) {
	if (!a) return false;
	if (!b) return true;
	return a->GetAgi() > b->GetAgi();
}

//DEX
bool Guild::CompareAscByDex(Character* a, Character* b) {
	if (!a) return false;
	if (!b) return true;
	return a->GetDex() < b->GetDex();
}
bool Guild::CompareDesByDex(Character* a, Character* b) {
	if (!a) return false;
	if (!b) return true;
	return a->GetDex() > b->GetDex();
}

//INTEL
bool Guild::CompareAscByIntel(Character* a, Character* b) {
	if (!a) return false;
	if (!b) return true;
	return a->GetIntel() < b->GetIntel();
}
bool Guild::CompareDesByIntel(Character* a, Character* b) {
	if (!a) return false;
	if (!b) return true;
	return a->GetIntel() > b->GetIntel();
}

//PIE
bool Guild::CompareAscByPie(Character* a, Character* b) {
	if (!a) return false;
	if (!b) return true;
	return a->GetPie() < b->GetPie();
}
bool Guild::CompareDesByPie(Character* a, Character* b) {
	if (!a) return false;
	if (!b) return true;
	return a->GetPie() > b->GetPie();
}
