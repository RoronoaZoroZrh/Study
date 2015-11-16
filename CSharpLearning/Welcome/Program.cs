/**
 *  author : Tiger
 *  date   : 2015-11-16 20:29:29
 *  brief  : 在标准输出上打出欢迎信息
 */
using System;

class Welcome
{
    static void Main(String[] args)
    {
        //在标准输出上打出欢迎信息
        Console.Write("Please enter your name:");
        Console.ReadLine();
        Console.WriteLine("Welcome to you!");

        //读取行，使程序不会立刻退出
        Console.ReadLine();
    }
}