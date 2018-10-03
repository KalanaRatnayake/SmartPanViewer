#include "gpuStitcher.h"
#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2\cudaimgproc.hpp>

cv::Mat gpuHomographyLM;
cv::Mat gpuHomographyMR;

//==================================================== internal functions ======================================================

void _DetectAndDescribe(cv::Mat& image, std::vector<cv::KeyPoint>& OutputKeypoints, cv::Mat& OutputDescriptor) {
	//create the greyscale image
	cv::Mat grayImage;
	cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

	//create the keypoint detector and descriptor as "feature" using SIFT
	cv::Ptr<cv::Feature2D> feature = cv::xfeatures2d::SIFT::create();

	//create a matrix of keypoints using feature
	feature->detect(grayImage, OutputKeypoints);

	//create a matrix of descriptors using feature and keypoints
	feature->compute(grayImage, OutputKeypoints, OutputDescriptor);

	grayImage.release();
	feature.release();
}

void _matchKeypoints(cv::Mat& imageA, cv::Mat& imageB, std::vector<cv::KeyPoint>& keypointA, std::vector<cv::KeyPoint>& keypointB, cv::Mat& featuresA, cv::Mat& featuresB, float ratio, double repojThresh, std::vector<cv::DMatch>& OutputGoodMatches, cv::Mat& OutputHomographyM) {
	//create a vector of vector to hold raw matches
	std::vector<std::vector<cv::DMatch>> rawMatches;

	//create two vector points to hold the points where the lines will be drawn
	std::vector<cv::Point2f> pointsA;
	std::vector<cv::Point2f> pointsB;

	//Descriptor created under Burteforce method. Takes time but output is best
	cv::Ptr<cv::DescriptorMatcher> matcher = cv::DescriptorMatcher::create("BruteForce");
	matcher->knnMatch(featuresA, featuresB, rawMatches, 2);

	//matrix to hold the qualified matches
	OutputGoodMatches.reserve(rawMatches.size());

	//selecting good points by comparing distances
	for (size_t i = 0; i < rawMatches.size(); i++)
	{
		if (rawMatches[i][0].distance < (rawMatches[i][1].distance*ratio))
		{
			OutputGoodMatches.push_back(rawMatches[i][0]);

			//-- Get the keypoints from the good matches
			pointsA.push_back(keypointA[rawMatches[i][0].queryIdx].pt);
			pointsB.push_back(keypointB[rawMatches[i][0].trainIdx].pt);
		}
	}


	//if the number of good Matches is larger than 4, calculte homography using them
	if (OutputGoodMatches.size() > 4) {
		OutputHomographyM = findHomography(pointsA, pointsB, cv::RANSAC, repojThresh);
	}
	matcher.release();
}

void _getHomographyMatrix(cv::Mat& imageA, cv::Mat& imageB, float ratio, double repojThresh, cv::Mat& outHomographyM) {
	std::vector<cv::KeyPoint> keypointA;
	std::vector<cv::KeyPoint> keypointB;
	cv::Mat featuresA;
	cv::Mat featuresB;
	std::vector<cv::DMatch> matches;

	_DetectAndDescribe(imageA, keypointA, featuresA);
	_DetectAndDescribe(imageB, keypointB, featuresB);

	_matchKeypoints(imageA, imageB, keypointA, keypointB, featuresA, featuresB, ratio, repojThresh, matches, outHomographyM);

	featuresA.release();
	featuresB.release();
}

void gpuStitchFrames(cv::cuda::GpuMat& imageA, cv::cuda::GpuMat& imageB, cv::Mat& inputHomography, cv::cuda::GpuMat& finalImage) {
	cv::cuda::GpuMat result;
	int hA = imageA.size().height;
	int wA = imageA.size().width;
	int hB = imageB.size().height;
	int wB = imageB.size().width;

	//warp the image 
	cv::cuda::warpPerspective(imageA, result, inputHomography, cv::Size(wA + wB, hA));

	finalImage = cv::cuda::GpuMat(cv::Size(imageA.cols + imageB.cols, imageB.rows), CV_8UC3);

	cv::cuda::GpuMat roi1(finalImage, cv::Rect(0, 0, imageB.cols, imageB.rows));
	cv::cuda::GpuMat roi2(finalImage, cv::Rect(0, 0, result.cols, imageB.rows));
	result.copyTo(roi2);
	imageB.copyTo(roi1);

	result.release();
	roi1.release();
	roi2.release();
}

void _stitchFrames(cv::Mat& imageA, cv::Mat& imageB, cv::Mat& inputHomography, cv::Mat& finalImage) {
	cv::Mat result;
	int hA = imageA.size().height;
	int wA = imageA.size().width;
	int hB = imageB.size().height;
	int wB = imageB.size().width;

	//warp the image 
	cv::warpPerspective(imageA, result, inputHomography, cv::Size(wA + wB, hA));

	finalImage = cv::Mat(cv::Size(imageA.cols + imageB.cols, imageB.rows), CV_8UC3);

	cv::Mat roi1(finalImage, cv::Rect(0, 0, imageB.cols, imageB.rows));
	cv::Mat roi2(finalImage, cv::Rect(0, 0, result.cols, imageB.rows));
	result.copyTo(roi2);
	imageB.copyTo(roi1);

	result.release();
	roi1.release();
	roi2.release();
}

//=============================================== functions visible to outside =================================================

gpuStitcher::gpuStitcher()
{
}

void gpuStitcher::gpuCalibrate(cv::Mat& left, cv::Mat& middle, cv::Mat& right) {
	cv::Mat transL, transM, transResult, result;

	cv::flip(left, transL, 1);
	cv::flip(middle, transM, 1);
	_getHomographyMatrix(transL, transM, 0.75, 4.0, gpuHomographyLM);

	_stitchFrames(transL, transM, gpuHomographyLM, transResult);
	cv::flip(transResult, result, 1);
	_getHomographyMatrix(right, result, 0.75, 4.0, gpuHomographyMR);
}

void gpuStitcher::gpuStitch(cv::Mat& left, cv::Mat& middle, cv::Mat& right, cv::Mat& finalImage) {
	cv::cuda::GpuMat Gleft, Gmiddle, Gright, GtransL, GtransM, GtransResult, Gresult, GfinalImage;

	//upload frames to gpu for processsing
	Gleft.upload(left);
	Gmiddle.upload(middle);
	Gright.upload(right);

	cv::cuda::flip(Gleft, GtransL, 1);
	cv::cuda::flip(Gmiddle, GtransM, 1);

	gpuStitchFrames(GtransL, GtransM, gpuHomographyLM, GtransResult);

	cv::cuda::flip(GtransResult, Gresult, 1);
	gpuStitchFrames(Gright, Gresult, gpuHomographyMR, GfinalImage);

	GfinalImage.download(finalImage);
}

gpuStitcher::~gpuStitcher()
{
}