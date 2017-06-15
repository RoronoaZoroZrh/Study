/********************************************************************
@file     Main.cpp
@date     2017-6-15 09:41:45
@author   Zoro_Tiger
@brief    问题 1053: 2003年秋浙江省计算机等级考试二级C 编程题(1)
          http://www.dotcpp.com/oj/problem1053.html
********************************************************************/
#include <cstdio>
#include <cmath>

#define TEST
#undef  TEST
#define INPUT_NUM 10 //!输入数量

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int my_array[INPUT_NUM];
	int sum = 0;

	for (int i = 0; i < INPUT_NUM; ++i)
	{
		scanf("%d", my_array + i);
		sum += *(my_array + i);
	}

	double average = static_cast<double>(sum) / INPUT_NUM;
	int count = 0;

	for (int i = 0; i < INPUT_NUM; ++i)
	{
		if (my_array[i] > average)
		{
			++count;
		}
	}

	printf("%d\n", count);

	return 0;
}