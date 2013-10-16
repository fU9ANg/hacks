
#ifndef _TASK_H_
#define _TASK_H_

#include "glog/logging.h"

#include "Buf.h"
#include "database.h"
#include "protocol.h"

#define CT_FLAGS 0
#define ST_FLAGS 1

struct sDebugProtocol
{
    int     cFlags;
    int     cType;
    string  cName;
    int     cStructLen;
    string  cStructName;
    string  cFormat;
};

static struct sDebugProtocol protocols[] =
{
    #define PROTOCOLS
    #include "PROTOCOLS"
    #undef  PROTOCOLS
    {0, 0, "", 0, "", ""},
};

/**
 * @class task基类
 */
class task
{
    public:
        task():autorelease(true){
        }
        virtual ~task(){}
        virtual int work() = 0;
        /**任务完成后是否自动释放*/
        bool autorelease;
        
    public:
        void debugProtocol (Buf* p)
        {
            MSG_HEAD* head = (MSG_HEAD*) p->ptr();
            char* pstr = ((char*) p->ptr()) + MSG_HEAD_LEN;
            int idx = 0;

            while (1) {
                if (protocols[idx].cType == 0)
                    break;
                if (protocols[idx].cType == head->cType)
                {
                    printf ("---------------------\n");
                    if (protocols[idx].cFlags == CT_FLAGS)
                        printf ("[- RecvTask -] Message Packet: \n");
                    else if (protocols[idx].cFlags == ST_FLAGS)
                        printf ("[- SendTask -] Message Packet: \n");

                    printf ("\tReceive message packet from FD=[%d]\n", p->getfd());
                    printf ("\tcType = 0x%x (%d) [%s]\n", protocols[idx].cType, protocols[idx].cType, protocols[idx].cName.c_str());
                    printf ("\tcSturctLen = %d, head->cLen = %d\n", protocols[idx].cStructLen, head->cLen);
                    printf ("\tcStructName = %s, Data: \n", protocols[idx].cStructName.c_str());
                    if (protocols[idx].cFormat.size() != 0) {
                        unsigned int i, j;
                        char str[20];
                        (void) memset (str, 0x00, sizeof (str));
                        for (j=0, i=0; i<protocols[idx].cFormat.size(); i++)
                        {
                            if (protocols[idx].cFormat[i] == ' ')
                                continue;

                            str[j] = protocols[idx].cFormat[i];
                            if (str[j] == ',') {
                                // print Message data
                                if (strcmp (str, "int,") == 0) {
                                    printf ("\t\t%s.int = %d\n", protocols[idx].cStructName.c_str(), \
                                            *(int*)pstr);
                                    pstr += sizeof (int);
                                }
                                else if (strcmp (str, "uint,") == 0) {
                                    printf ("\t\t%s.int = %d\n", protocols[idx].cStructName.c_str(), \
                                            *(unsigned int*)pstr);
                                    pstr += sizeof (unsigned int);
                                }
                                (void) memset (str, 0x00, sizeof (str));
                                j = 0;
                                continue;
                            }
                            j++;
                        }
                    }
                    break;
                }
                idx++;
            }
        }

    private:
};

#endif
