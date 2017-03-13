/********************************************************************
@file     Main.cpp
@date     2017-3-10
@author   Zoro_Tiger
@brief    基础动画显示（一）定时器的使用
********************************************************************/
//!头文件
#include <Windows.h>
#include <tchar.h>
#include <string>

//!宏定义
#define WINDOW_CLASS _T("Chapter 7 Class")
#define WINDOW_NAME  _T("Chapter 7 Window")
#define BITMAP_NUM   7
#define FILENAME_NUM 28

//!全局变量
HDC g_hdc = NULL, g_mdc = NULL;
HBITMAP g_bitmapArray[BITMAP_NUM] = { NULL };

//!消息响应函数
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//!变量声明
	static int nBitmapNum = 0;

	//!处理消息
	switch (msg)
	{
	case WM_TIMER:
		SelectObject(g_mdc, g_bitmapArray[nBitmapNum++]);
		nBitmapNum %= BITMAP_NUM;
		BitBlt(g_hdc, 0, 0, 600, 450, g_mdc, 0, 0, SRCCOPY);
		break;
	case WM_DESTROY:
		//!清理资源
		DeleteDC(g_mdc);
		ReleaseDC(hWnd, g_hdc);
		for (int i = 0; i < BITMAP_NUM; ++i)
		{
			DeleteObject(g_bitmapArray[i]);
		}
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
		break;
	}

	//!默认消息响应函数
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

//!程序入口
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
{
	//!窗口类
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
		NULL,
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
		600,
		450,
		NULL,
		NULL,
		hInstance,
		NULL);

	//!窗口创建失败
	if (NULL == hWnd)
	{
		return -1;
	}

	//!显示窗口
	ShowWindow(hWnd, nShowCmd);

	//!更新窗口
	UpdateWindow(hWnd);

	//!创建DC
	g_hdc = GetDC(hWnd);
	g_mdc = CreateCompatibleDC(g_hdc);

	//!创建Bitmap
	TCHAR strFile[FILENAME_NUM] = { 0 };
	for (int i = 0; i < BITMAP_NUM; ++i)
	{
		swprintf_s(strFile, _T("girl%d.bmp"), i);
		g_bitmapArray[i] = (HBITMAP)LoadImage(NULL, strFile, IMAGE_BITMAP, 640, 480, LR_LOADFROMFILE);
	}

	//!设置定时器
	SetTimer(hWnd, 1, 50, NULL);

	//!消息处理
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam; //!返回退出消息
}