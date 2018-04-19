#include "middle_frame_queue.h"
#include "opencv.hpp"
#include "boost\thread.hpp"

std::queue<cv::Mat> middleFrames;
int middleQueueSize;
boost::mutex middleMutex;
boost::condition_variable middle_condition_variable;

middle_frame_queue::middle_frame_queue(int size) {
	middleQueueSize = size;
}

//will lock the mutex and output the front image. if the queue is empty, will wait while until a image
//appear and will keep the lock on conditional variable so that other functions also will wait
void middle_frame_queue::middle_wait_and_pop(cv::Mat& popped_frame) {
	boost::mutex::scoped_lock lock(middleMutex);
	while (middleFrames.empty()) {
		middle_condition_variable.wait(lock);
	}

	popped_frame = middleFrames.front();
	middleFrames.pop();
}

//will push matrices to the end of the queue while locking the mutex
void middle_frame_queue::pushMiddle(cv::Mat const& frame) {
	boost::mutex::scoped_lock lock(middleMutex);
	if (middleFrames.size() < middleQueueSize) {
		middleFrames.push(frame);
	}
	else {
		middleFrames.pop();
		middleFrames.push(frame);
	}
	lock.unlock();
	middle_condition_variable.notify_one();
}