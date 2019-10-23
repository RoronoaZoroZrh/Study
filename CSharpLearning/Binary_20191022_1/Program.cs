/*
 *  author    : Zoro
 *  date      : 2019-10-22 18:07:10
 *  brief     : 二进制文件读取
 *  conclusion: 
 */
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Binary_20191022_1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("F3:");
            string file3 = Console.ReadLine();
            List<string> tmp1 = new List<string>();
            using (StreamReader sr = new StreamReader(file3))
            {
                while (!sr.EndOfStream)
                {
                    string aa = sr.ReadLine();
                    if (!tmp1.Contains(Path.GetFileNameWithoutExtension(aa)))
                    {
                        tmp1.Add(aa);
                    }
                }
            }

            Console.Write("F1:");
            string file1 = Console.ReadLine();

            Console.Write("F2:");
            string file2 = Console.ReadLine();

            HouseFitment2DirParser parser1 = new HouseFitment2DirParser();
            parser1.Parse(file1);

            HouseFitment2DirParser parser2 = new HouseFitment2DirParser();
            parser2.Parse(file2);

            List<string> re = tmp1.Except(parser1.mFitment2Dir.Keys.ToList()).ToList();
            re.ForEach(tmp => Console.WriteLine(tmp));
            Console.WriteLine();

            List<string> targets1 = parser1.mFitment2Dir.Keys.ToList().Except(parser2.mFitment2Dir.Keys.ToList()).ToList();
            targets1.ForEach(tmp => Console.WriteLine(tmp));
            Console.WriteLine();

            List<string> targets2 = parser2.mFitment2Dir.Keys.ToList().Except(parser1.mFitment2Dir.Keys.ToList()).ToList();
            targets2.ForEach(tmp => Console.WriteLine(tmp));
            Console.ReadLine();
        }
    }


    public class HouseFitment2DirParser
    {
        public Dictionary<string, string> mFitment2Dir = null;

        public bool Parse(string filePath)
        {
            using (Stream stream = new FileStream(filePath, FileMode.Open))
            {
                if (stream == null)
                {
                    return false;
                }

                if (mFitment2Dir == null)
                {
                    mFitment2Dir = new Dictionary<string, string>();
                }
                mFitment2Dir.Clear();

                using (BinaryReader reader = new BinaryReader(stream))
                {
                    int dCnt = reader.ReadInt32();
                    List<string> dirs = new List<string>(dCnt);
                    for (int i = 0; i < dCnt; ++i)
                    {
                        dirs.Add(reader.ReadString());
                    }

                    int fCnt = reader.ReadInt32();
                    for (int i = 0; i < fCnt; ++i)
                    {
                        mFitment2Dir[reader.ReadString()] = dirs[reader.ReadInt32()];
                    }
                }
                return true;
            }
        }
    }
}