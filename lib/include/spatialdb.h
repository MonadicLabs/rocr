#pragma once

#include <memory>

#include "charcandidate.h"

namespace rocr
{
class SpatialDB
{
public:
    SpatialDB(){}
    virtual ~SpatialDB(){}

    virtual void build( std::vector< std::shared_ptr<CharCandidate> > candidates )=0;
    virtual std::vector< std::shared_ptr< CharCandidate> > findNearest( std::shared_ptr<rocr::CharCandidate> cc, float radius = 0.0f ) = 0;

private:

protected:

};
}
