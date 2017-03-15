/********************************************************************
@file     Main.cpp
@date     2017-3-15
@author   Zoro_Tiger
@brief    基础动画显示（三） 透明动画的实现
********************************************************************/
//!头文件
#include <Windows.h>
#include <tchar.h>
#include <cstring>

//!宏定义
#define WINDOW_CLASS _T("Chapter 10 Class") //!窗口类名
#define WINDOW_NAME  _T("Chapter 10 Name")  //!窗口名称
#define RENDER_SPACE 100                    //!渲染间隔
#define DRAGON_NUM   8                      //!恐龙个数
#define DRAGON_WIDTH 95                     //!恐龙宽度
#define DRAGON_HEGTH 99                     //!恐龙高度
#define DRAGON_X     640                    //!恐龙初始X坐标
#define DRAGON_Y     360                    //!恐龙初始Y坐标

//!函数声明
bool RegistClass(HINSTANCE);
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void Render(int nTime);

//!全局变量
HDC g_hdc = NULL; //!DC
HDC g_mdc = NULL; //!兼容DC
HDC g_bdc = NULL; //!bufDC
HBITMAP g_background = NULL, g_dragon = NULL; //!背景图与龙
HBITMAP g_mdcBackground = NULL; //!mdc背景图

//!程序入口
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
{
	//!注册窗口类
	if (!RegistClass(hInstance))
	{
		return -1;
	}

	//!创建窗口
	HWND hWnd = CreateWindow(WINDOW_CLASS,
		WINDOW_NAME,
		WS_OVERLAPPEDWINDOW,
		10,
		10,
		640,
		480,
		NULL,
		NULL,
		hInstance,
		NULL);

	//!创建窗口失败
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
	g_bdc = CreateCompatibleDC(g_hdc);

	//!创建贴图
	g_background = (HBITMAP)LoadImage(NULL, _T("bg.bmp"), IMAGE_BITMAP, 640, 480, LR_LOADFROMFILE);
	g_dragon = (HBITMAP)LoadImage(NULL, _T("dra.bmp"), IMAGE_BITMAP, 760, 198, LR_LOADFROMFILE);
	g_mdcBackground = CreateCompatibleBitmap(g_hdc, 640, 480);
	SelectObject(g_mdc, g_mdcBackground);

	//!获取消息
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
			Render(GetTickCount());
		}
	}
	return msg.wParam;
}

//!注册窗口类
bool RegistClass(HINSTANCE hInstance)
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
		NULL
	};

	//!注册窗口类
	if (FAILED(RegisterClassEx(&wc)))
	{
		return false;
	}
	return true;
}

//!消息处理函数
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//!处理消息
	switch(msg)
	{
	case WM_DESTROY:
		//!清理资源
		DeleteDC(g_mdc);
		DeleteDC(g_bdc);
		ReleaseDC(hWnd, g_hdc);
		DeleteObject(g_dragon);
		DeleteObject(g_background);
		DeleteObject(g_mdcBackground);
		PostQuitMessage(0);
		break;
	}

	//!默认消息处理函数
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

//!渲染
void Render(int nTime)
{
	static int nPreTime = nTime; //!前次渲染时间
	static int nIndex = 0; //!恐龙编号
	static int nDragonX = DRAGON_X; //!恐龙X坐标
	static int nDragonY = DRAGON_Y; //!恐龙Y坐标

	//!渲染
	if (nTime - nPreTime >= RENDER_SPACE)
	{
		//!背景透明
		SelectObject(g_bdc, g_background);
		BitBlt(g_mdc, 0, 0, 640, 480, g_bdc, 0, 0, SRCCOPY);
 		SelectObject(g_bdc, g_dragon);
 		BitBlt(g_mdc, nDragonX, nDragonY, DRAGON_WIDTH, DRAGON_HEGTH, g_bdc, nIndex*DRAGON_WIDTH, DRAGON_HEGTH, SRCAND); //!左上角是原点
		BitBlt(g_mdc, nDragonX, nDragonY, DRAGON_WIDTH, DRAGON_HEGTH, g_bdc, nIndex*DRAGON_WIDTH, 0, SRCPAINT);
		BitBlt(g_hdc, 0, 0, 640, 480, g_mdc, 0, 0, SRCCOPY);

		//!调整恐龙坐标
		nDragonX = nDragonX - 20;
		if (nDragonX <= -DRAGON_WIDTH)
		{
			nDragonX = DRAGON_X;
		}

		//!调整恐龙编号
		++nIndex;
		nIndex = nIndex % DRAGON_NUM;

		//!调整前次渲染时间
		nPreTime = nTime;
	}
}