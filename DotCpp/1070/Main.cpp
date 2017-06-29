/********************************************************************
@file     Main.cpp
@date     2017-6-29 10:20:21
@author   Zoro_Tiger
@brief    问题 1070: 2006年春浙江省计算机等级考试二级C 编程题(1)
          http://www.dotcpp.com/oj/problem1070.html
********************************************************************/
//!头文件
#include <cstdio>
#include <cmath>

//!程序入口
int main(int argc, const char* argv[])
{
	//!变量声明
	int grade_a = 0, grade_b = 0, grade_c = 0, temp = 0;

	//!读取输入并计算
	while (scanf("%d", &temp) != EOF && temp > 0)
	{
		if (temp >= 85)
		{
			++grade_a;
		}
		else if (temp >= 60)
		{
			++grade_b;
		}
		else
		{
			++grade_c;
		}
	}

	//!显示结果
	printf(">=85:%d\n", grade_a);
	printf("60-84:%d\n", grade_b);
	printf("<60:%d\n", grade_c);

	//!返回系统
	return 0;
}