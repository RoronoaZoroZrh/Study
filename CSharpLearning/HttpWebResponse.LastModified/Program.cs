/*
 *  author : Zoro
 *  date   : 2018-3-27 10:33:13
 *  brief  : 查看类HttpWebResponse的LastModified属性
 */
using System;
using System.Net;

namespace _HttpWebResponse.LastModified
{
    class Program
    {
        static void Main(string[] args)
        {
            //!测试资源
            String sTestUrl = "https://www.baidu.com/";

            //!请求
            HttpWebRequest vRequest = (HttpWebRequest)WebRequest.Create(sTestUrl);

            //!响应
            HttpWebResponse vResponse = (HttpWebResponse)vRequest.GetResponse();

            //!显示属性LastModified
            Console.WriteLine("LastModified = " + vResponse.LastModified.ToString());

            //!示例结束
            Console.WriteLine("Sample Done!");
            Console.ReadLine();
        }
    }
}