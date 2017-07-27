/**
 *  author : Zoro_Tiger
 *  date   : 2017-7-27 18:35:48
 *  brief  : 检查未完成的工作
 */
using System;
using System.IO;
using System.Text;

namespace File_Operation_20170727_1
{
    class Program
    {
        public static void Main(string[] args)
        {
            Console.Write("文件名称：");
            String localFilePath = Console.ReadLine().Trim('\"');
            if (File.Exists(localFilePath))
            {
                String localUndoThings = String.Empty;
                using (StreamReader sr = new StreamReader(localFilePath, Encoding.Default))
                {
                    while (!sr.EndOfStream)
                    {
                        String localLine = sr.ReadLine();
                        if (String.IsNullOrWhiteSpace(localLine))
                        {
                            continue;
                        }
                        else
                        {
                            if (!localLine.Contains("(完成"))
                            {
                                localUndoThings = localUndoThings + localLine + Environment.NewLine;
                            }
                        }
                    }
                }

                //!显示信息
                Console.WriteLine("----------------------------------------------------------------");
                if (String.IsNullOrWhiteSpace(localUndoThings))
                {
                    Console.WriteLine("所有事情已完成...");
                }
                else
                {
                    Console.WriteLine(localUndoThings.TrimEnd(Environment.NewLine.ToCharArray()));
                }
                Console.WriteLine("----------------------------------------------------------------");
                Console.ReadLine();
            }
        }
    }
}