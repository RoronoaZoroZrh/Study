/********************************************************************
@file     Main.cpp
@date     2017-6-28 10:45:08
@author   Zoro_Tiger
@brief    ���� 1065: 2004�����㽭ʡ������ȼ����Զ���C �����(1)
          http://www.dotcpp.com/oj/problem1065.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <cmath>

//!�궨��
#define ARRAY_SIZE 10

//!�������
int main(int argc, const char* argv[])
{
	//!��������
	int array[ARRAY_SIZE]= { 0 };

	//!��ȡ���벢�ҵ���Сֵ
	int index = 0;
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		//!��ȡ����
		scanf("%d", array + i);

		//!�ҵ���Сֵ
		if (i != 0 && std::abs(array[i]) < std::abs(array[index])) //!����ֵ��С����������
		{
			index = i;
		}
	}

	//!������ֵ
	if (index != ARRAY_SIZE - 1) //!����������
	{
		array[index] += array[ARRAY_SIZE - 1];
		array[ARRAY_SIZE - 1] = array[index] - array[ARRAY_SIZE - 1];
		array[index] = array[index] - array[ARRAY_SIZE - 1];
	}

	//!������
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		if (0 == i)
		{
			printf("%d", array[i]);
		}
		else
		{
			printf(" %d", array[i]);
		}
	}
	
	//!����ϵͳ
	return 0;
}