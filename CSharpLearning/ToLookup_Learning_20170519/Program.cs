/**
 *  author : Tiger
 *  date   : 2017-5-19 09:48:13
 *  brief  : 挖一挖C#中那些我们不常用的东西之系列（1）——ToDictionary,ToLookup
 *           http://www.cnblogs.com/huangxincheng/p/3618872.html
 */
using System;
using System.Collections.Generic;
using System.Linq;

namespace ToLookup_Learning_20170519
{
    public class Ticket
    {
        /// <summary>
        /// 票号
        /// </summary>
        public String TicketN { get; set; }

        /// <summary>
        /// 订单号
        /// </summary>
        public String OrderID { get; set; }

        /// <summary>
        /// 备注
        /// </summary>
        public String Descrip { get; set; }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<Ticket> ticket_list = GetTicketList();
            var ticket_dic = ticket_list.ToLookup(i => i.OrderID);

            foreach (var itr in ticket_dic)
            {
                Console.WriteLine("OrderID:" + itr.Key);
                foreach (var sub_itr in itr)
                {
                    Console.WriteLine("\tTicketN:" + sub_itr.TicketN);
                    Console.WriteLine("\tDescrip:" + sub_itr.Descrip);
                }
            }

            Console.ReadLine();
        }

        public static List<Ticket> GetTicketList()
        {
            return new List<Ticket>()
            {
                new Ticket(){ TicketN = "999-12311", OrderID = "79121281", Descrip = "改签" },
                new Ticket(){ TicketN = "999-24572", OrderID = "29321289", Descrip = "退票" },
                new Ticket(){ TicketN = "999-68904", OrderID = "19321289", Descrip = "成交" },
                new Ticket(){ TicketN = "999-24172", OrderID = "64321212", Descrip = "未使用" },
                new Ticket(){ TicketN = "999-24579", OrderID = "19321289", Descrip = "退票" },
                new Ticket(){ TicketN = "999-21522", OrderID = "79121281", Descrip = "未使用" },
                new Ticket(){ TicketN = "999-24902", OrderID = "79121281", Descrip = "退票" },
                new Ticket(){ TicketN = "999-04571", OrderID = "29321289", Descrip = "改签" },
                new Ticket(){ TicketN = "999-23572", OrderID = "96576289", Descrip = "改签" },
                new Ticket(){ TicketN = "999-24971", OrderID = "99321289", Descrip = "成交" },
            };
        }
    }
}