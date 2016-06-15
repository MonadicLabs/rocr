
#include "charcandidate.h"
#include "spatialdb.h"

#include <opencv2/opencv.hpp>

using namespace rocr;
using namespace cv;

void rocr::CharCandidate::computeOrientation(std::shared_ptr<rocr::SpatialDB> db, LineDetector& ld )
{
    float searchRadius = 4.0f * _rect.width;
    std::vector< std::shared_ptr< CharCandidate > > nb = db->findNearest( this->getptr(), searchRadius );
    cv::Mat dbg = cv::Mat::zeros( 2000,2000,CV_8UC3 );
    rectangle( dbg, this->rect(), Scalar(0,255,0) );
    for( std::shared_ptr<CharCandidate> n : nb )
    {
        rectangle( dbg, n->rect(), Scalar(0,0,255) );
        ld.castVote( n, this->getptr() );
    }
    //ld.showAccu();
    //imshow( "popo", dbg );
    //waitKey(0);
}
