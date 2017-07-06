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

//!宏定义
#define RECT_SIZE  15

//!结果
struct Result
{
	Result(void)
	{
		Clear();
	}

	void Clear(void)
	{
		length = 0;
		memset(route, '\0', sizeof(route));
	}

	bool operator<(const Result& rhs) const
	{
		if (length != rhs.length)
		{
			return length < rhs.length;
		}
		else
		{
			for (int i = 0; i < length; ++i)
			{
				if (route[i] != rhs.route[i])
				{
					return route[i] < rhs.route[i];
				}
			}
		}
	}

	bool operator>(const Result& rhs) const
	{
		return !operator<(rhs);
	}

	void Print(void)
	{
		for (int i = 0; i < length; ++i)
		{
			printf("%c", route[i]);
		}
		printf("\n");
	}

	int  length;
	char route[RECT_SIZE*RECT_SIZE];
};

//!函数声明
void GetInput(void);
void HandleInput(void);
bool CanDFS(int x, int y);
void DFS(int x, int y);
int  BFS(int x, int y);
bool CanBFS(int x, int y);

//!全局变量
char   input[RECT_SIZE][RECT_SIZE];       //!输入
bool   maze_state[RECT_SIZE][RECT_SIZE];  //!迷宫状态
bool   t_maze_state[RECT_SIZE][RECT_SIZE];//!迷宫临时状态
int    number_r, number_c;                //!行列
int    total_int_cnt;                     //!数字数量
Result max_result, temp_result;           //!结果

//!程序入口
int main(int argc, const char* argv[])
{
	while (scanf("%d%d", &number_r, &number_c) != EOF && (number_r + number_c)) //!number_r和number_c同时为零退出
	{
		GetInput();         //!获取输入
		HandleInput();      //!处理输入
		max_result.Print(); //!显示结果
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
	max_result.Clear(); temp_result.Clear();
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
			if (CanDFS(i, j))
			{
				//!剪枝--如果最大值的长度已经为数字总数，那么如果第一位小于最大值第一位则不进行搜索
				if (total_int_cnt != 0 && max_result.length == total_int_cnt && input[i][j] < max_result.route[0])
				{
					continue;
				}

				//!进行搜索
				DFS(i, j);
			}
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
	else
	{
		return true;
	}
}

//!DFS
void DFS(int x, int y)
{
	if (CanDFS(x, y))
	{
		int length = BFS(x, y);
		if (length + temp_result.length < max_result.length)
		{
			return;
		}
		else if (length + temp_result.length == max_result.length)
		{
			for (int i = 0; i < temp_result.length; ++i)
			{
				if (temp_result.route[i] < max_result.route[i])
				{
					return;
				}
			}
		}

		maze_state[x][y] = true; temp_result.route[temp_result.length++] = input[x][y];

		printf("%d%d\n", x, y);
		temp_result.Print();

		DFS(x + 1, y);
		DFS(x, y + 1);
		DFS(x - 1, y);
		DFS(x, y - 1);
		if (max_result < temp_result) max_result = temp_result;
		maze_state[x][y] = false; --temp_result.length;
	}
}

//!BFS
int BFS(int x, int y)
{
	std::queue<int> my_queue;
	my_queue.push(x * RECT_SIZE + y);

	int length = 0;
	memset(t_maze_state, 0, sizeof(t_maze_state));
	while (!my_queue.empty())
	{
		int tmp = my_queue.front(); my_queue.pop();
		int new_x = tmp / RECT_SIZE, new_y = tmp % RECT_SIZE;
		if (CanBFS(new_x, new_y))
		{
			t_maze_state[new_x][new_y] = true;
			++length;

			if (CanBFS(new_x + 1, new_y))
			{
				my_queue.push((new_x + 1) * RECT_SIZE + new_y);
			}

			if (CanBFS(new_x - 1, new_y))
			{
				my_queue.push((new_x - 1) * RECT_SIZE + new_y);
			}

			if (CanBFS(new_x, new_y + 1))
			{
				my_queue.push(new_x * RECT_SIZE + (new_y + 1));
			}

			if (CanBFS(new_x, new_y - 1))
			{
				my_queue.push(new_x * RECT_SIZE + (new_y - 1));
			}
		}
	}

	return length;
}

//!是否能进行BFS
bool CanBFS(int x, int y)
{
	if (CanDFS(x, y) && !t_maze_state[x][y])
	{
		return true;
	}
	return false;
}