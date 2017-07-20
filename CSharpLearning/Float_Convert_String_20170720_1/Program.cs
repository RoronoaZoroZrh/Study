using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Float_Convert_String_20170720_1
{
    class Program
    {
        static void Main(string[] args)
        {
            //!测试值
            float fTestValue = 5.0000f;

            //!直接转换
            Console.WriteLine(fTestValue.ToString());

            //!转换(G)
            Console.WriteLine(fTestValue.ToString("G"));

            //!转换(N)
            Console.WriteLine(fTestValue.ToString("N"));

            //!decimal
            Decimal tempValue = (Decimal)fTestValue;
            Console.WriteLine(tempValue.ToString());

            //!double
            double dTempValue = (double)fTestValue;
            Console.WriteLine(dTempValue.ToString());

            //!防止程序直接退出
            Console.ReadLine();
        }
    }
}