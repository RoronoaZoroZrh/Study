/********************************************************************
@file     Main.cpp
@date     2017-05-10
@author   Zoro_Tiger
@brief    问题 1014: C语言程序设计教程（第三版）课后习题6.4
          http://www.dotcpp.com/oj/problem1014.html
********************************************************************/
#include <cstdio>

#define TEST
#undef  TEST

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		//!看了讨论区，这题确实应该是数据有问题
		//!注释掉的代码应该是正确的
		long/* double*/ cur_num = 1;
		long/* double*/ sum = 0;
		for (int i = 1; i <= n; ++i)
		{
			sum += (cur_num *= i);
		}
		//printf("%.0lf\n", sum);
		printf("%ld\n", sum);
	}

	return 0;
}