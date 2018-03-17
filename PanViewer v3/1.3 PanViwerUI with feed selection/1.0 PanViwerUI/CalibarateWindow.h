#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2\cudaimgproc.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <conio.h>

namespace My10PanViwerUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace std;
	using namespace cv;


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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;



	private: System::Windows::Forms::Button^  btnRefresh;
	private: System::Windows::Forms::RadioButton^  LBtn0;
	private: System::Windows::Forms::RadioButton^  LBtn1;
	private: System::Windows::Forms::RadioButton^  LBtn2;
	private: System::Windows::Forms::RadioButton^  MBtn2;
	private: System::Windows::Forms::RadioButton^  MBtn1;
	private: System::Windows::Forms::RadioButton^  MBtn0;
	private: System::Windows::Forms::RadioButton^  RBtn2;
	private: System::Windows::Forms::RadioButton^  RBtn1;
	private: System::Windows::Forms::RadioButton^  RBtn0;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnRefresh = (gcnew System::Windows::Forms::Button());
			this->LBtn0 = (gcnew System::Windows::Forms::RadioButton());
			this->LBtn1 = (gcnew System::Windows::Forms::RadioButton());
			this->LBtn2 = (gcnew System::Windows::Forms::RadioButton());
			this->MBtn2 = (gcnew System::Windows::Forms::RadioButton());
			this->MBtn1 = (gcnew System::Windows::Forms::RadioButton());
			this->MBtn0 = (gcnew System::Windows::Forms::RadioButton());
			this->RBtn2 = (gcnew System::Windows::Forms::RadioButton());
			this->RBtn1 = (gcnew System::Windows::Forms::RadioButton());
			this->RBtn0 = (gcnew System::Windows::Forms::RadioButton());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cam1Image))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cam2Image))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cam3Image))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
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
			this->btnCam1Down->Location = System::Drawing::Point(103, 326);
			this->btnCam1Down->Name = L"btnCam1Down";
			this->btnCam1Down->Size = System::Drawing::Size(90, 50);
			this->btnCam1Down->TabIndex = 4;
			this->btnCam1Down->Text = L"Down";
			this->btnCam1Down->UseVisualStyleBackColor = true;
			// 
			// btnCam1Left
			// 
			this->btnCam1Left->Location = System::Drawing::Point(231, 326);
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
			this->btnCam2Left->Location = System::Drawing::Point(650, 326);
			this->btnCam2Left->Name = L"btnCam2Left";
			this->btnCam2Left->Size = System::Drawing::Size(90, 50);
			this->btnCam2Left->TabIndex = 9;
			this->btnCam2Left->Text = L"Left";
			this->btnCam2Left->UseVisualStyleBackColor = true;
			// 
			// btnCam2Down
			// 
			this->btnCam2Down->Location = System::Drawing::Point(522, 326);
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
			this->btnCam3Left->Location = System::Drawing::Point(1070, 326);
			this->btnCam3Left->Name = L"btnCam3Left";
			this->btnCam3Left->Size = System::Drawing::Size(90, 50);
			this->btnCam3Left->TabIndex = 13;
			this->btnCam3Left->Text = L"Left";
			this->btnCam3Left->UseVisualStyleBackColor = true;
			// 
			// btnCam3Down
			// 
			this->btnCam3Down->Location = System::Drawing::Point(942, 326);
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
			this->btnDone->Location = System::Drawing::Point(1268, 304);
			this->btnDone->Name = L"btnDone";
			this->btnDone->Size = System::Drawing::Size(70, 60);
			this->btnDone->TabIndex = 15;
			this->btnDone->Text = L"Done";
			this->btnDone->UseVisualStyleBackColor = true;
			this->btnDone->Click += gcnew System::EventHandler(this, &CalibarateWindow::btnDone_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 3);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 13);
			this->label1->TabIndex = 16;
			this->label1->Text = L"Left Camera";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 4);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 13);
			this->label2->TabIndex = 17;
			this->label2->Text = L"Right Camera";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(2, 4);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 13);
			this->label3->TabIndex = 18;
			this->label3->Text = L"Middle Camera";
			// 
			// btnRefresh
			// 
			this->btnRefresh->Location = System::Drawing::Point(1268, 239);
			this->btnRefresh->Name = L"btnRefresh";
			this->btnRefresh->Size = System::Drawing::Size(70, 60);
			this->btnRefresh->TabIndex = 22;
			this->btnRefresh->Text = L"Refresh";
			this->btnRefresh->UseVisualStyleBackColor = true;
			this->btnRefresh->Click += gcnew System::EventHandler(this, &CalibarateWindow::btnRefresh_Click);
			// 
			// LBtn0
			// 
			this->LBtn0->AutoSize = true;
			this->LBtn0->Checked = true;
			this->LBtn0->Location = System::Drawing::Point(5, 19);
			this->LBtn0->Name = L"LBtn0";
			this->LBtn0->Size = System::Drawing::Size(31, 17);
			this->LBtn0->TabIndex = 23;
			this->LBtn0->TabStop = true;
			this->LBtn0->Text = L"0";
			this->LBtn0->UseVisualStyleBackColor = true;
			// 
			// LBtn1
			// 
			this->LBtn1->AutoSize = true;
			this->LBtn1->Location = System::Drawing::Point(40, 19);
			this->LBtn1->Name = L"LBtn1";
			this->LBtn1->Size = System::Drawing::Size(31, 17);
			this->LBtn1->TabIndex = 24;
			this->LBtn1->Text = L"1";
			this->LBtn1->UseVisualStyleBackColor = true;
			// 
			// LBtn2
			// 
			this->LBtn2->AutoSize = true;
			this->LBtn2->Location = System::Drawing::Point(5, 42);
			this->LBtn2->Name = L"LBtn2";
			this->LBtn2->Size = System::Drawing::Size(31, 17);
			this->LBtn2->TabIndex = 25;
			this->LBtn2->Text = L"2";
			this->LBtn2->UseVisualStyleBackColor = true;
			// 
			// MBtn2
			// 
			this->MBtn2->AutoSize = true;
			this->MBtn2->Location = System::Drawing::Point(6, 43);
			this->MBtn2->Name = L"MBtn2";
			this->MBtn2->Size = System::Drawing::Size(31, 17);
			this->MBtn2->TabIndex = 28;
			this->MBtn2->Text = L"2";
			this->MBtn2->UseVisualStyleBackColor = true;
			// 
			// MBtn1
			// 
			this->MBtn1->AutoSize = true;
			this->MBtn1->Checked = true;
			this->MBtn1->Location = System::Drawing::Point(40, 20);
			this->MBtn1->Name = L"MBtn1";
			this->MBtn1->Size = System::Drawing::Size(31, 17);
			this->MBtn1->TabIndex = 27;
			this->MBtn1->TabStop = true;
			this->MBtn1->Text = L"1";
			this->MBtn1->UseVisualStyleBackColor = true;
			// 
			// MBtn0
			// 
			this->MBtn0->AutoSize = true;
			this->MBtn0->Location = System::Drawing::Point(6, 20);
			this->MBtn0->Name = L"MBtn0";
			this->MBtn0->Size = System::Drawing::Size(31, 17);
			this->MBtn0->TabIndex = 26;
			this->MBtn0->Text = L"0";
			this->MBtn0->UseVisualStyleBackColor = true;
			// 
			// RBtn2
			// 
			this->RBtn2->AutoSize = true;
			this->RBtn2->Checked = true;
			this->RBtn2->Location = System::Drawing::Point(6, 43);
			this->RBtn2->Name = L"RBtn2";
			this->RBtn2->Size = System::Drawing::Size(31, 17);
			this->RBtn2->TabIndex = 31;
			this->RBtn2->TabStop = true;
			this->RBtn2->Text = L"2";
			this->RBtn2->UseVisualStyleBackColor = true;
			// 
			// RBtn1
			// 
			this->RBtn1->AutoSize = true;
			this->RBtn1->Location = System::Drawing::Point(40, 22);
			this->RBtn1->Name = L"RBtn1";
			this->RBtn1->Size = System::Drawing::Size(31, 17);
			this->RBtn1->TabIndex = 30;
			this->RBtn1->TabStop = true;
			this->RBtn1->Text = L"1";
			this->RBtn1->UseVisualStyleBackColor = true;
			// 
			// RBtn0
			// 
			this->RBtn0->AutoSize = true;
			this->RBtn0->Location = System::Drawing::Point(6, 22);
			this->RBtn0->Name = L"RBtn0";
			this->RBtn0->Size = System::Drawing::Size(31, 17);
			this->RBtn0->TabIndex = 29;
			this->RBtn0->TabStop = true;
			this->RBtn0->Text = L"0";
			this->RBtn0->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->LBtn2);
			this->panel1->Controls->Add(this->LBtn1);
			this->panel1->Controls->Add(this->LBtn0);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(1257, 14);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(84, 65);
			this->panel1->TabIndex = 32;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->MBtn2);
			this->panel2->Controls->Add(this->MBtn1);
			this->panel2->Controls->Add(this->MBtn0);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Location = System::Drawing::Point(1257, 85);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(84, 66);
			this->panel2->TabIndex = 33;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->RBtn1);
			this->panel3->Controls->Add(this->RBtn0);
			this->panel3->Controls->Add(this->label2);
			this->panel3->Controls->Add(this->RBtn2);
			this->panel3->Location = System::Drawing::Point(1257, 157);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(85, 66);
			this->panel3->TabIndex = 34;
			// 
			// CalibarateWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1350, 388);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->btnRefresh);
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
			this->Load += gcnew System::EventHandler(this, &CalibarateWindow::CalibarateWindow_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cam1Image))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cam2Image))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cam3Image))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);

		}

		void viewCameraLeft() {
			int lcameraID;

			if ((LBtn0->Checked) && !(MBtn0->Checked) && !(RBtn0->Checked)) {
				lcameraID = 0;
			}

			if ((LBtn1->Checked) && !(MBtn1->Checked) && !(RBtn1->Checked)) {
				lcameraID = 1;
			}

			if ((LBtn2->Checked) && !(MBtn2->Checked) && !(RBtn2->Checked)) {
				lcameraID = 2;
			}

			VideoCapture cap(lcameraID);
			cap.set(CV_CAP_PROP_FRAME_WIDTH, 800);
			cap.set(CV_CAP_PROP_FRAME_HEIGHT, 600);
			Mat frame;

			while (true)
			{
				if (cap.read(frame)) {
					System::Drawing::Graphics^ graphics = cam1Image->CreateGraphics();
					System::IntPtr ptr(frame.ptr());
					System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(frame.cols, frame.rows, frame.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
					System::Drawing::RectangleF rect(0, 0, cam1Image->Width, cam1Image->Height);

					graphics->DrawImage(b, rect);
					delete graphics;

					int c = waitKey(40);

					if (c == char('q')) {
						break;
					}
				}
				else {
					break;
				}
			}
			cap.release();
		}

		void viewCameraMiddle() {
			int mcameraID;

			if (!(LBtn0->Checked) && (MBtn0->Checked) && !(RBtn0->Checked)) {
				mcameraID = 0;
			}

			if (!(LBtn1->Checked) && (MBtn1->Checked) && !(RBtn1->Checked)) {
				mcameraID = 1;
			}

			if (!(LBtn2->Checked) && (MBtn2->Checked) && !(RBtn2->Checked)) {
				mcameraID = 2;
			}

			VideoCapture cap(mcameraID);
			cap.set(CV_CAP_PROP_FRAME_WIDTH, 800);
			cap.set(CV_CAP_PROP_FRAME_HEIGHT, 600);
			Mat frame;

			while (true)
			{
				if (cap.read(frame)) {
					System::Drawing::Graphics^ graphics = cam2Image->CreateGraphics();
					System::IntPtr ptr(frame.ptr());
					System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(frame.cols, frame.rows, frame.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
					System::Drawing::RectangleF rect(0, 0, cam2Image->Width, cam2Image->Height);
					graphics->DrawImage(b, rect);
					delete graphics;

					int c = waitKey(40);

					if (c == char('q')) {
						break;
					}
				}
				else {
					break;
				}
			}
			cap.release();
		}

		void viewCameraRight() {
			int rcameraID;

			if (!(LBtn0->Checked) && !(MBtn0->Checked) && (RBtn0->Checked)) {
				rcameraID = 0;
			}

			if (!(LBtn1->Checked) && !(MBtn1->Checked) && (RBtn1->Checked)) {
				rcameraID = 1;
			}

			if (!(LBtn2->Checked) && !(MBtn2->Checked) && (RBtn2->Checked)) {
				rcameraID = 2;
			}

			VideoCapture cap(rcameraID);
			cap.set(CV_CAP_PROP_FRAME_WIDTH, 800);
			cap.set(CV_CAP_PROP_FRAME_HEIGHT, 600);
			Mat frame;

			while (true)
			{
				if (cap.read(frame)) {
					System::Drawing::Graphics^ graphics = cam3Image->CreateGraphics();
					System::IntPtr ptr(frame.ptr());
					System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(frame.cols, frame.rows, frame.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
					System::Drawing::RectangleF rect(0, 0, cam3Image->Width, cam3Image->Height);
					graphics->DrawImage(b, rect);
					delete graphics;

					int c = waitKey(40);

					if (c == char('q')) {
						break;
					}
				}
				else {
					break;
				}
			}
			cap.release();
		}

#pragma endregion
private: System::Void btnDone_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}

Thread^ threadLeft = gcnew Thread(gcnew ThreadStart(this, &CalibarateWindow::viewCameraLeft));
Thread^ threadMiddle = gcnew Thread(gcnew ThreadStart(this, &CalibarateWindow::viewCameraMiddle));
Thread^ threadRight = gcnew Thread(gcnew ThreadStart(this, &CalibarateWindow::viewCameraRight));

private: System::Void CalibarateWindow_Load(System::Object^  sender, System::EventArgs^  e) {
	threadLeft->Start();
	threadMiddle->Start();
	threadRight->Start();
}

private: System::Void btnRefresh_Click(System::Object^  sender, System::EventArgs^  e) {
	threadLeft->Abort();
	threadMiddle->Abort();
	threadRight->Abort();

	Thread^ threadLeft2 = gcnew Thread(gcnew ThreadStart(this, &CalibarateWindow::viewCameraLeft));
	Thread^ threadMiddle2 = gcnew Thread(gcnew ThreadStart(this, &CalibarateWindow::viewCameraMiddle));
	Thread^ threadRight2 = gcnew Thread(gcnew ThreadStart(this, &CalibarateWindow::viewCameraRight));

	threadLeft2->Start();
	threadMiddle2->Start();
	threadRight2->Start();
}
};
}
