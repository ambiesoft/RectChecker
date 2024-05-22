namespace dotnet60RectChecker
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            txtMain = new TextBox();
            timerMain = new System.Windows.Forms.Timer(components);
            SuspendLayout();
            // 
            // txtMain
            // 
            txtMain.Anchor = AnchorStyles.Top | AnchorStyles.Bottom | AnchorStyles.Left | AnchorStyles.Right;
            txtMain.Location = new Point(8, 12);
            txtMain.Multiline = true;
            txtMain.Name = "txtMain";
            txtMain.Size = new Size(780, 413);
            txtMain.TabIndex = 0;
            // 
            // timerMain
            // 
            timerMain.Enabled = true;
            timerMain.Interval = 1000;
            timerMain.Tick += timerMain_Tick;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(txtMain);
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox txtMain;
        private System.Windows.Forms.Timer timerMain;
    }
}
