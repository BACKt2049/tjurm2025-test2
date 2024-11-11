#include "impls.h"
#include <algorithm>
float compute_iou(const cv::Rect& a, const cv::Rect& b) 
{
     cv::Rect chonghe = a & b;
    float chonghearea = chonghe.width * chonghe.height;
    float bingjiarea = a.area() + b.area() - chonghearea;
    float iou = chonghearea / bingjiarea;
  return iou;
}
