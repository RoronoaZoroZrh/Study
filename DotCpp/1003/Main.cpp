/********************************************************************
@file     Main.cpp
@date     2017-4-27
@author   Zoro_Tiger
@brief    问题 1003: C语言程序设计教程（第三版）课后习题3.7
          http://www.dotcpp.com/oj/problem1003.html
********************************************************************/
//!头文件
#include <cstdio>

//!宏定义
#define TEST
#undef  TEST
#define ARRAY_SIZE 256
#define ADD_NUM    4

//!程序入口
int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	char input[ARRAY_SIZE] = { 0 };
	while (scanf("%s", input) != EOF)
	{
		for (int i = 0; input[i] != '\0'; ++i)
		{
			input[i] += ADD_NUM;
		}
		printf("%s\n", input);
	}

	return 0;
}