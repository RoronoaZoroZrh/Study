/********************************************************************
@file     Main.cpp
@date     2016-5-27
@author   Zoro_Tiger
@brief    ���⡢������������֮��
********************************************************************/
#include <cstdio>

int main(int argc, const char* argv[])
{
	int nIntegerA, nIntegerB;
	while (scanf("%d%d", &nIntegerA, &nIntegerB) == 2)
	{
		printf("%d\n", nIntegerA + nIntegerB);
	}
	return 0;
}