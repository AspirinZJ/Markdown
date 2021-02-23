#include <iostream>
#include <opencv2/opencv.hpp>

#define ELEMENT_SIZE_MAX 20 // 结构元素最大值


cv::Mat srcImg, dstImg;
const char *outWinName = "output image";
int elementSize = 3; // 结构元素默认大小

void callBack(int, void *); // 回调函数


int main()
{
	srcImg = cv::imread("../test.png");
	if (srcImg.empty())
	{
		std::cerr << "Error: cannot load image!\n";
		return -1;
	}
	cv::namedWindow("input image", cv::WINDOW_AUTOSIZE);
	cv::imshow("input image", srcImg);

	cv::namedWindow(outWinName, cv::WINDOW_AUTOSIZE);
	cv::createTrackbar("Element size", outWinName, &elementSize, ELEMENT_SIZE_MAX, callBack);
	callBack(0, nullptr);

	cv::waitKey(0);
	return 0;
}

void callBack(int, void *)
{
	int s = elementSize * 2 + 1;
	// 获得结构元素
	cv::Mat structureElement = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(s, s), cv::Point(-1, -1));
	// 膨胀 dilate()
	// cv::dilate(srcImg, dstImg, structureElement, cv::Point(-1, -1), 1);
	// 腐蚀 erode()
	cv::erode(srcImg, dstImg, structureElement, cv::Point(-1, -1), 1);
	cv::imshow(outWinName, dstImg);
}

