#pragma once

#include "opencv2\opencv.hpp"

class stitched_frame_queue
{
public:
	stitched_frame_queue(int size);

	void stitched_wait_and_pop(cv::Mat& popped_frame);

	void pushstitched(cv::Mat const& frame);
};

