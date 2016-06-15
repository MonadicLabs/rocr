#pragma once

#include "spatialdb.h"

namespace rocr
{
    class LinearDB : public rocr::SpatialDB
    {
    public:
        LinearDB(){}
        virtual ~LinearDB(){}

        virtual void build( std::vector< std::shared_ptr<CharCandidate> > candidates );
        virtual std::vector< std::shared_ptr<CharCandidate> > findNearest( std::shared_ptr<CharCandidate> cc, float radius);

    private:
        std::vector< std::shared_ptr<CharCandidate> > _data;

    protected:

    };
}
