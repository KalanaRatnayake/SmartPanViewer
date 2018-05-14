namespace PanViewrUI_v3._0
{
    partial class Resolution
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.btnRestart = new System.Windows.Forms.Button();
            this.btnCancel = new System.Windows.Forms.Button();
            this.widthSet = new System.Windows.Forms.NumericUpDown();
            this.heightSet = new System.Windows.Forms.NumericUpDown();
            ((System.ComponentModel.ISupportInitialize)(this.widthSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.heightSet)).BeginInit();
            this.SuspendLayout();
            // 
            // btnRestart
            // 
            this.btnRestart.Location = new System.Drawing.Point(12, 122);
            this.btnRestart.Name = "btnRestart";
            this.btnRestart.Size = new System.Drawing.Size(91, 27);
            this.btnRestart.TabIndex = 0;
            this.btnRestart.Text = "Restart";
            this.btnRestart.UseVisualStyleBackColor = true;
            // 
            // btnCancel
            // 
            this.btnCancel.Location = new System.Drawing.Point(156, 122);
            this.btnCancel.Name = "btnCancel";
            this.btnCancel.Size = new System.Drawing.Size(91, 27);
            this.btnCancel.TabIndex = 1;
            this.btnCancel.Text = "Cancel";
            this.btnCancel.UseVisualStyleBackColor = true;
            this.btnCancel.Click += new System.EventHandler(this.btnCancel_Click);
            // 
            // widthSet
            // 
            this.widthSet.Location = new System.Drawing.Point(12, 36);
            this.widthSet.Name = "widthSet";
            this.widthSet.Size = new System.Drawing.Size(91, 20);
            this.widthSet.TabIndex = 6;
            // 
            // heightSet
            // 
            this.heightSet.Location = new System.Drawing.Point(156, 36);
            this.heightSet.Name = "heightSet";
            this.heightSet.Size = new System.Drawing.Size(91, 20);
            this.heightSet.TabIndex = 7;
            // 
            // Resolution
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(262, 159);
            this.Controls.Add(this.heightSet);
            this.Controls.Add(this.widthSet);
            this.Controls.Add(this.btnCancel);
            this.Controls.Add(this.btnRestart);
            this.Name = "Resolution";
            this.Text = "Resolution";
            ((System.ComponentModel.ISupportInitialize)(this.widthSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.heightSet)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnRestart;
        private System.Windows.Forms.Button btnCancel;
        private System.Windows.Forms.NumericUpDown widthSet;
        private System.Windows.Forms.NumericUpDown heightSet;
    }
}