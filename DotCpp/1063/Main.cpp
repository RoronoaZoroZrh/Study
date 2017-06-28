/********************************************************************
@file     Main.cpp
@date     2017-6-28 10:22:37
@author   Zoro_Tiger
@brief    问题 1063: C二级辅导-统计字符
          http://www.dotcpp.com/oj/problem1063.html
********************************************************************/
//!头文件
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

//!程序入口
int main(int argc, const char* argv[])
{
	//!变量声明
	std::string input = "";

	//!读取输入
	getline(std::cin, input);

	//!统计各字符个数
	int alpha_count = std::count_if(input.begin(), input.end(), isalpha);
	int space_count = std::count_if(input.begin(), input.end(), isspace);
	int digit_count = std::count_if(input.begin(), input.end(), isdigit);

	//!输出结果
	printf("%d\n%d\n%d\n%d\n", alpha_count, space_count, digit_count, input.size() - alpha_count - space_count - digit_count);
	
	//!返回系统
	return 0;
}