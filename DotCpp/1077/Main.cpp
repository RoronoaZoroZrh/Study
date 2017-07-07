/********************************************************************
@file     Main.cpp
@date     2017-7-4 11:05:30
@author   Zoro_Tiger
@brief    ���� 1077: Biggest Number
		  http://www.dotcpp.com/oj/problem1077.html
@detail   http://blog.csdn.net/q547550831/article/details/52161452
********************************************************************/
//!ͷ�ļ�
#include <cstdio>

//!�궨��
#define RECT_SIZE  15

//!ȫ�ֱ���
char   input[RECT_SIZE][RECT_SIZE];       //!����
bool   maze_state[RECT_SIZE][RECT_SIZE];  //!�Թ�״̬
bool   t_maze_state[RECT_SIZE][RECT_SIZE];//!�Թ���ʱ״̬
int    number_r, number_c;                //!����
int    total_int_cnt;                     //!��������

//!�������
int main(int argc, const char* argv[])
{
	while (scanf("%d%d", &number_r, &number_c) != EOF && (number_r + number_c)) //!number_r��number_cͬʱΪ���˳�
	{
		//GetInput();         //!��ȡ����
		//HandleInput();      //!��������
	}

	//!����ϵͳ
	return 0;
}

//!��ȡ����
void GetInput(void)
{
// 	//!��ʼ��
// 	memset(input, 0, sizeof(input));
// 	memset(maze_state, 0, sizeof(maze_state));
// 	bfs_map.clear();
// 	total_int_cnt = 0;
// 	dfs_tick = 0, bfs_tick = 0;
// 
// 	//!��ȡ����
// 	for (int i = 0; i < number_r; ++i)
// 	{
// 		scanf("%s", input + i);
// 		for (int j = 0; j < number_c; ++j)
// 		{
// 			if (isdigit(input[i][j]))
// 			{
// 				++total_int_cnt;
// 			}
// 			else
// 			{
// 				maze_state[i][j] = true;
// 			}
// 		}
// 	}
}

//!��������
void HandleInput(void)
{
// 	//!��������
// 	for (int i = 0; i < number_r; ++i)
// 	{
// 		for (int j = 0; j < number_c; ++j)
// 		{
// 			if (input[i][j] != '#')
// 			{
// 				//!��֦--������ֵ�ĳ����Ѿ�Ϊ������������ô�����һλС�����ֵ��һλ�򲻽�������
// 				if (total_int_cnt != 0 && max_result.length == total_int_cnt && input[i][j] < max_result.route[0])
// 				{
// 					continue;
// 				}
// 
// 				//!��������
// #ifdef IN_DEBUG
// 				dfs_tick = GetTickCount();
// #endif
// 				//DFS(i, j);
// #ifdef IN_DEBUG
// 				dfs_tick = GetTickCount() - dfs_tick;
// 				printf("dfs_tick=%ul\n", dfs_tick);
// #endif
// 			}
// 		}
// 	}
}

bool InMaze(int x, int y)
{
	return x >= 0 && x < number_r && y >= 0 && y < number_c;
}