/********************************************************************
@file     Main.cpp
@date     2017-5-25 09:45:52
@author   Zoro_Tiger
@brief    ���� 1030: C���Գ�����ƽ̳̣������棩�κ�ϰ��8.4
          http://www.dotcpp.com/oj/problem1030.html
********************************************************************/
#include <cstdio>
#include <cmath>

#define TEST
#undef  TEST
#define ARRAY_NUM 3

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	//!����
	int my_array[ARRAY_NUM][ARRAY_NUM];
	for (int i = 0; i < ARRAY_NUM; ++i)
	{
		for (int j = 0; j < ARRAY_NUM; ++j)
		{
			scanf("%d", my_array[i] + j);
		}
	}

	//!���
	for (int i = 0; i < ARRAY_NUM; ++i)
	{
		for (int j = 0; j < ARRAY_NUM; ++j)
		{
			printf("%d ", my_array[j][i]);
		}
		printf("\n");
	}

	return 0;
}