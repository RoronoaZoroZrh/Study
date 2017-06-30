/********************************************************************
@file     Main.cpp
@date     2017-6-30 09:44:39
@author   Zoro_Tiger
@brief    ���� 1074: ��������
          http://www.dotcpp.com/oj/problem1074.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>

//!�������
int main(int argc, const char* argv[])
{
	//!��������
	std::string input = "";

	//!��ȡ���벢����
	while (getline(std::cin, input) && input != "0")
	{
		int temp = 0;
		for (int i = 0; i < input.size(); ++i) //!�ܱ��������Ƿ��ܱ�ĳ������
		{
			temp = (temp * 10 + (input.at(i) - '0')) % 17;
		}
		printf("%d\n", (temp == 0 ? 1 : 0));
	}
	
	//!����ϵͳ
	return 0;
}