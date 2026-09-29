/*******************************************************************************
* タイトル:		HPゲージクラス
* プログラム名:	UI_HP.cpp
* 作成者:		大槻　海斗
* 作成日:		2025/01/29 ～
* 最終変更日:	2025/01/29
********************************************************************************/

/*******************************************************************************
* インクルードファイル
********************************************************************************/
#include "stdafx.h"
#include "UI_HP.h"
#include "World.h"

UI_HP::UI_HP(const Float2& location)
	: GameObject("UI_HP", location)
{

}

/*******************************************************************************
* 更新処理
********************************************************************************/
void UI_HP::Update()
{
	GameObjects objects = GetWorld()->GetGameObjects("PLAYER");

	SetLocation(objects.front()->GetLocation());
	SetLocation({ GetLocation().x,GetLocation().y - 50.0f});

	if (objects.front()->GetHP() <= 0) {
		SetDestroy(true);
	}
	else {
	
		m_adjustSize = objects.front()->GetHP() /(float)100;

		m_adjustPos = ((100 - objects.front()->GetHP()) / (float)2) / (float)100;
		m_adjustPos = m_texture01.size().x * m_adjustPos;
	}


}

/*******************************************************************************
* 描画処理
********************************************************************************/
void UI_HP::Draw() const
{
	m_texture02.drawAt(GetLocation());

	m_texture01.resized(m_texture01.size().x * m_adjustSize, m_texture01.size().y).drawAt(GetLocation().x - m_adjustPos, GetLocation().y);
}
