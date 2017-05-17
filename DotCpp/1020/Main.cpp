/********************************************************************
@file     Main.cpp
@date     2017-5-17 17:02:42
@author   Zoro_Tiger
@brief    ���� 1020: C���Գ�����ƽ̳̣������棩�κ�ϰ��6.10
          http://www.dotcpp.com/oj/problem1020.html
********************************************************************/
#include <cstdio>
#include <cmath>

#define TEST
#undef  TEST

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int day = 0;
	while (scanf("%d", &day) != EOF)
	{
		if (day == 1)
		{
			printf("%d\n", day);
		}
		else
		{
			//!��Ŀò�ƴ��˰ɣ�Ӧ������ǵ�һ�칲�ж��ٸ�����
			printf("%d\n", 3 * static_cast<int>(pow(2.0, day - 1)) - 2);
		}
	}

	return 0;
}