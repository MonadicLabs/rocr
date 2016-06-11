
#include <rocr.h>
#include <mserdetector.h>

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace rocr;

int main( int argc, char** argv )
{
    cv::Mat img = imread( argv[1] );
    MSERDetector d;
    auto res = d.detect( img );
    return 0;
}
