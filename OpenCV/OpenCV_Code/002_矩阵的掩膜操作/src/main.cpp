/*
 * 用	[0, -1, 0,
 * 		 -1, 5, -1,
 * 		 0, -1, 0]
 * 		 掩膜（kernel）提高图像的对比度
 * */
#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat srcImg;
	srcImg = cv::imread("../test.png");
	if (!srcImg.data)
	{
		printf("Error: cannot read image!\n");
		return -1;
	}
	CV_Assert(srcImg.depth() == CV_8U);
	cv::namedWindow("srcImage", CV_WINDOW_AUTOSIZE);
	cv::imshow("srcImage", srcImg);

	// 初始化目标图像
	cv::Mat dstImg = cv::Mat(srcImg.size(), srcImg.type());
	// srcImg.copyTo(dstImg); // 也可以不初始化目标图像而是拷贝源图像到目标图像

	long t1 = cv::getTickCount(); // OpenCV用于获取时间

	int channels = srcImg.channels(); // 图像通道数

	// 因为卷积核3x3, 做卷积时忽略最外面一圈，所以row和col都是从1开始
	for (int row = 1; row < srcImg.rows - 1; ++row)
	{
		// 源图像像素指针
		const uchar *pCurrent = srcImg.ptr<uchar>(row);
		const uchar *pPrevious = srcImg.ptr<uchar>(row - 1);
		auto *pNext = srcImg.ptr<uchar>(row + 1); // 也可以用auto指针
		// 目标图像像素指针
		auto *pDst = dstImg.ptr<uchar>(row);
		// uchar *pDst = dstImg.ptr<uchar>(row);

		for (int col = 1; col < (srcImg.cols - 1) * channels; ++col) // 注意有图像通道数，所以一行里面的总像素数是列数*像素数
		{
			// 进行掩膜（卷积）操作
			// cv::saturate_cast<uchar> 保证像素值在0~255之间
			pDst[col] = cv::saturate_cast<uchar>(
					5 * pCurrent[col] - (pCurrent[col - channels]
										 + pCurrent[col + channels] + pPrevious[col] + pNext[col]));
		}
	}

	long t2 = cv::getTickCount();
	std::cout << "Time consumption of my own method: " << t2 - t1 << std::endl;

	cv::namedWindow("dstImage", CV_WINDOW_AUTOSIZE);
	cv::imshow("dstImage", dstImg);

	cv::Mat dstImg2(srcImg.size(), srcImg.type());


	// 利用OpenCV提供的filter2D进行卷积操作
	t1 = cv::getTickCount();
	cv::Mat kernel = (cv::Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	cv::filter2D(srcImg, dstImg2, srcImg.depth(), kernel);
	// cv::filter2D(srcImg, dstImg2, -1, kernel); // -1表示深度推断
	t2 = cv::getTickCount();
	std::cout << "Time consumption of the OpenCV filter2D method: " << t2 - t1 << std::endl;

	cv::namedWindow("dstImage2", CV_WINDOW_AUTOSIZE);
	cv::imshow("dstImage2", dstImg2);
	cv::waitKey(0);

	return 0;
}
