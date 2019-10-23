/**
 *  author : Tiger
 *  date   : 2017-05-20 22:49:51
 *  brief  : 封装Win32 API
 */
using System;
using System.Diagnostics;
using System.Runtime.InteropServices;
using System.Threading;

namespace DNFScript
{
    //!Win32接口类
    public static class Win32API
    {
        //!获取窗口句柄
        public static IntPtr GetDNFWindowPtr()
        {
            return Process.GetProcessesByName("DNF")[0].MainWindowHandle;
        }

        //!移动窗口到原点
        public static void MoveDNFWindow(IntPtr vDNFPtr)
        {
            MoveWindow(vDNFPtr, 0, 0, 800, 600, false);
        }

        //!向左移动
        public static void GoLeft()
        {
            SendMessage(GetDNFWindowPtr(), 0X100, 0X0D, 0); //输入ENTER（0x0d）

            keybd_event(0x25, 0, 0, 0);
            Thread.Sleep(100);
            keybd_event(0x25, 0, 2, 0);
        }

        //!Win32 API
        [DllImport("USER32.DLL", CharSet = CharSet.Auto)]
        public static extern int MoveWindow(IntPtr hWnd, int x, int y, int nWidth, int nHeight, bool BRePaint);
        [DllImport("USER32.DLL", CharSet = CharSet.Auto)]
        public static extern void keybd_event(Byte bVk, Byte bScan, int dwFlags, int dwExtraInfo);
        [DllImport("user32.dll")]
        private static extern int SendMessage(IntPtr hWnd, int Msg, int wParam, int lParam);
    }
}