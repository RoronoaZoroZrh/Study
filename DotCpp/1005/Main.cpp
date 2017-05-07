/********************************************************************
@file     Main.cpp
@date     2017-05-07
@author   Zoro_Tiger
@brief    ���� 1005: C���Գ�����ƽ̳̣������棩�κ�ϰ��4.9
          http://www.dotcpp.com/oj/problem1005.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>

//!�궨��
#define TEST
#undef  TEST

//!�������
int main(int argc, const char* argv[])
{

#ifdef TEST
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	float fIn = 0.0f;
	while (scanf("%f", &fIn) != EOF)
	{
		float fOut = 5 * (fIn - 32) / 9;
		printf("c=%.2f\n", fOut);
	}

	return 0;
}