/*
 *  author : Tiger
 *  date   : 2017-11-1 16:22:41
 *  brief  : 查看文档注释直接生成xml文件功能
 */
using System;

namespace Comment_20171101_1
{
    /// <summary>
    /// class Program
    /// </summary>
    public class Program
    {
        /**
         * method Main
         */
        static void Main(string[] args)
        {
            Console.WriteLine(Add(1, 2));
        }

        /// <summary>
        /// 计算两个数之和
        /// </summary>
        /// <param name="nNumA">数字A</param>
        /// <param name="nNumB">数字B</param>
        /// <returns>数字A与数字B之和</returns>
        static int Add(int nNumA, int nNumB)
        {
            return nNumA + nNumB;
        }
    }

    /// <summary>
    /// class TestClass
    /// </summary>
    public class TestClass
    {
        /// <summary>
        /// 构造函数
        /// </summary>
        /// <param name="fNumA">数字A</param>
        /// <param name="fNumB">数字B</param>
        public TestClass(float fNumA, float fNumB)
        {

        }
    }
}