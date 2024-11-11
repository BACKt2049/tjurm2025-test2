#include "impls.h"
#include <vector>
#include <algorithm>

std::pair<cv::Rect, cv::RotatedRect> get_rect_by_contours(const cv::Mat& input) {
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    // 将输入图像转换为灰度图，然后进行二值化
    cv::Mat gray;
    cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
    cv::threshold(gray, gray, 100, 255, cv::THRESH_BINARY_INV);

    // 查找轮廓
    cv::findContours(gray, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    std::pair<cv::Rect, cv::RotatedRect> res;
    double maxArea = 0;

    // 遍历所有轮廓
    for (size_t i = 0; i < contours.size(); i++) {
        // 计算外接矩形
        cv::Rect rect = cv::boundingRect(contours[i]);
        // 计算最小面积外接矩形
        cv::RotatedRect rotatedRect = cv::minAreaRect(contours[i]);

        // 计算轮廓面积
        double area = cv::contourArea(contours[i]);

        // 更新最大面积的矩形
        if (area > maxArea) {
            maxArea = area;
            res.first = rect;
            res.second = rotatedRect;
        }
    }

    return res;
}
