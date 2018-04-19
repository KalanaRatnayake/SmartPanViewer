#include "right_frame_queue.h"
#include "opencv.hpp"
#include "boost\thread.hpp"

std::queue<cv::Mat> rightFrames;
int rightQueueSize;
boost::mutex rightMutex;
boost::condition_variable right_condition_variable;

right_frame_queue::right_frame_queue(int size) {
	rightQueueSize = size;
}

//will lock the mutex and output the front image. if the queue is empty, will wait while until a image
//appear and will keep the lock on conditional variable so that other functions also will wait
void right_frame_queue::right_wait_and_pop(cv::Mat& popped_frame) {
	boost::mutex::scoped_lock lock(rightMutex);
	while (rightFrames.empty()) {
		right_condition_variable.wait(lock);
	}

	popped_frame = rightFrames.front();
	rightFrames.pop();
}

//will push matrices to the end of the queue while locking the mutex
void right_frame_queue::pushRight(cv::Mat const& frame) {
	boost::mutex::scoped_lock lock(rightMutex);
	if (rightFrames.size() < rightQueueSize) {
		rightFrames.push(frame);
	}
	else {
		rightFrames.pop();
		rightFrames.push(frame);
	}
	lock.unlock();
	right_condition_variable.notify_one();
}

int const right_frame_queue::rightSize() {
	boost::mutex::scoped_lock lock(rightMutex);
	return rightFrames.size();
}