
#include <iostream>
#include <string>
#include <stdlib.h>

#include "tinyxml.h"
#include "tinystr.h"
#include "xml_parser.h"

using namespace std;

CXmlParser* CXmlParser::pInstance = NULL;

CXmlParser::CXmlParser (string sFile)
{
    m_xmlFile = sFile;
}

CXmlParser* CXmlParser::instance ()
{
    if (pInstance == NULL)
    {
        pInstance = new CXmlParser ("./resource_struct.xml");
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

string CXmlParser::getResourceByEncoding (string res_encoding, string t_encoding, string refer_encoding)
{
    return (getResource (res_encoding, t_encoding, refer_encoding, 1));
}

string CXmlParser::getResourceByName (string s_name, string t_name, string r_name)
{
    return (getResource (s_name, t_name, r_name, 0));
}

string CXmlParser::getResource (string s1, string s2, string s3, int flags)
{
    try {
        TiXmlElement* root = m_doc->RootElement ();
        
        TiXmlElement* resource = root->FirstChildElement ();
        TiXmlAttribute* resource_name;
        TiXmlAttribute* resource_encoding;
        while (resource)
        {
            resource_name = resource->FirstAttribute ();
            resource_encoding = resource->LastAttribute ();

            if (flags == 1) 
            {
                if (s1 != resource_encoding->Value ())
                {
                    resource = resource->NextSiblingElement ();
                    continue;
                }
            }
            else if (flags == 0)
            {
                if (s1 != resource_name->Value ())
                {
                    resource = resource->NextSiblingElement ();
                    continue;
                }
            }
/////
            
            TiXmlElement* type = resource->FirstChildElement ();
            TiXmlAttribute* type_name;
            TiXmlAttribute* type_encoding;

            while (type)
            {
                type_name = type->FirstAttribute ();
                type_encoding = type->LastAttribute ();

                if (flags == 1) 
                {
                    if (s2 != type_encoding->Value ())
                    {
                        type = type->NextSiblingElement ();
                        continue;
                    }
                }
                else if (flags == 0)
                {
                    if (s2 != type_name->Value ())
                    {
                        type = type->NextSiblingElement ();
                        continue;
                    }
                }

                //////
                TiXmlElement* reference = type->FirstChildElement ();
                TiXmlAttribute* reference_encoding = NULL;
                while (reference)
                {
                    reference_encoding = reference->LastAttribute ();

                    if (s3 == reference_encoding->Value ())
                    {
                        // found it
                        return (reference->FirstChild ()->Value ());
                    }
                    
                    TiXmlElement* siblingReference = reference;
                    reference = siblingReference->NextSiblingElement ();
                    if (reference == NULL)
                    {
                        //the end of reference node, loop exit
                        break;
                    }
                }
                ///////

                TiXmlElement* siblingType = type;
                type = siblingType->NextSiblingElement ();
                if (type == NULL)
                {
                    //the end of type node, loop exit
                    break;
                }
            }
/////
            TiXmlElement* siblingResource = resource;

            resource = siblingResource->NextSiblingElement ();
            if (resource == NULL)
            {
                //the end of resource node, program exit
                break;
            }

        }

    }
    catch (string& e) {
        return (NULL);
    }

    return (NULL);
}

bool CXmlParser::getEncodingByResource (string png_name, \
        string& res_encoding, string& t_encoding, string& refer_encoding)
{
    try {
        TiXmlElement* root = m_doc->RootElement ();
        
        TiXmlElement* resource = root->FirstChildElement ();
        TiXmlAttribute* resource_encoding;
        while (resource)
        {
            resource_encoding = resource->LastAttribute ();

            res_encoding = resource_encoding->Value();
/////
            
            TiXmlElement* type = resource->FirstChildElement ();
            TiXmlAttribute* type_encoding;

            while (type)
            {
                type_encoding = type->LastAttribute ();
                t_encoding = type_encoding->Value ();

                ////
                TiXmlElement* reference = type->FirstChildElement ();
                TiXmlAttribute* reference_encoding;
                while (reference)
                {
                    reference_encoding = reference->LastAttribute ();
                    refer_encoding = reference_encoding->Value ();

                    if (png_name == reference->FirstChild()->Value())
                    {
                        // found it
                        return (true);
                    }

                    TiXmlElement* siblingReference = reference;
                    reference = siblingReference->NextSiblingElement ();
                    if (reference == NULL)
                    {
                        //the end of reference node, loop exit
                        break;
                    }
                }
                ////

                TiXmlElement* siblingType = type;
                type = siblingType->NextSiblingElement ();
                if (type == NULL)
                {
                    //the end of type node, loop exit
                    break;
                }
            }
/////
            TiXmlElement* siblingResource = resource;

            resource = siblingResource->NextSiblingElement ();
            if (resource == NULL)
            {
                //the end of resource node, program exit
                break;
            }

        }

    }
    catch (string& e) {
        return (false);
    }

    res_encoding = "";
    t_encoding = "";
    refer_encoding = "";

    return (false);
}

bool CXmlParser::Dump ()
{
    try {
        TiXmlElement* root = m_doc->RootElement ();
        
        cout << "root=" << root->Value () << endl;

        TiXmlElement* resource = root->FirstChildElement ();
        TiXmlAttribute* resource_name;
        TiXmlAttribute* resource_encoding;
        while (resource)    /////// resource node
        {
            resource_name = resource->FirstAttribute ();
            resource_encoding = resource->LastAttribute ();

            cout << "\n" << resource_name->Name () << ": " << resource_name->Value ()<<
            " " << resource_encoding->Name () << ": " << resource_encoding->Value () << endl;;

//
            
            TiXmlElement* type = resource->FirstChildElement ();
            TiXmlAttribute* type_name;
            TiXmlAttribute* type_encoding;

            while (type)    /////// type node
            {
                type_name = type->FirstAttribute ();
                type_encoding = type->LastAttribute ();
                cout << "\t" << type_name->Name () << ": " << type_name->Value () << 
                " " << type_encoding->Name () << ": " << type_encoding->Value () << endl;
#if 1
                //
                TiXmlElement* reference = type->FirstChildElement ();
                TiXmlAttribute* reference_name;
                TiXmlAttribute* reference_encoding;
                while (reference)   /////// reference node
                {
                    reference_name = reference->FirstAttribute ();
                    reference_encoding = reference->LastAttribute ();
                    cout << "\t\t" << reference_name->Name () << ": " << reference_name->Value () << 
                    " " << reference_encoding->Name () << ": " << reference_encoding->Value () << endl;
                    cout << "\t\t\t" << reference->FirstChild ()->Value () << endl;

                    TiXmlElement* siblingReference = reference;
                    reference = siblingReference->NextSiblingElement ();
                    if (reference == NULL)
                    {
                        //cout << "\t\tthe end of reference node, loop exit"<< endl;
                        break;
                    }
                }
                //
#endif
                TiXmlElement* siblingType = type;
                type = siblingType->NextSiblingElement ();
                if (type == NULL)
                {
                    //cout << "\tthe end of type node, loop exit"<< endl;
                    break;
                }
            }
//
            TiXmlElement* siblingResource = resource;

            resource = siblingResource->NextSiblingElement ();
            if (resource == NULL)
            {
                //cout << "the end of resource node, program exit\n" << endl;
                break;
            }

        }
    }
    catch (string& e) {
        return (false);
    }

    cout << endl;
    return true;
}
