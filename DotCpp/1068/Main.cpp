/********************************************************************
@file     Main.cpp
@date     2017-6-29 09:57:16
@author   Zoro_Tiger
@brief    ���� 1068: 2005�괺�㽭ʡ������ȼ����Զ���C �����(2)
          http://www.dotcpp.com/oj/problem1068.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <cmath>

//!��������
int CToF(int c);

//!�������
int main(int argc, const char* argv[])
{
	//!������
	for (int i = -100; i <=150; i += 5)
	{
		printf("c=%d->f=%d\n", i, CToF(i));
	}

	//!����ϵͳ
	return 0;
}

//!ת���¶�
int CToF(int c)
{
	return 32 + c / 5 * 9;
}