/********************************************************************
@file     Main.cpp
@date     2017-5-10
@author   Zoro_Tiger
@brief    问题 1011: C语言程序设计教程（第三版）课后习题6.1
          http://www.dotcpp.com/oj/problem1011.html
********************************************************************/
#include <cstdio>
#include <cmath>

#define TEST
#undef  TEST

int GetMaxCommonDivisor(int a, int b);

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int number_a = 0, number_b = 0;
	while (scanf("%d%d", &number_a, &number_b) != EOF)
	{
		int max_common_divisor = 0;
		if (number_a > number_b)
		{
			max_common_divisor = GetMaxCommonDivisor(number_a, number_b);
		}
		else
		{
			max_common_divisor = GetMaxCommonDivisor(number_b, number_a);
		}
		
		printf("%d %d\n", max_common_divisor, number_a * number_b / max_common_divisor);
	}

	return 0;
}

//!辗转求余法
int GetMaxCommonDivisor(int a, int b)
{
	if (a % b == 0)
	{
		return b;
	}
	else
	{
		return GetMaxCommonDivisor(b, a % b);
	}
}