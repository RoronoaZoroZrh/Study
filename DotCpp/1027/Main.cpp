/********************************************************************
@file     Main.cpp
@date     2017-5-23 09:48:48
@author   Zoro_Tiger
@brief    ���� 1027: C���Գ�����ƽ̳̣������棩�κ�ϰ��8.1
          http://www.dotcpp.com/oj/problem1027.html
********************************************************************/
#include <cstdio>
#include <cmath>
#include <algorithm>

#define TEST
#undef  TEST

//!�����Լ��
int GetGCD(int a, int b)
{
	if (a % b == 0)
	{
		return b;
	}
	else
	{
		return GetGCD(b, a % b);
	}
}

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int a = 0, b = 0;
	while (scanf("%d%d", &a, &b) != EOF)
	{
		int temp = GetGCD(std::max(a, b), std::min(a, b));
		printf("%d %d\n", temp, a * b /  temp);
	}

	return 0;
}