/********************************************************************
@file     Main.cpp
@date     2017-05-10
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

	int number_a = 0, number_b = 0, number_c = 0;
	while (scanf("%d%d%d", &number_a, &number_b, &number_c) != EOF)
	{
		double sum = number_a * (number_a + 1) / 2;
		sum += number_b * (number_b + 1) * (2 * number_b + 1) / 6.0f;
		for (int i = 1; i <= number_c; ++i) sum += 1.0f / i;
		printf("%.2lf\n", sum);
	}

	return 0;
}