/********************************************************************
@file     Main.cpp
@date     2017-05-10
@author   Zoro_Tiger
@brief    ���� 1014: C���Գ�����ƽ̳̣������棩�κ�ϰ��6.4
          http://www.dotcpp.com/oj/problem1014.html
********************************************************************/
#include <cstdio>

#define TEST
#undef  TEST

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		//!����������������ȷʵӦ��������������
		//!ע�͵��Ĵ���Ӧ������ȷ��
		long/* double*/ cur_num = 1;
		long/* double*/ sum = 0;
		for (int i = 1; i <= n; ++i)
		{
			sum += (cur_num *= i);
		}
		//printf("%.0lf\n", sum);
		printf("%ld\n", sum);
	}

	return 0;
}