/********************************************************************
@file     Main.cpp
@date     2017-6-27 10:08:20
@author   Zoro_Tiger
@brief    问题 1059: C二级辅导-等差数列
          http://www.dotcpp.com/oj/problem1059.html
********************************************************************/
//!头文件
#include <cstdio>
#include <cmath>

//!程序入口
int main(int argc, const char* argv[])
{
	//!变量声明
	int a1 = 2, d = 3, n = 0;

	//!读取输入
	scanf("%d", &n);

	//!计算结果
	int sum = a1 * n + (n * (n - 1) / 2) * d;

	//!显示结果
	printf("%d\n", sum);

	//!返回系统
	return 0;
}