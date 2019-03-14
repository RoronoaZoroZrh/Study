/*
 *  author    : Zoro
 *  date      : 2019-3-8 16:21:04
 *  brief     : 修改属性
 *  conclusion: 
 */
using System;
using System.IO;
using System.Xml;

namespace Xml_Operation_20190308
{
    class Program
    {
        static void Main(string[] args)
        {
            //输入
            String input = Console.ReadLine();

            //加载
            XmlDocument xmlDoc = new XmlDocument();
            xmlDoc.Load(input);

            //遍历节点
            XmlNode tarNode = xmlDoc.SelectSingleNode("//Normal");
            foreach (XmlNode nodeIter in tarNode.SelectNodes("Note"))
            {
                //修改track属性
                XmlAttribute trackAttr = nodeIter.Attributes["track"];
                trackAttr.Value = (Int32.Parse(trackAttr.Value) / 5 * 4).ToString();

                //修改target_track属性
                XmlAttribute tarTrackAttr = nodeIter.Attributes["target_track"];
                if (tarTrackAttr != null)
                {
                    String tarValue = "";
                    foreach (String sIter in tarTrackAttr.Value.Split(','))
                    {
                        if (!String.IsNullOrEmpty(sIter))
                        {
                            tarValue = tarValue + (Int32.Parse(sIter) / 5 * 4).ToString() + ",";
                        }
                    }
                    tarTrackAttr.Value = tarValue.TrimEnd(',');
                }
            }

            //保存
            xmlDoc.Save(Path.GetFileNameWithoutExtension(input) + "_transfer.xml");
            Console.WriteLine("Done!!");
            Console.ReadLine();
        }
    }
}