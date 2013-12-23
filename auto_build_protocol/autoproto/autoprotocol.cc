
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "autoprotocol.h"

#include "tinyxml.h"
#include "tinystr.h"

using namespace std;

bool LoadXml (VECTORPROTOCOL* vProtocol, string& fName)
{
    try {
        TiXmlDocument* doc = new TiXmlDocument (fName.c_str ());
        doc->LoadFile ();
        TiXmlElement* rpc = doc->RootElement ();
        #ifdef DEBUG
        cout << rpc->Value () << endl;
        #endif

        // <Protocol> </Protocol>
        TiXmlElement* protocol = rpc->FirstChildElement ();
        for (; protocol; protocol = protocol->NextSiblingElement ())
        {
            CProtocol cpl;
            TiXmlAttribute* protocol_attr = protocol->FirstAttribute ();
            while (protocol_attr) {
                if (protocol_attr->Name() == string("name"))
                    cpl.name = protocol_attr->Value ();
                else if (protocol_attr->Name() == string("number"))
                    cpl.number = protocol_attr->Value ();
                else if (protocol_attr->Name() == string("handler"))
                    cpl.handler = protocol_attr->Value ();
                else if (protocol_attr->Name() == string("return_protocol"))
                    cpl.return_protocol = protocol_attr->Value ();
                else if (protocol_attr->Name() == string("file"))
                    cpl.file = protocol_attr->Value ();
                else if (protocol_attr->Name() == string("note"))
                    cpl.note = protocol_attr->Value ();

                #ifdef DEBUG
                cout << " " << protocol_attr->Name() << "=" << protocol_attr->Value();
                #endif
                protocol_attr = protocol_attr->Next ();
            }
            #ifdef DEBUG
            cout << endl;
            #endif

            // <Structure> </Structure>
            TiXmlElement* structure = protocol->FirstChildElement ();
            for (; structure; structure = structure->NextSiblingElement ())
            {
                TiXmlAttribute* structure_attr = structure->FirstAttribute ();
                while (structure_attr) {
                    if (structure_attr->Name() == string ("name"))
                        cpl.structure.name = structure_attr->Value ();
                    else if (structure_attr->Name() == string ("constructor"))
                        cpl.structure.ishas_cons = structure_attr->Value ();
                    else if (structure_attr->Name() == string ("operator"))
                        cpl.structure.ishas_op = structure_attr->Value ();
                    else if (structure_attr->Name() == string ("note"))
                        cpl.structure.note = structure_attr->Value ();

                    #ifdef DEBUG
                    cout << " " << structure_attr->Name() << "=" << structure_attr->Value();
                    #endif
                    structure_attr = structure_attr->Next ();
                }
                #ifdef DEBUG
                cout << endl;
                #endif

                // <Member> </Member>
                TiXmlElement* member = structure->FirstChildElement ();
                for (; member; member = member->NextSiblingElement ())
                {
                    CMember cmr;
                    TiXmlAttribute* member_attr = member->FirstAttribute ();
                    while (member_attr) {
                        if (member_attr->Name() == string("name"))
                            cmr.name = member_attr->Value ();
                        else if (member_attr->Name() == string("type"))
                            cmr.type = member_attr->Value ();
                        else if (member_attr->Name() == string("typename"))
                            cmr.typen = member_attr->Value ();
                        else if (member_attr->Name() == string("note"))
                            cmr.note = member_attr->Value ();
                        else if (member_attr->Name() == string("size"))
                            cmr.size = member_attr->Value ();

                        #ifdef DEBUG
                        cout << " " << member_attr->Name() << "=" << member_attr->Value();
                        #endif
#if 1
                        string sEnum = "enum";
                        if (member_attr->Value() == sEnum) {
                            TiXmlElement* enumeration = member->FirstChildElement ();
                            for (; enumeration; enumeration = enumeration->NextSiblingElement()) {

                                TiXmlAttribute* enumeration_attr = enumeration->FirstAttribute();
                                CEnum cem;
                                while (enumeration_attr) {
                                    if (enumeration_attr->Name() == string("name"))
                                        cem.name = enumeration_attr->Value ();
                                    else if (enumeration_attr->Name() == string("number"))
                                        cem.number = enumeration_attr->Value ();
                                    else if (enumeration_attr->Name() == string("note"))
                                        cem.note = enumeration_attr->Value ();

                                    #ifdef DEBUG
                                    cout << " " << enumeration_attr->Name() << "=" << enumeration_attr->Value();
                                    #endif
                                    enumeration_attr = enumeration_attr->Next();
                                }
                                cmr.vec_enum.push_back (cem);
                            }
                        }
#endif
                        member_attr = member_attr->Next ();
                    }
                    cpl.structure.vec_member.push_back (cmr);
                    #ifdef DEBUG
                    cout << endl;
                    #endif
                }
            }
            vProtocol->push_back (cpl);
        }
        #ifdef DEBUG
        cout << endl;a
        #endif
    }
    catch (string& e) {
        return (false);
    }

    return (true);
}

