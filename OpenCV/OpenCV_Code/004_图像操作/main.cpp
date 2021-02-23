#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat srcImg = cv::imread("../test.png", cv::IMREAD_UNCHANGED);
	if (srcImg.empty())
	{
		std::cerr << "Error: cannot open source image!\n";
		return -1;
	}

	cv::Mat grayImg;
	cv::cvtColor(srcImg, grayImg, cv::COLOR_BGR2GRAY);

	// 访问像素, 单通道
	for (int row = 0; row < grayImg.rows; ++row)
	{
		for (int col = 0; col < grayImg.cols; ++col)
		{
			uchar grayVal = grayImg.at<uchar>(row, col); // 读取像素处灰度值
			grayImg.at<uchar>(row, col) = 255 - grayVal; // 反色
		}
	}

	cv::namedWindow("gray image", CV_WINDOW_AUTOSIZE);
	cv::imshow("gray image", grayImg);

	// 访问像素， 三通道
	cv::Mat dstImg;
	dstImg.create(srcImg.size(), srcImg.type());
	for (int row = 0; row < dstImg.rows; ++row)
	{
		for (int col = 0; col < dstImg.cols; ++col)
		{
			if (dstImg.channels() == 1)
			{
				uchar grayVal = dstImg.at<uchar>(row, col);
				dstImg.at<uchar>(row, col) = 255 - grayVal;
			}
			else if (dstImg.channels() == 3)
			{
				// 获取三通到的像素值信息
				// typedef Vec<uchar, 3> Vec3b; Vec3b的定义
				cv::Vec3b intensity = srcImg.at<cv::Vec3b>(row, col);
				uchar b = intensity[0];
				//				uchar g = intensity[1];
				//				uchar r = intensity[2];
				dstImg.at<cv::Vec3b>(row, col)[0] = b; // 只保留源图像的蓝色通道
				dstImg.at<cv::Vec3b>(row, col)[1] = 0;
				dstImg.at<cv::Vec3b>(row, col)[2] = 0;
			}
		}
	}
	cv::namedWindow("dst image", CV_WINDOW_AUTOSIZE);
	cv::imshow("dst image", dstImg);

	cv::waitKey(0);
	return 0;
}
