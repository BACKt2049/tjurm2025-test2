#include "impls.h"
#include <opencv2/opencv.hpp>

std::vector<cv::Mat> erode(const cv::Mat& src_erode, const cv::Mat& src_dilate) {
    cv::Mat gray_erode, gray_dilate;
    cv::Mat binary_erode, binary_dilate;
    cv::Mat dst_erode, dst_dilate;
    cv::cvtColor(src_erode, gray_erode, cv::COLOR_BGR2GRAY);
    cv::cvtColor(src_dilate, gray_dilate, cv::COLOR_BGR2GRAY);
    cv::threshold(gray_erode, binary_erode, 50, 255, cv::THRESH_BINARY);
    cv::threshold(gray_dilate, binary_dilate, 50, 255, cv::THRESH_BINARY);
    cv::Mat element_erode = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::Mat element_dilate = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::erode(binary_erode, dst_erode, element_erode, cv::Point(-1, -1), 1, cv::BORDER_CONSTANT, cv::morphologyDefaultBorderValue());
    cv::dilate(binary_dilate, dst_dilate, element_dilate, cv::Point(-1, -1), 1, cv::BORDER_CONSTANT, cv::morphologyDefaultBorderValue());
 return {dst_erode, dst_dilate};
}
        
