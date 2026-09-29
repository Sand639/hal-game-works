/*******************************************************************************
* タイトル:		弓使いプログラム
* プログラム名:	Archer.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/09/18 〜
* 最終変更日:	2024/09/18
********************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "archer.h"
#include <iostream>
#include <fstream>

/*******************************************************************************
*　コンストラクタ
*******************************************************************************/
Archer::Archer() :Character()
{
	SetJob("弓使い");
	m_type = 2;
}

/*******************************************************************************
*　引数付きコンストラクタ
*******************************************************************************/
Archer::Archer(std::string name, std::string gen, std::string job,
	int hp, int mp, int atk, int def, int lv, int agi, int dex, int intel, int pie)
	: Character(name, gen, job, hp, mp, atk, def, lv, agi, dex, intel, pie)
{
	m_max_pie = m_pie;

	m_type = 2;
}

/*******************************************************************************
*　引数付きコンストラクタ
*******************************************************************************/
Archer::Archer(const Character& character)
	: Character(character)
{
	m_type = 2;
}

//SetJob関数があるため下の方でインクルード
#include <Windows.h>

/*******************************************************************************
*　攻撃
*******************************************************************************/
int Archer::Attack()
{
	std::cout << "\n　" << m_name << "のターン" << std::endl;

	Sleep(DELAY);

	int Select = (rand() % 3) + 1;

	if (Select == 3 && m_mp < 30)
		Select = 1;

	switch (Select)
	{
	case 1:
		//あまつかぜ
		//風に矢をのせて勢いをつけた攻撃
		//命中率はそのままで、火力が上がる
		std::cout << "\n　" << m_name << "の天つ風！" << std::endl;

		return m_atk * 1.2f;
		break;

	case 2:
		//こくふう
		//砂塵を巻き上げて相手の命中率を下げつつ
		//狙いを定めて相手を攻撃する
		std::cout << "\n　" << m_name << "の黒風！" << std::endl;

		m_pie *= 5;

		return m_atk * 0.5;

		break;

	case 3:
		//じんらいはたたがみ
		//矢に電気を載せて着弾点に激しい雷を落とす
		//消費魔力が多いが火力が高い
		std::cout << "\n　" << m_name << "の迅雷霹靂神" << std::endl;

		m_mp -= 30;

		return m_atk * 3;
		break;
	}
	return m_mp;
}

void Archer::Defense(int atk)
{
	Sleep(DELAY);

	int PIE = (rand() % 100) + 1;

	//回避！
	if ((m_pie / 10) >= PIE)
	{
		std::cout << "\n　しかし、" << m_name << "は攻撃をかわした" << std::endl;

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

	if (m_max_pie <= m_pie)
		m_pie = m_max_pie;
}
