
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <map>
#include <vector>

#include "tinyxml.h"
#include "tinystr.h"
#include "utils.h"
#include "md5_calc.h"

using namespace std;

struct sXmlFileNode
{
    string md5sum;
    string filename;
    string flag;
};

typedef std::vector <struct sXmlFileNode*> VECTORFILENODE;
typedef std::vector <string> VECTORSERVER;

void dumpNodes (VECTORFILENODE* vNode)
{
    VECTORFILENODE::iterator it;
    for (it = vNode->begin (); it != vNode->end (); it++)
    {
        cout << "flag=" << (*it)->flag << " " << (*it)->md5sum << ": " << (*it)->filename << endl;
    }
}

void cleanNodes (VECTORFILENODE* vNode)
{
    VECTORFILENODE::iterator it;
    for (it = vNode->begin (); it != vNode->end (); )
    {
        delete (*it++);
    }
    vNode->clear ();
}

bool LoadUpdateXml (string& fname, string& sbkserver, std::vector<string>* vServer, \
    VECTORFILENODE* vFileNode)
{
    try {
        TiXmlDocument* doc = new TiXmlDocument (fname.c_str());
        doc->LoadFile ();
        TiXmlElement*  root = doc->RootElement ();
        cout << root->Value () << endl;

        TiXmlElement* bk_server = root->FirstChildElement ();
        sbkserver = bk_server->GetText ();
        TiXmlElement* servers = bk_server->NextSiblingElement ();
        TiXmlElement* server = servers->FirstChildElement ();
        for (; server; server = server->NextSiblingElement ())
        {
            string tmpStr = server->GetText ();
            vServer->push_back (tmpStr);
        }

        TiXmlElement* filelist = servers->NextSiblingElement ();
        TiXmlElement* file = filelist->FirstChildElement ();
        for (; file; file = file->NextSiblingElement ())
        {
            TiXmlAttribute* atti_flag   = file->FirstAttribute ();
            TiXmlAttribute* atti_md5sum = file->LastAttribute ();

            struct sXmlFileNode* xmlFileNode = new (struct sXmlFileNode);
            xmlFileNode->md5sum = atti_md5sum->Value ();
            xmlFileNode->filename = file->GetText ();
            xmlFileNode->flag = atti_flag->Value ();

            vFileNode->push_back (xmlFileNode); 
        }
    }

    catch (string& e) {
        return (false);
    }

    return (true);
}

int main ()
{
    string f1 = "OUTOUTOUT.xml";
    string bk_server;
    VECTORFILENODE vNodes;
    VECTORSERVER vServers;

    LoadUpdateXml (f1, bk_server, &vServers, &vNodes);

#ifdef __DEBUG__
    cout << "bk_Server=" << bk_server << endl; 
    VECTORSERVER::iterator it;
    for (it = vServers.begin (); it != vServers.end (); it++)
    {
        cout << (*it) << endl;
    }
    dumpNodes (&vNodes);
    cleanNodes (&vNodes); 
#endif

    return (0); 
}
