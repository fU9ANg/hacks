
#include <iostream>
#include "tinyxml.h"
#include "tinystr.h"
#include <string>

#include <stdlib.h>

using namespace std;

#define MAX_VERSION_NUMBER  5
#define MAX_FILE_NUMBER     3

#define FILENAME(i)    "http://222.186.50.76:9090/static/test"".zip"

bool buildXML(string& fname)
{
    int i, j;
    try {
        TiXmlDocument* doc = new TiXmlDocument ();
        TiXmlElement* root = new TiXmlElement ("Updates");
        doc->LinkEndChild (root);

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

                TiXmlText* file_content = new TiXmlText (FILENAME(10));
                file->LinkEndChild (file_content);
            }
        }
        doc->SaveFile (fname.c_str());
    }
    catch (string& e) {
        return (false);
    }

    return (true);
}

bool dumpXML(string& fname)
{
    try {
        TiXmlDocument* doc = new TiXmlDocument (fname.c_str());
        doc->LoadFile ();
        TiXmlElement* root = doc->RootElement ();
        
        cout << root->Value () << endl;

        TiXmlElement* version = root->FirstChildElement ();
        TiXmlAttribute* atti_major = version->FirstAttribute ();
        TiXmlAttribute* atti_minor = version->LastAttribute ();

        TiXmlElement* file = version->FirstChildElement ();
        TiXmlAttribute* atti_size = file->FirstAttribute ();
        TiXmlAttribute* atti_date = file->LastAttribute ();

        cout << version->FirstChild ()->Value() << endl;
        cout << atti_major->Name () << ": " << atti_major->Value () << ", " <<
        atti_minor->Name () << ": " << atti_minor->Value () << endl;
        cout << file->FirstChild ()->Value() << endl;
        cout << atti_size->Name () << ": " << atti_size->Value () << ", " << \
        atti_date->Name () << ": " << atti_date->Value () << endl;

    }
    catch (string& e) {
        return (false);
    }

    return true;
}

int main()
{
    string fileName = "./info.xml";
    buildXML (fileName);
    dumpXML (fileName);
}

