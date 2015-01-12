
#ifndef __CC_ACCEPTED_KEY_H
#define __CC_ACCEPTED_KEY_H

#include "CCUtils.h"

class AcceptedKey
{
public:
        AcceptedKey () {
                m_obj = this;
                insertObjectToList (this);
        }
        virtual ~AcceptedKey () {
        	removeObjectFromList (m_obj);
        }

        virtual void processBack () {}
        virtual void processUp () {}
        virtual void processDown () {}
        virtual void processLeft () {}
        virtual void processRight () {}
        virtual void processOK () {}

private:
        AcceptedKey* m_obj;
};

#endif // __CC_ACCEPTED_KEY_H
