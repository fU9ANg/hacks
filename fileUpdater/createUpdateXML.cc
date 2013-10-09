
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string>
#include <map>
#include <vector>

#include "utils.h"
#include "md5_calc.h"

using namespace std;

struct sXmlFileNode
{
    string  md5sum;
    string  filename;
};

bool dumpXMLs (string& fname1, string& fname2)
{
    try {
        TiXmlDocument* doc = new TiXmlDocument (fname1.c_str ());
        doc->LoadFile ();
        TiXmlElement*  root = doc->RootElement ();
        cout << root->Value () << endl;

        TiXmlElement* version = root->FirstChildElement ();
        TiXmlElement* file = version->FirstChldElement ();
        TiXmlAttribute* atti_md5sum = file->FirstAttribute ();
        TiXmlAttribute* atti_file   = file->LastAttribute ();
    }
    catch (string& e) {
        return (false);
    }

    return (true);
}
