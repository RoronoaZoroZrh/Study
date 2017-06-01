/********************************************************************
@file     Main.cpp
@date     2017-06-01 09:47:51
@author   Zoro_Tiger
@brief    问题 1045: C语言程序设计教程（第三版）课后习题10.3
          http://www.dotcpp.com/oj/problem1045.html
********************************************************************/
#include <cstdio>

#define TEST
#undef  TEST
#define ARRAY_NUM 10

void GetArray(int* array)
{
	for (int i = 0; i < ARRAY_NUM; ++i)
	{
		scanf("%d", array + i);
	}
}

void HandleArray(int* array)
{
	int k = 0;
	for (int i = 1; i < ARRAY_NUM; ++i)
	{
		if (array[i] < array[k])
		{
			k = i;
		}
	}

	if (k != 0)
	{
		array[0] = array[k] + array[0];
		array[k] = array[0] - array[k];
		array[0] = array[0] - array[k];
	}

	k = ARRAY_NUM - 1;
	for (int i = 0; i < ARRAY_NUM - 1; ++i)
	{
		if (array[i] > array[k])
		{
			k = i;
		}
	}

	if (k != ARRAY_NUM - 1)
	{
		array[ARRAY_NUM - 1] = array[k] + array[ARRAY_NUM - 1];
		array[k] = array[ARRAY_NUM - 1] - array[k];
		array[ARRAY_NUM - 1] = array[ARRAY_NUM - 1] - array[k];
	}
}

void OutputArray(int* array)
{
	for (int i = 0; i < ARRAY_NUM; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int array[ARRAY_NUM];
	GetArray(array);
	HandleArray(array);
	OutputArray(array);

	return 0;
}