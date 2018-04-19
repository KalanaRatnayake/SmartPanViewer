#pragma once
#include "opencv2\opencv.hpp"

class cameraController
{
public:
	cameraController(int port, int WindowWidth, int WindowHeight);

	bool feedFrame(cv::Mat& frame);

	~cameraController();
};

