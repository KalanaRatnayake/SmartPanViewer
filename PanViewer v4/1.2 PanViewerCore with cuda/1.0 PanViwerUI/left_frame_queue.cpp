#include "left_frame_queue.h"
#include "opencv.hpp"
#include "boost\thread.hpp"

std::queue<cv::Mat> leftFrames;
int leftQueueSize;
boost::mutex leftMutex;
boost::condition_variable left_condition_variable;

left_frame_queue::left_frame_queue(int size) {
	leftQueueSize = size;
}

//will lock the mutex and output the front image. if the queue is empty, will wait while until a image
//appear and will keep the lock on conditional variable so that other functions also will wait
void left_frame_queue::left_wait_and_pop(cv::Mat& popped_frame) {
	boost::mutex::scoped_lock lock(leftMutex);
	while (leftFrames.empty()) {
		left_condition_variable.wait(lock);
	}

	popped_frame = leftFrames.front();
	leftFrames.pop();
}

//will push matrices to the end of the queue while locking the mutex
void left_frame_queue::pushLeft(cv::Mat const& frame) {
	boost::mutex::scoped_lock lock(leftMutex);
	if (leftFrames.size() < leftQueueSize) {
		leftFrames.push(frame);
	}
	else {
		leftFrames.pop();
		leftFrames.push(frame);
	}
	lock.unlock();
	left_condition_variable.notify_one();
}