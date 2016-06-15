#pragma once

#include <opencv2/opencv.hpp>

namespace rocr
{
    cv::Mat aspectResize(cv::Mat& img, cv::Size newSize, float& aspectRatio );

    template< class T >
    float pointDistance( T& a, T& b )
    {
        float dx = b.x - a.x;
        float dy = b.y - a.y;
        return sqrt( dx*dx + dy*dy );
    }
}
