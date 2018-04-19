#include "opencv.hpp"
#include "boost\thread.hpp"

class frame_queue
{
public:
	frame_queue(int size);

	void wait_and_pop(cv::Mat& popped_value);

	void push(cv::Mat const& data);

	int const size();
};
