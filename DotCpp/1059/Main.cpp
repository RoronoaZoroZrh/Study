/********************************************************************
@file     Main.cpp
@date     2017-6-27 10:08:20
@author   Zoro_Tiger
@brief    ���� 1059: C��������-�Ȳ�����
          http://www.dotcpp.com/oj/problem1059.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <cmath>

//!�������
int main(int argc, const char* argv[])
{
	//!��������
	int a1 = 2, d = 3, n = 0;

	//!��ȡ����
	scanf("%d", &n);

	//!������
	int sum = a1 * n + (n * (n - 1) / 2) * d;

	//!��ʾ���
	printf("%d\n", sum);

	//!����ϵͳ
	return 0;
}