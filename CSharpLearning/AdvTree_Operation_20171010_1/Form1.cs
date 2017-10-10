/**
 *  author : Tiger
 *  date   : 2017-10-10 11:33:40
 *  brief  : 为了验证AdvTree控件是否可以定位滚动条的位置（刷新后不可定位）
 */
using System;
using System.Windows.Forms;

namespace AdvTree_Operation_20171010_1
{
    public partial class AdvTree_OP : Form
    {
        //!构造函数
        public AdvTree_OP()
        {
            InitializeComponent();
        }

        //!构造AdvTree控件
        private void AdvTree_OP_Load(object sender, EventArgs e)
        {
            RefreshAdvTree();
        }

        //!刷新
        private void RefreshAdvTree()
        {
            AdvTree_Item.Nodes.Clear();
            for (int i = 0; i < 100; i++)
            {
                AdvTree_Item.Nodes.Add(new DevComponents.AdvTree.Node()
                {
                    Text = i.ToString()
                });
            }
        }

        //!定位滚动条位置
        private void AdvTree_Item_Click(object sender, EventArgs e)
        {
            RefreshAdvTree();
            DevComponents.AdvTree.Node vSelNode = AdvTree_Item.Nodes[AdvTree_Item.Nodes.Count - 1];
            AdvTree_Item.SelectNode(vSelNode, DevComponents.AdvTree.eTreeAction.Code);
            vSelNode.EnsureVisible();
        }
    }
}