/*******************************************************************************
* タイトル:		ゲームシーンメイン処理
* プログラム名:	Game_Main.cpp
* 作成者:		大槻　海斗
* 作成日:		2024/12/20 〜
* 最終変更日:	2025/01/12
********************************************************************************/

/*******************************************************************************
*　インクルードファイル
*******************************************************************************/
#include "sprite.h"
#include "light.h"
#include "Game_Main.h"
#include "cube.h"
#include "grid.h"
#include "keyboard.h"
#include "camera.h"
#include "camera_move.h"
#include "camera_rotation.h"
#include "model.h"
#include "collision.h"
#include "ball.h"
#include "ball_shot.h"
#include "billboard.h"
#include "trail.h"
#include "camera_follow.h"
#include "texture.h"
#include "UI_Manager.h"
#include "UI_pause.h"
#include "UI_time.h"
#include "Scene_Manager.h"
#include "Audio.h"

#include "MapParts.h"
#include "block_flag.h"

#include <list>

/*******************************************************************************
*　グローバル定数
*******************************************************************************/

//カメラ
static Camera* g_Camera;
static Camera* g_Camera2;

//ボール(プレイヤー)

static Ball* g_pBall = nullptr;

//テクスチャID
static int g_TextureId[15];

//3Dモデル
static MODEL* g_pModel[3] = {nullptr};

//UI
UI_Manager* g_pUI = nullptr;

//描画するかしないか
static bool g_doDrawUI = true;
static bool g_doDrawBillboard = true;

//マップパーツ
static MapParts* g_pMapParts[10];

XMFLOAT3 g_goalPos = { -31.0f, 21.0f, 20.0f };

XMFLOAT3 g_SpawnPos = { 0.0f,5.0f,0.0f };

//ゲーム状況
typedef enum
{
	GAME_STATE_NONE,
	GAME_STATE_SHOT,
	GAME_STATE_BALLMOVE,
	GAME_STATE_WAIT,
	GAME_STATE_MAX
}GAME_STATE;

static GAME_STATE g_State = GAME_STATE_NONE;
static unsigned int g_FrameCounter = 0;
static unsigned int g_FrameCountRegist = 0;

//サウンドを表す変数
static int BGM_ID;
static int SE_ID;

static bool uninit = false;

//動く床
static float z01 = 15.0f;
static bool z01TorF = true;

static float x01 = -5.0f;
static bool x01TorF = true;

static float x02 = -5.0f;
static bool x02TorF = true;

static float x03 = -5.0f;
static bool x03TorF = false;

static float y01 = 11.0f;
static bool y01TorF = false;


/*******************************************************************************
* プロトタイプ宣言
*******************************************************************************/
void CreateCube(XMFLOAT3 startPos, int x, int z, int textureId = -1);

