/********************************************************************
@file     Main.cpp
@date     2017-5-27 09:24:00
@author   Zoro_Tiger
@brief    问题 1035: C语言程序设计教程（第三版）课后习题8.9
          http://www.dotcpp.com/oj/problem1035.html
********************************************************************/
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
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
	getline(std::cin, input);

	//!统计
	int digit_num = std::count_if(input.begin(), input.end(), isdigit);
	int space_num = std::count_if(input.begin(), input.end(), isspace);
	int alpha_num = std::count_if(input.begin(), input.end(), isalpha);

	//!输出
	printf("%d %d %d %d \n", alpha_num, digit_num, space_num, (input.size() - alpha_num - digit_num - space_num));

	return 0;
}