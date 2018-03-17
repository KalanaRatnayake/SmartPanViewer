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
	cv::cvtColor(image, grayImage, COLOR_BGR2GRAY);
	
	//create the keypoint detector and descriptor as "feature" using SIFT
	Ptr<Feature2D> feature = xfeatures2d::SIFT::create();

	//create a matrix of keypoints using feature
	feature->detect(grayImage, OutputKeypoints);

	//create a maatrix of descriptors using feature and keypoints
	feature->compute(grayImage, OutputKeypoints, OutputDescriptor);
}

void matchKeypoints(Mat& imageA, Mat& imageB, vector<KeyPoint>& keypointA, vector<KeyPoint>& keypointB, Mat& featuresA, Mat& featuresB, float ratio, double repojThresh, vector<DMatch>& OutputGoodMatches, Mat& OutputHomographyM){
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

void stitch(Mat& imageA, Mat& imageB, float ratio, double repojThresh, bool showMatches, Mat& finalImage, Mat& visiblelines) {
	vector<KeyPoint> keypointA;
	vector<KeyPoint> keypointB;
	Mat featuresA;
	Mat featuresB;
	Mat matchFeatures;
	vector<DMatch> matches;
	Mat result;
	Mat homographyM;

	int hA = imageA.size().height;
	int wA = imageA.size().width;
	int hB = imageB.size().height;
	int wB = imageB.size().width;

	DetectAndDescribe(imageA, keypointA, featuresA);
	DetectAndDescribe(imageB, keypointB, featuresB);
	cout << "keypoint and descriptors are done..." << endl;

	matchKeypoints(imageA, imageB, keypointA, keypointB, featuresA, featuresB, ratio, repojThresh, matches, homographyM);
	cout << "Matches and homography is done..." << endl;

	//warp the image 
	cv::warpPerspective(imageA, result, homographyM, Size(wA+wB, hA));
	cout << "warping done..." << endl;

	finalImage = Mat(Size(imageB.cols + imageA.cols, imageB.rows), CV_8UC3);

	Mat roi1(finalImage, Rect(0, 0, imageB.cols, imageB.rows));
	Mat roi2(finalImage, Rect(0, 0, result.cols, imageB.rows));
	result.copyTo(roi2);
	imageB.copyTo(roi1);

	if (showMatches) {
		drawMatches(imageA, keypointA, imageB, keypointB, matches, visiblelines);
		cout << "drawing matches done..." << endl << endl;
	}

	cout << "========================================= Stitching complete ===========================================" << endl;
}

int main() {

	int start_s = clock();

	Mat result;
	Mat visiblelines;
	Mat imageL = cv::imread("left.jpg");
	Mat imageR = cv::imread("right.jpg");


	if (imageL.empty()) std::cerr << "Could not open image A file" << std::endl;
	if (imageR.empty()) std::cerr << "Could not open image B file" << std::endl;

	stitch(imageR, imageL, 0.75, 4.0, true, result, visiblelines);

	if (result.empty()) std::cerr << "Could not load result" << std::endl;
	if (visiblelines.empty()) std::cerr << "Could not load visiblelines" << std::endl;

	//Uncomment when you need to check drawn matches
	//cv::imshow("Visible Lines", visiblelines);
	//namedWindow("Visible Lines", WINDOW_FULLSCREEN);


	namedWindow("Final Image", WINDOW_FULLSCREEN);
	cv::imshow("Final Image", result);

	cv::imwrite("Result.jpg", result);

	int stop_s = clock();
	cout << "time: " << (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000 << endl;

	cv::waitKey(0);
	cv::destroyAllWindows();
}