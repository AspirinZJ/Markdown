#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat srcImg = cv::imread("../test.png", cv::IMREAD_UNCHANGED);
	if (srcImg.empty())
	{
		std::cerr << "Error: cannot load image!\n";
		return -1;
	}

	// cv::cvtColor(srcImg, srcImg, cv::COLOR_BGR2GRAY);

	char winName[] = "src image";
	cv::namedWindow(winName, CV_WINDOW_AUTOSIZE);
	cv::imshow(winName, srcImg);

	cv::Mat dstImg = cv::Mat::zeros(srcImg.size(), srcImg.type());

	float alpha = 0.5, beta = 30;
	for (int row = 0; row < srcImg.rows; ++row)
	{
		for (int col = 0; col < srcImg.cols; ++col)
		{
			if (srcImg.channels() == 3)
			{
				cv::Vec3b intensityF = srcImg.at<cv::Vec3b>(row, col); // 读取源图像像素
				uchar b = intensityF[0];
				uchar g = intensityF[1];
				uchar r = intensityF[2];
				// 为目标图像赋值
				dstImg.at<cv::Vec3b>(row, col) = cv::Vec3b(b * alpha + beta, g * alpha + beta, r * alpha + beta);
				//				dstImg.at<cv::Vec3b>(row, col)[0] = cv::saturate_cast<uchar>(alpha * b + beta);
				//				dstImg.at<cv::Vec3b>(row, col)[1] = cv::saturate_cast<uchar>(alpha * g + beta);
				//				dstImg.at<cv::Vec3b>(row, col)[2] = cv::saturate_cast<uchar>(alpha * r + beta);
			}
			else if (srcImg.channels() == 1)
			{
				dstImg.at<uchar>(row, col) = cv::saturate_cast<uchar>(alpha * srcImg.at<uchar>(row, col) + beta);
			}
		}
	}
	cv::namedWindow("dst image", CV_WINDOW_AUTOSIZE);
	cv::imshow("dst image", dstImg);


	cv::waitKey(0);
	return 0;
}
