using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DateTime_Operation_20170705_1
{
    class Program
    {
        static void Main(string[] args)
        {
            //!开机时间
            DateTime startup_time = DateTime.Now.AddMilliseconds(-Environment.TickCount);

            //!显示开机时间
            Console.WriteLine("上班时间：" + startup_time.ToLocalTime().ToString());

            //!计算还剩下多少上班时间
            DateTime shutup_time = startup_time.AddHours(9);
            TimeSpan left_time = shutup_time.Subtract(DateTime.Now);
            if (left_time.Ticks <= 0)
            {
                Console.WriteLine("已下班！");
            }
            else
            {
                Console.WriteLine("距离下班时间：" + left_time.ToString());
            }

            //!防止闪屏
            Console.ReadLine();
        }
    }
}