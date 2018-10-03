#include <opencv2/opencv.hpp>
#include <iostream>
#include <thread>
#include <stdio.h>
#include <windows.h>

void viewCamera(std::string address, std::string windowName) {
	cv::VideoCapture cap;
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
	const std::string videoStreamAddress1 = "http://ID:PASSWORD@IPADDRESS:PORTNO/mjpeg.cgi?user=ID&password=ID:PASSWORD&channel=0&.mjpg";
	const std::string videoStreamAddress2 = "http://ID:PASSWORD@IPADDRESS:PORTNO/mjpeg.cgi?user=ID&password=ID:PASSWORD&channel=0&.mjpg";
	const std::string videoStreamAddress3 = "http://ID:PASSWORD@IPADDRESS:PORTNO/mjpeg.cgi?user=ID&password=ID:PASSWORD&channel=0&.mjpg";


	std::thread cam1(viewCamera, videoStreamAddress1, "Camera 1");
	Sleep(500);
	std::thread cam2(viewCamera, videoStreamAddress2, "Camera 2");
	Sleep(500);
	std::thread cam3(viewCamera, videoStreamAddress3, "Camera 3");
	Sleep(500);

	cam1.join();
	cam2.join();
	cam3.join();

	return 0;
}