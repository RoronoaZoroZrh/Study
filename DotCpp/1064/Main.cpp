/********************************************************************
@file     Main.cpp
@date     2017-6-28 10:35:58
@author   Zoro_Tiger
@brief    ���� 1064: C��������-�׳�����
          http://www.dotcpp.com/oj/problem1064.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <cmath>

//!�������
int main(int argc, const char* argv[])
{
	//!�����������ú��м�ֵ
	double sum = 0, temp = 1;
	for (int i = 1; i <= 30; ++i)
	{
		temp *= static_cast<double>(i);
		sum += temp;
	}

	//!��ʾ���
	printf("%.2e\n", sum);

	//!����ϵͳ
	return 0;
}