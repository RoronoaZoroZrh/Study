/********************************************************************
@file     Main.cpp
@date     2017-5-8
@author   Zoro_Tiger
@brief    ���� 1008: C���Գ�����ƽ̳̣������棩�κ�ϰ��5.6
          http://www.dotcpp.com/oj/problem1008.html
********************************************************************/
#include <cstdio>

#define TEST
#undef  TEST

//!��ȡ�ɼ��ȼ�
char GetGrade(int number_score);

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int number_score = 0;
	while (scanf("%d", &number_score) != EOF)
	{
		printf("%c\n", GetGrade(number_score));
	}

	return 0;
}

char GetGrade(int number_score)
{
	if (number_score >= 90)
	{
		return 'A';
	}
	else if (number_score >= 80)
	{
		return 'B';
	}
	else if (number_score >= 70)
	{
		return 'C';
	}
	else if (number_score >= 60)
	{
		return 'D';
	}
	else
	{
		return 'E';
	}
}