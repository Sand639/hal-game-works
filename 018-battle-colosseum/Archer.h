/*******************************************************************************
* タイトル:		弓使いヘッダー
* プログラム名:	Archer.h
* 作成者:		大槻　海斗
* 作成日:		2024/09/18〜
* 最終変更日:	2024/09/18
********************************************************************************/

#ifndef _ARCHER_H_
#define _ARCHER_H_

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include<string>
#include "Character.h"

/*******************************************************************************
* クラス定義
*******************************************************************************/
//弓使いクラス
class Archer : public Character
{
private:
	int m_max_pie = m_pie;
public:
	Archer();
	Archer(std::string name, std::string gen, std::string job,
		int hp, int mp, int atk, int def, int lv, int agi, int dex, int intel, int pie);

	Archer(const Character& character);

	~Archer() {};

	int Attack() override;

	void Defense(int atk) override;
};

#endif	//_ARCHER_H_