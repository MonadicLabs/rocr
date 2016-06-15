
#include "lineardb.h"
#include "utils.h"

void rocr::LinearDB::build(std::vector< std::shared_ptr<rocr::CharCandidate> > candidates)
{
    _data.insert( _data.begin(), candidates.begin(), candidates.end() );
}

std::vector< std::shared_ptr<rocr::CharCandidate> > rocr::LinearDB::findNearest( std::shared_ptr<rocr::CharCandidate> cc, float radius)
{
    std::vector< std::shared_ptr<CharCandidate> > ret;
    // Linear search that is
    for( std::shared_ptr<CharCandidate> c : _data )
    {
        if( c == cc )
            continue;

        float beta = fmax( (float)(c->rect().area()) / (float)(cc->rect().area()), (float)(cc->rect().area()) / (float)(c->rect().area()) );
        if( beta > 10.0f )
            continue;

        cv::Point p1 = cc->center();
        cv::Point p2 = c->center();
        float d = pointDistance( p1, p2 );
        if( d < radius )
        {
            ret.push_back( c );
        }
    }
    return ret;
}
