
#ifndef _XML_PARSER_H
#define _XML_PARSER_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "tinyxml.h"
#include "tinystr.h"

using namespace std;

class CXmlNode;
class CXmlAttribute;
class CXmlParser;

#if 1
class CXmlNode
{
private:
    string name;
    string text;
    TiXmlElement*  element;
    CXmlNode* parent;
public:
    vector<CXmlNode*> children;
    vector<CXmlAttribute*> attributes;

public:
    CXmlNode (TiXmlElement* e)
    {
        this->element = e;
    }
    string getName ()   { return name; }
    string getText ()   { return text; }
    TiXmlElement* getXmlElement () { return element; }
    CXmlNode* getParent () { return parent; }

    void setName (string& s) { this->name = s; }
    void setText (string& t) { this->text = t; }
    void setParent (CXmlNode* n) { this->parent = n; }
    void setXmlElement (TiXmlElement* e) { this->element = e; }
};

class CXmlAttribute
{
private:
    string name;
    string value;
    TiXmlAttribute* attribute;

public:
    CXmlAttribute (TiXmlAttribute* a)
    {
        this->attribute = a;
    }
    string getName ()   { return name; }
    string getValue ()  { return value;}
    TiXmlAttribute* getXmlAttribute () { return attribute; }

    void setName (string& s) { this->name = s; }
    void setValue (string& v) { this->value = v; }
    void setXmlAttribute (TiXmlAttribute* a) { this->attribute = a; }
};
#endif

class CXmlParser
{
    public:
        ~CXmlParser ();
        static CXmlParser* instance ();

        bool Load ();
        bool Dump ();
        //bool Dump2 (TiXmlElement* parent, TiXmlElement* node);
        bool Dump2 (CXmlNode* root, CXmlNode* node);
        bool Dump3 ();

        bool DumpXML (CXmlNode* root);
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
