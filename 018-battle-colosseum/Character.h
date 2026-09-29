/*******************************************************************************
* タイトル:		キャラクタ―ヘッダー
* プログラム名:	Character.h
* 作成者:		大槻　海斗
* 作成日:		2024/05/31 〜
* 最終変更日:	2024/09/15
********************************************************************************/

#ifndef _CHARACTER_H_
#define _CHARACTER_H_

/*******************************************************************************
* インクルードファイル
*******************************************************************************/
#include<string>

/*******************************************************************************
* マクロ定義
*******************************************************************************/
#define DELAY (1000)

/*******************************************************************************
* クラス定義
*******************************************************************************/
//キャラクタークラス
class Character
{
protected:
	std::string m_name = "不明";	//名前
	std::string m_gen = "不明";		//性別
	std::string m_job = "不明";		//職業
	int m_hp = 0;	//体力
	int m_mp = 0;	//魔力
	int m_atk = 0;	//攻撃力
	int m_def = 0;	//防御力
	int m_lv = 0;	//レベル×
	int m_agi = 0;	//素早さ
	int m_dex = 0;	//器用さ×
	int m_intel = 0;//賢さ×
	int m_pie = 0;	//信仰度×

	int m_type = 0;
	//0 駆け出し冒険者(Characterクラス)
	//1 魔法使い(Wizardクラス)
public:
	Character();
	Character(std::string name, std::string gen, std::string job,
		int hp, int mp, int atk, int def, int lv, int agi, int dex, int intel, int pie);
		~Character();
	void SetName(std::string name);
	std::string GetName();
	void SetGen(std::string gen);
	std::string GetGen();
	void SetJob(std::string job);
	std::string GetJob();
	void SetHp(int hp);
	int GetHp();
	void SetMp(int mp);
	int GetMp();
	void SetAtk(int atk);
	int GetAtk();
	void SetDef(int def);
	int GetDef();
	void SetLv(int lv);
	int GetLv();
	void SetAgi(int agi);
	int GetAgi();
	void SetDex(int dex);
	int GetDex();
	void SetIntel(int intel);
	int GetIntel();
	void SetPie(int pie);
	int GetPie();
	void SeType(int type);
	int GetType();

	virtual int Attack();

	virtual void Defense(int atk);

	void SaveCharacter(std::ofstream& ofs);
	void LoadCharacter(std::ifstream& ifs);


};

#endif