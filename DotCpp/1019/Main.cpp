/********************************************************************
@file     Main.cpp
@date     2017-05-12 23:18:28
@author   Zoro_Tiger
@brief    问题 1019: C语言程序设计教程（第三版）课后习题6.9
          http://www.dotcpp.com/oj/problem1019.html
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

	int height = 0, times = 0;
	while (scanf("%d%d", &height, &times) != EOF)
	{
		double last_height = height / static_cast<double>(pow(2.0, times)); //! (a/(b^times))

		double temp_height = static_cast<double>(height);
		double distance = temp_height;
		for (int i = 1; i < times; ++i) //!模拟落下弹起的过程
		{
			temp_height /= 2;
			distance += (temp_height * 2);
		}

		printf("%.2lf %.2lf\n", last_height, distance);
	}

	return 0;
}