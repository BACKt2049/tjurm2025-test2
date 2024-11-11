#include "impls.h"
#include <opencv2/opencv.hpp>
#include <unordered_map>

std::unordered_map<int, cv::Rect> roi_color(const cv::Mat& input) {
    std::unordered_map<int, cv::Rect> res;
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

    // 1. 将彩色图像转换为灰度图像
    cv::Mat gray_image;
    cv::cvtColor(input, gray_image, cv::COLOR_BGR2GRAY);

    // 2. 对灰度图像进行二值化
    cv::Mat binary_image;
    cv::threshold(gray_image, binary_image, 0, 255, cv::THRESH_BINARY_INV + cv::THRESH_OTSU);

    // 3. 使用cv::findContours函数检测轮廓
    cv::findContours(binary_image, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // 遍历所有轮廓
    for (size_t i = 0; i < contours.size(); i++) {
        // 4. 使用cv::boundingRect计算外接矩形
        cv::Rect rect = cv::boundingRect(contours[i]);

        // 5. 使用该cv::Rect得到input中的ROI区域
        cv::Mat roi = input(rect);

        // 6. 使用统计的方法，得到该ROI区域的颜色
        int blue = 0, green = 0, red = 0;
        for (int y = 0; y < roi.rows; y++) {
            for (int x = 0; x < roi.cols; x++) {
                cv::Vec3b color = roi.at<cv::Vec3b>(y, x);
                red += color[2];
                green += color[1];
                blue += color[0];
            }
        }
        int totalPixels = roi.rows * roi.cols;
        int maxColor = std::max({blue, green, red});
        if (maxColor == blue) {
            res[0] = rect; // Blue
        } else if (maxColor == green) {
            res[1] = rect; // Green
        } else if (maxColor == red) {
            res[2] = rect; // Red
        }
    }

    return res;
}
