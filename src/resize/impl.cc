#include "impls.h"

cv::Mat my_resize(const cv::Mat& input, float scale) {
    // 计算新的图像尺寸
    int new_rows = static_cast<int>(input.rows * scale);
    int new_cols = static_cast<int>(input.cols * scale);

    // 创建一个新的Mat对象，用于存储缩放后的图像
    cv::Mat output = cv::Mat::zeros(new_rows, new_cols, input.type());

    // 遍历新图像的每个像素
    for (int i = 0; i < new_rows; ++i) {
        for (int j = 0; j < new_cols; ++j) {
            // 计算最近邻像素在原图像中的坐标
            int x = static_cast<int>(j / scale);
            int y = static_cast<int>(i / scale);

            // 确保坐标在原图像的范围内
            if (x < input.cols && y < input.rows) {
                // 将原图像中最近邻像素的值赋给新图像的对应像素
                output.at<cv::Vec3b>(i, j) = input.at<cv::Vec3b>(y, x);
            }
        }
    }

    return output;
}
