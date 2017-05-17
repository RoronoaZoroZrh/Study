/********************************************************************
@file     Main.cpp
@date     2017-5-17 17:02:42
@author   Zoro_Tiger
@brief    问题 1020: C语言程序设计教程（第三版）课后习题6.10
          http://www.dotcpp.com/oj/problem1020.html
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

	int day = 0;
	while (scanf("%d", &day) != EOF)
	{
		if (day == 1)
		{
			printf("%d\n", day);
		}
		else
		{
			//!题目貌似错了吧，应该求的是第一天共有多少个桃子
			printf("%d\n", 3 * static_cast<int>(pow(2.0, day - 1)) - 2);
		}
	}

	return 0;
}