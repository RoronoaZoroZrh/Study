/********************************************************************
@file     Main.cpp
@date     2017-6-29 09:47:09
@author   Zoro_Tiger
@brief    问题 1067: 2005年春浙江省计算机等级考试二级C 编程题(1)
          http://www.dotcpp.com/oj/problem1067.html
********************************************************************/
//!头文件
#include <cstdio>
#include <cmath>

//!程序入口
int main(int argc, const char* argv[])
{
	//!变量声明
	int number_x = 0;

	//!读取输入
	scanf("%d", &number_x);

	//!计算结果
	double result = 0;
	if (number_x < 0)
	{
		result = fabs(static_cast<double>(number_x));
	}
	else if (number_x < 2)
	{
		result = sqrt(static_cast<double>(number_x + 1));
	}
	else if (number_x < 4)
	{
		result = pow(static_cast<double>(number_x + 2), 5);
	}
	else
	{
		result = static_cast<double>(2 * number_x + 5);
	}

	//!显示结果
	printf("%.2lf\n", result);

	//!返回系统
	return 0;
}