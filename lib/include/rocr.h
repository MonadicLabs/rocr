#pragma once

#include <string>

#include "utils.h"
#include "spatialdb.h"
#include "lineardb.h"
#include "linedetector.h"

namespace rocr
{
    class ReceiptOCR
    {
    public:
        ReceiptOCR(){}
        virtual ~ReceiptOCR(){}

        void test();

    };
}
