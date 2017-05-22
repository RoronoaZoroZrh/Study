/********************************************************************
@file     Main.cpp
@date     2017-5-22 09:42:47
@author   Zoro_Tiger
@brief    问题 1024: C语言程序设计教程（第三版）课后习题7.3
          http://www.dotcpp.com/oj/problem1024.html
********************************************************************/
#include <cstdio>
#include <cmath>

#define TEST
#undef  TEST

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	//!变量定义
	int sum1 = 0, sum2 = 0, temp1 = 0, temp2 = 0, temp3 = 0;

	//!第一行
	scanf("%d%d%d", &temp1, &temp2, &temp3);
	sum1 += temp1;
	sum2 += temp3;

	//!第二行
	scanf("%d%d%d", &temp1, &temp2, &temp3);
	sum1 += temp2;
	sum2 += temp2;

	//!第三行
	scanf("%d%d%d", &temp1, &temp2, &temp3);
	sum1 += temp3;
	sum2 += temp1;

	//!输出结果
	printf("%d %d\n", sum1, sum2);

	return 0;
}