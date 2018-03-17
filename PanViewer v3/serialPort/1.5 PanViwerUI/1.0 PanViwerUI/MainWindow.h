#pragma once

#include "CalibarateWindow.h"
#include "MapWindow.h"

namespace My10PanViwerUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainWindow
	/// </summary>
	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  vidFrame;
	private: System::Windows::Forms::PictureBox^  imgMap;
	private: System::Windows::Forms::Button^  btnCalibarate;
	private: System::Windows::Forms::Button^  btnShutDown;
	private: System::Windows::Forms::Button^  btnAutoAdjust;
	private: System::Windows::Forms::Button^  btnManualAdjust;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainWindow::typeid));
			this->vidFrame = (gcnew System::Windows::Forms::PictureBox());
			this->imgMap = (gcnew System::Windows::Forms::PictureBox());
			this->btnCalibarate = (gcnew System::Windows::Forms::Button());
			this->btnShutDown = (gcnew System::Windows::Forms::Button());
			this->btnAutoAdjust = (gcnew System::Windows::Forms::Button());
			this->btnManualAdjust = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->vidFrame))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgMap))->BeginInit();
			this->SuspendLayout();
			// 
			// vidFrame
			// 
			this->vidFrame->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"vidFrame.Image")));
			this->vidFrame->Location = System::Drawing::Point(200, 12);
			this->vidFrame->MaximumSize = System::Drawing::Size(2400, 600);
			this->vidFrame->Name = L"vidFrame";
			this->vidFrame->Size = System::Drawing::Size(1138, 285);
			this->vidFrame->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->vidFrame->TabIndex = 0;
			this->vidFrame->TabStop = false;
			// 
			// imgMap
			// 
			this->imgMap->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"imgMap.Image")));
			this->imgMap->Location = System::Drawing::Point(12, 12);
			this->imgMap->Name = L"imgMap";
			this->imgMap->Size = System::Drawing::Size(180, 285);
			this->imgMap->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->imgMap->TabIndex = 1;
			this->imgMap->TabStop = false;
			this->imgMap->Click += gcnew System::EventHandler(this, &MainWindow::imgMap_Click);
			// 
			// btnCalibarate
			// 
			this->btnCalibarate->Location = System::Drawing::Point(12, 326);
			this->btnCalibarate->Name = L"btnCalibarate";
			this->btnCalibarate->Size = System::Drawing::Size(180, 50);
			this->btnCalibarate->TabIndex = 2;
			this->btnCalibarate->Text = L"Camera Calibarate ";
			this->btnCalibarate->UseVisualStyleBackColor = true;
			this->btnCalibarate->Click += gcnew System::EventHandler(this, &MainWindow::btnCalibarate_Click);
			// 
			// btnShutDown
			// 
			this->btnShutDown->Location = System::Drawing::Point(198, 326);
			this->btnShutDown->Name = L"btnShutDown";
			this->btnShutDown->Size = System::Drawing::Size(180, 50);
			this->btnShutDown->TabIndex = 3;
			this->btnShutDown->Text = L"Shut Down";
			this->btnShutDown->UseVisualStyleBackColor = true;
			// 
			// btnAutoAdjust
			// 
			this->btnAutoAdjust->Location = System::Drawing::Point(1158, 326);
			this->btnAutoAdjust->Name = L"btnAutoAdjust";
			this->btnAutoAdjust->Size = System::Drawing::Size(180, 50);
			this->btnAutoAdjust->TabIndex = 4;
			this->btnAutoAdjust->Text = L"Auto Adjust";
			this->btnAutoAdjust->UseVisualStyleBackColor = true;
			// 
			// btnManualAdjust
			// 
			this->btnManualAdjust->Location = System::Drawing::Point(972, 326);
			this->btnManualAdjust->Name = L"btnManualAdjust";
			this->btnManualAdjust->Size = System::Drawing::Size(180, 50);
			this->btnManualAdjust->TabIndex = 5;
			this->btnManualAdjust->Text = L"Manual Adjust";
			this->btnManualAdjust->UseVisualStyleBackColor = true;
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(1350, 388);
			this->Controls->Add(this->btnManualAdjust);
			this->Controls->Add(this->btnAutoAdjust);
			this->Controls->Add(this->btnShutDown);
			this->Controls->Add(this->btnCalibarate);
			this->Controls->Add(this->imgMap);
			this->Controls->Add(this->vidFrame);
			this->MaximumSize = System::Drawing::Size(2880, 900);
			this->MinimizeBox = false;
			this->Name = L"MainWindow";
			this->Text = L"Pan Viewer";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->vidFrame))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgMap))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void btnCalibarate_Click(System::Object^  sender, System::EventArgs^  e) {
	CalibarateWindow^ calibWindow = gcnew CalibarateWindow();
	calibWindow->ShowDialog();
}
private: System::Void imgMap_Click(System::Object^  sender, System::EventArgs^  e) {
	MapWindow^ mapWindow = gcnew MapWindow();
	mapWindow->ShowDialog();
}
};
}
