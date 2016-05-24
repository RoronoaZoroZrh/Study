namespace Plan
{
    partial class FormPlan
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormPlan));
            this.StyleManagerFormPlan = new DevComponents.DotNetBar.StyleManager();
            this.BarMenu = new DevComponents.DotNetBar.Bar();
            this.ButtonItemCheckCompleteTask = new DevComponents.DotNetBar.ButtonItem();
            this.ExpandablePanelPlan = new DevComponents.DotNetBar.ExpandablePanel();
            this.ListBoxPlan = new System.Windows.Forms.ListBox();
            this.ExpandablePanelToDo = new DevComponents.DotNetBar.ExpandablePanel();
            this.ListBoxToDo = new System.Windows.Forms.ListBox();
            this.ExpandablePanelDoing = new DevComponents.DotNetBar.ExpandablePanel();
            this.ListBoxDoing = new System.Windows.Forms.ListBox();
            this.ContextMenuStripFormPlan = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.ToolStripMenuItemAdd = new System.Windows.Forms.ToolStripMenuItem();
            this.ToolStripMenuItemDelete = new System.Windows.Forms.ToolStripMenuItem();
            this.ToolStripMenuItemMove = new System.Windows.Forms.ToolStripMenuItem();
            this.ToolStripMenuItemRevert = new System.Windows.Forms.ToolStripMenuItem();
            ((System.ComponentModel.ISupportInitialize)(this.BarMenu)).BeginInit();
            this.ExpandablePanelPlan.SuspendLayout();
            this.ExpandablePanelToDo.SuspendLayout();
            this.ExpandablePanelDoing.SuspendLayout();
            this.ContextMenuStripFormPlan.SuspendLayout();
            this.SuspendLayout();
            // 
            // StyleManagerFormPlan
            // 
            this.StyleManagerFormPlan.ManagerColorTint = System.Drawing.Color.Black;
            this.StyleManagerFormPlan.ManagerStyle = DevComponents.DotNetBar.eStyle.Office2010Silver;
            // 
            // BarMenu
            // 
            this.BarMenu.Dock = System.Windows.Forms.DockStyle.Top;
            this.BarMenu.Items.AddRange(new DevComponents.DotNetBar.BaseItem[] {
            this.ButtonItemCheckCompleteTask});
            this.BarMenu.Location = new System.Drawing.Point(0, 0);
            this.BarMenu.Name = "BarMenu";
            this.BarMenu.Size = new System.Drawing.Size(750, 27);
            this.BarMenu.Stretch = true;
            this.BarMenu.Style = DevComponents.DotNetBar.eDotNetBarStyle.StyleManagerControlled;
            this.BarMenu.TabIndex = 0;
            this.BarMenu.TabStop = false;
            // 
            // ButtonItemCheckCompleteTask
            // 
            this.ButtonItemCheckCompleteTask.Name = "ButtonItemCheckCompleteTask";
            this.ButtonItemCheckCompleteTask.Text = "查看完成任务";
            // 
            // ExpandablePanelPlan
            // 
            this.ExpandablePanelPlan.CanvasColor = System.Drawing.SystemColors.Control;
            this.ExpandablePanelPlan.ColorSchemeStyle = DevComponents.DotNetBar.eDotNetBarStyle.StyleManagerControlled;
            this.ExpandablePanelPlan.Controls.Add(this.ListBoxPlan);
            this.ExpandablePanelPlan.Dock = System.Windows.Forms.DockStyle.Left;
            this.ExpandablePanelPlan.ExpandButtonVisible = false;
            this.ExpandablePanelPlan.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.ExpandablePanelPlan.Location = new System.Drawing.Point(0, 27);
            this.ExpandablePanelPlan.Name = "ExpandablePanelPlan";
            this.ExpandablePanelPlan.Size = new System.Drawing.Size(250, 564);
            this.ExpandablePanelPlan.Style.Alignment = System.Drawing.StringAlignment.Center;
            this.ExpandablePanelPlan.Style.BackColor1.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelBackground;
            this.ExpandablePanelPlan.Style.Border = DevComponents.DotNetBar.eBorderType.SingleLine;
            this.ExpandablePanelPlan.Style.BorderColor.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.BarDockedBorder;
            this.ExpandablePanelPlan.Style.ForeColor.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.ItemText;
            this.ExpandablePanelPlan.Style.GradientAngle = 90;
            this.ExpandablePanelPlan.TabIndex = 1;
            this.ExpandablePanelPlan.TitleStyle.Alignment = System.Drawing.StringAlignment.Center;
            this.ExpandablePanelPlan.TitleStyle.BackColor1.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelBackground;
            this.ExpandablePanelPlan.TitleStyle.Border = DevComponents.DotNetBar.eBorderType.RaisedInner;
            this.ExpandablePanelPlan.TitleStyle.BorderColor.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelBorder;
            this.ExpandablePanelPlan.TitleStyle.ForeColor.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelText;
            this.ExpandablePanelPlan.TitleStyle.GradientAngle = 90;
            this.ExpandablePanelPlan.TitleText = "本周计划";
            // 
            // ListBoxPlan
            // 
            this.ListBoxPlan.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.ListBoxPlan.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ListBoxPlan.FormattingEnabled = true;
            this.ListBoxPlan.ItemHeight = 16;
            this.ListBoxPlan.Location = new System.Drawing.Point(0, 26);
            this.ListBoxPlan.Name = "ListBoxPlan";
            this.ListBoxPlan.Size = new System.Drawing.Size(250, 538);
            this.ListBoxPlan.TabIndex = 1;
            this.ListBoxPlan.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.ListBoxPlan_MouseDoubleClick);
            this.ListBoxPlan.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ListBoxPlan_MouseDown);
            this.ListBoxPlan.MouseUp += new System.Windows.Forms.MouseEventHandler(this.ListBox_MouseUp);
            // 
            // ExpandablePanelToDo
            // 
            this.ExpandablePanelToDo.CanvasColor = System.Drawing.SystemColors.Control;
            this.ExpandablePanelToDo.ColorSchemeStyle = DevComponents.DotNetBar.eDotNetBarStyle.StyleManagerControlled;
            this.ExpandablePanelToDo.Controls.Add(this.ListBoxToDo);
            this.ExpandablePanelToDo.Dock = System.Windows.Forms.DockStyle.Left;
            this.ExpandablePanelToDo.ExpandButtonVisible = false;
            this.ExpandablePanelToDo.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.ExpandablePanelToDo.Location = new System.Drawing.Point(250, 27);
            this.ExpandablePanelToDo.Name = "ExpandablePanelToDo";
            this.ExpandablePanelToDo.Size = new System.Drawing.Size(250, 564);
            this.ExpandablePanelToDo.Style.Alignment = System.Drawing.StringAlignment.Center;
            this.ExpandablePanelToDo.Style.BackColor1.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelBackground;
            this.ExpandablePanelToDo.Style.Border = DevComponents.DotNetBar.eBorderType.SingleLine;
            this.ExpandablePanelToDo.Style.BorderColor.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.BarDockedBorder;
            this.ExpandablePanelToDo.Style.ForeColor.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.ItemText;
            this.ExpandablePanelToDo.Style.GradientAngle = 90;
            this.ExpandablePanelToDo.TabIndex = 2;
            this.ExpandablePanelToDo.TitleStyle.Alignment = System.Drawing.StringAlignment.Center;
            this.ExpandablePanelToDo.TitleStyle.BackColor1.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelBackground;
            this.ExpandablePanelToDo.TitleStyle.Border = DevComponents.DotNetBar.eBorderType.RaisedInner;
            this.ExpandablePanelToDo.TitleStyle.BorderColor.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelBorder;
            this.ExpandablePanelToDo.TitleStyle.ForeColor.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelText;
            this.ExpandablePanelToDo.TitleStyle.GradientAngle = 90;
            this.ExpandablePanelToDo.TitleText = "即将进行";
            // 
            // ListBoxToDo
            // 
            this.ListBoxToDo.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.ListBoxToDo.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ListBoxToDo.FormattingEnabled = true;
            this.ListBoxToDo.ItemHeight = 16;
            this.ListBoxToDo.Location = new System.Drawing.Point(0, 26);
            this.ListBoxToDo.Name = "ListBoxToDo";
            this.ListBoxToDo.Size = new System.Drawing.Size(250, 538);
            this.ListBoxToDo.TabIndex = 2;
            this.ListBoxToDo.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.ListBoxToDo_MouseDoubleClick);
            this.ListBoxToDo.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ListBoxToDo_MouseDown);
            this.ListBoxToDo.MouseUp += new System.Windows.Forms.MouseEventHandler(this.ListBox_MouseUp);
            // 
            // ExpandablePanelDoing
            // 
            this.ExpandablePanelDoing.CanvasColor = System.Drawing.SystemColors.Control;
            this.ExpandablePanelDoing.ColorSchemeStyle = DevComponents.DotNetBar.eDotNetBarStyle.StyleManagerControlled;
            this.ExpandablePanelDoing.Controls.Add(this.ListBoxDoing);
            this.ExpandablePanelDoing.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ExpandablePanelDoing.ExpandButtonVisible = false;
            this.ExpandablePanelDoing.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.ExpandablePanelDoing.Location = new System.Drawing.Point(500, 27);
            this.ExpandablePanelDoing.Name = "ExpandablePanelDoing";
            this.ExpandablePanelDoing.Size = new System.Drawing.Size(250, 564);
            this.ExpandablePanelDoing.Style.Alignment = System.Drawing.StringAlignment.Center;
            this.ExpandablePanelDoing.Style.BackColor1.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelBackground;
            this.ExpandablePanelDoing.Style.Border = DevComponents.DotNetBar.eBorderType.SingleLine;
            this.ExpandablePanelDoing.Style.BorderColor.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.BarDockedBorder;
            this.ExpandablePanelDoing.Style.ForeColor.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.ItemText;
            this.ExpandablePanelDoing.Style.GradientAngle = 90;
            this.ExpandablePanelDoing.TabIndex = 3;
            this.ExpandablePanelDoing.TitleStyle.Alignment = System.Drawing.StringAlignment.Center;
            this.ExpandablePanelDoing.TitleStyle.BackColor1.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelBackground;
            this.ExpandablePanelDoing.TitleStyle.Border = DevComponents.DotNetBar.eBorderType.RaisedInner;
            this.ExpandablePanelDoing.TitleStyle.BorderColor.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelBorder;
            this.ExpandablePanelDoing.TitleStyle.ForeColor.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelText;
            this.ExpandablePanelDoing.TitleStyle.GradientAngle = 90;
            this.ExpandablePanelDoing.TitleText = "正在进行";
            // 
            // ListBoxDoing
            // 
            this.ListBoxDoing.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.ListBoxDoing.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ListBoxDoing.FormattingEnabled = true;
            this.ListBoxDoing.ItemHeight = 16;
            this.ListBoxDoing.Location = new System.Drawing.Point(0, 26);
            this.ListBoxDoing.Name = "ListBoxDoing";
            this.ListBoxDoing.Size = new System.Drawing.Size(250, 538);
            this.ListBoxDoing.TabIndex = 2;
            this.ListBoxDoing.MouseDoubleClick += new System.Windows.Forms.MouseEventHandler(this.ListBoxDoing_MouseDoubleClick);
            this.ListBoxDoing.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ListBoxDoing_MouseDown);
            this.ListBoxDoing.MouseUp += new System.Windows.Forms.MouseEventHandler(this.ListBox_MouseUp);
            // 
            // ContextMenuStripFormPlan
            // 
            this.ContextMenuStripFormPlan.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.ToolStripMenuItemAdd,
            this.ToolStripMenuItemDelete,
            this.ToolStripMenuItemMove,
            this.ToolStripMenuItemRevert});
            this.ContextMenuStripFormPlan.Name = "ContextMenuStripFormPlan";
            this.ContextMenuStripFormPlan.ShowImageMargin = false;
            this.ContextMenuStripFormPlan.Size = new System.Drawing.Size(76, 92);
            // 
            // ToolStripMenuItemAdd
            // 
            this.ToolStripMenuItemAdd.Name = "ToolStripMenuItemAdd";
            this.ToolStripMenuItemAdd.Size = new System.Drawing.Size(75, 22);
            this.ToolStripMenuItemAdd.Text = "添加";
            this.ToolStripMenuItemAdd.Click += new System.EventHandler(this.ToolStripMenuItemAdd_Click);
            // 
            // ToolStripMenuItemDelete
            // 
            this.ToolStripMenuItemDelete.Name = "ToolStripMenuItemDelete";
            this.ToolStripMenuItemDelete.Size = new System.Drawing.Size(75, 22);
            this.ToolStripMenuItemDelete.Text = "删除";
            // 
            // ToolStripMenuItemMove
            // 
            this.ToolStripMenuItemMove.Name = "ToolStripMenuItemMove";
            this.ToolStripMenuItemMove.Size = new System.Drawing.Size(75, 22);
            this.ToolStripMenuItemMove.Text = "移动";
            // 
            // ToolStripMenuItemRevert
            // 
            this.ToolStripMenuItemRevert.Name = "ToolStripMenuItemRevert";
            this.ToolStripMenuItemRevert.Size = new System.Drawing.Size(75, 22);
            this.ToolStripMenuItemRevert.Text = "撤销";
            // 
            // FormPlan
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(750, 591);
            this.Controls.Add(this.ExpandablePanelDoing);
            this.Controls.Add(this.ExpandablePanelToDo);
            this.Controls.Add(this.ExpandablePanelPlan);
            this.Controls.Add(this.BarMenu);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "FormPlan";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "计划";
            ((System.ComponentModel.ISupportInitialize)(this.BarMenu)).EndInit();
            this.ExpandablePanelPlan.ResumeLayout(false);
            this.ExpandablePanelToDo.ResumeLayout(false);
            this.ExpandablePanelDoing.ResumeLayout(false);
            this.ContextMenuStripFormPlan.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private DevComponents.DotNetBar.StyleManager StyleManagerFormPlan;
        private DevComponents.DotNetBar.Bar BarMenu;
        private DevComponents.DotNetBar.ButtonItem ButtonItemCheckCompleteTask;
        private DevComponents.DotNetBar.ExpandablePanel ExpandablePanelPlan;
        private DevComponents.DotNetBar.ExpandablePanel ExpandablePanelToDo;
        private DevComponents.DotNetBar.ExpandablePanel ExpandablePanelDoing;
        private System.Windows.Forms.ListBox ListBoxPlan;
        private System.Windows.Forms.ListBox ListBoxToDo;
        private System.Windows.Forms.ListBox ListBoxDoing;
        private System.Windows.Forms.ContextMenuStrip ContextMenuStripFormPlan;
        private System.Windows.Forms.ToolStripMenuItem ToolStripMenuItemAdd;
        private System.Windows.Forms.ToolStripMenuItem ToolStripMenuItemDelete;
        private System.Windows.Forms.ToolStripMenuItem ToolStripMenuItemMove;
        private System.Windows.Forms.ToolStripMenuItem ToolStripMenuItemRevert;
    }
}

