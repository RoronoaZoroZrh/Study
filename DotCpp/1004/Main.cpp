/********************************************************************
@file     Main.cpp
@date     2017-4-27
@author   Zoro_Tiger
@brief    问题 1004: 母牛的故事
          http://www.dotcpp.com/oj/problem1004.html
********************************************************************/
//!头文件
#include <cstdio>

//!宏定义
#define TEST
#undef  TEST
#define YEAR 55

//!全局变量
int Cow[YEAR];

//!程序入口
int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	//!初始化
	for (int i = 0; i < YEAR; ++i)
	{
		if (i < 4) Cow[i] = i;
		else Cow[i] = Cow[i - 1] + Cow[i - 3];
	}

	int year = 0;
	while (scanf("%d", &year) && year)
	{
		printf("%d\n", Cow[year]);
	}

	return 0;
}