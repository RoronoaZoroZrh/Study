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

//!函数声明
int GetCowNum(int year);

//!程序入口
int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int year = 0;
	while (scanf("%d", &year) && year)
	{
		printf("%d\n", GetCowNum(year));
	}

	return 0;
}

//!获取母牛数量
int GetCowNum(int year)
{
	switch (year)
	{
	case 1:
		return 1;
	case 2:
		return 2;
	case 3:
		return 3;
	default:
		return GetCowNum(year - 1) + GetCowNum(year - 3);
	}
}