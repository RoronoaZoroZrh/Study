/********************************************************************
@file     Main.cpp
@date     2016-10-10
@author   Zoro_Tiger
@brief    第一个版本的游戏控制台
********************************************************************/

//宏定义
#define WIN32_LEAN_AND_MEAN //不使用MFC
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0X8000) ? 1 : 0)
#define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code) & 0X8000) ? 0 : 1)

//头文件
#include <Windows.h>
#include <WindowsX.h>
#include <tchar.h>

//全局变量
HINSTANCE gInstance = NULL;
HWND gHwnd = NULL;

//函数声明
int Game_Init(void* pParam = NULL);
int Game_Main(void* pParam = NULL);
int Game_Shut(void* pParam = NULL);

//事件处理函数
LRESULT CALLBACK WndProc(HWND vHwnd, UINT nMsg, WPARAM vWparam, LPARAM vLparam)
{
	PAINTSTRUCT vPs;
	HDC vHdc;

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

//程序入口
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	WNDCLASSEX vWndClass;
	HWND vHwnd;
	MSG vMsg;

	vWndClass.cbSize = sizeof(vWndClass);
	vWndClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC | CS_DBLCLKS;
	vWndClass.lpfnWndProc = WndProc;
	vWndClass.hInstance = hInstance;
	vWndClass.cbClsExtra = 0;
	vWndClass.cbWndExtra = 0;
	vWndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	vWndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	vWndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	vWndClass.lpszClassName = _T("My Class");
	vWndClass.lpszMenuName = NULL;
	vWndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&vWndClass))
	{
		return 0;
	}

	if (!(vHwnd = CreateWindowEx(NULL,
		_T("My Class"),
		_T("My Window Application"),
		WS_OVERLAPPEDWINDOW,
		0,
		0,
		800,
		600,
		NULL,
		NULL,
		hInstance,
		NULL)))
	{
		return 0;
	}

	::gInstance = hInstance;
	::gHwnd = vHwnd;

	ShowWindow(gHwnd, SW_SHOW);

	Game_Init();
	while(TRUE)
	{
		if (PeekMessage(&vMsg, NULL, 0, 0, PM_REMOVE))
		{
			if (vMsg.message == WM_QUIT)
			{
				break;
			}
			TranslateMessage(&vMsg);
			DispatchMessage(&vMsg);
		}
		Game_Main();
	}
	Game_Shut();
	
	return vMsg.wParam;
}

int Game_Init(void* pParam /* = NULL */)
{
	return 1;
}

int Game_Main(void* pParam /* = NULL */)
{
	if (KEY_DOWN(VK_ESCAPE))
	{
		PostMessage(gHwnd, WM_DESTROY, 0, 0);
	}
	return 1;
}

int Game_Shut(void* pParam /* = NULL */)
{
	return 1;
}