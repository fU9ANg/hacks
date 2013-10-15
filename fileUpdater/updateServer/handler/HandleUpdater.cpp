
#include "HandleMessage.h"

#include "protocol.h"
#include "Buf.h"
#include "Single.h"

#include "version.pb.h"
#include "updatecontent.pb.h"

void CHandleMessage::handleTest (Buf* p)
{
    cout << "CT_Test" << endl;
    if (p == NULL)
        return;

    return;
}

void CHandleMessage::handleGetVersion (Buf* p)
{
    cout << "CT_Version" << endl;

    if (p == NULL)
        return;

    MSG_HEAD* head = (MSG_HEAD*) p->ptr ();
    head->cLen = sizeof (MSG_HEAD);
    head->cType = ST_GetVersion;

    version v;

    string recvstr ((char*) head->cData ());
    v.ParseFromString (recvstr);

    cout << v.ver() << endl;

    p->reset ();
    SINGLE->bufpool.free (p);
}

void CHandleMessage::handleGetUpdateContent (Buf* p)
{
    cout << "CT_GetUpdateContent" << endl;

    if (p == NULL)
        return;

    MSG_HEAD* head = (MSG_HEAD*) p->ptr ();
    head->cLen = sizeof (MSG_HEAD);
    head->cType = ST_GetUpdateContent;

    updatecontent update;

    int ffd, nread = 0;
    string fcontent;
    char buffer[MAX_BUFF_SIZE];
    if ((ffd = open ("outoutout.xml", O_RDONLY)) < 0)
    {
        perror ("open outoutout.xml");
        p->reset ();
        SINGLE->bufpool.free (p);
    }
    (void) memset (buffer, 0x00, sizeof (buffer));
    while ((nread = read (ffd, &buffer[0], MAX_BUFF_SIZE)) > 0)
    {
        string tmpStr = buffer;
        fcontent += tmpStr;
        (void) memset (buffer, 0x00, sizeof (buffer));
        
    }

    cout << fcontent.c_str() << endl;
    update.set_xmlcontent (fcontent.c_str());

    string  s_update;
    update.SerializeToString (&s_update);

    (void) memcpy (head->cData(), s_update.c_str(), s_update.size ());
    head->cLen += s_update.size ();
    
    p->setsize (head->cLen);
    SINGLE->sendqueue.enqueue (p);
}
