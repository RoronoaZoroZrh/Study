/********************************************************************
@file     Main.cpp
@date     2017-4-27
@author   Zoro_Tiger
@brief    ���� 1002: C���Գ�����ƽ̳̣������棩�κ�ϰ��1.6
          http://www.dotcpp.com/oj/problem1002.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <algorithm>

//!�궨��
#define TEST
#undef  TEST

//!�������
int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int number_a = 0, number_b = 0, number_c = 0;
	while (scanf("%d%d%d", &number_a, &number_b, &number_c) != EOF)
	{
		printf("%d\n", std::max(std::max(number_a, number_b), number_c));
	}

	return 0;
}