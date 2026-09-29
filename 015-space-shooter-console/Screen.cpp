#define CONIOEX
#include "conioex.h"
#include <time.h>	//時間ヘッダー

#ifdef _DEBUG
void DispFPS(void);
#endif
void WindowConsoleInitialize(void);

// *****************************************************************************
// グローバル変数
// *****************************************************************************
int CountFps;				// FPSカウンタ


// =============================================================================
//  初期化関数
// =============================================================================
void ScreenInit(void)
{

	// 画面をクリア
	clrscr();

	// カーソル非表示
	setcursortype(NOCURSOR);

	// 分解能を設定
	timeBeginPeriod(1);

	// ウィンドウ設定の初期化（HEW用設定）
	WindowConsoleInitialize();
}

// =============================================================================
//  終了処理関数
// =============================================================================
void ScreenUninit(void)
{
	// 分解能を戻す
	timeEndPeriod(1);

	// 画面をクリア
	clrscr();
	// カーソル表示
	setcursortype(NORMALCURSOR);
}

#ifdef _DEBUG
// =============================================================================
// FPS表示
// =============================================================================
void DispFPS(void)
{
	// 色設定
	textcolor(WHITE);

	gotoxy(1, 1);
	printf("FPS:%d", CountFps);
}
#endif

// =============================================================================
// ウィンドウ設定の初期化（HEW用設定）
// =============================================================================
void WindowConsoleInitialize(void)
{
	// Set console window position
	HWND consoleWindow = GetConsoleWindow();
	SetWindowPos(consoleWindow, 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// Set console window size
	SMALL_RECT windowSize = { 0, 0, 80, 25 };
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);

	// Set console buffer size
	// ウィンドウサイズは80, 25で固定すること
	COORD coord;
	coord.X = 80;
	coord.Y = 25;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	// Set console font style and size
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	// ↓フォントサイズのみ変更可↓
	cfi.dwFontSize.X = 15;                   // Width of each character in the font
	cfi.dwFontSize.Y = 30;                   // Height
	// ↑フォントサイズのみ変更可↑
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"MS Gothic");       // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
