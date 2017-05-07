/********************************************************************
@file     Main.cpp
@date     2017-05-07
@author   Zoro_Tiger
@brief    问题 1006: C语言程序设计教程（第三版）课后习题5.4
          http://www.dotcpp.com/oj/problem1006.html
********************************************************************/
//!头文件
#include <cstdio>
#include <algorithm>

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

	int nA = 0, nB = 0, nC = 0;
	while (scanf("%d%d%d", &nA, &nB, &nC) != EOF)
	{
		printf("%d\n", std::max(std::max(nA, nB), nC));
	}

	return 0;
}