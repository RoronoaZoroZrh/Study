/********************************************************************
@file     Main.cpp
@date     2017-6-28 09:53:19
@author   Zoro_Tiger
@brief    ���� 1060: C��������-ͬ�����
          http://www.dotcpp.com/oj/problem1060.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <cmath>

//!�������
int main(int argc, const char* argv[])
{
	//!���㲢������
	for (int i = 10; i <= 1000; ++i)
	{
		if (!(i % 2) && !(i % 3) && !(i % 7))
		{
			printf("%d\n", i);
		}
	}
	
	//!����ϵͳ
	return 0;
}