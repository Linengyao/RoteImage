// RoteImage.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	cv::Mat dstMat;
	cv::Mat	srcMat = cv::imread("E:\\课程\\大二下\\数字图像处理\\lena.jpg", 1);
	int width = srcMat.cols;
	int height = srcMat.rows;
	if (srcMat.empty())	return -1;
	//旋转-10°
	float angle = -10.0;

	float scale = 1;

	//旋转中心为图像中心
	cv::Point2f center(srcMat.cols*0.5, srcMat.rows*0.5);


	//获得变换矩阵
	 cv::Mat	rot = cv::getRotationMatrix2D(center, angle, scale);
	 //获取外接四边形
	cv::Rect bbox = cv::RotatedRect(center, srcMat.size(), angle).boundingRect();
	//调整仿射矩阵参数
	rot.at<double>(0, 2) += bbox.width / 2.0 - center.x;
	rot.at<double>(1, 2) += bbox.height / 2.0 - center.y;

	cv::warpAffine(srcMat, dstMat, rot, bbox.size());

	cv::imshow("src", srcMat);
	cv::imshow("dst", dstMat);
	cv::waitKey(0);
    //std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
