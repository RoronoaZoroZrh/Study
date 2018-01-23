/*
 *  author    : Zoro
 *  date      : 2018-1-23 16:00:41
 *  brief     : 使用正则表达式查找文件中指定字符串
 */
using System;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;

namespace Regex_20180123_1
{
    class Program
    {
        static void Main(string[] args)
        {
            //!读取文件路径
            Console.Write("文件路径：");
            String sFile = Console.ReadLine();

            //!读取文件内容
            String sContent = "";
            using (StreamReader vReader = new StreamReader(sFile, Encoding.Default))
            {
                sContent = vReader.ReadToEnd();
                vReader.Close();
            }

            //!查找匹配内容
            Regex vRegex = new Regex("NODE_NAME \"Bip01 Spine1\"[\\s\\S]+?TM_POS ([\\s\\S]+?)\\*TM_ROTAXIS", RegexOptions.Singleline);
            Match vMatch = vRegex.Match(sContent);
            if (vMatch.Success)
            {
                Console.WriteLine(vMatch.Value);
            }

            //!解析数值
            String sData = vMatch.Groups[1].Value.Trim();
            String sResult = String.Join(Environment.NewLine, sData.Split(' '));
            Console.WriteLine(sResult);

            //!结束
            Console.WriteLine("示例结束...");
            Console.ReadLine();
        }
    }
}