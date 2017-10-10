using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.IO;
using System.Xml;

namespace Regex_20170927_1
{
    class Program
    {
        static void Main(string[] args)
        {
            //!匹配项
            Regex regex1 = new Regex("stlp_std::");
            Regex regex2 = new Regex("CLIENT");

            //!遍历文件
            StreamWriter sw = new StreamWriter("output.txt");
            String sDirName = "bodyaprt";
            DirectoryInfo dirInfo = new DirectoryInfo(sDirName);
            Queue<DirectoryInfo> dirQueue = new Queue<DirectoryInfo>();
            dirQueue.Enqueue(dirInfo);
            XmlDocument doc = new XmlDocument();
            while (dirQueue.Count > 0)
            {
                DirectoryInfo tempDirInfo = dirQueue.Dequeue();
                FileInfo[] tempFileArray = tempDirInfo.GetFiles("*.bpt");
                FileInfo[] tempFileArray1 = tempDirInfo.GetFiles("*.chr");

                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine("开始遍历" + tempDirInfo.FullName + "中文件...");
                Console.ForegroundColor = ConsoleColor.Red;

                for (int i = 0; i < tempFileArray.Count(); ++i)
                {
                    try
                    {
                        doc.Load(tempFileArray.ElementAt(i).FullName);
                    }
                    catch (Exception)
                    {
                        Console.WriteLine(tempFileArray.ElementAt(i).FullName);
                        sw.WriteLine(tempFileArray.ElementAt(i).FullName);
                        sw.Flush();
                    }


                    //                     using (StreamReader sr = new StreamReader(tempFileArray.ElementAt(i).FullName))
                    //                     {
                    //                         StringBuilder sTemp = new StringBuilder(sr.ReadToEnd());
                    //                         if (regex1.Match(sTemp.ToString()).Success ||
                    //                             regex2.Match(sTemp.ToString()).Success)
                    //                         {
                    //                             Console.WriteLine(tempFileArray.ElementAt(i).FullName);
                    //                             sw.WriteLine(tempFileArray.ElementAt(i).FullName);
                    //                             sw.Flush();
                    //                         }
                    //                     }
                }

                if (tempFileArray.Count() > 0)
                {
                    for (int i = 0; i < tempFileArray1.Count(); ++i)
                    {
                        if (tempFileArray1[i].Length > 5 * 1024)
                        {
                            Console.WriteLine(tempFileArray1.ElementAt(i).FullName);
                            sw.WriteLine(tempFileArray1.ElementAt(i).FullName);
                            sw.Flush();
                        }
                    }
                }

                DirectoryInfo[] tempDirArray = tempDirInfo.GetDirectories();
                for (int i = 0; i < tempDirArray.Count(); ++i)
                {
                    dirQueue.Enqueue(tempDirArray.ElementAt(i));
                }
            }

            //!结束
            sw.Close();
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("结束遍历!");
            Console.ReadLine();
        }
    }
}