/********************************************************************
@file     Main.cpp
@date     2017-5-27 09:52:16
@author   Zoro_Tiger
@brief    ���� 1038: C���Գ�����ƽ̳̣������棩�κ�ϰ��9.3
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

	//!����
	float a = 0, b = 0, c = 0;
	scanf("%f%f%f", &a, &b, &c);

	//!����
	float area = AREA(S(a, b, c), a, b, c);

	//!���
	printf("%.3f\n", area);

	return 0;
}