/********************************************************************
@file     Main.cpp
@date     2017-5-18 09:28:39
@author   Zoro_Tiger
@brief    问题 1021: C语言程序设计教程（第三版）课后习题6.11
          http://www.dotcpp.com/oj/problem1021.html
********************************************************************/
#include <cstdio>
#include <cmath>

#define TEST
#undef  TEST
#define SMALL 0.00001

//!求平方根
double Sqrt(double fNum)
{
	double fTemp = fNum;
	while (fabs(fTemp * fTemp - fNum) > SMALL)
	{
		fTemp = (fTemp + fNum / fTemp) / 2.0;
	}
	return fTemp;
}

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	double fNum = 0;
	while (scanf("%lf", &fNum) != EOF)
	{
		printf("%.3lf\n", Sqrt(fNum));
	}

	return 0;
}