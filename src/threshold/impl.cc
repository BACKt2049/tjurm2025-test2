#include "impls.h"
std::vector<cv::Mat> threshold(const cv::Mat& src, int threshold_value)
{
    cv::Mat gray, dst;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);
    cv::threshold(gray, dst, threshold_value, 255, cv::THRESH_BINARY);
    return {gray, dst};
}
