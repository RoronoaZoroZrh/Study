/**
 *  author : Tiger
 *  date   : 2016-02-18 06:17:33
 *  brief  : 整数运算
 */
using System;

namespace Integer
{
    class Program
    {
        static void Main(string[] args)
        {
            //整数运算
            short nTestInteger = 32766;
            ++nTestInteger;
            Console.WriteLine(nTestInteger);
            ++nTestInteger;
            Console.WriteLine(nTestInteger);

            //读取行，以防止程序立刻退出
            Console.ReadLine();
        }
    }
}