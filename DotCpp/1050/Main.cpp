/********************************************************************
@file     Main.cpp
@date     2017-6-14 09:12:11
@author   Zoro_Tiger
@brief    问题 1050: C语言程序设计教程（第三版）课后习题11.3
          http://www.dotcpp.com/oj/problem1050.html
********************************************************************/
#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>

#define TEST
#undef  TEST

struct Student
{
	std::string id;
	std::string name;
	int score1;
	int score2;
	int score3;
};

int GetStudentNum(void)
{
	int student_num = 0;
	scanf("%d", &student_num);
	return student_num;
}

void GetStudents(Student student[], int student_num)
{
	for (int i = 0; i < student_num; ++i)
	{
		std::cin >> student[i].id >> student[i].name
			>> student[i].score1 >> student[i].score2 >> student[i].score3;
	}
}

void OutStudents(Student student[], int student_num)
{
	for (int i = 0; i < student_num; ++i)
	{
		std::cout << student[i].id << "," << student[i].name << ","
			<< student[i].score1 << "," << student[i].score2 << "," << student[i].score3;
		printf("\n");
	}
}

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int student_num = GetStudentNum();

	Student* pStudent = new Student[student_num];

	GetStudents(pStudent, student_num);

	OutStudents(pStudent, student_num);

	delete[] pStudent;

	return 0;
}