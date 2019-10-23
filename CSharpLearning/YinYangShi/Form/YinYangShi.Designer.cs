namespace YinYangShi
{
    partial class FormYinYangShi
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
            this.PanelYinYangShi = new DevComponents.DotNetBar.PanelEx();
            this.ButtonAwake = new DevComponents.DotNetBar.ButtonX();
            this.RichTextBoxLog = new System.Windows.Forms.RichTextBox();
            this.ButtonAutoBreak = new DevComponents.DotNetBar.ButtonX();
            this.ButtonAutoSearch = new DevComponents.DotNetBar.ButtonX();
            this.ButtonThrow = new DevComponents.DotNetBar.ButtonX();
            this.IntegerInputI = new DevComponents.Editors.IntegerInput();
            this.IntegerInputT = new DevComponents.Editors.IntegerInput();
            this.PanelYinYangShi.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.IntegerInputI)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.IntegerInputT)).BeginInit();
            this.SuspendLayout();
            // 
            // PanelYinYangShi
            // 
            this.PanelYinYangShi.CanvasColor = System.Drawing.SystemColors.Control;
            this.PanelYinYangShi.ColorSchemeStyle = DevComponents.DotNetBar.eDotNetBarStyle.StyleManagerControlled;
            this.PanelYinYangShi.Controls.Add(this.IntegerInputT);
            this.PanelYinYangShi.Controls.Add(this.IntegerInputI);
            this.PanelYinYangShi.Controls.Add(this.ButtonThrow);
            this.PanelYinYangShi.Controls.Add(this.ButtonAwake);
            this.PanelYinYangShi.Controls.Add(this.RichTextBoxLog);
            this.PanelYinYangShi.Controls.Add(this.ButtonAutoBreak);
            this.PanelYinYangShi.Controls.Add(this.ButtonAutoSearch);
            this.PanelYinYangShi.Dock = System.Windows.Forms.DockStyle.Fill;
            this.PanelYinYangShi.Location = new System.Drawing.Point(0, 0);
            this.PanelYinYangShi.Name = "PanelYinYangShi";
            this.PanelYinYangShi.Size = new System.Drawing.Size(1093, 603);
            this.PanelYinYangShi.Style.Alignment = System.Drawing.StringAlignment.Center;
            this.PanelYinYangShi.Style.BackColor1.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelBackground;
            this.PanelYinYangShi.Style.BackColor2.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelBackground2;
            this.PanelYinYangShi.Style.Border = DevComponents.DotNetBar.eBorderType.SingleLine;
            this.PanelYinYangShi.Style.BorderColor.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelBorder;
            this.PanelYinYangShi.Style.ForeColor.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelText;
            this.PanelYinYangShi.Style.GradientAngle = 90;
            this.PanelYinYangShi.TabIndex = 0;
            // 
            // ButtonAwake
            // 
            this.ButtonAwake.AccessibleRole = System.Windows.Forms.AccessibleRole.PushButton;
            this.ButtonAwake.ColorTable = DevComponents.DotNetBar.eButtonColor.OrangeWithBackground;
            this.ButtonAwake.Location = new System.Drawing.Point(12, 83);
            this.ButtonAwake.Name = "ButtonAwake";
            this.ButtonAwake.Size = new System.Drawing.Size(132, 53);
            this.ButtonAwake.Style = DevComponents.DotNetBar.eDotNetBarStyle.StyleManagerControlled;
            this.ButtonAwake.TabIndex = 5;
            this.ButtonAwake.Text = "自动觉醒";
            this.ButtonAwake.Click += new System.EventHandler(this.ButtonAwake_Click);
            // 
            // RichTextBoxLog
            // 
            this.RichTextBoxLog.Location = new System.Drawing.Point(310, 12);
            this.RichTextBoxLog.Name = "RichTextBoxLog";
            this.RichTextBoxLog.Size = new System.Drawing.Size(771, 579);
            this.RichTextBoxLog.TabIndex = 4;
            this.RichTextBoxLog.Text = "";
            // 
            // ButtonAutoBreak
            // 
            this.ButtonAutoBreak.AccessibleRole = System.Windows.Forms.AccessibleRole.PushButton;
            this.ButtonAutoBreak.ColorTable = DevComponents.DotNetBar.eButtonColor.OrangeWithBackground;
            this.ButtonAutoBreak.Location = new System.Drawing.Point(163, 12);
            this.ButtonAutoBreak.Name = "ButtonAutoBreak";
            this.ButtonAutoBreak.Size = new System.Drawing.Size(132, 53);
            this.ButtonAutoBreak.Style = DevComponents.DotNetBar.eDotNetBarStyle.StyleManagerControlled;
            this.ButtonAutoBreak.TabIndex = 3;
            this.ButtonAutoBreak.Text = "自动突破";
            this.ButtonAutoBreak.Click += new System.EventHandler(this.ButtonAutoBreak_Click);
            // 
            // ButtonAutoSearch
            // 
            this.ButtonAutoSearch.AccessibleRole = System.Windows.Forms.AccessibleRole.PushButton;
            this.ButtonAutoSearch.ColorTable = DevComponents.DotNetBar.eButtonColor.OrangeWithBackground;
            this.ButtonAutoSearch.Location = new System.Drawing.Point(12, 12);
            this.ButtonAutoSearch.Name = "ButtonAutoSearch";
            this.ButtonAutoSearch.Size = new System.Drawing.Size(132, 53);
            this.ButtonAutoSearch.Style = DevComponents.DotNetBar.eDotNetBarStyle.StyleManagerControlled;
            this.ButtonAutoSearch.TabIndex = 2;
            this.ButtonAutoSearch.Text = "自动探索";
            this.ButtonAutoSearch.Click += new System.EventHandler(this.ButtonAutoSearch_Click);
            // 
            // ButtonThrow
            // 
            this.ButtonThrow.AccessibleRole = System.Windows.Forms.AccessibleRole.PushButton;
            this.ButtonThrow.ColorTable = DevComponents.DotNetBar.eButtonColor.OrangeWithBackground;
            this.ButtonThrow.Location = new System.Drawing.Point(163, 154);
            this.ButtonThrow.Name = "ButtonThrow";
            this.ButtonThrow.Size = new System.Drawing.Size(132, 53);
            this.ButtonThrow.Style = DevComponents.DotNetBar.eDotNetBarStyle.StyleManagerControlled;
            this.ButtonThrow.TabIndex = 6;
            this.ButtonThrow.Text = "自动百鬼";
            this.ButtonThrow.Click += new System.EventHandler(this.ButtonThrow_Click);
            // 
            // IntegerInputI
            // 
            // 
            // 
            // 
            this.IntegerInputI.BackgroundStyle.Class = "DateTimeInputBackground";
            this.IntegerInputI.ButtonFreeText.Shortcut = DevComponents.DotNetBar.eShortcut.F2;
            this.IntegerInputI.Location = new System.Drawing.Point(12, 154);
            this.IntegerInputI.Name = "IntegerInputI";
            this.IntegerInputI.ShowUpDown = true;
            this.IntegerInputI.Size = new System.Drawing.Size(132, 21);
            this.IntegerInputI.TabIndex = 7;
            this.IntegerInputI.Value = 3;
            // 
            // IntegerInputT
            // 
            // 
            // 
            // 
            this.IntegerInputT.BackgroundStyle.Class = "DateTimeInputBackground";
            this.IntegerInputT.ButtonFreeText.Shortcut = DevComponents.DotNetBar.eShortcut.F2;
            this.IntegerInputT.Location = new System.Drawing.Point(12, 186);
            this.IntegerInputT.Name = "IntegerInputT";
            this.IntegerInputT.ShowUpDown = true;
            this.IntegerInputT.Size = new System.Drawing.Size(132, 21);
            this.IntegerInputT.TabIndex = 8;
            this.IntegerInputT.Value = 9;
            // 
            // FormYinYangShi
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1093, 603);
            this.Controls.Add(this.PanelYinYangShi);
            this.Name = "FormYinYangShi";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "阴阳师帮助脚本";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.PanelYinYangShi.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.IntegerInputI)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.IntegerInputT)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private DevComponents.DotNetBar.PanelEx PanelYinYangShi;
        private DevComponents.DotNetBar.ButtonX ButtonAutoSearch;
        private DevComponents.DotNetBar.ButtonX ButtonAutoBreak;
        private System.Windows.Forms.RichTextBox RichTextBoxLog;
        private DevComponents.DotNetBar.ButtonX ButtonAwake;
        private DevComponents.DotNetBar.ButtonX ButtonThrow;
        private DevComponents.Editors.IntegerInput IntegerInputI;
        private DevComponents.Editors.IntegerInput IntegerInputT;
    }
}

