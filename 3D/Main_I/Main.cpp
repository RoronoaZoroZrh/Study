/********************************************************************
@file     Main.cpp
@date     2016-10-9
@author   Zoro_Tiger
@brief    Windows�������С����
********************************************************************/
#define WIN32_LEAN_AND_MEAN //��ʹ��MFC

#include <Windows.h>  //��������ͷ�ļ�
#include <WindowsX.h> //����������ͳ���
#include <tchar.h>    //_Tͷ�ļ�

//����Windows��������
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	MessageBox(NULL, _T("There can be only one!"), _T("Information"), MB_OK | MB_ICONEXCLAMATION);
	return 0;
}