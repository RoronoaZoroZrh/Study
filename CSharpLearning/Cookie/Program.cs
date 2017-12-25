/*
 *  author : Zoro
 *  date   : 2017-12-25 09:55:17
 *  brief  : 查看cookie
 */
using System;
using System.Net;

namespace Cookie_20171225_1
{
    class Program
    {
        static void Main(string[] args)
        {
            //!请求
            HttpWebRequest vRequest = (HttpWebRequest)WebRequest.Create("https://www.baidu.com/index.php?tn=monline_3_dg");
            vRequest.CookieContainer = new CookieContainer();

            //!响应
            HttpWebResponse vResponse = (HttpWebResponse)vRequest.GetResponse();

            //!cookie
            for (int i = 0; i < vResponse.Cookies.Count; i++)
            {
                Console.WriteLine("Name = {0}, Value = {1}", vResponse.Cookies[i].Name, vResponse.Cookies[i].Value);
            }
            vResponse.Close();

            //!示例结束
            Console.WriteLine("Sample Done!");
            Console.ReadLine();
        }
    }
}