/*******************************************************************************
* タイトル:		タイトルシーンのバックグラウンド制御ヘッダー
* プログラム名:	Result_BG.cpp
* 作成者:		大槻海斗
* 作成日:		2024/06/10〜
* 更新日		2024/07/08
********************************************************************************/

/*******************************************************************************
*　インクルードファイル
*******************************************************************************/
#include "main.h"
#include "sprite.h"
#include "picture.h"
#include "Result_BG.h"
#include "keyboard.h"
#include "Scene_Manager.h"


/*******************************************************************************
*　グローバル変数
*******************************************************************************/
static Picture* g_pResultBG[6];
static int choiceNum = 0;

/*******************************************************************************
*　初期化
*******************************************************************************/
void InitResultBG()
{

	//現在の選択している番号
	choiceNum = 0;

	//タイトル画面背景
	g_pResultBG[0] =
		new Picture(
			TextureLoad(L"asset\\texture\\リザルト画面.png"),
			{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f },
			{ SCREEN_WIDTH, SCREEN_HEIGHT },
			{ 1.0f, 1.0f, 1.0f, 1.0f },
			true
		);

	//ゲームをはじめる
	g_pResultBG[1] =
		new Picture(
			TextureLoad(L"asset\\texture\\タイトル画面に戻る.png"),
			{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 100.0f, 0.0f },
			{ 500.0f, 200.0f },
			{ 1.0f, 1.0f, 1.0f, 1.0f },
			true
		);
	g_pResultBG[1]->SetTextureSize({ 3.0f,3.0f });

	//ゲームをはじめる選択中
	g_pResultBG[2] =
		new Picture(
			TextureLoad(L"asset\\texture\\タイトル画面に戻る選択中.png"),
			{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 100.0f, 0.0f },
			{ 500.0f, 200.0f },
			{ 1.0f, 1.0f, 1.0f, 1.0f },
			true
		);
	g_pResultBG[2]->SetTextureSize({ 3.0f,3.0f });


	//ゲームをやめる
	g_pResultBG[3] =
		new Picture(
			TextureLoad(L"asset\\texture\\ゲームをやめる.png"),
			{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 300.0f, 0.0f },
			{ 500.0f, 200.0f },
			{ 1.0f, 1.0f, 1.0f, 1.0f },
			true
		);
	g_pResultBG[3]->SetTextureSize({ 3.0f,3.0f });


	//ゲームをやめる
	g_pResultBG[4] =
		new Picture(
			TextureLoad(L"asset\\texture\\ゲームをやめる選択中.png"),
			{ SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 300.0f, 0.0f },
			{ 500.0f, 200.0f },
			{ 1.0f, 1.0f, 1.0f, 1.0f },
			false
		);
	g_pResultBG[4]->SetTextureSize({ 3.0f,3.0f });

	//操作説明　選択
	g_pResultBG[5] =
		new Picture(
			TextureLoad(L"asset\\texture\\操作説明_選択.png"),
			{ SCREEN_WIDTH - 250.0f, SCREEN_HEIGHT - 250.0f, 0.0f },
			{ SCREEN_WIDTH, SCREEN_HEIGHT },
			{ 1.0f, 1.0f, 1.0f, 1.0f },
			true
		);
	g_pResultBG[5]->SetTextureSize();

}

/*******************************************************************************
*　描画
*******************************************************************************/
void DrawResultBG()
{

	bool input = false;

	if (Keyboard_IsKeyDownTrigger(KK_W) || Keyboard_IsKeyDownTrigger(KK_UP))
	{
		if (choiceNum > 0)
		{
			choiceNum--;
			input = true;
		}
	}
	else if (Keyboard_IsKeyDownTrigger(KK_S) || Keyboard_IsKeyDownTrigger(KK_DOWN))
	{
		if (choiceNum < 1)
		{
			choiceNum++;
			input = true;
		}
	}

	//ここのポーズ画面で選択肢表示
	//選択しているところは光らせたりなんかする
	if (input)
	{
		g_pResultBG[2]->SetIsActive(false);
		g_pResultBG[4]->SetIsActive(false);


		switch (choiceNum)
		{
		case 0:
			g_pResultBG[2]->SetIsActive(true);
			break;
		case 1:
			g_pResultBG[4]->SetIsActive(true);
			break;
		default:break;
		}
	}


	if (Keyboard_IsKeyDownTrigger(KK_ENTER))
	{
		//機能ごとに操作を追加
		switch (choiceNum)
		{
		case 0:		//はじめる
			SetScene(SCENE_TITLE);
			break;

		case 1:		//ゲームをやめる
			SendMessage(GetHWnd(), WM_CLOSE, 0, 0);
			break;
		default:break;
		}
	}

	for (int i = 0; i < 6; i++)
		g_pResultBG[i]->Draw();


}