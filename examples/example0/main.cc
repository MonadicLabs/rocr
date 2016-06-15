
#include <rocr.h>
#include <mserdetector.h>

#include <memory>

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace rocr;
using namespace std;

int main( int argc, char** argv )
{
    cv::Mat img = imread( argv[1] );
    float ar;
    img = rocr::aspectResize( img, cv::Size(1024,1024), ar );
    MSERDetector d;
    auto res = d.detect( img );

    std::shared_ptr<SpatialDB> sdb = make_shared<LinearDB>();
    sdb->build( res );

    rocr::LineDetector ld( cv::Size( img.cols, img.rows ) );
    for( std::shared_ptr<CharCandidate> cc : res )
    {
        cc->computeOrientation( sdb, ld );
    }
    ld.showAccu();

    return 0;
}
