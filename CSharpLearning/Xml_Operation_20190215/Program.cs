/*
 *  author    : Zoro
 *  date      : 2019-2-15 10:41:50
 *  brief     : 查看文件中指定属性
 *  conclusion: 
 */
using System;
using System.IO;
using System.Xml;

namespace Xml_Operation_20190215
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //获取输入
            Console.Write("需要检查的目录：");
            String input = Console.ReadLine();

            //检查目录所有文件
            if (Directory.Exists(input))
            {
                DirectoryInfo dirInfo = new DirectoryInfo(input);
                foreach (FileInfo fileInfo in dirInfo.GetFiles("*.xml", SearchOption.AllDirectories))
                {
                    try
                    {
                        XmlDocument xmlDoc = new XmlDocument();
                        xmlDoc.Load(fileInfo.FullName);

                        XmlNode tarNode = null;

                        //tarNode = xmlDoc.SelectSingleNode("//Level/LevelInfo/TrackCount");
                        //if (tarNode != null)
                        //{
                        //    if (tarNode.InnerText == "5")
                        //    {
                        //        Console.WriteLine(String.Format("五轨：{0}", fileInfo.FullName));
                        //    }
                        //    else if (tarNode.InnerText == "3")
                        //    {
                        //        Console.WriteLine(String.Format("三轨：{0}", fileInfo.FullName));
                        //    }
                        //}

                        tarNode = xmlDoc.SelectSingleNode("//Level/SectionSeq/Section[@type=\"compete\"]");
                        if (tarNode != null)
                        {
                            Console.WriteLine(String.Format("Compete段落：{0}", fileInfo.FullName));
                        }

                        tarNode = xmlDoc.SelectSingleNode("//Level/SectionSeq/Section[@type=\"end\"]");
                        if (tarNode != null)
                        {
                            Console.WriteLine(String.Format("End段落：{0}", fileInfo.FullName));
                        }

                        tarNode = xmlDoc.SelectSingleNode("//Level/SectionSeq/Section[@type=\"showtime\"]");
                        if (tarNode != null)
                        {
                            Int32 beg = Convert.ToInt32(tarNode.Attributes["startbar"].Value);
                            Int32 end = Convert.ToInt32(tarNode.Attributes["endbar"].Value);
                            if (end - beg != 3)
                            {
                                Console.WriteLine(String.Format("Showtime长度不为4：{0} 长度：{1}", fileInfo.FullName, end - beg + 1));
                            }
                        }

                        tarNode = xmlDoc.SelectSingleNode("//Level/ActionSeq");
                        if (tarNode != null)
                        {
                            if (tarNode.Attributes["type"].Value != "1")
                            {
                                Console.WriteLine(String.Format("固定编舞：{0}", fileInfo.FullName));
                            }
                            else
                            {
                                foreach (XmlNode nodeIter in tarNode.SelectNodes("ActionList"))
                                {
                                    if (nodeIter != null && nodeIter.Attributes["level"].Value != "2")
                                    {
                                        Console.WriteLine(String.Format("激励程度不为2：{0}", fileInfo.FullName));
                                    }
                                }
                            }
                        }
                    }
                    catch (Exception)
                    {
                        Console.WriteLine(String.Format("文件格式不正确：{0}", fileInfo.FullName));
                    }
                }
            }

            //结束检查
            Console.WriteLine("Done!!");
            Console.ReadLine();
        }
    }
}