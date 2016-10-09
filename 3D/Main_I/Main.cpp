/********************************************************************
@file     Main.cpp
@date     2016-10-9
@author   Zoro_Tiger
@brief    Windows程序的最小需求
********************************************************************/
#define WIN32_LEAN_AND_MEAN //不使用MFC

#include <Windows.h>  //包含大量头文件
#include <WindowsX.h> //包含大量宏和常量
#include <tchar.h>    //_T头文件

//所有Windows程序的入口
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	MessageBox(NULL, _T("There can be only one!"), _T("Information"), MB_OK | MB_ICONEXCLAMATION);
	return 0;
}