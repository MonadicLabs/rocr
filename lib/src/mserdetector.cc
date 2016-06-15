
#include "mserdetector.h"

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void rocr::MSERDetector::setup(std::vector<rocr::Parameter> params)
{

}

std::vector< std::shared_ptr<rocr::CharCandidate> > rocr::MSERDetector::detect(cv::Mat img)
{
    std::vector< std::shared_ptr<CharCandidate> > res;

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

        // rectangle( dbg, r, Scalar(0,255,0) );
        std::shared_ptr<CharCandidate> c = make_shared<CharCandidate>();
        c->rect( r );
        res.push_back( c );
    }

    removeIncluded(res);

    for( std::shared_ptr<CharCandidate> cc : res )
    {
        rectangle( dbg, cc->rect(), Scalar(0,255,0) );
    }
    //imshow("dbg", dbg );
    //waitKey(0);

    imwrite( "/tmp/popo.png", dbg );

    return res;
}

int rocr::MSERDetector::removeIncluded(std::vector< std::shared_ptr<rocr::CharCandidate> > &chars)
{
    int ret;

    std::vector<int> todel(chars.size());
    std::fill( todel.begin(), todel.end(), 0 );

    std::vector< std::shared_ptr<CharCandidate> > tmp;

    for( int i = 0; i < chars.size(); ++i )
    {
        Rect ir = chars[i]->rect();
        for( int j = i+1; j < chars.size(); ++j )
        {
            Rect jr = chars[j]->rect();
            if( (ir & jr).area() == ir.area() )
            {
                todel[i] = 1;
            }
            else if( (ir & jr).area() == jr.area() )
            {
                todel[j] = 1;
            }
        }
    }

    for( int k = 0; k < chars.size(); ++k )
    {
        if( todel[k] == 0 )
            tmp.push_back(chars[k]);
    }

    chars = tmp;

    return ret;
}
