/********************************************************************
@file     Main.cpp
@date     2017-5-27 09:52:16
@author   Zoro_Tiger
@brief    问题 1038: C语言程序设计教程（第三版）课后习题9.3
          http://www.dotcpp.com/oj/problem1038.html
********************************************************************/
#include <cstdio>
#include <cmath>

#define TEST
#undef  TEST
#define S(a, b, c) ((a + b + c) / 2)
#define AREA(s, a, b, c) (sqrtf(s * (s - a) * (s - b) * (s - c)))

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	//!输入
	float a = 0, b = 0, c = 0;
	scanf("%f%f%f", &a, &b, &c);

	//!计算
	float area = AREA(S(a, b, c), a, b, c);

	//!输出
	printf("%.3f\n", area);

	return 0;
}