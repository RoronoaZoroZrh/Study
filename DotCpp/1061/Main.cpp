/********************************************************************
@file     Main.cpp
@date     2017-6-28 09:58:32
@author   Zoro_Tiger
@brief    ���� 1061: C��������-�Ƹ�����
          http://www.dotcpp.com/oj/problem1061.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <cmath>

//!�������
int main(int argc, const char* argv[])
{
	//!����
	double sum = 0, temp = 0, count = 0;
	for (int i = 0; i < 20; ++i)
	{
		scanf("%lf", &temp);
		if (temp <= 0)
		{
			++count;
		}
		else
		{
			sum += temp;
		}
	}

	//!������
	printf("%d\n", static_cast<int>(count));
	printf("%.2lf\n", sum / (20.0 - count));

	//!����ϵͳ
	return 0;
}