namespace Xml_Operation_20190505
{
    partial class Form_TransferTool
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
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.TextBox_Input = new System.Windows.Forms.TextBox();
            this.Label_Input = new System.Windows.Forms.Label();
            this.Button_Input = new System.Windows.Forms.Button();
            this.RichTextBox_Output = new System.Windows.Forms.RichTextBox();
            this.Button_Run = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // TextBox_Input
            // 
            this.TextBox_Input.Location = new System.Drawing.Point(83, 26);
            this.TextBox_Input.Name = "TextBox_Input";
            this.TextBox_Input.Size = new System.Drawing.Size(410, 21);
            this.TextBox_Input.TabIndex = 0;
            // 
            // Label_Input
            // 
            this.Label_Input.AutoSize = true;
            this.Label_Input.Location = new System.Drawing.Point(12, 30);
            this.Label_Input.Name = "Label_Input";
            this.Label_Input.Size = new System.Drawing.Size(65, 12);
            this.Label_Input.TabIndex = 1;
            this.Label_Input.Text = "关卡目录：";
            // 
            // Button_Input
            // 
            this.Button_Input.Location = new System.Drawing.Point(499, 25);
            this.Button_Input.Name = "Button_Input";
            this.Button_Input.Size = new System.Drawing.Size(92, 23);
            this.Button_Input.TabIndex = 2;
            this.Button_Input.Text = "...";
            this.Button_Input.UseVisualStyleBackColor = true;
            this.Button_Input.Click += new System.EventHandler(this.Button_Input_Click);
            // 
            // RichTextBox_Output
            // 
            this.RichTextBox_Output.Location = new System.Drawing.Point(14, 53);
            this.RichTextBox_Output.Name = "RichTextBox_Output";
            this.RichTextBox_Output.Size = new System.Drawing.Size(479, 161);
            this.RichTextBox_Output.TabIndex = 3;
            this.RichTextBox_Output.Text = "";
            // 
            // Button_Run
            // 
            this.Button_Run.Location = new System.Drawing.Point(499, 54);
            this.Button_Run.Name = "Button_Run";
            this.Button_Run.Size = new System.Drawing.Size(92, 160);
            this.Button_Run.TabIndex = 4;
            this.Button_Run.Text = "转换";
            this.Button_Run.UseVisualStyleBackColor = true;
            this.Button_Run.Click += new System.EventHandler(this.Button_Run_Click);
            // 
            // Form_TransferTool
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(603, 226);
            this.Controls.Add(this.Button_Run);
            this.Controls.Add(this.RichTextBox_Output);
            this.Controls.Add(this.Button_Input);
            this.Controls.Add(this.Label_Input);
            this.Controls.Add(this.TextBox_Input);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Name = "Form_TransferTool";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "关卡转换工具";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox TextBox_Input;
        private System.Windows.Forms.Label Label_Input;
        private System.Windows.Forms.Button Button_Input;
        private System.Windows.Forms.RichTextBox RichTextBox_Output;
        private System.Windows.Forms.Button Button_Run;
    }
}

