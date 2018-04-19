#include "displayController.h"
#include "opencv2\opencv.hpp"

int windowWidth;
int windowHeight;

//constructor will take widdth and height as inputs and create the controller
displayController::displayController(int width, int height) {
	windowWidth = width;
	windowHeight = height;
}

//showFrame will take the matrix of image and show it in a window
void displayController::showFrame(cv::Mat frame) {
	
}

displayController::~displayController()
{
}
