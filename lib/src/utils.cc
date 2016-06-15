
#include "utils.h"

cv::Mat rocr::aspectResize(cv::Mat &img, cv::Size newSize, float &aspectRatio)
{
    float ar = (float)(img.cols) / (float)(img.rows);
    if( ar > 1.0f )
    {
        // image plus large que haute
        aspectRatio = (float)(newSize.width) / (float)(img.cols);
    }
    else
    {
        aspectRatio = (float)(newSize.height) / (float)(img.rows);
    }
    cv::Mat ret;
    cv::resize( img, ret, cv::Size(), aspectRatio, aspectRatio );
    return ret;
}