void dumpNodes (VECTORPROTOCOL* vProtocol)
{
    VECTORPROTOCOL::iterator it;
    for (it = vProtocol->begin(); it != vProtocol->end(); it++)
    {
        cout << endl << "name=" << it->name << " number=" << it->number << 
        " handle=" << it->handler << " return_protocol=" << it->return_protocol <<
        " file=" << it->file << " note=" << it->note;

        cout << endl << "\tstructure.name=" << it->structure.name << " ishas_cons=" <<
        it->structure.ishas_cons << " ishas_op=" << it->structure.ishas_op <<
        " note=" << it->structure.note;

        VECTORMEMBER::iterator itm;
        for (itm = it->structure.vec_member.begin();  itm != it->structure.vec_member.end(); itm++)
        {
            cout << endl << "\t\tmember.name=" << itm->name << " type=" << itm->type <<
            " typename=" << itm->typen << " size=" << itm->size << " note=" << itm->note;
#if 1
            if (itm->type == string("enum"))
            {
                VECTORENUM::iterator ite;
                for (ite = itm->vec_enum.begin(); ite != itm->vec_enum.end(); ite++)
                    cout << endl << "\t\t\tenum.name=" << ite->name << " number=" << ite->number << \
                    " note=" << ite->note;
            }
#endif
        }
    }
    cout << endl;
}

void cleanNodes (VECTORPROTOCOL* vProtocol)
{
    VECTORPROTOCOL::iterator it;
    for (it = vProtocol->begin(); it != vProtocol->end(); it++)
    {
        VECTORMEMBER::iterator itm;
        for (itm = it->structure.vec_member.begin();  itm != it->structure.vec_member.end(); itm++)
        {
            if (itm->type == string("enum"))
                itm->vec_enum.clear ();
        }
        it->structure.vec_member.clear ();
    }
    vProtocol->clear ();
}

bool autoBuildProtocol (string& sName, string& sNumber, bool return_protocol, string& sNote)
{
    string content, tmpstr, chkcontent;
    content.clear ();
    if (sNumber == "auto")
        content = "\t" + sName + ", //" + sNote;
    else 
        content = "\t" + sName + "=" + sNumber + ", //" + sNote;
    chkcontent = content;
    replace (string ("protocol.h"), string("};"), content, chkcontent, false, false);

    if (return_protocol) {
        tmpstr = sName;
        content.clear();
        chkcontent.clear();
        content = "\t" + tmpstr.replace (0, 1, "S") + ",";
        chkcontent = content;
    }
    replace (string ("protocol.h"), string("};"), content, chkcontent, false, false);

    return (true);
}

