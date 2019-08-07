/**
 *  author : Tiger
 *  date   : 2019-4-4 18:16:14
 *  brief  : Floyd最短路径算法
 */
using System;

namespace Floyd_20190404_1
{
    public class Program
    {
        public static void Main(String[] args)
        {
            Int32[,] tarResult = new Int32[4, 4]; //存储结果
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                {
                    if (i == j)
                        tarResult[i, j] = 0;
                    else
                        tarResult[i, j] = Int32.MaxValue;
                }
            tarResult[0, 2] = 4;
            tarResult[0, 3] = 2;
            tarResult[2, 1] = 2;
            tarResult[3, 2] = 1;
            tarResult[3, 1] = 4;

            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    for (int k = 0; k < 4; ++k)
                    {
                        if (tarResult[j, i] != Int32.MaxValue &&
                            tarResult[i, k] != Int32.MaxValue &&
                            tarResult[j, k] > tarResult[j, i] + tarResult[i, k])
                        {
                            tarResult[j, k] = tarResult[j, i] + tarResult[i, k];
                            Console.WriteLine(String.Format("i={0} j={1} k={2} result={3}", i, j, k, tarResult[j, k]));
                        }
                    }

            for (int i = 0; i < 4; ++i)
            {
                for (int j = 0; j < 4; ++j)
                {
                    Console.Write(tarResult[i, j] + " ");
                }
                Console.WriteLine();
            }
            Console.ReadLine();
        }
    }
}