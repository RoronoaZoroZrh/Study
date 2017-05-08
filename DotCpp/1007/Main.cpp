/********************************************************************
@file     Main.cpp
@date     2017-5-8
@author   Zoro_Tiger
@brief    问题 1007: C语言程序设计教程（第三版）课后习题5.5
          http://www.dotcpp.com/oj/problem1007.html
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

	int number_x = 0;
	while (scanf("%d", &number_x) != EOF)
	{
		int number_y = number_x;
		if (number_x >= 1 && number_x < 10)
		{
			number_y = 2 * number_x - 1;
		}
		else if (number_x >= 10)
		{
			number_y = 3 * number_x - 11;
		}
		printf("%d\n", number_y);
	}

	return 0;
}