/**
 *  author : Tiger
 *  date   : 2017-3-16 09:50:36
 *  brief  : 冒泡排序
 */
using System;
using System.Collections.Generic;

namespace BubSort
{
    public class Program
    {
        //!程序入口
        public static void Main(string[] args)
        {
            //!冒泡排序
            List<int> list = new List<int> { 5, 4, 3, 1, 2 };
            for (int i = 0; i < list.Count - 1; i++)
            {
                Boolean bSort = true;
                for (int j = 0; j < list.Count - 1 - i; j++)
                {
                    if (list[j + 1] < list[j])
                    {
                        list[j + 1] ^= list[j];
                        list[j] ^= list[j + 1];
                        list[j + 1] ^= list[j];
                        bSort = false;
                    }
                }
                if (bSort)
                {
                    break;
                }
            }

            //!显示结果
            foreach (int iter in list)
            {
                Console.WriteLine(iter.ToString());
            }
            Console.ReadLine();
        }
    }
}