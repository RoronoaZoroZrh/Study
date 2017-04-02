using System;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace YinYangShi
{
    public partial class FormYinYangShi : Form
    {
        //!构造函数
        public FormYinYangShi()
        {
            InitializeComponent();
        }

        //!自动探索、探索固定章节
        private void ButtonAutoSearch_Click(object sender, EventArgs e)
        {
            //!改变命令状态
            m_bStopCmd = false;

            //!显示日志
            RichTextBoxLog.Text = RichTextBoxLog.Text + "自动探索开始..." + Environment.NewLine;

            //!选择固定位置章节


            //!显示日志
            RichTextBoxLog.Text = RichTextBoxLog.Text + "自动探索结束..." + Environment.NewLine;
        }

        //!停止命令
        private Boolean m_bStopCmd = false;

        private void Form1_Load(object sender, EventArgs e)
        {
            this.PanelYinYangShi.MouseClick += new MouseEventHandler(Form1_MouseClick);
        }

        void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            MessageBox.Show("X :" + e.X.ToString() + "Y :" + e.Y.ToString());

        }

        private void button1_Click(object sender, EventArgs e)
        {
            int x = 660;
            int y = 150;

            m_bFlag = true;

            //!3秒后点击鼠标
            Win32API.SetCurPos(x, y);
            Win32API.MouseClick(3);

            //!3秒后点击鼠标
            Win32API.SetCurPos(1100, 200);
            Win32API.MouseClick(3);

            Win32API.SetCurPos(980, 555);
            Win32API.MouseClick(3);

            while (m_bFlag)
            {
                for (int i = 0; i < 90; i++)
                {
                    Win32API.SetCurPos(650, 330);
                    Win32API.MouseClick(2);
                }

                for (int i = 0; i < 20; i++)
                {
                    Win32API.SetCurPos(300, 240);
                    Win32API.MouseClick(1);
                }

                Win32API.SetCurPos(0, 0);
                Win32API.MouseClick(3);


                for (int i = 400; i < 800; i += 30)
                {
                    for (int j = 300; j < 600; j += 30)
                    {
                        Win32API.SetCurPos(i, j);
                        Win32API.MouseClick(0.2f);
                    }
                }

                Win32API.SetCurPos(1100, 200);
                Win32API.MouseClick(3);

                Win32API.SetCurPos(980, 555);
                Win32API.MouseClick(3);
            }
        }


        [StructLayout(LayoutKind.Sequential)]
        struct NativeRECT
        {
            public int left;
            public int top;
            public int right;
            public int bottom;
        }


        private Boolean m_bFlag = false;

        [DllImport("user32.dll")]
        static extern IntPtr FindWindow(string strClass, string strWindow);

        [DllImport("user32.dll")]
        static extern IntPtr FindWindowEx(HandleRef hwndParent, HandleRef hwndChildAfter, string strClass, string strWindow);

        [DllImport("user32.dll")]
        static extern bool GetWindowRect(HandleRef hwnd, out NativeRECT rect);

        private void button1_Click_1(object sender, EventArgs e)
        {
            //             m_bFlag = false;
            // 
            //             for (int i = 0; i < 20; i++)
            //             {
            //                 Thread.Sleep(3000);
            // 
            //                 Win32API.SetCurPos(300, 220);
            //                 mouse_event(MouseEventFlag.LeftDown, 0, 0, 0, 0);
            //                 mouse_event(MouseEventFlag.LeftUp, 0, 0, 0, 0);
            //                 mouse_event(MouseEventFlag.LeftDown, 0, 0, 0, 0);
            //                 mouse_event(MouseEventFlag.LeftUp, 0, 0, 0, 0);
            //             }
        }
    }
}