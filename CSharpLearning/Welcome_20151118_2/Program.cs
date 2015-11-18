/**
 *  author : Tiger
 *  date   : 2015-11-18 20:54:14
 *  brief  : 在标准输出设备上打印欢迎信息、演示字符串拼接功能
 */
using System;

namespace Welcome
{
    class Program
    {
        static void Main(string[] args)
        {
            //在标准输出设备上打印欢迎信息
            Console.Write("Please enter your name:");
            Console.WriteLine("Welcome to you, " + Console.ReadLine() + "!");

            //读取行，以防止程序立刻退出
            Console.ReadLine();
        }
    }
}