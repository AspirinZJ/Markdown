#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat srcImg, dstImg;
cv::Mat mapX, mapY;

void updateMap(int);

int main()
{
	srcImg = cv::imread("../test.png");
	if (srcImg.empty())
	{
		std::cerr << "Error: cannot load image!\n";
		return -1;
	}
	cv::imshow("src image", srcImg);

	// 建立映射表
	mapX.create(srcImg.size(), CV_32FC1); // 32位单通道float
	mapY.create(srcImg.size(), CV_32FC1);

	int in;
	while (true)
	{
		in = cv::waitKey(0);
		if ('q' == in) { break; }

		updateMap(in);
		cv::remap(srcImg, dstImg, mapX, mapY, cv::INTER_LINEAR, cv::BORDER_CONSTANT, cv::Scalar(12, 123, 214));
		cv::imshow("output image", dstImg);
	}

	return 0;
}

void updateMap(int ind)
{
	for (int row = 0; row < srcImg.rows; ++row)
	{
		for (int col = 0; col < srcImg.cols; ++col)
		{
			switch (ind)
			{
				case 97: // 缩小一半
					if (col >= srcImg.cols * 0.25 && col < srcImg.cols * 0.75 && row >= srcImg.rows * 0.25 &&
						row < srcImg.rows * 0.75)
					{
						mapX.at<float>(row, col) = 2 * (col - srcImg.cols * 0.25);
						mapY.at<float>(row, col) = 2 * (row - srcImg.rows * 0.25);
					}
					else
					{
						mapX.at<float>(row, col) = 0;
						mapY.at<float>(row, col) = 0;
					}
					break;
				case 98: // 左右反转
					mapX.at<float>(row, col) = srcImg.cols - 1 - col;
					mapY.at<float>(row, col) = row;
					break;
				case 99: // 上下反转
					mapX.at<float>(row, col) = col;
					mapY.at<float>(row, col) = srcImg.rows - 1 - row;
					break;
				case 100: // 上下左右反转
					mapX.at<float>(row, col) = srcImg.cols - 1 - col;
					mapY.at<float>(row, col) = srcImg.rows - 1 - row;
					break;
				default:
					break;
			}
		}
	}
}