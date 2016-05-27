namespace Plan
{
    partial class ItemDetail
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(ItemDetail));
            this.PanelItemDetail = new DevComponents.DotNetBar.PanelEx();
            this.ButtonCancel = new DevComponents.DotNetBar.ButtonX();
            this.ButtonCertain = new DevComponents.DotNetBar.ButtonX();
            this.TextBoxDetail = new DevComponents.DotNetBar.Controls.TextBoxX();
            this.LabelDetail = new DevComponents.DotNetBar.LabelX();
            this.LabelSummary = new DevComponents.DotNetBar.LabelX();
            this.TextBoxSummary = new DevComponents.DotNetBar.Controls.TextBoxX();
            this.PanelItemDetail.SuspendLayout();
            this.SuspendLayout();
            // 
            // PanelItemDetail
            // 
            this.PanelItemDetail.CanvasColor = System.Drawing.SystemColors.Control;
            this.PanelItemDetail.ColorSchemeStyle = DevComponents.DotNetBar.eDotNetBarStyle.StyleManagerControlled;
            this.PanelItemDetail.Controls.Add(this.ButtonCancel);
            this.PanelItemDetail.Controls.Add(this.ButtonCertain);
            this.PanelItemDetail.Controls.Add(this.TextBoxDetail);
            this.PanelItemDetail.Controls.Add(this.LabelDetail);
            this.PanelItemDetail.Controls.Add(this.LabelSummary);
            this.PanelItemDetail.Controls.Add(this.TextBoxSummary);
            this.PanelItemDetail.Dock = System.Windows.Forms.DockStyle.Fill;
            this.PanelItemDetail.Location = new System.Drawing.Point(0, 0);
            this.PanelItemDetail.Name = "PanelItemDetail";
            this.PanelItemDetail.Size = new System.Drawing.Size(548, 292);
            this.PanelItemDetail.Style.Alignment = System.Drawing.StringAlignment.Center;
            this.PanelItemDetail.Style.BackColor1.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelBackground;
            this.PanelItemDetail.Style.Border = DevComponents.DotNetBar.eBorderType.SingleLine;
            this.PanelItemDetail.Style.BorderColor.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelBorder;
            this.PanelItemDetail.Style.ForeColor.ColorSchemePart = DevComponents.DotNetBar.eColorSchemePart.PanelText;
            this.PanelItemDetail.Style.GradientAngle = 90;
            this.PanelItemDetail.TabIndex = 0;
            // 
            // ButtonCancel
            // 
            this.ButtonCancel.AccessibleRole = System.Windows.Forms.AccessibleRole.PushButton;
            this.ButtonCancel.ColorTable = DevComponents.DotNetBar.eButtonColor.OrangeWithBackground;
            this.ButtonCancel.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.ButtonCancel.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.ButtonCancel.Location = new System.Drawing.Point(417, 242);
            this.ButtonCancel.Name = "ButtonCancel";
            this.ButtonCancel.Size = new System.Drawing.Size(119, 42);
            this.ButtonCancel.Style = DevComponents.DotNetBar.eDotNetBarStyle.StyleManagerControlled;
            this.ButtonCancel.TabIndex = 5;
            this.ButtonCancel.Text = "取消";
            // 
            // ButtonCertain
            // 
            this.ButtonCertain.AccessibleRole = System.Windows.Forms.AccessibleRole.PushButton;
            this.ButtonCertain.ColorTable = DevComponents.DotNetBar.eButtonColor.OrangeWithBackground;
            this.ButtonCertain.DialogResult = System.Windows.Forms.DialogResult.OK;
            this.ButtonCertain.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.ButtonCertain.Location = new System.Drawing.Point(263, 242);
            this.ButtonCertain.Name = "ButtonCertain";
            this.ButtonCertain.Size = new System.Drawing.Size(119, 42);
            this.ButtonCertain.Style = DevComponents.DotNetBar.eDotNetBarStyle.StyleManagerControlled;
            this.ButtonCertain.TabIndex = 4;
            this.ButtonCertain.Text = "确定";
            // 
            // TextBoxDetail
            // 
            // 
            // 
            // 
            this.TextBoxDetail.Border.Class = "TextBoxBorder";
            this.TextBoxDetail.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.TextBoxDetail.Location = new System.Drawing.Point(119, 50);
            this.TextBoxDetail.Multiline = true;
            this.TextBoxDetail.Name = "TextBoxDetail";
            this.TextBoxDetail.Size = new System.Drawing.Size(417, 186);
            this.TextBoxDetail.TabIndex = 3;
            // 
            // LabelDetail
            // 
            this.LabelDetail.AutoSize = true;
            // 
            // 
            // 
            this.LabelDetail.BackgroundStyle.Class = "";
            this.LabelDetail.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.LabelDetail.Location = new System.Drawing.Point(12, 50);
            this.LabelDetail.Name = "LabelDetail";
            this.LabelDetail.Size = new System.Drawing.Size(90, 23);
            this.LabelDetail.TabIndex = 2;
            this.LabelDetail.Text = "详细说明：";
            // 
            // LabelSummary
            // 
            this.LabelSummary.AutoSize = true;
            // 
            // 
            // 
            this.LabelSummary.BackgroundStyle.Class = "";
            this.LabelSummary.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.LabelSummary.Location = new System.Drawing.Point(12, 12);
            this.LabelSummary.Name = "LabelSummary";
            this.LabelSummary.Size = new System.Drawing.Size(90, 23);
            this.LabelSummary.TabIndex = 1;
            this.LabelSummary.Text = "概要说明：";
            // 
            // TextBoxSummary
            // 
            // 
            // 
            // 
            this.TextBoxSummary.Border.Class = "TextBoxBorder";
            this.TextBoxSummary.Font = new System.Drawing.Font("宋体", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.TextBoxSummary.Location = new System.Drawing.Point(119, 10);
            this.TextBoxSummary.Name = "TextBoxSummary";
            this.TextBoxSummary.Size = new System.Drawing.Size(417, 26);
            this.TextBoxSummary.TabIndex = 0;
            // 
            // ItemDetail
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.CancelButton = this.ButtonCancel;
            this.ClientSize = new System.Drawing.Size(548, 292);
            this.ControlBox = false;
            this.Controls.Add(this.PanelItemDetail);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "ItemDetail";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "详细信息";
            this.PanelItemDetail.ResumeLayout(false);
            this.PanelItemDetail.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private DevComponents.DotNetBar.PanelEx PanelItemDetail;
        private DevComponents.DotNetBar.Controls.TextBoxX TextBoxSummary;
        private DevComponents.DotNetBar.LabelX LabelSummary;
        private DevComponents.DotNetBar.LabelX LabelDetail;
        private DevComponents.DotNetBar.Controls.TextBoxX TextBoxDetail;
        private DevComponents.DotNetBar.ButtonX ButtonCertain;
        private DevComponents.DotNetBar.ButtonX ButtonCancel;
    }
}