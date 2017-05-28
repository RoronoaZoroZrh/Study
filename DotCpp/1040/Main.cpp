/********************************************************************
@file     Main.cpp
@date     2017-05-28 21:57:02
@author   Zoro_Tiger
@brief    问题 1040: C语言程序设计教程（第三版）课后习题9.6
          http://www.dotcpp.com/oj/problem1040.html
********************************************************************/
#include <cstdio>

#define TEST
#undef  TEST

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	//!输入
	float fNum = 0;
	scanf("%f", &fNum);

	//!输出
	printf("%6.2f\n", fNum);
	printf("%6.2f %6.2f\n", fNum, fNum);
	printf("%6.2f %6.2f %6.2f\n", fNum, fNum, fNum);

	return 0;
}