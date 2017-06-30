/********************************************************************
@file     Main.cpp
@date     2017-6-30 11:31:54
@author   Zoro_Tiger
@brief    问题 1075: 台球碰撞
          http://www.dotcpp.com/oj/problem1075.html
********************************************************************/
//!头文件
#include <cstdio>
#include <cmath>
#include <math.h>

//!程序入口
int main(int argc, const char* argv[])
{
	//!变量声明
	double l, w, x, y, r, a, v, s;

	//!读取数据并计算
	while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &l, &w, &x, &y, &r, &a, &v, &s) != EOF && (l + w + x + y + r + a + v + s))
	{
		//!速度分解（一直没发现精度问题导致错了好多次）
		double v_x = v * cos(a * 4.0 * atan(1.0) / 180.0);
		double v_y = v * sin(a * 4.0 * atan(1.0) / 180.0);


		//!计算移动距离
		double distance_x = v_x * s, distance_y = v_y * s;

		//!整体移动
		double scope_x = l - 2 * r, scope_y = w - 2 * r;
		double final_x = x - r, final_y = y - r;

		//!计算最终位置
		distance_x = fmod(distance_x, scope_x * 2);
		distance_y = fmod(distance_y, scope_y * 2);
		if (distance_x < 0) distance_x = distance_x + scope_x * 2;
		if (distance_y < 0) distance_y = distance_y + scope_y * 2;
		final_x = fmod(final_x + distance_x, scope_x * 2);
		final_y = fmod(final_y + distance_y, scope_y * 2);
		if (final_x > scope_x) final_x = 2 * scope_x - final_x;
		if (final_y > scope_y) final_y = 2 * scope_y - final_y;

		//!输出结果
		printf("%.2lf %.2lf\n", final_x + r, final_y + r);
	}

	//!返回系统
	return 0;
}