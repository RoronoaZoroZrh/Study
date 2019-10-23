/**
 *  author : Tiger
 *  date   : 2017-04-02 11:35:37
 *  brief  : 阴阳师自动脚本
 */
using System;
using System.Windows.Forms;

namespace YinYangShi
{
    public partial class FormYinYangShi : Form
    {
        public FormYinYangShi() { InitializeComponent(); }

        private void ButtonAutoSearch_Click(Object sender, EventArgs e)
        {
            LogInfo("自动探索开始...", true);
            Win32API.MoveWindow(Win32API.GetWindowPtr());
            Boolean excuteState = true;
            do
            {
                Int32 posX = new Random().Next(-5, 5) + 920;
                Int32 posY = new Random().Next(-5, 5) + 400;
                Win32API.MouseClick(posX, posY, 3);
                posX = new Random().Next(-5, 5) + 720;
                posY = new Random().Next(-5, 5) + 440;
                Win32API.MouseClick(posX, posY, 3);

                LogInfo("击杀怪物开始...");
                for (Int32 i = 1; i <= 70; i++)
                {
                    if (Control.MousePosition.X != posX && Control.MousePosition.Y != posY)
                    {
                        excuteState = false;
                        break;
                    }
                    LogInfo(String.Format("第{0:D2}次寻找怪物...", i));
                    posX = new Random().Next(-5, 5) + 520;
                    posY = new Random().Next(-5, 5) + 220;
                    Win32API.MouseClick(posX, posY, 2);
                    Win32API.MouseClick(posX, posY - 60, 2);
                }

                if (excuteState)
                {
                    posX = new Random().Next(-2, 2) + 40;
                    posY = new Random().Next(-2, 2) + 70;
                    Win32API.MouseClick(posX, posY, 5);
                    Win32API.MouseClick(posX, posY, 3);
                    posX = new Random().Next(-5, 5) + 600;
                    posY = new Random().Next(-5, 5) + 350;
                    Win32API.MouseClick(posX, posY, 2);
                }
            }
            while (excuteState);
            LogInfo("自动探索结束...");
        }

        private void ButtonAutoBreak_Click(object sender, EventArgs e)
        {
            LogInfo("自动突破开始...", true);
            Win32API.MoveWindow(Win32API.GetWindowPtr());
            Int32 breakCnt = 0;
            Boolean excuteState = true;
            do
            {
                Int32 posX = new Random().Next(-5, 5) + 250;
                Int32 posY = new Random().Next(-5, 5) + 560;
                Win32API.MouseClick(posX, posY, 3);

                Win32API.MouseClick(700, 500, 2);
                for (Int32 i = 260; i <= 800; i = i + 270)
                {
                    for (Int32 j = 150; j <= 370; j = j + 110)
                    {
                        if (Control.MousePosition.X != 700 && Control.MousePosition.Y != 500)
                        {
                            excuteState = false;
                            break;
                        }
                        else
                        {
                            LogInfo(String.Format("第{0:D2}次突破...", ++breakCnt));
                            posX = new Random().Next(-2, 2) + i;
                            posY = new Random().Next(-2, 2) + j;
                            Win32API.MouseClick(posX, posY, 2);
                            Win32API.MouseClick(posX + 20, posY + 140, 40);
                            Win32API.MouseClick(700, 500, 5);
                            Win32API.MouseClick(700, 500, 5);
                            Win32API.MouseClick(700, 500, 5);
                        }
                    }
                }

                Win32API.MouseClick(800, 450, 3);
                Win32API.MouseClick(560, 360, 3);
            }
            while (excuteState);
            LogInfo("自动突破结束...");
        }

