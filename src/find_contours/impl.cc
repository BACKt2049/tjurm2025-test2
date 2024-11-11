#include "impls.h"

std::vector<std::vector<cv::Point>> find_contours(const cv::Mat& input) {
    std::vector<std::vector<cv::Point>> res;
    std::vector<cv::Vec4i> hierarchy;
    cv::Mat gray_image;
    cv::cvtColor(input, gray_image, cv::COLOR_BGR2GRAY);
    cv::Mat binary_image;
    cv::threshold(gray_image, binary_image, 100, 255, cv::THRESH_BINARY);
    cv::findContours(binary_image, res, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    return res;
}
