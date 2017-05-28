/********************************************************************
@file     Main.cpp
@date     2017-05-28 22:02:55
@author   Zoro_Tiger
@brief    问题 1041: C语言程序设计教程（第三版）课后习题9.8
          http://www.dotcpp.com/oj/problem1041.html
********************************************************************/
#include <cstdio>
#include <algorithm>

#define TEST
#undef  TEST
#define MAX(a, b, c) GetMax(a, b, c)

float GetMax(float a, float b, float c)
{
	return std::max(std::max(a, b), c);
}

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	//!输入
	float a = 0, b = 0, c = 0;
	scanf("%f%f%f", &a, &b, &c);

	//!输出
	printf("%.3f\n", GetMax(a, b, c));
	printf("%.3f\n", MAX(a, b, c));

	return 0;
}