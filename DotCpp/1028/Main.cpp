/********************************************************************
@file     Main.cpp
@date     2017-5-24 09:52:47
@author   Zoro_Tiger
@brief    问题 1028: C语言程序设计教程（第三版）课后习题8.2
          http://www.dotcpp.com/oj/problem1028.html
********************************************************************/
#include <cstdio>
#include <cmath>

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
		int temp = number_b * number_b - 4 * number_a * number_c;
		double part_a = (0 - number_b) / static_cast<double>(2 * number_a);
		double part_b = sqrt(fabs(static_cast<double>(temp))) / static_cast<double>(2 * number_a);
		if (temp > 0)
		{
			printf("x1=%.3lf x2=%.3f\n", part_a + part_b, part_a - part_b);
		}
		else if (temp < 0)
		{
			printf("x1=%.3lf+%.3lfi x2=%.3f-%.3lfi\n", part_a, part_b, part_a, part_b);
		}
		else
		{
			printf("x1=%.3lf x2=%.3f\n", part_a, part_a);
		}
	}

	return 0;
}