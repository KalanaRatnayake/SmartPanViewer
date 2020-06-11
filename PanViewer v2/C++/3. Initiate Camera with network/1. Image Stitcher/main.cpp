#include <opencv2/opencv.hpp>
#include <iostream>
#include <thread>
#include <stdio.h>
#include <windows.h>

void viewCamera(std::string address, std::string windowName) {
	cv::VideoCapture cap;
	cap.set(CV_CAP_PROP_FRAME_WIDTH, 816);
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 612);
	cv::Mat frame;

	while (true)
	{
		if (!cap.open(address)) {
			std::cout << "Error opening video stream or file" << std::endl;
		}

		if (cap.read(frame)) {
			cv::imshow(windowName, frame);
			int c = cv::waitKey(40);

			if (c == char('q')) {
				break;
			}
		} else {
			std::cout << "No frame, " << address << std::endl;
		}
	}
	cap.release();
}

int main() {
	const std::string videoStreamAddress1 = "rtsp://admin:123456zxc@192.168.1.62:554/Streaming/Channels/101/";
	const std::string videoStreamAddress2 = "rtsp://admin:123456zxc@192.168.1.63:554/Streaming/Channels/101/";
	const std::string videoStreamAddress3 = "rtsp://admin:123456zxc@192.168.1.64:554/Streaming/Channels/101/";


	std::thread cam1(viewCamera, videoStreamAddress1, "Camera 1.jpg");
	Sleep(500);
	std::thread cam2(viewCamera, videoStreamAddress2, "Camera 2.jpg");
	Sleep(500);
	std::thread cam3(viewCamera, videoStreamAddress3, "Camera 3.jpg");
	Sleep(500);

	cam1.join();
	cam2.join();
	cam3.join();

	return 0;
}