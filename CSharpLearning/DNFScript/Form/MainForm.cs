using System;
using System.Windows.Forms;

namespace DNFScript
{
    //!主界面
    public partial class MainForm : Form
    {
        //!构造函数
        public MainForm()
        {
            InitializeComponent();
        }

        //!加载
        private void MainForm_Load(object sender, EventArgs e)
        {
            //!获取句柄
            GetDNFWindowPtr();
        }

        //!关闭
        private void MainForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            //!清理资源
            DNFScriptLog.Clean();
        }

        //!自动执行
        private void AutoButton_Click(object sender, EventArgs e)
        {
            AutoButton.Enabled = false;
            while (true)
            {
                Win32API.GoLeft();
            }
            AutoButton.Enabled = true;
        }

        //!获取句柄
        private void GetDNFWindowPtr()
        {
            //!获取DNF句柄
            m_vDNFPtr = Win32API.GetDNFWindowPtr();

            //!移动游戏到原点
            Win32API.MoveDNFWindow(m_vDNFPtr);
            if (IntPtr.Zero == m_vDNFPtr)
            {
                DNFScriptLog.LogError("获取DNF句柄失败...");
            }
            else
            {
                DNFScriptLog.LogInfo("获取DNF句柄成功...");
            }
        }

        //!DNF句柄
        private IntPtr m_vDNFPtr = IntPtr.Zero;
    }
}