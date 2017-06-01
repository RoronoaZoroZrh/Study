/********************************************************************
@file     Main.cpp
@date     2017-06-01 10:06:55
@author   Zoro_Tiger
@brief    问题 1046: C语言程序设计教程（第三版）课后习题10.4
          http://www.dotcpp.com/oj/problem1046.html
********************************************************************/
#include <cstdio>
#include <vector>

#define TEST
#undef  TEST

class MyQueue
{

public:

	MyQueue(int queue_size)
	{
		m_begin = 0;
		m_queue_size = queue_size;
		m_vec.clear();
		//m_vec.swap(std::vector<int>());
	}

	void GetInput(void)
	{
		int input = 0;
		for (int i = 0; i < m_queue_size; ++i)
		{
			scanf("%d", &input);
			m_vec.push_back(input);
		}
	}

	void ChangeBegin(int begin_index)
	{
		m_begin = m_queue_size - begin_index;
	}

	void Output()
	{
		int index = m_begin;
		for (int i = 0; i < m_queue_size; ++i)
		{
			index = m_begin + i;
			if (index >= m_queue_size)
			{
				index %= m_queue_size;
			}
			printf("%d ", m_vec[index]);
		}
		printf("\n");
	}

private:

	int m_begin;
	int m_queue_size;
	std::vector<int> m_vec;

};

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int queue_size = 0;
	scanf("%d", &queue_size);

	MyQueue my_queue(queue_size);
	my_queue.GetInput();

	int begin_index = 0;
	scanf("%d", &begin_index);
	my_queue.ChangeBegin(begin_index);

	my_queue.Output();

	return 0;
}