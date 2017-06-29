/********************************************************************
@file     Main.cpp
@date     2017-6-28
@author   Zoro_Tiger
@brief    ��Ϸ������Ϣ����һ�� ������Ϣ����
********************************************************************/
//!ͷ�ļ�
#include "RenderForm.h"

//!�������
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
{
	//!��ʾ��Ⱦ����
	RenderForm::GetRenderForm(hInstance)->Show(nShowCmd);

	//!��������
	MSG msg;

	//!��ȡ��Ϣ
	GetMessage(&msg, NULL, NULL, NULL);

	//!��Ϣѭ��
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

	//!����ϵͳ
	return msg.wParam;
}