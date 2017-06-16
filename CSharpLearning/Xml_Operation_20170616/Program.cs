using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace Xml_Operation_20170616
{
    public class Program
    {
        static void Main(string[] args)
        {
            //!读取文件路径
            String file_path = Console.ReadLine();

            //!加载文件
            XmlDocument xml_doc = new XmlDocument();
            xml_doc.Load(file_path);

            //!参数节点
            XmlElement element1 = xml_doc.CreateElement("strength_param1");
            element1.InnerText = "0.8";
            XmlElement element2 = xml_doc.CreateElement("strength_param2");
            element2.InnerText = "0.2";
            XmlElement element3 = xml_doc.CreateElement("lucky_standard");
            element3.InnerText = "100";
            XmlElement element4 = xml_doc.CreateElement("lucky_param1");
            element4.InnerText = "0.8";
            XmlElement element5 = xml_doc.CreateElement("lucky_param2");
            element5.InnerText = "0.2";

            //!添加声明
            xml_doc.RemoveAll();
            XmlDeclaration dec = xml_doc.CreateXmlDeclaration("1.0", "UTF-8", null);
            xml_doc.AppendChild(dec);

            //!添加根节点
            XmlElement root_element = xml_doc.CreateElement("config");
            xml_doc.AppendChild(root_element);

            //!添加装备节点
            for (int i = 0; i < 4; i++)
            {
                XmlElement equipment_element = xml_doc.CreateElement("equipment");
                root_element.AppendChild(equipment_element);

                XmlAttribute type_attr = xml_doc.CreateAttribute("type");
                equipment_element.Attributes.Append(type_attr);

                XmlAttribute subtype_attr = xml_doc.CreateAttribute("subtype");
                equipment_element.Attributes.Append(subtype_attr);

                if (0 == i)
                {
                    type_attr.Value = "1003";
                    subtype_attr.Value = "32";
                }
                else
                {
                    type_attr.Value = "1004";
                    if (1 == i) subtype_attr.Value = "1200000";
                    else if (2 == i) subtype_attr.Value = "1200001";
                    else if (3 == i) subtype_attr.Value = "1200002";
                }

                XmlElement level_list_element = xml_doc.CreateElement("strength_level_list");
                equipment_element.AppendChild(level_list_element);

                for (int j = 0; j < 20; j++)
                {
                    XmlElement strength_level_element = xml_doc.CreateElement("strength_level");
                    level_list_element.AppendChild(strength_level_element);

                    XmlAttribute level_attr = xml_doc.CreateAttribute("level");
                    level_attr.Value = (j + 1).ToString();
                    strength_level_element.Attributes.Append(level_attr);

                    strength_level_element.AppendChild(element1.Clone());
                    strength_level_element.AppendChild(element2.Clone());
                    strength_level_element.AppendChild(element3.Clone());
                    strength_level_element.AppendChild(element4.Clone());
                    strength_level_element.AppendChild(element5.Clone());
                }
            }

            //!保存文件
            xml_doc.Save(file_path);
        }
    }
}