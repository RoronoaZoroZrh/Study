/********************************************************************
@file     Main.cpp
@date     2017-6-28
@author   Zoro_Tiger
@brief    游戏输入消息处理（一） 键盘消息处理
********************************************************************/
//!头文件
#include "RenderForm.h"

//!程序入口
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
{
	//!显示渲染窗体
	RenderForm::GetRenderForm(hInstance)->Show(nShowCmd);

	//!变量声明
	MSG msg;

	//!获取消息
	GetMessage(&msg, NULL, NULL, NULL);

	//!消息循环
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			RenderForm::GetRenderForm(hInstance)->Render(GetTickCount());
		}
	}

	//!返回系统
	return msg.wParam;
}