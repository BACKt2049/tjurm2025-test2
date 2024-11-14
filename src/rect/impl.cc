#include <opencv2/opencv.hpp>
#include <vector>

std::pair<cv::Rect, cv::RotatedRect> get_rect_by_contours(const cv::Mat& input) {
    std::pair<cv::Rect, cv::RotatedRect> res;
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::Mat gray;
    cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
    cv::Mat canny_output;
    cv::Canny(gray, canny_output, 100, 200);
    cv::findContours(canny_output, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    double max_area = 0;
    for (size_t i = 0; i < contours.size(); i++) 
    {
        double area = cv::contourArea(contours[i]);
        if (area > max_area)
        {
            max_area = area;
            cv::Rect bounding_rect = cv::boundingRect(contours[i]);
            cv::RotatedRect min_area_rect = cv::minAreaRect(contours[i]);
            res.first = bounding_rect;
            res.second = min_area_rect;
        }
    }

    return res;
}
