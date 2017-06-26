/********************************************************************
@file     Main.cpp
@date     2017-6-26 13:40:42
@author   Zoro_Tiger
@brief    问题 1056: C二级辅导-温度转换
          http://www.dotcpp.com/oj/problem1056.html
********************************************************************/
//!头文件
#include <cstdio>
#include <cmath>

//!程序入口
int main(int argc, const char* argv[])
{
	//!温度
	double temperature = 0;

	//!读取温度
	scanf("%lf", &temperature);

	//!输出转换后的温度
	printf("%.2lf\n", static_cast<double>(5 * (temperature - 32) / 9.0));

	//!返回系统
	return 0;
}