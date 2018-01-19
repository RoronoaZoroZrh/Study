/*
 *  author    : Zoro
 *  date      : 2018-1-19 15:36:17
 *  brief     : 查看Directory检查null参数的情况
 *  conclusion: Directory使用null参数不会出现异常
 */
using System;
using System.IO;

namespace DirectoryExists_20180119_1
{
    class Program
    {
        static void Main(string[] args)
        {
            //!使用null作为参数
            Boolean bExpectResult = true;
            Boolean bActualResult = true;
            try
            {
                Directory.Exists(null);
            }
            catch (Exception)
            {
                bActualResult = false;
            }

            //!显示信息
            Console.WriteLine(bExpectResult == bActualResult);

            //!结束
            Console.WriteLine("示例结束...");
            Console.ReadLine();
        }
    }
}
