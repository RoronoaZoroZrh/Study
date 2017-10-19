//!时间：2017-10-19 17:08:12
//!说明：通过练习确定Timer的AutoReset属性含义
//!结论：AutoReset为false表示定时器触发事件仅运行一次
//!     AutoReset为true表示定时器触发事件运行多次，该值默认为true
using System;
using System.Timers;

namespace Timer_20171019_1
{
    class Program
    {
        //!主函数
        static void Main(string[] args)
        {
            Timer vTimer = new Timer(1000.0f / 30.0f);
            vTimer.Elapsed += vTimer_Elapsed;
            vTimer.Enabled = true;

            Console.WriteLine("vTimer.AutoReset = false...");
            vTimer.AutoReset = false;

            DateTime vBegin = DateTime.Now;
            while (true)
            {
                if ((DateTime.Now - vBegin).TotalMinutes >= 1 && !vTimer.AutoReset)
                {
                    Console.WriteLine("vTimer.AutoReset = true...");
                    vTimer.AutoReset = true;
                    m_nCount = 0;
                }
                else if ((DateTime.Now - vBegin).TotalMinutes >= 2)
                {
                    Console.WriteLine("测试完成...");
                    break;
                }
            }

            Console.ReadLine();
        }

        //!定时器触发事件
        private static void vTimer_Elapsed(object sender, EventArgs e)
        {
            Console.WriteLine((++m_nCount).ToString());
        }

        //!定时器触发事件运行次数
        private static int m_nCount = 0;
    }
}