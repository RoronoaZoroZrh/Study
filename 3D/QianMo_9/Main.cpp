/********************************************************************
@file     Main.cpp
@date     2017-3-14
@author   Zoro_Tiger
@brief    ��Ϸ��ͼ������һ��ƽ���ͼ��ͼ
********************************************************************/
//!ͷ�ļ�
#include <Windows.h>
#include <tchar.h>
#include <cstring>

//!�궨��
#define WINDOW_CLASS _T("Chapter 9 Class")  //!����
#define WINDOW_NAME  _T("Chapter 9 Window") //!��������
#define BITMAP_NUM   3                      //!��ͼ����
#define FILEPATH_LEN 256                    //!·������
#define MAP_ROW      8                      //!��
#define MAP_COL      8                      //!��
#define BITMAP_WIDTH 50                     //!��ͼ���
#define BITMAP_HEGTH 50                     //!��ͼ����

//!ȫ�ֱ���
HDC g_hdc = NULL, g_mdc = NULL; //!HDC������HDC
HBITMAP g_bitmap = NULL;        //!��ͼ

//!��������
void Render(void);

//!��Ϣ������
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//!������Ϣ
	switch (msg)
	{
	case WM_DESTROY:
		//!������Դ
		DeleteDC(g_mdc);
		ReleaseDC(hWnd, g_hdc);
		DeleteObject(g_bitmap);
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
	int nShowCmds)
{
	//!����������
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
		430,
		450,
		NULL,
		NULL,
		hInstance,
		NULL);

	//!��ʾ����
	ShowWindow(hWnd, nShowCmds);

	//!���´���
	UpdateWindow(hWnd);

	//!��ʼ��DC
	g_hdc = GetDC(hWnd);
	g_mdc = CreateCompatibleDC(g_hdc);

	//!��ȡС��ͼ
	HBITMAP bitmap[BITMAP_NUM];
	TCHAR strFile[FILEPATH_LEN];
	for (int i = 0; i < BITMAP_NUM; ++i)
	{
#ifdef _UNICODE
		swprintf_s(strFile, _T("map%d.bmp"), i);
#else
		sprintf_s(strFile, _T("map%d.bmp"), i);
#endif
		bitmap[i] = (HBITMAP)LoadImage(NULL, strFile, IMAGE_BITMAP, 50, 50, LR_LOADFROMFILE);
	}

	//!��������ͼ
	g_bitmap = CreateCompatibleBitmap(g_hdc, MAP_COL * BITMAP_WIDTH, MAP_ROW * BITMAP_HEGTH);
	SelectObject(g_mdc, g_bitmap);

	//!��С��ͼ��װ�ɴ���ͼ
	int nMapIndex = 0;
	HDC mdc = CreateCompatibleDC(g_hdc);
	for (int i = 0; i < MAP_ROW; ++i)
	{
		for (int j = 0; j < MAP_COL; ++j)
		{
			nMapIndex = j % BITMAP_NUM;
			SelectObject(mdc, bitmap[nMapIndex]);
			BitBlt(g_mdc, i * BITMAP_WIDTH, j * BITMAP_HEGTH, BITMAP_WIDTH, BITMAP_HEGTH, mdc, 0, 0, SRCCOPY);
		}
	}

	//!ɾ��DC
	DeleteDC(mdc);

	//!ɾ��С��ͼ
	for (int i = 0; i < BITMAP_NUM; ++i)
	{
		DeleteObject(bitmap[i]);
	}

	//!�����Ϣ
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
			Render();
		}
	}
	return msg.wParam;
}

//!��Ⱦ
void Render(void)
{
	BitBlt(g_hdc, 0, 0, MAP_COL * BITMAP_WIDTH, MAP_ROW * BITMAP_HEGTH, g_mdc, 0, 0, SRCCOPY);
}