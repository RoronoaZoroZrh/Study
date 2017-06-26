/********************************************************************
@file     Main.cpp
@date     2017-6-26 13:20:08
@author   Zoro_Tiger
@brief    问题 1055: C二级辅导-进制转换
          http://www.dotcpp.com/oj/problem1055.html
********************************************************************/
//!头文件
#include <cstdio>
#include <cmath>

//!函数声明
void Octal(int number);

//!程序入口
int main(int argc, const char* argv[])
{
	//!定义变量
	int number = 0;
	
	//!读取输入
	scanf("%d", &number);

	//!处理输入
	Octal(number);

	return 0;
}

//!将指定数字转换成八进制
void Octal(int number)
{
	if (number != 0)
	{
		Octal(number / 8);
		printf("%d", number % 8);
	}
}