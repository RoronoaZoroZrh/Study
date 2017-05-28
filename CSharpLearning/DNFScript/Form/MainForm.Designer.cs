namespace DNFScript
{
    partial class MainForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.MainFormPanel = new DevComponents.DotNetBar.PanelEx();
            this.AutoButton = new DevComponents.DotNetBar.ButtonX();
            this.MainFormPanel.SuspendLayout();
            this.SuspendLayout();
            // 
            // MainFormPanel
            // 
            this.MainFormPanel.CanvasColor = System.Drawing.SystemColors.Control;
            this.MainFormPanel.ColorSchemeStyle = DevComponents.DotNetBar.eDotNetBarStyle.StyleManagerControlled;
            this.MainFormPanel.Controls.Add(this.AutoButton);
            this.MainFormPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.MainFormPanel.Location = new System.Drawing.Point(0, 0);
            this.MainFormPanel.Name = "MainFormPanel";
            this.MainFormPanel.Size = new System.Drawing.Size(841, 548);
            this.MainFormPanel.Style.Alignment = System.Drawing.StringAlignment.Center;
            this.MainFormPanel.Style.BackColor1.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelBackground;
            this.MainFormPanel.Style.BackColor2.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelBackground2;
            this.MainFormPanel.Style.Border = DevComponents.DotNetBar.eBorderType.SingleLine;
            this.MainFormPanel.Style.BorderColor.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelBorder;
            this.MainFormPanel.Style.ForeColor.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelText;
            this.MainFormPanel.Style.GradientAngle = 90;
            this.MainFormPanel.TabIndex = 0;
            // 
            // AutoButton
            // 
            this.AutoButton.AccessibleRole = System.Windows.Forms.AccessibleRole.PushButton;
            this.AutoButton.ColorTable = DevComponents.DotNetBar.eButtonColor.OrangeWithBackground;
            this.AutoButton.Location = new System.Drawing.Point(680, 475);
            this.AutoButton.Name = "AutoButton";
            this.AutoButton.Size = new System.Drawing.Size(149, 61);
            this.AutoButton.Style = DevComponents.DotNetBar.eDotNetBarStyle.StyleManagerControlled;
            this.AutoButton.TabIndex = 0;
            this.AutoButton.Text = "自动执行";
            this.AutoButton.Click += new System.EventHandler(this.AutoButton_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(841, 548);
            this.Controls.Add(this.MainFormPanel);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "DNF脚本";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.MainForm_FormClosed);
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.MainFormPanel.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private DevComponents.DotNetBar.PanelEx MainFormPanel;
        private DevComponents.DotNetBar.ButtonX AutoButton;
    }
}

