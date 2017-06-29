/********************************************************************
@file     Main.cpp
@date     2017-6-29 10:04:20
@author   Zoro_Tiger
@brief    问题 1069: 2005年春浙江省计算机等级考试二级C 编程题(3)
          http://www.dotcpp.com/oj/problem1069.html
********************************************************************/
//!头文件
#include <cstdio>
#include <cmath>

//!程序入口
int main(int argc, const char* argv[])
{
	//!变量声明
	int number_n = 0;
	
	//!读取输入
	scanf("%d", &number_n);

	//!读取输入并计算结果
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

	//!输出结果
	printf("%d %d %d\n", number_max, index_x + 1, index_y + 1);
	
	//!返回系统
	return 0;
}