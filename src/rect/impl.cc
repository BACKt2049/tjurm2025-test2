#include "impls.h"
#include <vector>
#include <algorithm>

std::pair<cv::Rect, cv::RotatedRect> get_rect_by_contours(const cv::Mat& input) 
{
    std::vector<std::vector<cv::Point>> contours;std::vector<cv::Vec4i> hierarchy;
    cv::Mat gray;cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
    cv::threshold(gray, gray, 100, 255, cv::THRESH_BINARY_INV);
    cv::findContours(gray, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    std::pair<cv::Rect, cv::RotatedRect> res;
    double maxArea = 0;
    for (size_t i = 0; i < contours.size(); i++)
        {
        cv::Rect rect = cv::boundingRect(contours[i]);
        cv::RotatedRect rotatedRect = cv::minAreaRect(contours[i]);
        double area = cv::contourArea(contours[i]);
        if (area > maxArea) 
        {
            maxArea = area;
            res.first = rect;
            res.second = rotatedRect;
        }
    }

    return res;
}
