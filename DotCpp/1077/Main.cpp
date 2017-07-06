/********************************************************************
@file     Main.cpp
@date     2017-7-4 11:05:30
@author   Zoro_Tiger
@brief    问题 1077: Biggest Number
		  http://www.dotcpp.com/oj/problem1077.html
@detail   http://blog.csdn.net/q547550831/article/details/52161452
********************************************************************/
//!头文件
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>

//!函数声明
void GetInput(void);

//!宏定义
#define RECT_SIZE  15

//!全局变量
char input[RECT_SIZE][RECT_SIZE];       //!输入
bool maze_state[RECT_SIZE][RECT_SIZE];  //!迷宫状态
int  number_r, number_c;                //!行列
int  total_int_cnt;                     //!数字数量
char max_result[RECT_SIZE*RECT_SIZE];   //!结果

//!程序入口
int main(int argc, const char* argv[])
{
	while (scanf("%d%d", &number_r, &number_c) != EOF && (number_r + number_c)) //!number_r和number_c同时为零退出
	{
		GetInput(); //!获取输入
	}

	//!返回系统
	return 0;
}

//!获取输入
void GetInput(void)
{
	//!初始化
	memset(input, 0, sizeof(input));
	memset(maze_state, 0, sizeof(maze_state));
	memset(max_result, 0, sizeof(max_result));
	total_int_cnt = 0;

	//!获取输入
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

//!处理输入
void HandleInput(void)
{
	//!处理输入
	for (int i = 0; i < number_r; ++i)
	{
		for (int j = 0; j < number_c; ++j)
		{
			
		}
	}
}

//!是否能进行DFS
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