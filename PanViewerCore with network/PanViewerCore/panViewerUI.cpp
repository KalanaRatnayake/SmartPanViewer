#include "panViewerUI.h"
#include "panViewerCore.h"
#include "boost\thread.hpp"

#define CVUI_IMPLEMENTATION
#include "cvui.h"
#include "wtypes.h"
#include <iostream>

#define WINDOW1_NAME "Panaromic View"
#define WINDOW2_NAME "Camera View"
#define WINDOW3_NAME "PanViewer"

panViewerCore panCore;
int WindowWidth;
int WindowHeight;

panViewerUI::panViewerUI() {
}

panViewerUI::panViewerUI(int left, int middle, int right, int width, int height){
	panCore = panViewerCore(left, middle, right, (width/3), height/2);
	WindowWidth = width;
	WindowHeight = height;
}

void panViewerUI::stitchedOutput() {
	cvui::init(WINDOW1_NAME, 0, 0);

	cv::Mat frame = cv::Mat(cv::Size((WindowWidth + 10), (WindowHeight + 10)), CV_8UC3);

	while (true) {
		cv::Mat stitched = panCore.stitchedImage();

		cvui::image(frame, 5, 5, stitched);
		cvui::imshow(WINDOW1_NAME, frame);

		if (cv::waitKey(20) == 27) {
			break;
		}
	}
}

void panViewerUI::openCameraOutput() {
	cvui::init(WINDOW2_NAME, 0, 0);

	cv::Mat frame = cv::Mat(cv::Size((WindowWidth+20), (WindowHeight+10)), CV_8UC3);

	while (true) {

		cv::Mat left = panCore.leftCameraImage();
		cv::Mat middle = panCore.middleCameraImage();
		cv::Mat right = panCore.rightCameraImage();

		cvui::image(frame, 5, 5, left);
		cvui::image(frame, ((WindowWidth /3) + 10), 5, middle);
		cvui::image(frame, (2*(WindowWidth /3) + 15), 5, right);

		cvui::imshow(WINDOW2_NAME, frame);

		if (cv::waitKey(20) == 27) {
			break;
		}
	}
}

void panViewerUI::openAllOutputs() {
	cvui::init(WINDOW3_NAME, 0, 0);

	cv::Mat frame = cv::Mat(cv::Size((WindowWidth + 20), (WindowHeight + 10)), CV_8UC3);

	while (true) {

		cv::Mat left = panCore.leftCameraImage();
		cv::Mat middle = panCore.middleCameraImage();
		cv::Mat right = panCore.rightCameraImage();
		cv::Mat stitched = panCore.stitchedImage();

		cvui::image(frame, 5, 5, left);
		cvui::image(frame, ((WindowWidth / 3) + 10), 5, middle);
		cvui::image(frame, (2 * (WindowWidth / 3) + 15), 5, right);
		cvui::image(frame, 5, WindowHeight/2, stitched);

		cvui::imshow(WINDOW3_NAME, frame);

		if (cv::waitKey(20) == 27) {
			break;
		}
	}
}

void panViewerUI::deleteUI(){
	panCore.deleteCore();
}
