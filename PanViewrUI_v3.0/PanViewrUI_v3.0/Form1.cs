using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace PanViewrUI_v3._0
{
    public partial class Main : Form
    {
        public Main()
        {
            InitializeComponent();
        }

        int leftCam = 0;
        int middleCam = 1;
        int rightCam = 2;
        int width = 1366;
        int height = 384;

        [DllImport("PanViewer.dll", EntryPoint = "createUI", CallingConvention = CallingConvention.Cdecl)]
        public static extern void createUI(int left, int middle, int right, int width, int height);

        [DllImport("PanViewer.dll", EntryPoint = "openCameraOutpu", CallingConvention = CallingConvention.Cdecl)]
        public static extern void openCameraOutput();

        [DllImport("PanViewer.dll", EntryPoint = "stitchedOutput", CallingConvention = CallingConvention.Cdecl)]
        public static extern void stitchedOutput();

        [DllImport("PanViewer.dll", EntryPoint = "deleteUI", CallingConvention = CallingConvention.Cdecl)]
        public static extern void deleteUI();

        private void btnResolution_Click(object sender, EventArgs e)
        {
            
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            createUI(leftCam, middleCam, rightCam, width, height);
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            deleteUI();
        }
    }
}
