/**
 *  author : Tiger
 *  date   : 2018-4-4 17:37:27
 *  brief  : 使用32位程序启动64位进程
 */
using System;

namespace Create64Process_20180404_1
{
    class Program
    {
        static void Main(string[] args)
        {
            System.Diagnostics.Process process = new System.Diagnostics.Process();
            process.StartInfo.WorkingDirectory = @"../../";
            process.StartInfo.FileName = "../../Test.exe";
            process.StartInfo.UseShellExecute = false;
            process.StartInfo.RedirectStandardInput = false;
            process.StartInfo.RedirectStandardOutput = false;
            process.StartInfo.RedirectStandardError = true;
            process.StartInfo.CreateNoWindow = true;
            process.Start();
            process.WaitForExit();

            Console.WriteLine("Done!!");
            Console.ReadLine();
        }
    }
}