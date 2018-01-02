/*
 *  author : Zoro
 *  date   : 2018-1-2 10:59:26
 *  brief  : 查找所有工程文件
 */
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace FindFile_20180102_1
{
    class Program
    {
        static void Main(string[] args)
        {
            //!查找工程文件
            Console.Write("工程目录：");
            String sDir = Console.ReadLine();
            String sPattern = "*.*proj";
            List<FileInfo> vResult = GetAllFiles(sDir, sPattern);

            //!查找文件
            sPattern = "AlienDll.vcxproj";
            List<FileInfo> vResult1 = GetAllFiles(vResult, sPattern);
            vResult1.ForEach(vFile => Console.WriteLine(vFile.FullName));

            //!记录内容
            StringBuilder vContent1 = new StringBuilder("引用工程" + Environment.NewLine);
            vResult1.ForEach(vFile => vContent1.Append(vFile.FullName + Environment.NewLine));
            WriteFile("result.txt", String.Join(Environment.NewLine, vContent1));

            //!查找文件
            sPattern = "AlienDll.dll";
            List<FileInfo> vResult2 = GetAllFiles(vResult, sPattern);
            vResult2.ForEach(vFile => Console.WriteLine(vFile.FullName));

            //!记录内容
            StringBuilder vContent2 = new StringBuilder("引用DLL" + Environment.NewLine);
            vResult2.ForEach(vFile => vContent2.Append(vFile.FullName + Environment.NewLine));
            WriteFile("result.txt", String.Join(Environment.NewLine, vContent2));

            //!示例结束
            Console.WriteLine("Done!");
            Console.ReadLine();
        }

        //!查找文件
        public static List<FileInfo> GetAllFiles(String sDir, String sPattern)
        {
            List<FileInfo> vResult = new List<FileInfo>();
            if (Directory.Exists(sDir))
            {
                Queue<DirectoryInfo> vSearchQueue = new Queue<DirectoryInfo>();
                vSearchQueue.Enqueue(new DirectoryInfo(sDir));
                while (vSearchQueue.Count > 0)
                {
                    DirectoryInfo vCurDirInfo = vSearchQueue.Dequeue();
                    Console.WriteLine("查找目录：" + vCurDirInfo.FullName);
                    foreach (FileInfo vFileInfo in vCurDirInfo.GetFiles(sPattern))
                    {
                        vResult.Add(vFileInfo);
                    }

                    foreach (DirectoryInfo vDirInfo in vCurDirInfo.GetDirectories())
                    {
                        if (vDirInfo.FullName.Contains(".svn")) continue;
                        vSearchQueue.Enqueue(vDirInfo);
                    }
                }
            }
            return vResult;
        }

        //!查找文件
        public static List<FileInfo> GetAllFiles(List<FileInfo> vFiles, String sPattern)
        {
            List<FileInfo> vResult = new List<FileInfo>();
            foreach (FileInfo vFile in vFiles)
            {
                using (StreamReader vReader = new StreamReader(vFile.FullName, Encoding.Default))
                {
                    String sContent = vReader.ReadToEnd();
                    if (sContent.Contains(sPattern))
                    {
                        vResult.Add(vFile);
                    }
                    vReader.Close();
                }
            }
            return vResult;
        }

        //!写入文件
        public static void WriteFile(String sFile, String sContent)
        {
            using (StreamWriter vWriter = new StreamWriter(sFile, true))
            {
                vWriter.WriteLine(sContent);
                vWriter.Close();
            }
        }
    }
}