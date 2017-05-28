using System;
using System.IO;

namespace DNFScript
{
    //!日志
    public class DNFScriptLog
    {
        //!打印信息
        public static void LogInfo(String sInfo)
        {
            if (null == m_writer)
            {
                m_writer = new StreamWriter("DNFScript.log");
            }
            m_writer.WriteLine("Info:" + sInfo);
            m_writer.Flush();
        }

        //!打印错误信息
        public static void LogError(String sError)
        {
            if (null == m_writer)
            {
                m_writer = new StreamWriter("DNFScript.log");
            }
            m_writer.WriteLine("Error:" + sError);
            m_writer.Flush();
        }

        //!关闭流
        public static void Clean()
        {
            m_writer.Close();
        }

        //!流
        private static StreamWriter m_writer = null;
    }
}