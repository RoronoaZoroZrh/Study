/********************************************************************
@file     Main.cpp
@date     2017-5-11
@author   Zoro_Tiger
@brief    问题 1009: C语言程序设计教程（第三版）课后习题5.7
          http://www.dotcpp.com/oj/problem1009.html
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

	int number_n = 0;
	while (scanf("%d", &number_n) != EOF)
	{
		for (int i = 2; i <= number_n; ++i)
		{
			//!取最大遍历值
			int max_gcd = floor(sqrt(static_cast<long double>(i))), sum = 0;
			for (int j = 1; j <= max_gcd; ++j)
			{
				if (i % j == 0)
				{
					//!取两个乘数相加
					sum += j;
					int temp = i / j;
					if (j != temp && temp != i)
					{
						sum += temp;
					}

					//!检测和是否超限
					if (sum > i)
					{
						break;
					}
				}
			}

			//!打印所有因子
			if (sum == i)
			{
				printf("%d its factors are ", i);
				for (int j = 1; j < i; ++j)
				{
					if (i % j == 0)
					{
						printf("%d ", j);
					}
				}
				printf("\n");
			}
		}
	}

	return 0;
}