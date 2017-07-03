/********************************************************************
@file     Main.cpp
@date     2017-7-3 10:24:28
@author   Zoro_Tiger
@brief    ���� 1076: �ڲ�������
          http://www.dotcpp.com/oj/problem1076.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <cmath>

//!�궨��
#define ARRAY_SIZE 15

//!�������
int main(int argc, const char* argv[])
{
	//!��������
	int number_t = 0; double param[ARRAY_SIZE] = { 0.0 };

	//!��ȡ���벢����
	while (scanf("%d", &number_t) != EOF && number_t != 0)
	{
		//!��ȡϵ��
		for (int i = 0; i <= number_t; ++i)
		{
			scanf("%lf", param + i);
		}

		//!���ַ����ҽ�
		double left = -1.0, middle = 0.0, right = 1E6, sum = 0, temp = 1;
		while (fabs(param[0] + sum) > 1E-7)
		{
			sum = 0; middle = (left + right) / 2.0; temp = 1;
			for (int i = 1; i <= number_t; ++i)
			{
				temp = temp / (1 + middle);
				sum += param[i] * temp;
			}

			if (param[0] + sum > 1E-7) left = middle;
			else right = middle;
		}

		//!��ʾ���
		printf("%.2lf\n", middle);
	}

	//!����ϵͳ
	return 0;
}