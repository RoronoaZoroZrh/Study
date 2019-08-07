/*
 *  author    : Zoro
 *  date      : 2018-10-19 09:58:55
 *  brief     : 获取指定目录今日修改CSharp文件列表
 *  conclusion: 
 */
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;

namespace GetFileTime_20181019_1
{
    class Program
    {
        static void Main(string[] args)
        {
            //Input
            Console.Write("Input:");
            string input = Console.ReadLine();

            //获取文件时间
            if (Directory.Exists(input))
            {
                Dictionary<string, DateTime> result = new Dictionary<string, DateTime>();
                foreach (FileInfo fileInfo in new DirectoryInfo(input).GetFiles("*.cs", SearchOption.AllDirectories))
                {
                    if (fileInfo.LastAccessTime.Month == DateTime.Now.Month &&
                        fileInfo.LastAccessTime.Day >= DateTime.Now.Day)
                    {
                        result.Add(fileInfo.FullName, fileInfo.LastAccessTime);
                    }
                }
                using (StreamWriter writer = new StreamWriter(@"D:\result.txt"))
                {
                    foreach (var itr in result)
                    {
                        writer.WriteLine(string.Format("File:{0}, Time:{1}", itr.Key, itr.Value));
                    }
                }
                Process.Start(@"D:\result.txt");
            }

            //结束
            Console.WriteLine("Done!");
        }
    }
}