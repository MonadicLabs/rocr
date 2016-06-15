#pragma once

#include <memory>

#include <opencv2/core.hpp>

#include "linedetector.h"

namespace rocr
{
    class SpatialDB;
    class CharCandidate : public std::enable_shared_from_this<CharCandidate>
    {
    public:
        CharCandidate(){}
        virtual ~CharCandidate(){}

        std::shared_ptr<CharCandidate> getptr()
        {
            return shared_from_this();
        }

        cv::Rect rect(){ return _rect; }
        void rect( const cv::Rect& r ){ _rect = r; }
        cv::Point center(){ return cv::Point( _rect.x + _rect.width/2, _rect.y + _rect.height/2 ); }

        void computeOrientation(std::shared_ptr<rocr::SpatialDB> db , LineDetector &ld);

    private:
        cv::Rect _rect;

    protected:

    };
}
