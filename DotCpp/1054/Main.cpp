/********************************************************************
@file     Main.cpp
@date     2017-6-26 10:20:11
@author   Zoro_Tiger
@brief    问题 1054: 2003年秋浙江省计算机等级考试二级C 编程题(2)
          http://www.dotcpp.com/oj/problem1054.html
********************************************************************/
//!头文件
#include <cstdio>
#include <cmath>

//!函数声明
bool IsPrime(int number);

//!程序入口
int main(int argc, const char* argv[])
{
	//!变量定义
	int number_m = 0, number_n = 0;

	//!读取输入
	scanf("%d%d", &number_m, &number_n);

	//!统计数字number_m和number_n之间素数和
	int sum = 0;
	for (int i = number_m; i <= number_n; ++i)
	{
		if (IsPrime(i))
		{
			sum += i;
		}
	}

	//!输出结果
	printf("%d\n", sum);

	//!返回系统
	return 0;
}

//!判断数字是否为素数
bool IsPrime(int number)
{
	bool result = (number != 1);
	for (int i = 2; i * i <= number; ++i)
	{
		if (number % i == 0)
		{
			result = false;
			break;
		}
	}
	return result;
}