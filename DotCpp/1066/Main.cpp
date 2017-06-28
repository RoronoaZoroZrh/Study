/********************************************************************
@file     Main.cpp
@date     2017-6-28 13:49:56
@author   Zoro_Tiger
@brief    ���� 1066: 2004�����㽭ʡ������ȼ����Զ���C �����(2)
          http://www.dotcpp.com/oj/problem1066.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <cmath>

//!�������
int main(int argc, const char* argv[])
{
	//!��������
	double x = 0; int n = 0;

	//!��ȡ����
	scanf("%lf%d", &x, &n);

	//!������
	double result = 0, temp_fact = 1, temp_power = 1;
	for (int i = 1; i <= n; ++i)
	{
		temp_power *= x;
		temp_fact *= static_cast<double>(i);
		if (i % 2 == 0)
		{
			result -= temp_power / temp_fact;
		}
		else
		{
			result += temp_power / temp_fact;
		}
	}

	//!��ʾ���
	printf("%.4lf\n", result);
	
	//!����ϵͳ
	return 0;
}