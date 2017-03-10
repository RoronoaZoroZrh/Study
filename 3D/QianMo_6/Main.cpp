/********************************************************************
@file     Main.cpp
@date     2017-3-10
@author   Zoro_Tiger
@brief    ��Ϸ�����ͼ������͸����Ч����������
********************************************************************/
//!ͷ�ļ�
#include <Windows.h>
#include <tchar.h>

//!�궨��
#define WINDOW_CLASS _T("Chapter 6 Class")
#define WINDOW_NAME  _T("Chapter 6 Window")

//!ȫ�ֱ���
HDC g_mdc = NULL; //!����DC
HBITMAP g_backgroundPic = NULL, g_dragonPic = NULL; //!����ͼƬ�����ͼƬ

//!��Ϣ������
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//!��������
	PAINTSTRUCT ps;
	HDC hdc;

	//��Ϣ����
	switch (msg)
	{
	case WM_PAINT:
		
		//!��ʼ����
		hdc = BeginPaint(hWnd, &ps);

		//!���Ʊ���
		SelectObject(g_mdc, g_backgroundPic);
		BitBlt(hdc, 0, 0, 600, 450, g_mdc, 0, 0, SRCCOPY);

		//!���ƿ���
		SelectObject(g_mdc, g_dragonPic);
		BitBlt(hdc, 200, 320, 85, 99, g_mdc, 85, 0, SRCAND);
		BitBlt(hdc, 200, 320, 85, 99, g_mdc, 0,  0, SRCPAINT);

		//!��������
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		//!������Դ
		DeleteDC(g_mdc);
		DeleteObject(g_backgroundPic);
		DeleteObject(g_dragonPic);
		PostQuitMessage(0);
		break;
	}

	//!Ĭ����Ϣ������
	return DefWindowProc(hWnd, msg, wParam, lParam); 
}

//!�������
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lCmdLine,
	int nShowCmd)
{
	//!������
	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX),
		CS_CLASSDC, //!�ô���������д���ʵ��������һ��������
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
	HDC hdc = GetDC(hWnd);
	HDC mdc = CreateCompatibleDC(hdc); //!����DC
	g_mdc = mdc;

	//!��ȡλͼ
	g_backgroundPic = (HBITMAP)LoadImage(NULL, _T("bg.bmp"), IMAGE_BITMAP, 600, 450, LR_LOADFROMFILE);
	g_dragonPic = (HBITMAP)LoadImage(NULL, _T("dra.bmp"), IMAGE_BITMAP, 170, 99, LR_LOADFROMFILE);

	//!���Ʊ���
	SelectObject(g_mdc, g_backgroundPic);
	BitBlt(hdc, 0, 0, 600, 450, g_mdc, 0, 0, SRCCOPY);

	//!���ƿ���
	SelectObject(g_mdc, g_dragonPic);
	BitBlt(hdc, 200, 320, 85, 99, g_mdc, 85, 0, SRCAND);
	BitBlt(hdc, 200, 320, 85, 99, g_mdc, 0,  0, SRCPAINT);

	//!ɾ��DC
	ReleaseDC(hWnd, hdc);

	//!������Ϣ
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		//!����Ϣ�������⴦��
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	//!���ز���ϵͳ
	return msg.wParam;
}