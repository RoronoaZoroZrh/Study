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

//!��������
int GetCowNum(int year);

//!�������
int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int year = 0;
	while (scanf("%d", &year) && year)
	{
		printf("%d\n", GetCowNum(year));
	}

	return 0;
}

//!��ȡĸţ����
int GetCowNum(int year)
{
	switch (year)
	{
	case 1:
		return 1;
	case 2:
		return 2;
	case 3:
		return 3;
	default:
		return GetCowNum(year - 1) + GetCowNum(year - 3);
	}
}