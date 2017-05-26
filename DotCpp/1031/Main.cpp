/********************************************************************
@file     Main.cpp
@date     2017-5-26 09:36:10
@author   Zoro_Tiger
@brief    问题 1031: C语言程序设计教程（第三版）课后习题8.5
          http://www.dotcpp.com/oj/problem1031.html
********************************************************************/
#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>

#define TEST
#undef  TEST

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	std::string input = "";
	while (std::cin >> input) //!输入
	{
		//!转置、不让用
		//std::reverse(input.begin(), input.end());

		//!输出
		for (int i = input.size() - 1; i >= 0; --i)
		{
			printf("%c", input[i]);
		}
		printf("\n");
	}

	return 0;
}