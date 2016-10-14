/********************************************************************
@file     Main.cpp
@date     2016-10-14
@author   Zoro_Tiger
@brief    最终的T3D游戏控制台
********************************************************************/

//宏定义
#define INITGUID //确保COM接口可用
#define WIN32_LEAN_AND_MEAN //不使用MFC

#define WINDOW_CLASS_NAME "My Window Class"
#define WINDOW_TITLE      "My Window Application"
#define WINDOW_WIDTH      640
#define WINDOW_HEIGHT     480
#define WINDOW_BPP        16
#define WINDOWED_APP      1

//头文件
#include <Windows.h>
#include <WindowsX.h>
#include <mmsystem.h>
#include <iostream>
#include <ddraw.h>
#include <dsound.h>
#include <dmksctrl.h>
#include <dmusici.h>
#include <dmusicc.h>
#include <dmusicf.h>
#include <dinput.h>
#include "t3dlib1.h"
#include "t3dlib2.h"
#include "t3dlib3.h"

//全局变量
HWND main_window_handle = NULL; //用于存储窗口句柄
HINSTANCE main_instance = NULL; //用于存储实例

//函数声明、游戏控制台
int Game_Init(void* pParam = NULL);
int Game_Shut(void* pParam = NULL);
int Game_Main(void* pParam = NULL);

//事件处理函数
LRESULT CALLBACK WndProc(HWND vHwnd, UINT nMsg, WPARAM vWparam, LPARAM vLparam)
{
	HDC vHdc;
	PAINTSTRUCT vPs;

	switch (nMsg)
	{
	case WM_CREATE:
		{
			return 0;
		}
	case WM_PAINT:
		{
			vHdc = BeginPaint(vHwnd, &vPs);
			EndPaint(vHwnd, &vPs);
			return 0;
		}
	case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}
	default:
		{
			break;
		}
	}
	return DefWindowProc(vHwnd, nMsg, vWparam, vLparam);
}

//入口函数
int WINAPI WinMain(HINSTANCE vInstance,
	HINSTANCE vPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	//变量声明
	WNDCLASSEX vWndClsEx;
	HWND vHwnd;
	MSG vMsg;
	
	//设置窗口类结构
	vWndClsEx.cbSize        = sizeof(WNDCLASSEX);
	vWndClsEx.style         = CS_OWNDC | CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
	vWndClsEx.lpfnWndProc   = WndProc;
	vWndClsEx.cbClsExtra    = 0;
	vWndClsEx.cbWndExtra    = 0;
	vWndClsEx.hInstance     = vInstance;
	vWndClsEx.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	vWndClsEx.hCursor       = LoadCursor(NULL, IDC_ARROW);
	vWndClsEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	vWndClsEx.lpszMenuName  = NULL;
	vWndClsEx.lpszClassName = WINDOW_CLASS_NAME;
	vWndClsEx.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

	//注册窗口类
	if (!RegisterClassEx(&vWndClsEx))
	{
		return 0;
	}

	//创建窗口
	vHwnd = CreateWindowEx(NULL,
		WINDOW_CLASS_NAME,
		WINDOW_TITLE,
		WINDOWED_APP ? WS_OVERLAPPEDWINDOW : WS_POPUP | WS_VISIBLE,
		0,
		0,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		NULL,
		NULL,
		vInstance,
		NULL);
	if (NULL == vHwnd)
	{
		return 0;
	}

	//将窗口句柄和窗口实例存储到全局变量中
	main_instance = vInstance;
	main_window_handle = vHwnd;
	
	//调整窗口大小
	if (WINDOWED_APP)
	{
		//调整窗口大小
		RECT vWindowRect = { 0, 0, WINDOW_WIDTH - 1, WINDOW_HEIGHT - 1 };
		AdjustWindowRectEx(&vWindowRect,
			GetWindowStyle(main_window_handle),
			GetMenu(main_window_handle) != NULL,
			GetWindowExStyle(main_window_handle));

		//存储偏移量
		window_client_x0 = -vWindowRect.left;
		window_client_y0 = -vWindowRect.top;

		//移动窗口
		MoveWindow(main_window_handle,
			0,
			0,
			vWindowRect.right - vWindowRect.left,
			vWindowRect.bottom - vWindowRect.top,
			FALSE);

		//显示窗口
		ShowWindow(vHwnd, nCmdShow);
	}

	//游戏初始化
	Game_Init();

	//禁用按键
	SystemParametersInfo(SPI_SCREENSAVERRUNNING, FALSE, NULL, 0);

	//主事件循环
	while (TRUE)
	{
		//处理事件
		if (PeekMessage(&vMsg, NULL, NULL, 0, PM_REMOVE))
		{
			if (vMsg.message == WM_QUIT)
			{
				return 0;
			}
			TranslateMessage(&vMsg);
			DispatchMessage(&vMsg);
		}

		//游戏逻辑
		Game_Main();
	}

	//游戏关闭
	Game_Shut();

	//启用按键
	SystemParametersInfo(SPI_SCREENSAVERRUNNING, TRUE, NULL, 0);

	//返回到操作系统
	return vMsg.wParam;
}

//游戏初始化
int Game_Init(void* pParam /* = NULL */)
{
	//初始化DirectDraw
	DDraw_Init(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BPP, WINDOWED_APP);

	//初始化DirectInput
	DInput_Init();

	//初始化键盘
	DInput_Init_Keyboard();

	//初始化DirectSound
	DSound_Init();

	//初始化DirectMusic
	DMusic_Init();

	//隐藏鼠标
	ShowCursor(FALSE);

	//随机数生成器
	srand(Start_Clock());

	//初始化成功
	return TRUE;
}

//游戏关闭
int Game_Shut(void* pParam /* = NULL */)
{
	//关闭DirectSound
	DSound_Stop_All_Sounds();
	DSound_Delete_All_Sounds();
	DSound_Shutdown();

	//关闭DirectMusic
	DMusic_Delete_All_MIDI();
	DMusic_Shutdown();

	//关闭键盘
	DInput_Release_Keyboard();

	//关闭DirectInput
	DInput_Shutdown();

	//关闭DirectDraw
	DDraw_Shutdown();

	//关闭成功
	return TRUE;
}

//游戏逻辑
int Game_Main(void* pParam /* = NULL */)
{
	//启动定时时钟
	Start_Clock();

	//清空缓存
	DDraw_Fill_Surface(lpddsback, 0);

	//读取键盘
	DInput_Read_Keyboard();

	//交换缓存
	DDraw_Flip();

	//同步到30帧/秒
	Wait_Clock(30);

	//Escape键退出
	if (KEY_DOWN(VK_ESCAPE) || keyboard_state[DIK_ESCAPE])
	{
		PostMessage(main_window_handle, WM_DESTROY, 0, 0);
	}

	//成功返回
	return TRUE;
}