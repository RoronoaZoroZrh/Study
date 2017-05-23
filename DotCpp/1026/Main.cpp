/********************************************************************
@file     Main.cpp
@date     2017-5-23 09:41:44
@author   Zoro_Tiger
@brief    问题 1026: C语言程序设计教程（第三版）课后习题7.5
          http://www.dotcpp.com/oj/problem1026.html
********************************************************************/
#include <cstdio>
#include <cmath>

#define TEST
#undef  TEST
#define ARRAY_NUM 10

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	//!输入
	int my_array[ARRAY_NUM];
	for (int i = 0; i < ARRAY_NUM; ++i)
	{
		scanf("%d", my_array + i);
	}

	//!输出
	for (int i = ARRAY_NUM - 1; i >= 0; --i)
	{
		if (0 == i)
		{
			printf("%d\n", my_array[i]);
		}
		else
		{
			printf("%d ", my_array[i]);
		}
	}

	return 0;
}