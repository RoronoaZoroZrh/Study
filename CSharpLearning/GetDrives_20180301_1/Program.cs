/*
 *  author : Zoro
 *  date   : 2018-3-1 10:25:05
 *  brief  : 查看Drive
 */
using System;
using System.IO;

namespace GetDrives_20180301_1
{
    class Program
    {
        static void Main(string[] args)
        {
            DriveInfo[] vDriveInfos = DriveInfo.GetDrives();
            foreach (DriveInfo vDriveInfo in vDriveInfos)
            {
                Console.WriteLine(vDriveInfo.Name);
                Console.WriteLine(vDriveInfo.AvailableFreeSpace);
            }

            Console.WriteLine(Directory.GetCurrentDirectory());
            foreach (DriveInfo vDriveInfo in vDriveInfos)
            {
                long nSize = 100 * 1024 * 1024 * 1024L;
                if (Directory.GetCurrentDirectory().Contains(vDriveInfo.Name) &&
                    vDriveInfo.AvailableFreeSpace < nSize)
                {
                    Console.WriteLine(vDriveInfo.AvailableFreeSpace);
                    Console.WriteLine(nSize);
                }
            }

            Console.ReadLine();
        }
    }
}