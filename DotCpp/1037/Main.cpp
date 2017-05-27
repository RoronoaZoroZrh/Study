/********************************************************************
@file     Main.cpp
@date     2017-5-27 09:45:01
@author   Zoro_Tiger
@brief    问题 1037: C语言程序设计教程（第三版）课后习题9.2
          http://www.dotcpp.com/oj/problem1037.html
********************************************************************/
#include <cstdio>
#include <cmath>

#define TEST
#undef  TEST
#define REMAINDER(Left, Right) Left % Right

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	//!输入
	int num_a = 0, num_b = 0;
	scanf("%d%d", &num_a, &num_b);

	//!计算
	int remainder = REMAINDER(num_a, num_b);

	//!输出
	printf("%d\n", remainder);

	return 0;
}