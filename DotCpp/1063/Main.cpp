/********************************************************************
@file     Main.cpp
@date     2017-6-28 10:22:37
@author   Zoro_Tiger
@brief    ���� 1063: C��������-ͳ���ַ�
          http://www.dotcpp.com/oj/problem1063.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

//!�������
int main(int argc, const char* argv[])
{
	//!��������
	std::string input = "";

	//!��ȡ����
	getline(std::cin, input);

	//!ͳ�Ƹ��ַ�����
	int alpha_count = std::count_if(input.begin(), input.end(), isalpha);
	int space_count = std::count_if(input.begin(), input.end(), isspace);
	int digit_count = std::count_if(input.begin(), input.end(), isdigit);

	//!������
	printf("%d\n%d\n%d\n%d\n", alpha_count, space_count, digit_count, input.size() - alpha_count - space_count - digit_count);
	
	//!����ϵͳ
	return 0;
}