/********************************************************************
@file     Main.cpp
@date     2017-5-26 09:36:10
@author   Zoro_Tiger
@brief    ���� 1031: C���Գ�����ƽ̳̣������棩�κ�ϰ��8.5
          http://www.dotcpp.com/oj/problem1031.html
********************************************************************/
#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>

#define TEST
#undef  TEST

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	std::string input = "";
	while (std::cin >> input) //!����
	{
		//!ת�á�������
		//std::reverse(input.begin(), input.end());

		//!���
		for (int i = input.size() - 1; i >= 0; --i)
		{
			printf("%c", input[i]);
		}
		printf("\n");
	}

	return 0;
}