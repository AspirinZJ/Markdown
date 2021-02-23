#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat srcImg = cv::imread("../test.png", cv::IMREAD_UNCHANGED);
	if (srcImg.empty())
	{
		std::cout << "Error: cannot open source image!" << std::endl;
		return -1;
	}
	cv::namedWindow("src image", CV_WINDOW_AUTOSIZE);
	cv::imshow("src image", srcImg);

	// 创建Mat对象
	cv::Mat dstImg = cv::Mat(srcImg.size(), srcImg.type());
	dstImg = cv::Scalar(127, 0, 255);
	cv::namedWindow("dst image", CV_WINDOW_AUTOSIZE);
	cv::imshow("dst image", dstImg);

	cv::Mat dstImg2 = srcImg.clone(); // Mat图像的完全拷贝
	cv::namedWindow("dst image2", CV_WINDOW_AUTOSIZE);
	cv::imshow("dst image2", dstImg2);

	// copyTo()方法
	cv::Mat dstImg3;
	srcImg.copyTo(dstImg3);
	cv::namedWindow("dst image3", CV_WINDOW_AUTOSIZE);
	cv::imshow("dst image3", dstImg3);


	// 创建Mat对象
	cv::Mat mat(3, 3, CV_8UC3, cv::Scalar(0, 0, 255)); // 纯红色
	std::cout << "mat: " << std::endl << mat << std::endl;


	// Mat::create创建Mat对象
	cv::Mat mat2;
	mat2.create(srcImg.size(), srcImg.type());
	mat2 = cv::Scalar(0, 255, 0);
	cv::namedWindow("mat2", CV_WINDOW_AUTOSIZE);
	cv::imshow("mat2", mat2);

	// 定义小数组
	cv::Mat kernel = (cv::Mat_<uchar>(2, 2) << 1, 0, 0, 1);
	std::cout << "kernel: " << std::endl << kernel << std::endl;

	// 初始化为0的Mat对象
	cv::Mat mat3 = cv::Mat::zeros(cv::Size(2, 2), CV_8UC3);
	std::cout << "mat3: " << std::endl << mat3 << std::endl;

	// 对角矩阵
	mat3 = cv::Mat::eye(2, 2, CV_8UC4);
	std::cout << "mat3: " << std::endl << mat3 << std::endl;

	// cvtColor()方法
	cv::cvtColor(dstImg3, dstImg3, cv::COLOR_BGR2GRAY);
	cv::namedWindow("dst image3_2", CV_WINDOW_AUTOSIZE);
	cv::imshow("dst image3_2", dstImg3);

	//channels()方法获取通道数
	std::cout << "src image channels: " << dstImg3.channels() << std::endl;

	// cols, rows是行和列
	std::cout << "src image cols: " << srcImg.cols << ". rows: " << srcImg.rows << std::endl;

	// 获取像素指针, ptr<uchar>
	const uchar *pPixel = dstImg3.ptr<uchar>(0);
	std::cout << "The gray value of the [0, 0] pixel: " << (int) pPixel[0] << std::endl;


	cv::waitKey(0);


	return 0;
}
