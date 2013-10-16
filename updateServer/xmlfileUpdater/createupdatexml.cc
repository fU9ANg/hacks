
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
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
    string  md5sum;
    string  filename;
    string  flag;
};

typedef std::vector <struct sXmlFileNode*> VECTORFILENODE;

void createUpdateNode (VECTORFILENODE* out, VECTORFILENODE* vNode1, VECTORFILENODE* vNode2)
{
    VECTORFILENODE::iterator it1, it2;

    for (it2 = vNode2->begin (); it2 != vNode2->end (); it2++)
    {
        for (it1 = vNode1->begin (); it1 != vNode1->end (); it1++)
        {
            if ((*it1)->md5sum == (*it2)->md5sum)
                break;
        }

        if (it1 != vNode1->end ())
            continue;
        struct sXmlFileNode* fileNode = new (struct sXmlFileNode);
        fileNode->md5sum = (*it2)->md5sum;
        fileNode->filename = (*it2)->filename;
        fileNode->flag = "ADD";
        out->push_back (fileNode);
    }

    for (it1 = vNode1->begin (); it1 != vNode1->end (); it1++)
    {
        for (it2 = vNode2->begin (); it2 != vNode2->end (); it2++)
        {
            if ((*it1)->md5sum == (*it2)->md5sum)
                break;
        }
        if (it2 != vNode2->end ())
            continue;
        struct sXmlFileNode* fileNode = new (struct sXmlFileNode);
        fileNode->md5sum = (*it1)->md5sum;
        fileNode->filename = (*it1)->filename;
        fileNode->flag = "DEL";
        out->push_back (fileNode);
    }
}

bool buildUpdateXML (string& fname, VECTORFILENODE* vNode)
{
    try {
        TiXmlDocument* doc = new TiXmlDocument ();
        TiXmlElement* root = new TiXmlElement ("updates");
        doc->LinkEndChild (root);

        TiXmlElement* bk_server = new TiXmlElement ("bk_server");
        TiXmlText* bk_server_addr = new TiXmlText ("192.168.0.254");
        bk_server->LinkEndChild (bk_server_addr);
        root->LinkEndChild (bk_server);

        TiXmlElement* servers = new TiXmlElement ("servers");
        root->LinkEndChild (servers);

        TiXmlElement* server = new TiXmlElement ("server");
        TiXmlText* server_addr = new TiXmlText ("xxx.xxx.xxx.xxx");
        server->LinkEndChild (server_addr);
        servers->LinkEndChild (server);

        TiXmlElement* filelist = new TiXmlElement ("filelist");
        root->LinkEndChild (filelist);

        VECTORFILENODE::iterator it;
        for (it = vNode->begin (); it != vNode->end (); it++)
        {
            TiXmlElement* file = new TiXmlElement ("file");
            file->SetAttribute ("flag", (*it)->flag.c_str());
            file->SetAttribute ("md5", (*it)->md5sum.c_str());
            TiXmlText* file_content = new TiXmlText ((*it)->filename.c_str());
            file->LinkEndChild (file_content);

            filelist->LinkEndChild (file);
        }
#if 0
        for (i = 0; i < MAX_VERSION_NUMBER; i++) {
            TiXmlElement* version = new TiXmlElement ("Version");
            version->SetAttribute ("major", "1");
            version->SetAttribute ("minor", "2");
            root->LinkEndChild (version);

            for (j = 0; j < MAX_FILE_NUMBER; j++) {
                TiXmlElement* file = new TiXmlElement ("File");
                file->SetAttribute ("size", "130k");
                file->SetAttribute ("date", "2013/7/13 12:10:10");
                version->LinkEndChild (file);

                TiXmlText* file_content = new TiXmlText (FILENAME (10));
                file->LinkEndChild (file_content);
            }
        }
#endif
        doc->SaveFile (fname.c_str());
    }
    catch (string& e) {
        return (false);
    }

    return (true);
}

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

bool LoadXml (VECTORFILENODE* vNode, string& fname)
{
    try {
        TiXmlDocument* doc = new TiXmlDocument (fname.c_str ());
        doc->LoadFile ();
        TiXmlElement*  root = doc->RootElement ();
        cout << root->Value () << endl;

        TiXmlElement* version = root->FirstChildElement ();
        TiXmlElement* file = version->FirstChildElement ();
        for (; file; file = file->NextSiblingElement ())
        {
            TiXmlAttribute* atti_md5sum = file->FirstAttribute ();
            string s_file   = file->GetText ();

            struct sXmlFileNode* xmlFileNode = new (struct sXmlFileNode);
            xmlFileNode->md5sum = atti_md5sum->Value ();
            xmlFileNode->filename = file->GetText ();
            xmlFileNode->flag = "add";

            vNode->push_back (xmlFileNode);
        }
    }

    catch (string& e) {
        return (false);
    }

    return (true);
}

int main (int argc, char** argv)
{
    if (argc != 3)
    {
        printf ("usage: %s <version1> <version2>.\n", argv[0]);
        exit (1);
    }
    string f1 = argv[1];
    string f2 = argv[2];

    string outfile = f1.substr (f1.rfind ("v"), f1.rfind (".xml") - f1.rfind ("v")) + "-" + \
                     f2.substr (f2.rfind ("v"), f2.rfind (".xml") - f2.rfind ("v")) + ".xml";
    cout << outfile << endl; getchar ();
    VECTORFILENODE vNode1, vNode2, out;
    LoadXml (&vNode1, f1);
    LoadXml (&vNode2, f2);


    createUpdateNode (&out, &vNode1, &vNode2);
    // dump information
    ///dumpNodes (&vNode1);
    ///dumpNodes (&vNode2);
    dumpNodes (&out);

    buildUpdateXML (outfile, &out);

    // clear all node
    cleanNodes (&vNode1);
    cleanNodes (&vNode2);
    cleanNodes (&out);

    return (0);
}
