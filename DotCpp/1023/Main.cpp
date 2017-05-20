/********************************************************************
@file     Main.cpp
@date     2017-05-20 22:05:39
@author   Zoro_Tiger
@brief    ���� 1023: C���Գ�����ƽ̳̣������棩�κ�ϰ��7.2
		  http://www.dotcpp.com/oj/problem1023.html
********************************************************************/
#include <cstdio>
#include <cstring>

#define TEST
#undef  TEST
#define ARRAY_NUM 10

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	//!��ȡ����
	int array[ARRAY_NUM];
	memset(array, 0, sizeof(array));
	for (int i = 0; i < ARRAY_NUM; ++i)
	{
		scanf("%d", &array[i]);
	}

	//!����
	for (int i = 0; i < ARRAY_NUM - 1; ++i)
	{
		int k = i;
		for (int j = i + 1; j < ARRAY_NUM; ++j)
		{
			if (array[j] < array[k])
			{
				k = j;
			}
		}

		if (k != i)
		{
			array[i] = array[i] + array[k];
			array[k] = array[i] - array[k];
			array[i] = array[i] - array[k];
		}
	}

	//!������
	for (int i = 0; i < ARRAY_NUM; ++i)
	{
		printf("%d\n", array[i]);
	}

	return 0;
}