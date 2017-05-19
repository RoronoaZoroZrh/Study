/********************************************************************
@file     Main.cpp
@date     2017-5-19 09:12:51
@author   Zoro_Tiger
@brief    问题 1022: C语言程序设计教程（第三版）课后习题7.1
          http://www.dotcpp.com/oj/problem1022.html
********************************************************************/
#include <cstdio>
#include <cmath>
#include <cstring>

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
		bool* pFlagArray = new bool[number_n + 1];
		memset(pFlagArray, true, number_n + 1);

		for (int i = 2; i <= number_n; ++i)
		{
			if (pFlagArray[i]) //!查看是否为素数
			{
				for (int j = 2; j * j <= i; ++j)
				{
					if (i % j == 0)
					{
						pFlagArray[i] = false;
						break;
					}
				}
			}

			if (pFlagArray[i]) //!素数的倍数都不是素数
			{
				for (int j = i + i; j <= number_n; j += i)
				{
					pFlagArray[j] = false;
				}
			}
		}

		for (int i = 2; i <= number_n; ++i) //!打印所有素数
		{
			if (pFlagArray[i])
			{
				printf("%d\n", i);
			}
		}

		delete[] pFlagArray;
	}

	return 0;
}