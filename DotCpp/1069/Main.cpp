/********************************************************************
@file     Main.cpp
@date     2017-6-29 10:04:20
@author   Zoro_Tiger
@brief    ���� 1069: 2005�괺�㽭ʡ������ȼ����Զ���C �����(3)
          http://www.dotcpp.com/oj/problem1069.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <cmath>

//!�������
int main(int argc, const char* argv[])
{
	//!��������
	int number_n = 0;
	
	//!��ȡ����
	scanf("%d", &number_n);

	//!��ȡ���벢������
	int number_max, index_x, index_y, number_temp;
	for (int i = 0; i < number_n; ++i)
	{
		for (int j = 0; j < number_n; ++j)
		{
			if (!i && !j)
			{
				scanf("%d", &number_max); index_x = i; index_y = j;
			}
			else
			{
				scanf("%d", &number_temp);
				if (std::abs(number_temp) > number_max)
				{
					number_max = number_temp; index_x = i; index_y = j;
				}
			}
		}
	}

	//!������
	printf("%d %d %d\n", number_max, index_x + 1, index_y + 1);
	
	//!����ϵͳ
	return 0;
}