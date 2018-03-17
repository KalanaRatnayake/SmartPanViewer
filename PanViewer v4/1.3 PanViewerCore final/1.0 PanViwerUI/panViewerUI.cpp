#include "panViewerUI.h"
#include "panViewerCore.h"
#include "boost\thread.hpp"

#define CVUI_IMPLEMENTATION
#include "cvui.h"

#define WINDOW1_NAME "Panaromic View"
#define WINDOW2_NAME "Camera View"

panViewerCore panCore;
int WindowWidth;
int WindowHeight;

panViewerUI::panViewerUI(int left, int middle, int right, int width, int height){
	panCore = panViewerCore(left, middle, right, (width/3), height);
	WindowWidth = width;
	WindowHeight = height;
}

void panViewerUI::stitchedOutput() {
	cvui::init(WINDOW1_NAME);
	cv::Mat frame = cv::Mat(cv::Size((WindowWidth + 40), (WindowHeight + 20)), CV_8UC3);

	while (true) {
		cv::Mat stitched = panCore.stitchedImage();

		cvui::image(frame, 10, 10, stitched);
		cvui::imshow(WINDOW1_NAME, frame);

		if (cv::waitKey(20) == 27) {
			break;
		}
	}
}

void panViewerUI::openCameraOutput() {
	cvui::init(WINDOW2_NAME);

	cv::Mat frame = cv::Mat(cv::Size((WindowWidth), (WindowHeight)), CV_8UC3);

	while (true) {

		cv::Mat left = panCore.leftCameraImage();
		cv::Mat middle = panCore.middleCameraImage();
		cv::Mat right = panCore.rightCameraImage();

		cvui::image(frame, 0, 10, left);
		cvui::image(frame, ((WindowWidth /3) + 5), 10, middle);
		cvui::image(frame, (2*(WindowWidth /3) + 10), 10, right);

		cvui::imshow(WINDOW2_NAME, frame);

		if (cv::waitKey(20) == 27) {
			break;
		}
	}
}

panViewerUI::~panViewerUI(){
	panCore.~panViewerCore();
}
