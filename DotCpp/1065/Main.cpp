/********************************************************************
@file     Main.cpp
@date     2017-6-28 10:45:08
@author   Zoro_Tiger
@brief    问题 1065: 2004年秋浙江省计算机等级考试二级C 编程题(1)
          http://www.dotcpp.com/oj/problem1065.html
********************************************************************/
//!头文件
#include <cstdio>
#include <cmath>

//!宏定义
#define ARRAY_SIZE 10

//!程序入口
int main(int argc, const char* argv[])
{
	//!变量声明
	int array[ARRAY_SIZE]= { 0 };

	//!读取输入并找到最小值
	int index = 0;
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		//!读取输入
		scanf("%d", array + i);

		//!找到最小值
		if (i != 0 && std::abs(array[i]) < std::abs(array[index])) //!绝对值最小，看错题了
		{
			index = i;
		}
	}

	//!交换数值
	if (index != ARRAY_SIZE - 1) //!避免自身交换
	{
		array[index] += array[ARRAY_SIZE - 1];
		array[ARRAY_SIZE - 1] = array[index] - array[ARRAY_SIZE - 1];
		array[index] = array[index] - array[ARRAY_SIZE - 1];
	}

	//!输出结果
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
	
	//!返回系统
	return 0;
}