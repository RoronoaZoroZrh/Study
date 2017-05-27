/********************************************************************
@file     Main.cpp
@date     2017-5-27 09:35:06
@author   Zoro_Tiger
@brief    ���� 1036: C���Գ�����ƽ̳̣������棩�κ�ϰ��9.1
          http://www.dotcpp.com/oj/problem1036.html
********************************************************************/
#include <cstdio>
#include <cmath>

#define TEST
#undef  TEST
#define EXCHANGE(Left, Right) Left += Right; Right = Left - Right; Left = Left - Right;

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
	EXCHANGE(num_a, num_b);

	//!���
	printf("%d %d\n", num_a, num_b);

	return 0;
}