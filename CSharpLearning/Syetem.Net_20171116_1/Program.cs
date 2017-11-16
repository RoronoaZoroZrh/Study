/*
 *  author : Zoro
 *  date   : 2017-11-16 19:29:26
 *  brief  : 访问网站
 */
using System;
using System.IO;
using System.Net;

namespace Syetem.Net_20171116_1
{
    class Program
    {
        static void Main(string[] args)
        {
            //!创建WebRequest
            HttpWebRequest vRequest = (HttpWebRequest)WebRequest.Create("https://www.baidu.com");
            if (null == vRequest)
            {
                return;
            }

            //!创建WebResponse
            HttpWebResponse vResponse = (HttpWebResponse)vRequest.GetResponse();
            if (null == vResponse)
            {
                return;
            }

            //!获取输入流
            Stream vStream = vResponse.GetResponseStream();
            int nInput = int.MinValue;
            while ((nInput = vStream.ReadByte()) != -1)
            {
                Console.Write((char)nInput);
            }

            //!结束示例
            Console.WriteLine("Done!");
            Console.ReadLine();
        }
    }
}