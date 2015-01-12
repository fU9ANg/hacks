
#include "CCKeyManager.h"

CCKeyManager* CCKeyManager::p_instance = NULL;
int CCKeyManager::cnt = 0;
HANDLEMAP CCKeyManager::handle_map;

CCKeyManager::CCKeyManager() {
	// TODO Auto-generated constructor stub

}

bool CCKeyManager::registerHandle (enum RedLineKeyType type, SEL_CallMyFuncO selector, CCObject* target)
{
	HANDLEMAP::iterator it;
    HANDLEMAP::iterator ittemp;
    for (it = CCKeyManager::handle_map.begin(); it != CCKeyManager::handle_map.end(); ++it) {
        if (it->first == type) {
            ittemp = it;
        }
    }

    if (ittemp != CCKeyManager::handle_map.end()) {
        delete ittemp->second;
        CCKeyManager::handle_map.erase (ittemp);
    }

    sHandlerStruct* handle = new sHandlerStruct;
    handle->selector = selector;
    handle->target = target;
    CCKeyManager::handle_map.insert (std::make_pair (type, handle));

    return (true);
}

bool CCKeyManager::unRegisterHandle (enum RedLineKeyType type, CCObject* target)
{
    HANDLEMAP::iterator it = CCKeyManager::handle_map.find (type);
    if (it != CCKeyManager::handle_map.end ()) {
        if (it->second->target == target) {
            delete it->second;
            CCKeyManager::handle_map.erase (it);
        }
        else {
            CCLog ("unRegisterHandle: can't found target!");
            return (false);
        }
    }

    return (true);
}

sHandlerStruct* CCKeyManager::getHandle (enum RedLineKeyType type)
{
    for (HANDLEMAP::iterator it = CCKeyManager::handle_map.begin(); \
        it != CCKeyManager::handle_map.end(); ++it) {
        if (it->first == type) {
            return (it->second);
        }
    }

    return (NULL);
}

void CCKeyManager::callCppFunction (enum RedLineKeyType type)
{
	sHandlerStruct* handle = CCKEYMANAGER->getHandle (type);
    if (handle) {
        CCLog ("callCppFunction: goto call c++ function.");
        (handle->target->*handle->selector) (type);
    }

    return;
}
