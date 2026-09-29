/*******************************************************************************
* タイトル:		UI制御
* プログラム名:	UI_Manager.h
* 作成者:		大槻海斗
* 作成日:		2024/12/21〜
* 更新日		2024/12/21
*******************************************************************************/
#pragma once
/*******************************************************************************
*　前方宣言
*******************************************************************************/
class Score;
class Pause;
class Time;

/*******************************************************************************
*　クラス定義
*******************************************************************************/
class UI_Manager {

private:

	//UIを持たせる
	Score* m_score = nullptr;
	Pause* m_pause = nullptr;
	Time* m_time = nullptr;

public:

	UI_Manager() = default;
	~UI_Manager() = default;

	void Init();
	void Uninit();
	void Update();
	void Draw() const;

	Score* GetScore() { return m_score; }
	Pause* GetPause() { return m_pause; }
	Time* GetTime() { return m_time; }
};


