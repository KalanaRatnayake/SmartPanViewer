#pragma once
#include "opencv2\opencv.hpp"

class gpuStitcher
{
public:
	gpuStitcher();

	void gpuCalibrate(cv::Mat& left, cv::Mat& middle, cv::Mat& right);

	void gpuStitch(cv::Mat& left, cv::Mat& middle, cv::Mat& right, cv::Mat& finalImage);
	
	~gpuStitcher();
};

