/********************************************************************
@file     Main.cpp
@date     2017-6-28 09:53:19
@author   Zoro_Tiger
@brief    问题 1060: C二级辅导-同因查找
          http://www.dotcpp.com/oj/problem1060.html
********************************************************************/
//!头文件
#include <cstdio>
#include <cmath>

//!程序入口
int main(int argc, const char* argv[])
{
	//!计算并输出结果
	for (int i = 10; i <= 1000; ++i)
	{
		if (!(i % 2) && !(i % 3) && !(i % 7))
		{
			printf("%d\n", i);
		}
	}
	
	//!返回系统
	return 0;
}