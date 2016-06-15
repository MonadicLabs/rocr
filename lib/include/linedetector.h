#pragma once

#include <memory>
#include <opencv2/opencv.hpp>

#define DEG2RAD 0.017453293f

#ifndef round
    #define round(_x) ((_x-floor(_x))>=0.5 ? ceil(_x) : floor(_x))
#endif

namespace rocr
{
class CharCandidate;
class LineDetector
{
public:
    LineDetector( cv::Size imgSize )
        :_imgSize(imgSize)
    {
        // Hough-based line character line detection
        int h = _imgSize.width;
        int w = _imgSize.height;

        //Create the accumulator
        _hough_h = ((sqrt(2.0) * (double)(h>w?h:w)));
        int _accu_h = _hough_h * 2.0; // -r -> +r
        int _accu_w = 180;

        _accumulator = cv::Mat::zeros( _accu_h, _accu_w, CV_32F );
        _center = cv::Point( w/2, w/2 );
    }

    void castVote( std::shared_ptr<rocr::CharCandidate> a, std::shared_ptr<rocr::CharCandidate> b );

    void showAccu();

    virtual ~LineDetector()
    {}

private:
    cv::Mat _accumulator;
    cv::Size _imgSize;
    cv::Point _center;
    double _hough_h;

};
}
