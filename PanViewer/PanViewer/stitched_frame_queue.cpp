#include "stitched_frame_queue.h"
#include "opencv.hpp"
#include "boost\thread.hpp"

std::queue<cv::Mat> stitchedFrames;
int stitchedQueueSize;
boost::mutex stitchedMutex;
boost::condition_variable stitched_condition_variable;


stitched_frame_queue::stitched_frame_queue(int size){
	stitchedQueueSize = size;
}

/*
*will lock the mutex and output the front image. if the queue is empty, will wait while until a image
*appear and will keep the lock on conditional variable so that other functions also will wait
*/

void stitched_frame_queue::stitched_wait_and_pop(cv::Mat& popped_frame) {
	boost::mutex::scoped_lock lock(stitchedMutex);
	while (stitchedFrames.empty()) {
		stitched_condition_variable.wait(lock);
	}

	popped_frame = stitchedFrames.front();
	stitchedFrames.pop();
}

//will push matrices to the end of the queue while locking the mutex
void stitched_frame_queue::pushstitched(cv::Mat const& frame) {
	boost::mutex::scoped_lock lock(stitchedMutex);
	if (stitchedFrames.size() < stitchedQueueSize) {
		stitchedFrames.push(frame);
	}
	else {
		stitchedFrames.pop();
		stitchedFrames.push(frame);
	}
	lock.unlock();
	stitched_condition_variable.notify_one();
}