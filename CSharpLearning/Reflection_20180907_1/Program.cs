/*
 *  author    : Zoro
 *  date      : 2018-9-7 15:19:12
 *  brief     : 利用反射获取程序集中的方法
 *  conclusion: 利用反射和标记可以很方便的筛选出程序集中想要的信息
 */
using System;
using System.Reflection;

namespace Reflection_20180907_1
{
    class Program
    {
        static void Main(string[] args)
        {
            //当前程序集
            Assembly assembly = Assembly.GetExecutingAssembly();

            //打印当前程序集名称
            Console.WriteLine(assembly.GetName());
            Console.WriteLine(assembly.FullName);

            //打印当前程序集信息
            foreach (Type type in assembly.GetTypes())
            {
                //打印类名称
                Console.WriteLine(type.FullName);

                //打印方法名称
                foreach (MethodInfo info in type.GetMethods(BindingFlags.Static | BindingFlags.Public))
                {
                    if (info.GetCustomAttribute(typeof(TestCallBackAttribute)) != null)
                    {
                        Console.WriteLine(info.Name);
                    }
                }
            }

            //测试结束
            Console.WriteLine("示例结束...");
            Console.ReadLine();
        }
    }

    [AttributeUsage(AttributeTargets.Method)]
    public class TestCallBackAttribute : Attribute
    {

    }

    public class TestClass
    {
        public void TestMethod()
        {

        }

        public static void StaticTestMethod()
        {

        }

        [TestCallBack]
        public static void SpecialStaticTestMethod()
        {

        }
    }
}
