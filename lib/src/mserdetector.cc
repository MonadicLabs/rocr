
#include "mserdetector.h"

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void rocr::MSERDetector::setup(std::vector<rocr::Parameter> params)
{

}

std::vector<std::shared_ptr<rocr::CharCandidate> > rocr::MSERDetector::detect(cv::Mat img)
{
    std::vector< shared_ptr<CharCandidate> > res;

    cv::Mat imgGray;
    if( img.channels() == 3 )
    {
        cvtColor( img, imgGray, CV_RGB2GRAY );
    }
    else
    {
        imgGray = img.clone();
    }
    cv::Ptr<MSER> mser = MSER::create( 5, 10 );
    std::vector< std::vector< Point > > pts;
    std::vector< cv::Rect > bboxes;
    mser->detectRegions( imgGray, pts, bboxes );

    cv::Mat dbg( imgGray.rows, imgGray.cols, CV_8UC3 );
    dbg = img;
    for( Rect r : bboxes )
    {
        rectangle( dbg, r, Scalar(0,255,0) );

        auto c = make_shared<CharCandidate>();
        c->rect( r );
        res.push_back( c );
    }

    //imshow("dbg", dbg );
    //waitKey(0);

    imwrite( "/tmp/popo.png", dbg );

    return res;
}
