#include "right_frame_queue.h"
#include "left_frame_queue.h"
#include "middle_frame_queue.h"
#include "stitcher.h"
#include "settings.h"
#include "boost\chrono.hpp"
#include "boost\thread.hpp"

void wait(int seconds)
{
	boost::this_thread::sleep_for(boost::chrono::milliseconds{ seconds });
}

void feedFromLeftCamera(int port, int width, int height, left_frame_queue holder) {
	cv::VideoCapture cam = cv::VideoCapture(port);
	cam.set(CV_CAP_PROP_FRAME_WIDTH, width);
	cam.set(CV_CAP_PROP_FRAME_HEIGHT, height);

	while (true) {
		if (cam.isOpened())
		{
			cv::Mat	frame;
			if (cam.read(frame)) {
				holder.pushLeft(frame);
			}
			wait(35);
		}
	}
}

void feedFromMiddleCamera(int port, int width, int height, middle_frame_queue holder) {
	cv::VideoCapture cam = cv::VideoCapture(port);
	cam.set(CV_CAP_PROP_FRAME_WIDTH, width);
	cam.set(CV_CAP_PROP_FRAME_HEIGHT, height);

	while (true) {
		if (cam.isOpened())
		{
			cv::Mat	frame;
			if (cam.read(frame)) {
				holder.pushMiddle(frame);
			}
			wait(35);
		}
	}
}

void feedFromRightCamera(int port, int width, int height, right_frame_queue holder) {
	cv::VideoCapture cam = cv::VideoCapture(port);
	cam.set(CV_CAP_PROP_FRAME_WIDTH, width);
	cam.set(CV_CAP_PROP_FRAME_HEIGHT, height);

	while (true) {
		if (cam.isOpened())
		{
			cv::Mat	frame;
			if (cam.read(frame)) {
				holder.pushRight(frame);
			}
			wait(35);
		}
	}
}

void feedToLeftDisplay(int width, int height, left_frame_queue holder, std::string windowName) {
	while (true) {
		cv::Mat frame;
		holder.left_wait_and_pop(frame);
		cv::imshow(windowName, frame);
		cv::waitKey(35);
	}
}

void feedToMiddleDisplay(int width, int height, middle_frame_queue holder, std::string windowName) {
	while (true) {
		cv::Mat frame;
		holder.middle_wait_and_pop(frame);
		cv::imshow(windowName, frame);
		cv::waitKey(35);
	}
}

void feedToRightDisplay(int width, int height, right_frame_queue holder, std::string windowName) {
	while (true) {
		cv::Mat frame;
		holder.right_wait_and_pop(frame);
		cv::imshow(windowName, frame);
		cv::waitKey(35);
	}
}

void feedToStitch(left_frame_queue leftQueue, middle_frame_queue middleQueue, right_frame_queue rightQueue, int width, int height, std::string windowName) {
	cv::Mat left, middle, right;
	stitcher stitcher1 = stitcher();

	leftQueue.left_wait_and_pop(left);
	middleQueue.middle_wait_and_pop(middle);
	rightQueue.right_wait_and_pop(right);

	stitcher1.calibrate(left, middle, right);

	while (true){
		cv::Mat left, middle, right, image;

		leftQueue.left_wait_and_pop(left);
		middleQueue.middle_wait_and_pop(middle);
		rightQueue.right_wait_and_pop(right);

		stitcher1.stitch(left, middle, right, image);
		cv::imshow(windowName, image);
		cv::waitKey(33);
	}
}

void PanViewerCore(int leftCamPort, int middleCamPort, int rightCamPort) {

	left_frame_queue leftQueue = left_frame_queue(20);
	middle_frame_queue middleQueue = middle_frame_queue(20);
	right_frame_queue rightQueue = right_frame_queue(20);

	boost::thread leftfeed{ feedFromLeftCamera, leftCamPort, 800, 600, leftQueue};
	boost::thread middlefeed{ feedFromMiddleCamera, middleCamPort, 800, 600, middleQueue };
	boost::thread rightfeed{ feedFromRightCamera, rightCamPort, 800, 600, rightQueue };

	boost::thread toLeftDisplay{ feedToLeftDisplay, 800, 600, leftQueue, "Left Display" };
	boost::thread toMiddleDisplay{ feedToMiddleDisplay, 800, 600, middleQueue, "Middle Display" };
	boost::thread toRightDisplay{ feedToRightDisplay, 800, 600, rightQueue, "Right Display" };

	boost::thread toStitcher{ feedToStitch, leftQueue, middleQueue, rightQueue, 2400, 600, "Stitched Display"};

	leftfeed.detach();
	middlefeed.detach();
	rightfeed.detach();
	toLeftDisplay.detach();
	toMiddleDisplay.detach();
	toRightDisplay.detach();
	toStitcher.detach();
}

void main() {
	settings setting = settings();

	int leftPort = setting.readINI_left();
	int middlePort = setting.readINI_middle();
	int rightPort = setting.readINI_right();

	char choice;
	char choiceExit;
	
	PanViewerCore(leftPort, middlePort, rightPort);

	std::cout << "Do you want to change the camera order ?(y/n): ";
	std::cin >> choice;

	if (choice == 'y' || choice == 'Y') {
		std::cout << "Enter new left port value: ";
		std::cin >> leftPort;

		std::cout << "Enter new middle port value: ";
		std::cin >> middlePort;

		std::cout << "Enter new right port value: ";
		std::cin >> rightPort;

		setting.writeINI(leftPort, middlePort, rightPort);
		PanViewerCore(leftPort, middlePort, rightPort);
		while (true) {} //keep the program running
	}
	if (choice == 'n' || choice == 'N') {
		std::cout << "Do you want to change the camera order ?(y/n): ";
		std::cin >> choiceExit;
		if (choice == 'y' || choice == 'Y') {
			//do nothing
		} 

		if (choice == 'n' || choice == 'N') {
			while (true){} //keep the program running
		}
	}
}