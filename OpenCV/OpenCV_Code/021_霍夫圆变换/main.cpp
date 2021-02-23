#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat srcImg, dstImg;
	srcImg = cv::imread("../coins.jpg");
	if (!srcImg.data)
	{
		std::cerr << "Error: cannot load image!\n";
		return -1;
	}
	cv::imshow("src image", srcImg);

	// 1. 一定要做中值滤波，霍夫圆检测对噪点敏感
	cv::medianBlur(srcImg, dstImg, 3);
	cv::cvtColor(dstImg, dstImg, cv::COLOR_BGR2GRAY);

	// 2. 霍夫圆检测
	std::vector<cv::Vec3f> pCircles;
	cv::HoughCircles(dstImg, pCircles, CV_HOUGH_GRADIENT, 1, 30, 100, 30, 10, 50);
	for (auto circle : pCircles)
	{
		cv::circle(srcImg, cv::Point(circle[0], circle[1]), circle[2], cv::Scalar(0, 0, 255), 2, cv::LINE_AA);
		cv::circle(srcImg, cv::Point(circle[0], circle[1]), 2, cv::Scalar(242, 13, 111), 2);
	}

	cv::imshow("circles", srcImg);


	cv::waitKey(0);
	return 0;
}
