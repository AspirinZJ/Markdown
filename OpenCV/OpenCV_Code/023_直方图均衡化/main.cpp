#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat srcImg, grayImg, dstImg;
	srcImg = cv::imread("../test2.png", cv::IMREAD_UNCHANGED);
	if (srcImg.empty())
	{
		std::cerr << "Error: cannot load image!\n";
		return -1;
	}

	cv::cvtColor(srcImg, grayImg, cv::COLOR_BGR2GRAY);
	cv::namedWindow("gray image", cv::WINDOW_AUTOSIZE);
	cv::imshow("gray image", grayImg);
	// equalizeHist 输入必须是8位的单通道图像
	cv::equalizeHist(grayImg, dstImg);
	cv::namedWindow("output image", cv::WINDOW_AUTOSIZE);
	cv::imshow("output image", dstImg);

	cv::waitKey(0);
	return 0;
}
