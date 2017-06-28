/********************************************************************
@file     Main.cpp
@date     2017-6-28 10:11:17
@author   Zoro_Tiger
@brief    ���� 1062: C��������-��Լ����
          http://www.dotcpp.com/oj/problem1062.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <cmath>

//!��������
int CalcGCD(int m, int n);

//!�������
int main(int argc, const char* argv[])
{
	//!����
	int number_m, number_n;

	//!��ȡ����
	scanf("%d%d", &number_m, &number_n);

	//!�������Լ��
	int divisor = (number_m > number_n ? CalcGCD(number_m, number_n) : CalcGCD(number_n, number_m));

	//!������󹫱���
	int multiple = number_m / divisor * number_n;

	//!������
	printf("%d\n%d\n", divisor, multiple);
	
	//!����ϵͳ
	return 0;
}

//!�������Լ��
int CalcGCD(int m, int n)
{
	if (m % n == 0)
	{
		return n;
	}
	else
	{
		return CalcGCD(n, m % n);
	}
}