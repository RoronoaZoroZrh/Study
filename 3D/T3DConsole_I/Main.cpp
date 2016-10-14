/********************************************************************
@file     Main.cpp
@date     2016-10-14
@author   Zoro_Tiger
@brief    ���յ�T3D��Ϸ����̨
********************************************************************/

//�궨��
#define INITGUID //ȷ��COM�ӿڿ���
#define WIN32_LEAN_AND_MEAN //��ʹ��MFC

#define WINDOW_CLASS_NAME "My Window Class"
#define WINDOW_TITLE      "My Window Application"
#define WINDOW_WIDTH      640
#define WINDOW_HEIGHT     480
#define WINDOW_BPP        16
#define WINDOWED_APP      1

//ͷ�ļ�
#include <Windows.h>
#include <WindowsX.h>
#include <mmsystem.h>
#include <iostream>
#include <ddraw.h>
#include <dsound.h>
#include <dmksctrl.h>
#include <dmusici.h>
#include <dmusicc.h>
#include <dmusicf.h>
#include <dinput.h>
#include "t3dlib1.h"
#include "t3dlib2.h"
#include "t3dlib3.h"

//ȫ�ֱ���
HWND main_window_handle = NULL; //���ڴ洢���ھ��
HINSTANCE main_instance = NULL; //���ڴ洢ʵ��

//������������Ϸ����̨
int Game_Init(void* pParam = NULL);
int Game_Shut(void* pParam = NULL);
int Game_Main(void* pParam = NULL);

//�¼�������
LRESULT CALLBACK WndProc(HWND vHwnd, UINT nMsg, WPARAM vWparam, LPARAM vLparam)
{
	HDC vHdc;
	PAINTSTRUCT vPs;

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

//��ں���
int WINAPI WinMain(HINSTANCE vInstance,
	HINSTANCE vPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	//��������
	WNDCLASSEX vWndClsEx;
	HWND vHwnd;
	MSG vMsg;
	
	//���ô�����ṹ
	vWndClsEx.cbSize        = sizeof(WNDCLASSEX);
	vWndClsEx.style         = CS_OWNDC | CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
	vWndClsEx.lpfnWndProc   = WndProc;
	vWndClsEx.cbClsExtra    = 0;
	vWndClsEx.cbWndExtra    = 0;
	vWndClsEx.hInstance     = vInstance;
	vWndClsEx.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	vWndClsEx.hCursor       = LoadCursor(NULL, IDC_ARROW);
	vWndClsEx.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	vWndClsEx.lpszMenuName  = NULL;
	vWndClsEx.lpszClassName = WINDOW_CLASS_NAME;
	vWndClsEx.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

	//ע�ᴰ����
	if (!RegisterClassEx(&vWndClsEx))
	{
		return 0;
	}

	//��������
	vHwnd = CreateWindowEx(NULL,
		WINDOW_CLASS_NAME,
		WINDOW_TITLE,
		WINDOWED_APP ? WS_OVERLAPPEDWINDOW : WS_POPUP | WS_VISIBLE,
		0,
		0,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		NULL,
		NULL,
		vInstance,
		NULL);
	if (NULL == vHwnd)
	{
		return 0;
	}

	//�����ھ���ʹ���ʵ���洢��ȫ�ֱ�����
	main_instance = vInstance;
	main_window_handle = vHwnd;
	
	//�������ڴ�С
	if (WINDOWED_APP)
	{
		//�������ڴ�С
		RECT vWindowRect = { 0, 0, WINDOW_WIDTH - 1, WINDOW_HEIGHT - 1 };
		AdjustWindowRectEx(&vWindowRect,
			GetWindowStyle(main_window_handle),
			GetMenu(main_window_handle) != NULL,
			GetWindowExStyle(main_window_handle));

		//�洢ƫ����
		window_client_x0 = -vWindowRect.left;
		window_client_y0 = -vWindowRect.top;

		//�ƶ�����
		MoveWindow(main_window_handle,
			0,
			0,
			vWindowRect.right - vWindowRect.left,
			vWindowRect.bottom - vWindowRect.top,
			FALSE);

		//��ʾ����
		ShowWindow(vHwnd, nCmdShow);
	}

	//��Ϸ��ʼ��
	Game_Init();

	//���ð���
	SystemParametersInfo(SPI_SCREENSAVERRUNNING, FALSE, NULL, 0);

	//���¼�ѭ��
	while (TRUE)
	{
		//�����¼�
		if (PeekMessage(&vMsg, NULL, NULL, 0, PM_REMOVE))
		{
			if (vMsg.message == WM_QUIT)
			{
				return 0;
			}
			TranslateMessage(&vMsg);
			DispatchMessage(&vMsg);
		}

		//��Ϸ�߼�
		Game_Main();
	}

	//��Ϸ�ر�
	Game_Shut();

	//���ð���
	SystemParametersInfo(SPI_SCREENSAVERRUNNING, TRUE, NULL, 0);

	//���ص�����ϵͳ
	return vMsg.wParam;
}

//��Ϸ��ʼ��
int Game_Init(void* pParam /* = NULL */)
{
	//��ʼ��DirectDraw
	DDraw_Init(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_BPP, WINDOWED_APP);

	//��ʼ��DirectInput
	DInput_Init();

	//��ʼ������
	DInput_Init_Keyboard();

	//��ʼ��DirectSound
	DSound_Init();

	//��ʼ��DirectMusic
	DMusic_Init();

	//�������
	ShowCursor(FALSE);

	//�����������
	srand(Start_Clock());

	//��ʼ���ɹ�
	return TRUE;
}

//��Ϸ�ر�
int Game_Shut(void* pParam /* = NULL */)
{
	//�ر�DirectSound
	DSound_Stop_All_Sounds();
	DSound_Delete_All_Sounds();
	DSound_Shutdown();

	//�ر�DirectMusic
	DMusic_Delete_All_MIDI();
	DMusic_Shutdown();

	//�رռ���
	DInput_Release_Keyboard();

	//�ر�DirectInput
	DInput_Shutdown();

	//�ر�DirectDraw
	DDraw_Shutdown();

	//�رճɹ�
	return TRUE;
}

//��Ϸ�߼�
int Game_Main(void* pParam /* = NULL */)
{
	//������ʱʱ��
	Start_Clock();

	//��ջ���
	DDraw_Fill_Surface(lpddsback, 0);

	//��ȡ����
	DInput_Read_Keyboard();

	//��������
	DDraw_Flip();

	//ͬ����30֡/��
	Wait_Clock(30);

	//Escape���˳�
	if (KEY_DOWN(VK_ESCAPE) || keyboard_state[DIK_ESCAPE])
	{
		PostMessage(main_window_handle, WM_DESTROY, 0, 0);
	}

	//�ɹ�����
	return TRUE;
}