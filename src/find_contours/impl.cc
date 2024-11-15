#include <opencv2/opencv.hpp>
#include "impls.h"

std::vector<std::vector<cv::Point>> find_contours(const cv::Mat& input) {
    std::vector<std::vector<cv::Point>> res;
    std::vector<cv::Vec4i> hierarchy;
    cv::Mat gray;
    cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
    cv::Mat binary;
    cv::threshold(gray, binary, 100, 255, cv::THRESH_BINARY_INV);
    cv::findContours(binary, res, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
    std::vector<std::vector<cv::Point>> innerContours;
    for (size_t i = 0; i < hierarchy.size(); i++) {
        if (hierarchy[i][3] == -1) {
            innerContours.push_back(res[i]);
        }
    }
    
    return innerContours;
}
