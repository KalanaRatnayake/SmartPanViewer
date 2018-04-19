#include "cameraController.h"
#include "opencv2\opencv.hpp"

cv::VideoCapture cap;

//will create the VideoCapture object according to paarameters
cameraController::cameraController(int port, int WindowWidth, int WindowHeight){
	cap = cv::VideoCapture(port);
	cap.set(CV_CAP_PROP_FRAME_WIDTH, WindowWidth);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, WindowHeight);
}

//will feed a frame 
bool cameraController::feedFrame(cv::Mat& frame) {
	if (cap.read(frame)) {
		return true;
	} else {
		return false;
	}
}

//will call release() and release the camera connected through port
cameraController::~cameraController(){
	cap.~VideoCapture();
}
