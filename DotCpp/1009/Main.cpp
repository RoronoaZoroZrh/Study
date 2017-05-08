/********************************************************************
@file     Main.cpp
@date     2017-5-8
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

	int number;
	while (scanf("%d", &number) != EOF)
	{
		//!输出位数
		int number_bit = static_cast<int>(log10(static_cast<double>(number))) + 1;
		printf("%d\n", number_bit);

		int temp_number = 0;

		//!输出正序
		temp_number = number;
		for (int i = number_bit - 1; i >= 1; --i)
		{
			int remainder = static_cast<int>(pow(10.0f, i));
			int sub_temp_number = temp_number / remainder;
			printf("%d ", sub_temp_number % 10);
		}
		printf("%d\n", temp_number % 10);

		//!输出逆序
		temp_number = number;
		for (int i = 1; i <= number_bit; ++i)
		{
			printf("%d", temp_number % 10);
			temp_number /= 10;
		}
		printf("\n");
	}

	return 0;
}