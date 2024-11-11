#include "impls.h"
float compute_area_ratio(const std::vector<cv::Point>& contour) 
{
     double contourArea = cv::contourArea(contour);
    cv::Rect boundingRect = cv::boundingRect(contour);
    double rectArea = boundingRect.width * boundingRect.height;
    float areaRatio = static_cast<float>(contourArea) / rectArea;
    return 0.f;
}
