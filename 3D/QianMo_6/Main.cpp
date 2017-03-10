/********************************************************************
@file     Main.cpp
@date     2017-3-10
@author   Zoro_Tiger
@brief    游戏画面绘图（三）透明特效的制作方法
********************************************************************/
//!头文件
#include <Windows.h>
#include <tchar.h>

//!宏定义
#define WINDOW_CLASS _T("Chapter 6 Class")
#define WINDOW_NAME  _T("Chapter 6 Window")

//!全局变量
HDC g_mdc = NULL; //!兼容DC
HBITMAP g_backgroundPic = NULL, g_dragonPic = NULL; //!背景图片与恐龙图片

//!消息处理函数
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//!变量声明
	PAINTSTRUCT ps;
	HDC hdc;

	//消息处理
	switch (msg)
	{
	case WM_PAINT:
		
		//!开始绘制
		hdc = BeginPaint(hWnd, &ps);

		//!绘制背景
		SelectObject(g_mdc, g_backgroundPic);
		BitBlt(hdc, 0, 0, 600, 450, g_mdc, 0, 0, SRCCOPY);

		//!绘制恐龙
		SelectObject(g_mdc, g_dragonPic);
		BitBlt(hdc, 200, 320, 85, 99, g_mdc, 85, 0, SRCAND);
		BitBlt(hdc, 200, 320, 85, 99, g_mdc, 0,  0, SRCPAINT);

		//!结束绘制
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		//!清理资源
		DeleteDC(g_mdc);
		DeleteObject(g_backgroundPic);
		DeleteObject(g_dragonPic);
		PostQuitMessage(0);
		break;
	}

	//!默认消息处理函数
	return DefWindowProc(hWnd, msg, wParam, lParam); 
}

//!程序入口
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lCmdLine,
	int nShowCmd)
{
	//!窗口类
	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX),
		CS_CLASSDC, //!该窗口类的所有窗口实例都共享一个窗口类
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
	HDC hdc = GetDC(hWnd);
	HDC mdc = CreateCompatibleDC(hdc); //!兼容DC
	g_mdc = mdc;

	//!读取位图
	g_backgroundPic = (HBITMAP)LoadImage(NULL, _T("bg.bmp"), IMAGE_BITMAP, 600, 450, LR_LOADFROMFILE);
	g_dragonPic = (HBITMAP)LoadImage(NULL, _T("dra.bmp"), IMAGE_BITMAP, 170, 99, LR_LOADFROMFILE);

	//!绘制背景
	SelectObject(g_mdc, g_backgroundPic);
	BitBlt(hdc, 0, 0, 600, 450, g_mdc, 0, 0, SRCCOPY);

	//!绘制恐龙
	SelectObject(g_mdc, g_dragonPic);
	BitBlt(hdc, 200, 320, 85, 99, g_mdc, 85, 0, SRCAND);
	BitBlt(hdc, 200, 320, 85, 99, g_mdc, 0,  0, SRCPAINT);

	//!删除DC
	ReleaseDC(hWnd, hdc);

	//!处理消息
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		//!对消息进行特殊处理
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	//!返回操作系统
	return msg.wParam;
}