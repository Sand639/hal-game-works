/*******************************************************************************
* タイトル:		ポーズ画面
* プログラム名:	UI_pause.cpp
* 作成者:		大槻　海斗
* 作成日:		2025/01/12 〜
* 最終変更日:	2025/01/12
********************************************************************************/

/********************************************************************************
* インクルードファイル
********************************************************************************/
#include "UI_pause.h"
#include "texture.h"
#include "keyboard.h"
#include "Scene_Game.h"
#include "main.h"

/*******************************************************************************
*　初期化処理
*******************************************************************************/
void Pause::Init()
{
	//ポーズ画面背景
	m_pausePicture[0] =
		new Picture(
			TextureLoad(L"asset\\texture\\Gray.png"),
			{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f },
			{ SCREEN_WIDTH, SCREEN_HEIGHT },
			{ 1.0f, 1.0f, 1.0f, 0.3f },
			true
		);

	//ゲームに戻る
	m_pausePicture[1] =
		new Picture(
			TextureLoad(L"asset\\texture\\ゲームに戻る.png"),
			{ SCREEN_WIDTH / 2, 300.0f, 0.0f },
			{ SCREEN_WIDTH, SCREEN_HEIGHT },
			{ 1.0f, 1.0f, 1.0f, 1.0f },
			true
		);
	m_pausePicture[1]->SetTextureSize();

	//ゲームに戻る選択中
	m_pausePicture[2] =
		new Picture(
			TextureLoad(L"asset\\texture\\ゲームに戻る選択中.png"),
			{ SCREEN_WIDTH / 2, 300.0f, 0.0f },
			{ SCREEN_WIDTH, SCREEN_HEIGHT },
			{ 1.0f, 1.0f, 1.0f, 1.0f },
			true
		);
	m_pausePicture[2]->SetTextureSize();

	//はじめからやりなおす
	m_pausePicture[3] =
		new Picture(
			TextureLoad(L"asset\\texture\\はじめからやりなおす.png"),
			{ SCREEN_WIDTH / 2, 600.0f, 0.0f },
			{ SCREEN_WIDTH, SCREEN_HEIGHT },
			{ 1.0f, 1.0f, 1.0f, 1.0f },
			true
		);
	m_pausePicture[3]->SetTextureSize();

	//はじめからやりなおす選択中
	m_pausePicture[4] =
		new Picture(
			TextureLoad(L"asset\\texture\\はじめからやりなおす選択中.png"),
			{ SCREEN_WIDTH / 2, 600.0f, 0.0f },
			{ SCREEN_WIDTH, SCREEN_HEIGHT },
			{ 1.0f, 1.0f, 1.0f, 1.0f },
			false
		);
	m_pausePicture[4]->SetTextureSize();

	//ゲームをやめる
	m_pausePicture[5] =
		new Picture(
			TextureLoad(L"asset\\texture\\ゲームをやめる.png"),
			{ SCREEN_WIDTH / 2, 900.0f, 0.0f },
			{ SCREEN_WIDTH, SCREEN_HEIGHT },
			{ 1.0f, 1.0f, 1.0f, 1.0f },
			true
		);
	m_pausePicture[5]->SetTextureSize();

	//ゲームをやめる選択中
	m_pausePicture[6] =
		new Picture(
			TextureLoad(L"asset\\texture\\ゲームをやめる選択中.png"),
			{ SCREEN_WIDTH / 2, 900.0f, 0.0f },
			{ SCREEN_WIDTH, SCREEN_HEIGHT },
			{ 1.0f, 1.0f, 1.0f, 1.0f },
			false
		);
	m_pausePicture[6]->SetTextureSize();

	//操作説明　選択
	m_pausePicture[7] =
		new Picture(
			TextureLoad(L"asset\\texture\\操作説明_選択.png"),
			{ SCREEN_WIDTH - 250.0f, SCREEN_HEIGHT - 250.0f, 0.0f },
			{ SCREEN_WIDTH, SCREEN_HEIGHT },
			{ 1.0f, 1.0f, 1.0f, 1.0f },
			true
		);
	m_pausePicture[7]->SetTextureSize();

}

/*******************************************************************************
*　終了処理
*******************************************************************************/
void Pause::Uninit()
{
	for (int i = 0; i < 8; i++)
	{
		if (m_pausePicture[i]) {
			delete m_pausePicture[i];
			m_pausePicture[i] = nullptr;
		}
	}
}

/*******************************************************************************
*　更新処理
*******************************************************************************/
void Pause::Update()
{
	if (!m_isPause)
		return;

	//選択
	if (Keyboard_IsKeyDownTrigger(KK_W) || Keyboard_IsKeyDownTrigger(KK_UP))
	{
		if (m_choiceNum > 0)
		{
			m_choiceNum--;
		}
	}
	else if (Keyboard_IsKeyDownTrigger(KK_S) || Keyboard_IsKeyDownTrigger(KK_DOWN))
	{
		if (m_choiceNum < 2)
		{
			m_choiceNum++;
		}
	}

	m_pausePicture[2]->SetIsActive(false);
	m_pausePicture[4]->SetIsActive(false);
	m_pausePicture[6]->SetIsActive(false);

	switch (m_choiceNum)
	{
	case 0:
		m_pausePicture[2]->SetIsActive(true);
		break;
	case 1:
		m_pausePicture[4]->SetIsActive(true);
		break;
	case 2:
		m_pausePicture[6]->SetIsActive(true);
	default:
		break;
	}

	//決定
	if (Keyboard_IsKeyDownTrigger(KK_ENTER))
	{
		switch (m_choiceNum)
		{
		case 0:		//ゲームに戻る
			ChangePause();
			break;

		case 1:		//はじめからやりなおす
			SetGameScene(GAME_MAIN);
			break;
		case 2:		//ゲームをやめる
			SendMessage(GetHWnd(), WM_CLOSE, 0, 0);

		default:break;
		}
	}

}

/*******************************************************************************
*　描画処理
*******************************************************************************/
void Pause::Draw()
{
	if (!m_isPause)
		return;

	for (int i = 0; i < 8; i++)
		m_pausePicture[i]->Draw();

}

/*******************************************************************************
*　ポーズ切替
*******************************************************************************/
bool Pause::ChangePause()
{
	if (m_isPause) {
		m_isPause = false;
		return false;
	}
	else {
		m_isPause = true;
		return true;
	}
}

bool Pause::GetPause()
{
	return m_isPause;
}

