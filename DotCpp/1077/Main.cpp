/********************************************************************
@file     Main.cpp
@date     2017-7-4 11:05:30
@author   Zoro_Tiger
@brief    ���� 1077: Biggest Number
		  http://www.dotcpp.com/oj/problem1077.html
@detail   DFS+��֦
********************************************************************/
//!ͷ�ļ�
#include <cmath>
#include <cstdio>
#include <cstring>

//!�궨��
#define RECT_SIZE 15

//!ȫ�ֱ���
int  number_r = 0, number_c = 0;       //!�С���
char input[RECT_SIZE][RECT_SIZE];      //!�Թ�
bool maze_state[RECT_SIZE][RECT_SIZE]; //!�Թ�״̬

//!DFS
void DFS(int x, int y)
{
	
}

//!�������
int main(int argc, const char* argv[])
{
	while (scanf("%d%d", &number_r, &number_c) != EOF && !(number_r + number_c))
	{
		//!��ȡ����
		memset(input, 0, sizeof(input));
		for (int i = 0; i < number_r; ++i) scanf("%s", input + i);
	}

	//!����ϵͳ
	return 0;
}