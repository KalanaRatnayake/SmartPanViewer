#pragma once
#include "opencv2\opencv.hpp"

class displayController
{
public:
	displayController(int width, int height);

	void showFrame(cv::Mat frame);

	~displayController();
};