/*******************************************************************************
*　初期化処理
*******************************************************************************/
void InitGameMain(void)
{
	InitCube();

	InitBillboard();

	InitBallShot();

	//テクスチャ読み込み
	g_TextureId[0] = TextureLoad(L"asset/texture/操作説明_矢印.png");
	g_TextureId[1] = TextureLoad(L"asset/texture/操作説明_WASD.png");
	g_TextureId[2] = TextureLoad(L"asset/texture/操作説明_スペース.png");
	g_TextureId[3] = TextureLoad(L"asset/texture/block01.png");
	g_TextureId[4] = TextureLoad(L"asset/texture/操作説明_QE.png");
	g_TextureId[5] = TextureLoad(L"asset/texture/操作説明_Esc.png");
	g_TextureId[6] = TextureLoad(L"asset/texture/操作説明_UI.png");
	g_TextureId[7] = TextureLoad(L"asset/texture/ゴール説明.png");
	g_TextureId[8] = TextureLoad(L"asset/texture/block02.png");
	g_TextureId[9] = TextureLoad(L"asset/texture/リスポーンブロック説明.png");
	g_TextureId[10] = TextureLoad(L"asset/texture/操作説明_R.png");
	g_TextureId[11] = TextureLoad(L"asset/texture/block03.png");
	g_TextureId[12] = TextureLoad(L"asset/texture/block04.png");
	g_TextureId[13] = TextureLoad(L"asset/texture/block05.png");
	g_TextureId[14] = TextureLoad(L"asset/texture/ゼロタイムブロック説明.png");

	//モデル初期化
	g_pModel[0] = ModelLoad("asset/model/RedArrow.fbx");
	g_pModel[0]->pos = { -5.0f, 4.0f, 15.0f };

	//カメラの初期化
	g_Camera = new Following_Camera();
	g_Camera2 = new MovingCamera();

	//ライトの初期化	これを動かして昼と夜を再現する
	SetDirectionalLight({ -1.0f,-1.0f,1.0f,0.0f }, { 0.5f,0.5f,0.5f,0.0f });
	SetAmbientColor({ 1.0f,1.0f,1.0f,0.0f });

	//ボールの初期化
	g_pBall = new Ball({ 0.0f,5.0f,0.0f });
	SetBallShot(g_pBall);

	g_pBall->ModelLoad();

	//UI初期化
	g_pUI = new UI_Manager();
	g_pUI->Init();

	g_pMapParts[0] = new Flag;
	g_pMapParts[0]->Init();

	//サウンドデータの読み込み
	BGM_ID = LoadAudio("asset\\Audio\\The_Seasons_Go_Around.wav");
	PlayAudio(BGM_ID, true);

	SE_ID = LoadAudio("asset\\Audio\\キックの素振り1.wav");

	uninit = false;
}

/*******************************************************************************
*　終了処理
*******************************************************************************/
void UninitGameMain(void)
{
	uninit = true;


	for (int i = 0; i < 10; i++) {
		if (g_pMapParts[i])
		{
			delete g_pMapParts[i];
			g_pMapParts[i] = nullptr;
		}
	}


	if (g_pUI) {
		g_pUI->Uninit();
		delete g_pUI;
		g_pUI = nullptr;
	}


	g_pBall->ModelRelease();
	delete g_pBall;

	delete g_Camera;
	delete g_Camera2;


	for (int i = 0; i < 3; i++) {
		if (g_pModel[i])
		{
			ModelRelease(g_pModel[i]);
			g_pModel[i] = nullptr;
		}

	}

	UninitBallShot();

	UninitBillboard();

	UninitCube();


	UnloadAudio(BGM_ID);
	UnloadAudio(SE_ID);
}


