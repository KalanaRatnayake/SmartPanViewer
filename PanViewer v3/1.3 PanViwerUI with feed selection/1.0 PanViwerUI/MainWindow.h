#pragma once

#include "CalibarateWindow.h"
#include "MapWindow.h"
#include "CoreProgram.h"
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
#include <chrono>

namespace My10PanViwerUI {

	using namespace System;
	using namespace System::Threading;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace cv;
	using namespace cuda;


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
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::RadioButton^  RBtn1;
	private: System::Windows::Forms::RadioButton^  RBtn0;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::RadioButton^  RBtn2;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::RadioButton^  MBtn2;
	private: System::Windows::Forms::RadioButton^  MBtn1;
	private: System::Windows::Forms::RadioButton^  MBtn0;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::RadioButton^  LBtn2;
	private: System::Windows::Forms::RadioButton^  LBtn1;
	private: System::Windows::Forms::RadioButton^  LBtn0;
	private: System::Windows::Forms::Label^  label1;

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
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->RBtn1 = (gcnew System::Windows::Forms::RadioButton());
			this->RBtn0 = (gcnew System::Windows::Forms::RadioButton());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->RBtn2 = (gcnew System::Windows::Forms::RadioButton());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->MBtn2 = (gcnew System::Windows::Forms::RadioButton());
			this->MBtn1 = (gcnew System::Windows::Forms::RadioButton());
			this->MBtn0 = (gcnew System::Windows::Forms::RadioButton());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->LBtn2 = (gcnew System::Windows::Forms::RadioButton());
			this->LBtn1 = (gcnew System::Windows::Forms::RadioButton());
			this->LBtn0 = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->vidFrame))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgMap))->BeginInit();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
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
			this->btnShutDown->Click += gcnew System::EventHandler(this, &MainWindow::btnShutDown_Click);
			// 
			// btnAutoAdjust
			// 
			this->btnAutoAdjust->Location = System::Drawing::Point(1158, 326);
			this->btnAutoAdjust->Name = L"btnAutoAdjust";
			this->btnAutoAdjust->Size = System::Drawing::Size(180, 50);
			this->btnAutoAdjust->TabIndex = 4;
			this->btnAutoAdjust->Text = L"Auto Adjust";
			this->btnAutoAdjust->UseVisualStyleBackColor = true;
			this->btnAutoAdjust->Click += gcnew System::EventHandler(this, &MainWindow::btnAutoAdjust_Click);
			// 
			// btnManualAdjust
			// 
			this->btnManualAdjust->Location = System::Drawing::Point(972, 326);
			this->btnManualAdjust->Name = L"btnManualAdjust";
			this->btnManualAdjust->Size = System::Drawing::Size(180, 50);
			this->btnManualAdjust->TabIndex = 5;
			this->btnManualAdjust->Text = L"Manual Adjust";
			this->btnManualAdjust->UseVisualStyleBackColor = true;
			this->btnManualAdjust->Click += gcnew System::EventHandler(this, &MainWindow::btnManualAdjust_Click);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->RBtn1);
			this->panel3->Controls->Add(this->RBtn0);
			this->panel3->Controls->Add(this->label2);
			this->panel3->Controls->Add(this->RBtn2);
			this->panel3->Location = System::Drawing::Point(734, 326);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(112, 50);
			this->panel3->TabIndex = 37;
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
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 4);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 13);
			this->label2->TabIndex = 17;
			this->label2->Text = L"Right Camera";
			// 
			// RBtn2
			// 
			this->RBtn2->AutoSize = true;
			this->RBtn2->Checked = true;
			this->RBtn2->Location = System::Drawing::Point(77, 22);
			this->RBtn2->Name = L"RBtn2";
			this->RBtn2->Size = System::Drawing::Size(31, 17);
			this->RBtn2->TabIndex = 31;
			this->RBtn2->TabStop = true;
			this->RBtn2->Text = L"2";
			this->RBtn2->UseVisualStyleBackColor = true;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->MBtn2);
			this->panel2->Controls->Add(this->MBtn1);
			this->panel2->Controls->Add(this->MBtn0);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Location = System::Drawing::Point(596, 326);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(111, 50);
			this->panel2->TabIndex = 36;
			// 
			// MBtn2
			// 
			this->MBtn2->AutoSize = true;
			this->MBtn2->Location = System::Drawing::Point(77, 20);
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
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(2, 4);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 13);
			this->label3->TabIndex = 18;
			this->label3->Text = L"Middle Camera";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->LBtn2);
			this->panel1->Controls->Add(this->LBtn1);
			this->panel1->Controls->Add(this->LBtn0);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(461, 326);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(111, 50);
			this->panel1->TabIndex = 35;
			// 
			// LBtn2
			// 
			this->LBtn2->AutoSize = true;
			this->LBtn2->Location = System::Drawing::Point(77, 19);
			this->LBtn2->Name = L"LBtn2";
			this->LBtn2->Size = System::Drawing::Size(31, 17);
			this->LBtn2->TabIndex = 25;
			this->LBtn2->Text = L"2";
			this->LBtn2->UseVisualStyleBackColor = true;
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
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 3);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 13);
			this->label1->TabIndex = 16;
			this->label1->Text = L"Left Camera";
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(1350, 388);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
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
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}

		//custom defined function

		void threadedMain() {
			int Lcam, Mcam, Rcam;
			VideoCapture CapL, CapM, CapR;
			Mat frameL, frameM, frameR, transL, transM, transResult, homographyLM, homographyR_LM, result, finalImage;
			GpuMat GframeL, GframeM, GframeR, GtransL, GtransM, GtransResult, Gresult, GfinalImage;

			if ((LBtn0->Checked) && !(MBtn0->Checked) && !(RBtn0->Checked)) {
				Lcam = 0;
			}
			if ((LBtn1->Checked) && !(MBtn1->Checked) && !(RBtn1->Checked)) {
				Lcam = 1;
			}
			if ((LBtn2->Checked) && !(MBtn2->Checked) && !(RBtn2->Checked)) {
				Lcam = 2;
			}
			if (!(LBtn0->Checked) && (MBtn0->Checked) && !(RBtn0->Checked)) {
				Mcam = 0;
			}
			if (!(LBtn1->Checked) && (MBtn1->Checked) && !(RBtn1->Checked)) {
				Mcam = 1;
			}
			if (!(LBtn2->Checked) && (MBtn2->Checked) && !(RBtn2->Checked)) {
				Mcam = 2;
			}
			if (!(LBtn0->Checked) && !(MBtn0->Checked) && (RBtn0->Checked)) {
				Rcam = 0;
			}
			if (!(LBtn1->Checked) && !(MBtn1->Checked) && (RBtn1->Checked)) {
				Rcam = 1;
			}
			if (!(LBtn2->Checked) && !(MBtn2->Checked) && (RBtn2->Checked)) {
				Rcam = 2;
			}

			bool state = true;

			while (state) {
				CapL = VideoCapture(Lcam);
				CapL.set(CV_CAP_PROP_FRAME_WIDTH, 800);
				CapL.set(CV_CAP_PROP_FRAME_HEIGHT, 600);

				CapM = VideoCapture(Mcam);
				CapM.set(CV_CAP_PROP_FRAME_WIDTH, 800);
				CapM.set(CV_CAP_PROP_FRAME_HEIGHT, 600);

				CapR = VideoCapture(Rcam);
				CapR.set(CV_CAP_PROP_FRAME_WIDTH, 800);
				CapR.set(CV_CAP_PROP_FRAME_HEIGHT, 600);

				//take initial images to caliberate
				if (CapL.read(frameL)) {
					if (CapM.read(frameM)) {
						if (CapR.read(frameR)) {
							state = false;
						}
					}
				}

				cv::flip(frameL, transL, 1);
				cv::flip(frameM, transM, 1);
				getHomographyMatrix(transL, transM, 0.75, 4.0, homographyLM);

				stitch(transL, transM, homographyLM, transResult);
				cv::flip(transResult, result, 1);
				getHomographyMatrix(frameR, result, 0.75, 4.0, homographyR_LM);
			}

			transL.release();
			transM.release();
			transResult.release();
			result.release();
			frameL.release();
			frameM.release();
			frameR.release();


			while (true) {
				if (CapL.read(frameL) == false) {
					continue;
				}
				if (CapM.read(frameM) == false) {
					continue;
				}
				if (CapR.read(frameR) == false) {
					continue;
				}


				//upload frames to gpu for processsing
				GframeL.upload(frameL);
				GframeM.upload(frameM);
				GframeR.upload(frameR);

				gpuEqualizeImage(GframeL, GframeL);
				gpuEqualizeImage(GframeM, GframeM);
				gpuEqualizeImage(GframeR, GframeR);

				cuda::flip(GframeL, GtransL, 1);
				cuda::flip(GframeM, GtransM, 1);

				gpuStitch(GtransL, GtransM, homographyLM, GtransResult);

				cuda::flip(GtransResult, Gresult, 1);
				gpuStitch(GframeR, Gresult, homographyR_LM, GfinalImage);

				GfinalImage.download(finalImage);

				if (true) {
					System::Drawing::Graphics^ graphics = vidFrame->CreateGraphics();
					System::IntPtr ptr(finalImage.ptr());
					System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(finalImage.cols, finalImage.rows, finalImage.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
					System::Drawing::RectangleF rect(0, 0, vidFrame->Width, vidFrame->Height);
					graphics->DrawImage(b, rect);
					delete graphics;

					frameL.release();
					frameM.release();
					frameR.release();
					GframeL.release();
					GframeM.release();
					GframeR.release();
					GtransL.release();
					GtransM.release();
					GtransResult.release();
					Gresult.release();
					GfinalImage.release();

					int c = waitKey(40);
					if (c == char('q')) {
						break;
					}
				}
				else {
					break;
				}
			}

			waitKey(0);
			cv::destroyAllWindows();
			CapL.release();
			CapM.release();
			CapR.release();
		}

		void threadedMainLoop() {
			while (true) {
				int Lcam, Mcam, Rcam;
				VideoCapture CapL, CapM, CapR;
				Mat frameL, frameM, frameR, transL, transM, transResult, homographyLM, homographyR_LM, result, finalImage;
				GpuMat GframeL, GframeM, GframeR, GtransL, GtransM, GtransResult, Gresult, GfinalImage;

				if ((LBtn0->Checked) && !(MBtn0->Checked) && !(RBtn0->Checked)) {
					Lcam = 0;
				}
				if ((LBtn1->Checked) && !(MBtn1->Checked) && !(RBtn1->Checked)) {
					Lcam = 1;
				}
				if ((LBtn2->Checked) && !(MBtn2->Checked) && !(RBtn2->Checked)) {
					Lcam = 2;
				}
				if (!(LBtn0->Checked) && (MBtn0->Checked) && !(RBtn0->Checked)) {
					Mcam = 0;
				}
				if (!(LBtn1->Checked) && (MBtn1->Checked) && !(RBtn1->Checked)) {
					Mcam = 1;
				}
				if (!(LBtn2->Checked) && (MBtn2->Checked) && !(RBtn2->Checked)) {
					Mcam = 2;
				}
				if (!(LBtn0->Checked) && !(MBtn0->Checked) && (RBtn0->Checked)) {
					Rcam = 0;
				}
				if (!(LBtn1->Checked) && !(MBtn1->Checked) && (RBtn1->Checked)) {
					Rcam = 1;
				}
				if (!(LBtn2->Checked) && !(MBtn2->Checked) && (RBtn2->Checked)) {
					Rcam = 2;
				}

				bool state = true;

				while (state) {
					CapL = VideoCapture(Lcam);
					CapL.set(CV_CAP_PROP_FRAME_WIDTH, 800);
					CapL.set(CV_CAP_PROP_FRAME_HEIGHT, 600);

					CapM = VideoCapture(Mcam);
					CapM.set(CV_CAP_PROP_FRAME_WIDTH, 800);
					CapM.set(CV_CAP_PROP_FRAME_HEIGHT, 600);

					CapR = VideoCapture(Rcam);
					CapR.set(CV_CAP_PROP_FRAME_WIDTH, 800);
					CapR.set(CV_CAP_PROP_FRAME_HEIGHT, 600);

					//take initial images to caliberate
					if (CapL.read(frameL)) {
						if (CapM.read(frameM)) {
							if (CapR.read(frameR)) {
								state = false;
							}
						}
					}

					cv::flip(frameL, transL, 1);
					cv::flip(frameM, transM, 1);
					getHomographyMatrix(transL, transM, 0.75, 4.0, homographyLM);

					stitch(transL, transM, homographyLM, transResult);
					cv::flip(transResult, result, 1);
					getHomographyMatrix(frameR, result, 0.75, 4.0, homographyR_LM);
				}

				transL.release();
				transM.release();
				transResult.release();
				result.release();
				frameL.release();
				frameM.release();
				frameR.release();



				while (true) {
					if (CapL.read(frameL) == false) {
						continue;
					}
					if (CapM.read(frameM) == false) {
						continue;
					}
					if (CapR.read(frameR) == false) {
						continue;
					}


					//upload frames to gpu for processsing
					GframeL.upload(frameL);
					GframeM.upload(frameM);
					GframeR.upload(frameR);

					gpuEqualizeImage(GframeL, GframeL);
					gpuEqualizeImage(GframeM, GframeM);
					gpuEqualizeImage(GframeR, GframeR);

					cuda::flip(GframeL, GtransL, 1);
					cuda::flip(GframeM, GtransM, 1);

					gpuStitch(GtransL, GtransM, homographyLM, GtransResult);

					cuda::flip(GtransResult, Gresult, 1);
					gpuStitch(GframeR, Gresult, homographyR_LM, GfinalImage);

					GfinalImage.download(finalImage);

					if (true) {
						System::Drawing::Graphics^ graphics = vidFrame->CreateGraphics();
						System::IntPtr ptr(finalImage.ptr());
						System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(finalImage.cols, finalImage.rows, finalImage.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
						System::Drawing::RectangleF rect(0, 0, vidFrame->Width, vidFrame->Height);
						graphics->DrawImage(b, rect);
						delete graphics;

						frameL.release();
						frameM.release();
						frameR.release();
						GframeL.release();
						GframeM.release();
						GframeR.release();
						GtransL.release();
						GtransM.release();
						GtransResult.release();
						Gresult.release();
						GfinalImage.release();

						int c = waitKey(40);
						if (c == char('q')) {
							break;
						}
					}
					else {
						break;
					}
				}

				waitKey(0);
				cv::destroyAllWindows();
				CapL.release();
				CapM.release();
				CapR.release();
			}
		}

#pragma endregion
private: System::Void btnCalibarate_Click(System::Object^  sender, System::EventArgs^  e) {
	CalibarateWindow^ calibWindow = gcnew CalibarateWindow();
	calibWindow->ShowDialog(this);
}
private: System::Void imgMap_Click(System::Object^  sender, System::EventArgs^  e) {
	MapWindow^ mapWindow = gcnew MapWindow();
	mapWindow->ShowDialog(this);
}
private: System::Void btnShutDown_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
	system("shutdown -s");
}
private: System::Void btnManualAdjust_Click(System::Object^  sender, System::EventArgs^  e) {
	Thread^ thread1 = gcnew Thread(gcnew ThreadStart(this, &MainWindow::threadedMain));
	thread1->Start();
}
private: System::Void btnAutoAdjust_Click(System::Object^  sender, System::EventArgs^  e) {
	Thread^ thread2 = gcnew Thread(gcnew ThreadStart(this, &MainWindow::threadedMain));
	thread2->Start();
}
};
}
