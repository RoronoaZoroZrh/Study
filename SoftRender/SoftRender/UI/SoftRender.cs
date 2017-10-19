using System;
using System.Windows.Forms;

namespace SoftRender
{
    //!窗体
    public partial class SoftRender : Form
    {
        //!构造
        public SoftRender()
        {
            InitializeComponent();
        }

        //!加载
        private void SoftRender_Load(object sender, System.EventArgs e)
        {
            CreateTimer();
            CreateRender();
        }

        //!构造定时器
        private void CreateTimer()
        {
            m_vTimer = new System.Timers.Timer(1000.0f / 30.0f);
            m_vTimer.Elapsed += Timer_Elapsed;
            m_vTimer.Enabled = true;
            m_vTimer.Start();
        }

        //!定时器触发事件
        private void Timer_Elapsed(object vSender, EventArgs vArgs)
        {
            m_vRender.Update();
        }

        //!构造软渲染器
        private void CreateRender()
        {
            m_vRender = new Render(CreateGraphics());
        }

        //!定时器
        private System.Timers.Timer m_vTimer = null;

        //!软渲染器
        private Render m_vRender = null;
    }
}