/*******************************************************************************
*　更新処理
*******************************************************************************/
void UpdateGameMain(void)
{
	if (uninit)
		return;

	//ポーズ
	if (Keyboard_IsKeyDownTrigger(KK_ESCAPE)) {
		g_pUI->GetPause()->ChangePause();
		return;
	}

	///UIの処理
	g_pUI->Update();

	if (g_pUI->GetPause()->GetPause())
		return;

	//カメラの更新
	g_Camera->Update();
	g_Camera2->Update();

	//便利ボタン

	//強制リセットボタン
	if (Keyboard_IsKeyDownTrigger(KK_R)) {
		g_pBall->SetPosition({ g_SpawnPos.x,g_SpawnPos.y,g_SpawnPos.z });
		g_pBall->OnOverlap();
	}

	//次のリスポーン地点へ
	//デバッグ用兼できない人用
	if (Keyboard_IsKeyDownTrigger(KK_D1)) {
		g_SpawnPos.x = 17.0f;
		g_SpawnPos.y = 8.0f;
		g_SpawnPos.z = 31.0f;
	}

	if (Keyboard_IsKeyDownTrigger(KK_D2)) {
		g_SpawnPos.x = -2.0f;
		g_SpawnPos.y = 12.0f;
		g_SpawnPos.z = 20.0f;
	}

	if (Keyboard_IsKeyDownTrigger(KK_D3)) {
		g_SpawnPos.x = 0.0f;
		g_SpawnPos.y = 13.0f;
		g_SpawnPos.z = -15.0f;
	}

	if (Keyboard_IsKeyDownTrigger(KK_D4)) {
		g_SpawnPos.x = -42.0f;
		g_SpawnPos.y = 18.0f;
		g_SpawnPos.z = -15.0f;
	}

	if (Keyboard_IsKeyDownTrigger(KK_D5)) {
		g_SpawnPos.x = -31.0f;
		g_SpawnPos.y = 21.0f;
		g_SpawnPos.z = 19.0f;
	}

	//UI非表示
	if (Keyboard_IsKeyDownTrigger(KK_U)) {
		if (g_doDrawUI) {
			g_doDrawUI = false;
		}
		else {
			g_doDrawUI = true;
		}
	}

	//ビルボード非表示
	if (Keyboard_IsKeyDownTrigger(KK_I)) {
		if (g_doDrawBillboard) {
			g_doDrawBillboard = false;
		}
		else {
			g_doDrawBillboard = true;
		}
	}



	//ゲーム状況
	switch (g_State) {

	case GAME_STATE_NONE:	//待機状態

		if (g_FrameCounter - g_FrameCountRegist > 60) {
			g_State = GAME_STATE_SHOT;
		}

		break;

	case GAME_STATE_SHOT:	//ボール発射待機

		UpdateBallShot();

		if (Keyboard_IsKeyDownTrigger(KK_SPACE)) {
			PlayAudio(SE_ID);
			g_pBall->AddForce({ GetBallShotVelocity() });
			g_State = GAME_STATE_BALLMOVE;
		}

		break;

	case GAME_STATE_BALLMOVE:	//ボール移動中

		SetTrailPosition(g_pBall->GetPosition());

		//ボールがある程度下にいたらリセット
		XMFLOAT3 pos;
		XMStoreFloat3(&pos, g_pBall->GetPosition());
		if (pos.y <= -10.0f) {
			g_pBall->SetPosition({ g_SpawnPos.x,g_SpawnPos.y,g_SpawnPos.z });
			g_pBall->OnOverlap();
		}

		if (g_pBall->IsStopped()) {
			//クールタイムなし
			g_State = GAME_STATE_SHOT;
			g_FrameCountRegist = g_FrameCounter;
		}

		break;

	case GAME_STATE_WAIT:	//クールタイム

		if (g_FrameCounter - g_FrameCountRegist > 60 * 1) {
			g_State = GAME_STATE_SHOT;
		}

	default:
		break;
	}

	//MODELとの当たり判定
	AABB model_world_aabb = g_pModel[0]->aabb.Trancelation(XMLoadFloat3(&g_pModel[0]->pos));
	g_pBall->OnHit(model_world_aabb);

	//ゴールとの当たり判定
	XMVECTOR GoalPosition = { g_goalPos.x, g_goalPos.y, g_goalPos.z };
	AABB goal_local_aabb({ -0.5f,-0.5f,-0.5f }, { 0.5f,3.0f,0.5f });
	AABB goal_world_aabb = goal_local_aabb.Trancelation(GoalPosition);
	if(g_pBall->OnHit(goal_world_aabb)){

		SetTime(g_pUI->GetTime());

		//ゴールエフェクトを描画してからリザルトに移行させる
		SetScene(SCENE_RESULT);
	}


	//ボール(プレイヤー)の処理
	g_pBall->Update();


	if (z01 < 14.0f || z01 > 19.0f) {
		if (z01TorF) {
			z01TorF = false;
		}
		else {
			z01TorF = true;
		}
	}

	if (z01TorF) {
		z01 += 0.01f;
	}
	else {
		z01 -= 0.01f;
	}

	if (x01 <= -8.0f || x01 > -2.0f) {
		if (x01TorF) {
			x01TorF = false;
		}
		else {
			x01TorF = true;
		}
	}


	if (x01TorF) {
		x01 += 0.01f;
	}
	else {
		x01 -= 0.01f;
	}

	if (x02 <= -6.0f || x02 > 0.0f) {
		if (x02TorF) {
			x02TorF = false;
		}
		else {
			x02TorF = true;
		}
	}

	if (x02TorF) {
		x02 += 0.02f;
	}
	else {
		x02 -= 0.02f;
	}

	if (x03 <= -8.0f || x03 > 2.0f) {
		if (x03TorF) {
			x03TorF = false;
		}
		else {
			x03TorF = true;
		}
	}

	if (x03TorF) {
		x03 += 0.02f;
	}
	else {
		x03 -= 0.02f;
	}


	if (y01 < 8.0f || y01 > 14.0f) {
		if (y01TorF) {
			y01TorF = false;
		}
		else {
			y01TorF = true;
		}
	}

	if (y01TorF) {
		y01 += 0.05f;
	}
	else {
		y01 -= 0.05f;
	}


	//フレームカウンター
	g_FrameCounter++;

}

