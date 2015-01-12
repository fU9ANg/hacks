
#ifndef _CCTESTKEYEVENT_H_
#define _CCTESTKEYEVENT_H_

#include "CCAcceptedKey.h"
#include <list>

class CCTestKeyEvent: public AcceptedKey {

public:
        CCTestKeyEvent (void);
        ~CCTestKeyEvent (void) {}

public:
        void processBack ();
        void processUp ();
        void processDown ();
        void processLeft ();
        void processRight ();
        void processOK ();
};

#endif /* _CCTESTKEYEVENT_H_ */
