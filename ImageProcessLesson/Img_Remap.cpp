#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include "Function1.h"

int Remap()
{
	cv::Mat srcImage = cv::imread("D:/VisualStudioLearn/ImageProcessLesson/ImageProcessLesson/img.jpg");
	if (!srcImage.data)
		return -1;
	cv::Mat resultImage(srcImage.size(), srcImage.type());

	cv::Mat xMapImage(srcImage.size(), CV_32FC1);
	cv::Mat yMapImage(srcImage.size(), CV_32FC1);
	//图像的宽高
	int rows = srcImage.rows;
	int cols = srcImage.cols;
	//图像遍历
	for (int j = 0; j < rows; j++)
	{
		for (int i = 0; i < cols; i++)
		{
			//计算新的坐标
			xMapImage.at<float>(j, i) = cols - i;
			yMapImage.at<float>(j, i) = rows - j;
		}
		//进行重映射
	}
	remap(srcImage, resultImage, xMapImage, yMapImage, cv::INTER_LINEAR);
	cv::imshow("srcImage", srcImage);
	cv::imshow("resultImage", resultImage);
	cv::waitKey(0);
	return 0;
}