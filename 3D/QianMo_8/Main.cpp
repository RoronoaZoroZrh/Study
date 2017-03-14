/********************************************************************
@file     Main.cpp
@date     2017-3-14
@author   Zoro_Tiger
@brief    ����������ʾ��������Ϸѭ����ʹ��
********************************************************************/
//!ͷ�ļ�
#include <Windows.h>
#include <tchar.h>
#include <string>

//!�궨��
#define WINDOW_CLASS _T("Chapter 8 Class")
#define WINDOW_NAME  _T("Chapter 8 Window")
#define BITMAP_NUM   8
#define FILENAME_LEN 28
#define RENDER_SPACE 100

//!ȫ�ֱ���
HDC g_hdc = NULL, g_mdc = NULL;
HBITMAP g_bitmapArray[BITMAP_NUM] = { NULL };

//!��Ϣ������
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//!������Ϣ
	switch (msg)
	{
	case WM_DESTROY:
		{
			//!ɾ��DC
			DeleteDC(g_mdc);
			ReleaseDC(hWnd, g_hdc);
			//!ɾ����ͼ
			for (int i = 0; i < BITMAP_NUM; ++i)
			{
				DeleteObject(g_bitmapArray[i]);
			}
			PostQuitMessage(0);
			break;
		}
	}

	//!Ĭ����Ϣ������
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

//!��������
void Render(UINT nTime);

//!��ں���
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
		NULL
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

	//!��������ʧ��
	if (NULL == hWnd)
	{
		return -1;
	}

	//!��ʾ����
	ShowWindow(hWnd, nShowCmd);

	//���´���
	UpdateWindow(hWnd);

	//!��ʼ��DC
	g_hdc = GetDC(hWnd);
	g_mdc = CreateCompatibleDC(g_hdc);

	//!��ʼ����ͼ
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
void Render(UINT nTime)
{
	//!��������
	static int nIndex = 0;
	static int nLastRenderTime = 0;

	//!��Ⱦ
	if (nTime - nLastRenderTime >= RENDER_SPACE)
	{
		//!ѡ����ͼ���󵽼���DC
		SelectObject(g_mdc, g_bitmapArray[nIndex]);
		nIndex = (++nIndex) % BITMAP_NUM;

		//!��ʾʱ����
		TCHAR strTime[256] = "";
#ifdef _UNICODE
		swprintf_s(strTime, _T("time escape:%d"), (nTime - nLastRenderTime));
#else
		sprintf_s(strTime, _T("time escape:%d"), (nTime - nLastRenderTime));
#endif
		TextOut(g_mdc, 0, 0, strTime, 15);

		//!������DC
		BitBlt(g_hdc, 0, 0, 600, 450, g_mdc, 0, 0, SRCCOPY);

		//!�ϴ���Ⱦʱ��
		nLastRenderTime = nTime;
	}
}