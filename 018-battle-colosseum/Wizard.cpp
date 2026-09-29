/*******************************************************************************
* タイトル:		魔法使いプログラム
* プログラム名:	Wizrad.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/09/16 〜
* 最終変更日:	2024/09/16
********************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "wizard.h"
#include <iostream>
#include <fstream>

/*******************************************************************************
*　コンストラクタ
*******************************************************************************/
Wizard::Wizard():Character()
{
	SetJob("魔法使い");
	m_type = 1;
}

/*******************************************************************************
*　引数付きコンストラクタ
*******************************************************************************/
Wizard::Wizard(std::string name, std::string gen, std::string job,
	int hp, int mp, int atk, int def, int lv, int agi, int dex, int intel, int pie)
	: Character(name, gen, job, hp, mp, atk, def, lv, agi, dex, intel, pie) 
{
	m_max_mp = m_mp;
	m_max_def = m_def;
	m_max_hp = m_hp;
	m_type = 1;
}

/*******************************************************************************
*　引数付きコンストラクタ
*******************************************************************************/
Wizard::Wizard(const Character& character)
	: Character(character)
{
	m_max_mp = m_mp;
	m_max_def = m_def;
	m_max_hp = m_hp;
	m_type = 1;
}

//SetJob関数があるため下の方でインクルード
#include <Windows.h>

/*******************************************************************************
*　攻撃
*******************************************************************************/
int Wizard::Attack()
{
	std::cout << "\n　" << m_name << "のターン" << std::endl;

	Sleep(DELAY);

	int Select = (rand() % 3) + 1;

	if (m_mp < 10)
		Select = 1;
	if (Select == 3 && m_mp < 50)
		Select = 2;

	switch (Select)
	{
	case 1:
		//周りの物質からMPを集める
		//たとえ敵に攻撃をかわされても、MPは回復する
		std::cout << "\n　" << m_name << "のマジックハーベスト！" << std::endl;

		m_mp += m_atk;

		if (m_max_mp <= m_mp)
			m_mp = m_max_mp;

		return m_atk;
		break;

	case 2:
		//自身を風で守りながら
		//風に乗った砂利で相手の体力を削る
		std::cout << "\n　" << m_name << "のサイクロン！" << std::endl;

		m_mp -= 10;

		m_def *= 1.5;

		return m_atk * 1.5;

		break;

	case 3:
		//火属性の爆裂魔法。上級魔法が故に習得が困難
		//消費魔力が非常に多いがその分火力が桁違いな魔法
		std::cout << "\n　" << m_name << "のエクスプロージョン！" << std::endl;

		m_mp -= 50;

		return m_atk * 5;
		break;
	}
	return m_mp;
}

void Wizard::Defense(int atk)
{
	Sleep(DELAY);

	int PIE = (rand() % 100) + 1;

	//回避！
	if ((m_pie / 10) >= PIE)
	{
		std::cout << "\n　しかし、" << m_name << "は攻撃を吸収した" << std::endl;
		m_hp += atk;

		if (m_max_hp <= m_hp)
			m_hp = m_max_hp;

		std::cout << "\n　" << m_name << "の残りHPは" << m_hp << "だ！" << std::endl;
		return;
	}

	int Damage = atk;
	std::cout << "\n　" << m_name << "に";

	float def = m_def;

	def /= 100;
	if (def == 0) {/*defが0なら何もしない*/ }
	else if (def >= 0.5)
		Damage /= 2;
	else
		Damage *= (1 - def);

	m_hp -= Damage;

	std::cout << Damage << "ダメージ！" << std::endl;

	Sleep(DELAY);

	std::cout << "\n　" << m_name << "の残りHPは" << m_hp << "だ！" << std::endl;

	if (m_max_hp <= m_def)
		m_def = m_max_def;
}
