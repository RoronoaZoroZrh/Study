/********************************************************************
@file     Main.cpp
@date     2017-6-29 11:27:27
@author   Zoro_Tiger
@brief    ���� 1072: ��ˮƿ
          http://www.dotcpp.com/oj/problem1072.html
@detail   ÿ������ƿ���Զһ�һƿ��ˮ���Ҳ�������ƿ
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <cmath>

//!�������
int main(int argc, const char* argv[])
{
	//!��������
	int empty_bottle = 0;

	//!��ȡ����
	while (scanf("%d", &empty_bottle) != EOF && empty_bottle > 0)
	{
		//!��ʾ���
		printf("%d\n", empty_bottle / 2);
	}

	//!����ϵͳ
	return 0;
}