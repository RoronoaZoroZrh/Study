/********************************************************************
@file     Main.cpp
@date     2017-5-27 09:16:00
@author   Zoro_Tiger
@brief    问题 1034: C语言程序设计教程（第三版）课后习题8.8
          http://www.dotcpp.com/oj/problem1034.html
********************************************************************/
#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>
#include <cstring>

#define TEST
#undef  TEST

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	//!输入
	std::string input = "";
	std::cin >> input;

	//!输出
	for (size_t i = 0; i < input.size(); ++i)
	{
		if (0 == i)
		{
			printf("%c", input[i]);
		}
		else
		{
			printf(" %c", input[i]);
		}
	}

	return 0;
}