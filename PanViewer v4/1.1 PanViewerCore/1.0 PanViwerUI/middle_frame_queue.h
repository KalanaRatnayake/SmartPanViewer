#pragma once
#include "opencv.hpp"

class middle_frame_queue
{
public:
	middle_frame_queue(int size);

	void middle_wait_and_pop(cv::Mat& popped_frame);

	void pushMiddle(cv::Mat const& frame);

	int const middleSize();
};
