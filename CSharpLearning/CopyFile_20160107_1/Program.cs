/**
 *  author : Tiger
 *  date   : 2016-1-7 13:44:17
 *  brief  : 拷贝文件
 */
using System;
using System.IO;

namespace CopyFile
{
    class Program
    {
        static void Main(string[] args)
        {
            //读取旧文件位置
            Console.Write("oldFile:");
            String oldFile = Console.ReadLine();

            //读取新文件位置
            Console.Write("newFile:");
            String newFile = Console.ReadLine();

            //拷贝文件
            CopyFile(oldFile, newFile);

            //读取行，以防止程序立刻退出
            Console.ReadLine();
        }

        //拷贝文件
        public static void CopyFile(String oldFile, String newFile)
        {
            if (File.Exists(oldFile)) //文件存在才进行拷贝
            {
                //创建目录
                if (!Directory.Exists(Path.GetDirectoryName(oldFile)))
                {
                    Directory.CreateDirectory(Path.GetDirectoryName(oldFile));
                }

                //去掉newFile只读属性
                if (File.Exists(newFile))
                {
                    new FileInfo(newFile).IsReadOnly = false;
                }

                //拷贝文件
                new FileInfo(oldFile).MoveTo(newFile);
                new FileInfo(newFile).IsReadOnly = false;
            }
        }
    }
}