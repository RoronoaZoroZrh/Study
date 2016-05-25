namespace Plan
{
    partial class ItemComplete
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.PanelItemComplete = new DevComponents.DotNetBar.PanelEx();
            this.ListBoxComplete = new System.Windows.Forms.ListBox();
            this.ButtonCertain = new DevComponents.DotNetBar.ButtonX();
            this.PanelItemComplete.SuspendLayout();
            this.SuspendLayout();
            // 
            // PanelItemComplete
            // 
            this.PanelItemComplete.CanvasColor = System.Drawing.SystemColors.Control;
            this.PanelItemComplete.ColorSchemeStyle = DevComponents.DotNetBar.eDotNetBarStyle.StyleManagerControlled;
            this.PanelItemComplete.Controls.Add(this.ButtonCertain);
            this.PanelItemComplete.Controls.Add(this.ListBoxComplete);
            this.PanelItemComplete.Dock = System.Windows.Forms.DockStyle.Fill;
            this.PanelItemComplete.Location = new System.Drawing.Point(0, 0);
            this.PanelItemComplete.Name = "PanelItemComplete";
            this.PanelItemComplete.Size = new System.Drawing.Size(571, 547);
            this.PanelItemComplete.Style.Alignment = System.Drawing.StringAlignment.Center;
            this.PanelItemComplete.Style.BackColor1.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelBackground;
            this.PanelItemComplete.Style.Border = DevComponents.DotNetBar.eBorderType.SingleLine;
            this.PanelItemComplete.Style.BorderColor.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelBorder;
            this.PanelItemComplete.Style.ForeColor.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelText;
            this.PanelItemComplete.Style.GradientAngle = 90;
            this.PanelItemComplete.TabIndex = 0;
            // 
            // ListBoxComplete
            // 
            this.ListBoxComplete.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.ListBoxComplete.Dock = System.Windows.Forms.DockStyle.Top;
            this.ListBoxComplete.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.ListBoxComplete.FormattingEnabled = true;
            this.ListBoxComplete.ItemHeight = 16;
            this.ListBoxComplete.Location = new System.Drawing.Point(0, 0);
            this.ListBoxComplete.Name = "ListBoxComplete";
            this.ListBoxComplete.Size = new System.Drawing.Size(571, 482);
            this.ListBoxComplete.TabIndex = 0;
            this.ListBoxComplete.DoubleClick += new System.EventHandler(this.ListBoxComplete_DoubleClick);
            // 
            // ButtonCertain
            // 
            this.ButtonCertain.AccessibleRole = System.Windows.Forms.AccessibleRole.PushButton;
            this.ButtonCertain.ColorTable = DevComponents.DotNetBar.eButtonColor.OrangeWithBackground;
            this.ButtonCertain.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.ButtonCertain.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ButtonCertain.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.ButtonCertain.Location = new System.Drawing.Point(0, 482);
            this.ButtonCertain.Name = "ButtonCertain";
            this.ButtonCertain.Size = new System.Drawing.Size(571, 65);
            this.ButtonCertain.Style = DevComponents.DotNetBar.eDotNetBarStyle.StyleManagerControlled;
            this.ButtonCertain.TabIndex = 1;
            this.ButtonCertain.Text = "确定";
            // 
            // ItemComplete
            // 
            this.AcceptButton = this.ButtonCertain;
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.ButtonCertain;
            this.ClientSize = new System.Drawing.Size(571, 547);
            this.ControlBox = false;
            this.Controls.Add(this.PanelItemComplete);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "ItemComplete";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "已完成";
            this.PanelItemComplete.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private DevComponents.DotNetBar.PanelEx PanelItemComplete;
        private System.Windows.Forms.ListBox ListBoxComplete;
        private DevComponents.DotNetBar.ButtonX ButtonCertain;
    }
}