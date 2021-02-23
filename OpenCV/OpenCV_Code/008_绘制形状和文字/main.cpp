#include <iostream>
#include <ctime>
#include <opencv2/opencv.hpp>

// 不管传不传引用效果都是一样的
void drawLine(cv::Mat);
void drawRectangle(cv::Mat &);
void drawEllipse(cv::Mat);
void drawCircle(cv::Mat);
void callFillPoly(cv::Mat);
void drawText(cv::Mat);
void drawRandomLine(cv::Mat);

int main()
{
	cv::Mat srcImg = cv::imread("../test.png", cv::IMREAD_UNCHANGED);
	if (srcImg.empty())
	{
		std::cerr << "Error: cannot read image!" << std::endl;
		return -1;
	}

	cv::namedWindow("original image", cv::WINDOW_AUTOSIZE);
	cv::imshow("original image", srcImg);

	drawLine(srcImg);
	drawRectangle(srcImg);
	drawEllipse(srcImg);
	drawCircle(srcImg);
	callFillPoly(srcImg);
	drawText(srcImg);

	cv::Mat bg = cv::Mat::zeros(srcImg.size(), srcImg.type());
	drawRandomLine(bg);


	cv::waitKey(0);
	return 0;
}

// Point点，Scalar是bgr色彩， line画线
void drawLine(cv::Mat image)
{
	cv::Point point1(10, 20);
	cv::Point point2;
	point2.x = 300;
	point2.y = 100;
	cv::Scalar bgr = cv::Scalar(200, 0, 150);
	cv::line(image, point1, point2, bgr, 5, cv::LINE_8);
	cv::namedWindow("new image", cv::WINDOW_AUTOSIZE);
	cv::imshow("new image", image);
}

// rectangle画矩形
void drawRectangle(cv::Mat &image)
{
	cv::Rect rect(50, 50, 100, 120);
	cv::Scalar bgr(255, 0, 0);
	cv::rectangle(image, rect, bgr, 3, cv::LINE_AA); // 开启反锯齿
	cv::namedWindow("new image2", cv::WINDOW_AUTOSIZE);
	cv::imshow("new image2", image);
}

// ellipse画椭圆
void drawEllipse(cv::Mat image)
{
	cv::ellipse(image, cv::Point(image.cols / 2, image.rows / 2), cv::Size(image.cols / 4, image.rows / 4),
				60, 0, 300, cv::Scalar(255, 0, 120), 3, cv::LINE_8);
	cv::namedWindow("new image3", cv::WINDOW_AUTOSIZE);
	cv::imshow("new image3", image);
}

void drawCircle(cv::Mat image)
{
	cv::Scalar color = cv::Scalar(0, 212, 35);
	cv::Point center(image.cols / 2, image.rows / 2);
	cv::circle(image, center, 50, color, 2);
	cv::namedWindow("circle", cv::WINDOW_AUTOSIZE);
	cv::imshow("circle", image);
}

// 画多边形，注意格式
void callFillPoly(cv::Mat image)
{
	cv::Point ptArr[1][5];
	ptArr[0][0] = cv::Point(100, 100);
	ptArr[0][1] = cv::Point(100, 200);
	ptArr[0][2] = cv::Point(200, 200);
	ptArr[0][3] = cv::Point(200, 100);
	ptArr[0][4] = cv::Point(100, 100);

	const cv::Point *pPtArr[] = {ptArr[0]};
	int npt[] = {5};
	cv::Scalar color(223, 221, 44);
	cv::fillPoly(image, pPtArr, npt, 1, color);
	cv::namedWindow("polly", cv::WINDOW_AUTOSIZE);
	cv::imshow("polly", image);
}

void drawText(cv::Mat image)
{
	cv::putText(image, "Hello World!", cv::Point(200, 200), CV_FONT_HERSHEY_COMPLEX, 1.0, cv::Scalar(34, 111, 34), 2);
	cv::namedWindow("text", cv::WINDOW_AUTOSIZE);
	cv::imshow("text", image);
}

void drawRandomLine(cv::Mat image)
{
	cv::RNG rng((unsigned int) time(NULL));
	while (true)
	{
		cv::Point point1(rng.uniform(0, image.cols), rng.uniform(0, image.rows));
		cv::Point point2(rng.uniform(0, image.cols), rng.uniform(0, image.rows));
		cv::Scalar color(rng.uniform(0, 255), rng.uniform(0, 255));
		cv::line(image, point1, point2, color, 2);
		cv::namedWindow("random line", cv::WINDOW_AUTOSIZE);
		cv::imshow("random line", image);

		if (cv::waitKey(50) > 0) break;
	}
}
