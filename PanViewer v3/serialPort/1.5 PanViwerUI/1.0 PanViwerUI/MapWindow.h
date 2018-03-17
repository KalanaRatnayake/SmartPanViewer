#pragma once

namespace My10PanViwerUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MapWindow
	/// </summary>
	public ref class MapWindow : public System::Windows::Forms::Form
	{
	public:
		MapWindow(void)
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
		~MapWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  imgMap;
	protected:

	protected:

	private: System::Windows::Forms::PictureBox^  vidFrame;
	private: System::Windows::Forms::Button^  btnDone;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MapWindow::typeid));
			this->imgMap = (gcnew System::Windows::Forms::PictureBox());
			this->vidFrame = (gcnew System::Windows::Forms::PictureBox());
			this->btnDone = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgMap))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->vidFrame))->BeginInit();
			this->SuspendLayout();
			// 
			// imgMap
			// 
			this->imgMap->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"imgMap.Image")));
			this->imgMap->Location = System::Drawing::Point(11, 12);
			this->imgMap->Name = L"imgMap";
			this->imgMap->Size = System::Drawing::Size(660, 370);
			this->imgMap->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->imgMap->TabIndex = 0;
			this->imgMap->TabStop = false;
			// 
			// vidFrame
			// 
			this->vidFrame->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"vidFrame.Image")));
			this->vidFrame->Location = System::Drawing::Point(680, 113);
			this->vidFrame->Name = L"vidFrame";
			this->vidFrame->Size = System::Drawing::Size(660, 165);
			this->vidFrame->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->vidFrame->TabIndex = 1;
			this->vidFrame->TabStop = false;
			// 
			// btnDone
			// 
			this->btnDone->Location = System::Drawing::Point(1178, 324);
			this->btnDone->Name = L"btnDone";
			this->btnDone->Size = System::Drawing::Size(162, 52);
			this->btnDone->TabIndex = 2;
			this->btnDone->Text = L"Done";
			this->btnDone->UseVisualStyleBackColor = true;
			this->btnDone->Click += gcnew System::EventHandler(this, &MapWindow::btnDone_Click);
			// 
			// MapWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1350, 388);
			this->Controls->Add(this->btnDone);
			this->Controls->Add(this->vidFrame);
			this->Controls->Add(this->imgMap);
			this->MaximumSize = System::Drawing::Size(2880, 900);
			this->Name = L"MapWindow";
			this->Text = L"MapWindow";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgMap))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->vidFrame))->EndInit();
			this->ResumeLayout(false);

		}

#pragma endregion
	private: System::Void btnDone_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
};
}
