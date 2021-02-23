#include <iostream>
#include <opencv2/opencv.hpp>

#define BACKPROP_WINNAME "back projection image"

cv::Mat handImg1, handImg2, hsvImg, hueImg;
int numBins = 12;
void histCallBack(int, void *);

int main()
{
	handImg1 = cv::imread("../hand1.png", cv::IMREAD_UNCHANGED);
	handImg2 = cv::imread("../hand2.png", cv::IMREAD_UNCHANGED);
	if (handImg1.empty() || handImg2.empty())
	{
		std::cerr << "Error: cannot load image!\n";
		return -1;
	}
	cv::namedWindow("original image", cv::WINDOW_AUTOSIZE);
	cv::namedWindow(BACKPROP_WINNAME, cv::WINDOW_AUTOSIZE);
	cv::imshow("original image", handImg1);

	cv::cvtColor(handImg1, hsvImg, cv::COLOR_BGR2HSV);    // 转换到HSV色彩空间
	hueImg.create(hsvImg.size(), hsvImg.depth()); // 单通道 depth->type
	int nChannels[] = {0, 0};
	cv::mixChannels(&hsvImg, 1, &hueImg, 1, nChannels, 1);

	cv::createTrackbar("histogram bins", BACKPROP_WINNAME, &numBins, 180, histCallBack);
	histCallBack(0, nullptr);

	cv::waitKey(0);
	return 0;
}

void histCallBack(int, void *)
{
	float range[] = {0, 180};
	const float *histRanges = {range};
	cv::Mat hueHist;
	// 获取直方图
	cv::calcHist(&hueImg, 1, 0, cv::Mat(), hueHist, 1, &numBins, &histRanges, true, false);
	// 归一化
	cv::normalize(hueHist, hueHist, 0.0, 255.0, cv::NORM_MINMAX);

	cv::Mat backProjectionImg;
	// 反向投影
	cv::calcBackProject(&hueImg, 1, 0, hueHist, backProjectionImg, &histRanges);
	cv::imshow(BACKPROP_WINNAME, backProjectionImg);

	int histHeight = 400, histWidth = 400;
	int binWidth = histWidth / numBins;
	cv::Mat histImg(histHeight, histWidth, CV_8UC3, cv::Scalar(127, 127, 127));

	for (int i = 0; i < numBins - 1; ++i)
	{
		cv::rectangle(histImg, cv::Point(i * binWidth, histHeight - hueHist.at<float>(i) * (400 / 255)),
					  cv::Point((i + 1) * binWidth, histHeight), cv::Scalar(0, 255, 255), -1);
	}

	cv::imshow("Histogram", histImg);
}
