#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

int main()
{
	cv::Mat srcImg, edgeImg, dstImg;
	srcImg = cv::imread("../building.jpg");
	if (srcImg.empty())
	{
		std::cerr << "Error: cannot load image!\n";
		return -1;
	}
	cv::namedWindow("src image", cv::WINDOW_AUTOSIZE);
	cv::imshow("src image", srcImg);

	// extract edge
	cv::Canny(srcImg, edgeImg, 100, 200);
	cv::imshow("edge image", edgeImg);

	std::vector<cv::Vec4f> pLines;
	cv::cvtColor(edgeImg, dstImg, cv::COLOR_GRAY2BGR);
	cv::HoughLinesP(edgeImg, pLines, 1, CV_PI / 180.0, 10, 0, 10);
	cv::Scalar color(0, 0, 255);

	for (size_t i = 0; i < pLines.size(); ++i)
	{
		cv::Vec4f hLine = pLines[i];
		cv::line(dstImg, cv::Point(hLine[0], hLine[1]), cv::Point(hLine[2], hLine[3]), color, 1, cv::LINE_AA);
	}

	cv::imshow("hough lines", dstImg);

	cv::waitKey(0);

	return 0;
}
