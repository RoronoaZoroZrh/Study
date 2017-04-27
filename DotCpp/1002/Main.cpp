/********************************************************************
@file     Main.cpp
@date     2017-4-27
@author   Zoro_Tiger
@brief    问题 1002: C语言程序设计教程（第三版）课后习题1.6
          http://www.dotcpp.com/oj/problem1002.html
********************************************************************/
//!头文件
#include <cstdio>
#include <algorithm>

//!宏定义
#define TEST
#undef  TEST

//!程序入口
int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int number_a = 0, number_b = 0, number_c = 0;
	while (scanf("%d%d%d", &number_a, &number_b, &number_c) != EOF)
	{
		printf("%d\n", std::max(std::max(number_a, number_b), number_c));
	}

	return 0;
}