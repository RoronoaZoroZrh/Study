/********************************************************************
@file     ResourcesManager.h
@date     2017-6-28
@author   Zoro_Tiger
@brief    资源管理器
********************************************************************/
//!头文件
#include "DataDefine.h"

//!宏定义
#define BITMAP_NUM 4 //!位图数量

//!资源管理器
class ResourcesManager
{
	
public:

	//!析构函数
	virtual ~ResourcesManager(void);

	//!获取资源管理器
	static ResourcesManager* GetResourcesManager(void);

	//!清理资源管理器
	static void ReleaseResourcesManager(void);

private:

	//!构造函数
	ResourcesManager(void);

	//!初始化资源
	void _InitResources(void);

	//!加载资源
	void _LoadResources(void);

	//!清理资源
	void _DeleResources(void);

public:

	//!获取背景图
	HBITMAP& GetBackground(void);

private:

	//!资源管理实例
	static ResourcesManager* m_instance;

	//!背景图
	HBITMAP m_background;

	//!位图
	HBITMAP m_girl[BITMAP_NUM];
};