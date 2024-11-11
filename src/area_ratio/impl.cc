#include <opencv2/opencv.hpp>
#include <vector>

float compute_area_ratio(const std::vector<cv::Point>& contour) {
    double carea = cv::contourArea(contour);
    cv::Rect boundingrect = cv::boundingRect(contour);
    double rectarea = boundingrect.width * boundingrect.height;
    float arear = static_cast<float>(carea) / rectarea;
    return arear;
}
