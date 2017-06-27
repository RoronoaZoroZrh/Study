/********************************************************************
@file     Main.cpp
@date     2017-6-27 09:39:57
@author   Zoro_Tiger
@brief    问题 1057: C二级辅导-分段函数
          http://www.dotcpp.com/oj/problem1057.html
********************************************************************/
//!头文件
#include <cstdio>
#include <cmath>

//!程序入口
int main(int argc, const char* argv[])
{
	//!变量定义
	float number = 0;

	//!读取输入
	scanf("%f", &number);

	//!输出结果
	if (number < 1)
	{
		printf("%.2f\n", number);
	}
	else if (number >= 1 && number < 10)
	{
		printf("%.2f\n", 2 * number - 1);
	}
	else
	{
		printf("%.2f\n", 3 * number - 11);
	}

	//!返回系统
	return 0;
}