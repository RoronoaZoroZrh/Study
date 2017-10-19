using System.Drawing;

namespace SoftRender
{
    //!渲染
    public class Render
    {
        //!构造函数
        public Render(Graphics vGraphics)
        {
            m_vGraphics = vGraphics;
        }

        //!更新
        public void Update()
        {

        }

        //!图形句柄
        private Graphics m_vGraphics = null;
    }
}