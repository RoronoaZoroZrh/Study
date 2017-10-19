using System;
using System.Windows.Forms;

namespace SoftRender
{
    static class Program
    {
        /// <summary>
        /// 应用程序的主入口点。
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false); //!GDI+上显示文本
            Application.Run(new SoftRender());
        }
    }
}