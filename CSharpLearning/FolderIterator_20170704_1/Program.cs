/**
 *  author : Zoro_Tiger
 *  date   : 2017-7-4 10:39:27
 *  brief  : 遍历目录
 */
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace FolderIterator_20170704_1
{
    class Program
    {
        static void Main(string[] args)
        {
            //!根目录
            String sFolder = String.Empty;

            //!读取根目录
            Console.Write("Root Folder:");
            sFolder = Console.ReadLine();

            //!遍历根目录
            StringBuilder sResult = new StringBuilder();
            Queue<DirectoryInfo> my_queue = new Queue<DirectoryInfo>();
            my_queue.Enqueue(new DirectoryInfo(sFolder));
            while (my_queue.Count() > 0)
            {
                var cur_dir = my_queue.Dequeue();
                foreach (var itr in cur_dir.GetDirectories())
                {
                    long res_id = long.MinValue;
                    if (long.TryParse(itr.Name, out res_id) && res_id > 100000000)
                    {
                        sResult.Append(res_id.ToString() + Environment.NewLine);
                    }
                    else
                    {
                        my_queue.Enqueue(itr);
                    }
                }
            }

            //!输出结果
            using (StreamWriter writer = new StreamWriter("result.txt"))
            {
                writer.Write(sResult);
            }
            Console.WriteLine("Done!");
            Console.ReadLine();
        }
    }
}