/********************************************************************
@file     Main.cpp
@date     2017-05-07
@author   Zoro_Tiger
@brief    问题 1005: C语言程序设计教程（第三版）课后习题4.9
          http://www.dotcpp.com/oj/problem1005.html
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
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	float fIn = 0.0f;
	while (scanf("%f", &fIn) != EOF)
	{
		float fOut = 5 * (fIn - 32) / 9;
		printf("c=%.2f\n", fOut);
	}

	return 0;
}