/*
 *  author : Zoro
 *  date   : 2017-12-8 17:21:53
 *  brief  : 使用StreamReader读取文件
 */
using System;
using System.IO;
using System.Linq;
using System.Text;

namespace StreamReader_20171208_1
{
    class Program
    {
        static void Main(string[] args)
        {
            //!文件
            String sFileName = @"..\..\hailang.uir";
            if (!File.Exists(sFileName))
            {
                Console.WriteLine("File Don't Exist:" + sFileName);
                return;
            }

            //!读取文件
            using (StreamReader vReader = new StreamReader(sFileName, Encoding.Default))
            {
                while (!vReader.EndOfStream)
                {
                    String sLine = vReader.ReadLine().Trim();
                    Console.WriteLine(sLine + ":" + sLine.Split(' ').Count().ToString());
                }
            }

            //!结束示例
            Console.WriteLine("Done!");
            Console.ReadLine();
        }
    }
}