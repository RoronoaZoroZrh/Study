/**
 *  author : Tiger
 *  date   : 2017-05-20 22:49:51
 *  brief  : 封装Win32 API
 */
using System;
using System.Diagnostics;
using System.Runtime.InteropServices;

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

        //!Win32 API
        [DllImport("user32.dll", CharSet = CharSet.Auto)]
        public static extern int MoveWindow(IntPtr hWnd, int x, int y, int nWidth, int nHeight, bool BRePaint);
    }
}