/*******************************************************************************
*　描画処理
*******************************************************************************/
void DrawGameMain(void)
{

	if (uninit)
		return;

	//カメラ
	SetViewMatrix(g_Camera->GetMatrixView());
	SetProjectionMatrix(g_Camera->GetMatrixPersoective());

	SetPixelShader3d();
	SetDepthEnable(true);

	//ビルボード描画
	if (g_doDrawBillboard) {
		CalculateBillboardMatrix(g_Camera->GetMatrixView());

		//カメラ操作説明
		DrawBillboard(g_TextureId[0], { 0.0f,0.0f }, { 0.0f, 5.0f, -20.0f }, { 10.0f,10.0f }, 0.0f, 0.0f, 0.0f, (float)TextureGetWidth(g_TextureId[0]), (float)TextureGetHeight(g_TextureId[0]));

		//ボールの飛ぶ方向操作説明
		DrawBillboard(g_TextureId[1], { 0.0f,0.0f }, { -10.0f, 3.0f,  10.0f }, { 5.0f,5.0f }, 0.0f, 0.0f, 0.0f, (float)TextureGetWidth(g_TextureId[1]), (float)TextureGetHeight(g_TextureId[1]));

		//ボールの発射操作説明
		DrawBillboard(g_TextureId[2], { 0.0f,0.0f }, { 10.0f, 3.0f,  10.0f }, { 5.0f,5.0f }, 0.0f, 0.0f, 0.0f, (float)TextureGetWidth(g_TextureId[2]), (float)TextureGetHeight(g_TextureId[2]));

		//カメラの視点拡大縮小操作説明
		DrawBillboard(g_TextureId[4], { 0.0f,0.0f }, { -20.0f, 5.0f,  0.0f }, { 10.0f,10.0f }, 0.0f, 0.0f, 0.0f, (float)TextureGetWidth(g_TextureId[4]), (float)TextureGetHeight(g_TextureId[4]));

		//ポーズ画面の開き方操作説明
		DrawBillboard(g_TextureId[5], { 0.0f,0.0f }, { 20.0f, 5.0f,  0.0f }, { 10.0f,10.0f }, 0.0f, 0.0f, 0.0f, (float)TextureGetWidth(g_TextureId[5]), (float)TextureGetHeight(g_TextureId[5]));

		//ビルボードとUIの非表示の仕方
		DrawBillboard(g_TextureId[6], { 0.0f,0.0f }, { -10.0f, 5.0f,  20.0f }, { 10.0f,10.0f }, 0.0f, 0.0f, 0.0f, (float)TextureGetWidth(g_TextureId[6]), (float)TextureGetHeight(g_TextureId[6]));
		
		//ゴール条件
		DrawBillboard(g_TextureId[7], { 0.0f,0.0f }, { 0.0f, 5.0f,  40.0f }, { 10.0f,10.0f }, 0.0f, 0.0f, 0.0f, (float)TextureGetWidth(g_TextureId[6]), (float)TextureGetHeight(g_TextureId[6]));
		
		//リスポーンブロック説明
		DrawBillboard(g_TextureId[9], { 0.0f,0.0f }, { 25.0f, 10.0f,  30.0f }, { 10.0f,10.0f }, 0.0f, 0.0f, 0.0f, (float)TextureGetWidth(g_TextureId[6]), (float)TextureGetHeight(g_TextureId[6]));
		
		//復活地点に強制復活説明
		DrawBillboard(g_TextureId[10], { 0.0f,0.0f }, { 20.0f, 15.0f,  10.0f }, { 10.0f,10.0f }, 0.0f, 0.0f, 0.0f, (float)TextureGetWidth(g_TextureId[6]), (float)TextureGetHeight(g_TextureId[6]));

		//ゼロタイムブロック説明
		DrawBillboard(g_TextureId[14], { 0.0f,0.0f }, { -55.0f, 20.0f,  -15.0f }, { 10.0f,10.0f }, 0.0f, 0.0f, 0.0f, (float)TextureGetWidth(g_TextureId[6]), (float)TextureGetHeight(g_TextureId[6]));

	}


	SetUVMatrix(XMMatrixIdentity());

	SetPixelShader3d();
	SetDepthEnable(true);



	//cube描画
	CreateCube({ -15.5f, 0.0f, -15.5f }, 30, 30, g_TextureId[3]);

	CreateCube({ -5.5f, 0.5f, 14.5f }, 10, 10, g_TextureId[3]);

	CreateCube({ -3.0f, 2.0f, 26.0f }, 5, 10, g_TextureId[3]);

	CreateCube({ 3.0f, 4.0f, 26.0f }, 8, 10, g_TextureId[3]);
	
	//リスポーンブロック
	CreateCube({ 13.0f, 6.0f, 26.0f }, 8, 10, g_TextureId[8]);

	CreateCube({ 13.0f, 9.0f, 16.0f }, 8, 8, g_TextureId[3]);

	//動く床
	CreateCube({ 3.0f, 9.0f, z01 }, 6, 6, g_TextureId[11]);

	CreateCube({ 0.0f, 10.0f, 17.0f }, 1, 6, g_TextureId[3]);

	//リスポーンブロック
	CreateCube({ -6.0f, 10.0f, 17.0f }, 6, 6, g_TextureId[8]);

	//動く床
	CreateCube({ x01, 10.0f, 9.0f }, 6, 6, g_TextureId[11]);

	//動く床
	CreateCube({ x02, 10.0f, 0.0f }, 6, 6, g_TextureId[11]);

	//動く床
	CreateCube({ x03, 10.0f, -9.0f }, 6, 6, g_TextureId[11]);

	CreateCube({ -3.0f, 11.0f, -12.0f }, 6, 1, g_TextureId[3]);

	//リスポーンブロック
	CreateCube({ -3.0f, 11.0f, -18.0f }, 6, 6, g_TextureId[8]);

	//動く床
	CreateCube({ -13.0f, y01, -18.0f }, 6, 6, g_TextureId[12]);

	CreateCube({ -24.0f, 13.0f, -18.0f }, 6, 6, g_TextureId[3]);

	//動く床
	CreateCube({ -34.0f, y01 + 2.0f, -18.0f }, 4, 4, g_TextureId[12]);

	CreateCube({ -40.0f, 16.0f, -18.0f }, 1, 6, g_TextureId[3]);

	//リスポーンブロック
	CreateCube({ -45.0f, 16.0f, -18.0f }, 5, 6, g_TextureId[8]);

	//クールタイム無効の床
	CreateCube({ -45.0f, 16.0f, -8.0f }, 4, 4, g_TextureId[13]);

	//クールタイム無効の床
	CreateCube({ -42.0f, 16.0f, -1.0f }, 4, 4, g_TextureId[13]);

	//クールタイム無効の床
	CreateCube({ -45.0f, 16.0f, 6.0f }, 4, 4, g_TextureId[13]);

	//クールタイム無効の床
	CreateCube({ -47.0f, 17.0f, 12.0f }, 4, 4, g_TextureId[13]);

	//クールタイム無効の床
	CreateCube({ -42.0f, 18.0f, 14.0f }, 4, 4, g_TextureId[13]);

	//リスポーンブロック
	CreateCube({ -34.0f, 20.0f, 17.0f }, 5, 5, g_TextureId[8]);




	//ボール(プレイヤー)の描画
	g_pBall->Draw();

	//モデルの描画
	static XMMATRIX translation = XMMatrixTranslation(0, 0, 0);

	//矢印
	translation = XMMatrixTranslation(g_pModel[0]->pos.x, g_pModel[0]->pos.y, g_pModel[0]->pos.z);
	ModelDraw(g_pModel[0], translation);

	//ゴール(フラッグ)
	translation = XMMatrixTranslation(g_goalPos.x, g_goalPos.y, g_goalPos.z);
	g_pMapParts[0]->Draw(translation);

	//ボール発射待機中なら矢印を描画
	if (g_State == GAME_STATE_SHOT) {
		DrawBallShot();
	}

	//UIの描画
	if (g_doDrawUI) {

		SetWorldViewProjection2D();
		SetDepthEnable(false);
		SetPixelShader2d();
		g_pUI->Draw();
	}
}

