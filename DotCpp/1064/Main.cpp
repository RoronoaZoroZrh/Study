/********************************************************************
@file     Main.cpp
@date     2017-6-28 10:35:58
@author   Zoro_Tiger
@brief    问题 1064: C二级辅导-阶乘数列
          http://www.dotcpp.com/oj/problem1064.html
********************************************************************/
//!头文件
#include <cstdio>
#include <cmath>

//!程序入口
int main(int argc, const char* argv[])
{
	//!计算结果、利用好中间值
	double sum = 0, temp = 1;
	for (int i = 1; i <= 30; ++i)
	{
		temp *= static_cast<double>(i);
		sum += temp;
	}

	//!显示结果
	printf("%.2e\n", sum);

	//!返回系统
	return 0;
}