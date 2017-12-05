/*
 *  author : Zoro
 *  date   : 2017-12-5 11:01:51
 *  brief  : 访问网站过程中的异常处理
 */
using System.IO;
using System.Net;

namespace System.Net_20171205_1
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                //!创建WebRequest
                HttpWebRequest vRequest = (HttpWebRequest)WebRequest.Create("https://www.baidu.com");

                //!发动请求、获取WebResponse
                HttpWebResponse vResponse = (HttpWebResponse)vRequest.GetResponse();

                //!获取响应流
                Stream vStream = vResponse.GetResponseStream();
                int nInput = int.MinValue;
                while ((nInput = vStream.ReadByte()) != -1) //!读取到-1表示读取到文件尾
                {
                    Console.Write((char)nInput);
                }
            }
            catch (WebException vWebException)
            {
                Console.WriteLine("NetWork Error:" + vWebException.Message + "\nStatus Code:" + vWebException.Status);
            }
            catch (Exception vException)
            {
                Console.WriteLine("Message:" + vException.Message + "\nTrace:" + vException.StackTrace);
            }

            //!结束示例
            Console.WriteLine("\nDone!");
            Console.ReadLine();
        }
    }
}