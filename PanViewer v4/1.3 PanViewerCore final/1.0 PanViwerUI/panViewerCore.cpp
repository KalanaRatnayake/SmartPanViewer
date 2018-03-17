#include "panViewerCore.h"
#include "right_frame_queue.h"
#include "left_frame_queue.h"
#include "middle_frame_queue.h"
#include "stitched_frame_queue.h"
#include "gpuStitcher.h"
#include "boost\chrono.hpp"
#include "boost\thread.hpp"

bool leftThreadRun;
bool middleThreadRun;
bool rightThreadRun;
bool stitchedThreadRun;

left_frame_queue leftQueue = left_frame_queue(20);
middle_frame_queue middleQueue = middle_frame_queue(20);
right_frame_queue rightQueue = right_frame_queue(20);
stitched_frame_queue stitchQueue = stitched_frame_queue(20);

boost::thread leftfeed;
boost::thread middlefeed;
boost::thread rightfeed;
boost::thread toStitcher;

//==================================================== Internal functions ========================================================

void wait(int miliseconds)
{
	boost::this_thread::sleep_for(boost::chrono::milliseconds{ miliseconds });
}

void feedFromLeftCamera(int port, int width, int height, left_frame_queue holder) {
	cv::VideoCapture cam = cv::VideoCapture(port);
	cam.set(CV_CAP_PROP_FRAME_WIDTH, width);
	cam.set(CV_CAP_PROP_FRAME_HEIGHT, height);

	while (leftThreadRun) {
		if (cam.isOpened())
		{
			cv::Mat	frame;
			if (cam.read(frame)) {
				holder.pushLeft(frame);
			}
		}
		wait(70);
	}
}

void feedFromMiddleCamera(int port, int width, int height, middle_frame_queue holder) {
	cv::VideoCapture cam = cv::VideoCapture(port);
	cam.set(CV_CAP_PROP_FRAME_WIDTH, width);
	cam.set(CV_CAP_PROP_FRAME_HEIGHT, height);

	while (middleThreadRun) {
		if (cam.isOpened())
		{
			cv::Mat	frame;
			if (cam.read(frame)) {
				holder.pushMiddle(frame);
			}
		}
		wait(70);
	}
}

void feedFromRightCamera(int port, int width, int height, right_frame_queue holder) {
	cv::VideoCapture cam = cv::VideoCapture(port);
	cam.set(CV_CAP_PROP_FRAME_WIDTH, width);
	cam.set(CV_CAP_PROP_FRAME_HEIGHT, height);

	while (rightThreadRun) {
		if (cam.isOpened())
		{
			cv::Mat	frame;
			if (cam.read(frame)) {
				holder.pushRight(frame);
			}
		}
		wait(70);
	}
}

void feedToStitch(left_frame_queue leftQueue, middle_frame_queue middleQueue, right_frame_queue rightQueue, stitched_frame_queue stitchQueue) {
	try {
		cv::Mat left, middle, right;
		gpuStitcher stitcher = gpuStitcher();

		leftQueue.left_wait_and_pop(left);
		middleQueue.middle_wait_and_pop(middle);
		rightQueue.right_wait_and_pop(right);

		stitcher.gpuCalibrate(left, middle, right);

		while (stitchedThreadRun) {
			cv::Mat left, middle, right, image;

			leftQueue.left_wait_and_pop(left);
			middleQueue.middle_wait_and_pop(middle);
			rightQueue.right_wait_and_pop(right);

			stitcher.gpuStitch(left, middle, right, image);

			stitchQueue.pushstitched(image);
		}
	}
	catch (cv::Exception& e) {
		cv::Mat left2, middle2, right2;

		leftQueue.left_wait_and_pop(left2);
		middleQueue.middle_wait_and_pop(middle2);
		rightQueue.right_wait_and_pop(right2);

		left2.release();
		middle2.release();
		right2.release();

		feedToStitch(leftQueue, middleQueue, rightQueue, stitchQueue);
	}
}

void initialize(int leftCamPort, int middleCamPort, int rightCamPort, int width, int height) {
	leftfeed = boost::thread { feedFromLeftCamera, leftCamPort, width, height, leftQueue };
	middlefeed = boost::thread { feedFromMiddleCamera, middleCamPort, width, height, middleQueue };
	rightfeed = boost::thread { feedFromRightCamera, rightCamPort, width, height, rightQueue };
	toStitcher = boost::thread { feedToStitch, leftQueue, middleQueue, rightQueue, stitchQueue };

	leftfeed.detach();
	middlefeed.detach();
	rightfeed.detach();
	toStitcher.detach();
}


//================================================ functions visible to outside =================================================

panViewerCore::panViewerCore() {
}

panViewerCore::panViewerCore(int left, int middle, int right, int width, int height){
	leftThreadRun = true;
	middleThreadRun = true;
	rightThreadRun = true;
	stitchedThreadRun = true;

	initialize(left, middle, right, width, height);
}

cv::Mat panViewerCore::leftCameraImage(){
	cv::Mat frame;
	leftQueue.left_wait_and_pop(frame);
	return frame;
}

cv::Mat panViewerCore::middleCameraImage() {
	cv::Mat frame;
	middleQueue.middle_wait_and_pop(frame);
	return frame;
}

cv::Mat panViewerCore::rightCameraImage() {
	cv::Mat frame;
	rightQueue.right_wait_and_pop(frame);
	return frame;
}

cv::Mat panViewerCore::stitchedImage() {
	cv::Mat frame;
	stitchQueue.stitched_wait_and_pop(frame);
	return frame;
}

panViewerCore::~panViewerCore() {
	leftThreadRun = false;
	middleThreadRun = false;
	rightThreadRun = false;
	stitchedThreadRun = false;
}
