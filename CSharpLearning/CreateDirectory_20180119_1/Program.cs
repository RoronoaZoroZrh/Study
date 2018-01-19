/*
 *  author    : Zoro
 *  date      : 2018-1-19 13:52:36
 *  brief     : 查看重复创建目录的影响
 *  conclusion: 可以重复创建目录
 */
using System;
using System.IO;

namespace CreateDirectory_20180119_1
{
    class Program
    {
        static void Main(string[] args)
        {
            //!测试资源
            String sTestFile = "./TestDir/TestFile.txt";

            //!第一次创建目录
            Directory.CreateDirectory(Path.GetDirectoryName(sTestFile));
            File.Create(sTestFile).Close();

            //!第二次创建目录
            Boolean bExpectResult = true;
            Boolean bActualResult = true;
            try
            {
                Directory.CreateDirectory(Path.GetDirectoryName(sTestFile));
            }
            catch (Exception)
            {
                bActualResult = false;
            }

            //!显示测试结果
            Console.WriteLine(bExpectResult == bActualResult);

            //!结束
            Console.WriteLine("示例结束...");
            Console.ReadLine();
        }
    }
}