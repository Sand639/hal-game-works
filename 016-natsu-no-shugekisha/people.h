//=====================================//
// people.h
// 大槻海斗
// 2024/06/05〜
//=====================================//

#ifndef _PEOPLE_H_
#define _PEOPLE_H_

#include "main.h"


/*******************************************************************************
*　マクロ
******************************************************************************/
#define PEOPLE_MAX (50)		//最大ブロック数
#define PEOPLE_WIDTH (60.0f)	//ブロックの幅
#define PEOPLE_HIGHT (60.0f)	//ブロックの高さ
#define PEOPLE_NUM_X (16)	//横に連なるブロック数
#define PEOPLE_NUM_Y (9)	//縦に連なるブロック数
#define PEOPLE_TYPE_MAX	(3)	//テクスチャの数
#define PEOPLE_MOVE_TIME (60)//1行動の時間

/*******************************************************************************
*　クラス
******************************************************************************/

class People
{
private:

public:
	int HP;
	XMFLOAT3 pos;	// 座標
	XMFLOAT3 oldpos;// 1フレーム前の座標
	XMFLOAT2 vel;	// 移動値
	XMFLOAT2 size;	// サイズ
	bool use;		// 使用フラグ
	int	type;		//ブロック種類
	int frm;
	bool move;
	int value;

	People();
	~People();

	void Update();
	void Draw();

	void MinusHP();
};


/*******************************************************************************
*　プロトタイプ宣言
*******************************************************************************/

void SetPeople();
void InitPeople(void);
void UpadatePeople(void);
void UninitPeople(void);
People* GetPeople(void);


#endif


