/********************************************************************
@file     Main.cpp
@date     2017-5-10
@author   Zoro_Tiger
@brief    ���� 1011: C���Գ�����ƽ̳̣������棩�κ�ϰ��6.1
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

//!շת���෨
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