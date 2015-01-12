
#ifndef CCKEYMANAGER_H_
#define CCKEYMANAGER_H_

#include "cocos2d.h"
#include "cocoa/CCArray.h"
#include "cocoa/CCObject.h"
#include "CCKeyMap.h"
#include "CCAcceptedKey.h"
#include <map>
#include <list>

using namespace std;
using namespace cocos2d;
typedef void (CCObject::*SEL_CallMyFuncO)(int type);
#define callmyfuncO_selector(_SELECTOR) (SEL_CallMyFuncO)(&_SELECTOR)

struct sHandlerStruct
{
	CCObject* target;
	SEL_CallMyFuncO selector;
};

typedef std::map<enum RedLineKeyType, sHandlerStruct*> HANDLEMAP;

class CCKeyManager: public cocos2d::CCNode {

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
    bool registerHandle (enum RedLineKeyType type, SEL_CallMyFuncO selector, CCObject* target);
    bool unRegisterHandle (enum RedLineKeyType type, CCObject* target);
    sHandlerStruct* getHandle (enum RedLineKeyType type);
    void callCppFunction (enum RedLineKeyType type);

private:
    static CCKeyManager* p_instance;
    static int cnt;

    static HANDLEMAP handle_map;
    CCKeyManager (void);
    ~CCKeyManager (void) {}

};

#define CCKEYMANAGER CCKeyManager::instance()

#endif /* CCKEYMANAGER_H_ */
