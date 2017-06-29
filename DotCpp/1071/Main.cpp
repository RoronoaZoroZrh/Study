/********************************************************************
@file     Main.cpp
@date     2017-6-29 10:34:00
@author   Zoro_Tiger
@brief    问题 1071: 2006年春浙江省计算机等级考试二级C 编程题(2)
          http://www.dotcpp.com/oj/problem1071.html
********************************************************************/
//!头文件
#include <cstdio>
#include <cmath>

//!程序入口
int main(int argc, const char* argv[])
{
	//!变量声明
	int number_n = 0;

	//!读取输入
	scanf("%d", &number_n);

	//!计算结果
	double sum = 0, temp = 1;
	for (int i = 1; i <= number_n; ++i)
	{
		temp *= static_cast<double>(i);
		sum += 1 / temp;
	}

	//!显示结果
	printf("sum=%.5lf\n", sum);

	//!返回系统
	return 0;
}