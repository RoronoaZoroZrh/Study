/********************************************************************
@file     Main.cpp
@date     2017-3-20
@author   Zoro_Tiger
@brief    ����������ʾ���ģ� ������ͼ
********************************************************************/
//!ͷ�ļ�
#include <tchar.h>
#include <cstring>
#include "DataDefine.h"

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
Dragon  g_dragon[DRAGON_NUM];

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

	for (int i = 0; i < DRAGON_NUM; ++i)
	{
		g_dragon[i].x = 200;
		g_dragon[i].y = 200;
		g_dragon[i].dir = 3;
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

void BubSort(void)
{
	for (int i = 0; i < DRAGON_NUM - 1; ++i)
	{
		bool order = true;
		for (int j = 0; j < DRAGON_NUM - i - 1; ++j)
		{
			if (g_dragon[j].y > g_dragon[j + 1].y)
			{
				auto temp = g_dragon[j];
				g_dragon[j] = g_dragon[j + 1];
				g_dragon[j + 1] = temp;
				order = false;
			}
		}
		
		if (order) break;
	}
}

//!��Ⱦ
void Render(UINT nTick)
{
	static int nPreTime = 0; //!ǰ����Ⱦʱ��
	static int nPictNum = 0; //!��ǰ�����±�

	//!��Ⱦ
	if (nTick - nPreTime >= RENDER_TIME)
	{
		nPreTime = nTick;

		//!��Ⱦ����
		SelectObject(g_bufferdc, g_background);
		BitBlt(g_mdc, 0, 0, 640, 480, g_bufferdc, 0, 0, SRCCOPY);

		//!����
		BubSort();

		//!��Ⱦ����
		for (int i = 0; i < DRAGON_NUM; ++i)
		{
			SelectObject(g_bufferdc, g_bitmapArray[g_dragon[i].dir]);

			int w, h;
			switch (g_dragon[i].dir)
			{
			case 0:
				{
					w = 66;
					h = 94;
					break;
				}
			case 1:
				{
					w = 68;
					h = 82;
					break;
				}
			case 2:
				{
					w = 95;
					h = 99;
					break;
				}
			case 3:
				{
					w = 95;
					h = 99;
					break;
				}
			}

			BitBlt(g_mdc, g_dragon[i].x, g_dragon[i].y, w, h, g_bufferdc, nPictNum * w, h, SRCAND);
			BitBlt(g_mdc, g_dragon[i].x, g_dragon[i].y, w, h, g_bufferdc, nPictNum * w, 0, SRCPAINT);
		}

		BitBlt(g_hdc, 0, 0, 640, 480, g_mdc, 0, 0, SRCCOPY);

		for(int i = 0; i < DRAGON_NUM; ++i)  
		{  
			switch(rand() % 4)
			{  
			case 0:
				switch(g_dragon[i].dir)  
				{  
				case 0:   
					g_dragon[i].y -= 20;  
					break;  
				case 1:  
					g_dragon[i].x += 2;  
					g_dragon[i].y -= 31;  
					break;  
				case 2:   
					g_dragon[i].x += 14;  
					g_dragon[i].y -= 20;  
					break;  
				case 3:  
					g_dragon[i].x += 14;  
					g_dragon[i].y -= 20;  
					break;  
				}  

				if(g_dragon[i].y < 0)  
					g_dragon[i].y = 0;  
				g_dragon[i].dir = 0;  
				break;
			case 1:
				switch(g_dragon[i].dir)  
				{  
				case 0:  
					g_dragon[i].x -= 2;  
					g_dragon[i].y += 31;  
					break;  
				case 1:  
					g_dragon[i].y += 20;  
					break;  
				case 2:  
					g_dragon[i].x += 15;  
					g_dragon[i].y += 29;  
					break;  
				case 3:  
					g_dragon[i].x += 15;  
					g_dragon[i].y += 29;  
					break;  
				}  

				if(g_dragon[i].y > 370)  
					g_dragon[i].y = 370;  
				g_dragon[i].dir = 1;  
				break;  
			case 2:
				switch(g_dragon[i].dir)  
				{  
				case 0:  
					g_dragon[i].x -= 34;  
					break;  
				case 1:  
					g_dragon[i].x -= 34;  
					g_dragon[i].y -= 9;  
					break;  
				case 2:  
					g_dragon[i].x -= 20;  
					break;  
				case 3:  
					g_dragon[i].x -= 20;  
					break;  
				}  
				if(g_dragon[i].x < 0)  
					g_dragon[i].x = 0;  
				g_dragon[i].dir = 2;  
				break;  
			case 3:
				switch(g_dragon[i].dir)  
				{  
				case 0:  
					g_dragon[i].x += 6;  
					break;  
				case 1:  
					g_dragon[i].x += 6;  
					g_dragon[i].y -= 10;  
					break;  
				case 2:  
					g_dragon[i].x += 20;  
					break;  
				case 3:  
					g_dragon[i].x += 20;  
					break;  
				}  
				if(g_dragon[i].x > 535)  
					g_dragon[i].x = 535;  
				g_dragon[i].dir = 3;  
				break;  
			}  
		}  

		++nPictNum; nPictNum %= 8;
	}
}