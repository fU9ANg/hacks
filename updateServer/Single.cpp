//
// Singleton
//

#include "Single.h"
#include "userlist.h"

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
    userlist = new CUserList ();
}
    
Single::~Single()
{
    delete userlist;
}
