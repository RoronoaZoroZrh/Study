/********************************************************************
@file     Main.cpp
@date     2017-6-29 09:47:09
@author   Zoro_Tiger
@brief    ���� 1067: 2005�괺�㽭ʡ������ȼ����Զ���C �����(1)
          http://www.dotcpp.com/oj/problem1067.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <cmath>

//!�������
int main(int argc, const char* argv[])
{
	//!��������
	int number_x = 0;

	//!��ȡ����
	scanf("%d", &number_x);

	//!������
	double result = 0;
	if (number_x < 0)
	{
		result = fabs(static_cast<double>(number_x));
	}
	else if (number_x < 2)
	{
		result = sqrt(static_cast<double>(number_x + 1));
	}
	else if (number_x < 4)
	{
		result = pow(static_cast<double>(number_x + 2), 5);
	}
	else
	{
		result = static_cast<double>(2 * number_x + 5);
	}

	//!��ʾ���
	printf("%.2lf\n", result);

	//!����ϵͳ
	return 0;
}