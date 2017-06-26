/********************************************************************
@file     Main.cpp
@date     2017-6-26 13:20:08
@author   Zoro_Tiger
@brief    ���� 1055: C��������-����ת��
          http://www.dotcpp.com/oj/problem1055.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <cmath>

//!��������
void Octal(int number);

//!�������
int main(int argc, const char* argv[])
{
	//!�������
	int number = 0;
	
	//!��ȡ����
	scanf("%d", &number);

	//!��������
	Octal(number);

	return 0;
}

//!��ָ������ת���ɰ˽���
void Octal(int number)
{
	if (number != 0)
	{
		Octal(number / 8);
		printf("%d", number % 8);
	}
}