/*
 *  author    : Zoro
 *  date      : 2018-1-19 14:53:06
 *  brief     : 查看StringBuilder用null构造的情况
 *  conclusion: 用null构造后StringBuilder为""
 */
using System;
using System.Text;

namespace StringBuilder_20180119_1
{
    class Program
    {
        static void Main(string[] args)
        {
            //!构造
            StringBuilder sTestStr = new StringBuilder(null);

            //!检查值
            String sExpectResult = "";
            String sActualResult = sTestStr.ToString();

            //!显示信息
            Console.WriteLine(sExpectResult == sActualResult);

            //!测试结束
            Console.WriteLine("示例结束...");
            Console.ReadLine();
        }
    }
}