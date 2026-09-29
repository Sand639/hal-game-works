/*******************************************************************************
* タイトル:		バトル
* プログラム名:	Battle->cpp
* 作成者:		大槻　海斗
* 作成日:		2024/09/06 〜
* 最終変更日:	2024/09/06
********************************************************************************/

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include "Battle.h"
#include "Wizard.h"
#include "Archer.h"
#include "Kenshi.h"
#include <iostream>

/*******************************************************************************
*　コンストラクタ
*******************************************************************************/
Battle::Battle(Character* pFighterA, Character* pFighterB)
{
	m_Fighters[0] = pFighterA;
	m_Fighters[1] = pFighterB;

	for (int i = 0; i < 2; i++)
	{
		m_Fighters[i] = CharacterFactory(m_Fighters[i]->GetType(), i);
	}
}

Character* Battle::CharacterFactory(int type, int i)
{
	Character* pCharacter = nullptr;

	switch (type)
	{
	case 0:
	default:
		pCharacter = new Character(
			m_Fighters[i]->GetName(), m_Fighters[i]->GetGen(),
			m_Fighters[i]->GetJob(), m_Fighters[i]->GetHp(),
			m_Fighters[i]->GetMp(), m_Fighters[i]->GetAtk(),
			m_Fighters[i]->GetDef(), m_Fighters[i]->GetLv(),
			m_Fighters[i]->GetAgi(), m_Fighters[i]->GetDex(),
			m_Fighters[i]->GetIntel(), m_Fighters[i]->GetPie()
			);
		break;
	case 1:
		pCharacter = new Wizard(
			m_Fighters[i]->GetName(), m_Fighters[i]->GetGen(),
			m_Fighters[i]->GetJob(), m_Fighters[i]->GetHp(),
			m_Fighters[i]->GetMp(), m_Fighters[i]->GetAtk(),
			m_Fighters[i]->GetDef(), m_Fighters[i]->GetLv(),
			m_Fighters[i]->GetAgi(), m_Fighters[i]->GetDex(),
			m_Fighters[i]->GetIntel(), m_Fighters[i]->GetPie()
		);
		break;
	case 2:
		pCharacter = new Archer(
			m_Fighters[i]->GetName(), m_Fighters[i]->GetGen(),
			m_Fighters[i]->GetJob(), m_Fighters[i]->GetHp(),
			m_Fighters[i]->GetMp(), m_Fighters[i]->GetAtk(),
			m_Fighters[i]->GetDef(), m_Fighters[i]->GetLv(),
			m_Fighters[i]->GetAgi(), m_Fighters[i]->GetDex(),
			m_Fighters[i]->GetIntel(), m_Fighters[i]->GetPie()
		);
		break;
	case 3:
		pCharacter = new Kenshi(
			m_Fighters[i]->GetName(), m_Fighters[i]->GetGen(),
			m_Fighters[i]->GetJob(), m_Fighters[i]->GetHp(),
			m_Fighters[i]->GetMp(), m_Fighters[i]->GetAtk(),
			m_Fighters[i]->GetDef(), m_Fighters[i]->GetLv(),
			m_Fighters[i]->GetAgi(), m_Fighters[i]->GetDex(),
			m_Fighters[i]->GetIntel(), m_Fighters[i]->GetPie()
		);
		break;
	}

	return pCharacter;
}

#include <Windows.h>

/*******************************************************************************
* バトル
*******************************************************************************/
void Battle::Fight()
{
	bool loop = true;
	int turn = 0;
	int StackSpeed[2] = {};
	int AttackTurn = 0;
	int DefenceTurn = 1;

	system("cls");

	std::cout << "\n　" << m_Fighters[0]->GetName() << "\nと";
	std::cout << "\n　" << m_Fighters[1]->GetName() << "\nの戦いが始まった！" << std::endl;

	Sleep(DELAY);

	while (m_Fighters[0]->GetHp() > 0 && m_Fighters[1]->GetHp() > 0)
	{
		system("cls");

		//先に100を超えたほうが攻撃
		if (StackSpeed[0] >= StackSpeed[1] && StackSpeed[0] >= 100)
		{
			AttackTurn = 0;
			DefenceTurn = 1;
			StackSpeed[0] -= 100;
		}
		else if (StackSpeed[1] >= StackSpeed[0] && StackSpeed[1] >= 100)
		{
			AttackTurn = 1;
			DefenceTurn = 0;
			StackSpeed[1] -= 100;
		}
		else
		{
			StackSpeed[0] += m_Fighters[0]->GetAgi();
			StackSpeed[1] += m_Fighters[1]->GetAgi();
			continue;
		}

		//ポリモーフィズム
		m_Fighters[DefenceTurn]->Defense(m_Fighters[AttackTurn]->Attack());

		Sleep(DELAY);
	}

	if (m_Fighters[0]->GetHp() <= 0)
	{
		std::cout << "\n　" << m_Fighters[0]->GetName() << "は倒れた..." << std::endl;
		std::cout << "\n　" << m_Fighters[1]->GetName() << "の勝利！" << std::endl;
	}
	else
	{
		std::cout << "\n　" << m_Fighters[1]->GetName() << "は倒れた..." << std::endl;
		std::cout << "\n　" << m_Fighters[0]->GetName() << "の勝利！" << std::endl;
	}

}
