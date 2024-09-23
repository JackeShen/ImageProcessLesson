#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include "Function1.h"

int Img_Extraction2()
{
	//��ȡͼ��Դ
	cv::Mat srcImage = cv::imread("D:/VisualStudioLearn/ImageProcessLesson/ImageProcessLesson/img.jpg");
	if (srcImage.empty())
	{
		std::cout << "��ȡͼ��ʧ�ܣ�" << std::endl;
		return -1;
	}
	//ת�Ҷ�ͼ
	cv::Mat srcGray;
	cv::cvtColor(srcImage, srcGray, cv::COLOR_BGR2GRAY);
	cv::imshow("scrGray",srcGray);
	
	//��ֵƽ��
	cv::Mat blurDstImage;
	blur(srcGray, blurDstImage, cv::Size(3, 3),cv::Point(-1,-1));
	cv::imshow("blurDstImage", blurDstImage);
	//д��ͼ��
	cv::imwrite("D:/VisualStudioLearn/ImageProcessLesson/ImageProcessLesson/img_blur.jpg", blurDstImage);
	cv::waitKey(0);

	return 0;
	
}