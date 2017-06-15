/********************************************************************
@file     Main.cpp
@date     2017-6-15 09:24:35
@author   Zoro_Tiger
@brief    问题 1052: C语言程序设计教程（第三版）课后习题11.8
          http://www.dotcpp.com/oj/problem1052.html
********************************************************************/
#include <cstdio>
#include <cmath>
#include <algorithm>

#define TEST
#undef  TEST

struct Student
{
	int id;
	int score;
};

bool operator<(const Student& lh, const Student& rh)
{
	return lh.id < rh.id;
}

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int n = 0, m = 0;
	scanf("%d%d", &n, &m);

	Student* pStu = new Student[n + m];
	for (int i = 0; i < n + m; ++i)
	{
		scanf("%d%d", &pStu[i].id, &pStu[i].score);
	}

	std::sort(pStu, pStu + n + m);

	for (int i = 0; i < n + m; ++i)
	{
		printf("%d %d\n", pStu[i].id, pStu[i].score);
	}

	return 0;
}