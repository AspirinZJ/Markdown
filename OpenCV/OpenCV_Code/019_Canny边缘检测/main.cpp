#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat srcImg, grayImg, blurImg, edgeImg, dstImg;
int t1 = 50;
const int t1Max = 255;
const char *outName = "out image";

void setT1Value(int, void *);

int main()
{
	srcImg = cv::imread("../test.png", cv::IMREAD_UNCHANGED);
	if (srcImg.empty())
	{
		std::cerr << "Error: cannot load image!\n";
		return -1;
	}
	cv::namedWindow(outName, cv::WINDOW_AUTOSIZE);
	cv::cvtColor(srcImg, grayImg, cv::COLOR_BGR2GRAY);
	cv::blur(grayImg, blurImg, cv::Size(3, 3));

	cv::createTrackbar("t1 value", outName, &t1, t1Max, setT1Value);
	setT1Value(0, nullptr);

	cv::waitKey(0);
	return 0;
}

void setT1Value(int, void *)
{
	cv::Canny(blurImg, edgeImg, t1, t1 * 2, 3);
	dstImg.create(edgeImg.size(), edgeImg.type());
	srcImg.copyTo(dstImg, edgeImg); // copyTo(output, mask)
	cv::imshow(outName, dstImg);
}
