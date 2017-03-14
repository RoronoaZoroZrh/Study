/********************************************************************
@file     Main.cpp
@date     2017-3-14
@author   Zoro_Tiger
@brief    游戏地图制作（一）平面地图贴图
********************************************************************/
//!头文件
#include <Windows.h>
#include <tchar.h>
#include <cstring>

//!宏定义
#define WINDOW_CLASS _T("Chapter 9 Class")  //!类名
#define WINDOW_NAME  _T("Chapter 9 Window") //!标题名称
#define BITMAP_NUM   3                      //!贴图数量
#define FILEPATH_LEN 256                    //!路径长度
#define MAP_ROW      8                      //!行
#define MAP_COL      8                      //!列
#define BITMAP_WIDTH 50                     //!贴图宽度
#define BITMAP_HEGTH 50                     //!贴图长度

//!全局变量
HDC g_hdc = NULL, g_mdc = NULL; //!HDC、兼容HDC
HBITMAP g_bitmap = NULL;        //!地图

//!函数声明
void Render(void);

//!消息处理函数
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//!处理消息
	switch (msg)
	{
	case WM_DESTROY:
		//!清理资源
		DeleteDC(g_mdc);
		ReleaseDC(hWnd, g_hdc);
		DeleteObject(g_bitmap);
		PostQuitMessage(0);
		break;
	}

	//!默认消息处理函数
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

//!程序入口
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmds)
{
	//!声明窗口类
	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX),
		CS_CLASSDC,
		WndProc,
		0,
		0,
		hInstance,
		NULL,
		LoadCursor(NULL, IDC_ARROW),
		(HBRUSH)(COLOR_WINDOW + 1),
		NULL,
		WINDOW_CLASS,
	};

	//!注册窗口类
	if (FAILED(RegisterClassEx(&wc)))
	{
		return -1;
	}

	//!创建窗口
	HWND hWnd = CreateWindow(WINDOW_CLASS,
		WINDOW_NAME,
		WS_OVERLAPPEDWINDOW,
		10,
		10,
		430,
		450,
		NULL,
		NULL,
		hInstance,
		NULL);

	//!显示窗口
	ShowWindow(hWnd, nShowCmds);

	//!更新窗口
	UpdateWindow(hWnd);

	//!初始化DC
	g_hdc = GetDC(hWnd);
	g_mdc = CreateCompatibleDC(g_hdc);

	//!获取小贴图
	HBITMAP bitmap[BITMAP_NUM];
	TCHAR strFile[FILEPATH_LEN];
	for (int i = 0; i < BITMAP_NUM; ++i)
	{
#ifdef _UNICODE
		swprintf_s(strFile, _T("map%d.bmp"), i);
#else
		sprintf_s(strFile, _T("map%d.bmp"), i);
#endif
		bitmap[i] = (HBITMAP)LoadImage(NULL, strFile, IMAGE_BITMAP, 50, 50, LR_LOADFROMFILE);
	}

	//!创建大贴图
	g_bitmap = CreateCompatibleBitmap(g_hdc, MAP_COL * BITMAP_WIDTH, MAP_ROW * BITMAP_HEGTH);
	SelectObject(g_mdc, g_bitmap);

	//!将小贴图组装成大贴图
	int nMapIndex = 0;
	HDC mdc = CreateCompatibleDC(g_hdc);
	for (int i = 0; i < MAP_ROW; ++i)
	{
		for (int j = 0; j < MAP_COL; ++j)
		{
			nMapIndex = j % BITMAP_NUM;
			SelectObject(mdc, bitmap[nMapIndex]);
			BitBlt(g_mdc, i * BITMAP_WIDTH, j * BITMAP_HEGTH, BITMAP_WIDTH, BITMAP_HEGTH, mdc, 0, 0, SRCCOPY);
		}
	}

	//!删除DC
	DeleteDC(mdc);

	//!删除小贴图
	for (int i = 0; i < BITMAP_NUM; ++i)
	{
		DeleteObject(bitmap[i]);
	}

	//!获得消息
	MSG msg;
	GetMessage(&msg, NULL, 0, 0);
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Render();
		}
	}
	return msg.wParam;
}

//!渲染
void Render(void)
{
	BitBlt(g_hdc, 0, 0, MAP_COL * BITMAP_WIDTH, MAP_ROW * BITMAP_HEGTH, g_mdc, 0, 0, SRCCOPY);
}