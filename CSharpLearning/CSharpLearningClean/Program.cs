/**
 *  author : Tiger
 *  date   : 2015-11-16 21:08:03
 *  brief  : 清理解决方案CSharpLearning生成的文件，运行解决方案根目录下该项目可执行文件才能正确运行
 */
using System;
using System.Diagnostics;
using System.IO;

namespace CSharpLearningClean
{
    class Program
    {
        static void Main(string[] args)
        {
            //关闭VS进程，否则某些文件被占用，导致文件无法删除
            foreach (Process process in Process.GetProcesses())
            {
                if (process.ProcessName == "devenv")
                {
                    process.Kill();
                }
            }
            System.Threading.Thread.Sleep(1 * 1000);

            //设置输出颜色
            Console.ForegroundColor = ConsoleColor.DarkGreen;

            //获取解决方案根目录
            String solutionRootDiretory = Environment.CurrentDirectory;

            //清理解决方案CSharpLearning生成的文件
            if (Directory.Exists(solutionRootDiretory))
            {
                //解决方案CSharpLearning根目录信息
                DirectoryInfo solutionRootDirInfo = new DirectoryInfo(solutionRootDiretory);

                //1.删除解决方案*.suo文件
                Console.WriteLine("删除解决方案*.suo文件开始...");
                foreach (FileInfo fileInfo in solutionRootDirInfo.GetFiles("*.suo"))
                {
                    Console.WriteLine("删除文件" + fileInfo.FullName);
                    fileInfo.Attributes = FileAttributes.Normal;
                    fileInfo.Delete();
                }
                Console.WriteLine("删除解决方案*.suo文件结束...");
                Console.WriteLine();

                //2.删除各个项目中bin、obj、Debug、Release目录，*.user文件
                Console.WriteLine("删除各个项目中bin、obj、Debug、Release目录开始...");
                foreach (DirectoryInfo dirInfo in solutionRootDirInfo.GetDirectories())
                {
                    //删除bin目录
                    String binDirectory = dirInfo.FullName + "\\bin\\";
                    if (Directory.Exists(binDirectory))
                    {
                        Console.WriteLine("删除目录" + binDirectory);
                        DirectoryInfo binDirInfo = new DirectoryInfo(binDirectory);
                        binDirInfo.Attributes = FileAttributes.Normal;
                        binDirInfo.Delete(true);
                    }

                    //删除obj目录
                    String objDirectory = dirInfo.FullName + "\\obj\\";
                    if (Directory.Exists(objDirectory))
                    {
                        Console.WriteLine("删除目录" + objDirectory);
                        DirectoryInfo objDirInfo = new DirectoryInfo(objDirectory);
                        objDirInfo.Attributes = FileAttributes.Normal;
                        objDirInfo.Delete(true);
                    }

                    //删除Debug目录
                    String debugDirectory = dirInfo.FullName + "\\Debug\\";
                    if (Directory.Exists(debugDirectory))
                    {
                        Console.WriteLine("删除目录" + debugDirectory);
                        DirectoryInfo debugDirInfo = new DirectoryInfo(debugDirectory);
                        debugDirInfo.Attributes = FileAttributes.Normal;
                        debugDirInfo.Delete(true);
                    }

                    //删除Release目录
                    String releaseDirectory = dirInfo.FullName + "\\Release\\";
                    if (Directory.Exists(releaseDirectory))
                    {
                        Console.WriteLine("删除目录" + releaseDirectory);
                        DirectoryInfo releaseDirInfo = new DirectoryInfo(releaseDirectory);
                        releaseDirInfo.Attributes = FileAttributes.Normal;
                        releaseDirInfo.Delete(true);
                    }

                    //删除*.user文件
                    foreach (FileInfo fileInfo in dirInfo.GetFiles("*.user"))
                    {
                        fileInfo.Attributes = FileAttributes.Normal;
                        fileInfo.Delete();
                    }
                }
                Console.WriteLine("删除各个项目中bin、obj、Debug、Release目录完成...");
                Console.WriteLine();

                //3.删除解决方案*.sdf文件
                Console.WriteLine("删除解决方案*.sdf文件开始...");
                foreach (FileInfo fileInfo in solutionRootDirInfo.GetFiles("*.sdf"))
                {
                    Console.WriteLine("删除文件" + fileInfo.FullName);
                    fileInfo.Attributes = FileAttributes.Normal;
                    fileInfo.Delete();
                }
                Console.WriteLine("删除解决方案*.sdf文件结束...");
                Console.WriteLine();

                //4.删除解决方案Debug目录
                Console.WriteLine("删除解决方案Debug目录开始...");
                foreach (DirectoryInfo dirInfo in solutionRootDirInfo.GetDirectories())
                {
                    if (String.Compare(dirInfo.Name, "Debug", true) == 0)
                    {
                        Console.WriteLine("删除目录" + dirInfo.FullName);
                        dirInfo.Attributes = FileAttributes.Normal;
                        dirInfo.Delete(true);
                    }
                }
                Console.WriteLine("删除解决方案Debug目录结束...");
                Console.WriteLine();

                //5.删除解决方案Release目录
                Console.WriteLine("删除解决方案Release目录开始...");
                foreach (DirectoryInfo dirInfo in solutionRootDirInfo.GetDirectories())
                {
                    if (String.Compare(dirInfo.Name, "Release", true) == 0)
                    {
                        Console.WriteLine("删除目录" + dirInfo.FullName);
                        dirInfo.Attributes = FileAttributes.Normal;
                        dirInfo.Delete(true);
                    }
                }
                Console.WriteLine("删除解决方案Release目录结束...");
                Console.WriteLine();

                //6.删除解决方案ipch目录
                Console.WriteLine("删除解决方案ipch目录开始...");
                foreach (DirectoryInfo dirInfo in solutionRootDirInfo.GetDirectories())
                {
                    if (String.Compare(dirInfo.Name, "ipch", true) == 0)
                    {
                        Console.WriteLine("删除目录" + dirInfo.FullName);
                        dirInfo.Attributes = FileAttributes.Normal;
                        dirInfo.Delete(true);
                    }
                }
                Console.WriteLine("删除解决方案ipch目录结束...");
                Console.WriteLine();
            }

            //清理完成
            Console.WriteLine("清理完成...");
            Console.ReadLine();
        }
    }
}