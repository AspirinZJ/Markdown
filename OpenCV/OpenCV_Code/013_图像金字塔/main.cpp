#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat srcImg;
	srcImg = cv::imread("../cat.png");
	if (srcImg.empty())
	{
		std::cerr << "Error: cannot load image!\n";
		return -1;
	}
	cv::namedWindow("src image", cv::WINDOW_AUTOSIZE);
	cv::imshow("src image", srcImg);

	// 上采样
	cv::Mat upImg;
	cv::pyrUp(srcImg, upImg, cv::Size(srcImg.cols * 2, srcImg.rows * 2));
	cv::imshow("up image", upImg);

	// 降采样
	cv::Mat downImg;
	cv::pyrDown(srcImg, downImg, cv::Size(srcImg.cols / 2, srcImg.rows / 2));
	cv::imshow("down image", downImg);

	// 高斯不同 DoG
	cv::Mat grayImg, gaussianImg1, gaussianImg2, dogImg;
	cv::cvtColor(srcImg, grayImg, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(grayImg, gaussianImg1, cv::Size(5, 5), 0, 0);
	cv::GaussianBlur(gaussianImg1, gaussianImg2, cv::Size(5, 5), 0, 0);
	cv::subtract(gaussianImg1, gaussianImg2, dogImg); // 两个高斯模糊相减
	cv::normalize(dogImg, dogImg, 255, 0, cv::NORM_MINMAX); // 归一化
	cv::imshow("DOG", dogImg);



	cv::waitKey(0);
	return 0;
}
