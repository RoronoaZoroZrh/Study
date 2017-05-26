/********************************************************************
@file     Main.cpp
@date     2017-5-26 09:45:32
@author   Zoro_Tiger
@brief    问题 1032: C语言程序设计教程（第三版）课后习题8.6
          http://www.dotcpp.com/oj/problem1032.html
********************************************************************/
#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>

#define TEST
#undef  TEST

std::string AddString(const std::string& left_str, const std::string& right_str)
{
	return left_str + right_str;
}

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	std::string left_str = "", right_str = "";
	while (std::cin >> left_str >> right_str)
	{
		printf("%s\n", AddString(left_str, right_str).c_str());
	}

	return 0;
}