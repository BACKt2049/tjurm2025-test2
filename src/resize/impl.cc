#include "impls.h"

cv::Mat my_resize(const cv::Mat& input, float scale) {
    int new_rows = static_cast<int>(input.rows * scale);
    int new_cols = static_cast<int>(input.cols * scale);
    cv::Mat output = cv::Mat::zeros(new_rows, new_cols, input.type());
    for (int i = 0; i < new_rows; ++i)
        {
        for (int j = 0; j < new_cols; ++j)
            {
            int x = static_cast<int>(j / scale);int y = static_cast<int>(i / scale);
            if (x < input.cols && y < input.rows)
            {
                output.at<cv::Vec3b>(i, j) = input.at<cv::Vec3b>(y, x);
            }
        }
    }
    //这里是进行了一些修改稍微好看一点
    return output;
}
