/********************************************************************
@file     Main.cpp
@date     2017-5-8
@author   Zoro_Tiger
@brief    问题 1073: 弟弟的作业
          http://www.dotcpp.com/oj/problem1073.html
********************************************************************/
//!头文件
#include <cstdio>
#include <string>

//!程序入口
int main(int argc, const char* argv[])
{
	//!变量声明
	int right_answer_count = 0, number_a, number_b, number_c, number_result;
	char oper;
	std::string result;

	//!统计正确答案个数
	while (scanf("%d%c%d=%s", &number_a, &oper, &number_b, result.c_str()) != EOF)
	{
		number_c = (oper == '+' ? number_a + number_b : number_a - number_b);
		if (result != "?")
		{
			number_result = atoi(result.c_str());
			if (number_result == number_c)
			{
				++right_answer_count;
			}
		}
	}

	//!显示结果
	printf("%d\n", right_answer_count);

	//!返回系统
	return 0;
}