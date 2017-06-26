/********************************************************************
@file     Main.cpp
@date     2017-6-26 10:20:11
@author   Zoro_Tiger
@brief    ���� 1054: 2003�����㽭ʡ������ȼ����Զ���C �����(2)
          http://www.dotcpp.com/oj/problem1054.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <cmath>

//!��������
bool IsPrime(int number);

//!�������
int main(int argc, const char* argv[])
{
	//!��������
	int number_m = 0, number_n = 0;

	//!��ȡ����
	scanf("%d%d", &number_m, &number_n);

	//!ͳ������number_m��number_n֮��������
	int sum = 0;
	for (int i = number_m; i <= number_n; ++i)
	{
		if (IsPrime(i))
		{
			sum += i;
		}
	}

	//!������
	printf("%d\n", sum);

	//!����ϵͳ
	return 0;
}

//!�ж������Ƿ�Ϊ����
bool IsPrime(int number)
{
	bool result = (number != 1);
	for (int i = 2; i * i <= number; ++i)
	{
		if (number % i == 0)
		{
			result = false;
			break;
		}
	}
	return result;
}