/********************************************************************
@file     Main.cpp
@date     2017-5-11
@author   Zoro_Tiger
@brief    ���� 1016: C���Գ�����ƽ̳̣������棩�κ�ϰ��6.6
          http://www.dotcpp.com/oj/problem1016.html
********************************************************************/
#include <cstdio>
#include <cmath>

#define TEST
#undef  TEST

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	//!ָ��Ϊ��λ����һ��ʼû����
	for (int i = 100; i <= 999; ++i)
	{
		int temp = i, sum = 0;
		for (int j = 0; j < 3; ++j)
		{
			int local_temp = temp % 10;
			sum += local_temp * local_temp * local_temp;
			temp /= 10;
		}
		
		if (sum == i)
		{
			printf("%d\n", i);
		}
	}

	return 0;
}