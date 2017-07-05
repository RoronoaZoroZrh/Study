/********************************************************************
@file     Main.cpp
@date     2017-7-4 11:05:30
@author   Zoro_Tiger
@brief    问题 1077: Biggest Number
		  http://www.dotcpp.com/oj/problem1077.html
@detail   http://blog.csdn.net/axuan_k/article/details/47208365
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
#define ROUTE_SIZE 30
#define DIRECTION  4

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
		memset(route, 0, sizeof(route));
	}

	bool operator<(const Result& rhs) const
	{
		if (length != rhs.length)
		{
			return length < rhs.length;
		}
		for (int i = 0; i < length; ++i)
		{
			if (route[i] != rhs.route[i])
			{
				return route[i] < rhs.route[i];
			}
		}
		return false;
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
	char route[ROUTE_SIZE];
};

//!全局变量
int    number_r = 0, number_c = 0;                        //!行、列
char   input[RECT_SIZE][RECT_SIZE];                       //!迷宫
bool   maze_state[RECT_SIZE][RECT_SIZE];                  //!迷宫状态
Result cur_result, max_result, temp_result, tmp_result;   //!结果
bool   maze_temp_state[RECT_SIZE][RECT_SIZE];             //!迷宫临时状态

//!获取长度
int GetLength(int x, int y)
{
	memset(maze_temp_state, 0, sizeof(maze_temp_state));

	std::queue<int> my_queue;
	my_queue.push(x * RECT_SIZE + y);

	temp_result.Clear();
	temp_result.route[temp_result.length++] = input[x][y];
	maze_temp_state[x][y] = true;

	int temp, temp_x, temp_y, new_x, new_y;
	while (!my_queue.empty())
	{
		temp = my_queue.front(); my_queue.pop();
		temp_x = temp / RECT_SIZE;
		temp_y = temp % RECT_SIZE;

		new_x = temp_x, new_y = temp_y + 1;
		if (new_y < number_c && isdigit(input[new_x][new_y]) && !maze_temp_state[new_x][new_y] && !maze_state[new_x][new_y])
		{
			maze_temp_state[new_x][new_y] = true;
			temp_result.route[temp_result.length++] = input[new_x][new_y];
			my_queue.push(new_x * RECT_SIZE + new_y);
		}

		new_x = temp_x, new_y = temp_y - 1;
		if (new_y >= 0 && isdigit(input[new_x][new_y]) && !maze_temp_state[new_x][new_y] && !maze_state[new_x][new_y])
		{
			maze_temp_state[new_x][new_y] = true;
			temp_result.route[temp_result.length++] = input[new_x][new_y];
			my_queue.push(new_x * RECT_SIZE + new_y);
		}

		new_x = temp_x - 1, new_y = temp_y;
		if (new_x >= 0 && isdigit(input[new_x][new_y]) && !maze_temp_state[new_x][new_y] && !maze_state[new_x][new_y])
		{
			maze_temp_state[new_x][new_y] = true;
			temp_result.route[temp_result.length++] = input[new_x][new_y];
			my_queue.push(new_x * RECT_SIZE + new_y);
		}

		new_x = temp_x + 1, new_y = temp_y;
		if (new_x < number_r && isdigit(input[new_x][new_y]) && !maze_temp_state[new_x][new_y] && !maze_state[new_x][new_y])
		{
			maze_temp_state[new_x][new_y] = true;
			temp_result.route[temp_result.length++] = input[new_x][new_y];
			my_queue.push(new_x * RECT_SIZE + new_y);
		}
	}

	return temp_result.length;
}

//!DFS
void DFS(int x, int y)
{
	if (isdigit(input[x][y]) && !maze_state[x][y])
	{
		//!计算
		maze_state[x][y] = true;  cur_result.route[cur_result.length++] = input[x][y];

		if (x < number_r && y + 1 < number_c)	
		{
			int length = GetLength(x, y + 1);
			if(cur_result.length + length < max_result.length)
			{

			}
			else if (cur_result.length + length == max_result.length)
			{
				std::sort(temp_result.route, temp_result.route + temp_result.length);
				tmp_result = cur_result;
				for(int i = temp_result.length - 1; i >= 0; --i) tmp_result.route[tmp_result.length++] = temp_result.route[i];
				if(tmp_result < max_result)
				{

				}
				else
				{
					DFS(x, y + 1);
				}
			}
			else
			{
				DFS(x, y + 1);
			}
		}

		if (x < number_r && y - 1 < number_c && y - 1 >= 0)
		{
			int length = GetLength(x, y - 1);
			if(cur_result.length + length < max_result.length)
			{

			}
			else if (cur_result.length + length == max_result.length)
			{
				std::sort(temp_result.route, temp_result.route + temp_result.length);
				tmp_result = cur_result;
				for(int i = temp_result.length - 1; i >= 0; --i) tmp_result.route[tmp_result.length++] = temp_result.route[i];
				if(tmp_result < max_result)
				{

				}
				else
				{
					DFS(x, y - 1);
				}
			}
			else
			{
				DFS(x, y - 1);
			}
		}

		if (x - 1 < number_r && y < number_c && x - 1 >= 0)
		{
			int length = GetLength(x - 1, y);
			if(cur_result.length + length < max_result.length)
			{

			}
			else if (cur_result.length + length == max_result.length)
			{
				std::sort(temp_result.route, temp_result.route + temp_result.length);
				tmp_result = cur_result;
				for(int i = temp_result.length - 1; i >= 0; --i) tmp_result.route[tmp_result.length++] = temp_result.route[i];
				if(tmp_result < max_result)
				{

				}
				else
				{
					DFS(x - 1, y);
				}
			}
			else
			{
				DFS(x - 1, y);
			}
		}

		if (x + 1 < number_r && y < number_c)
		{
			int length = GetLength(x + 1, y);
			if(cur_result.length + length < max_result.length)
			{

			}
			else if (cur_result.length + length == max_result.length)
			{
				std::sort(temp_result.route, temp_result.route + temp_result.length);
				tmp_result = cur_result;
				for(int i = temp_result.length - 1; i >= 0; --i) tmp_result.route[tmp_result.length++] = temp_result.route[i];
				if(tmp_result < max_result)
				{

				}
				else
				{
					DFS(x + 1, y);
				}
			}
			else
			{
				DFS(x + 1, y);
			}
			
		}

		if (max_result < cur_result) max_result = cur_result;
		maze_state[x][y] = false; cur_result.length--;
	}
}

//!程序入口
int main(int argc, const char* argv[])
{
	while (scanf("%d%d", &number_r, &number_c) != EOF && (number_r + number_c))
	{
		//!读取输入
		memset(input, 0, sizeof(input));
		memset(maze_state, 0, sizeof(maze_state));
		for (int i = 0; i < number_r; ++i) scanf("%s", input + i);
		cur_result.Clear(); max_result.Clear();

		//!计算
		for (int i = 0; i < number_r; ++i)
		{
			for (int j = 0; j < number_c; ++j)
			{
				DFS(i, j);
			}
		}

		//!显示结果
		max_result.Print();
	}

	//!返回系统
	return 0;
}