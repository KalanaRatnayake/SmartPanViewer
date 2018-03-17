#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <iostream>
#include <ctime>

using namespace std;
using namespace cv;

void DetectAndDescribe(Mat& image, vector<KeyPoint>& OutputKeypoints, Mat& OutputDescriptor) {
	//create the greyscale image
	Mat grayImage;
	cvtColor(image, grayImage, COLOR_BGR2GRAY);

	//create the keypoint detector and descriptor as "feature" using SIFT
	Ptr<Feature2D> feature = xfeatures2d::SIFT::create();

	//create a matrix of keypoints using feature
	feature->detect(grayImage, OutputKeypoints);

	//create a maatrix of descriptors using feature and keypoints
	feature->compute(grayImage, OutputKeypoints, OutputDescriptor);
}

void matchKeypoints(Mat& imageA, Mat& imageB, vector<KeyPoint>& keypointA, vector<KeyPoint>& keypointB, Mat& featuresA, Mat& featuresB, float ratio, double repojThresh, vector<DMatch>& OutputGoodMatches, Mat& OutputHomographyM) {
	//create a vector of vector to hold raw matches
	vector<vector<DMatch>> rawMatches;

	//create two vector points to hold the points where the lines will be drawn
	vector<Point2f> pointsA;
	vector<Point2f> pointsB;

	//Descriptor created under Burteforce method. Takes time but output is best
	Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("BruteForce");
	matcher->knnMatch(featuresA, featuresB, rawMatches, 2);

	//matrix to hold the qualified matches
	OutputGoodMatches.reserve(rawMatches.size());

	//selecting good points by comparing distances
	for (size_t i = 0; i < rawMatches.size(); i++)
	{
		if (rawMatches[i][0].distance < (rawMatches[i][1].distance*ratio))
		{
			OutputGoodMatches.push_back(rawMatches[i][0]);
		}
	}


	for (int i = 0; i < OutputGoodMatches.size(); i++)
	{
		//-- Get the keypoints from the good matches
		pointsA.push_back(keypointA[OutputGoodMatches[i].queryIdx].pt);
		pointsB.push_back(keypointB[OutputGoodMatches[i].trainIdx].pt);
	}

	//if the number of good Matches is larger than 4, calculte homography using them
	if (OutputGoodMatches.size() > 4) {
		OutputHomographyM = findHomography(pointsA, pointsB, RANSAC, repojThresh);
	}
}

void getHomographyMatrix(Mat& imageA, Mat& imageB, float ratio, double repojThresh, Mat& outHomographyM) {
	vector<KeyPoint> keypointA;
	vector<KeyPoint> keypointB;
	Mat featuresA;
	Mat featuresB;
	vector<DMatch> matches;

	DetectAndDescribe(imageA, keypointA, featuresA);
	DetectAndDescribe(imageB, keypointB, featuresB);

	matchKeypoints(imageA, imageB, keypointA, keypointB, featuresA, featuresB, ratio, repojThresh, matches, outHomographyM);
}


void stitch(Mat& imageA, Mat& imageB, Mat& inputHomography, Mat& finalImage) {
	Mat result;
	int hA = imageA.size().height;
	int wA = imageA.size().width;
	int hB = imageB.size().height;
	int wB = imageB.size().width;

	//warp the image 
	warpPerspective(imageA, result, inputHomography, Size(wA + wB, hA));

	finalImage = Mat(Size(imageA.cols+imageB.cols, imageB.rows), CV_8UC3);

	Mat roi1(finalImage, Rect(0, 0, imageB.cols, imageB.rows));
	Mat roi2(finalImage, Rect(0, 0, result.cols, imageB.rows));
	result.copyTo(roi2);
	imageB.copyTo(roi1);

}

void equalizeImage(Mat& InputImage, Mat& OutputImage) {
	Mat imgYUV;
	Mat imgBGR;
	vector<Mat> channels;
	vector<Mat> channelsBGR;
	vector<Mat> combined;
	Mat Y, U, V;

	cvtColor(InputImage, imgYUV, COLOR_BGR2YUV);

	//split images into channels
	split(imgYUV, channels);

	//equalize the histogram of the Y cahnnel because intensity is given by the y channel
	equalizeHist(channels[0], channels[0]);

	//merge intestified channels back into the YUV image
	merge(channels, imgYUV);

	//convert YVU image back into BGR
	cvtColor(imgYUV, imgBGR, COLOR_YUV2BGR);

	//split images into channels
	split(imgBGR, channelsBGR);

	//equalize the histogram of the Y cahnnel because intensity is given by the y channel
	equalizeHist(channelsBGR[0], channelsBGR[0]);
	equalizeHist(channelsBGR[1], channelsBGR[1]);
	equalizeHist(channelsBGR[2], channelsBGR[2]);

	merge(channelsBGR, OutputImage);
}


int main() {

	int start_s = clock();

	VideoCapture CapL;
	VideoCapture CapM;
	VideoCapture CapR;
	Mat frameL;
	Mat frameM;
	Mat frameR;
	Mat transL;
	Mat transM;
	Mat transResult;
	Mat homographyLM;
	Mat homographyR_LM;
	Mat result;
	Mat finalImage;
	Mat visiblelines;


	CapL = VideoCapture(0);
	CapL.set(CV_CAP_PROP_FRAME_WIDTH, 800);
	CapL.set(CV_CAP_PROP_FRAME_HEIGHT, 600);

	CapM = VideoCapture(1);
	CapM.set(CV_CAP_PROP_FRAME_WIDTH, 800);
	CapM.set(CV_CAP_PROP_FRAME_HEIGHT, 600);

	CapR = VideoCapture(2);
	CapR.set(CV_CAP_PROP_FRAME_WIDTH, 800);
	CapR.set(CV_CAP_PROP_FRAME_HEIGHT, 600);

	//take initial images to caliberate
	if (CapL.read(frameL)) {
	}
	if (CapM.read(frameM)) {
	}
	if (CapR.read(frameR)) {
	}

	flip(frameL, transL, 1);
	flip(frameM, transM, 1);
	getHomographyMatrix(transL, transM, 0.75, 4.0, homographyLM);

	stitch(transL, transM, homographyLM, transResult);
	flip(transResult, result, 1);
	getHomographyMatrix(frameR, result, 0.75, 4.0, homographyR_LM);

	int stop_s = clock();
	cout << "time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << endl;

	while (true){
		CapL.read(frameL);
		CapM.read(frameM);
		CapR.read(frameR);

		equalizeImage(frameL, frameL);
		equalizeImage(frameM, frameM);
		equalizeImage(frameR, frameR);

		flip(frameL, transL, 1);
		flip(frameM, transM, 1);
		stitch(transL, transM, homographyLM, transResult);

		flip(transResult, result, 1);
		stitch(frameR, result, homographyR_LM, finalImage);


		if (true){
			namedWindow("Video Feed", WINDOW_NORMAL);
			resizeWindow("Video Feed", 1366, 340);
			imshow("Video Feed", finalImage);
			if (waitKey(30) && 0xFF == char('q')) {
				break;
			}
		}
		else {
			break;
		}
	}

	waitKey(0);
	destroyAllWindows();
	CapL.release();
	CapM.release();
	CapR.release();
}