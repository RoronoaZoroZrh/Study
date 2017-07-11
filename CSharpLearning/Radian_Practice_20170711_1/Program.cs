/**
 *  author : Zoro_Tiger
 *  date   : 2017-7-11 14:17:43
 *  brief  : 弧度角度转化
 */
using System;

namespace Radian_Practice_20170711_1
{
    class Program
    {
        static void Main(string[] args)
        {
            Int32  int_num = Int32.Parse(Console.ReadLine());

            Double sum = 0;
            for (int i = 0; i < int_num; i++)
            {
                String temp = Console.ReadLine().Trim();
                sum += Double.Parse(temp);
            }

            Double angle = (sum / (Math.Atan(1.0) * 4.0) * 180) % 360.0;
            Console.WriteLine("Radian=" + sum.ToString() + " Angle=" + angle.ToString());
            Console.ReadLine();
        }
    }
}