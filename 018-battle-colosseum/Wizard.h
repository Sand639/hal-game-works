/*******************************************************************************
* タイトル:		魔法使いヘッダー
* プログラム名:	Wizrad.h
* 作成者:		大槻　海斗
* 作成日:		2024/09/16〜
* 最終変更日:	2024/09/16
********************************************************************************/

#ifndef _WIZARD_H_
#define _WIZARD_H_

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include<string>
#include "Character.h"

/*******************************************************************************
* クラス定義
*******************************************************************************/
//魔法使いクラス
class Wizard : public Character
{
private:
	int m_max_mp = m_mp;
	int m_max_def = m_def;
	int m_max_hp = m_hp;
public:
	Wizard();
	Wizard(std::string name, std::string gen, std::string job,
		int hp, int mp, int atk, int def, int lv, int agi, int dex, int intel, int pie);

	Wizard(const Character& character);

	~Wizard() {};

	int Attack() override;

	void Defense(int atk) override;
};

#endif	//_WIZARD_H_