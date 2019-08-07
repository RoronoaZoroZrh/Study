/********************************************************************
@file     Main.cpp
@date     2019-5-9 10:06:33
@author   Zoro_Tiger
@brief    问题 1078: Repairing a Road
		  https://www.dotcpp.com/oj/problem1078.html
@detail   https://www.cnblogs.com/oyking/p/3278741.html
********************************************************************/
#include <cmath>
#include <cstdio>

#define EPS 1E-6
#define MAX_VALUE 1E+6
#define VERTEX_MAX_SIZE 100

double Cost[VERTEX_MAX_SIZE][VERTEX_MAX_SIZE];
double Coef[VERTEX_MAX_SIZE][VERTEX_MAX_SIZE];

inline void Min(double& lValue, const double& rValue) { if (lValue > rValue) lValue = rValue; }

int main(int argc, const char* argv[])
{
	int verCnt, edgeCnt;
	while (scanf("%d %d", &verCnt, &edgeCnt) != EOF)
	{
		//结束用例
		if (verCnt == 0 && edgeCnt == 0)
			break;

		//初始化
		for (int i = 0; i < verCnt; ++i)
		{
			for (int j = 0; j < verCnt; ++j)
			{
				Coef[i][j] = 0.0f;
				Cost[i][j] = MAX_VALUE;
			}
			Cost[i][i] = 0.0f;
		}

		//读取数据
		int verIndex1, verIndex2;
		double cost, coef;
		for (int i = 0; i < edgeCnt; ++i)
		{
			scanf("%d %d %lf %lf", &verIndex1, &verIndex2, &cost, &coef);
			Cost[verIndex1 - 1][verIndex2 - 1] = Cost[verIndex2 - 1][verIndex1 - 1] = cost;
			Coef[verIndex1 - 1][verIndex2 - 1] = Coef[verIndex2 - 1][verIndex1 - 1] = coef;
		}

		//Floyd
		for (int i = 0; i < verCnt; ++i)
			for (int j = 0; j < verCnt; ++j)
				for (int k = 0; k < verCnt; ++k)
					Min(Cost[j][k], Cost[j][i] + Cost[i][k]);

		//计算花费
		double final_cost = Cost[0][verCnt - 1];
		for (int i = 0; i < verCnt; ++i)
			for (int j = 0; j < verCnt; ++j)
			{
				if (Coef[i][j] > EPS)
				{
					double lValue = Cost[0][i], rValue = final_cost, mValue, checkValue;
					if (lValue < rValue)
					{
						while (rValue - lValue > EPS)
						{
							mValue = (lValue + rValue) / 2.0f;
							checkValue = 1 - log(Coef[i][j]) * Cost[i][j] * pow(Coef[i][j], 0 - mValue);
							if (checkValue > EPS)
								rValue = mValue;
							else
								lValue = mValue;
						}
						Min(final_cost, lValue + Cost[j][verCnt - 1] + Cost[i][j] * pow(Coef[i][j], 0 - lValue));
					}
				}
			}
		printf("%.3f\n", final_cost);
	}
	return 0;
}