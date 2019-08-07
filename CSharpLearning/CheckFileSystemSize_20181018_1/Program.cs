/*
 *  author    : Zoro
 *  date      : 2018-10-18 10:28:04
 *  brief     : 显示指定目录下文件和子目录的大小
 *  conclusion: 
 */
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace CheckFileSystemSize_20181018_1
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = "";
            do
            {
                //获取目录
                Console.Write("Input:");
                input = Console.ReadLine();

                //获取文件和子目录大小
                Dictionary<String, long> tempOutput = new Dictionary<string, long>();
                if (System.IO.Directory.Exists(input))
                {
                    using (StreamWriter writer = new StreamWriter(@"D:\result.txt"))
                    {
                        //子目录
                        writer.WriteLine("----------------------子目录----------------------");
                        tempOutput.Clear();
                        foreach (var itr in new DirectoryInfo(input).GetDirectories())
                        {
                            tempOutput.Add(itr.Name, itr.GetFiles("*", SearchOption.AllDirectories).Sum(fileInfo => fileInfo.Length));
                        }
                        tempOutput = tempOutput.OrderBy(pair => pair.Value).ToDictionary(k => k.Key, v => v.Value);
                        foreach (var itr in tempOutput)
                        {
                            writer.WriteLine(string.Format("目录:{0}, 大小:{1}MB", itr.Key, itr.Value / 1024 / 1024));
                        }

                        //子文件
                        writer.WriteLine("----------------------子文件----------------------");
                        tempOutput.Clear();
                        foreach (var itr in new DirectoryInfo(input).GetFiles())
                        {
                            tempOutput.Add(itr.Name, itr.Length);
                        }
                        tempOutput = tempOutput.OrderBy(pair => pair.Value).ToDictionary(k => k.Key, v => v.Value);
                        foreach (var itr in tempOutput)
                        {
                            writer.WriteLine(string.Format("文件:{0}, 大小:{1}MB", itr.Key, itr.Value / 1024 / 1024));
                        }

                        //结束
                        writer.WriteLine("-------------------------------------------------");
                        Process.Start(@"D:\result.txt");
                    }
                }
            } while (input != "exit");
        }
    }
}