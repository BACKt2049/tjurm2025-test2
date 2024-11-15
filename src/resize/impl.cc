#include "impls.h"
cv::Mat my_resize(const cv::Mat& input, float scale)
{
    int new_rows = static_cast<int>(input.rows * scale);
    int new_cols = static_cast<int>(input.cols * scale);
    cv::Mat output = cv::Mat::zeros(new_rows, new_cols, input.type());
    for (int i = 0; i < new_rows; ++i)
        {
        for (int j = 0; j < new_cols; ++j) 
        {
            float x = j / scale;
            float y = i / scale;
            int x1 = static_cast<int>(x);
            int y1 = static_cast<int>(y);
            int x2 = x1 + 1;
            int y2 = y1 + 1;
            if (x2 >= input.cols) x2 = x1;
            if (y2 >= input.rows) y2 = y1;
            float wx2 = x - x1;
            float wy2 = y - y1;
            float wx1 = 1.0 - wx2;
            float wy1 = 1.0 - wy2;
            for (int k = 0; k < 3; ++k) { // 对于BGR三个通道
                float p1 = input.at<cv::Vec3b>(y1, x1)[k] * wx1 * wy1;
                float p2 = input.at<cv::Vec3b>(y1, x2)[k] * wx2 * wy1;
                float p3 = input.at<cv::Vec3b>(y2, x1)[k] * wx1 * wy2;
                float p4 = input.at<cv::Vec3b>(y2, x2)[k] * wx2 * wy2;
                output.at<cv::Vec3b>(i, j)[k] = static_cast<uchar>(p1 + p2 + p3 + p4);
            }
        }
    }

    return output;
}
