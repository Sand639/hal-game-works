#pragma once
/*******************************************************************************
* マクロ定義
*******************************************************************************/
#define NUM_LEVEL (3)

/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
void LevelItemInit(void);
void LevelItemUninit(void);
void LevelItemUpdate(void);
void LevelItemDraw(void);

void LevelItemCreate(float x, float y);
void LevelItemDelete(int id);

ITEM* GetLevelItem();
