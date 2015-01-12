
#include "CCUtils.h"

#include "CCAcceptedKey.h"
#include "CCKeyManager.h"

void insertObjectToList (AcceptedKey* obj)
{
	CCKEYMANAGER->insert(obj);
}
void removeObjectFromList (AcceptedKey* obj)
{
	CCKEYMANAGER->remove(obj);
}
