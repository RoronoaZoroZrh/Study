/********************************************************************
@file     Main.cpp
@date     2017-5-25 09:32:58
@author   Zoro_Tiger
@brief    问题 1029: C语言程序设计教程（第三版）课后习题8.3
          http://www.dotcpp.com/oj/problem1029.html
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

	//!输入
	int integer = 0;
	scanf("%d", &integer);

	//!判断输入是否为素数
	bool is_prime = true;
	for (int i = 2; i * i <= integer; ++i)
	{
		if (integer % i == 0)
		{
			is_prime = false;
			break;
		}
	}

	//!输出
	if (is_prime)
	{
		printf("prime\n");
	}
	else
	{
		printf("not prime");
	}

	return 0;
}