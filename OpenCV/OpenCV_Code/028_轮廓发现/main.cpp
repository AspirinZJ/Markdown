#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat srcImg, dstImg;
const char *outWinName = "contours";
int threshold = 100;
const int thresholdMax = 255;
cv::RNG rng;
void contoursDemo(int, void *);

int main()
{
	srcImg = cv::imread("../test.png", cv::IMREAD_UNCHANGED);
	if (!srcImg.data)
	{
		std::cerr << "Error: cannot load image!\n";
		return -1;
	}
	cvNamedWindow("source image", CV_WINDOW_AUTOSIZE);
	cv::imshow("source image", srcImg);

	cv::cvtColor(srcImg, srcImg, cv::COLOR_BGR2GRAY);

	cv::namedWindow(outWinName, cv::WINDOW_AUTOSIZE);
	cv::createTrackbar("threshold", outWinName, &threshold, thresholdMax, contoursDemo);
	contoursDemo(0, nullptr);

	cv::waitKey(0);
	return 0;
}

void contoursDemo(int, void *)
{
	cv::Mat CannyOutImg;
	cv::Canny(srcImg, CannyOutImg, threshold, 2 * threshold, 3, false);
	std::vector<std::vector<cv::Point>> contourPoints;
	std::vector<cv::Vec4i> hierachy;

	cv::findContours(CannyOutImg, contourPoints, hierachy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

	dstImg = cv::Mat::zeros(srcImg.size(), CV_8UC3);
	for (size_t i = 0; i < contourPoints.size(); ++i)
	{
		cv::Scalar color(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		cv::drawContours(dstImg, contourPoints, i, color, 2, cv::LINE_AA, hierachy, 0, cv::Point(0, 0));
	}

	cv::imshow(outWinName, dstImg);
}
