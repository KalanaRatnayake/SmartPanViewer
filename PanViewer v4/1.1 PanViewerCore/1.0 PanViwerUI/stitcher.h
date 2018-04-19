#pragma once
#include "opencv2\opencv.hpp"

class stitcher
{
public:
	stitcher();

	void calibrate(cv::Mat& left, cv::Mat& middle, cv::Mat& right);
	
	void stitch(cv::Mat& left, cv::Mat& middle, cv::Mat& right, cv::Mat& finalImage);
	
	~stitcher();
};

