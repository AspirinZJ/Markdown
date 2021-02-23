#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat srcImg;
	srcImg = cv::imread("../test.png", cv::IMREAD_UNCHANGED);
	if (!srcImg.data)
	{
		std::cerr << "Error: cannot load image!\n";\
        return -1;
	}
	cv::namedWindow("src image", cv::WINDOW_AUTOSIZE);
	cv::imshow("src image", srcImg);

	// 分通道显示
	std::vector<cv::Mat> bgrPlanesMat;
	cv::split(srcImg, bgrPlanesMat);
	cv::imshow("b", bgrPlanesMat[0]);
	cv::imshow("g", bgrPlanesMat[1]);
	cv::imshow("r", bgrPlanesMat[2]);

	cv::Mat bHist, gHist, rHist;
	int histSize = 256;
	float range[] = {0, 256};
	const float *histRanges = {range};
	cv::calcHist(&bgrPlanesMat[0], 1, nullptr, cv::Mat(), bHist, 1, &histSize, &histRanges, true, false);
	cv::calcHist(&bgrPlanesMat[1], 1, nullptr, cv::Mat(), gHist, 1, &histSize, &histRanges, true, false);
	cv::calcHist(&bgrPlanesMat[2], 1, nullptr, cv::Mat(), rHist, 1, &histSize, &histRanges, true, false);

	int histHeight = 400;
	int histWidth = 512;
	int binWidth = histWidth / histSize;

	cv::Mat histImage(histWidth, histHeight, CV_8UC3, cv::Scalar(127, 127, 127));
	// 归一化
	cv::normalize(bHist, bHist, 0, histHeight, cv::NORM_MINMAX, -1);
	cv::normalize(gHist, gHist, 0, histHeight, cv::NORM_MINMAX, -1);
	cv::normalize(rHist, rHist, 0, histHeight, cv::NORM_MINMAX, -1);

	// 绘制直方图
	for (int i = 1; i < histSize; ++i)
	{
		cv::line(histImage, cv::Point((i - 1) * binWidth, histHeight - cvRound(bHist.at<float>(i - 1))),
				 cv::Point(i * binWidth, histHeight - cvRound(bHist.at<float>(i))), cv::Scalar(255, 0, 0), 2,
				 cv::LINE_AA);
		cv::line(histImage, cv::Point((i - 1) * binWidth, histHeight - cvRound(gHist.at<float>(i - 1))),
				 cv::Point(i * binWidth, histHeight - cvRound(gHist.at<float>(i))), cv::Scalar(0, 255, 0), 2,
				 cv::LINE_AA);
		cv::line(histImage, cv::Point((i - 1) * binWidth, histHeight - cvRound(rHist.at<float>(i - 1))),
				 cv::Point(i * binWidth, histHeight - cvRound(rHist.at<float>(i))), cv::Scalar(0, 0, 255), 2,
				 cv::LINE_AA);
	}

	cv::imshow("histgram", histImage);

	cv::waitKey(0);
	return 0;
}
