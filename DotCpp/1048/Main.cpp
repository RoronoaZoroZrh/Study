/********************************************************************
@file     Main.cpp
@date     2017-6-12 09:39:30
@author   Zoro_Tiger
@brief    问题 1048: C语言程序设计教程（第三版）课后习题10.7
          http://www.dotcpp.com/oj/problem1048.html
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

	int number_n = 0;
	scanf("%d", &number_n);

	std::string input = "";
	std::cin >> input;

	int number_m = 0;
	scanf("%d", &number_m);

	std::string output = input.substr(number_m - 1);
	std::cout << output;

	return 0;
}