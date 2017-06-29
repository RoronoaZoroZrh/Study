/********************************************************************
@file     Main.cpp
@date     2017-6-29 10:20:21
@author   Zoro_Tiger
@brief    ���� 1070: 2006�괺�㽭ʡ������ȼ����Զ���C �����(1)
          http://www.dotcpp.com/oj/problem1070.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <cmath>

//!�������
int main(int argc, const char* argv[])
{
	//!��������
	int grade_a = 0, grade_b = 0, grade_c = 0, temp = 0;

	//!��ȡ���벢����
	while (scanf("%d", &temp) != EOF && temp > 0)
	{
		if (temp >= 85)
		{
			++grade_a;
		}
		else if (temp >= 60)
		{
			++grade_b;
		}
		else
		{
			++grade_c;
		}
	}

	//!��ʾ���
	printf(">=85:%d\n", grade_a);
	printf("60-84:%d\n", grade_b);
	printf("<60:%d\n", grade_c);

	//!����ϵͳ
	return 0;
}