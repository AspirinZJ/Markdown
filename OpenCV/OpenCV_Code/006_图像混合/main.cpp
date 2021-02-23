#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat srcImg1, srcImg2, dstImg;
	srcImg1 = cv::imread("../test.png");
	if (!srcImg1.data)
	{
		std::cerr << "Error: cannot load source image 1!\n";
		return -1;
	}
	srcImg2 = cv::imread("../test2.png");
	if (!srcImg2.data)
	{
		std::cerr << "Error: cannot load source image 2!\n";
		return -1;
	}

	CV_Assert(srcImg1.size() == srcImg2.size());

	// addWeighted()线性混合相加
	cv::addWeighted(srcImg1, 0.5, srcImg2, 0.5, 0.0, dstImg);

	cv::namedWindow("dst image", CV_WINDOW_AUTOSIZE);
	cv::imshow("dst image", dstImg);

	// 直接add()
	cv::add(srcImg1, srcImg2, dstImg, cv::Mat());
	cv::namedWindow("directly add", CV_WINDOW_AUTOSIZE);
	cv::imshow("directly add", dstImg);

	// 相乘multiply()
	cv::multiply(srcImg1, srcImg2, dstImg, 0.02);
	cv::namedWindow("multiply", CV_WINDOW_AUTOSIZE);
	cv::imshow("multiply", dstImg);

	cv::waitKey(0);
	return 0;
}
