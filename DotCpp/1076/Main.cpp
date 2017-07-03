/********************************************************************
@file     Main.cpp
@date     2017-7-3 10:24:28
@author   Zoro_Tiger
@brief    问题 1076: 内部收益率
          http://www.dotcpp.com/oj/problem1076.html
********************************************************************/
//!头文件
#include <cstdio>
#include <cmath>

//!宏定义
#define ARRAY_SIZE 15

//!程序入口
int main(int argc, const char* argv[])
{
	//!变量声明
	int number_t = 0; double param[ARRAY_SIZE] = { 0.0 };

	//!读取输入并计算
	while (scanf("%d", &number_t) != EOF && number_t != 0)
	{
		//!读取系数
		for (int i = 0; i <= number_t; ++i)
		{
			scanf("%lf", param + i);
		}

		//!二分法查找解
		double left = -1.0, middle = 0.0, right = 1E6, sum = 0, temp = 1;
		while (fabs(param[0] + sum) > 1E-7)
		{
			sum = 0; middle = (left + right) / 2.0; temp = 1;
			for (int i = 1; i <= number_t; ++i)
			{
				temp = temp / (1 + middle);
				sum += param[i] * temp;
			}

			if (param[0] + sum > 1E-7) left = middle;
			else right = middle;
		}

		//!显示结果
		printf("%.2lf\n", middle);
	}

	//!返回系统
	return 0;
}