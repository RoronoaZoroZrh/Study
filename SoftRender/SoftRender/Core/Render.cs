using System.Drawing;

namespace SoftRender
{
    //!渲染
    public class Render
    {
        //!构造函数
        public Render(Graphics vGraphics, int nWidth, int nHeight)
        {
            m_vFGraphics = vGraphics;
            m_vBuffer = new Bitmap(nWidth, nHeight);
            m_vBGraphics = Graphics.FromImage(m_vBuffer);
        }

        //!更新
        public void Update()
        {

        }

        //!图形
        private Graphics m_vFGraphics = null;
        private Graphics m_vBGraphics = null;

        //!帧缓存
        private Bitmap m_vBuffer = null;
    }
}