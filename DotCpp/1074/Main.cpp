/********************************************************************
@file     Main.cpp
@date     2017-6-30 09:44:39
@author   Zoro_Tiger
@brief    问题 1074: 数字整除
          http://www.dotcpp.com/oj/problem1074.html
********************************************************************/
//!头文件
#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>

//!程序入口
int main(int argc, const char* argv[])
{
	//!变量声明
	std::string input = "";

	//!读取输入并处理
	while (getline(std::cin, input) && input != "0")
	{
		int temp = 0;
		for (int i = 0; i < input.size(); ++i) //!很暴力的求是否能被某数整除
		{
			temp = (temp * 10 + (input.at(i) - '0')) % 17;
		}
		printf("%d\n", (temp == 0 ? 1 : 0));
	}
	
	//!返回系统
	return 0;
}