/*******************************************************************************
* タイトル:		剣士プログラム
* プログラム名:	Kenshi.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/09/18 〜
* 最終変更日:	2024/09/18
********************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "Kenshi.h"
#include <iostream>
#include <fstream>

/*******************************************************************************
*　コンストラクタ
*******************************************************************************/
Kenshi::Kenshi() :Character()
{
	SetJob("剣士");
	m_type = 3;
}

/*******************************************************************************
*　引数付きコンストラクタ
*******************************************************************************/
Kenshi::Kenshi(std::string name, std::string gen, std::string job,
	int hp, int mp, int atk, int def, int lv, int agi, int dex, int intel, int pie)
	: Character(name, gen, job, hp, mp, atk, def, lv, agi, dex, intel, pie)
{
	m_max_atk = m_atk;

	m_type = 3;
}

/*******************************************************************************
*　引数付きコンストラクタ
*******************************************************************************/
Kenshi::Kenshi(const Character& character)
	: Character(character)
{
	m_type = 3;
}

//SetJob関数があるため下の方でインクルード
#include <Windows.h>

/*******************************************************************************
*　攻撃
*******************************************************************************/
int Kenshi::Attack()
{
	static int count = 0;

	std::cout << "\n　" << m_name << "のターン" << std::endl;

	Sleep(DELAY);

	int Select = (rand() % 3) + 1;

	if ((Select == 2) && (m_use == true || count == 2))
		Select = 3;

	if (Select == 3 && m_mp < 10)
		Select = 1;

	if (count == 1)
	{
		m_use = false;
		count++;
	}
	else if (count == 2)
	{
		m_atk = m_max_atk;
	}

	switch (Select)
	{
	case 1:
		//シンプルな斬り攻撃
		std::cout << "\n　" << m_name << "の一文字！" << std::endl;

		return m_atk * 1.3f;
		break;

	case 2:
		//相手との間合いを見切る
		//次の攻撃をかわし、自分の攻撃を上げる
		std::cout << "\n　" << m_name << "の間合い！" << std::endl;

		m_use = true;
		count = 1;
		m_atk *= 2;

		return 0;

		break;

	case 3:

		//くうらいけん
		//鞘の中で刀を加速させ、ものすごい勢いで相手を斬る
		//斬られた相手は風すら感じないらしい
		std::cout << "\n　" << m_name << "の抜刀、空来剣！" << std::endl;

		m_mp -= 10;

		return m_atk * 3;
		break;
	}
	return m_atk;
}

void Kenshi::Defense(int atk)
{
	Sleep(DELAY);

	int PIE = (rand() % 100) + 1;

	//回避！
	if ((m_pie / 10) >= PIE || m_use == true)
	{
		std::cout << "\n　しかし、" << m_name << "は攻撃を受け流した" << std::endl;

		m_use = false;

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

}
