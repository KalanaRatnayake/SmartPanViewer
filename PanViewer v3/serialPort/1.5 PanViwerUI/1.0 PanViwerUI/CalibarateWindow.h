#pragma once

namespace My10PanViwerUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CalibarateWindow
	/// </summary>
	public ref class CalibarateWindow : public System::Windows::Forms::Form
	{
	public:
		CalibarateWindow(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CalibarateWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  cam1Image;
	private: System::Windows::Forms::PictureBox^  cam2Image;
	private: System::Windows::Forms::PictureBox^  cam3Image;
	private: System::Windows::Forms::Button^  btnCam1Up;
	private: System::Windows::Forms::Button^  btnCam1Down;

	private: System::Windows::Forms::Button^  btnCam1Left;
	private: System::Windows::Forms::Button^  btnCam1Right;
	private: System::Windows::Forms::Button^  btnCam2Right;

	private: System::Windows::Forms::Button^  btnCam2Left;

	private: System::Windows::Forms::Button^  btnCam2Down;

	private: System::Windows::Forms::Button^  btnCam2Up;
	private: System::Windows::Forms::Button^  btnCam3Right;

	private: System::Windows::Forms::Button^  btnCam3Left;

	private: System::Windows::Forms::Button^  btnCam3Down;

	private: System::Windows::Forms::Button^  btnCam3Up;
	private: System::Windows::Forms::Button^  btnDone;














	protected:

	protected:



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(CalibarateWindow::typeid));
			this->cam1Image = (gcnew System::Windows::Forms::PictureBox());
			this->cam2Image = (gcnew System::Windows::Forms::PictureBox());
			this->cam3Image = (gcnew System::Windows::Forms::PictureBox());
			this->btnCam1Up = (gcnew System::Windows::Forms::Button());
			this->btnCam1Down = (gcnew System::Windows::Forms::Button());
			this->btnCam1Left = (gcnew System::Windows::Forms::Button());
			this->btnCam1Right = (gcnew System::Windows::Forms::Button());
			this->btnCam2Right = (gcnew System::Windows::Forms::Button());
			this->btnCam2Left = (gcnew System::Windows::Forms::Button());
			this->btnCam2Down = (gcnew System::Windows::Forms::Button());
			this->btnCam2Up = (gcnew System::Windows::Forms::Button());
			this->btnCam3Right = (gcnew System::Windows::Forms::Button());
			this->btnCam3Left = (gcnew System::Windows::Forms::Button());
			this->btnCam3Down = (gcnew System::Windows::Forms::Button());
			this->btnCam3Up = (gcnew System::Windows::Forms::Button());
			this->btnDone = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cam1Image))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cam2Image))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cam3Image))->BeginInit();
			this->SuspendLayout();
			// 
			// cam1Image
			// 
			this->cam1Image->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cam1Image.Image")));
			this->cam1Image->Location = System::Drawing::Point(12, 12);
			this->cam1Image->MaximumSize = System::Drawing::Size(800, 600);
			this->cam1Image->Name = L"cam1Image";
			this->cam1Image->Size = System::Drawing::Size(400, 300);
			this->cam1Image->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cam1Image->TabIndex = 0;
			this->cam1Image->TabStop = false;
			// 
			// cam2Image
			// 
			this->cam2Image->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cam2Image.Image")));
			this->cam2Image->Location = System::Drawing::Point(431, 12);
			this->cam2Image->MaximumSize = System::Drawing::Size(800, 600);
			this->cam2Image->Name = L"cam2Image";
			this->cam2Image->Size = System::Drawing::Size(400, 300);
			this->cam2Image->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cam2Image->TabIndex = 1;
			this->cam2Image->TabStop = false;
			// 
			// cam3Image
			// 
			this->cam3Image->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"cam3Image.Image")));
			this->cam3Image->Location = System::Drawing::Point(851, 12);
			this->cam3Image->MaximumSize = System::Drawing::Size(800, 600);
			this->cam3Image->Name = L"cam3Image";
			this->cam3Image->Size = System::Drawing::Size(400, 300);
			this->cam3Image->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->cam3Image->TabIndex = 2;
			this->cam3Image->TabStop = false;
			// 
			// btnCam1Up
			// 
			this->btnCam1Up->Location = System::Drawing::Point(12, 326);
			this->btnCam1Up->Name = L"btnCam1Up";
			this->btnCam1Up->Size = System::Drawing::Size(90, 50);
			this->btnCam1Up->TabIndex = 3;
			this->btnCam1Up->Text = L"Up";
			this->btnCam1Up->UseVisualStyleBackColor = true;
			// 
			// btnCam1Down
			// 
			this->btnCam1Down->Location = System::Drawing::Point(108, 326);
			this->btnCam1Down->Name = L"btnCam1Down";
			this->btnCam1Down->Size = System::Drawing::Size(90, 50);
			this->btnCam1Down->TabIndex = 4;
			this->btnCam1Down->Text = L"Down";
			this->btnCam1Down->UseVisualStyleBackColor = true;
			// 
			// btnCam1Left
			// 
			this->btnCam1Left->Location = System::Drawing::Point(226, 326);
			this->btnCam1Left->Name = L"btnCam1Left";
			this->btnCam1Left->Size = System::Drawing::Size(90, 50);
			this->btnCam1Left->TabIndex = 5;
			this->btnCam1Left->Text = L"Left";
			this->btnCam1Left->UseVisualStyleBackColor = true;
			// 
			// btnCam1Right
			// 
			this->btnCam1Right->Location = System::Drawing::Point(322, 326);
			this->btnCam1Right->Name = L"btnCam1Right";
			this->btnCam1Right->Size = System::Drawing::Size(90, 50);
			this->btnCam1Right->TabIndex = 6;
			this->btnCam1Right->Text = L"Right";
			this->btnCam1Right->UseVisualStyleBackColor = true;
			// 
			// btnCam2Right
			// 
			this->btnCam2Right->Location = System::Drawing::Point(741, 326);
			this->btnCam2Right->Name = L"btnCam2Right";
			this->btnCam2Right->Size = System::Drawing::Size(90, 50);
			this->btnCam2Right->TabIndex = 10;
			this->btnCam2Right->Text = L"Right";
			this->btnCam2Right->UseVisualStyleBackColor = true;
			// 
			// btnCam2Left
			// 
			this->btnCam2Left->Location = System::Drawing::Point(645, 326);
			this->btnCam2Left->Name = L"btnCam2Left";
			this->btnCam2Left->Size = System::Drawing::Size(90, 50);
			this->btnCam2Left->TabIndex = 9;
			this->btnCam2Left->Text = L"Left";
			this->btnCam2Left->UseVisualStyleBackColor = true;
			// 
			// btnCam2Down
			// 
			this->btnCam2Down->Location = System::Drawing::Point(527, 326);
			this->btnCam2Down->Name = L"btnCam2Down";
			this->btnCam2Down->Size = System::Drawing::Size(90, 50);
			this->btnCam2Down->TabIndex = 8;
			this->btnCam2Down->Text = L"Down";
			this->btnCam2Down->UseVisualStyleBackColor = true;
			// 
			// btnCam2Up
			// 
			this->btnCam2Up->Location = System::Drawing::Point(431, 326);
			this->btnCam2Up->Name = L"btnCam2Up";
			this->btnCam2Up->Size = System::Drawing::Size(90, 50);
			this->btnCam2Up->TabIndex = 7;
			this->btnCam2Up->Text = L"Up";
			this->btnCam2Up->UseVisualStyleBackColor = true;
			// 
			// btnCam3Right
			// 
			this->btnCam3Right->Location = System::Drawing::Point(1161, 326);
			this->btnCam3Right->Name = L"btnCam3Right";
			this->btnCam3Right->Size = System::Drawing::Size(90, 50);
			this->btnCam3Right->TabIndex = 14;
			this->btnCam3Right->Text = L"Right";
			this->btnCam3Right->UseVisualStyleBackColor = true;
			// 
			// btnCam3Left
			// 
			this->btnCam3Left->Location = System::Drawing::Point(1065, 326);
			this->btnCam3Left->Name = L"btnCam3Left";
			this->btnCam3Left->Size = System::Drawing::Size(90, 50);
			this->btnCam3Left->TabIndex = 13;
			this->btnCam3Left->Text = L"Left";
			this->btnCam3Left->UseVisualStyleBackColor = true;
			// 
			// btnCam3Down
			// 
			this->btnCam3Down->Location = System::Drawing::Point(947, 326);
			this->btnCam3Down->Name = L"btnCam3Down";
			this->btnCam3Down->Size = System::Drawing::Size(90, 50);
			this->btnCam3Down->TabIndex = 12;
			this->btnCam3Down->Text = L"Down";
			this->btnCam3Down->UseVisualStyleBackColor = true;
			// 
			// btnCam3Up
			// 
			this->btnCam3Up->Location = System::Drawing::Point(851, 326);
			this->btnCam3Up->Name = L"btnCam3Up";
			this->btnCam3Up->Size = System::Drawing::Size(90, 50);
			this->btnCam3Up->TabIndex = 11;
			this->btnCam3Up->Text = L"Up";
			this->btnCam3Up->UseVisualStyleBackColor = true;
			// 
			// btnDone
			// 
			this->btnDone->Location = System::Drawing::Point(1268, 152);
			this->btnDone->Name = L"btnDone";
			this->btnDone->Size = System::Drawing::Size(70, 80);
			this->btnDone->TabIndex = 15;
			this->btnDone->Text = L"Done";
			this->btnDone->UseVisualStyleBackColor = true;
			this->btnDone->Click += gcnew System::EventHandler(this, &CalibarateWindow::btnDone_Click);
			// 
			// CalibarateWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1350, 388);
			this->Controls->Add(this->btnDone);
			this->Controls->Add(this->btnCam3Right);
			this->Controls->Add(this->btnCam3Left);
			this->Controls->Add(this->btnCam3Down);
			this->Controls->Add(this->btnCam3Up);
			this->Controls->Add(this->btnCam2Right);
			this->Controls->Add(this->btnCam2Left);
			this->Controls->Add(this->btnCam2Down);
			this->Controls->Add(this->btnCam2Up);
			this->Controls->Add(this->btnCam1Right);
			this->Controls->Add(this->btnCam1Left);
			this->Controls->Add(this->btnCam1Down);
			this->Controls->Add(this->btnCam1Up);
			this->Controls->Add(this->cam3Image);
			this->Controls->Add(this->cam2Image);
			this->Controls->Add(this->cam1Image);
			this->MaximumSize = System::Drawing::Size(2880, 900);
			this->MinimizeBox = false;
			this->Name = L"CalibarateWindow";
			this->Text = L"Calibarate Cameras";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cam1Image))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cam2Image))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cam3Image))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void btnDone_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
};
}
