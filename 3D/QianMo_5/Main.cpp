/********************************************************************
@file     Main.cpp
@date     2017-2-14
@author   Zoro_Tiger
@brief    游戏画面绘图（二）绘制位图
********************************************************************/
#include <Windows.h>

#define WINDOW_CLASS "Chapter 5 Class"
#define WINDOW_NAME "Chapter 5 Window"

HDC g_dc;
HBITMAP g_bitmap;

LRESULT WINAPI WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{	
	PAINTSTRUCT ps;
	HDC hdc;

	switch (Msg)
	{
	case WM_PAINT:
		
		hdc = BeginPaint(hWnd, &ps);
		BitBlt(hdc, 0, 0, 800, 600, g_dc, 0, 0, SRCCOPY);
		EndPaint(hWnd, &ps);
	case WM_DESTROY:
		DeleteDC(g_dc);
		DeleteObject(g_bitmap);
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, Msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
{
	WNDCLASSEX wndClass = {
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

	if (FAILED(RegisterClassEx(&wndClass)))
	{
		return -1;
	}

	HWND hWnd = CreateWindow(WINDOW_CLASS,
		WINDOW_NAME,
		WS_OVERLAPPEDWINDOW,
		0,
		0,
		800,
		600,
		NULL,
		NULL,
		hInstance,
		NULL);
	UpdateWindow(hWnd);
	ShowWindow(hWnd, nShowCmd);

	HDC hdc = GetDC(hWnd);
	g_dc = CreateCompatibleDC(hdc);

	g_bitmap = (HBITMAP)LoadImage(NULL, "bg.bmp", IMAGE_BITMAP, 800, 600, LR_LOADFROMFILE);
	SelectObject(g_dc, g_bitmap);

	BitBlt(hdc, 0, 0, 800, 600, g_dc, 0, 0, SRCCOPY);

	ReleaseDC(hWnd, hdc);

	MSG msg;
	while (GetMessage(&msg, hWnd, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}