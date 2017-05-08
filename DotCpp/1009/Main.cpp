/********************************************************************
@file     Main.cpp
@date     2017-5-8
@author   Zoro_Tiger
@brief    ���� 1009: C���Գ�����ƽ̳̣������棩�κ�ϰ��5.7
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
		//!���λ��
		int number_bit = static_cast<int>(log10(static_cast<double>(number))) + 1;
		printf("%d\n", number_bit);

		int temp_number = 0;

		//!�������
		temp_number = number;
		for (int i = number_bit - 1; i >= 1; --i)
		{
			int remainder = static_cast<int>(pow(10.0f, i));
			int sub_temp_number = temp_number / remainder;
			printf("%d ", sub_temp_number % 10);
		}
		printf("%d\n", temp_number % 10);

		//!�������
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