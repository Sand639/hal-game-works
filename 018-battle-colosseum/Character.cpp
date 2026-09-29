/*******************************************************************************
* タイトル:		キャラクタ―プログラム
* プログラム名:	Character.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/05/31 ～
* 最終変更日:	2024/09/15
********************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "Character.h"
#include <iostream>
#include <fstream>
#include <string>

//コンストラクタ
Character::Character()
{

}

//引数付きコンストラクタ
Character::Character(std::string name, std::string gen, std::string job,
	int hp, int mp, int atk, int def,  int lv, int agi, int dex, int intel, int pie) :
	m_name(name), m_gen(gen), m_job(job), m_hp(hp), m_mp(mp),
	m_atk(atk), m_def(def), m_lv(lv), m_agi(agi), m_dex(dex), m_intel(intel), m_pie(pie)
{

}

//デストラクタ
Character::~Character()
{

}

void Character::SetName(std::string name)
{
	m_name = name;
}

std::string Character::GetName()
{
	return m_name;
}

void Character::SetGen(std::string gen)
{
	m_gen = gen;
}

std::string Character::GetGen()
{
	return m_gen;
}

void Character::SetJob(std::string job)
{
	m_job = job;
}

std::string Character::GetJob()
{
	return m_job;
}

void Character::SetHp(int hp)
{
	m_hp = hp;
}

int Character::GetHp()
{
	return m_hp;
}

void Character::SetMp(int mp)
{
	m_mp = mp;
}

int Character::GetMp()
{
	return m_mp;
}

void Character::SetAtk(int atk)
{
	m_atk = atk;
}

int Character::GetAtk()
{
	return m_atk;
}

void Character::SetDef(int def)
{
	m_def = def;
}

int Character::GetDef()
{
	return m_def;
}

void Character::SetLv(int lv)
{
	m_lv = lv;
}

int Character::GetLv()
{
	return m_lv;
}

void Character::SetAgi(int agi)
{
	m_agi = agi;
}

int Character::GetAgi()
{
	return m_agi;
}

void Character::SetDex(int dex)
{
	m_dex = dex;
}

int Character::GetDex()
{
	return m_dex;
}

void Character::SetIntel(int intel)
{
	m_intel = intel;
}

int Character::GetIntel()
{
	return m_intel;
}

void Character::SetPie(int pie)
{
	m_pie = pie;
}

int Character::GetPie()
{
	return m_pie;
}

void Character::SeType(int type)
{
	m_type = type;
}

int Character::GetType()
{
	return m_type;
}

//SetJob関数があるため下の方でインクルード
#include <Windows.h>

int Character::Attack()
{
	std::cout << "\n　" << m_name << "のターン" << std::endl;

	Sleep(DELAY);
	std::cout << "\n　" << m_name << "の攻撃！" << std::endl;
	return m_atk;
}

void Character::Defense(int atk)
{
	Sleep(DELAY);

	int PIE = (rand() % 100) + 1;

	//回避！
	if ((m_pie / 10) >= PIE)
	{
		std::cout << "\n　しかし、" << m_name << "は回避した！" << std::endl;
		return;
	}

	int Damage = atk;
	std::cout << "\n　" << m_name << "に";

	float def = m_def;

	def /= 100;
	if(def == 0){/*defが0なら何もしない*/}
	else if (def >= 0.5)
		Damage /= 2;
	else
		Damage *= (1 - def);

	m_hp -= Damage;

	std::cout << Damage << "ダメージ！" << std::endl;

	Sleep(DELAY);

	std::cout <<"\n　" << m_name << "の残りHPは" << m_hp << "だ！" << std::endl;
}

void Character::SaveCharacter(std::ofstream& ofs)
{
	// メンバー変数をファイルに書き込む
	std::size_t stringLength = m_name.size();
	ofs.write(reinterpret_cast<const char*>(&stringLength), sizeof(stringLength));
	ofs.write(m_name.c_str(), stringLength);

	ofs.write(reinterpret_cast<const char*>(&m_hp), sizeof(m_hp));
	ofs.write(reinterpret_cast<const char*>(&m_mp), sizeof(m_mp));
	ofs.write(reinterpret_cast<const char*>(&m_atk), sizeof(m_atk));
	ofs.write(reinterpret_cast<const char*>(&m_def), sizeof(m_def));

	stringLength = m_gen.size();
	ofs.write(reinterpret_cast<const char*>(&stringLength), sizeof(stringLength));
	ofs.write(m_gen.c_str(), stringLength);

	stringLength = m_job.size();
	ofs.write(reinterpret_cast<const char*>(&stringLength), sizeof(stringLength));
	ofs.write(m_job.c_str(), stringLength);

	ofs.write(reinterpret_cast<const char*>(&m_lv), sizeof(m_lv));
	ofs.write(reinterpret_cast<const char*>(&m_agi), sizeof(m_agi));
	ofs.write(reinterpret_cast<const char*>(&m_dex), sizeof(m_dex));
	ofs.write(reinterpret_cast<const char*>(&m_intel), sizeof(m_intel));
	ofs.write(reinterpret_cast<const char*>(&m_pie), sizeof(m_pie));
	ofs.write(reinterpret_cast<const char*>(&m_type), sizeof(m_type));
}

void Character::LoadCharacter(std::ifstream& ifs)
{

	// メンバー変数をファイルから読み込む
	std::size_t stringLength;

	ifs.read(reinterpret_cast<char*>(&stringLength), sizeof(stringLength));
	m_name.resize(stringLength);
	ifs.read(&m_name[0], stringLength);

	ifs.read(reinterpret_cast<char*>(&m_hp), sizeof(m_hp));
	ifs.read(reinterpret_cast<char*>(&m_mp), sizeof(m_mp));
	ifs.read(reinterpret_cast<char*>(&m_atk), sizeof(m_atk));
	ifs.read(reinterpret_cast<char*>(&m_def), sizeof(m_def));

	ifs.read(reinterpret_cast<char*>(&stringLength), sizeof(stringLength));
	m_gen.resize(stringLength);
	ifs.read(&m_gen[0], stringLength);

	ifs.read(reinterpret_cast<char*>(&stringLength), sizeof(stringLength));
	m_job.resize(stringLength);
	ifs.read(&m_job[0], stringLength);

	ifs.read(reinterpret_cast<char*>(&m_lv), sizeof(m_lv));
	ifs.read(reinterpret_cast<char*>(&m_agi), sizeof(m_agi));
	ifs.read(reinterpret_cast<char*>(&m_dex), sizeof(m_dex));
	ifs.read(reinterpret_cast<char*>(&m_intel), sizeof(m_intel));
	ifs.read(reinterpret_cast<char*>(&m_pie), sizeof(m_pie));
	ifs.read(reinterpret_cast<char*>(&m_type), sizeof(m_type));

}
