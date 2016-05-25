using System;
using System.Windows.Forms;

namespace Plan
{
    public partial class ItemComplete : Form
    {
        //构造函数
        public ItemComplete(FormPlanDataLayer vDataLayer)
        {
            //初始化控件
            InitializeComponent();

            //初始化数据
            this.m_vFormPlanDataLayer = vDataLayer;
            this.m_vFormPlanDataLayer.InitListBox(this.ListBoxComplete);
        }

        //显示Item详细信息
        private void ListBoxComplete_DoubleClick(object sender, System.EventArgs e)
        {
            if (this.ListBoxComplete.SelectedItem != null)
            {
                String sDetailInfo = String.Empty;
                if (this.m_vFormPlanDataLayer.GetPlanData(this.ListBoxComplete, this.ListBoxComplete.SelectedItem.ToString(), ref sDetailInfo))
                {
                    ItemDetail fItemDetail = new ItemDetail();
                    fItemDetail.SummaryInfo = this.ListBoxComplete.SelectedItem.ToString();
                    fItemDetail.DetailInfo = sDetailInfo;
                    fItemDetail.ReadOnly = true;
                    fItemDetail.ShowDialog();
                }
            }
        }

        //数据
        private FormPlanDataLayer m_vFormPlanDataLayer = null;
    }
}