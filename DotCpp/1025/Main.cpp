/********************************************************************
@file     Main.cpp
@date     2017-5-22 09:52:14
@author   Zoro_Tiger
@brief    ���� 1025: C���Գ�����ƽ̳̣������棩�κ�ϰ��7.4
          http://www.dotcpp.com/oj/problem1025.html
********************************************************************/
#include <cstdio>
#include <cmath>

#define TEST
#undef  TEST
#define ARRAY_NUM 9

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	//!��ȡ����
	int array[ARRAY_NUM];
	for (int i = 0; i < ARRAY_NUM; ++i)
	{
		scanf("%d", array + i);
	}

	//!��ȡ����
	int num = 0;
	scanf("%d", &num);

	//!�ҵ�����λ��
	int key = -1;
	for (int i = 0; i < ARRAY_NUM - 1; ++i)
	{
		if (array[i] >= num && array[i + 1] <= num)
		{
			key = i + 1;
			break;
		}
		else if (array[i] <= num && array[i + 1] >= num)
		{
			key = i + 1;
			break;
		}
	}

	//!û���ҵ�����λ��
	if (-1 == key)
	{
		if (array[0] < array[ARRAY_NUM - 1])
		{
			if (key < array[0])
			{
				key = 0;
			}
			else
			{
				key = ARRAY_NUM;
			}
		}
		else
		{
			if (key > array[0])
			{
				key = 0;
			}
			else
			{
				key = ARRAY_NUM;
			}
		}
	}

	//!������
	bool bFlag = true;
	for (int i = 0; i < ARRAY_NUM; ++i)
	{
		if (key <= i && bFlag)
		{
			bFlag = false;
			printf("%d\n", num);
		}
		printf("%d\n", array[i]);
	}

	return 0;
}