/*
 *  author : Zoro
 *  date   : 2017-12-25 09:34:36
 *  brief  : 查看响应报头
 */
using System;
using System.Net;

namespace Headers_20171225_1
{
    class Program
    {
        static void Main(string[] args)
        {
            //!请求
            HttpWebRequest vRequest = (HttpWebRequest)WebRequest.Create("http://www.McGraw-Hill.com");

            //!响应
            HttpWebResponse vResponse = (HttpWebResponse)vRequest.GetResponse();

            //!报头
            String[] vHeaders = vResponse.Headers.AllKeys;
            foreach (String sHeader in vHeaders)
            {
                Console.Write("{0, -20}", sHeader);
                foreach (String sValue in vResponse.Headers.GetValues(sHeader))
                {
                    Console.WriteLine(sValue);
                }
            }

            //!示例结束
            Console.WriteLine("Done!");
            Console.ReadLine();
        }
    }
}