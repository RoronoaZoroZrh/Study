/********************************************************************
@file     Main.cpp
@date     2017年3月25日13:59:59
@author   Zoro_Tiger
@brief    Book Essential C++ 1.1 Code
********************************************************************/
//!头文件
#include <iostream>
#include <string>

//!程序入口
int main(int argc, const char* argv[])
{
	//!输出
	std::cout << "你叫什么名字：";

	//!输入
	std::string sName = "";
	std::cin >> sName;

	//!输出
	std::cout << "你好" << sName << "..." << std::endl;
	system("pause");

	return 0;
}