/********************************************************************
@file     Main.cpp
@date     2017-05-28 21:48:29
@author   Zoro_Tiger
@brief    问题 1039: C语言程序设计教程（第三版）课后习题9.4
          http://www.dotcpp.com/oj/problem1039.html
********************************************************************/
#include <cstdio>

#define TEST
#undef  TEST
#define LEAP_YEAR(y) (((y % 4) && (y % 100 != 0)) || (y % 400 == 0))

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	//!输入
	int year = 0;
	scanf("%d", &year);

	//!判断是否为闰年
	if (LEAP_YEAR(year))
	{
		printf("L\n");
	}
	else
	{
		printf("N\n");
	}

	return 0;
}