/********************************************************************
@file     Main.cpp
@date     2017-4-26
@author   Zoro_Tiger
@brief    问题 1000: 简单的a+b
          http://www.dotcpp.com/oj/problem1000.html
********************************************************************/
//!头文件
#include <cstdio>

//!宏定义
#define TEST
#undef  TEST

//!程序入口
int main(int argc, const char* argv[])
{

#ifdef TEST //!从文件读取输入
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	//!计算两个数之和
	int number_a = 0, number_b = 0;
	while (scanf("%d%d", &number_a, &number_b) != EOF)
	{
		printf("%d\n", number_a + number_b);
	}

	return 0;
}