/*
 *  author    : Zoro
 *  date      : 2018-9-5 14:33:23
 *  brief     : 用属性DescriptionAttribute来获取枚举描述
 *  conclusion: 可以采用这种方式很方便的获取枚举描述
 */
using System;
using System.ComponentModel;
using System.Reflection;

namespace Enum_DescriptionAttribute_20180905
{
    //测试枚举
    internal enum TEnum
    {
        [Description("第一")] One,
        [Description("第二")] Two,
        [Description("第三")] Three,
    }

    //枚举帮助类
    internal static class EnumHelper<T>
    {

        //获取枚举描述
        public static string GetDescription(T enumValue)
        {
            Type type = typeof(T);
            if (type.IsEnum)
            {
                FieldInfo fieldInfo = type.GetField(enumValue.ToString());
                DescriptionAttribute attribute = (DescriptionAttribute)fieldInfo.GetCustomAttribute(typeof(DescriptionAttribute), false);
                if (attribute != null)
                {
                    return attribute.Description;
                }
            }
            return null;
        }

    }

    internal class Program
    {
        static void Main(string[] args)
        {
            //输出描述
            foreach (var itr in Enum.GetValues(typeof(TEnum)))
            {
                Console.WriteLine(EnumHelper<TEnum>.GetDescription((TEnum)itr));
            }

            //测试结束
            Console.WriteLine("示例结束...");
            Console.ReadLine();
        }
    }
}
