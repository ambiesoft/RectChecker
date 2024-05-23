using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace dotnet462ClientRectChecker
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void timerMain_Tick(object sender, EventArgs e)
        {
            StringBuilder sb = new StringBuilder();

            sb.Append("MainForm:");
            sb.AppendLine("Location.X=" + Location.X);
            sb.AppendLine("Location.Y=" + Location.Y);
            sb.AppendLine();
            sb.AppendLine("Size.Width=" + Size.Width);
            sb.AppendLine("Size.Height=" + Size.Height);
            sb.AppendLine();

            sb.AppendLine("Button:");
            sb.AppendLine("Button.Location.X=" + btnClient.Location.X);
            sb.AppendLine("Button.Location.Y=" + btnClient.Location.Y);
            sb.AppendLine();
            sb.AppendLine("Button.Size.Width=" + btnClient.Size.Width);
            sb.AppendLine("Button.Size.Height=" + btnClient.Size.Height);
            sb.AppendLine();

            Point ptButtonScreen = this.PointToScreen(btnClient.Location);
            sb.AppendLine("Button Screen:");
            sb.AppendLine("ptButtonScreen.X=" + ptButtonScreen.X);
            sb.AppendLine("ptButtonScreen.Y=" + ptButtonScreen.Y);
            sb.AppendLine();

            txtMain.Text = sb.ToString();
        }
    }
}
