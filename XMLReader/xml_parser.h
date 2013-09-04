
// written by fU9ANg
// bb.newlife@gmail.com

#ifndef _XML_PARSER_H
#define _XML_PARSER_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "tinyxml.h"
#include "tinystr.h"

using namespace std;

// PROTOTYPES
class CXmlNode;
class CXmlAttribute;
class CXmlParser;

class CXmlNode
{
private:
    string name;
    string text;
    TiXmlElement*  element;
    CXmlNode*      parent;

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

    void   setName (string& s) { this->name = s; }
    void   setValue (string& v) { this->value = v; }
    void   setXmlAttribute (TiXmlAttribute* a) { this->attribute = a; }

    bool   getBoolValue ();
    int    getIntValue ();
    int    getIntValue (int min, int max);
    float  getFloatValue ();
    float  getFloatValue (float min, float max);
    string getRestrictedValue ();
};

class CXmlParser
{
    public:
        ~CXmlParser ();
        static CXmlParser* instance ();

        bool Load ();
        bool Init ();

        bool DumpXML (CXmlNode* root);

    private:
        bool Loading (CXmlNode* root, CXmlNode* node);
        CXmlParser (string sFile);
        static CXmlParser* pInstance;
        TiXmlDocument* m_doc;
        string m_xmlFile;
};

#define XMLPARSER   CXmlParser::instance()

#endif  //_XML_PARSER_H
