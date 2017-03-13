/********************************************************************
@file     Main.cpp
@date     2017-3-10
@author   Zoro_Tiger
@brief    ����������ʾ��һ����ʱ����ʹ��
********************************************************************/
//!ͷ�ļ�
#include <Windows.h>
#include <tchar.h>
#include <string>

//!�궨��
#define WINDOW_CLASS _T("Chapter 7 Class")
#define WINDOW_NAME  _T("Chapter 7 Window")
#define BITMAP_NUM   7
#define FILENAME_NUM 28

//!ȫ�ֱ���
HDC g_hdc = NULL, g_mdc = NULL;
HBITMAP g_bitmapArray[BITMAP_NUM] = { NULL };

//!��Ϣ��Ӧ����
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//!��������
	static int nBitmapNum = 0;

	//!������Ϣ
	switch (msg)
	{
	case WM_TIMER:
		SelectObject(g_mdc, g_bitmapArray[nBitmapNum++]);
		nBitmapNum %= BITMAP_NUM;
		BitBlt(g_hdc, 0, 0, 600, 450, g_mdc, 0, 0, SRCCOPY);
		break;
	case WM_DESTROY:
		//!������Դ
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

	//!Ĭ����Ϣ��Ӧ����
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

//!�������
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
{
	//!������
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

	//!ע�ᴰ����
	if (FAILED(RegisterClassEx(&wc)))
	{
		return -1;
	}

	//!��������
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

	//!���ڴ���ʧ��
	if (NULL == hWnd)
	{
		return -1;
	}

	//!��ʾ����
	ShowWindow(hWnd, nShowCmd);

	//!���´���
	UpdateWindow(hWnd);

	//!����DC
	g_hdc = GetDC(hWnd);
	g_mdc = CreateCompatibleDC(g_hdc);

	//!����Bitmap
	TCHAR strFile[FILENAME_NUM] = { 0 };
	for (int i = 0; i < BITMAP_NUM; ++i)
	{
		swprintf_s(strFile, _T("girl%d.bmp"), i);
		g_bitmapArray[i] = (HBITMAP)LoadImage(NULL, strFile, IMAGE_BITMAP, 640, 480, LR_LOADFROMFILE);
	}

	//!���ö�ʱ��
	SetTimer(hWnd, 1, 50, NULL);

	//!��Ϣ����
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam; //!�����˳���Ϣ
}