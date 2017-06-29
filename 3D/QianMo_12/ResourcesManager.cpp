/********************************************************************
@file     ResourcesManager.cpp
@date     2017-6-28
@author   Zoro_Tiger
@brief    资源管理器
********************************************************************/
//!头文件
#include "ResourcesManager.h"

//!初始化
ResourcesManager* ResourcesManager::m_instance = NULL;

ResourcesManager::ResourcesManager(void)
{
	_InitResources();
	_LoadResources();
}

ResourcesManager::~ResourcesManager(void)
{
	_DeleResources();
}

ResourcesManager* ResourcesManager::GetResourcesManager(void)
{
	if (NULL == m_instance)
	{
		m_instance = new ResourcesManager();
	}
	return m_instance;
}

void ResourcesManager::ReleaseResourcesManager(void)
{
	if (NULL != m_instance)
	{
		delete m_instance; m_instance = NULL;
	}
}

void ResourcesManager::_InitResources(void)
{
	this->m_background = NULL;
	for (int i = 0; i < BITMAP_NUM; ++i)
	{
		this->m_girl[i] = NULL;
	}
}

void ResourcesManager::_LoadResources(void)
{
	//!这些魔数看着好烦人
	this->m_background = (HBITMAP)LoadImage(NULL, _T("bg.bmp"), IMAGE_BITMAP, 640, 480, LR_LOADFROMFILE);
	this->m_girl[0] = (HBITMAP)LoadImage(NULL, _T("girl0.bmp"), IMAGE_BITMAP, 440, 148, LR_LOADFROMFILE);
	this->m_girl[1] = (HBITMAP)LoadImage(NULL, _T("girl1.bmp"), IMAGE_BITMAP, 424, 154, LR_LOADFROMFILE);
	this->m_girl[2] = (HBITMAP)LoadImage(NULL, _T("girl2.bmp"), IMAGE_BITMAP, 480, 148, LR_LOADFROMFILE);
	this->m_girl[3] = (HBITMAP)LoadImage(NULL, _T("girl3.bmp"), IMAGE_BITMAP, 480, 148, LR_LOADFROMFILE);
}

void ResourcesManager::_DeleResources(void)
{
	DeleteObject(this->m_background);
	for (int i = 0; i < BITMAP_NUM; ++i)
	{
		DeleteObject(this->m_girl[i]);
	}
}

HBITMAP& ResourcesManager::GetBackground(void)
{
	return this->m_background;
}