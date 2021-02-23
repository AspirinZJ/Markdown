#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat srcImg = cv::imread("../test.png", cv::IMREAD_UNCHANGED);
	if (!srcImg.data)
	{
		std::cerr << "Error: cannot load image!\n";
		return -1;
	}

	// 均值模糊blur
	cv::Mat dstImg;
	cv::blur(srcImg, dstImg, cv::Size(1, 50), cv::Point(-1, -1)); // （-1, -1）表示默认中心
	cv::namedWindow("blur", cv::WINDOW_AUTOSIZE);
	cv::imshow("blur", dstImg);


	// 高斯模糊GaussianBlur()
	cv::Mat dstImg2;
	cv::GaussianBlur(srcImg, dstImg2, cv::Size(5, 5), 10, 10); // 卷积核大小必须是奇数
	cv::namedWindow("GaussianBlur", cv::WINDOW_AUTOSIZE);
	cv::imshow("GaussianBlur", dstImg2);

	// 中值模糊medianBlur()， 能够很好地消除椒盐噪声
	cv::Mat dstImg3;
	cv::medianBlur(srcImg, dstImg3, 5);
	cv::namedWindow("medianBlur", cv::WINDOW_AUTOSIZE);
	cv::imshow("medianBlur", dstImg3);

	// 双边模糊bilateralFilter
	cv::Mat dstImg4;
	cv::bilateralFilter(srcImg, dstImg4, 5, 150.0, 3.0); // 保留了更多边缘的效果
	cv::namedWindow("bilateralFilter", cv::WINDOW_AUTOSIZE);
	cv::imshow("bilateralFilter", dstImg4);



	cv::waitKey(0);
	return 0;
}