bool autoBuildHandler (string& pName, string& sFile, string& sHandler)
{
    string cppfile = sHandler + ".cpp";
    fstream ofs;
    int length = 0;
    if (sFile == string ("auto")) {
        cppfile = "handler/" + sHandler + ".cpp";
    }
    else {
        cppfile = "handler/" + sFile;
    }
    ofs.open (cppfile.c_str(), fstream::out | fstream::app);

    ofs.seekg (0, ofs.end);
    length = ofs.tellg ();
    ofs.seekg (0, ofs.beg);

    if (length == 0) {
        ofs << "#include \"HandleMessage.h\"" << endl;
        ofs << "#include \"protocol.h\"" << endl;
        ofs << "#include \"Buf.h\"" << endl << endl;
    }

#if 1
    // handleX
    string handlecontent = "void CHandleMessage::" + sHandler + "(Buf* p)";
    if (!checkcontent (cppfile, handlecontent)) {
        ofs << endl << handlecontent << endl;
        ofs << "{" << endl;
        ofs << "    //TODO:" << endl;
        ofs << "}" << endl;
    }
#endif 
    ofs.close ();

    // MSGHANDLE
    string msghandlefile = "handler/MSGHANDLE";
    string msghandlecontent =  "    MSGNAME (" + pName + ", " + sHandler + ");";
    if (!checkcontent (msghandlefile, msghandlecontent)) {
        ofs.open ("handler/MSGHANDLE", fstream::out | fstream::app);
        ofs.seekg (0, ofs.end);
        ofs << msghandlecontent << endl;
        ofs.close ();
    }
    return (true);
}

bool autoBuildMakefile (string& sFile)
{
    string sMakefile = "Makefile";
    fstream ifs, ofs;
    char buf[1024];
    string line;
    size_t found;
    ifs.open (sMakefile.c_str(), fstream::in);
    ofs.open (".Makefile.tmp", fstream::out | fstream::app);
    while (!ifs.eof ()) {
        ifs.getline (buf, 1024);
        line = buf;

        ofs << line << endl;
        if ((found = line.find ("virtual.o")) != std::string::npos) {
            ofs << TAB3 << "handler/" << sFile << ".o \\" << endl;
        }
    }

    ifs.close ();
    ofs.close ();

    system ("rm -rf Makefile");
    system ("mv .Makefile.tmp Makefile");
    return (true);
}

bool checkcontent (string sFile, string content)
{
    fstream ifs;
    char buffer[1024];
    string line;
    size_t found;

    ifs.open (sFile.c_str(), fstream::in);
    while (!ifs.eof ()) {
        ifs.getline (buffer, 1024);
        line = buffer;

        if ((found = line.find (content.c_str())) != std::string::npos) {
            ifs.close ();
            return (true);
        }
    }
    ifs.close ();

    return (false);
}

bool replace (string sFile, string sFlag, string content, string chkcontent, bool iscontinue, bool seek)
{
    fstream ifs, ofs;
    char buffer[1024];
    string line;
    size_t found;
    bool Flagcontinue = true; 
    string sDstFile = "." + sFile + ".tmp";

    if (checkcontent (sFile, chkcontent)) {
        #ifdef DEBUG
        cout << "[DEBUG-INFO]: '" << chkcontent << "' exsist in the file '" << sFile << "'" << endl;
        #endif
        return (false);
    }

    ifs.open (sFile.c_str(), fstream::in);
    ofs.open (sDstFile.c_str(), fstream::out | fstream::app);

    while (!ifs.eof ()) {
        ifs.getline (buffer, 1024);
        line = buffer;
#if 1
        if (seek) {
            ofs << line << endl;
            if (((found = line.find (sFlag.c_str())) != std::string::npos) && (Flagcontinue)) {
                ofs << content << endl;
                if (iscontinue == false)
                    Flagcontinue = false;
                    
            }
        }
        else {
            if (((found = line.find (sFlag.c_str())) != std::string::npos) && (Flagcontinue)) {
                ofs << content << endl;
                if (iscontinue == false)
                    Flagcontinue = false;
            }
            ofs << line << endl;
        }
#endif
    }

    ifs.close ();
    ofs.close ();

    string tmpstr1, tmpstr2;
    tmpstr1 = "rm -rf " + sFile;
    tmpstr2 = "mv " + sDstFile + " " + sFile;
    //cout << "tmpstr1 = " << tmpstr1 << endl;
    //cout << "tmpstr2 = " << tmpstr2 << endl;
#if 1
    system (tmpstr1.c_str());
    system (tmpstr2.c_str());
#endif
    return (true);
}

