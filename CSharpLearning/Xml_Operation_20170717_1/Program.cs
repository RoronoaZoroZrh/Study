/**
 *  author : Zoro_Tiger
 *  date   : 2017-7-17 16:28:51
 *  brief  : 整理XML文件格式
 */
using System;
using System.IO;
using System.Xml;

namespace Xml_Operation_20170717_1
{
    class Program
    {
        static void Main(string[] args)
        {
            //!读取文件路径
            String file_path = Console.ReadLine();

            try
            {
                //!去只读
                FileInfo file_info = new FileInfo(file_path);
                Boolean IsReadOnly = file_info.IsReadOnly;
                file_info.IsReadOnly = false;

                //!整理格式
                XmlDocument doc = new XmlDocument();
                doc.Load(file_path);
                doc.Save(file_path);

                //!恢复只读属性
                file_info.IsReadOnly = IsReadOnly;
            }
            catch (Exception e)
            {
                Console.WriteLine(e.ToString());
            }
        }
    }
}