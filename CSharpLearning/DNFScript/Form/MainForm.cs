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
            //!获取DNF句柄
            m_vDNFPtr = Win32API.GetDNFWindowPtr();

            //!移动游戏到原点
            Win32API.MoveDNFWindow(m_vDNFPtr);
        }

        //!DNF句柄
        private IntPtr m_vDNFPtr = IntPtr.Zero;
    }
}