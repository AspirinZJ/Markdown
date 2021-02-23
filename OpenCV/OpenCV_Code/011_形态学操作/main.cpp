#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat srcImg = cv::imread("../test4.png", cv::IMREAD_UNCHANGED);
	if (srcImg.empty())
	{
		std::cerr << "Error: cannot load image!\n";
		return -1;
	}
	cv::namedWindow("src image", cv::WINDOW_AUTOSIZE);
	cv::imshow("src image", srcImg);

	cv::namedWindow("output image", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("output image2", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("output image3", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("output image4", cv::WINDOW_AUTOSIZE);
	cv::Mat dstImg;

	// 获取结构元素
	cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(11, 11), cv::Point(-1, -1));

	// 形态学开操作, CV_MOP_OPEN
	cv::morphologyEx(srcImg, dstImg, CV_MOP_OPEN, kernel, cv::Point(-1, -1));
	cv::imshow("output image", dstImg);

	// 形态学闭操作 CV_MOP_CLOSE
	cv::morphologyEx(srcImg, dstImg, CV_MOP_CLOSE, kernel, cv::Point(-1, -1));
	cv::imshow("output image2", dstImg);

	// 形态学梯度, CV_MOP_GRADIENT
	cv::Mat kernel2 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3), cv::Point(-1, -1));
	cv::morphologyEx(srcImg, dstImg, CV_MOP_GRADIENT, kernel2, cv::Point(-1, -1));
	cv::imshow("output image3", dstImg);

	// 顶帽 top hat
	cv::morphologyEx(srcImg, dstImg, CV_MOP_TOPHAT, kernel);
	cv::imshow("output image4", dstImg);

	// 黑帽 black hat
	cv::morphologyEx(srcImg, dstImg, CV_MOP_BLACKHAT, kernel);
	cv::imshow("output image5", dstImg);


	cv::waitKey(0);
	return 0;
}
