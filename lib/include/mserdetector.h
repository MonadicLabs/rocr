#pragma once

#include "chardetector.h"

namespace rocr
{
    class MSERDetector : public CharDetector
    {
    public:
        MSERDetector(){}
        virtual ~MSERDetector(){}

        virtual void setup(std::vector<Parameter> params);
        virtual std::vector< std::shared_ptr< CharCandidate > > detect(cv::Mat img);
    private:

    protected:

    };
}
