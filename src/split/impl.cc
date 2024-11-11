#include "impls.h"
std::vector<cv::Mat> split(const cv::Mat& rgb_image)
{
    std::vector<cv::Mat> result;
    cv::split(rgb_image, result); 
    return result;
}
