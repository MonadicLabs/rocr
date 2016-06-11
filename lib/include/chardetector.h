#pragma once

#include <vector>
#include <memory>

#include "parameter.h"
#include "charcandidate.h"

#include <opencv2/opencv.hpp>

namespace rocr
{
class CharDetector
{
public:
    CharDetector(){}
    virtual ~CharDetector(){}

    virtual void setup( std::vector< rocr::Parameter > params ) =0;
    virtual std::vector< std::shared_ptr< rocr::CharCandidate > > detect( cv::Mat img ) = 0;

private:

protected:

};
}
