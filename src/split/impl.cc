#include "impls.h"
#include <vector>
#include <iostream>

// 假设我们的图像是BGR格式的
std::vector<cv::Mat> split(const cv::Mat& rgb_image) {
    std::vector<cv::Mat> result(3, cv::Mat(rgb_image.size(), CV_8UC1)); // 初始化三个通道的图像

    // 遍历图像的每个像素
    for (int y = 0; y < rgb_image.rows; ++y) {
        for (int x = 0; x < rgb_image.cols; ++x) {
            cv::Vec3b& pixel = rgb_image.at<cv::Vec3b>(y, x); // 获取BGR格式的像素值
            // 提取BGR通道并分别赋值给对应的通道图像
            result[0].at<uchar>(y, x) = pixel[0]; // 蓝色通道
            result[1].at<uchar>(y, x) = pixel[1]; // 绿色通道
            result[2].at<uchar>(y, x) = pixel[2]; // 红色通道
        }
    }

    return result;
}
