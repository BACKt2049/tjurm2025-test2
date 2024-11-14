#include <opencv2/opencv.hpp>
#include <vector>

std::vector<std::vector<cv::Point>> find_contours(const cv::Mat& input)
{
    cv::imshow("Input Image", input);
    cv::waitKey(0); 
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::Mat gray;
    if (input.channels() == 3) 
    {
        cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
    } else
    {
        gray = input.clone();
    }
    cv::Mat blurred;
    cv::GaussianBlur(gray, blurred, cv::Size(5, 5), 0);
    cv::Mat canny_output;
    cv::Canny(blurred, canny_output, 50, 150);
    cv::findContours(canny_output, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);
    std::vector<std::vector<cv::Point>> res; 
    for (size_t i = 0; i < hierarchy.size(); i++)
        {
        if (hierarchy[i][3] == -1 && hierarchy[i][0] == -1)
        {
            res.push_back(contours[i]);
        }
    }
    return res;
}
