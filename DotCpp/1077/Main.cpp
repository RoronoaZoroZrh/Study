/********************************************************************
@file     Main.cpp
@date     2017-7-4 11:05:30
@author   Zoro_Tiger
@brief    ���� 1077: Biggest Number
		  http://www.dotcpp.com/oj/problem1077.html
@detail   http://blog.csdn.net/q547550831/article/details/52161452
********************************************************************/
//!ͷ�ļ�
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>

//!��������
void GetInput(void);

//!�궨��
#define RECT_SIZE  15

//!ȫ�ֱ���
char input[RECT_SIZE][RECT_SIZE];       //!����
bool maze_state[RECT_SIZE][RECT_SIZE];  //!�Թ�״̬
int  number_r, number_c;                //!����
int  total_int_cnt;                     //!��������
char max_result[RECT_SIZE*RECT_SIZE];   //!���

//!�������
int main(int argc, const char* argv[])
{
	while (scanf("%d%d", &number_r, &number_c) != EOF && (number_r + number_c)) //!number_r��number_cͬʱΪ���˳�
	{
		GetInput(); //!��ȡ����
	}

	//!����ϵͳ
	return 0;
}

//!��ȡ����
void GetInput(void)
{
	//!��ʼ��
	memset(input, 0, sizeof(input));
	memset(maze_state, 0, sizeof(maze_state));
	memset(max_result, 0, sizeof(max_result));
	total_int_cnt = 0;

	//!��ȡ����
	for (int i = 0; i < number_r; ++i)
	{
		scanf("%s", input + i);
		for (int j = 0; j < number_c; ++j)
		{
			if (isdigit(input[i][j]))
			{
				++total_int_cnt;
			}
			else
			{
				maze_state[i][j] = true;
			}
		}
	}
}

//!��������
void HandleInput(void)
{
	//!��������
	for (int i = 0; i < number_r; ++i)
	{
		for (int j = 0; j < number_c; ++j)
		{
			
		}
	}
}

//!�Ƿ��ܽ���DFS
bool CanDFS(int x, int y)
{
	if (maze_state[x][y])
	{
		return false;
	}
	else if (x < 0 || x >= number_r || y < 0 || y >= number_c)
	{
		return false;
	}
	else if (strlen(max_result) == total_int_cnt && input[x][y])
	{

	}
}

//!DFS
void DFS(int x, int y)
{
	
}