/********************************************************************
@file     Main.cpp
@date     2017-4-26
@author   Zoro_Tiger
@brief    问题 1001: C语言程序设计教程（第三版）课后习题1.5
          http://www.dotcpp.com/oj/problem1001.html
********************************************************************/
//!头文件
#include <cstdio>

//!宏定义
#define TEST
#undef  TEST

//!程序入口
int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("out.txt", "w", stdout);
#endif

	//!输出到屏幕
	printf("**************************\nHello World!\n**************************");

	return 0;
}