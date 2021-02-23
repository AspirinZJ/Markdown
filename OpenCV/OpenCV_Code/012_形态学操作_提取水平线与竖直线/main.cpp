#include <iostream>
#include <opencv2/opencv.hpp>

// 转换为奇数
int toOdd(int num)
{ return num / 2 * 2 + 1; }

int main()
{
	cv::Mat srcImg = cv::imread("../test5.png", cv::IMREAD_UNCHANGED);
	if (!srcImg.data)
	{
		std::cerr << "Error: cannot load image!\n";
		return -1;
	}

	// 转换为灰度图像
	cv::Mat grayImg;
	cv::cvtColor(srcImg, grayImg, cv::COLOR_BGR2GRAY);
	cv::imshow("grayImg", grayImg);

	// 转换为二值图像
	cv::Mat binImg;
	cv::adaptiveThreshold(~grayImg, binImg, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 15, -2);
	cv::imshow("bin image", binImg);

	// 水平线结构体
	cv::Mat hline = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(toOdd(srcImg.cols / 16), 1));
	// 竖直线结构体
	cv::Mat vline = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(1, toOdd(srcImg.rows / 16)));

	// 获取水平线
	cv::Mat hlineImg;
	// 下面的操作直接使用开操作也可以
	cv::morphologyEx(binImg, hlineImg, CV_MOP_ERODE, hline); // 用水平线结构体腐蚀获得水平线
	cv::morphologyEx(hlineImg, hlineImg, CV_MOP_DILATE, hline); // 用水平线膨胀还原原始图像
	cv::bitwise_not(hlineImg, hlineImg); // 反色
	cv::blur(hlineImg, hlineImg, cv::Size(3, 3));
	cv::namedWindow("horizontal lines", cv::WINDOW_AUTOSIZE);
	cv::imshow("horizontal lines", hlineImg);

	// 获取竖直线
	cv::Mat vlineImg; cv::morphologyEx(binImg, vlineImg, CV_MOP_OPEN, vline); // 用竖直线结构体进行开操作获得竖直线
	cv::namedWindow("vertical lines", cv::WINDOW_AUTOSIZE);
	cv::imshow("vertical lines", vlineImg);

	// 去除文字后的干扰线
	cv::Mat fontImg = cv::imread("../test6.png");
	if (fontImg.empty())
	{
		std::cerr << "Error: cannot load image!\n";
		return -1;
	}
	cv::Mat dstImg;
	cv::cvtColor(fontImg, dstImg, cv::COLOR_BGR2GRAY);
	cv::adaptiveThreshold(~dstImg, dstImg, 255, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY, 21, -2);

	cv::Mat structure = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
	cv::morphologyEx(dstImg, dstImg, CV_MOP_OPEN, structure);
	cv::namedWindow("font without lines", cv::WINDOW_AUTOSIZE);
	cv::imshow("font without line", dstImg);


	cv::waitKey(0);
	return 0;
}
