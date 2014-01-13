
#include <sys/wait.h>

#include "HandleMessage.h"

#include "protocol.h"
#include "Buf.h"
#include "Single.h"
#include "Config.h"

#include "version.pb.h"
#include "updatecontent.pb.h"

void CHandleMessage::handleTest (Buf* p)
{
    cout << "CT_Test" << endl;
    if (p == NULL)
        return;

    return;
}

void CHandleMessage::handleLogin (Buf* p)
{
    cout << "CT_Login" << endl;

    if (p == NULL)
        return;

    SINGLE->userlist->add_client (p->getfd ());

    MSG_HEAD* head = (MSG_HEAD*) p->ptr ();
    head->cLen = MSG_HEAD_LEN;
    head->cType = ST_Login;

    p->reset ();
    SINGLE->bufpool.free (p);
}

void CHandleMessage::handleGetVersion (Buf* p)
{
    cout << "CT_Version" << endl;

    if (p == NULL)
        return;

    CClient* pclient = NULL;
    MSG_HEAD* head = (MSG_HEAD*) p->ptr ();
    head->cLen = MSG_HEAD_LEN;
    head->cType = ST_GetVersion;

    version v;

    string recvstr ((char*) head->cData ());
    v.ParseFromString (recvstr);

    pclient = SINGLE->userlist->get_client_by_fd (p->getfd ());
    if (pclient)
    {
        pclient->setVersion (v.ver ());
        cout << "Client version is: " << pclient->getVersion () << endl;
    }

    p->reset ();
    SINGLE->bufpool.free (p);
}

void CHandleMessage::handleGetUpdateContent (Buf* p)
{
    cout << "CT_GetUpdateContent" << endl;

    if (p == NULL)
        return;

    int status;
    pid_t pid;

    CClient* pclient = NULL;
    MSG_HEAD* head = (MSG_HEAD*) p->ptr ();
    head->cLen = MSG_HEAD_LEN;
    head->cType = ST_GetUpdateContent;

    // execute external exe file
    pclient = SINGLE->userlist->get_client_by_fd (p->getfd ());
    if (pclient)
    {
#ifdef DDEBUG
        cout << "Request Version: " << pclient->getVersion () << "\t" << "System Version: " << CONFIG->curr_version << endl;
#endif
        string tmpFirstVersion = "xmlfileUpdater/xml/";
        tmpFirstVersion += pclient->getVersion();
        tmpFirstVersion += ".xml";

        string tmpSecondVersion = "xmlfileUpdater/xml/" + CONFIG->curr_version + ".xml";

        pid = fork ();
        if (pid == 0)
            execl("xmlfileUpdater/createupdatexml", \
                  "xmlfileUpdater/createupdatexml", \
                   tmpFirstVersion.c_str(), \
                   tmpSecondVersion.c_str(), \
                   CONFIG->download_server.c_str(), NULL);
        else if (pid > 0)
            waitpid (pid, &status, 0);
        else {
            p->reset ();
            SINGLE->bufpool.free (p);
            return;
        }
    }
    else
    {
        p->reset ();
        SINGLE->bufpool.free (p);
        return;
    }

    updatecontent update;

    int ffd, nread = 0;
    string fcontent;
    char buffer[MAX_BUFF_SIZE];
    string fileName = pclient->getVersion() + "-" + CONFIG->curr_version + ".xml";
    if ((ffd = open (fileName.c_str(), O_RDONLY)) < 0)
    {
        perror ("open");
        p->reset ();
        SINGLE->bufpool.free (p);
        return;
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

    head->cLen = MSG_HEAD_LEN;
    head->cType = ST_GetUpdateContent;
    head->cLen += s_update.size ();

    p->setsize (head->cLen);
    SINGLE->sendqueue.enqueue (p);
}
