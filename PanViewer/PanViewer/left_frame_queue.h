#pragma once
#include "opencv.hpp"

class left_frame_queue
{
public:
	left_frame_queue(int size);

	void left_wait_and_pop(cv::Mat& popped_frame);

	void pushLeft(cv::Mat const& frame);
};

