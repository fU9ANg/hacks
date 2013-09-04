
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <cstdlib>
#include <stdexcept>

#include "tinyxml.h"
#include "tinystr.h"
#include "xml_parser.h"
#include "converType.h"

using namespace std;

CXmlParser* CXmlParser::pInstance = NULL;

/*
=====================
  CXmlAttribute::getBoolValue
=====================
*/
bool CXmlAttribute::getBoolValue ()
{
    if ((this->value == "true") ||
        (this->value == "TRUE") ||
        (this->value == "Ture") ||
        (this->value == "1"))
    {
        return (true);
    }
    else if ((this->value == "false") ||
             (this->value == "FALSE") ||
             (this->value == "False") ||
             (this->value == "0"))
    {
        return (false);
    }
    else
    {
        throw runtime_error ("Not a valid bool value (true or false): " + \
            getName() + ": " + value);
    }
}

int CXmlAttribute::getIntValue ()
{
    return (strToInt (value));
}

int CXmlAttribute::getIntValue (int min, int max)
{
    int i = strToInt (value);
    if (i < min || i > max)
    {   
        throw runtime_error ("Xml Attribute integer out of range: " + \
            getName () + ": " + value);
    }

    return (i);
}

float CXmlAttribute::getFloatValue ()
{
    return (strToFloat (value));
}

float CXmlAttribute::getFloatValue (float min, float max)
{
    float f = strToFloat (value);
    if (f < min || f > max)
    {
        throw runtime_error ("Xml Attribute float out of range: " + \
            getName () + ": " + value);
    }

    return (f);
}

string CXmlAttribute::getRestrictedValue ()
{
    const string allowedChars = "abcdefghijklmnopqrstuvwxyz1234567890._-/";

    for (unsigned int i=0; i<value.size(); i++) {
        if (allowedChars.find (value[i]) == string::npos) {
            throw runtime_error (\
                string ("The string \"" + value + "\" contains a character that is not allowed: \"") +
                value[i] + "\"\nFor portability reasons the only allowed characters in this field are: " +
                "\"" + allowedChars + "\"");
        }
    }

    return (value);
}

CXmlParser::CXmlParser (string sFile)
{
    m_xmlFile = sFile;
}

CXmlParser* CXmlParser::instance ()
{
    if (pInstance == NULL)
    {
        pInstance = new CXmlParser ("./xml/resource_struct.xml");
        if (pInstance->Load () == false)
        {
            cout << "[error] load xml file" << endl;
        }
    }
    return (pInstance);
}

bool CXmlParser::Load ()
{
    try {
        m_doc = new TiXmlDocument (m_xmlFile.c_str());
        m_doc->LoadFile ();
    }
    catch (string& e) {
        return (false);
    }

    return (true);
}

bool CXmlParser::Init ()
{
    TiXmlElement* root = m_doc->RootElement ();
    CXmlNode* rootXmlNode  = new CXmlNode (root);

    Loading (rootXmlNode, rootXmlNode);

    cout << endl << "\n\n\n[------- DUMPING XML NODE INFORMATION -------]" << endl;
    DumpXML (rootXmlNode);

    return (true);
}

bool CXmlParser::DumpXML (CXmlNode* root)
{
    vector<CXmlNode*>::iterator it;
    vector<CXmlAttribute*>::iterator ait;
    for (it=root->children.begin(); it != root->children.end(); it++) {
        cout << "\nName: " << (*it)->getName () << endl;
        cout << "Text: " << (*it)->getText () << endl;
        cout << "[ATTRIBUTES]" << endl;

        for (ait=(*it)->attributes.begin(); ait != (*it)->attributes.end (); ait++) {
            cout << (*ait)->getName () << "=" << (*ait)->getValue () << endl;
        }
        DumpXML (*it);
    }

    return (true);
}

bool CXmlParser::Loading (CXmlNode* parent, CXmlNode* node)
{
    TiXmlElement*   tempNode    = NULL;
    TiXmlAttribute* attribute   = NULL;

    for (tempNode=node->getXmlElement(); tempNode; \
         tempNode=tempNode->NextSiblingElement ())
    {
        CXmlNode* XMLNode = new CXmlNode (tempNode);
            XMLNode->setParent (parent);
            parent->children.push_back (XMLNode);

        // check node name
        cout << endl << "[Name]" << tempNode->Value ();
        string tmpName = tempNode->Value ();
        XMLNode->setName (tmpName);

        // check node text
        if (tempNode->GetText ()) {
            cout << endl << "[Value]" << tempNode->GetText ();
            string tmpText = tempNode->GetText ();
            XMLNode->setText (tmpText);
        }

        // check node attribute
        attribute = tempNode->FirstAttribute ();
        while (attribute)
        {
            cout << "\n[ATTRIBUTE]" << attribute->Name () << ": " << attribute->Value () << endl;
            CXmlAttribute *Attribute = new CXmlAttribute (attribute);
            string tName = attribute->Name ();
            Attribute->setName (tName);
            string tValue = attribute->Value ();
            Attribute->setValue (tValue);
            XMLNode->attributes.push_back (Attribute);
            attribute = attribute->Next ();
        } 
        
        // check node children
        Loading (XMLNode, new CXmlNode(tempNode->FirstChildElement ()));
    }

    return (true);
}
