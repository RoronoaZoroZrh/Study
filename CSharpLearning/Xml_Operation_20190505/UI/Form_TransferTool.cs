using System;
using System.Collections.Generic;
using System.IO;
using System.Windows.Forms;
using System.Xml;

namespace Xml_Operation_20190505
{
    public partial class Form_TransferTool : Form
    {
        public Form_TransferTool()
        {
            InitializeComponent();
        }

        private void Button_Input_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog inputDialog = new FolderBrowserDialog();
            if (DialogResult.OK == inputDialog.ShowDialog(this))
            {
                TextBox_Input.Text = inputDialog.SelectedPath;
            }
        }

        private void Button_Run_Click(object sender, EventArgs e)
        {
            String input = TextBox_Input.Text.Trim();
            if (!Directory.Exists(input))
            {
                MessageBox.Show(this, String.Format("关卡目录不存在:{0}", input), "错误", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                RichTextBox_Output.Clear();
                String output = Path.GetDirectoryName(input).TrimEnd('/').TrimEnd('\\') + "\\" + Path.GetFileName(input) + "_Transfer\\";
                Directory.CreateDirectory(output);
                DirectoryInfo tarDirInfo = new DirectoryInfo(input);
                foreach (FileInfo infoIter in tarDirInfo.GetFiles("*.xml", SearchOption.AllDirectories))
                {
                    try
                    {
                        //加载
                        XmlDocument xmlDoc = new XmlDocument();
                        xmlDoc.Load(infoIter.FullName);

                        //遍历节点
                        XmlNode tarNode = xmlDoc.SelectSingleNode("//Normal");
                        List<XmlNode> noteNodes = new List<XmlNode>();
                        foreach (XmlNode nodeIter in tarNode.SelectNodes("Note"))
                        {
                            if (nodeIter.Attributes["note_type"].Value == "pair")
                                noteNodes.Add(nodeIter);
                        }

                        //修改节点
                        foreach (XmlNode nodeIter in noteNodes)
                        {
                            XmlNode newNoteNode = nodeIter.Clone();
                            newNoteNode.Attributes["note_type"].Value = "short";
                            newNoteNode.Attributes["track"].Value = newNoteNode.Attributes["target_track"].Value;
                            newNoteNode.Attributes.Remove(newNoteNode.Attributes["target_track"]);
                            tarNode.InsertAfter(newNoteNode, nodeIter);

                            nodeIter.Attributes["note_type"].Value = "short";
                            nodeIter.Attributes.Remove(nodeIter.Attributes["target_track"]);
                        }

                        //保存
                        xmlDoc.Save(output + Path.GetFileName(infoIter.FullName));
                    }
                    catch (Exception)
                    {
                        if (String.IsNullOrWhiteSpace(RichTextBox_Output.Text))
                        {
                            RichTextBox_Output.Text += "以下文件转换失败!" + Environment.NewLine;
                        }
                        RichTextBox_Output.Text += infoIter.FullName + Environment.NewLine;
                    }
                }

                if (String.IsNullOrWhiteSpace(RichTextBox_Output.Text))
                {
                    MessageBox.Show(this, "转换成功", "提示", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
                else
                {
                    MessageBox.Show(this, "转换失败", "错误", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
            }
        }
    }
}