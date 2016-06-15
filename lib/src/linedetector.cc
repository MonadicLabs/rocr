
#include "linedetector.h"
#include "charcandidate.h"

using namespace cv;

void rocr::LineDetector::castVote(std::shared_ptr<rocr::CharCandidate> a, std::shared_ptr<rocr::CharCandidate> b)
{
    // Calcule l'angle entre les deux centroides
    Point2f p1 = a->center();
    Point2f p2 = b->center();
    float angle = atan2(p1.y - p2.y, p1.x - p2.x);
    float dangle = angle * 180.0f / CV_PI;

    int t = 90 + dangle;
    int x = (p1.x + p2.x) / 2.0f;
    int y = (p1.y + p2.y) / 2.0f;
    double r = ( ((double)x - _center.x) * cos((double)t * DEG2RAD)) + (((double)y - _center.y) * sin((double)t * DEG2RAD));

    //
    //_accu[ (int)((round(r + hough_h) * 180.0)) + t]++;

    _accumulator.at<float>( (int)((round(r + _hough_h) * 180.0)) + t ) += 1.0f;

}

void rocr::LineDetector::showAccu()
{
    double min;
    double max;
    cv::minMaxIdx(_accumulator, &min, &max);
    cv::Mat adjMap;
    // expand your range to 0..255. Similar to histEq();
    _accumulator.convertTo(adjMap,CV_8UC1, 255 / (max-min), -min);

    // this is great. It converts your grayscale image into a tone-mapped one,
    // much more pleasing for the eye
    // function is found in contrib module, so include contrib.hpp
    // and link accordingly
    cv::Mat falseColorsMap;
    applyColorMap(adjMap, falseColorsMap, cv::COLORMAP_JET);

    cv::imshow("Out", falseColorsMap);
    //cv::imshow("accu", _accumulator);
    cv::waitKey(0);
}