bool autoBuild (VECTORPROTOCOL* vProtocol)
{
    VECTORPROTOCOL::iterator it;
    string tmpFile, content;
    for (it = vProtocol->begin(); it != vProtocol->end(); it++)
    {
        /*
        cout << endl << "name=" << it->name << " number=" << it->number << 
        " handle=" << it->handler << " return_protocol=" << it->return_protocol <<
        " file=" << it->file << " note=" << it->note;
        */
        tmpFile = it->file;
        tmpFile.replace (tmpFile.size() - 4, 4, "");
        autoBuildProtocol (it->name, it->number, it->return_protocol=="Y"?true:false, it->note); 
        autoBuildHandler  (it->name, it->file, it->handler);
        //autoBuildMakefile (it->file=="auto"?it->handler:tmpFile);
        content.clear ();
        content = TAB3;
        if (it->file == "auto")
            content += "handler/" + it->handler;
        else
            content += "handler/" + tmpFile;
        content += ".o \\";
        replace (string ("Makefile"), string("virtual.o"), content, content, false, true);

        /*
        cout << endl << "\tstructure.name=" << it->structure.name << " ishas_cons=" <<
        it->structure.ishas_cons << " ishas_op=" << it->structure.ishas_op <<
        " note=" << it->structure.note;
        */

        VECTORMEMBER::iterator itm;
        string members;
        string enums;
        string enumscontent;
        if ((it->structure.ishas_cons == "Y") || (it->structure.ishas_op == "Y"))
            members = "\n//" + it->structure.note + "\nstruct " + it->structure.name + " {\nprivate:\n";
        else
            members = "\n//" + it->structure.note + "\nstruct " + it->structure.name + " {\n";
        for (itm = it->structure.vec_member.begin();  itm != it->structure.vec_member.end(); itm++)
        {
            /*
            cout << endl << "\t\tmember.name=" << itm->name << " type=" << itm->type <<
            " size=" << itm->size << " note=" << itm->note;
            */
#if 1
            if (itm->type == "enum")
            {
                VECTORENUM::iterator ite;
                enums = "\n//" + itm->note + "\nenum " + itm->typen + " {\n";
                enumscontent = "enum " + itm->typen + " {";
                for (ite = itm->vec_enum.begin(); ite != itm->vec_enum.end(); ite++) {
                    /*
                    cout << endl << "\t\t\tenum.name=" << ite->name << " number=" << ite->number << \
                    " note=" << ite->note;
                    */
                    if (ite->number == "auto")
                        enums = enums + TAB1 + ite->name + ", //" + ite->note + "\n";
                    else
                        enums = enums + TAB1 + ite->name + "=" + ite->number + ", //" + ite->note + "\n";
                }
                members = members + TAB1 +  itm->type + SPACE1 + itm->typen + SPACE1 + itm->name + "; //" + itm->note + "\n";
            }
#endif
            else if (itm->type == "char")
                members = members + TAB1 +  itm->type + SPACE1 + itm->name + "[" + itm->size + "]; //" + itm->note + "\n";
            else
                members = members + TAB1 +  itm->type + SPACE1 + itm->name + "; //" + itm->note + "\n";
        }

        // autoBuildMethod
        if (it->structure.ishas_cons == "Y") {
            members += "public:\n";
            autoBuildCons (members, it->structure.name, &(it->structure.vec_member));
        }
        if (it->structure.ishas_op == "Y") {
            members += "public:\n";
            for (itm = it->structure.vec_member.begin();  itm != it->structure.vec_member.end(); itm++)
                autoBuildMethod (members, itm->name, itm->type, itm->typen);
        }

        members += "};\n";
        string check_members = "struct " + it->structure.name + " {";
        replace (string ("protocol.h"), string("// structs"), members, check_members, false, true);
        enums += "};\n";
        replace (string ("protocol.h"), string("// enums"), enums, enumscontent, false, true);

    }
    #ifdef DEBUG
    cout << endl;
    #endif
    return (true);
}

