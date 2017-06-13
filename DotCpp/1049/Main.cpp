/********************************************************************
@file     Main.cpp
@date     2017-6-13 09:33:30
@author   Zoro_Tiger
@brief    问题 1049: C语言程序设计教程（第三版）课后习题11.1
          http://www.dotcpp.com/oj/problem1049.html
********************************************************************/
#include <cstdio>
#include <cmath>

#define TEST
#undef  TEST

struct Date
{
	int year;
	int month;
	int day;
};

bool IsLeapYear(int year)
{
	if (year % 400 == 0)
	{
		return true;
	}
	else if (year % 4 == 0 && year % 100 != 0)
	{
		return true;
	}
	return false;
}

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int month_contain_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	Date date;
	scanf("%d%d%d", &date.year, &date.month, &date.day);

	if (IsLeapYear(date.year))
	{
		month_contain_days[1] = 29;
	}
	else
	{
		month_contain_days[1] = 28;
	}

	int all_days = 0;
	for (int i = 0; i < date.month - 1; ++i)
	{
		all_days += month_contain_days[i];
	}
	all_days += date.day;

	printf("%d\n", all_days);

	return 0;
}