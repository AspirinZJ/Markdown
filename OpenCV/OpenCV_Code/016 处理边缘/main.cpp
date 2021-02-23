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

	int top = (int) (0.05 * srcImg.rows);
	int bottom = (int) (0.05 * srcImg.rows);
	int left = (int) (0.05 * srcImg.cols);
	int right = (int) (0.05 * srcImg.cols);
	int borderType;
	cv::RNG rng((unsigned int) time(nullptr));

	char ch;
	while (true)
	{
		ch = cv::waitKey(0);
		if ('q' == ch) { break; }
		else if ('r' == ch) { borderType = cv::BORDER_REPLICATE; }
		else if ('w' == ch) { borderType = cv::BORDER_WRAP; }
		else if ('c' == ch) { borderType = cv::BORDER_CONSTANT; }
		else { borderType = cv::BORDER_DEFAULT; }
		cv::Scalar color(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		cv::copyMakeBorder(srcImg, dstImg, top, bottom, left, right, borderType, color);
		cv::imshow("dst image", dstImg);
	}

	// Gaussian模糊等算法时可以指定边缘类型
	cv::GaussianBlur(srcImg, dstImg, cv::Size(5, 5), 0, 0, cv::BORDER_CONSTANT);
	cv::imshow("dst image", dstImg);
	cv::waitKey(0);


	return 0;
}