bool autoBuildCons (string& members, string structure_name, VECTORMEMBER* vec_member)
{
    VECTORMEMBER::iterator itm;
    string tmpstr = TAB1 + structure_name + "(";
    string charstr;

    for (itm = vec_member->begin(); itm != vec_member->end(); itm++) {
        if (itm->type == "enum")
            tmpstr += itm->type + SPACE1 + itm->typen;
        else if (itm->type == "char")
            tmpstr += itm->type + "*";
        else 
            tmpstr += itm->type;
   
        if ((itm + 1) == vec_member->end())
            tmpstr += SPACE1 + itm->name.substr (1);
        else
            tmpstr += SPACE1 + itm->name.substr (1) + ", "; 
    }
    tmpstr = tmpstr + ")\n" + TAB2 + ":";

    for (itm = vec_member->begin(); itm != vec_member->end(); itm++) {
        if (itm->type == "char")
            charstr = charstr + TAB2 + "memcpy (" + itm->name + ", " + itm->name.substr(1) + ", " + itm->size + ");\n";
        else {
            if ((itm + 1) == vec_member->end())
                tmpstr += itm->name + "(" + itm->name.substr (1) + ")";
            else
                tmpstr += itm->name + "(" + itm->name.substr (1) + "), ";
        }
    }
    tmpstr = tmpstr + "\n" + TAB1 + "{\n" + charstr + "\n" + TAB1 + "}\n";

    members += tmpstr;
}

bool autoBuildMethod (string& members, string member_name, string member_type, string member_typen)
{
    string tmp_member_name;
    //set method
    tmp_member_name = member_name;
    tmp_member_name.replace (0, 1, "set");
    if (member_type == "enum")
        members = members + TAB1 + "void " + tmp_member_name + " (enum " + member_typen + " " + member_name.substr(1) + ")\n" + TAB1 +
            "{\n" + TAB2 + member_name + "=" + member_name.substr(1) + ";\n" + TAB1 + "};\n";
    else if (member_type == "char")
        ;
    else
        members = members + TAB1 + "void " + tmp_member_name + " (" + member_type + " " + member_name.substr(1) + ")\n" + TAB1 +
            "{\n" + TAB2 + member_name + "=" + member_name.substr(1) + ";\n" + TAB1 + "};\n";

    //get method
    tmp_member_name = member_name;
    tmp_member_name.replace (0, 1, "get");
    if (member_type == "enum")
        members = members + TAB1 + member_type + " " + member_typen + " " + tmp_member_name + "(void)\n" + TAB1 +
            "{\n" + TAB2 + "return(" + member_name + ");\n" + TAB1 + "};\n";
    else if (member_type == "char")
        ;
    else
        members = members + TAB1 + member_type + " " + tmp_member_name + " (void)\n" + TAB1 +
            "{\n" + TAB2 + "return(" + member_name + ");\n" + TAB1 + "};\n";

    return (true);
}

int main (int argc, char** argv)
{
    VECTORPROTOCOL vProtocol;
    string sFile;

    if (argc > 2) {
        cout << "usage: " << argv[0] << " <xml config file>." << endl;
        return (1);
    }
    else if (argc == 2) {
        sFile = argv[1];
    }
    else {
        sFile = "./rpc.xml";
    }

    cout << "Load xml file: '" << sFile << "'......" << endl;

    if (!LoadXml (&vProtocol, sFile)) {
        cout << "can't load xml, please check it.\n";
        return (1);
    }
    cout << "[success]" << endl << endl;

    #ifdef DEBUG
    dumpNodes (&vProtocol);
    #endif

    cout << "Auto building cpp file......" << endl;
    replace (string ("protocol.h"), string("};"), string("// structs"), string("// structs"), false, true);
    replace (string ("protocol.h"), string("};"), string("// enums"), string("// enums"), false, true);
    replace (string ("protocol.h"), string("#pragma pack(1)"), string("#include <string.h>"), string("#include <string.h>"), false, false);
    autoBuild (&vProtocol);
    cout << "[success]" << endl;

    cleanNodes (&vProtocol);
    return (0);
}
