/********************************************************************
@file     Main.cpp
@date     2017-05-29 12:55:07
@author   Zoro_Tiger
@brief    ���� 1043: C���Գ�����ƽ̳̣������棩�κ�ϰ��10.1
          http://www.dotcpp.com/oj/problem1043.html
********************************************************************/
#include <cstdio>
#include <algorithm>
#include <vector>

#define TEST
#undef  TEST
#define VEC_SIZE 3

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	//!����
	std::vector<int> vec(VEC_SIZE);
	for (int i = 0; i < VEC_SIZE; ++i)
	{
		scanf("%d", &vec[i]);
	}

	//!����
	std::sort(vec.begin(), vec.end());

	//!���
	for (int i = 0; i < VEC_SIZE; ++i)
	{
		printf("%d ", vec[i]);
	}

	return 0;
}