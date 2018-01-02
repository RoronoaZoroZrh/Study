/*
 *  author : Zoro
 *  date   : 2018-1-2 16:34:41
 *  brief  : 查找引用方法
 */
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace FindFunction_20180102_1
{
    class Program
    {
        static void Main(string[] args)
        {
            //!文件目录
            Console.Write("输入目录：");
            String sIDir = Console.ReadLine();
            Console.Write("输出目录：");
            String sODir = Console.ReadLine();
            String sOFile = sODir + "\\result.txt";
            if (File.Exists(sOFile)) File.Delete(sOFile);

            //!所有方法
            List<String> vAllRefFunctions = new List<String>
            {
                "Init",
                "Connect",
                "CreateFolder",
                "CheckIn",
                "CheckOut",
                "Delete",
                "DeleteLocal",
                "DisConnect",
                "FolderExists",
                "GetActiveBranch",
                "GetLatest",
                "GetLocalpath",
                "ImportFile",
                "isConnect",
                "isNull",
                "Move",
                "GetNamespacePath",
                "Rename",
                "SelectActiveBranch",
                "SetActiveBranch",
                "SetWorkingPath",
                "GetProj",
                "GetChildren",
                "HasChildren",
                "Release",
                "ImportFileWithNoDialog",
                "DeleteFileWithNoDialog",
                "GetFileModifyTime",
                "GetFiles",
                "CheckResBeforeCheckOut",
                "CheckOutWithoutDialog",
                "ImportFileWithoutDialog",
                "CheckInWithoutDialog",
                "DeleteWithoutDialog",
                "UndoCheckOutWithoutDialog",
                "CheckResExist",
                "CheckResConsistence",
                "IsResCheckOut",
            };

            //!读取输入
            List<String> vAllUsedFunctions = new List<String>();
            foreach (FileInfo vFile in new DirectoryInfo(sIDir).GetFiles("*.txt"))
            {
                List<String> vFunctions = new List<String>();
                using (StreamReader vReader = new StreamReader(vFile.FullName))
                {
                    while (!vReader.EndOfStream)
                    {
                        String sCurLine = vReader.ReadLine();
                        String sFunction = sCurLine.Substring(sCurLine.IndexOf("for") + 5);
                        sFunction = sFunction.Substring(0, sFunction.IndexOf("\'"));
                        if (!vFunctions.Contains(sFunction))
                        {
                            vFunctions.Add(sFunction);
                        }
                    }
                }
                vAllUsedFunctions.AddRange(vFunctions.Except(vAllUsedFunctions));

                //!写入结果
                using (StreamWriter vWriter = new StreamWriter(sOFile, true))
                {
                    vWriter.WriteLine("<" + Path.GetFileNameWithoutExtension(vFile.FullName) + ">");
                    vFunctions.Sort();
                    foreach (String sFunction in vFunctions)
                    {
                        vWriter.WriteLine(sFunction);
                    }
                    vWriter.WriteLine();
                }
            }

            //!使用的接口
            String sContent1 = "使用的接口" + Environment.NewLine;
            sContent1 = sContent1 + String.Join(Environment.NewLine, vAllUsedFunctions);
            using (StreamWriter vWriter = new StreamWriter(sOFile, true)) vWriter.WriteLine(sContent1);

            //!未使用的接口
            String sContent2 = "<未使用的接口>" + Environment.NewLine;
            sContent2 = sContent2 + String.Join(Environment.NewLine, vAllRefFunctions.Except(vAllUsedFunctions));
            using (StreamWriter vWriter = new StreamWriter(sOFile, true))
            {
                vWriter.WriteLine();
                vWriter.WriteLine(sContent2);
            }

            //!示例结束
            Console.WriteLine("Done!");
            Console.ReadLine();
        }
    }
}