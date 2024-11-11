#include "impls.h"
#include <unordered_map>
std::unordered_map<int, cv::Rect> roi_color(const cv::Mat& input)
{
    std::unordered_map<int, cv::Rect> res;
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::Mat gray_image;
    cv::cvtColor(input, gray_image, cv::COLOR_BGR2GRAY);
    cv::Mat binary_image;
    cv::threshold(gray_image, binary_image, 0, 255, cv::THRESH_BINARY_INV + cv::THRESH_OTSU);
    cv::findContours(binary_image, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    for (size_t i = 0; i < contours.size(); i++) 
    {
        cv::Rect rect = cv::boundingRect(contours[i]);
        cv::Mat roi = input(rect);
        int blue = 0, green = 0, red = 0;
        for (int y = 0; y < roi.rows; y++)
            {
            for (int x = 0; x < roi.cols; x++) 
            {
                cv::Vec3b color = roi.at<cv::Vec3b>(y, x);
                red += color[2];
                green += color[1];
                blue += color[0];
            }
        }
        int totalPixels = roi.rows * roi.cols;
        int maxColor = std::max({blue, green, red});
        if (maxColor == blue)
        {
            res[0] = rect;
        }
        else if (maxColor == green)
        {
            res[1] = rect;
        } 
        else if (maxColor == red) 
        {
            res[2] = rect; 
        }
    }

    return res;
}
