/*
 *  author : Zoro
 *  date   : 2018-12-3 19:34:51
 *  brief  : 验证继承后静态属性情况(基类和子类拥有同样的静态属性)
 */
using System;

namespace StaticInheritTest_20181203_1
{
    public class Program
    {
        static void Main(string[] args)
        {
            ZRHTest.TestProperty = true;
            Console.WriteLine(ZRHTest.TestProperty);
            Console.WriteLine(ZRHSubTest.TestProperty);

            ZRHSubTest.TestProperty = false;
            Console.WriteLine(ZRHTest.TestProperty);
            Console.WriteLine(ZRHSubTest.TestProperty);

            Console.WriteLine("Done!");
            Console.ReadLine();
        }
    }

    //!测试基类
    public class ZRHTest
    {
        public static Boolean TestProperty;
    }

    //!测试子类
    public class ZRHSubTest : ZRHTest
    {

    }
}
