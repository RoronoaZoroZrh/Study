/********************************************************************
@file     Main.cpp
@date     2017-7-4 11:05:30
@author   Zoro_Tiger
@brief    问题 1077: Biggest Number
		  http://www.dotcpp.com/oj/problem1077.html
@detail   DFS+剪枝
********************************************************************/
//!头文件
#include <cmath>
#include <cstdio>
#include <cstring>

//!宏定义
#define RECT_SIZE 15

//!全局变量
int  number_r = 0, number_c = 0;       //!行、列
char input[RECT_SIZE][RECT_SIZE];      //!迷宫
bool maze_state[RECT_SIZE][RECT_SIZE]; //!迷宫状态

//!DFS
void DFS(int x, int y)
{
	
}

//!程序入口
int main(int argc, const char* argv[])
{
	while (scanf("%d%d", &number_r, &number_c) != EOF && !(number_r + number_c))
	{
		//!读取输入
		memset(input, 0, sizeof(input));
		for (int i = 0; i < number_r; ++i) scanf("%s", input + i);
	}

	//!返回系统
	return 0;
}