/********************************************************************
@file     Main.cpp
@date     2017-3-14
@author   Zoro_Tiger
@brief    基础动画显示（二）游戏循环的使用
********************************************************************/
//!头文件
#include <Windows.h>
#include <tchar.h>
#include <string>

//!宏定义
#define WINDOW_CLASS _T("Chapter 8 Class")
#define WINDOW_NAME  _T("Chapter 8 Window")
#define BITMAP_NUM   8
#define FILENAME_LEN 28
#define RENDER_SPACE 100

//!全局变量
HDC g_hdc = NULL, g_mdc = NULL;
HBITMAP g_bitmapArray[BITMAP_NUM] = { NULL };

//!消息处理函数
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//!处理消息
	switch (msg)
	{
	case WM_DESTROY:
		{
			//!删除DC
			DeleteDC(g_mdc);
			ReleaseDC(hWnd, g_hdc);
			//!删除贴图
			for (int i = 0; i < BITMAP_NUM; ++i)
			{
				DeleteObject(g_bitmapArray[i]);
			}
			PostQuitMessage(0);
			break;
		}
	}

	//!默认消息处理函数
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

//!函数声明
void Render(UINT nTime);

//!入口函数
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
		NULL
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

	//!创建窗口失败
	if (NULL == hWnd)
	{
		return -1;
	}

	//!显示窗口
	ShowWindow(hWnd, nShowCmd);

	//更新窗口
	UpdateWindow(hWnd);

	//!初始化DC
	g_hdc = GetDC(hWnd);
	g_mdc = CreateCompatibleDC(g_hdc);

	//!初始化贴图
	TCHAR strFile[FILENAME_LEN] = { 0 };
	for (int i = 0; i < BITMAP_NUM; ++i)
	{
#ifdef _UNICODE
		swprintf_s(strFile, _T("man%d.bmp"), i);
#else
		sprintf_s(strFile, _T("man%d.bmp"), i);
#endif
		g_bitmapArray[i] = (HBITMAP)LoadImage(NULL, strFile, IMAGE_BITMAP, 600, 480, LR_LOADFROMFILE);
	}

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

//!渲染
void Render(UINT nTime)
{
	//!变量声明
	static int nIndex = 0;
	static int nLastRenderTime = 0;

	//!渲染
	if (nTime - nLastRenderTime >= RENDER_SPACE)
	{
		//!选择贴图对象到兼容DC
		SelectObject(g_mdc, g_bitmapArray[nIndex]);
		nIndex = (++nIndex) % BITMAP_NUM;

		//!显示时间间隔
		TCHAR strTime[256] = "";
#ifdef _UNICODE
		swprintf_s(strTime, _T("time escape:%d"), (nTime - nLastRenderTime));
#else
		sprintf_s(strTime, _T("time escape:%d"), (nTime - nLastRenderTime));
#endif
		TextOut(g_mdc, 0, 0, strTime, 15);

		//!拷贝到DC
		BitBlt(g_hdc, 0, 0, 600, 450, g_mdc, 0, 0, SRCCOPY);

		//!上次渲染时间
		nLastRenderTime = nTime;
	}
}