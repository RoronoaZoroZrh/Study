/**
 *  author : Tiger
 *  date   : 2017-03-26 19:40:08
 *  brief  : 封装Win32 API
 */
using System;
using System.Runtime.InteropServices;
using System.Threading;

namespace YinYangShi
{
    //!Win32 API类
    public static class Win32API
    {
        //!鼠标点击
        public static void MouseClick(float fTime)
        {
            //!鼠标点击
            mouse_event(MouseEventFlag.LeftDown, 0, 0, 0, 0);
            mouse_event(MouseEventFlag.LeftUp,   0, 0, 0, 0);
            mouse_event(MouseEventFlag.LeftDown, 0, 0, 0, 0);
            mouse_event(MouseEventFlag.LeftUp,   0, 0, 0, 0);

            //!鼠标点击间隔
            int nClickTime = (int)(m_nUint * fTime);
            Thread.Sleep(nClickTime);
        }

        //!设置鼠标位置
        public static void SetCurPos(int nX, int nY)
        {
            SetCursorPos(nX, nY);
        }

        //!鼠标点击
        public static void MouseClick(int nX, int nY, float fTime)
        {
            //!设置鼠标位置
            SetCurPos(nX, nY);

            //!鼠标点击
            MouseClick(fTime);
        }

        //!毫秒与秒换算单位
        private const int m_nUint = 1000;

        //!枚举声明
        [Flags]
        enum MouseEventFlag : uint
        {
            Move        = 0x0001,
            LeftDown    = 0x0002,
            LeftUp      = 0x0004,
            RightDown   = 0x0008,
            RightUp     = 0x0010,
            MiddleDown  = 0x0020,
            MiddleUp    = 0x0040,
            XDown       = 0x0080,
            XUp         = 0x0100,
            Wheel       = 0x0800,
            VirtualDesk = 0x4000,
            Absolute    = 0x8000,
        }

        //!函数声明
        [DllImport("user32.dll")]
        private static extern void mouse_event(MouseEventFlag flags, int dx, int dy, int cButtons, int dwExtraInfo);
        [DllImport("user32.dll")]
        private static extern void mouse_event(MouseEventFlag flags, int dx, int dy, uint data, UIntPtr extraInfo);
        [DllImport("user32.dll")]
        private static extern Boolean SetCursorPos(int X, int Y);
    }
}