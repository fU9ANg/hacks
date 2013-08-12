
#ifndef _XML_PARSER_H
#define _XML_PARSER_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include "tinyxml.h"
#include "tinystr.h"

using namespace std;

class CXmlParser
{
    public:
        ~CXmlParser ();
        static CXmlParser* instance ();

        bool Load ();
        bool Dump ();
        string getResourceByEncoding (string res_encoding, string type_encoding, string refer_encoding);
        string getResourceByName (string s_resource, string s_type, string s_reference);
        bool getEncodingByResource (string name, \
            string& res_encoding, string& type_encoding, string& refer_encoding);

    private:
        string getResource (string s1, string s2, string s3, int flags);
        bool getEncoding (string s1, string& s2, string& s3, string& s4, int flags);

        CXmlParser (string sFile);
        static CXmlParser* pInstance;
        TiXmlDocument* m_doc;
        string m_xmlFile;
};

#define XMLPARSER   CXmlParser::instance()

#endif  //_XML_PARSER_H
