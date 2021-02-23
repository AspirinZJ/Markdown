#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat srcImg, dstImg;
	srcImg = cv::imread("../cat.png");
	if (srcImg.empty())
	{
		std::cerr << "Error: cannot load image!\n";
		return -1;
	}
	cv::imshow("src image", srcImg);

	// Robert算子
	cv::Mat robertKer = (cv::Mat_<int>(2, 2) << 1, 0, 0, -1);
	cv::filter2D(srcImg, dstImg, -1, robertKer);
	cv::imshow("robert x directoion", dstImg);

	cv::Mat robertKer2 = (cv::Mat_<int>(2, 2) << 0, 1, -1, 0);
	cv::filter2D(srcImg, dstImg, -1, robertKer2);
	cv::imshow("robert y directoion", dstImg);

	// Sobel算子
	cv::Mat sobelKer = (cv::Mat_<int>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
	cv::filter2D(srcImg, dstImg, -1, sobelKer);
	cv::imshow("sobel x direction", dstImg);

	cv::Mat sobelKer2 = (cv::Mat_<int>(3, 3) << -1, -2, -1, 0, 0, 0, 1, 2, 1);
	cv::filter2D(srcImg, dstImg, -1, sobelKer2);
	cv::imshow("sobel y direction", dstImg);

	// Laplace算子
	cv::Mat laplaceKer = (cv::Mat_<int>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);
	cv::filter2D(srcImg, dstImg, 0, laplaceKer, cv::Point(-1, -1), 127);
	cv::imshow("laplace", dstImg);

	cv::waitKey(0);
	return 0;
}
