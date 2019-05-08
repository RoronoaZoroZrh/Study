using System;
using System.IO;
using System.Windows.Forms;
using System.Xml;

namespace Xml_Operation_20190313
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
                        foreach (XmlNode nodeIter in tarNode.SelectNodes("Note"))
                        {
                            //修改track属性
                            XmlAttribute trackAttr = nodeIter.Attributes["track"];
                            trackAttr.Value = (Int32.Parse(trackAttr.Value) / 4 * 5).ToString();

                            //修改target_track属性
                            XmlAttribute tarTrackAttr = nodeIter.Attributes["target_track"];
                            if (tarTrackAttr != null)
                            {
                                String tarValue = "";
                                foreach (String sIter in tarTrackAttr.Value.Split(','))
                                {
                                    if (!String.IsNullOrEmpty(sIter))
                                    {
                                        tarValue = tarValue + (Int32.Parse(sIter) / 4 * 5).ToString() + ",";
                                    }
                                }
                                tarTrackAttr.Value = tarValue.TrimEnd(',');
                            }
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