/********************************************************************
@file     Main.cpp
@date     2017-5-9
@author   Zoro_Tiger
@brief    问题 1010: C语言程序设计教程（第三版）课后习题5.8
          http://www.dotcpp.com/oj/problem1010.html
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

	int benifit = 0;
	while (scanf("%d", &benifit) != EOF)
	{
		int reward = 0;
		if (benifit - 1000000 > 0)
		{
			reward += static_cast<int>((benifit - 1000000) * 0.01f);
			benifit -= 1000000;
		}
		else if (benifit - 600000 > 0)
		{
			reward += static_cast<int>((benifit - 600000) * 0.015f);
			benifit -= 600000;
		}
		else if (benifit - 400000 > 0)
		{
			reward += static_cast<int>((benifit - 400000) * 0.03f);
			benifit -= 400000;
		}
		else if (benifit - 200000 > 0)
		{
			reward += static_cast<int>((benifit - 200000) * 0.05f);
			benifit -= 200000;
		}
		else if (benifit - 100000 > 0)
		{
			reward += static_cast<int>((benifit - 100000) * 0.075f);
			benifit -= 100000;
		}
		else
		{
			reward += static_cast<int>(benifit * 0.1f);
		}
		printf("%d\n", reward);
	}

	return 0;
}