/********************************************************************
@file     Main.cpp
@date     2017-4-26
@author   Zoro_Tiger
@brief    ���� 1000: �򵥵�a+b
          http://www.dotcpp.com/oj/problem1000.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>

//!�궨��
#define TEST
#undef  TEST

//!�������
int main(int argc, const char* argv[])
{

#ifdef TEST //!���ļ���ȡ����
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	//!����������֮��
	int number_a = 0, number_b = 0;
	while (scanf("%d%d", &number_a, &number_b) != EOF)
	{
		printf("%d\n", number_a + number_b);
	}

	return 0;
}