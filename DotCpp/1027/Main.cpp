/********************************************************************
@file     Main.cpp
@date     2017-5-23 09:48:48
@author   Zoro_Tiger
@brief    问题 1027: C语言程序设计教程（第三版）课后习题8.1
          http://www.dotcpp.com/oj/problem1027.html
********************************************************************/
#include <cstdio>
#include <cmath>
#include <algorithm>

#define TEST
#undef  TEST

//!求最大公约数
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