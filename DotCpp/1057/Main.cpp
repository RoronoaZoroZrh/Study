/********************************************************************
@file     Main.cpp
@date     2017-6-27 09:39:57
@author   Zoro_Tiger
@brief    ���� 1057: C��������-�ֶκ���
          http://www.dotcpp.com/oj/problem1057.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <cmath>

//!�������
int main(int argc, const char* argv[])
{
	//!��������
	float number = 0;

	//!��ȡ����
	scanf("%f", &number);

	//!������
	if (number < 1)
	{
		printf("%.2f\n", number);
	}
	else if (number >= 1 && number < 10)
	{
		printf("%.2f\n", 2 * number - 1);
	}
	else
	{
		printf("%.2f\n", 3 * number - 11);
	}

	//!����ϵͳ
	return 0;
}