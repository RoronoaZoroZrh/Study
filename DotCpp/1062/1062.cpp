/********************************************************************
@file     Main.cpp
@date     2017-6-28 10:11:17
@author   Zoro_Tiger
@brief    问题 1062: C二级辅导-公约公倍
          http://www.dotcpp.com/oj/problem1062.html
********************************************************************/
//!头文件
#include <cstdio>
#include <cmath>

//!函数声明
int CalcGCD(int m, int n);

//!程序入口
int main(int argc, const char* argv[])
{
	//!声明
	int number_m, number_n;

	//!读取输入
	scanf("%d%d", &number_m, &number_n);

	//!计算最大公约数
	int divisor = (number_m > number_n ? CalcGCD(number_m, number_n) : CalcGCD(number_n, number_m));

	//!计算最大公倍数
	int multiple = number_m / divisor * number_n;

	//!输出结果
	printf("%d\n%d\n", divisor, multiple);
	
	//!返回系统
	return 0;
}

//!计算最大公约数
int CalcGCD(int m, int n)
{
	if (m % n == 0)
	{
		return n;
	}
	else
	{
		return CalcGCD(n, m % n);
	}
}