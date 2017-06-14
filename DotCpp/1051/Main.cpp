/********************************************************************
@file     Main.cpp
@date     2017-6-14 09:33:51
@author   Zoro_Tiger
@brief    问题 1051: C语言程序设计教程（第三版）课后习题11.5
          http://www.dotcpp.com/oj/problem1051.html
********************************************************************/
#include <cstdio>
#include <cmath>

#define TEST
#undef  TEST
#define ARRAY_SIZE 128

struct Student
{
	char id[ARRAY_SIZE];
	char name[ARRAY_SIZE];
	int score1;
	int score2;
	int score3;
	int total_score;
};

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int student_num = 0;
	scanf("%d", &student_num);

	Student* pStudent = new Student[student_num];

	double ava_score1 = 0, ava_score2 = 0, ava_score3 = 0;
	for (int i = 0; i < student_num; ++i)
	{
		scanf("%s%s%d%d%d", pStudent[i].id, pStudent[i].name, &pStudent[i].score1, &pStudent[i].score2, &pStudent[i].score3);
		pStudent[i].total_score = pStudent[i].score1 + pStudent[i].score2 + pStudent[i].score3;
		ava_score1 += pStudent[i].score1;
		ava_score2 += pStudent[i].score2;
		ava_score3 += pStudent[i].score3;
	}
	ava_score1 /= static_cast<double>(student_num);
	ava_score2 /= static_cast<double>(student_num);
	ava_score3 /= static_cast<double>(student_num);
	printf("%d %d %d\n", static_cast<int>(ava_score1), static_cast<int>(ava_score2), static_cast<int>(ava_score3));

	int index = 0;
	for (int i = 0; i < student_num; ++i)
	{
		if (pStudent[i].total_score > pStudent[index].total_score)
		{
			index = i;
		}
	}
	printf("%s %s %d %d %d\n", pStudent[index].id, pStudent[index].name, pStudent[index].score1, pStudent[index].score2, pStudent[index].score3);

	delete[] pStudent;

	return 0;
}