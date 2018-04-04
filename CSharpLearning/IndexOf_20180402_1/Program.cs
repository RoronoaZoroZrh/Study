/*
 *  author : Zoro
 *  date   : 2018-4-2 10:17:21
 *  brief  : 查看IndexOf属性
 */
using System;
using System.Collections.Generic;

namespace IndexOf_20180402_1
{
    class Program
    {
        static void Main(string[] args)
        {
            //!测试容器
            List<String> vTestList = new List<String> { "11", "33", "22" };

            //!调用方法IndexOf
            int nIndex = vTestList.IndexOf("22");

            //!显示结果
            Console.WriteLine(nIndex);

            //!结束示例
            Console.WriteLine("Done!!");
            Console.ReadLine();
        }
    }
}