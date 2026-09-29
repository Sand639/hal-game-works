/*******************************************************************************
* タイトル:		時間アニメーション制御ヘッダー
* プログラム名:	time.h
* 作成者:		大槻海斗
* 作成日:		2025/01/13〜
* 更新日		2025/01/13
*******************************************************************************/

#pragma once
/********************************************************************************
* インクルードファイル
********************************************************************************/
#include "UI.h"

/*******************************************************************************
* クラス定義
*******************************************************************************/
class Time : public UI
{
private:
	int m_minute = 0;
	int m_second = 0;
	int m_millisecond = 0;

public:
	Time() = default;
	Time(const Time& other) {
		m_minute = other.m_minute;
		m_second = other.m_second;
		m_millisecond = other.m_millisecond;
	}

	void Init() override;
	void Uninit() override;
	void Update() override;
	void Draw() override;

	int GetMin() { return m_minute; }
	int GetSec() {return m_second;}
	int GetMilSec() { return m_millisecond; }
};




