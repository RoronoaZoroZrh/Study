/********************************************************************
@file     Main.cpp
@date     2017-6-30 11:31:54
@author   Zoro_Tiger
@brief    ���� 1075: ̨����ײ
          http://www.dotcpp.com/oj/problem1075.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <cmath>
#include <math.h>

//!�������
int main(int argc, const char* argv[])
{
	//!��������
	double l, w, x, y, r, a, v, s;

	//!��ȡ���ݲ�����
	while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &l, &w, &x, &y, &r, &a, &v, &s) != EOF && (l + w + x + y + r + a + v + s))
	{
		//!�ٶȷֽ⣨һֱû���־������⵼�´��˺ö�Σ�
		double v_x = v * cos(a * 4.0 * atan(1.0) / 180.0);
		double v_y = v * sin(a * 4.0 * atan(1.0) / 180.0);


		//!�����ƶ�����
		double distance_x = v_x * s, distance_y = v_y * s;

		//!�����ƶ�
		double scope_x = l - 2 * r, scope_y = w - 2 * r;
		double final_x = x - r, final_y = y - r;

		//!��������λ��
		distance_x = fmod(distance_x, scope_x * 2);
		distance_y = fmod(distance_y, scope_y * 2);
		if (distance_x < 0) distance_x = distance_x + scope_x * 2;
		if (distance_y < 0) distance_y = distance_y + scope_y * 2;
		final_x = fmod(final_x + distance_x, scope_x * 2);
		final_y = fmod(final_y + distance_y, scope_y * 2);
		if (final_x > scope_x) final_x = 2 * scope_x - final_x;
		if (final_y > scope_y) final_y = 2 * scope_y - final_y;

		//!������
		printf("%.2lf %.2lf\n", final_x + r, final_y + r);
	}

	//!����ϵͳ
	return 0;
}