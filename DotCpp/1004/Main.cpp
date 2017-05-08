/********************************************************************
@file     Main.cpp
@date     2017-4-27
@author   Zoro_Tiger
@brief    ���� 1004: ĸţ�Ĺ���
          http://www.dotcpp.com/oj/problem1004.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>

//!�궨��
#define TEST
#undef  TEST
#define YEAR 55

//!ȫ�ֱ���
int Cow[YEAR];

//!�������
int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	//!��ʼ��
	for (int i = 0; i < YEAR; ++i)
	{
		if (i < 4) Cow[i] = i;
		else Cow[i] = Cow[i - 1] + Cow[i - 3];
	}

	int year = 0;
	while (scanf("%d", &year) && year)
	{
		printf("%d\n", Cow[year]);
	}

	return 0;
}