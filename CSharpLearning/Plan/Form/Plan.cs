using System.Drawing;
using System.Windows.Forms;

namespace Plan
{
    public partial class FormPlan : Form
    {
        //构造函数
        public FormPlan()
        {
            //初始化控件
            InitializeComponent();
        }

        //显示右键菜单
        private void ListBox_MouseUp(object sender, MouseEventArgs e)
        {
            //显示右键菜单
            if (e.Button == MouseButtons.Right)
            {
                if (this.ListBoxPlan.Focused) //计划面板右键菜单
                {
                    this.SetPanelPlanContextMenuStrip(e);
                }
                else if (this.ListBoxToDo.Focused) //即将进行面板右键菜单
                {
                    this.SetPanelToDoContextMenuStrip(e);
                }
                else if (this.ListBoxDoing.Focused) //正在进行面板右键菜单
                {
                    this.SetPanelDoingContextMenuStrip(e);
                }
            }
        }

        //设置计划面板右键菜单
        private void SetPanelPlanContextMenuStrip(MouseEventArgs e)
        {
            if (this.ListBoxPlan.SelectedIndices.Count > 0)
            {
                this.ToolStripMenuItemAdd.Visible = true;
                this.ToolStripMenuItemDelete.Visible = true;
                this.ToolStripMenuItemMove.Visible = true;
                this.ToolStripMenuItemRevert.Visible = false;
            }
            else
            {
                this.ToolStripMenuItemAdd.Visible = true;
                this.ToolStripMenuItemDelete.Visible = false;
                this.ToolStripMenuItemMove.Visible = false;
                this.ToolStripMenuItemRevert.Visible = false;
            }
            this.ContextMenuStripFormPlan.Show(this.ListBoxPlan, new Point(e.X, e.Y));
        }

        //设置即将进行面板右键菜单
        private void SetPanelToDoContextMenuStrip(MouseEventArgs e)
        {
            if (this.ListBoxToDo.SelectedIndices.Count > 0)
            {
                this.ToolStripMenuItemAdd.Visible = false;
                this.ToolStripMenuItemDelete.Visible = false;
                this.ToolStripMenuItemMove.Visible = true;
                this.ToolStripMenuItemRevert.Visible = true;
            }
            else
            {
                this.ToolStripMenuItemAdd.Visible = false;
                this.ToolStripMenuItemDelete.Visible = false;
                this.ToolStripMenuItemMove.Visible = false;
                this.ToolStripMenuItemRevert.Visible = false;
            }
            this.ContextMenuStripFormPlan.Show(this.ListBoxToDo, new Point(e.X, e.Y));
        }

        //设置正在进行面板右键菜单
        private void SetPanelDoingContextMenuStrip(MouseEventArgs e)
        {
            if (this.ListBoxDoing.SelectedIndices.Count > 0)
            {
                this.ToolStripMenuItemAdd.Visible = false;
                this.ToolStripMenuItemDelete.Visible = false;
                this.ToolStripMenuItemMove.Visible = true;
                this.ToolStripMenuItemRevert.Visible = true;
            }
            else
            {
                this.ToolStripMenuItemAdd.Visible = false;
                this.ToolStripMenuItemDelete.Visible = false;
                this.ToolStripMenuItemMove.Visible = false;
                this.ToolStripMenuItemRevert.Visible = false;
            }
            this.ContextMenuStripFormPlan.Show(this.ListBoxDoing, new Point(e.X, e.Y));
        }

        //设置焦点
        private void ListBoxPlan_MouseDown(object sender, MouseEventArgs e)
        {
            this.ListBoxPlan.Focus();
        }

        //设置焦点
        private void ListBoxToDo_MouseDown(object sender, MouseEventArgs e)
        {
            this.ListBoxToDo.Focus();
        }

        //设置焦点
        private void ListBoxDoing_MouseDown(object sender, MouseEventArgs e)
        {
            this.ListBoxDoing.Focus();
        }

        //添加
        private void ToolStripMenuItemAdd_Click(object sender, System.EventArgs e)
        {
            
        }

        //数据层
        private FormPlanDataLayer m_formPlanDataLayer = new FormPlanDataLayer();
    }
}