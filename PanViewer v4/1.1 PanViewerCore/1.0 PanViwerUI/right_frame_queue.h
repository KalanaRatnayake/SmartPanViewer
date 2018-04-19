#pragma once

#include "opencv.hpp"

class right_frame_queue
{
public:
	right_frame_queue(int size);

	void right_wait_and_pop(cv::Mat& popped_frame);

	void pushRight(cv::Mat const& frame);

	int const rightSize();
};

