//調べるところメモ
/*
* 
プリプロセッサにNOMINMAXをいれててもReleaseビルドだとエラー



assimpのmaterial.inlの
この行にmin,maxのガードを入れないとビルドが通らない


#ifdef min
#undef min
#endif

		iNum = static_cast<unsigned int>(std::min(static_cast<size_t>(iNum),prop->mDataLength / sizeof(Type)));
		::memcpy(pOut,prop->mData,iNum * sizeof(Type));
		if (pMax) {
			*pMax = iNum;
		}
#ifdef max
#undef max
#endif



AABBの当たり判定がcubeの高さを半分にすると安定しない

*/


//=====================================//
// インクルード
//=====================================//
#include "main.h"
#include "renderer.h"
#include "sprite.h"
#include "keyboard.h"
#include "Audio.h"
#include "Scene_Manager.h"
#include "texture.h"
#include "light.h"

//==========================================//
// ライブラリのリンク						//
//==========================================//
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dcompiler.lib")
#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "dxguid.lib")
#pragma comment (lib, "dinput8.lib")

//==========================================//
//マクロ定義								//
//==========================================//

#define	CLASS_NAME		"DX21 Window"
#define WINDOW_CAPTION	"DX21ウィンドウ表示"

//==========================================//
//グローバル変数							//
//==========================================//
#ifdef _DEBUG	//デバッグノード時のみ変数を作る
//デバッグモードの時だけ_DEBUGが定義されるため有効になる

int g_CountFPS;		//FPSカウンター
char g_DebugStr[2048] = WINDOW_CAPTION;	//表示文字列設定
#endif

HWND g_hWnd;

//==========================================//
//プロトタイプ宣言							//
//==========================================//

//コールバック関数＝＞他人が呼びだしてくれる関数
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//初期化関数
HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow);

//終了処理
void Uninit(void);

//更新処理
void Update(void);

//描画処理
void Draw(void);


//==========================================//
// メイン関数								//
//==========================================//
int APIENTRY WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmd, _In_ int nCmdShow)
{
	//乱数初期化
	srand((UINT)timeGetTime());	//デバッグ中はコメントでもよい

	//フレームレート計測用変数
	DWORD dwExecLastTime;
	DWORD dwFPSLastTime;
	DWORD dwCurrentTime;
	DWORD dwFrameCount;

	//COMコンポーネントの準備(機能を備品化してがいぶのプログラムから共有利用する仕組み)
	HRESULT hr = CoInitializeEx(nullptr, COINITBASE_MULTITHREADED);

	//ウィンドウクラスの登録（ウィンドウの仕様的な物を決めてWindowsへセットする）
	WNDCLASS	wc;						//構造体を準備
	ZeroMemory(&wc, sizeof(WNDCLASS));	//内容を0で初期化
	wc.lpfnWndProc = WndProc;			//コールバック関数のポインター
	wc.lpszClassName = CLASS_NAME;		//この仕様書の名前
	wc.hInstance = hInstance;			//このアプリケーションのこと
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			//カーソルの種類
	wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1);	//ウィンドウの背景色
	RegisterClass(&wc);			//構造体をWindowsへセット

	//ウィンドウサイズの調整
	RECT rc = { 
		0, 0,		//左上	（横0    縦0 )
		SCREEN_WIDTH, SCREEN_HEIGHT};	//右下　（横1280 縦720）

	//描画領域が1280 * 720になるようにサイズ調整する↓
	//ウィンドウのサイズ調整関数
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW ^ (WS_THICKFRAME | WS_MAXIMIZEBOX | WS_MINIMIZEBOX), FALSE);

	//ウィンドウの作成
	g_hWnd = CreateWindow(
		CLASS_NAME,				//作りたいウィンドウ
		WINDOW_CAPTION,			//ウィンドウに表示するタイトル
		WS_OVERLAPPEDWINDOW ^ (WS_THICKFRAME | WS_MAXIMIZEBOX | WS_MINIMIZEBOX),	//標準的な形状のウィンドウ　サイズ変更禁止
		CW_USEDEFAULT,			//デフォルト設定でおまかせ
		CW_USEDEFAULT,
		rc.right - rc.left,
		rc.bottom - rc.top,
		NULL,
		NULL,
		hInstance,				//アプリケーションのハンドル
		NULL
	);

	//初期化処理
	if (FAILED(Init(hInstance, g_hWnd, true)))
	{
		return -1;	//初期化失敗
	}
	

	//作成したウィンドウを表示する
	ShowWindow(g_hWnd, nCmdShow);	//引数に従って表示、または非表示

	//ウィンドウの内容を強制表示
	UpdateWindow(g_hWnd);

	//メッセージループ
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));	//メッセージ構造体を作成して初期化

	//フレームレート計測初期化
	timeBeginPeriod(1);	//タイマーの分解能を設定
	dwExecLastTime = dwFPSLastTime = timeGetTime();	//現在のタイマー値
	dwCurrentTime = dwFrameCount = 0;

	//終了メッセージが来るまでループする
	//ゲームループ
	while (1)
	{	//メッセージの有無をチェック
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	//Windowsからなにかメッセージが来ていた場合
		{	
			if (msg.message == WM_QUIT)	//完全終了しましたメッセージ
			{
				break;	//whileループから抜ける
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);	//WndProc1が呼びだされる
			}
		}
		else //Windowsからメッセージが来ていない場合
		{
			dwCurrentTime = timeGetTime();	//現在のタイマー値を取得

			if ((dwCurrentTime - dwFPSLastTime) >= 1000)	//1秒経過したか
			{
#ifdef _DEBUG
				g_CountFPS = dwFrameCount;
#endif
				dwFPSLastTime = dwCurrentTime;	//現在のタイマー値を保存
				dwFrameCount = 0;				//フレームカウントをクリア
			}

			if ((dwCurrentTime - dwExecLastTime) >= ((float)1000 / 60))	//1/60秒経過したか
			{
				dwExecLastTime = dwCurrentTime;	//現在の時間を保存
#ifdef _DEBUG
				wsprintf(g_DebugStr, WINDOW_CAPTION);	//配列にキャプション文字列を格納
				//strlenでWINDOW_CAPTIONの後ろに文字列を追加
				wsprintf(&g_DebugStr[strlen(g_DebugStr)], "FPS:%d", g_CountFPS);
				SetWindowText(g_hWnd, g_DebugStr);	//キャプション部分の置き換え
				//↑これを応用することによってプレイヤーのHPなどを表記する事もできる
#endif

				Update();	//更新処理
				Draw();		//描画処理

				keycopy();

				dwFrameCount++;	//フレームカウントを進める
			}
		}
	}	//Endwhile

	//終了処理
	Uninit();

	//終了する
	return (int)msg.wParam;
}

