/********************************************************************
@file     ResourcesManager.h
@date     2017-6-28
@author   Zoro_Tiger
@brief    ��Դ������
********************************************************************/
//!ͷ�ļ�
#include "DataDefine.h"

//!�궨��
#define BITMAP_NUM 4 //!λͼ����

//!��Դ������
class ResourcesManager
{
	
public:

	//!���캯��
	ResourcesManager(void);

	//!��������
	virtual ~ResourcesManager(void);

	//!��ȡ��Դ������
	static ResourcesManager* GetResourcesManager(void);

	//!������Դ������
	static void ReleaseResourcesManager(void);

private:

	//!��ʼ����Դ
	void _InitResources(void);

	//!������Դ
	void _LoadResources(void);

	//!������Դ
	void _DeleResources(void);

private:

	//!��Դ����
	static ResourcesManager* m_instance;

	//!����ͼ
	HBITMAP m_background;

	//!λͼ
	HBITMAP m_girl[BITMAP_NUM];
};