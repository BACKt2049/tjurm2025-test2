#include "impls.h"
#include <vector>
#include <iostream>
std::vector<cv::Mat> split(const cv::Mat& rgb_image)
{
    std::vector<cv::Mat> result(3, cv::Mat(rgb_image.size(), CV_8UC1));
    for (int y = 0; y < rgb_image.rows; ++y)
        {
        for (int x = 0; x < rgb_image.cols; ++x)
            {
            cv::Vec3b& pixel = rgb_image.at<cv::Vec3b>(y, x); 
            result[0].at<uchar>(y, x) = pixel[0]; 
            result[1].at<uchar>(y, x) = pixel[1]; 
            result[2].at<uchar>(y, x) = pixel[2];
        }
    }
    return result;
}
