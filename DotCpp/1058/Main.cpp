/********************************************************************
@file     Main.cpp
@date     2017-6-27 09:50:36
@author   Zoro_Tiger
@brief    问题 1058: C二级辅导-求偶数和
          http://www.dotcpp.com/oj/problem1058.html
********************************************************************/
//!头文件
#include <cstdio>
#include <cmath>

//!程序入口
int main(int argc, const char* argv[])
{
	//!整数个数
	int int_num = 0;
	scanf("%d", &int_num);

	//!读取输入并计算偶数之和
	int sum = 0, temp = 0;
	while (int_num --)
	{
		scanf("%d", &temp);
		sum += (temp % 2 == 0 ? temp : 0);
	}

	//!输出结果
	printf("%d\n", sum);
	
	//!返回系统
	return 0;
}