        private void ButtonThrow_Click(object sender, EventArgs e)
        {
            LogInfo("自动百鬼夜行开始...", true);
            Int32 iCnt = IntegerInputI.Value;
            Int32 tCnt = IntegerInputT.Value;
            Win32API.MoveWindow(Win32API.GetWindowPtr());
            Boolean excuteState = true;
            do
            {
                if (--iCnt >= 0)
                {
                    Int32 posX = new Random().Next(-5, 5) + 250;
                    Int32 posY = new Random().Next(-5, 5) + 450;
                    Win32API.MouseClick(posX, posY, 3);
                    posX = new Random().Next(-5, 5) + 400;
                    posY = new Random().Next(-5, 5) + 250;
                    Win32API.MouseClick(posX, posY, 3);
                }

                if (--tCnt >= 0)
                {
                    LogInfo(String.Format("第{0:D2}次百鬼...", IntegerInputT.Value - tCnt));
                    Int32 posX = new Random().Next(-5, 5) + 750;
                    Int32 posY = new Random().Next(-5, 5) + 450;
                    Win32API.MouseClick(posX, posY, 3);
                    Win32API.MouseClick(posX + 50, posY - 50, 3, false);

                    posX = new Random().Next(-5, 5) + 900;
                    posY = new Random().Next(-5, 5) + 500;
                    Win32API.MouseClick(posX, posY, 3);
                    for (int i = 1; i <= 150; ++i)
                    {
                        LogInfo(String.Format("第{0:D3}次扔豆...", i));
                        if (Control.MousePosition.X != posX && Control.MousePosition.Y != posY)
                        {
                            excuteState = false;
                            break;
                        }
                        else
                        {
                            posX = new Random().Next(-5, 5) + 850;
                            posY = new Random().Next(-5, 5) + 350;
                            Win32API.MouseClick(posX, posY, 0.5f);
                        }
                    }
                    Win32API.MouseClick(800, 580, 3);
                }
                else
                    excuteState = false;
            }
            while (excuteState);
            LogInfo("自动百鬼夜行结束...");
        }

        //!测试代码
        private void Form1_Load(object sender, EventArgs e)
        {
            this.PanelYinYangShi.MouseClick += new MouseEventHandler(Form1_MouseClick);
        }

        //!测试代码
        void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            MessageBox.Show("X :" + e.X.ToString() + "Y :" + e.Y.ToString());

        }

        //!自动觉醒
        private void ButtonAwake_Click(object sender, EventArgs e)
        {
            //!改变命令状态
            mExcuteState = false;

            //!显示日志
            RichTextBoxLog.Text = RichTextBoxLog.Text + "自动觉醒开始..." + Environment.NewLine;

            //!进入觉醒界面
            Win32API.MouseClick(85, 670, 5);

            //!No.1
            Win32API.MouseClick(250, 350, 5);

            //!觉醒
            int nAwakeTimes = 1; //!统计觉醒次数
            while (!mExcuteState)
            {
                //!显示日志
                RichTextBoxLog.Text = RichTextBoxLog.Text + "第" + nAwakeTimes++.ToString() + "次觉醒..." + Environment.NewLine;

                //!设置滚动位置
                RichTextBoxLog.SelectionStart = RichTextBoxLog.Text.Length;
                RichTextBoxLog.ScrollToCaret();

                //!刷新
                Update();

                //!点击挑战
                Win32API.MouseClick(0950, 500, 10);
                Win32API.MouseClick(1100, 600, 60);

                //!获取奖励
                Win32API.MouseClick(1100, 600, 01);
                Win32API.MouseClick(1100, 600, 01);
                Win32API.MouseClick(1100, 600, 01);
                Win32API.MouseClick(1100, 600, 01);
                Win32API.MouseClick(1100, 600, 10);

                //!停止
                if (Control.MousePosition.X != 1100 && Control.MousePosition.Y != 600)
                {
                    //!停止
                    mExcuteState = true;

                    //!显示日志
                    RichTextBoxLog.Text = RichTextBoxLog.Text + "自动觉醒停止..." + Environment.NewLine;
                    break;
                }
            }

            //!显示日志
            RichTextBoxLog.Text = RichTextBoxLog.Text + "自动觉醒结束..." + Environment.NewLine + Environment.NewLine;
        }

        private void LogInfo(String message, Boolean clear = false)
        {
            if (clear)
                RichTextBoxLog.Text = "";
            RichTextBoxLog.Text = String.Format("{0}{1} {2}{3}", RichTextBoxLog.Text, DateTime.Now, message, Environment.NewLine);
            RichTextBoxLog.SelectionStart = RichTextBoxLog.Text.Length;
            RichTextBoxLog.ScrollToCaret();
            Update();
        }

        private Boolean mExcuteState = false;
    }
}