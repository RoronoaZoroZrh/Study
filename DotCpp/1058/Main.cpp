/********************************************************************
@file     Main.cpp
@date     2017-6-27 09:50:36
@author   Zoro_Tiger
@brief    ���� 1058: C��������-��ż����
          http://www.dotcpp.com/oj/problem1058.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <cmath>

//!�������
int main(int argc, const char* argv[])
{
	//!��������
	int int_num = 0;
	scanf("%d", &int_num);

	//!��ȡ���벢����ż��֮��
	int sum = 0, temp = 0;
	while (int_num --)
	{
		scanf("%d", &temp);
		sum += (temp % 2 == 0 ? temp : 0);
	}

	//!������
	printf("%d\n", sum);
	
	//!����ϵͳ
	return 0;
}