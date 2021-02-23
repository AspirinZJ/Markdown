#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat srcImg, dstImg;
	srcImg = cv::imread("../test.png");
	if (srcImg.empty())
	{
		std::cerr << "Error: cannot load image!\n";
		return -1;
	}
	cv::imshow("src image", srcImg);

	// 1. Gaussian Blur
	cv::GaussianBlur(srcImg, srcImg, cv::Size(3, 3), 0, 0);
	// 2. 转为灰度
	cv::cvtColor(srcImg, srcImg, cv::COLOR_BGR2GRAY);
	// 3. Laplacian
	cv::Mat edgeImg;
	cv::Laplacian(srcImg, edgeImg, CV_16S, 3, 1);
	// 4. convertScaleAbs
	cv::convertScaleAbs(edgeImg, edgeImg);

	// cv::threshold(edgeImg, edgeImg, 0, 255, cv::THRESH_OTSU | cv::THRESH_BINARY);
	cv::imshow("edge image", edgeImg);


	cv::waitKey(0);
	return 0;
}
