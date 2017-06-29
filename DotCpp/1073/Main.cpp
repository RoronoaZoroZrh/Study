/********************************************************************
@file     Main.cpp
@date     2017-5-8
@author   Zoro_Tiger
@brief    ���� 1073: �ܵܵ���ҵ
          http://www.dotcpp.com/oj/problem1073.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <string>

//!�������
int main(int argc, const char* argv[])
{
	//!��������
	int right_answer_count = 0, number_a, number_b, number_c, number_result;
	char oper;
	std::string result;

	//!ͳ����ȷ�𰸸���
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

	//!��ʾ���
	printf("%d\n", right_answer_count);

	//!����ϵͳ
	return 0;
}