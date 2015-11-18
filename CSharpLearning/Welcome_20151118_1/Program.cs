/**
 *  author : Tiger
 *  date   : 2015-11-18 20:38:36
 *  brief  : 在标准输出设备上打印欢迎信息
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
            Console.WriteLine("Welcome to you, {0}!", Console.ReadLine());

            //读取行，使程序不会立刻退出
            Console.ReadLine();
        }
    }
}