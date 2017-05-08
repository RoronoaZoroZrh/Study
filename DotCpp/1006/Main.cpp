/********************************************************************
@file     Main.cpp
@date     2017-05-07
@author   Zoro_Tiger
@brief    ���� 1006: C���Գ�����ƽ̳̣������棩�κ�ϰ��5.4
          http://www.dotcpp.com/oj/problem1006.html
********************************************************************/
//!ͷ�ļ�
#include <cstdio>
#include <algorithm>

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

	int nA = 0, nB = 0, nC = 0;
	while (scanf("%d%d%d", &nA, &nB, &nC) != EOF)
	{
		printf("%d\n", std::max(std::max(nA, nB), nC));
	}

	return 0;
}