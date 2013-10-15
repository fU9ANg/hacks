//
// Singleton
//

#include "Single.h"

Single* Single::p_ = NULL;
Single* Single::instance() 
{
    if (NULL == p_) {
        p_ = new Single(); 
    }
    return p_;
}

Single::Single()
{
}
    
Single::~Single()
{
}
