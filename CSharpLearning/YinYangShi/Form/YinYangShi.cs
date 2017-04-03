/**
 *  author : Tiger
 *  date   : 2017-04-02 11:35:37
 *  brief  : 阴阳师自动脚本
 */
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
            Win32API.MouseClick(1100, 200, 3);

            //!点击探索按钮
            Win32API.MouseClick(0980, 555, 3);

            //!无限循环探索副本
            while (!m_bStopCmd)
            {
                //!循环100次、寻找怪物
                RichTextBoxLog.Text = RichTextBoxLog.Text + "击杀怪物开始..." + Environment.NewLine;
                for (int i = 1; i <= 100; i++)
                {
                    //!显示日志
                    RichTextBoxLog.Text = RichTextBoxLog.Text + "第" + i.ToString() + "次寻找..." + Environment.NewLine;

                    //!寻找小怪
                    Win32API.MouseClick(655, 310, 2);

                    //!停止
                    if (Control.MousePosition.X != 655 && Control.MousePosition.Y != 310)
                    {
                        //!停止
                        m_bStopCmd = true;

                        //!显示日志
                        RichTextBoxLog.Text = RichTextBoxLog.Text + "寻找怪物停止..." + Environment.NewLine;
                        break;
                    }

                    //!设置滚动位置
                    RichTextBoxLog.SelectionStart = RichTextBoxLog.Text.Length;
                    RichTextBoxLog.ScrollToCaret();

                    //!刷新
                    Update();
                }
                RichTextBoxLog.Text = RichTextBoxLog.Text + "击杀怪物结束..." + Environment.NewLine;

                //!退出
                if (m_bStopCmd)
                {
                    break;
                }

                //!退出探索副本
                Win32API.MouseClick(75, 90, 5); //!避免界面卡住
                Win32API.MouseClick(75, 90, 3);
                Win32API.MouseClick(740, 405, 3);

                //!选择固定位置章节
                Win32API.MouseClick(1100, 200, 3);

                //!点击探索按钮
                Win32API.MouseClick(0980, 555, 3);
            }

            //!显示日志
            RichTextBoxLog.Text = RichTextBoxLog.Text + "自动探索结束..." + Environment.NewLine + Environment.NewLine;
        }

        //!自动结界突破
        private void ButtonAutoBreak_Click(object sender, EventArgs e)
        {
            //!改变命令状态
            m_bStopCmd = false;

            //!显示日志
            RichTextBoxLog.Text = RichTextBoxLog.Text + "自动突破开始..." + Environment.NewLine;

            //!点击结界突破按钮
            Win32API.MouseClick(400, 660, 3);

            //!突破
            int nBreakCnt = 1;
            while (!m_bStopCmd)
            {
                for (int i = 300; i <= 1000; i += 350)
                {
                    for (int j = 180; j <= 420; j += 120)
                    {
                        //!显示日志
                        RichTextBoxLog.Text = RichTextBoxLog.Text + "第" + nBreakCnt.ToString() + "次突破..." + Environment.NewLine;

                        //!设置滚动位置
                        RichTextBoxLog.SelectionStart = RichTextBoxLog.Text.Length;
                        RichTextBoxLog.ScrollToCaret();

                        //!刷新
                        Update();

                        //!点击突破
                        Win32API.MouseClick(i, j, 3);

                        //!点击挑战
                        Win32API.MouseClick(i + 60, j + 110, 10);
                        Win32API.MouseClick(1100, 600, 60);

                        //!点击退出
                        Win32API.MouseClick(1100, 600, 5);
                        Win32API.MouseClick(1100, 600, 5);
                        Win32API.MouseClick(1100, 600, 5);
                        Win32API.MouseClick(1100, 600, 5); //退出奖励界面
                        Win32API.MouseClick(1100, 600, 5); //退出奖励界面
                        Win32API.MouseClick(1100, 600, 1); //退出奖励界面
                        Win32API.MouseClick(1100, 600, 1); //退出奖励界面
                        Win32API.MouseClick(1100, 600, 9); //退出奖励界面

                        //!累计突破次数
                        ++nBreakCnt;
                    }
                }

                //!退出
                if (nBreakCnt >= 18)
                {
                    break;
                }
            }

            //!显示日志
            RichTextBoxLog.Text = RichTextBoxLog.Text + "自动突破结束..." + Environment.NewLine + Environment.NewLine;
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