/********************************************************************
@file     Main.cpp
@date     2017-6-26 13:40:42
@author   Zoro_Tiger
@brief    ���� 1056: C��������-�¶�ת��
          http://www.dotcpp.com/oj/problem1056.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <cmath>

//!�������
int main(int argc, const char* argv[])
{
	//!�¶�
	double temperature = 0;

	//!��ȡ�¶�
	scanf("%lf", &temperature);

	//!���ת������¶�
	printf("%.2lf\n", static_cast<double>(5 * (temperature - 32) / 9.0));

	//!����ϵͳ
	return 0;
}