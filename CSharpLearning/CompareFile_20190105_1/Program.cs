/*
 *  author    : Zoro
 *  date      : 2019-1-5 10:41:24
 *  brief     : 查看目录中新添加的文件
 *  conclusion: 
 */
using System;
using System.Collections.Generic;
using System.IO;

namespace CompareFile_20190105_1
{
    public class Program
    {
        static void Main(string[] args)
        {
            List<FileInfo> orgFiles = GetFileInfos(new DirectoryInfo(GetInput("原始目录")));
            List<FileInfo> tarFiles = GetFileInfos(new DirectoryInfo(GetInput("目标目录")));

            Dictionary<String, FileInfo> filesDic = new Dictionary<String, FileInfo>();
            tarFiles.ForEach(tarFile => filesDic.Add(tarFile.FullName, tarFile));

            foreach (FileInfo itr in orgFiles)
            {
                foreach (FileInfo subItr in tarFiles)
                {
                    if (subItr.Name == itr.Name)
                    {
                        filesDic.Remove(subItr.FullName);
                        break;
                    }
                }
            }

            Console.WriteLine("新添加文件如下:");
            Directory.CreateDirectory("D:\\Output\\");
            foreach (string filePath in filesDic.Keys)
            {
                Console.WriteLine(filePath);
                try
                {
                    File.Copy(filePath, "D:\\Output\\" + Path.GetFileName(filePath));
                }
                catch (Exception)
                {
                    Console.WriteLine(String.Format("File Copy Failed! {0}", filePath));
                }
            }
            Console.ReadLine();
        }

        public static String GetInput(string label)
        {
            Console.Write(String.Format("{0}:", label));
            return Console.ReadLine();
        }

        public static List<FileInfo> GetFileInfos(DirectoryInfo directoryInfo)
        {
            List<FileInfo> fileInfos = new List<FileInfo>();
            foreach (FileInfo fileInfo in directoryInfo.GetFiles("*.cs", SearchOption.AllDirectories))
                fileInfos.Add(fileInfo);
            return fileInfos;
        }
    }
}