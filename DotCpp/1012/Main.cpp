/********************************************************************
@file     Main.cpp
@date     2017-5-10
@author   Zoro_Tiger
@brief    问题 1012: C语言程序设计教程（第三版）课后习题6.2
          http://www.dotcpp.com/oj/problem1012.html
********************************************************************/
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstring>

#define TEST
#undef  TEST

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	std::string input = "";
	while (getline(std::cin, input))
	{
		int alpha_num = std::count_if(input.begin(), input.end(), isalpha);
		int digit_num = std::count_if(input.begin(), input.end(), isdigit);
		int space_num = std::count_if(input.begin(), input.end(), isspace);
		printf("%d ",  alpha_num);
		printf("%d ",  digit_num);
		printf("%d ",  space_num);
		printf("%d\n", input.size() - alpha_num - digit_num - space_num);
	}

	return 0;
}