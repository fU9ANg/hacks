
#include "CCKeyManager.h"

CCKeyManager* CCKeyManager::p_instance = NULL;
int CCKeyManager::cnt = 0;
ACCEPTEDKEYLIST CCKeyManager::ak_list;

CCKeyManager::CCKeyManager() {
	// TODO Auto-generated constructor stub

}

void CCKeyManager::callCppFunction (int keytype)
{
        enum RedLineKeyType kt = (enum RedLineKeyType) keytype;

        for (ACCEPTEDKEYLIST::iterator it=ak_list.begin(); it!=ak_list.end(); ++it) {
        	switch (kt) {
        	case RLKT_BACK:
        		(*it)->processBack ();
        		break;
        	case RLKT_OK:
        		(*it)->processOK ();
        		break;
        	case RLKT_UP:
        		(*it)->processUp ();
        		break;
        	case RLKT_DOWN:
        		(*it)->processDown ();
        		break;
        	case RLKT_LEFT:
        		(*it)->processLeft ();
        		break;
        	case RLKT_RIGHT:
        		(*it)->processRight ();
        		break;
        	} // swith

        } // for

}

bool CCKeyManager::insert (AcceptedKey* obj)
{
        if (!obj) return (false);
        ak_list.push_back (obj);
        return (true);
}

bool CCKeyManager::remove (AcceptedKey* obj)
{
        if (!obj) return (false);
        for (ACCEPTEDKEYLIST::iterator it=ak_list.begin(); it!=ak_list.end(); ++it) {
                if ((*it) == obj) {
                        ak_list.erase (it);
                        return (true);
                }
        }
        return (true);
}
