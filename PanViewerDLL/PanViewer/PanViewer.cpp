// PanViewer.cpp : Defines the exported functions for the DLL application.
//

#ifndef uchar
typedef unsigned char uchar;
#endif

#include "PanViewer.h"
#include "opencv2\opencv.hpp"
#include "panViewerCore.h"

panViewerCore pvCore;

extern "C" {

	__declspec(dllexport) void createCore(int left, int middle, int right) {
		pvCore = panViewerCore(left, middle, right);
	}

	__declspec(dllexport) uchar* returnLeftCameraImage() {
		cv::Mat frame = pvCore.leftCameraImage();
		static cv::Mat tmp;
		cv::cvtColor(frame, tmp, CV_BGR2RGB);
		return tmp.data;
	}

	__declspec(dllexport) uchar* returnMiddleCameraImage() {
		cv::Mat frame = pvCore.middleCameraImage();
		static cv::Mat tmp;
		cv::cvtColor(frame, tmp, CV_BGR2RGB);
		return tmp.data;
	}

	__declspec(dllexport) uchar* returnRightCameraImage() {
		cv::Mat frame = pvCore.rightCameraImage();
		static cv::Mat tmp;
		cv::cvtColor(frame, tmp, CV_BGR2RGB);
		return tmp.data;
	}

	__declspec(dllexport) uchar* returnStitchedImage() {
		cv::Mat frame = pvCore.stitchedImage();
		static cv::Mat tmp;
		cv::cvtColor(frame, tmp, CV_BGR2RGB);
		return tmp.data;
	}
}