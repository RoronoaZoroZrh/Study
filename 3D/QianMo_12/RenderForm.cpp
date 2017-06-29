/********************************************************************
@file     RenderForm.cpp
@date     2017-6-29
@author   Zoro_Tiger
@brief    渲染窗口
********************************************************************/
//!头文件
#include "RenderForm.h"
#include "ResourcesManager.h"

//!初始化
RenderForm* RenderForm::m_instance = NULL;

//!窗体消息处理函数
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}

RenderForm::RenderForm(HINSTANCE hInstance)
{
	_InitFormResources();
	this->m_hInstance = hInstance;
	_LoadFormResources();
}

RenderForm::~RenderForm(void)
{
	_DeleFormResources();
}

RenderForm* RenderForm::GetRenderForm(HINSTANCE hInstance)
{
	if (NULL == m_instance)
	{
		m_instance = new RenderForm(hInstance);
	}
	return m_instance;
}

void RenderForm::ReleaseRenderForm(void)
{
	if (NULL != m_instance)
	{
		delete m_instance; m_instance = NULL;
	}
}

void RenderForm::Show(int show_cmd)
{
	if (NULL == this->m_hwnd)
	{
		_CreateWindow();
	}
	ShowWindow(this->m_hwnd, show_cmd);
	UpdateWindow(this->m_hwnd);
}

void RenderForm::Close(void)
{
	SendMessage(this->m_hwnd, WM_CLOSE, NULL, NULL);
}

void RenderForm::Render(DWORD time)
{
	static DWORD last_render_time = 0;
	if (time - last_render_time >= 100)
	{
		_RenderBackground();
		_Present();
		last_render_time = time;
	}
}

void RenderForm::_InitFormResources(void)
{
	memset(&(this->m_wnd_class), NULL, sizeof(WNDCLASSEX));
	this->m_hInstance = NULL;
	this->m_hwnd = NULL;
	this->m_hdc = this->m_back_hdc = this->m_buffer_hdc = NULL;
}

void RenderForm::_LoadFormResources(void)
{
	_CreateWindowClass();
	this->m_hdc = GetDC(this->m_hwnd);
	this->m_back_hdc = CreateCompatibleDC(this->m_hdc);
	this->m_buffer_hdc = CreateCompatibleDC(this->m_hdc);
	HBITMAP temp_bitmap = CreateCompatibleBitmap(this->m_hdc, 640, 480);
	SelectObject(this->m_back_hdc, temp_bitmap);
}

void RenderForm::_DeleFormResources(void)
{
	UnregisterClass(WINDOW_CLASS, this->m_hInstance);
	ReleaseDC(this->m_hwnd, this->m_hdc);
	DeleteDC(this->m_back_hdc);
	DeleteDC(this->m_buffer_hdc);
}

void RenderForm::_CreateWindowClass(void)
{
	this->m_wnd_class.cbSize = sizeof(WNDCLASSEX);
	this->m_wnd_class.cbClsExtra = 0;
	this->m_wnd_class.cbWndExtra = 0;
	this->m_wnd_class.lpfnWndProc = WndProc;
	this->m_wnd_class.lpszClassName = WINDOW_CLASS;
	this->m_wnd_class.lpszMenuName = NULL;
	this->m_wnd_class.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	this->m_wnd_class.hCursor = LoadCursor(NULL, IDC_ARROW);
	this->m_wnd_class.hIcon = NULL;
	this->m_wnd_class.hIconSm = NULL;
	this->m_wnd_class.hInstance = this->m_hInstance;
	RegisterClassEx(&this->m_wnd_class);
}

void RenderForm::_CreateWindow(void)
{
	this->m_hwnd = CreateWindow(WINDOW_CLASS,
		WINDOW_NAME,
		WS_OVERLAPPEDWINDOW,
		10,
		10,
		648,
		480,
		NULL,
		NULL,
		this->m_hInstance,
		NULL);
}

void RenderForm::_RenderBackground(void)
{
// 	HBITMAP background = ResourcesManager::GetResourcesManager()->GetBackground();
// 	SelectObject(this->m_buffer_hdc, background);
// 	BitBlt(this->m_back_hdc, 0, 0, 640, 480, this->m_buffer_hdc, 0, 0, SRCCOPY);

	auto bg = (HBITMAP)LoadImage(NULL,_T("bg.bmp"),IMAGE_BITMAP,640,480,LR_LOADFROMFILE);  
	HDC hdc = GetDC(this->m_hwnd);
	HDC mdc = CreateCompatibleDC(hdc); //!兼容DC
	SelectObject(mdc, bg);
	BitBlt(hdc, 0, 0, 640, 480, mdc, 0, 0, SRCCOPY);
}

void RenderForm::_Present(void)
{
	//BitBlt(this->m_hdc, 0, 0, 640, 480, this->m_back_hdc, 0, 0, SRCCOPY);
}