#include <iostream>
#include <opencv2/opencv.hpp>

#define INPUT_NAME "original image"
#define OUTPUT_NAME "result image"
#define MATCH_T    "template match demo"

void templateMatchDemo(int, void *);
int matchMethod = CV_TM_SQDIFF;
const int matchMethodMax = 5;

cv::Mat srcImg, templateImg, dstImg;

int main()
{
	srcImg = cv::imread("../source.png", cv::IMREAD_UNCHANGED);
	templateImg = cv::imread("../template.png", cv::IMREAD_UNCHANGED);
	if (srcImg.empty() || templateImg.empty())
	{
		std::cerr << "Error: cannot load image!\n";
		return -1;
	}
	cv::namedWindow(INPUT_NAME, cv::WINDOW_AUTOSIZE);
	cv::namedWindow(OUTPUT_NAME, cv::WINDOW_AUTOSIZE);
	cv::namedWindow(MATCH_T, cv::WINDOW_AUTOSIZE);
	cv::imshow(INPUT_NAME, srcImg);
	const char *trackBarTitle = "Match Algorithm Methods";

	cv::createTrackbar(trackBarTitle, OUTPUT_NAME, &matchMethod, matchMethodMax, templateMatchDemo);
	templateMatchDemo(0, nullptr);

	cv::waitKey(0);
	return 0;
}

void templateMatchDemo(int, void *)
{
	int width = srcImg.cols - templateImg.cols + 1;
	int height = srcImg.rows - templateImg.rows + 1;
	cv::Mat result(height, width, CV_32FC1);
	// 模板匹配
	cv::matchTemplate(srcImg, templateImg, result, matchMethod);
	// 归一化
	cv::normalize(result, result, 0, 1, cv::NORM_MINMAX);

	// 找出匹配的最小值和最大值位置
	cv::Point minLoc, maxLoc;
	double minVal, maxVal;
	cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);

	// 绘制出最大最小值位置
	cv::Point temLoc;
	temLoc = (matchMethod == CV_TM_SQDIFF || matchMethod == CV_TM_SQDIFF_NORMED) ? minLoc : maxLoc;

	srcImg.copyTo(dstImg);
	cv::rectangle(dstImg, cv::Rect(temLoc.x, temLoc.y, templateImg.cols, templateImg.rows),
			   cv::Scalar(0, 255, 255), 2, cv::LINE_AA);
	cv::rectangle(result, cv::Rect(temLoc.x, temLoc.y, templateImg.cols, templateImg.rows),
				  cv::Scalar(0, 255, 255), 2, cv::LINE_AA);

	cv::imshow(OUTPUT_NAME, dstImg);
	cv::imshow(MATCH_T, result);
}