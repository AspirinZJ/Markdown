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

	// 1. Gaussian模糊
	cv::GaussianBlur(srcImg, dstImg, cv::Size(3, 3), 0, 0);
	// 2. 转灰度图
	cv::Mat grayImg;
	cv::cvtColor(dstImg, grayImg, cv::COLOR_BGR2GRAY);
	// 3. 计算梯度
	cv::Mat gradX, gradY;
	// cv::Sobel(grayImg, gradX, CV_16S, 1, 0, 3, 1);
	cv::Scharr(grayImg, gradX, CV_16S, 1, 0, 3, 1);
	cv::convertScaleAbs(gradX, gradX); // 差分有负数情况，需要转换一下
	// cv::Sobel(grayImg, gradY, CV_16S, 0, 1, 3, 1);
	cv::Scharr(grayImg, gradY, CV_16S, 0, 1, 3, 1);
	cv::convertScaleAbs(gradY, gradY);
	cv::imshow("gradX", gradX);
	cv::imshow("gradY", gradY);

	// 4. 将梯度合成
	cv::Mat finalMat = cv::Mat(gradX.size(), gradX.type());
	cv::addWeighted(gradX, 0.5, gradY, 0.5, 0, finalMat);
	cv::imshow("final result", finalMat); // 加权相加

	for (int row = 0; row < gradX.rows; ++row)
	{
		for (int col = 0; col < gradX.cols; ++col)
		{
			finalMat.at<uchar>(row, col) = (int) (0.5 * (gradX.at<uchar>(row, col) + gradY.at<uchar>(row, col)));
		}
	}
	cv::imshow("my final result", finalMat); // 加权相加

	cv::waitKey(0);
	return 0;
}
