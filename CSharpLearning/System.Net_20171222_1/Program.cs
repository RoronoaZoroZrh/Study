/*
 *  author : Zoro
 *  date   : 2017-12-22 09:34:36
 *  brief  : 查看Uri的字段和属性
 */
using System;

namespace System.Net_20171222_1
{
    class Program
    {
        static void Main(string[] args)
        {
            //!创建Uri
            Uri vUri = new Uri("https://www.baidu.com/s?cl=3&tn=baidutop10&fr=top1000&wd=%E8%83%A1%E6%AD%8C%E8%B7%AA%E5%9C%B0%E7%AD%BE%E5%90%8D&rsv_idx=2");

            //!服务器
            Console.WriteLine("Host: " + vUri.Host);

            //!端口号
            Console.WriteLine("Port: " + vUri.Port.ToString());

            //!协议
            Console.WriteLine("Scheme: " + vUri.Scheme);

            //!本地文件路径
            Console.WriteLine("Local Path: " + vUri.LocalPath);

            //!查询字符串
            Console.WriteLine("Query: " + vUri.Query);

            //!本地文件路径和查询字符串
            Console.WriteLine("Local Path And Query: " + vUri.PathAndQuery);

            //!示例结束
            Console.WriteLine("Done!");
            Console.ReadLine();
        }
    }
}