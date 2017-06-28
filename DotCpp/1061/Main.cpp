/********************************************************************
@file     Main.cpp
@date     2017-6-28 09:58:32
@author   Zoro_Tiger
@brief    问题 1061: C二级辅导-计负均正
          http://www.dotcpp.com/oj/problem1061.html
********************************************************************/
//!头文件
#include <cstdio>
#include <cmath>

//!程序入口
int main(int argc, const char* argv[])
{
	//!计算
	double sum = 0, temp = 0, count = 0;
	for (int i = 0; i < 20; ++i)
	{
		scanf("%lf", &temp);
		if (temp <= 0)
		{
			++count;
		}
		else
		{
			sum += temp;
		}
	}

	//!输出结果
	printf("%d\n", static_cast<int>(count));
	printf("%.2lf\n", sum / (20.0 - count));

	//!返回系统
	return 0;
}