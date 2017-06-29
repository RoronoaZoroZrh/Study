/********************************************************************
@file     Main.cpp
@date     2017-6-29 09:57:16
@author   Zoro_Tiger
@brief    问题 1068: 2005年春浙江省计算机等级考试二级C 编程题(2)
          http://www.dotcpp.com/oj/problem1068.html
********************************************************************/
//!头文件
#include <cstdio>
#include <cmath>

//!函数声明
int CToF(int c);

//!程序入口
int main(int argc, const char* argv[])
{
	//!输出结果
	for (int i = -100; i <=150; i += 5)
	{
		printf("c=%d->f=%d\n", i, CToF(i));
	}

	//!返回系统
	return 0;
}

//!转换温度
int CToF(int c)
{
	return 32 + c / 5 * 9;
}