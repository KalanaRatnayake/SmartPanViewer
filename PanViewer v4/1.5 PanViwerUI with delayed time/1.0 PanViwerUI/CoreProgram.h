#ifndef COREPROGRAM
#define COREPROGRAM

#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2\cudaimgproc.hpp>
#include <iostream>
#include <ctime>

using namespace std;
using namespace cv;
using namespace cuda;
using namespace System;
using namespace System ::Threading;

void DetectAndDescribe(Mat& image, vector<KeyPoint>& OutputKeypoints, Mat& OutputDescriptor);

void matchKeypoints(Mat& imageA, Mat& imageB, vector<KeyPoint>& keypointA, vector<KeyPoint>& keypointB, Mat& featuresA, Mat& featuresB, float ratio, double repojThresh, vector<DMatch>& OutputGoodMatches, Mat& OutputHomographyM); 

void getHomographyMatrix(Mat& imageA, Mat& imageB, float ratio, double repojThresh, Mat& outHomographyM); 

void gpuStitch(GpuMat& imageA, GpuMat& imageB, Mat& inputHomography, GpuMat& finalImage); 

void stitch(Mat& imageA, Mat& imageB, Mat& inputHomography, Mat& finalImage); 

//CUDA used for high performance
void gpuEqualizeImage(GpuMat& InputImage, GpuMat& OutputImage);

#endif

