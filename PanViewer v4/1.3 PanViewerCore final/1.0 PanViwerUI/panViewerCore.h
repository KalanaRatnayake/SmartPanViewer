#pragma once
#include "opencv2\opencv.hpp"

class panViewerCore
{
public:
	panViewerCore();

	panViewerCore(int left, int middle, int right, int width, int height);

	cv::Mat leftCameraImage();

	cv::Mat middleCameraImage();

	cv::Mat rightCameraImage();

	cv::Mat stitchedImage();

	~panViewerCore();
};

