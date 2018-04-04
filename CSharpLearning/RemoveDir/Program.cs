/*
 *  author : Zoro
 *  date   : 2018-3-30 11:22:23
 *  brief  : 删除目录
 */
using System;
using System.IO;

namespace RemoveDir
{
    class Program
    {
        static void Main(string[] args)
        {
            DirectoryInfo vDirInfo = new DirectoryInfo(".");
            foreach (DirectoryInfo vDirInfoItr in vDirInfo.GetDirectories())
            {
                Console.WriteLine("Delete " + vDirInfoItr.FullName);

                System.Diagnostics.Process p = new System.Diagnostics.Process();
                p.StartInfo.FileName = "cmd.exe";
                p.StartInfo.UseShellExecute = false;
                p.StartInfo.RedirectStandardInput = true;
                p.StartInfo.RedirectStandardOutput = true;
                p.StartInfo.RedirectStandardError = true;
                p.StartInfo.CreateNoWindow = true;
                p.Start();
                p.StandardInput.WriteLine("rmdir " + vDirInfoItr.FullName + "/s /q");
                p.StandardInput.AutoFlush = true;
            }

            Console.WriteLine("Done!!");
            Console.ReadLine();
        }
    }
}