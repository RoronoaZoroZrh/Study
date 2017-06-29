/********************************************************************
@file     Main.cpp
@date     2017-6-29 10:34:00
@author   Zoro_Tiger
@brief    ���� 1071: 2006�괺�㽭ʡ������ȼ����Զ���C �����(2)
          http://www.dotcpp.com/oj/problem1071.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <cmath>

//!�������
int main(int argc, const char* argv[])
{
	//!��������
	int number_n = 0;

	//!��ȡ����
	scanf("%d", &number_n);

	//!������
	double sum = 0, temp = 1;
	for (int i = 1; i <= number_n; ++i)
	{
		temp *= static_cast<double>(i);
		sum += 1 / temp;
	}

	//!��ʾ���
	printf("sum=%.5lf\n", sum);

	//!����ϵͳ
	return 0;
}