/*******************************************************************************
* タイトル:		剣士ヘッダー
* プログラム名:	Kenshi.h
* 作成者:		大槻　海斗
* 作成日:		2024/09/18〜
* 最終変更日:	2024/09/18
********************************************************************************/

#ifndef _Kenshi_H_
#define _Kenshi_H_

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include<string>
#include "Character.h"

/*******************************************************************************
* クラス定義
*******************************************************************************/
//剣士クラス
class Kenshi : public Character
{
private:
	int m_max_atk = m_atk;
	bool m_use = false;
public:
	Kenshi();
	Kenshi(std::string name, std::string gen, std::string job,
		int hp, int mp, int atk, int def, int lv, int agi, int dex, int intel, int pie);

	Kenshi(const Character& character);

	~Kenshi() {};

	int Attack() override;

	void Defense(int atk) override;
};

#endif	//_Kenshi_H_