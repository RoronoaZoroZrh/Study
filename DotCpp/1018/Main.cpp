/********************************************************************
@file     Main.cpp
@date     2017-05-12
@author   Zoro_Tiger
@brief    ���� 1018: C���Գ�����ƽ̳̣������棩�κ�ϰ��6.8
          http://www.dotcpp.com/oj/problem1018.html
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

	int number_n = 0;
	while (scanf("%d", &number_n) != EOF)
	{
		double a = 1, b = 2, sum = 0;
		for (int i = 0; i < number_n; ++i)
		{
			sum += b / a;
			a = a + b; //!aֵ�����ֵ������

			//!����
			a = a + b;
			b = a - b;
			a = a - b;
		}
		printf("%.2lf\n", sum);
	}

	return 0;
}