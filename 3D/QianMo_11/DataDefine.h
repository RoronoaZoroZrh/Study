/********************************************************************
@file     DataDefine.h
@date     2017-6-28
@author   Zoro_Tiger
@brief    基础动画显示（四） 排序贴图
********************************************************************/
//!头文件
#include <Windows.h>

//!宏定义
#define DRAGON_NUM   10                      //!恐龙数量

//!恐龙信息
struct Dragon
{
	int x;   //!位置X坐标
	int y;   //!位置Y坐标
	int dir; //!方向
};