/*******************************************************************************
*　X,Z上の平面作成
*******************************************************************************/
void CreateCube(XMFLOAT3 startPos,int x, int z, int textureId) {

	static const XMMATRIX scaleY_Half = XMMatrixScaling(1.0f, 0.5f, 1.0f);
	static const float Bottom = 0.25f;
	int texture = textureId;

		for (int i = 0; i < x * z; i++) {
			if (i % x == 0) {
				startPos.x += (float)x;
				startPos.z += 1.0f;
			}

			//ボールとの当たり判定
			XMVECTOR CubePosition = { startPos.x, startPos.y, startPos.z };

			AABB cube_local_aabb({ -0.5f,-0.5f,-0.5f }, { 0.5f,0.5f,0.5f });
			AABB cube_world_aabb = cube_local_aabb.Trancelation(CubePosition);

			//ボールと当たっていたら
			if (g_pBall->OnHit(cube_world_aabb)) {
				if (textureId == g_TextureId[8]) {
					
					if (startPos.y <= 6.0f) {
						g_SpawnPos.x = 17.0f;
						g_SpawnPos.y = 8.0f;
						g_SpawnPos.z = 31.0f;
					}
					else if(startPos.y <= 10.0f)
					{
						g_SpawnPos.x = -2.0f;
						g_SpawnPos.y = 12.0f;
						g_SpawnPos.z = 20.0f;

					}
					else if(startPos.y <= 11.0f)
					{
						g_SpawnPos.x = 0.0f;
						g_SpawnPos.y = 13.0f;
						g_SpawnPos.z = -15.0f;

					}
					else if (startPos.y <= 16.0f) {
						g_SpawnPos.x = -42.0f;
						g_SpawnPos.y = 18.0f;
						g_SpawnPos.z = -15.0f;

					}
				}
				else if (textureId == g_TextureId[13]) {
					g_State = GAME_STATE_SHOT;
				}
			}

			DrawCube(XMMatrixTranslation(startPos.x, startPos.y, startPos.z), texture);

			startPos.x -= 1.0f;
			texture = textureId;
		}


}

Ball* GetBallPointer() {
	return g_pBall;
}