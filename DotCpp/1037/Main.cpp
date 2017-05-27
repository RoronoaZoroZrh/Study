/********************************************************************
@file     Main.cpp
@date     2017-5-27 09:45:01
@author   Zoro_Tiger
@brief    ���� 1037: C���Գ�����ƽ̳̣������棩�κ�ϰ��9.2
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

	//!����
	int num_a = 0, num_b = 0;
	scanf("%d%d", &num_a, &num_b);

	//!����
	int remainder = REMAINDER(num_a, num_b);

	//!���
	printf("%d\n", remainder);

	return 0;
}