#include <vector>
#include <algorithm>
#include "impls.h"
std::vector<cv::Mat> threshold(const cv::Mat& src, int threshold_value) 
{
    cv::Mat gray(src.size(), CV_8UC1); 
    cv::Mat dst(src.size(), CV_8UC1);  
    for (int y = 0; y < src.rows; ++y)
        {for (int x = 0; x < src.cols; ++x)
            {cv::Vec3b color = src.at<cv::Vec3b>(y, x);
            uchar grayValue = static_cast<uchar>(0.299 * color[2] + 0.587 * color[1] + 0.114 * color[0]);
            gray.at<uchar>(y, x) = grayValue; }
        }
    for (int y = 0; y < src.rows; ++y)
        {
        for (int x = 0; x < src.cols; ++x) 
        {
            uchar grayValue = gray.at<uchar>(y, x);
            dst.at<uchar>(y, x) = (grayValue > threshold_value) ? 255 : 0;
        }
    }
    return {gray, dst};
}
