/********************************************************************
@file     Main.cpp
@date     2017-06-01 09:39:07
@author   Zoro_Tiger
@brief    问题 1044: C语言程序设计教程（第三版）课后习题10.2
          http://www.dotcpp.com/oj/problem1044.html
********************************************************************/
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

#define TEST
#undef  TEST
#define VEC_SIZE 3

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	std::vector<std::string> my_vec(VEC_SIZE);
	for (int i = 0; i < VEC_SIZE; ++i)
	{
		std::cin >> my_vec[i];
	}

	std::sort(my_vec.begin(), my_vec.end());

	for (int i = 0; i < VEC_SIZE; ++i)
	{
		printf("%s\n", my_vec[i].c_str());
	}

	return 0;
}