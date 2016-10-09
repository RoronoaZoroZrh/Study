/********************************************************************
@file     Main.cpp
@date     2016-10-9
@author   Zoro_Tiger
@brief    一个基本的Windows应用程序
********************************************************************/
//宏定义
#define WIN32_LEAN_AND_MEAN         //不使用MFC

//包含文件
#include <Windows.h>
#include <windowsx.h>
#include <stdio.h>
#include <math.h>
#include <tchar.h>

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
			//验证窗口是否有效
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

	vWndClass.cbSize = sizeof(WNDCLASSEX);
	vWndClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC | CS_DBLCLKS;
	vWndClass.lpfnWndProc = WndProc;
	vWndClass.cbClsExtra = 0;
	vWndClass.cbWndExtra = 0;
	vWndClass.hInstance = hInstance;
	vWndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	vWndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	vWndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	vWndClass.lpszMenuName = NULL;
	vWndClass.lpszClassName = _T("My Class");
	vWndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&vWndClass))
	{
		return 0;
	}

	if (!(vHwnd = CreateWindowEx(NULL,
		_T("My Class"),
		_T("My Windows Application"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0,
		0,
		400,
		400,
		NULL,
		NULL,
		hInstance,
		NULL)))
	{
		return 0;
	}

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
	}
	return vMsg.wParam;
}