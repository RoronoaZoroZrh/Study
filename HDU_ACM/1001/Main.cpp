/********************************************************************
@file     Main.cpp
@date     2017-03-25
@author   Zoro_Tiger
@brief    计算1-N的和
********************************************************************/
//!头文件
#include <cstdio>

//!程序入口
int main(int argc, const char* argv[])
{
	__int64 nInteger = 0;
	while (scanf("%I64d", &nInteger) == 1)
	{
		printf("%I64d\n\n", nInteger * (nInteger + 1) / 2);
	}
	return 0;
}