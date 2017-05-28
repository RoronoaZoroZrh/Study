/********************************************************************
@file     Main.cpp
@date     2017-05-28 22:10:10
@author   Zoro_Tiger
@brief    问题 1042: C语言程序设计教程（第三版）课后习题9.10
          http://www.dotcpp.com/oj/problem1042.html
********************************************************************/
#include <cstdio>
#include <locale>

#define TEST
#undef  TEST

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	char c;
	while (scanf("%c", &c) != EOF)
	{
		if (isalpha(c))
		{
			printf("%c", c + 1);
		}
		else
		{
			printf("%c", c);
		}
	}

	return 0;
}