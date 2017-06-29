/********************************************************************
@file     RenderForm.h
@date     2017-6-29
@author   Zoro_Tiger
@brief    ��Ⱦ����
********************************************************************/
//!ͷ�ļ�
#include "DataDefine.h"

//!�궨��
#define WINDOW_CLASS _T("Chapter 12 Class")    //!����
#define WINDOW_NAME  _T("Chapter 12 Window")   //!����

//!������
class RenderForm
{

public:

	//!��������
	virtual ~RenderForm(void);

	//!��ȡ��Ⱦ����ʵ��
	static RenderForm* GetRenderForm(HINSTANCE hInstance);

	//!������Ⱦ����ʵ��
	static void ReleaseRenderForm(void);

public:

	//!��ʾ��Ⱦ����
	void Show(int show_cmd);

	//!�ر���Ⱦ����
	void Close(void);

	//!��Ⱦ
	void Render(DWORD time);

private:

	//!���캯��
	RenderForm(HINSTANCE hInstance);

	//!��ʼ��������Դ
	void _InitFormResources(void);

	//!���ش�����Դ
	void _LoadFormResources(void);

	//!��������Դ
	void _DeleFormResources(void);

	//!����������
	void _CreateWindowClass(void);

	//!��������
	void _CreateWindow(void);

	//!��Ⱦ����ͼ
	void _RenderBackground(void);

	//!����
	void _Present(void);

private:

	//!��Ⱦ����ʵ��
	static RenderForm* m_instance;

	//!����
	WNDCLASSEX m_wnd_class;

	//!����ʵ��
	HINSTANCE m_hInstance;

	//!������
	HWND m_hwnd;

	//!ǰ̨DC����̨DC��bufferDC
	HDC m_hdc, m_back_hdc, m_buffer_hdc;

};