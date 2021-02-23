#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat srcImg, dstImg;
const char *outWinName = "convex hull";
int threshold = 100;
const int thresholdMax = 255;
cv::RNG rng;

void thresholdCallBack(int, void *);

int main()
{
	srcImg = cv::imread("../coins.jpg", cv::IMREAD_UNCHANGED);
	if (srcImg.empty())
	{
		std::cerr << "Error: cannot load image!\n";
		return -1;
	}
	cv::namedWindow("input image", cv::WINDOW_AUTOSIZE);
	cv::imshow("input image", srcImg);

	cv::cvtColor(srcImg, srcImg, cv::COLOR_BGR2GRAY);
	cv::blur(srcImg, srcImg, cv::Size(3, 3), cv::Point(-1, -1));

	cv::namedWindow(outWinName, cv::WINDOW_AUTOSIZE);
	cv::createTrackbar("threshold trackbar", outWinName, &threshold, thresholdMax, thresholdCallBack);
	thresholdCallBack(0, nullptr);

	cv::waitKey(0);
	return 0;
}

void thresholdCallBack(int, void *)
{
	// 二值化
	cv::Mat binImg; // 二值图像
	cv::threshold(srcImg, binImg, threshold, thresholdMax, cv::THRESH_BINARY);

	std::vector<std::vector<cv::Point>> contourPoints;
	std::vector<cv::Vec4i> hierachy;
	cv::findContours(binImg, contourPoints, hierachy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

	// 定义凸包
	std::vector<std::vector<cv::Point>> convex(contourPoints.size());
	for (int i = 0; i < contourPoints.size(); ++i)
	{
		cv::convexHull(contourPoints[i], convex[i], false, true);
	}

	dstImg = cv::Mat::zeros(srcImg.size(), CV_8UC3);
	for (int k = 0; k < convex.size(); ++k)
	{
		cv::Scalar color(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		// cv::drawContours(dstImg, contourPoints, k, color, 2, 8, hierachy, 0, cv::Point(0, 0));
		cv::drawContours(dstImg, convex, k, color, 2, 8, hierachy, 0, cv::Point(0, 0));
	}

	cv::imshow(outWinName, dstImg);
}