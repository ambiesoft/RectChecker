using System.Text;

namespace dotnet60RectChecker
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

            sb.AppendLine("Location.X=" + Location.X);
            sb.AppendLine("Location.Y=" + Location.Y);
            sb.AppendLine();
            sb.AppendLine("Size.Width=" + Size.Width);
            sb.AppendLine("Size.Height=" + Size.Height);
            sb.AppendLine();
            sb.AppendLine("RestoreBounds.Left=" + RestoreBounds.Left);
            sb.AppendLine("RestoreBounds.Top=" + RestoreBounds.Top);
            sb.AppendLine("RestoreBounds.Right=" + RestoreBounds.Right);
            sb.AppendLine("RestoreBounds.Bottom=" + RestoreBounds.Bottom);
            sb.AppendLine("RestoreBounds.Width=" + RestoreBounds.Width);
            sb.AppendLine("RestoreBounds.Height=" + RestoreBounds.Height);


            txtMain.Text = sb.ToString();
        }
    }
}