//==========================================//
//ウィンドウプロシージャ					//
//==========================================//
//wParam <- 何を押されたか　
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_ACTIVATEAPP:
		case WM_SYSKEYDOWN:
		case WM_KEYUP:
		case WM_SYSKEYUP:
			Keyboard_ProcessMessage(uMsg, wParam, lParam);
         break;

		case WM_KEYDOWN:	//キーが押された
			//if (wParam == VK_RETURN)//押されたのはENTERキー
			//{
			//	//ウィンドウを閉じたいリクエストを送る
			//	SendMessage(hWnd, WM_CLOSE, 0, 0);
			//}
			Keyboard_ProcessMessage(uMsg, wParam, lParam);
			break;

		case WM_CLOSE:	//ウィンドウを閉じなさい命令
			if (
				MessageBox(hWnd, "本当に終了してよろしいですか",
					"確認", MB_OKCANCEL | MB_DEFBUTTON2) == IDOK
				)
			{	//OKが押された時
				DestroyWindow(hWnd);//終了する手続きをWindowsへリクエスト
			}
			else
			{
				return 0;	//やっぱり終わらない
			}
			break;

		case WM_DESTROY:	//終了してOKですよ
			PostQuitMessage(0);	//自分にメッセージ0を送る
			break;
	}

	//必要のないメッセージは適当に処理させて終了
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

//==========================================//
// 初期化関数								//
//==========================================//
HRESULT Init(HINSTANCE hInstance, HWND hWnd, BOOL bWindow)
{
	Keyboard_Initialize();

	//DirectX関連の初期化
	InitRenderer(hInstance, hWnd, bWindow);

	//テクスチャの初期化
	TextureInitialize();

	//ライトの初期化
	InitLight();

	//サウンドの初期化
	InitAudio();

	//スプライトの初期化
	InitSprite();

	//マネージャーの初期化
	InitManager();


	return S_OK;
}


//==========================================//
// 終了処理									//
//==========================================//
void Uninit(void)
{

	//マネージャーの終了処理
	UninitManager();

	//スプライトの終了処理
	UninitSprite();

	//サウンドの終了処理
	UninitAudio();

	//ライトの終了処理
	UninitLight();

	//テクスチャの終了処理
	TextureFinalize();

	//DirectX関連の終了処理
	UninitRenderer();
}


//==========================================//
// 更新処理									//
//==========================================//
void Update(void)
{
	//マネージャーの更新処理
	UpdateManager();
}

//==========================================//
// 描画処理									//
//==========================================//
void Draw(void)
{
	//バッファリングのクリア
	Clear();

	//マネージャーの描画処理
	DrawManager();

	//バックバッファをフロントバッファへコピー
	Present();


}

float getRandomFloat(float min, float max) {
	return min + static_cast<float>(rand()) / static_cast<float>(RAND_MAX / (max - min));
}

HWND GetHWnd()
{
	return g_hWnd;
}
