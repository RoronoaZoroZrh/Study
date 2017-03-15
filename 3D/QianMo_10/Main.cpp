/********************************************************************
@file     Main.cpp
@date     2017-3-15
@author   Zoro_Tiger
@brief    ����������ʾ������ ͸��������ʵ��
********************************************************************/
//!ͷ�ļ�
#include <Windows.h>
#include <tchar.h>
#include <cstring>

//!�궨��
#define WINDOW_CLASS _T("Chapter 10 Class") //!��������
#define WINDOW_NAME  _T("Chapter 10 Name")  //!��������
#define RENDER_SPACE 100                    //!��Ⱦ���
#define DRAGON_NUM   8                      //!��������
#define DRAGON_WIDTH 95                     //!�������
#define DRAGON_HEGTH 99                     //!�����߶�
#define DRAGON_X     640                    //!������ʼX����
#define DRAGON_Y     360                    //!������ʼY����

//!��������
bool RegistClass(HINSTANCE);
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
void Render(int nTime);

//!ȫ�ֱ���
HDC g_hdc = NULL; //!DC
HDC g_mdc = NULL; //!����DC
HDC g_bdc = NULL; //!bufDC
HBITMAP g_background = NULL, g_dragon = NULL; //!����ͼ����
HBITMAP g_mdcBackground = NULL; //!mdc����ͼ

//!�������
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
{
	//!ע�ᴰ����
	if (!RegistClass(hInstance))
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

	//!��������ʧ��
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
	g_bdc = CreateCompatibleDC(g_hdc);

	//!������ͼ
	g_background = (HBITMAP)LoadImage(NULL, _T("bg.bmp"), IMAGE_BITMAP, 640, 480, LR_LOADFROMFILE);
	g_dragon = (HBITMAP)LoadImage(NULL, _T("dra.bmp"), IMAGE_BITMAP, 760, 198, LR_LOADFROMFILE);
	g_mdcBackground = CreateCompatibleBitmap(g_hdc, 640, 480);
	SelectObject(g_mdc, g_mdcBackground);

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

//!ע�ᴰ����
bool RegistClass(HINSTANCE hInstance)
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
		return false;
	}
	return true;
}

//!��Ϣ������
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	//!������Ϣ
	switch(msg)
	{
	case WM_DESTROY:
		//!������Դ
		DeleteDC(g_mdc);
		DeleteDC(g_bdc);
		ReleaseDC(hWnd, g_hdc);
		DeleteObject(g_dragon);
		DeleteObject(g_background);
		DeleteObject(g_mdcBackground);
		PostQuitMessage(0);
		break;
	}

	//!Ĭ����Ϣ������
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

//!��Ⱦ
void Render(int nTime)
{
	static int nPreTime = nTime; //!ǰ����Ⱦʱ��
	static int nIndex = 0; //!�������
	static int nDragonX = DRAGON_X; //!����X����
	static int nDragonY = DRAGON_Y; //!����Y����

	//!��Ⱦ
	if (nTime - nPreTime >= RENDER_SPACE)
	{
		//!����͸��
		SelectObject(g_bdc, g_background);
		BitBlt(g_mdc, 0, 0, 640, 480, g_bdc, 0, 0, SRCCOPY);
 		SelectObject(g_bdc, g_dragon);
 		BitBlt(g_mdc, nDragonX, nDragonY, DRAGON_WIDTH, DRAGON_HEGTH, g_bdc, nIndex*DRAGON_WIDTH, DRAGON_HEGTH, SRCAND); //!���Ͻ���ԭ��
		BitBlt(g_mdc, nDragonX, nDragonY, DRAGON_WIDTH, DRAGON_HEGTH, g_bdc, nIndex*DRAGON_WIDTH, 0, SRCPAINT);
		BitBlt(g_hdc, 0, 0, 640, 480, g_mdc, 0, 0, SRCCOPY);

		//!������������
		nDragonX = nDragonX - 20;
		if (nDragonX <= -DRAGON_WIDTH)
		{
			nDragonX = DRAGON_X;
		}

		//!�����������
		++nIndex;
		nIndex = nIndex % DRAGON_NUM;

		//!����ǰ����Ⱦʱ��
		nPreTime = nTime;
	}
}