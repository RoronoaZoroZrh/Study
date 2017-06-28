/********************************************************************
@file     Main.cpp
@date     2017-6-28 13:49:56
@author   Zoro_Tiger
@brief    问题 1066: 2004年秋浙江省计算机等级考试二级C 编程题(2)
          http://www.dotcpp.com/oj/problem1066.html
********************************************************************/
//!头文件
#include <cstdio>
#include <cmath>

//!程序入口
int main(int argc, const char* argv[])
{
	//!变量声明
	double x = 0; int n = 0;

	//!读取数据
	scanf("%lf%d", &x, &n);

	//!计算结果
	double result = 0, temp_fact = 1, temp_power = 1;
	for (int i = 1; i <= n; ++i)
	{
		temp_power *= x;
		temp_fact *= static_cast<double>(i);
		if (i % 2 == 0)
		{
			result -= temp_power / temp_fact;
		}
		else
		{
			result += temp_power / temp_fact;
		}
	}

	//!显示结果
	printf("%.4lf\n", result);
	
	//!返回系统
	return 0;
}