#include "frame_queue.h"
#include "opencv.hpp"
#include "boost\thread.hpp"

std::queue<cv::Mat> frames;
int queueSize;
boost::mutex mutex;
boost::condition_variable condition_variable;

frame_queue::frame_queue(int size) {
	queueSize = size;
}

//will lock the mutex and output the front image. if the queue is empty, will wait while until a image
//appear and will keep the lock on conditional variable so that other functions also will wait
void frame_queue::wait_and_pop(cv::Mat& popped_frame){
	boost::mutex::scoped_lock lock(mutex);
	while (frames.empty()){
		condition_variable.wait(lock);
	}

	popped_frame = frames.front();
	frames.pop();
}

//will push matrices to the end of the queue while locking the mutex
void frame_queue::push(cv::Mat const& frame){
	boost::mutex::scoped_lock lock(mutex);
	if (frames.size() < queueSize) {
		frames.push(frame);
	} else {
		frames.pop();
		frames.push(frame);
	}
	lock.unlock();
	condition_variable.notify_one();
}

int const frame_queue::size() {
	boost::mutex::scoped_lock lock(mutex);
	return frames.size();
}