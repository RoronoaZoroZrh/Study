/********************************************************************
@file     RenderForm.h
@date     2017-6-29
@author   Zoro_Tiger
@brief    渲染窗口
********************************************************************/
//!头文件
#include "DataDefine.h"

//!宏定义
#define WINDOW_CLASS _T("Chapter 12 Class")    //!类名
#define WINDOW_NAME  _T("Chapter 12 Window")   //!窗口

//!窗体类
class RenderForm
{

public:

	//!析构函数
	virtual ~RenderForm(void);

	//!获取渲染窗口实例
	static RenderForm* GetRenderForm(HINSTANCE hInstance);

	//!清理渲染窗口实例
	static void ReleaseRenderForm(void);

public:

	//!显示渲染窗口
	void Show(int show_cmd);

	//!关闭渲染窗口
	void Close(void);

	//!渲染
	void Render(DWORD time);

private:

	//!构造函数
	RenderForm(HINSTANCE hInstance);

	//!初始化窗体资源
	void _InitFormResources(void);

	//!加载窗体资源
	void _LoadFormResources(void);

	//!清理窗体资源
	void _DeleFormResources(void);

	//!创建窗体类
	void _CreateWindowClass(void);

	//!创建窗体
	void _CreateWindow(void);

	//!渲染背景图
	void _RenderBackground(void);

	//!交换
	void _Present(void);

private:

	//!渲染窗口实例
	static RenderForm* m_instance;

	//!类名
	WNDCLASSEX m_wnd_class;

	//!程序实例
	HINSTANCE m_hInstance;

	//!窗体句柄
	HWND m_hwnd;

	//!前台DC、后台DC、bufferDC
	HDC m_hdc, m_back_hdc, m_buffer_hdc;

};