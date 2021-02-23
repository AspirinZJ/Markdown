#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	// 读取图像
	cv::Mat srcImage = cv::imread("../test.png", cv::IMREAD_UNCHANGED);

	if (srcImage.empty())
	{
		printf("Error: cannot read image!\n");
		return -1;
	}

	// 显示图像
	cv::namedWindow("srcImage", CV_WINDOW_AUTOSIZE);
	cv::imshow("srcImage", srcImage);

	cv::namedWindow("After converting", CV_WINDOW_AUTOSIZE);
	// 转换图像色彩空间
	cv::Mat outImage;
	cv::cvtColor(srcImage, outImage, CV_BGR2HLS); // CV_BGR2HLS, CV_BGR2GRAY...
	cv::imshow("After converting", outImage);
	cv::waitKey(0);

	// 保存图像
	cv::imwrite("../saveImage.tiff", outImage);

	return 0;
}
