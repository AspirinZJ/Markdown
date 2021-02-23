#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat srcImg, grayImg, dstImg;
int threshold = 127; // 255/2
const int thresholdMax = 255;
int thresholdType = 0;
const int thresholdTypeMax = 4;
/*
enum ThresholdTypes {
	THRESH_BINARY     = 0, //!< \f[\texttt{dst} (x,y) =  \fork{\texttt{maxval}}{if \(\texttt{src}(x,y) > \texttt{thresh}\)}{0}{otherwise}\f]
	THRESH_BINARY_INV = 1, //!< \f[\texttt{dst} (x,y) =  \fork{0}{if \(\texttt{src}(x,y) > \texttt{thresh}\)}{\texttt{maxval}}{otherwise}\f]
	THRESH_TRUNC      = 2, //!< \f[\texttt{dst} (x,y) =  \fork{\texttt{threshold}}{if \(\texttt{src}(x,y) > \texttt{thresh}\)}{\texttt{src}(x,y)}{otherwise}\f]
	THRESH_TOZERO     = 3, //!< \f[\texttt{dst} (x,y) =  \fork{\texttt{src}(x,y)}{if \(\texttt{src}(x,y) > \texttt{thresh}\)}{0}{otherwise}\f]
	THRESH_TOZERO_INV = 4, //!< \f[\texttt{dst} (x,y) =  \fork{0}{if \(\texttt{src}(x,y) > \texttt{thresh}\)}{\texttt{src}(x,y)}{otherwise}\f]
	THRESH_MASK       = 7,
	THRESH_OTSU       = 8, //!< flag, use Otsu algorithm to choose the optimal threshold value
	THRESH_TRIANGLE   = 16 //!< flag, use Triangle algorithm to choose the optimal threshold value
};
*/

void changeThreshold(int, void *);

int main()
{
	srcImg = cv::imread("../cat.png");
	if (srcImg.empty())
	{
		std::cerr << "Error: cannot load image!\n";
		return -1;
	}
	cv::imshow("src image", srcImg);
	cv::cvtColor(srcImg, grayImg, cv::COLOR_BGR2GRAY);

	cv::namedWindow("output image", cv::WINDOW_AUTOSIZE);

	cv::createTrackbar("threshold trackbar", "output image", &threshold, thresholdMax, changeThreshold);
	cv::createTrackbar("threshold type trackbar", "output image", &thresholdType, thresholdTypeMax, changeThreshold);
	changeThreshold(0, nullptr);

	// 自动获取阈值
	cv::Mat dstImg2;
	cv::threshold(grayImg, dstImg2, 0, 255, cv::THRESH_OTSU | cv::THRESH_BINARY);
	cv::imshow("optimium threshold", dstImg2);


	cv::waitKey(0);
	return 0;
}

void changeThreshold(int, void *)
{
	cv::threshold(grayImg, dstImg, threshold, thresholdMax, thresholdType);
	cv::imshow("output image", dstImg);
}