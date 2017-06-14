/********************************************************************
@file     Main.cpp
@date     2017-3-20
@author   Zoro_Tiger
@brief    ����������ʾ���ģ� ������ͼ
********************************************************************/
//!ͷ�ļ�
#include <Windows.h>
#include <tchar.h>
#include <cstring>

//!�궨��
#define WINDOW_CLASS _T("Chapter 11 Class")  //!����
#define WINDOW_NAME  _T("Chapter 11 Window") //!����
#define BITMAP_NUM   4                       //!��ͼ����
#define RENDER_TIME  100                     //!��Ⱦ���

//!ȫ�ֱ���
HDC g_hdc = NULL;
HDC g_mdc = NULL;
HDC g_bufferdc = NULL;
HBITMAP g_bitmapArray[BITMAP_NUM] = { NULL };
HBITMAP g_background = NULL;

//!��������
void Render(UINT nTick);

//!��Ϣ������
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//!������Ϣ
	switch (msg)
	{
	case WM_DESTROY:
		//!������Դ
		DeleteDC(g_bufferdc);
		DeleteDC(g_mdc);
		ReleaseDC(hWnd, g_hdc);
		PostQuitMessage(0);
		break;
	}

	//!Ĭ����Ϣ������
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

//!�������
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd )
{
	//!������
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.style = CS_CLASSDC;
	wc.lpfnWndProc = WndProc;
	wc.lpszClassName = WINDOW_CLASS;
	wc.lpszMenuName = NULL;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hIcon = NULL;
	wc.hIconSm = NULL;
	wc.hInstance = hInstance;

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
		640,
		480,
		NULL,
		NULL,
		hInstance,
		NULL);

	//!��ʾ����
	ShowWindow(hWnd, nShowCmd);

	//!���´���
	UpdateWindow(hWnd);

	//!����DC
	g_hdc = GetDC(hWnd);
	g_mdc = CreateCompatibleDC(g_hdc);
	g_bufferdc = CreateCompatibleDC(g_hdc);

	//!������ͼ
	HBITMAP mdcPic = CreateCompatibleBitmap(g_hdc, 640, 480);
	SelectObject(g_mdc, mdcPic);
	g_bitmapArray[0] = (HBITMAP)LoadImage(NULL, _T("dra0.bmp"), IMAGE_BITMAP, 528, 188, LR_LOADFROMFILE);
	g_bitmapArray[1] = (HBITMAP)LoadImage(NULL, _T("dra1.bmp"), IMAGE_BITMAP, 544, 164, LR_LOADFROMFILE);
	g_bitmapArray[2] = (HBITMAP)LoadImage(NULL, _T("dra2.bmp"), IMAGE_BITMAP, 760, 198, LR_LOADFROMFILE);
	g_bitmapArray[3] = (HBITMAP)LoadImage(NULL, _T("dra3.bmp"), IMAGE_BITMAP, 760, 198, LR_LOADFROMFILE);
	g_background = (HBITMAP)LoadImage(NULL, _T("bg.bmp"), IMAGE_BITMAP, 640, 480, LR_LOADFROMFILE);

	//!��ȡ��Ϣ
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

//!��Ⱦ
void Render(UINT nTick)
{
	static int nPreTime = 0; //!ǰ����Ⱦʱ��

	//!��Ⱦ
	if (nTick - nPreTime >= RENDER_TIME)
	{
		nPreTime = nTick;

		//!��Ⱦ����
		SelectObject(g_bufferdc, g_background);
		BitBlt(g_mdc, 0, 0, 640, 480, g_bufferdc, 0, 0, SRCCOPY);
		BitBlt(g_hdc, 0, 0, 640, 480, g_mdc, 0, 0, SRCCOPY);
	}
}