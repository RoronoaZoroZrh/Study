using System;
using System.Windows.Forms;

namespace Plan
{
    public partial class ItemDetail : Form
    {
        //构造函数
        public ItemDetail()
        {
            //初始化控件
            InitializeComponent();
        }

        //概要信息
        public String SummaryInfo
        {
            get { return this.TextBoxSummary.Text.Trim(); }
            set { this.TextBoxSummary.Text = value; }
        }

        //详细信息
        public String DetailInfo
        {
            get { return this.TextBoxDetail.Text.Trim(); }
            set { this.TextBoxDetail.Text = value; }
        }
    }
}