/********************************************************************
@file     Main.cpp
@date     2017-05-10
@author   Zoro_Tiger
@brief    ���� 1013: C���Գ�����ƽ̳̣������棩�κ�ϰ��6.3
          http://www.dotcpp.com/oj/problem1013.html
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

	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			sum += 2 * static_cast<int>(pow(10.0, i)) * (n - i);
		}
		printf("%d\n", sum);
	}

	return 0;
}