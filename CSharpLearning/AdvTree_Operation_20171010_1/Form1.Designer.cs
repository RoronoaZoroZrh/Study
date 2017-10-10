namespace AdvTree_Operation_20171010_1
{
    partial class AdvTree_OP
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
            this.AdvTree_Item = new DevComponents.AdvTree.AdvTree();
            this.nodeConnector1 = new DevComponents.AdvTree.NodeConnector();
            this.elementStyle1 = new DevComponents.DotNetBar.ElementStyle();
            ((System.ComponentModel.ISupportInitialize)(this.AdvTree_Item)).BeginInit();
            this.SuspendLayout();
            // 
            // AdvTree_Item
            // 
            this.AdvTree_Item.AccessibleRole = System.Windows.Forms.AccessibleRole.Outline;
            this.AdvTree_Item.AllowDrop = true;
            this.AdvTree_Item.BackColor = System.Drawing.SystemColors.Window;
            // 
            // 
            // 
            this.AdvTree_Item.BackgroundStyle.Class = "TreeBorderKey";
            this.AdvTree_Item.Dock = System.Windows.Forms.DockStyle.Fill;
            this.AdvTree_Item.Location = new System.Drawing.Point(0, 0);
            this.AdvTree_Item.Name = "AdvTree_Item";
            this.AdvTree_Item.NodesConnector = this.nodeConnector1;
            this.AdvTree_Item.NodeStyle = this.elementStyle1;
            this.AdvTree_Item.PathSeparator = ";";
            this.AdvTree_Item.Size = new System.Drawing.Size(440, 384);
            this.AdvTree_Item.Styles.Add(this.elementStyle1);
            this.AdvTree_Item.TabIndex = 0;
            this.AdvTree_Item.Click += new System.EventHandler(this.AdvTree_Item_Click);
            // 
            // nodeConnector1
            // 
            this.nodeConnector1.LineColor = System.Drawing.SystemColors.ControlText;
            // 
            // elementStyle1
            // 
            this.elementStyle1.Class = "";
            this.elementStyle1.Name = "elementStyle1";
            this.elementStyle1.TextColor = System.Drawing.SystemColors.ControlText;
            // 
            // AdvTree_OP
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(440, 384);
            this.Controls.Add(this.AdvTree_Item);
            this.Name = "AdvTree_OP";
            this.Text = "AdvTree操作练习";
            this.Load += new System.EventHandler(this.AdvTree_OP_Load);
            ((System.ComponentModel.ISupportInitialize)(this.AdvTree_Item)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private DevComponents.AdvTree.AdvTree AdvTree_Item;
        private DevComponents.AdvTree.NodeConnector nodeConnector1;
        private DevComponents.DotNetBar.ElementStyle elementStyle1;
    }
}

