#pragma once

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
	using namespace cuda;

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
			this->Load += gcnew System::EventHandler(this, &MapWindow::MapWindow_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgMap))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->vidFrame))->EndInit();
			this->ResumeLayout(false);

		}

		void threadedMain() {
			VideoCapture CapL, CapM, CapR;
			Mat frameL, frameM, frameR, transL, transM, transResult, homographyLM, homographyR_LM, result, finalImage;
			GpuMat GframeL, GframeM, GframeR, GtransL, GtransM, GtransResult, Gresult, GfinalImage;

			bool state = true;

			while (state) {
				CapL = VideoCapture(0);
				CapL.set(CV_CAP_PROP_FRAME_WIDTH, 800);
				CapL.set(CV_CAP_PROP_FRAME_HEIGHT, 600);

				CapM = VideoCapture(1);
				CapM.set(CV_CAP_PROP_FRAME_WIDTH, 800);
				CapM.set(CV_CAP_PROP_FRAME_HEIGHT, 600);

				CapR = VideoCapture(2);
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

#pragma endregion
	private: System::Void btnDone_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}

private: System::Void MapWindow_Load(System::Object^  sender, System::EventArgs^  e) {
	Thread^ thread1 = gcnew Thread(gcnew ThreadStart(this, &MapWindow::threadedMain));
	thread1->Start();
}
};
}
