/********************************************************************
@file     Main.cpp
@date     2017-6-29 11:27:27
@author   Zoro_Tiger
@brief    问题 1072: 汽水瓶
          http://www.dotcpp.com/oj/problem1072.html
@detail   每两个空瓶可以兑换一瓶汽水并且不产生空瓶
********************************************************************/
//!头文件
#include <cstdio>
#include <cmath>

//!程序入口
int main(int argc, const char* argv[])
{
	//!变量声明
	int empty_bottle = 0;

	//!读取输入
	while (scanf("%d", &empty_bottle) != EOF && empty_bottle > 0)
	{
		//!显示结果
		printf("%d\n", empty_bottle / 2);
	}

	//!返回系统
	return 0;
}