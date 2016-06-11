#pragma once

#include <opencv2/core.hpp>

namespace rocr
{
    class CharCandidate
    {
    public:
        CharCandidate(){}
        virtual ~CharCandidate(){}

        cv::Rect rect(){ return _rect; }
        void rect( const cv::Rect& r ){ _rect = r; }

    private:
        cv::Rect _rect;

    protected:

    };
}
