/********************************************************************
@file     Main.cpp
@date     2017-5-27 09:24:00
@author   Zoro_Tiger
@brief    ���� 1035: C���Գ�����ƽ̳̣������棩�κ�ϰ��8.9
          http://www.dotcpp.com/oj/problem1035.html
********************************************************************/
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>

#define TEST
#undef  TEST

int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	//!����
	std::string input = "";
	getline(std::cin, input);

	//!ͳ��
	int digit_num = std::count_if(input.begin(), input.end(), isdigit);
	int space_num = std::count_if(input.begin(), input.end(), isspace);
	int alpha_num = std::count_if(input.begin(), input.end(), isalpha);

	//!���
	printf("%d %d %d %d \n", alpha_num, digit_num, space_num, (input.size() - alpha_num - digit_num - space_num));

	return 0;
}