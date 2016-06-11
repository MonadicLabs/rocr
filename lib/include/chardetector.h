#pragma once

#include <vector>

#include "parameter.h"

namespace rocr
{
    class CharDetector
    {
    public:
        CharDetector(){}
        virtual ~CharDetector(){}

        void setup( std::vector< rocr::Parameter > params ) =0;

    private:

    protected:

    };
}
