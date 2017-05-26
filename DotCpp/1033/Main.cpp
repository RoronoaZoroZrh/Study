/********************************************************************
@file     Main.cpp
@date     2017-5-26 09:53:03
@author   Zoro_Tiger
@brief    问题 1033: C语言程序设计教程（第三版）课后习题8.7
          http://www.dotcpp.com/oj/problem1033.html
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

	//!输入
	std::string input = "";
	std::cin >> input;

	//!查找元音字符
	std::string temp = "aeiuo";
	for (size_t i = 0; i < input.size(); ++i)
	{
		if (temp.find(input[i]) != std::string::npos)
		{
			printf("%c", input[i]);
		}
	}
	printf("\n");

	return 0;
}