
//Windowの表示
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "common.h"
#include "MyDirect3D.h"
#include "MyTex.h"
#include "Sprite.h"
#include "debug_font.h"
#include "system_timer.h"
#include "PatternAnimation.h"
#include "input.h"
#include "Game.h"

#pragma comment(lib,"d3d9.lib")	//ライブラリの直接リンク	プラグマディレクティブ

#define CP (100*2*D3DX_PI)	//背景*2*π
#define RADIAN (D3DX_PI*2/CP)


/*
#if defined(DEBUG)||defined(_DEBUG)
#pragma comment(lib,"d3dx9d.lib")
#else
#pragma comment(lib,"d3dx9.lib")
#endif*/

//定数定義
#define CLASS_NAME	"GetWindow"
#define WINDOW_CAPTION	"Window"


//プロトタイプ宣言
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
bool Init();
void Update();
void Draw();
void Uninit();
//追加テスト関数
static void Update(void);	//更新関数

LPDIRECT3DDEVICE9 g_pDevice=NULL;

static float move_x = 0.0f;
static float move_y = 0.0f;
static float Rowling = 0;
int kakudai = 0;
bool W = false;
bool A = false;
bool S = false;
bool D = false;

static int kaiten=0;


HWND hWnd = NULL;


static int tex[TEXTUREDATA_MAX];

static int g_FrameCount = 0;	//フレームカウンタ　１フレーム経つと１プラスされる。
static int g_FPSBaseFrameCount = 0;	//FPS計測の基となるフレームカウンタ
static double g_FPSBaseTime = 0.0f;	//FPS計測の基となる時間
static double g_StaticFrameTime = 0.0f;	//フレーム固定変数
float g_FPS = 0.0f;	//FPS


		RECT window_rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };	//RECT型構造体を宣言、初期化

//メイン
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	UNREFERENCED_PARAMETER(hPrevInstance);	//使わない変数に対して警告が出ないようにする。
	UNREFERENCED_PARAMETER(lpCmdLine);

	///////////////////////////////////////////////////////////////////////////////////////////////ウィンドウせってい
		WNDCLASS wc = {};	//ウィンドウクラス型のwc構造体を全て初期化。(全て0が入る)

		wc.lpfnWndProc = WndProc;	//ウィンドウプロシージャの登録：関数ポインタ ( ()がついていない。 )		ＯＳがメッセージを送る先、ＯＳが自動で使用する。
		wc.lpszClassName = CLASS_NAME;	//クラス名(Windowの名前)の登録
		wc.hInstance = hInstance;	//ハンドルの数値
		wc.hCursor = LoadCursor(NULL, IDC_ARROW);	//カーソルのデザイン
		wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1);	//ウィンドウの背景色

		RegisterClass(&wc);


		int window_width = window_rect.right - window_rect.left;	//ウィンドウバーの分拡大調整
		int window_height = window_rect.bottom - window_rect.top;	//ウィンドウバーの分拡大調整
		int primary_width = GetSystemMetrics(SM_CXSCREEN);	//ｐｃ画面の横
		int primary_height = GetSystemMetrics(SM_CYSCREEN);	//ｐｃ画面の高さ
		int wndout_x = max((primary_width - window_width) / 2, 0);	//ウィンドウの出力座標をX軸の真ん中にする
		int wndout_y = max((primary_height - window_height) / 2, 0);	//ウィンドウの出力座標をY軸の真ん中にする
		DWORD window_style = WS_OVERLAPPEDWINDOW ^ (WS_THICKFRAME | WS_MAXIMIZEBOX);	//ウィンドウの形式を指定(佐藤講師曰く綺麗に書きたい)

		AdjustWindowRect(&window_rect, WS_OVERLAPPEDWINDOW ^ (WS_THICKFRAME | WS_MAXIMIZEBOX), FALSE);	//ウィンドウの調整

		hWnd = CreateWindow(
			CLASS_NAME,
			WINDOW_CAPTION,
			window_style,	//ウィンドウの形式(OVERLAPEDWINDOW:普通のやつ.WS_POPUPWINDOW:枠のないウィンドウ、フルスクリーン)
			wndout_x,		//ウィンドウの出力初期位置X
			wndout_y,		//ウィンドウの出力初期位置Y
			window_width,		//ウィンドウの幅
			window_height,		//ウィンドウの高さ
			NULL,
			NULL,
			hInstance,
			NULL

		);	//ハンドル値が返される。

		Keyboard_Initialize(hInstance, hWnd);	// できればInitに移す
		
		ShowWindow(hWnd, nCmdShow);	//表示したいウィンドウのハンドルを入れる。
		
		UpdateWindow(hWnd);	//GetMessageでシステムからメッセージを受け取り、メッセージループ(待機)を行う。メッセージが来るまで現状の持続

		if (!Init())
		{
			return -1;
		}

	///////////////////////////////////////////////////////////////////////////////////////////////////ウィンドウ設定終了


	MSG msg = {};	//メッセージ格納変数宣言
		
	while (WM_QUIT != msg.message)	//終了メッセージが来ない限りループ
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);	//キー入力取得
			DispatchMessage(&msg);	//メッセージをウィンドウプロシージャに受け渡す
		}
		else
		{
			double time = SystemTimer_GetTime();
			if (time - g_StaticFrameTime < 1.0 / 60.0)
			{
				Sleep(0);
			}
			else
			{
				g_StaticFrameTime = time;

				Update();
				Draw();
				
				
				//ゲーム処理
			}
		}
	}
	
	Uninit();

	return (int)msg.wParam;


}



LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)	//システムが勝手に呼び出してくれるプロシージャ
{
	switch (uMsg)
	{
	case WM_KEYDOWN:	//なんらかのキーが押された際に送られてくるメッセージ
		if (wParam == VK_ESCAPE)
		{

			SendMessage(hWnd, WM_CLOSE, 0, 0);

		}
		break;

	case WM_CLOSE:
		if (MessageBox(hWnd, "本当に終了しますか？", "終了確認", MB_OKCANCEL | MB_DEFBUTTON2) == IDOK)
		{
			DestroyWindow(hWnd);	//消滅するウィンドウのハンドルを指定する。(まだ消滅しない)
		}
		return 0;

	case WM_DESTROY:	//DESTROYメッセージを送られて来た際にウィンドウを消滅させる。
		PostQuitMessage(0);
		return 0;

	};

	return DefWindowProc(hWnd, uMsg, wParam, lParam);

}

bool Init()
{
	bool hr = MyDirect3D_Init(hWnd);
	if (hr==false)
	{
		MessageBox(hWnd, "デバイスの設定に失敗しました。", "エラー", MB_OK|MB_DEFBUTTON1);
		return false;
	}
	
	g_pDevice = GetDevice();
	DebugFont_Initialize();	//デバッグフォントモジュールの初期化


	Sprite_Init();





	if (Texture_Load() > 0)
	{
		MessageBox(NULL, "テクスチャエラーMAIN", "エラー", MB_OK);
	}

	SystemTimer_Initialize();
	SystemTimer_Start();


	 g_FrameCount = g_FPSBaseFrameCount = 0;	//全て0にできる。
	 g_FPS = 0.0f;

	 g_StaticFrameTime = g_FPSBaseTime = SystemTimer_GetTime();	//全てに現在の時刻を入れる。

	PatternAnimation_Init();

	GameInit();


	return true;
}

void Draw()
{
	g_pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_RGBA(0, 0, 255, 1), 1.0f, 0);//0,NULL:全消去	target~zbuffer:奥行を消す(二次)	color_rgba:消去する色	1.0f:奥行情報(0～1.0)	0:

	g_pDevice->BeginScene();	//シーン開始




	DebugFont_Draw(100, 500, "fps:%f", g_FPS);



	GameDraw();


	g_pDevice->EndScene();		//シーン終了
	g_pDevice->Present(NULL, NULL, NULL, NULL);	//描画処理(注意：重くなるためpresentは必ず一つだけ。)

}


void Update()
{		

	/*/　FPS計測は最後に行う　/*/

	g_FrameCount++;	//フレームカウントアップ

					//現在のシステム時間の取得
	double time = SystemTimer_GetTime();

	//現在のFPS計測時間から規定時間たっていたらFPS計測	　今の時間から前の時間を引くと経過時間が出る。
	if (time - g_FPSBaseTime >= FPS_MEASUREMENT_TIME)
	{
		g_FPS = (float)((g_FrameCount - g_FPSBaseFrameCount) / (time - g_FPSBaseTime));
	
		//FPS計測の基になる値
		g_FPSBaseFrameCount = g_FrameCount;
		g_FPSBaseTime = time;
	}
	

	Keyboard_Update();	//１フレームに一回キーボードの状態を調べる

	GameUpdate();




}



void Uninit()
{
	MyDirect3D_Uninit();
	DebugFont_Finalize();
	Keyboard_Finalize();



}
