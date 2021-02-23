#include <iostream>
#include <opencv2/opencv.hpp>

std::string doubleToString(double d);

int main()
{
	cv::Mat img1 = cv::imread("../test.png", cv::IMREAD_UNCHANGED);
	cv::Mat img2 = cv::imread("../test2.png", cv::IMREAD_UNCHANGED);
	cv::Mat img3 = cv::imread("../test3.png", cv::IMREAD_UNCHANGED);

	if (img1.empty() || img2.empty() || img3.empty())
	{
		std::cerr << "Error: cannot load images!\n";
		return -1;
	}

	// 转换到HSV色彩空间，因为HSV对于光线，颜色等变化更加敏感
	cv::cvtColor(img1, img1, cv::COLOR_BGR2HSV);
	cv::cvtColor(img2, img2, cv::COLOR_BGR2HSV);
	cv::cvtColor(img3, img3, cv::COLOR_BGR2HSV);

	// 操作H和S通道
	const int hBins = 50;
	const int sBins = 60;
	int histSize[] = {hBins, sBins};

	// Hue varies from 0 to 179, saturation varies from 0 to 255
	const float hRanges[] = {0, 180};
	const float sRanges[] = {0, 255};
	const float *ranges[] = {hRanges, sRanges};

	// use the 0-th and 1-st channels
	int channels[] = {0, 1};

	cv::MatND hist1, hist2, hist3; // MatND表示多维矩阵

	// 计算直方图，归一化
	cv::calcHist(&img1, 1, channels, cv::Mat(), hist1, 2, histSize, ranges, true, false);
	cv::normalize(hist1, hist1, 0, 1, cv::NORM_MINMAX);
	cv::calcHist(&img2, 1, channels, cv::Mat(), hist2, 2, histSize, ranges, true, false);
	cv::normalize(hist2, hist2, 0, 1, cv::NORM_MINMAX);
	cv::calcHist(&img3, 1, channels, cv::Mat(), hist3, 2, histSize, ranges, true, false);
	cv::normalize(hist3, hist3, 0, 1, cv::NORM_MINMAX);

	// 比较直方图
	double result11 = cv::compareHist(hist1, hist1, CV_COMP_CORREL);
	double result12 = cv::compareHist(hist1, hist2, CV_COMP_CORREL);
	double result13 = cv::compareHist(hist1, hist3, CV_COMP_CORREL);
	double result23 = cv::compareHist(hist2, hist3, CV_COMP_CORREL);
	std::cout << "result11: " << result11 << ". result12: " << result12 << ". result13: " << result13 << ". result23: "
			  << result23 << std::endl;

	cv::putText(img1, doubleToString(result11), cv::Point(50, 50), CV_FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 0, 255));
	cv::putText(img2, doubleToString(result12), cv::Point(50, 50), CV_FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 0, 255));
	cv::putText(img3, doubleToString(result13), cv::Point(50, 50), CV_FONT_HERSHEY_COMPLEX, 1, cv::Scalar(255, 0, 255));

	cv::namedWindow("image 1", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("image 2", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("image 3", cv::WINDOW_AUTOSIZE);
	cv::imshow("image 1", img1);
	cv::imshow("image 2", img2);
	cv::imshow("image 3", img3);


	cv::waitKey(0);
	return 0;
}

std::string doubleToString(double d)
{
	std::ostringstream oss;
	if (oss << d) { return oss.str(); }
	return "invalid conversion";
}