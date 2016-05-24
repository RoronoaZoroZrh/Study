using System;
using System.Collections.Generic;
using System.Windows.Forms;

namespace Plan
{
    public enum Operate
    {
        Add,    //增加
        Modify, //修改
        Delete, //删除
        Move,   //移动
        Revert, //撤销
    }

    public class FormPlanDataLayer
    {
        //处理数据
        public void HandlePlanData(ListBox lControl, Operate oOperate, String sSummaryInfo = "", String sDetailInfo = "")
        {
            if (oOperate == Operate.Add) //增加
            {
                this.AddPlanData(lControl, sSummaryInfo, sDetailInfo);
            }
            else if (oOperate == Operate.Modify) //修改
            {
                this.ModifyPlanData(lControl, sSummaryInfo, sDetailInfo);
            }
        }

        //获取数据
        public Boolean GetPlanData(ListBox lControl, String sSummaryInfo, ref String sDetailInfo)
        {
            if (!this.m_dPlanData.ContainsKey(lControl.Name))
            {
                MessageBox.Show(lControl, "没有此类信息");
                return false;
            }

            if (!this.m_dPlanData[lControl.Name].ContainsKey(sSummaryInfo))
            {
                MessageBox.Show(lControl, "没有此类信息");
                return false;
            }

            sDetailInfo = this.m_dPlanData[lControl.Name][sSummaryInfo];
            return true;
        }

        //增加
        private void AddPlanData(ListBox lControl, String sSummaryInfo = "", String sDetailInfo = "")
        {
            if (!this.m_dPlanData.ContainsKey(lControl.Name))
            {
                this.m_dPlanData.Add(lControl.Name, new Dictionary<String, String>());
            }

            if (this.m_dPlanData[lControl.Name].ContainsKey(sSummaryInfo))
            {
                MessageBox.Show(lControl, "已包含此项");
                return;
            }

            lControl.Items.Add(sSummaryInfo);
            this.m_dPlanData[lControl.Name].Add(sSummaryInfo, sDetailInfo);
        }

        //修改
        private void ModifyPlanData(ListBox lControl, String sSummaryInfo = "", String sDetailInfo = "")
        {
            if (!this.m_dPlanData.ContainsKey(lControl.Name))
            {
                MessageBox.Show(lControl, "不包含此项");
                return;
            }

            if (!this.m_dPlanData[lControl.Name].ContainsKey(sSummaryInfo))
            {
                MessageBox.Show(lControl, "不包含此项");
                return;
            }

            this.m_dPlanData[lControl.Name][sSummaryInfo] = sDetailInfo;
        }

        //数据
        private Dictionary<String, Dictionary<String, String>> m_dPlanData = new Dictionary<String, Dictionary<String, String>>();
    }
}