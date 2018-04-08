/*
 *  author : Zoro
 *  date   : 2018-4-8 11:33:35
 *  brief  : 读写同一个文件
 */
using System;
using System.IO;
using System.Linq;
using System.Text;

namespace StreamReader_StreamWriter_20180408_1
{
    class Program
    {
        static void Main(string[] args)
        {
            //!测试文件
            String sTestFile = "Test.txt";

            //!写入文件
            for (int i = 0; i < 100; i++)
            {
                using (StreamWriter vWriter = new StreamWriter(sTestFile, true, Encoding.Default))
                {
                    vWriter.Write(i);
                    vWriter.WriteLine('|' + (i + 1).ToString());
                    vWriter.Close();
                    using (StreamReader vReader = new StreamReader(sTestFile, Encoding.Default))
                    {
                        String[] vContent = vReader.ReadToEnd().Split(Environment.NewLine.ToCharArray());
                        if (vContent.Count() > 2)
                        {
                            String sLastLine = vContent[vContent.Count() - 3];
                            if (!String.IsNullOrWhiteSpace(sLastLine))
                            {
                                String[] vProgress = sLastLine.Split('|');
                                Console.Write(vProgress[0] + " ");
                                Console.WriteLine(vProgress[1]);
                            }
                        }
                        vReader.Close();
                    }
                }
            }

            //!结束示例
            Console.WriteLine("Done!!");
            Console.ReadLine();
        }
    }
}