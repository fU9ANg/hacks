
#ifndef CCKEYMANAGER_H_
#define CCKEYMANAGER_H_

#include "CCKeyMap.h"
#include "CCAcceptedKey.h"
#include <cstdlib>
#include <list>

using namespace std;

typedef list<AcceptedKey*> ACCEPTEDKEYLIST;

class CCKeyManager {

public:
    static CCKeyManager* instance(void) {
        if (NULL == p_instance) {
            p_instance = new CCKeyManager ();
        }
        ++cnt;
        return (p_instance);
    }

    bool deleteInstance (void) {
        if (0 == --cnt) {
            delete p_instance;
            p_instance = NULL;
        }
        return (true);
    }
    static bool insert (AcceptedKey* obj);
    static bool remove (AcceptedKey* obj);
    static void callCppFunction (int keytype);


private:
    static CCKeyManager* p_instance;
    static int cnt;
    static ACCEPTEDKEYLIST ak_list;

    CCKeyManager (void);
    ~CCKeyManager (void) {}

};

#define CCKEYMANAGER CCKeyManager::instance()

#endif /* CCKEYMANAGER_H_ */
