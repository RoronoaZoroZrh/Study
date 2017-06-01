/********************************************************************
@file     Main.cpp
@date     2017-06-01 12:17:46
@author   Zoro_Tiger
@brief    ���� 1047: C���Գ�����ƽ̳̣������棩�κ�ϰ��10.5
          http://www.dotcpp.com/oj/problem1047.html
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

	int number_n = 0;
	scanf("%d", &number_n);

	int result = 0;
	for (int i = 2; i <= number_n; ++i)
	{
		result = (result + 3) % i;
	}
	printf("%d\n", result + 1);

	return 0;
}