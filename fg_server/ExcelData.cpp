
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>

#include "pugixml.hpp"
#include "pugiconfig.hpp"
#include "ExcelData.h"

using namespace pugi;
using namespace std;

void ExcelField::dump ()
{
    vector<nameValue>::iterator itPro;
    for (itPro = Properties.begin(); itPro != Properties.end(); itPro++) {
        cout << " " << itPro->first << "=" <<itPro->second;
    }
    std::cout << endl;
}

int ExcelField::convert ()
{
    vector<nameValue>::iterator itPro;
    for (itPro = Properties.begin(); itPro != Properties.end(); itPro++) {
        //cout << " " << itPro->first << "=" <<itPro->second;
        if (itPro->first == "name")
            _name = itPro->second;
        else if (itPro->first == "toName" || itPro->first == "toname")
            _toName = itPro->second;
        else if (itPro->first == "dataType")
            _dataType = itPro->second;
        else if (itPro->first == "localizable")
            _localizable = itPro->second;
        else if (itPro->first == "defaultValue")
            _defaultValue = itPro->second;
        else if (itPro->first == "useTip")
            _useTip = itPro->second;
        else if (itPro->first == "fields")
            _fields = itPro->second;
        else if (itPro->first == "type")
            _type = itPro->second;
    }
    return (0);
}

void ExcelSheet::dump ()
{
    cout << "Sheets:";

    vector<nameValue>::iterator itProperty;
    for (itProperty = Properties.begin(); itProperty != Properties.end(); itProperty++) {
        cout << " " << itProperty->first << "=" <<itProperty->second;
    }
    std::cout << endl;

    vector<ExcelField>::iterator itField;
    for (itField = Fields.begin(); itField != Fields.end(); itField++) {
        cout << "\t";
        itField->dump ();
    }
}

int ExcelSheet::convert ()
{
    vector<nameValue>::iterator itProperty;
    for (itProperty = Properties.begin(); itProperty != Properties.end(); itProperty++) {
        if (itProperty->first == "excelName")
            _excelName = itProperty->second;
        else if (itProperty->first == "name")
            _name = itProperty->second;
        else if ((itProperty->first == "toName") || (itProperty->first == "toname"))
            _toName = itProperty->second;
        else if (itProperty->first == "useTip")
            _useTip = itProperty->second;
    }

    vector<ExcelField>::iterator itField;
    for (itField = Fields.begin(); itField != Fields.end(); itField++) {
        itField->convert ();
    }
    return (0);
}

void ExcelTable::dumpSheets ()
{
    vector<ExcelSheet>::iterator itSheet;
    for (itSheet = Sheets.begin(); itSheet != Sheets.end(); itSheet++) {
        itSheet->dump ();
    }
}

int ExcelTable::convertSheets ()
{
    vector<ExcelSheet>::iterator itSheet;
    for (itSheet = Sheets.begin(); itSheet != Sheets.end(); itSheet++) {
        itSheet->convert ();
    }

    return (0);
}

//////////////////////////////////////////////////////////////////////////////////////
//
int ExcelTable::product ()
{
    string sIncludeFile, sSourceFile;
    sIncludeFile = "";
    sSourceFile  = "";

    //
    string sCode = "";
    vector<ExcelSheet>::iterator itSheet;
    for (itSheet = Sheets.begin(); itSheet != Sheets.end(); itSheet++) {
        sCode += itSheet->productSheetDefine ();
    }
    sCode = STRUCTURE_INCLUDES + sCode;
    sSourceFile += sCode;
    //printf ("%s", sCode.c_str());
    //
    sIncludeFile += STRUCTURE_IFNDEF_DEFINE;

    for (itSheet = Sheets.begin(); itSheet != Sheets.end(); itSheet++) {
        sCode = "";
        //printf ("\n---------------product-------------\n");
        sIncludeFile += STRUCTURE_CLASS_DEFINE;
        sCode = itSheet->productSheetDataInH ();
        sIncludeFile += sCode;
        //printf ("%s", sCode.c_str());
        sCode = itSheet->productSheetInH ();
        sCode = itSheet->productTryFindByPKInH (sCode);
        sCode = itSheet->productFindByPKInH (sCode);
        sIncludeFile += sCode;
        itSheet->productMultiKeyINH (sIncludeFile);
        itSheet->productUniqueINH (sIncludeFile);
        //printf ("%s", sCode.c_str());


        sCode = itSheet->productSheetData ();
        sSourceFile += sCode;
        //printf ("%s", sCode.c_str());
        sCode = itSheet->productSheetGetRow ();
        sSourceFile += sCode;
        //printf ("%s", sCode.c_str());
        sCode = itSheet->productSheetGetAll ();
        sSourceFile += sCode;
        //printf ("%s", sCode.c_str());
        sCode = itSheet->productSheetInit ();
        sSourceFile += sCode;
        //printf ("%s", sCode.c_str());
        sCode = itSheet->productSheetInitLink ();
        sSourceFile += sCode;
        //printf ("%s", sCode.c_str());
#if 1
        sCode = itSheet->productTryFindByPK ();
        sSourceFile += sCode;
        //printf ("%s", sCode.c_str());
        sCode = itSheet->productFindByPK ();
        sSourceFile += sCode;
#endif
        //
        sCode = itSheet->productSheetDump ();
        sSourceFile += sCode;

        itSheet->productMultiKey (sSourceFile);
        itSheet->productUnique (sSourceFile);
        itSheet->productAssignInFunction (sSourceFile);
    }


    //
    sCode = "";
    for (itSheet = Sheets.begin(); itSheet != Sheets.end(); itSheet++) {
        sCode += itSheet->productInitSheets ();
    }
    sCode = STRUCTURE_INITSHEETS_BEGIN + sCode + STRUCTURE_INITSHEETS_END;
    sSourceFile += sCode;
    //printf ("%s", sCode.c_str());


    sIncludeFile += STRUCTURE_ENDIF;

    ///
    ofstream outfile ("Sheet.h", std::ofstream::binary);
    outfile.write (sIncludeFile.c_str (), sIncludeFile.size ());
    outfile.close ();

    outfile.open ("Sheet.cpp", std::ofstream::binary);
    outfile.write (sSourceFile.c_str(), sSourceFile.size ());
    outfile.close ();

    //printf ("---------------------------------------------------\n");
    //printf ("%s", sIncludeFile.c_str ());
    //printf ("+++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    //printf ("%s", sSourceFile.c_str ());

    return (0);
}


///////////////////////////////// ASSIGNUTILS /////////////////////////////
string AssignUtils::getInitKey (string& sClassName, const char* fmt, ...)
{
    va_list ap;
    string  type;
    string  name;
    string  str1, str2;

    va_start (ap, fmt);
    while (*fmt) {
        if (*fmt == '%' && *(fmt+1) == 's') {
            if (type.empty ()) {
                type = va_arg (ap, char*);
            }
            else {
                name = va_arg (ap, char*);

                str1 = type;
                str2 = name;

                type.clear ();
            }
        }

        fmt++;
    }
    va_end (ap);

    string sCode = STRUCTURE_INIT_KEY_ONLY;
    sCode = ExcelUtils::findAndReplace (sCode, "yyyyy", str1);
    sCode = ExcelUtils::findAndReplace (sCode, "zzzzz", str2);

    //printf ("%s", sCode.c_str());

    return (sCode);
}

string AssignUtils::getInitMultiKey (string& sClassName, const char* fmt, ...)
{
    va_list ap;
    string  type;
    string  name;
    string  str1, str2, str3, str4;

    str2 = "_SheetIndexType" + sClassName;
    va_start (ap, fmt);
    while (*fmt) {
        if (*fmt == '%' && *(fmt+1) == 's') {
            if (type.empty ()) {
                type = va_arg (ap, char*);
            }
            else {
                name = va_arg (ap, char*);

                str1 += name + "_";
                str2 += name;
                str3 += "d[i]." + name + ",";
                type.clear ();
            }
        }

        fmt++;
    }
    va_end (ap);


    str1 = str1.substr (0, str1.size() -1);
    str3 = str3.substr (0, str3.size() -1);
    string sCode = STRUCTURE_INIT_KEY_MULTI;
    sCode = ExcelUtils::findAndReplace (sCode, "aaaaa", str1);
    sCode = ExcelUtils::findAndReplace (sCode, "bbbbb", str2);
    sCode = ExcelUtils::findAndReplace (sCode, "ccccc", str3);

    //printf ("%s", sCode.c_str());

    return (sCode);
}

string AssignUtils::getInitPK (string& sClassName, const char* fmt, ...)
{
    va_list ap;
    string  type;
    string  name;
    string  str1, str2, str3, str4;

    va_start (ap, fmt);
    while (*fmt) {
        if (*fmt == '%' && *(fmt+1) == 's') {
            if (type.empty ()) {
                type = va_arg (ap, char*);
            }
            else {
                name = va_arg (ap, char*);

                str1 = type;
                str2 = name;

                if (type == "int") {
                    str3 = "%d";
                    str4 = "";
                }
                else if (type == "string") {
                    str3 = "%s";
                    str4 = ".c_str()";
                }

                type.clear ();
            }
        }

        fmt++;
    }
    va_end (ap);

    string sCode = STRUCTURE_INIT_PK;
    sCode = ExcelUtils::findAndReplace (sCode, "yyyyy", str1);
    sCode = ExcelUtils::findAndReplace (sCode, "zzzzz", str2);
    sCode = ExcelUtils::findAndReplace (sCode, "xxxxx", sClassName);
    sCode = ExcelUtils::findAndReplace (sCode, "aaaaa", str3);
    sCode = ExcelUtils::findAndReplace (sCode, "bbbbb", str4);

    //printf ("%s", sCode.c_str());

    return (sCode);
}

string AssignUtils::getInitUnique (string& sClassName, const char* fmt, ...)
{
    va_list ap;
    string  type;
    string  name;
    string  str1, str2, str3, str4, str5;

    str2 = "_SheetIndexType" + sClassName;
    va_start (ap, fmt);
    while (*fmt) {
        if (*fmt == '%' && *(fmt+1) == 's') {
            if (type.empty ()) {
                type = va_arg (ap, char*);
            }
            else {
                name = va_arg (ap, char*);

                str1 += name + "_";
                str2 += name;
                str3 += "d[i]." + name + ",";
                
                if (type == "int") {
                    str4 += name + "=%d,";
                    str5 += "d[i]." + name + ",";
                }
                else if (type == "string") {
                    str4 += name + "=%s,";
                    str5 += "d[i]." + name + ".c_str(),";
                }
                type.clear ();
            }
        }

        fmt++;
    }
    va_end (ap);


    str1 = str1.substr (0, str1.size() -1);
    str3 = str3.substr (0, str3.size() -1);
    str4 = str4.substr (0, str4.size() -1);
    str5 = str5.substr (0, str5.size() -1);
    string sCode = STRUCTURE_INIT_UNIQUE;
    sCode = ExcelUtils::findAndReplace (sCode, "aaaaa", str1);
    sCode = ExcelUtils::findAndReplace (sCode, "bbbbb", str2);
    sCode = ExcelUtils::findAndReplace (sCode, "ccccc", str3);
    sCode = ExcelUtils::findAndReplace (sCode, "xxxxx", sClassName);
    sCode = ExcelUtils::findAndReplace (sCode, "ddddd", str4);
    sCode = ExcelUtils::findAndReplace (sCode, "eeeee", str5);

    //printf ("%s", sCode.c_str());

    return (sCode);
}

///////////////////////////////// ASSIGNUTILS END /////////////////////////////

///////////////////////////////// UNIQUEUTILS /////////////////////////////
string UniqueUtils::getUniqueStruct (string& sClassName, const char* fmt, ...)
{
    va_list ap;
    string  type;
    string  name;
    string  str1, str2, str3, str4;

    sClassName = "_SheetIndexType" + sClassName;

    va_start (ap, fmt);
    while (*fmt) {
        if (*fmt == '%' && *(fmt+1) == 's') {
            if (type.empty ()) {
                type = va_arg (ap, char*);
            }
            else {
                name = va_arg (ap, char*);

                sClassName += name;

                str1 += "\t" + type + " " + name + ";\n";
                str2 += type + " _" + name + ",";
                str3 += "\t\t" + name + " = _" + name + ";\n";
                str4 += "\t\tif (this->" + name + "<s." + name + ") return (true);\n";
                str4 += "\t\tif (this->" + name + ">s." + name + ") return (false);\n";

                type.clear ();
            }
        }

        fmt++;
    }
    va_end (ap);

    str2 = str2.substr (0, str2.size() -1);
    string sCode = STRUCTURE_UNIQUE_STRUCT;
    sCode = ExcelUtils::findAndReplace (sCode, "aaaaa", sClassName);
    sCode = ExcelUtils::findAndReplace (sCode, "bbbbb", str1);
    sCode = ExcelUtils::findAndReplace (sCode, "ccccc", str2);
    sCode = ExcelUtils::findAndReplace (sCode, "ddddd", str3);
    sCode = ExcelUtils::findAndReplace (sCode, "eeeee", str4);

    //printf ("%s", sCode.c_str());

    return (sCode);
}

string UniqueUtils::getUniqueDefine (string& sClassName, const char* fmt, ...)
{
    va_list ap;
    string  type;
    string  name;
    string  str1, str2;

    str1 = "_SheetIndexType" + sClassName;

    va_start (ap, fmt);
    while (*fmt) {
        if (*fmt == '%' && *(fmt+1) == 's') {
            if (type.empty ()) {
                type = va_arg (ap, char*);
            }
            else {
                name = va_arg (ap, char*);

                str1 += name;
                str2 += name + "_";
                type.clear ();
            }
        }

        fmt++;
    }
    va_end (ap);

    str2 = str2.substr (0, str2.size() -1);
    string sCode = STRUCTURE_UNIQUE_DEFINE;
    sCode = ExcelUtils::findAndReplace (sCode, "aaaaa", str1);
    sCode = ExcelUtils::findAndReplace (sCode, "bbbbb", str2);

    //printf ("%s", sCode.c_str());

    return (sCode);
}

string UniqueUtils::getFindByUniqueINH (string& sClassName, const char* fmt, ...)
{
    va_list ap;
    string  type;
    string  name;
    string  str1, str2;

    va_start (ap, fmt);
    while (*fmt) {
        if (*fmt == '%' && *(fmt+1) == 's') {
            if (type.empty ()) {
                type = va_arg (ap, char*);
            }
            else {
                name = va_arg (ap, char*);

                str1 += name;
                str2 += type + " _" + name + ",";
                type.clear ();
            }
        }

        fmt++;
    }
    va_end (ap);

    str2 = str2.substr (0, str2.size() -1);
    string sCode = STRUCTURE_FIND_BY_UNIQUE_INH;
    sCode = ExcelUtils::findAndReplace (sCode, "xxxxx", sClassName);
    sCode = ExcelUtils::findAndReplace (sCode, "aaaaa", str1);
    sCode = ExcelUtils::findAndReplace (sCode, "bbbbb", str2);

    //printf ("%s", sCode.c_str());

    return (sCode);
}

string UniqueUtils::getFindByUnique (string& sClassName, const char* fmt, ...)
{
    va_list ap;
    string  type;
    string  name;
    string  str1, str2, str3, str4, str5, str6, str7;

    str3 = "_SheetIndexType" + sClassName;

    va_start (ap, fmt);
    while (*fmt) {
        if (*fmt == '%' && *(fmt+1) == 's') {
            if (type.empty ()) {
                type = va_arg (ap, char*);
            }
            else {
                name = va_arg (ap, char*);

                str1 += name;
                str2 += type + " _" + name + ",";
                str3 += name;
                str4 += name + "_";
                str5 += "_" + name + ",";
                if (type == "string") {
                    str6 += "%s,";
                    str7 += "_" + name + ".c_str(),";
                }
                else if (type == "int") {
                    str6 += "%d,";
                    str7 += "_" + name + ",";
                }
                type.clear ();
            }
        }

        fmt++;
    }
    va_end (ap);

    str2 = str2.substr (0, str2.size() -1);
    str4 = str4.substr (0, str4.size() -1);
    str5 = str5.substr (0, str5.size() -1);
    str6 = str6.substr (0, str6.size() -1);
    str7 = str7.substr (0, str7.size() -1);
    string sCode = STRUCTURE_FIND_BY_UNIQUE;
    sCode = ExcelUtils::findAndReplace (sCode, "xxxxx", sClassName);
    sCode = ExcelUtils::findAndReplace (sCode, "aaaaa", str1);
    sCode = ExcelUtils::findAndReplace (sCode, "bbbbb", str2);
    sCode = ExcelUtils::findAndReplace (sCode, "ccccc", str3);
    sCode = ExcelUtils::findAndReplace (sCode, "ddddd", str4);
    sCode = ExcelUtils::findAndReplace (sCode, "eeeee", str3 + "(" + str5 + ")");
    sCode = ExcelUtils::findAndReplace (sCode, "yyyyy", str5);
    sCode = ExcelUtils::findAndReplace (sCode, "zzzzz", str6);
    sCode = ExcelUtils::findAndReplace (sCode, "wwwww", str7);

    //printf ("%s", sCode.c_str());

    return (sCode);
}

///////////////////////////////// UNIQUEUTILS END /////////////////////////////

///////////////////////////////// MULTIKEYUTILS /////////////////////////////

string MultiKeyUtils::getMultiKeyDefine (string& sClassName, const char* fmt, ...)
{
    va_list ap;
    string  type;
    string  name;
    string  str1, str2;

    str1 = "_SheetIndexType" + sClassName;

    va_start (ap, fmt);
    while (*fmt) {
        if (*fmt == '%' && *(fmt+1) == 's') {
            if (type.empty ()) {
                type = va_arg (ap, char*);
            }
            else {
                name = va_arg (ap, char*);

                str1 += name;
                str2 += name + "_";
                type.clear ();
            }
        }

        fmt++;
    }
    va_end (ap);

    str2 = str2.substr (0, str2.size() -1);
    string sCode = STRUCTURE_MULTI_KEY_DEFINE;
    sCode = ExcelUtils::findAndReplace (sCode, "aaaaa", str1);
    sCode = ExcelUtils::findAndReplace (sCode, "bbbbb", str2);

    //printf ("%s", sCode.c_str());

    return (sCode);
}

string MultiKeyUtils::getFindByMultiKeyINH (string& sClassName, const char* fmt, ...)
{
    va_list ap;
    string  type;
    string  name;
    string  str1, str2;

    va_start (ap, fmt);
    while (*fmt) {
        if (*fmt == '%' && *(fmt+1) == 's') {
            if (type.empty ()) {
                type = va_arg (ap, char*);
            }
            else {
                name = va_arg (ap, char*);

                str1 += name;
                str2 += type + " _" + name + ",";
                type.clear ();
            }
        }

        fmt++;
    }
    va_end (ap);

    str2 = str2.substr (0, str2.size() -1);
    string sCode = STRUCTURE_FIND_BY_MULTI_KEY_INH;
    sCode = ExcelUtils::findAndReplace (sCode, "xxxxx", sClassName);
    sCode = ExcelUtils::findAndReplace (sCode, "aaaaa", str1);
    sCode = ExcelUtils::findAndReplace (sCode, "bbbbb", str2);

    //printf ("%s", sCode.c_str());

    return (sCode);
}

string MultiKeyUtils::getFindByMultiKey (string& sClassName, const char* fmt, ...)
{
    va_list ap;
    string  type;
    string  name;
    string  str1, str2, str3, str4, str5;

    str3 = "_SheetIndexType" + sClassName;

    va_start (ap, fmt);
    while (*fmt) {
        if (*fmt == '%' && *(fmt+1) == 's') {
            if (type.empty ()) {
                type = va_arg (ap, char*);
            }
            else {
                name = va_arg (ap, char*);

                str1 += name;
                str2 += type + " _" + name + ",";
                str3 += name;
                str4 += name + "_";
                str5 += "_" + name + ",";
                type.clear ();
            }
        }

        fmt++;
    }
    va_end (ap);

    str2 = str2.substr (0, str2.size() -1);
    str4 = str4.substr (0, str4.size() -1);
    str5 = str5.substr (0, str5.size() -1);
    string sCode = STRUCTURE_FIND_BY_MULTI_KEY;
    sCode = ExcelUtils::findAndReplace (sCode, "xxxxx", sClassName);
    sCode = ExcelUtils::findAndReplace (sCode, "aaaaa", str1);
    sCode = ExcelUtils::findAndReplace (sCode, "bbbbb", str2);
    sCode = ExcelUtils::findAndReplace (sCode, "ccccc", str3);
    sCode = ExcelUtils::findAndReplace (sCode, "ddddd", str4);
    sCode = ExcelUtils::findAndReplace (sCode, "eeeee", str3 + "(" + str5 + ")");

    //printf ("%s", sCode.c_str());

    return (sCode);
}

string MultiKeyUtils::getMultiKeyStruct (string& structName, const char* fmt, ...)
{
    va_list ap;
    string  type;
    string  name;
    string  str1, str2, str3, str4;

    structName = "_SheetIndexType" + structName;

    va_start (ap, fmt);
    while (*fmt) {
        if (*fmt == '%' && *(fmt+1) == 's') {
            if (type.empty ()) {
                type = va_arg (ap, char*);
            }
            else {
                name = va_arg (ap, char*);

                structName += name;

                str1 += "\t" + type + " " + name + ";\n";
                str2 += type + " _" + name + ",";
                str3 += "\t\t" + name + " = _" + name + ";\n";
                str4 += "\t\tif (this->" + name + "<s." + name + ") return (true);\n";
                str4 += "\t\tif (this->" + name + ">s." + name + ") return (false);\n";

                type.clear ();
            }
        }

        fmt++;
    }
    va_end (ap);

    str2 = str2.substr (0, str2.size() -1);
    string sCode = STRUCTURE_MULTI_KEY_STRUCT;
    sCode = ExcelUtils::findAndReplace (sCode, "aaaaa", structName);
    sCode = ExcelUtils::findAndReplace (sCode, "bbbbb", str1);
    sCode = ExcelUtils::findAndReplace (sCode, "ccccc", str2);
    sCode = ExcelUtils::findAndReplace (sCode, "ddddd", str3);
    sCode = ExcelUtils::findAndReplace (sCode, "eeeee", str4);

    //printf ("%s", sCode.c_str());

    return (sCode);
}

///////////////////////////////// MULTIKEYUTILS END /////////////////////////////

///////////////////////////////// EXCELSTRINGUTILS /////////////////////////////
std::string& ExcelStringUtils::trim (std::string &s) 
{
    if (s.empty()) {  
        return s;
    }

    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1); 
    return s;
}

///////////////////////////////// EXCELSTRINGUTILS END /////////////////////////////

string ExcelUtils::findAndReplace (string sCode, string subStr, string repStr)
{
    // find and replace

    size_t pos, len;
    len = subStr.size ();
    while ((pos = sCode.find (subStr)) != string::npos) {
        sCode.replace (pos, len, repStr);
    }
    return (sCode);
}

string ExcelUtils::findAndInsert (string sCode, string subStr, string instStr, enum InstFlag flag)
{
    // find and insert

    size_t pos, len;
    len = subStr.size();
    if ((pos = sCode.find (subStr)) != string::npos) {
    
        if (flag == BEFORE)
            sCode.insert (pos    , instStr); // before insert
        else if (flag == AFTER)
            sCode.insert (pos+len, instStr); // after  insert
    }

    return (sCode);
}

string ExcelField::productSheetData (string sCode)
{
    string sInsert = "";
    if (dataType () == "int") {
        if (defaultValue() == "")
            sInsert = TAB + toName () + " = 0;" + ENTER;
        else
            sInsert = TAB + toName () + " = " + defaultValue() + ";" + ENTER;
    }
    else if (dataType () == "string") {
        if (defaultValue() == "")
            sInsert = TAB + toName () + " = \"\";" + ENTER;
        else
            sInsert = TAB + toName () + " = \"" + defaultValue() + "\";" + ENTER;
    }

    sCode = ExcelUtils::findAndInsert (sCode, "{\n", sInsert, AFTER);
    return (sCode);
}

string ExcelSheet::productSheetData (void)
{
    string sCode;
    sCode = STRUCTURE_SHEETDATA_SHEETDATA;
    sCode = ExcelUtils::findAndReplace (sCode, "xxxxx", toName ());

    vector<ExcelField>::reverse_iterator itField;
    for (itField = Fields.rbegin(); itField != Fields.rend(); itField++) {
        if (!itField->isIndexField)
            sCode = itField->productSheetData (sCode);
    }
    
    return (sCode);
}

string ExcelField::productSheetInit (string sCode)
{
    string sInsert;
    string sPos = "\t\toneData._row_id = row_num++;\n";

    if (dataType() == "int") {
        sInsert = "\t\tSheetUtils::readToken (fp, value);\n";
        sInsert+= "\t\toneData.";
        sInsert+= toName () + " = atoi (value.c_str ());\n";
    }
    else if (dataType() == "string") {
        sInsert = "\t\tSheetUtils::readToken (fp, value);\n";
        sInsert+= "\t\toneData.";
        sInsert+= toName () + " = value;\n";
    }
    else {
        //return ("");
        sInsert = ";";
    }

    sCode = ExcelUtils::findAndInsert (sCode, sPos, sInsert, BEFORE);

    return (sCode);
}

string ExcelField::productSheetDataInH (string sCode)
{
    string sInsert = TAB + dataType() + " " + toName () + ";"+ TAB + "//" + name () + ENTER;
    sCode = ExcelUtils::findAndInsert (sCode, "public:\n", sInsert, AFTER);
    return (sCode);
}

string ExcelSheet::productSheetDataInH (void)
{
    string sCode;
    sCode = STRUCTURE_SHEETDATA;
    sCode = ExcelUtils::findAndReplace (sCode, "xxxxx", toName ());

    vector<ExcelField>::reverse_iterator itField;
    for (itField = Fields.rbegin(); itField != Fields.rend(); itField++) {
        if (!itField->isIndexField)
            sCode = itField->productSheetDataInH (sCode);
    }
    
    return (sCode);
}

string ExcelSheet::productSheetInH (void)
{
    string sCode;
    sCode = STRUCTURE_SHEET;
    sCode = ExcelUtils::findAndReplace (sCode, "xxxxx", toName ());

    return (sCode);
}

string ExcelSheet::productSheetGetRow (void)
{
    string sCode;
    sCode = STRUCTURE_SHEET_GETROW;
    sCode = ExcelUtils::findAndReplace (sCode, "xxxxx", toName ());

    return (sCode);
}

string ExcelSheet::productSheetGetAll (void)
{
    string sCode;
    sCode = STRUCTURE_SHEET_GETALL;
    sCode = ExcelUtils::findAndReplace (sCode, "xxxxx", toName ());

    return (sCode);
}

string ExcelSheet::productSheetInit (void)
{
    string sCode;
    sCode = STRUCTURE_SHEET_INIT;

    vector<ExcelField>::iterator itField;
    for (itField = Fields.begin(); itField != Fields.end(); itField++) {
        if (!itField->isIndexField)
            sCode = itField->productSheetInit (sCode);
    }
    
    sCode = ExcelUtils::findAndReplace (sCode, "xxxxx", toName ());

    return (sCode);
}

string ExcelSheet::productSheetInitLink (void)
{
    string sCode;
    sCode = STRUCTURE_SHEET_INITLINK;
    sCode = ExcelUtils::findAndReplace (sCode, "xxxxx", toName ());

    return (sCode);
}

string ExcelSheet::productInitSheets (void)
{
    string sCode;
    sCode = STRUCTURE_INITSHEETS_CONTENT;
    sCode = ExcelUtils::findAndReplace (sCode, "xxxxx", toName ());

    return (sCode);
}

string ExcelSheet::productSheetDefine (void)
{
    string sCode;
    sCode = STRUCTURE_SHEETS_DEFINE;
    sCode = ExcelUtils::findAndReplace (sCode, "xxxxx", toName ());

    return (sCode);
}

string ExcelSheet::productSheetDump (void)
{
    string sCode;

    vector<ExcelField>::iterator itField;
    for (itField = Fields.begin(); itField != Fields.end(); itField++) {
        if (!itField->isIndexField)
            sCode += itField->productSheetDump ();
    }

    sCode = STRUCTURE_DUMP_BEGIN + sCode + STRUCTURE_DUMP_END;
    sCode = ExcelUtils::findAndReplace (sCode, "xxxxx", toName ());

    return (sCode);
}

string ExcelField::productSheetDump (void)
{
    string sCode;
    string sReplace;

    sCode = STRUCTURE_DUMP_CONTENT;
    sReplace += "data[i]." + toName ();
    sCode = ExcelUtils::findAndReplace (sCode, "yyyyy", toName ());
    sCode = ExcelUtils::findAndReplace (sCode, "zzzzz", sReplace);

    return (sCode);
}

// PK

string ExcelField::productTryFindByPKInH (string _dataType, string _toName)
{
    string sCode;

    if (type() == "PK")
        sCode = STRUCTURE_TRY_FIND_BY_PK_INH;
    else if (type() == "KEY")
        sCode = STRUCTURE_TRY_FIND_BY_KEY_INH;

    sCode = ExcelUtils::findAndReplace (sCode, "yyyyy", _dataType);
    sCode = ExcelUtils::findAndReplace (sCode, "zzzzz", _toName);

    return (sCode);
}

string ExcelSheet::productTryFindByPKInH (string sCode)
{
    string sResult = sCode;
    string sFind = "Data *data;\n";


    vector<ExcelField>::iterator itField;
    for (itField = Fields.begin(); itField != Fields.end(); itField++) {
        if (itField->isIndexField) {
            // find field.
            vector<ExcelField>::iterator itf;
            for (itf = Fields.begin(); itf != Fields.end(); itf++) {
                if (itf->toName() == itField->fields()) {
                    sResult = ExcelUtils::findAndInsert (sResult, sFind, \
                            itField->productTryFindByPKInH(itf->dataType(), itf->toName()), AFTER);
                    break;
                }
            }
        }
    }

    if (sResult == sCode)
        return (sCode);
    else
        return (sResult);
}
string ExcelField::productFindByPKInH (string _dataType, string _toName)
{
    string sCode;

    if (type() == "PK")
        sCode = STRUCTURE_FIND_BY_PK_INH;
    else if (type() == "KEY")
        sCode = STRUCTURE_FIND_BY_KEY_INH;

    sCode = ExcelUtils::findAndReplace (sCode, "yyyyy", _dataType);
    sCode = ExcelUtils::findAndReplace (sCode, "zzzzz", _toName);


    return (sCode);
}
string ExcelSheet::productFindByPKInH   (string sCode)
{
    string sResult = sCode;
    string sFind = "\tvoid dump (void);";

    vector<ExcelField>::iterator itField;
    for (itField = Fields.begin(); itField != Fields.end(); itField++) {
        if (itField->isIndexField) {
            // find field.
            vector<ExcelField>::iterator itf;
            for (itf = Fields.begin(); itf != Fields.end(); itf++) {
                if (itf->toName() == itField->fields()) {
                    sResult = ExcelUtils::findAndInsert (sResult, sFind, \
                            itField->productFindByPKInH(itf->dataType(), itf->toName()), BEFORE);
                    break;
                }
            }
        }
    }

    sResult = ExcelUtils::findAndReplace (sResult, "xxxxx", toName ());


    if (sResult == sCode)
        return (sCode);
    else
        return (sResult);
}

string ExcelField::productTryFindByPK (string _dataType, string _toName)
{
    string sCode = "";

    if (type() == "PK") {
        sCode = STRUCTURE_TRY_FIND_BY_PK;
        sCode = ExcelUtils::findAndReplace (sCode, "yyyyy", _dataType);
        sCode = ExcelUtils::findAndReplace (sCode, "zzzzz", _toName);
    }

    return (sCode);
}

string ExcelSheet::productTryFindByPK   (void)
{
    string sCode = "";


    vector<ExcelField>::iterator itField;
    for (itField = Fields.begin(); itField != Fields.end(); itField++) {
        if (itField->isIndexField) {
            // find field.
            vector<ExcelField>::iterator itf;
            for (itf = Fields.begin(); itf != Fields.end(); itf++) {
                if (itf->toName() == itField->fields()) {
                    sCode+= itField->productTryFindByPK (itf->dataType(), itf->toName());
                    sCode = ExcelUtils::findAndReplace (sCode, "xxxxx", toName ());
                    break;
                }
            }
        }
    }

    return (sCode);
}

string ExcelField::productFindByPK (string _dataType, string _toName)
{
    string sCode;

    if (type() == "PK")
        sCode = STRUCTURE_FIND_BY_PK;
    else if (type() == "KEY")
        sCode = STRUCTURE_FIND_BY_KEY;

    sCode = ExcelUtils::findAndReplace (sCode, "yyyyy", _dataType);
    sCode = ExcelUtils::findAndReplace (sCode, "zzzzz", _toName);

    return (sCode);
}

string ExcelSheet::productFindByPK (void)
{
    string sCode = "";


    vector<ExcelField>::iterator itField;
    for (itField = Fields.begin(); itField != Fields.end(); itField++) {
        if (itField->isIndexField) {
            // find field.
            vector<ExcelField>::iterator itf;
            for (itf = Fields.begin(); itf != Fields.end(); itf++) {
                if (itf->toName() == itField->fields()) {
                    sCode+= itField->productFindByPK (itf->dataType(), itf->toName());
                    sCode = ExcelUtils::findAndReplace (sCode, "xxxxx", toName ());
                    break;
                }
            }
        }
    }

    return (sCode);
}

string ExcelSheet::productMultiKeyINH (string& sMainCode)
{
    string sCode = "";
    string sFields = "";
    string sField = "";
    string sClassName = toName ();

    //std::map<string, string> datatypeName_;
    vector<string> sDatatypeName;

    vector<ExcelField>::iterator itField;
    for (itField = Fields.begin(); itField != Fields.end(); itField++) {
        if ((itField->isIndexField) && \
            (itField->type() == "KEY") && \
            (itField->fields().find (',') != string::npos)) {
            // find multikey fields.
            sFields = itField->fields ();
            while (1) {
                int pos = sFields.find (',');
                if (pos == 0) {
                    sFields = sFields.substr (1);
                    continue;
                }
                if (pos < 0) {
                    ExcelStringUtils::trim (sFields);
                    sField = sFields;
                    sFields = "";
                    goto success;
                    break;
                }
                sField = sFields.substr (0, pos);
                sFields= sFields.substr (pos+1);
success:
                ExcelStringUtils::trim (sField);
                //printf ("[DEBUG2]:'%s'\n", sField.c_str ());

                vector<ExcelField>::iterator itf;
                for (itf = Fields.begin(); itf != Fields.end(); itf++) {
                    if (itf->isIndexField)  continue;

                    if (itf->toName () == sField) {
                        // TODO:
                        //printf ("[MULTIKEY]: datatype=%s, name=%s\n", itf->dataType ().c_str(), itf->toName ().c_str());
                        sDatatypeName.push_back (itf->dataType ());
                        sDatatypeName.push_back (itf->toName ());
                    }
                }

                if (sFields.empty ()) {
                    break;
                }
            }
            // TODO:      bool forEach (SheetPlayerData& item);
            /*
            printf ("sDatatypeName.size() = %ld\n", sDatatypeName.size());
            for (unsigned int i=0; i<sDatatypeName.size(); i++) {
                printf ("%s\n", sDatatypeName[i].c_str());
            }
            */
            if (sDatatypeName.size () == 4) {
                sClassName.clear ();
                sClassName = toName ();
                sCode = MultiKeyUtils::getMultiKeyDefine (sClassName, "%s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str());
                string sReplace = string ("\tSheet") + sClassName + string ("Data *data;\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, AFTER);

                sClassName.clear ();
                sClassName = toName ();
                sCode = MultiKeyUtils::getMultiKeyStruct (sClassName, "%s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str());
                sReplace = string ("class Sheet") + toName () + string (" : public SheetBase\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);

                sClassName.clear ();
                sClassName = toName ();
                sCode = MultiKeyUtils::getFindByMultiKeyINH (sClassName, "%s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str());
                sReplace = string ("\tbool forEach (Sheet") + toName () + string ("Data& item);\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);
            }
            else if (sDatatypeName.size () == 6) {
                sClassName.clear ();
                sClassName = toName ();
                sCode = MultiKeyUtils::getMultiKeyDefine (sClassName, "%s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str());
                string sReplace = string ("\tSheet") + sClassName + string ("Data *data;\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, AFTER);

                sClassName.clear ();
                sClassName = toName ();
                sCode = MultiKeyUtils::getMultiKeyStruct (sClassName, "%s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str());
                sReplace = string ("class Sheet") + toName () + string (" : public SheetBase\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);

                sClassName.clear ();
                sClassName = toName ();
                sCode = MultiKeyUtils::getFindByMultiKeyINH (sClassName, "%s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str());
                sReplace = string ("\tbool forEach (Sheet") + toName () + string ("Data& item);\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);
            }
            else if (sDatatypeName.size () == 8) {
                sClassName.clear ();
                sClassName = toName ();
                sCode = MultiKeyUtils::getMultiKeyDefine (sClassName, "%s %s %s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str(), \
                        sDatatypeName[6].c_str(), \
                        sDatatypeName[7].c_str());
                string sReplace = string ("\tSheet") + sClassName + string ("Data *data;\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, AFTER);

                sClassName.clear ();
                sClassName = toName ();
                sCode = MultiKeyUtils::getMultiKeyStruct (sClassName, "%s %s %s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str(), \
                        sDatatypeName[6].c_str(), \
                        sDatatypeName[7].c_str());
                sReplace = string ("class Sheet") + toName () + string (" : public SheetBase\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);

                sClassName.clear ();
                sClassName = toName ();
                sCode = MultiKeyUtils::getFindByMultiKeyINH (sClassName, "%s %s %s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str(), \
                        sDatatypeName[6].c_str(), \
                        sDatatypeName[7].c_str());
                sReplace = string ("\tbool forEach (Sheet") + toName () + string ("Data& item);\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);
            }
            else if (sDatatypeName.size () == 10) {
                sClassName.clear ();
                sClassName = toName ();
                sCode = MultiKeyUtils::getMultiKeyDefine (sClassName, "%s %s %s %s %s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str(), \
                        sDatatypeName[6].c_str(), \
                        sDatatypeName[7].c_str(), \
                        sDatatypeName[8].c_str(), \
                        sDatatypeName[9].c_str());
                string sReplace = string ("\tSheet") + sClassName + string ("Data *data;\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, AFTER);

                sClassName.clear ();
                sClassName = toName ();
                sCode = MultiKeyUtils::getMultiKeyStruct (sClassName, "%s %s %s %s %s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str(), \
                        sDatatypeName[6].c_str(), \
                        sDatatypeName[7].c_str(), \
                        sDatatypeName[8].c_str(), \
                        sDatatypeName[9].c_str());
                sReplace = string ("class Sheet") + toName () + string (" : public SheetBase\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);

                sClassName.clear ();
                sClassName = toName ();
                sCode = MultiKeyUtils::getFindByMultiKeyINH (sClassName, "%s %s %s %s %s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str(), \
                        sDatatypeName[6].c_str(), \
                        sDatatypeName[7].c_str(), \
                        sDatatypeName[8].c_str(), \
                        sDatatypeName[9].c_str());
                sReplace = string ("\tbool forEach (Sheet") + toName () + string ("Data& item);\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);
            }
            sDatatypeName.clear ();
        }
    }

    return (sCode);
}

string ExcelSheet::productMultiKey (string& sMainCode)
{
    string sCode = "";
    string sFields = "";
    string sField = "";
    string sClassName = toName ();

    //std::map<string, string> datatypeName_;
    vector<string> sDatatypeName;

    vector<ExcelField>::iterator itField;
    for (itField = Fields.begin(); itField != Fields.end(); itField++) {
        if ((itField->isIndexField) && \
            (itField->type() == "KEY") && \
            (itField->fields().find (',') != string::npos)) {
            // find multikey fields.
            sFields = itField->fields ();
            while (1) {
                int pos = sFields.find (',');
                if (pos == 0) {
                    sFields = sFields.substr (1);
                    continue;
                }
                if (pos < 0) {
                    ExcelStringUtils::trim (sFields);
                    sField = sFields;
                    sFields = "";
                    goto success;
                    break;
                }
                sField = sFields.substr (0, pos);
                sFields= sFields.substr (pos+1);
success:
                ExcelStringUtils::trim (sField);
                //printf ("[DEBUG2]:'%s'\n", sField.c_str ());

                vector<ExcelField>::iterator itf;
                for (itf = Fields.begin(); itf != Fields.end(); itf++) {
                    if (itf->isIndexField)  continue;

                    if (itf->toName () == sField) {
                        // TODO:
                        //printf ("[MULTIKEY]: datatype=%s, name=%s\n", itf->dataType ().c_str(), itf->toName ().c_str());
                        sDatatypeName.push_back (itf->dataType ());
                        sDatatypeName.push_back (itf->toName ());
                    }
                }

                if (sFields.empty ()) {
                    break;
                }
            }
            // TODO:      bool forEach (SheetPlayerData& item);
            /*
            printf ("sDatatypeName.size() = %ld\n", sDatatypeName.size());
            for (unsigned int i=0; i<sDatatypeName.size(); i++) {
                printf ("%s\n", sDatatypeName[i].c_str());
            }
            */
            if (sDatatypeName.size () == 4) {
                sClassName.clear ();
                sClassName = toName ();
                sCode = MultiKeyUtils::getFindByMultiKey (sClassName, "%s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str());
                sMainCode += sCode;
                //sReplace = string ("class Sheet") + toName () + string (" : public SheetBase\n");
                //sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);
            }
            else if (sDatatypeName.size () == 6) {
                sClassName.clear ();
                sClassName = toName ();
                sCode = MultiKeyUtils::getFindByMultiKey (sClassName, "%s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str());
                sMainCode += sCode;
                //sReplace = string ("\tbool forEach (Sheet") + toName () + string ("Data& item);\n");
                //sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);
            }
            else if (sDatatypeName.size () == 8) {
                sClassName.clear ();
                sClassName = toName ();
                sCode = MultiKeyUtils::getFindByMultiKey (sClassName, "%s %s %s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str(), \
                        sDatatypeName[6].c_str(), \
                        sDatatypeName[7].c_str());
                sMainCode += sCode;
                //sReplace = string ("\tbool forEach (Sheet") + toName () + string ("Data& item);\n");
                //sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);
            }
            else if (sDatatypeName.size () == 10) {
                sClassName.clear ();
                sClassName = toName ();
                sCode = MultiKeyUtils::getFindByMultiKey (sClassName, "%s %s %s %s %s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str(), \
                        sDatatypeName[6].c_str(), \
                        sDatatypeName[7].c_str(), \
                        sDatatypeName[8].c_str(), \
                        sDatatypeName[9].c_str());
                sMainCode += sCode;
                //sReplace = string ("\tbool forEach (Sheet") + toName () + string ("Data& item);\n");
                //sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);
            }
            sDatatypeName.clear ();
        }
    }

    return (sCode);
}

///////////////////////////////////

string ExcelSheet::productUniqueINH (string& sMainCode)
{
    string sCode = "";
    string sFields = "";
    string sField = "";
    string sClassName = toName ();

    //std::map<string, string> datatypeName_;
    vector<string> sDatatypeName;

    vector<ExcelField>::iterator itField;
    for (itField = Fields.begin(); itField != Fields.end(); itField++) {
        if ((itField->isIndexField) && \
            (itField->type() == "UNIQUE") && \
            (itField->fields().find (',') != string::npos)) {
            // find unique fields.
            sFields = itField->fields ();
            while (1) {
                int pos = sFields.find (',');
                if (pos == 0) {
                    sFields = sFields.substr (1);
                    continue;
                }
                if (pos < 0) {
                    ExcelStringUtils::trim (sFields);
                    sField = sFields;
                    sFields = "";
                    goto success;
                    break;
                }
                sField = sFields.substr (0, pos);
                sFields= sFields.substr (pos+1);
success:
                ExcelStringUtils::trim (sField);
                //printf ("[DEBUG2]:'%s'\n", sField.c_str ());

                vector<ExcelField>::iterator itf;
                for (itf = Fields.begin(); itf != Fields.end(); itf++) {
                    if (itf->isIndexField)  continue;

                    if (itf->toName () == sField) {
                        // TODO:
                        //printf ("[UNIQUE]: datatype=%s, name=%s\n", itf->dataType ().c_str(), itf->toName ().c_str());
                        sDatatypeName.push_back (itf->dataType ());
                        sDatatypeName.push_back (itf->toName ());
                    }
                }

                if (sFields.empty ()) {
                    break;
                }
            }
            // TODO:      bool forEach (SheetPlayerData& item);
            /*
            printf ("sDatatypeName.size() = %ld\n", sDatatypeName.size());
            for (unsigned int i=0; i<sDatatypeName.size(); i++) {
                printf ("%s\n", sDatatypeName[i].c_str());
            }
            */
            if (sDatatypeName.size () == 4) {
                sClassName.clear ();
                sClassName = toName ();
                sCode = UniqueUtils::getUniqueDefine (sClassName, "%s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str());
                //printf ("UniqueUtils::getUniqueDefine - sCode=\n%s\n", sCode.c_str());
                string sReplace = string ("\tSheet") + sClassName + string ("Data *data;\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, AFTER);

                sClassName.clear ();
                sClassName = toName ();
                sCode = UniqueUtils::getUniqueStruct (sClassName, "%s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str());
                //printf ("UniqueUtils::getUniqueStruct - sCode=\n%s\n", sCode.c_str());
                sReplace = string ("class Sheet") + toName () + string (" : public SheetBase\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);

                sClassName.clear ();
                sClassName = toName ();
                sCode = UniqueUtils::getFindByUniqueINH (sClassName, "%s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str());
                //printf ("UniqueUtils::getFindByUniqueINH - sCode=\n%s\n", sCode.c_str());
                sReplace = string ("\tbool forEach (Sheet") + toName () + string ("Data& item);\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);
            }
            else if (sDatatypeName.size () == 6) {
                sClassName.clear ();
                sClassName = toName ();
                sCode = UniqueUtils::getUniqueDefine (sClassName, "%s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str());
                string sReplace = string ("\tSheet") + sClassName + string ("Data *data;\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, AFTER);

                sClassName.clear ();
                sClassName = toName ();
                sCode = UniqueUtils::getUniqueStruct (sClassName, "%s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str());
                sReplace = string ("class Sheet") + toName () + string (" : public SheetBase\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);

                sClassName.clear ();
                sClassName = toName ();
                sCode = UniqueUtils::getFindByUniqueINH (sClassName, "%s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str());
                sReplace = string ("\tbool forEach (Sheet") + toName () + string ("Data& item);\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);
            }
            else if (sDatatypeName.size () == 8) {
                sClassName.clear ();
                sClassName = toName ();
                sCode = UniqueUtils::getUniqueDefine (sClassName, "%s %s %s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str(), \
                        sDatatypeName[6].c_str(), \
                        sDatatypeName[7].c_str());
                string sReplace = string ("\tSheet") + sClassName + string ("Data *data;\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, AFTER);

                sClassName.clear ();
                sClassName = toName ();
                sCode = UniqueUtils::getUniqueStruct (sClassName, "%s %s %s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str(), \
                        sDatatypeName[6].c_str(), \
                        sDatatypeName[7].c_str());
                sReplace = string ("class Sheet") + toName () + string (" : public SheetBase\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);

                sClassName.clear ();
                sClassName = toName ();
                sCode = UniqueUtils::getFindByUniqueINH (sClassName, "%s %s %s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str(), \
                        sDatatypeName[6].c_str(), \
                        sDatatypeName[7].c_str());
                sReplace = string ("\tbool forEach (Sheet") + toName () + string ("Data& item);\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);
            }
            else if (sDatatypeName.size () == 10) {
                sClassName.clear ();
                sClassName = toName ();
                sCode = UniqueUtils::getUniqueDefine (sClassName, "%s %s %s %s %s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str(), \
                        sDatatypeName[6].c_str(), \
                        sDatatypeName[7].c_str(), \
                        sDatatypeName[8].c_str(), \
                        sDatatypeName[9].c_str());
                string sReplace = string ("\tSheet") + sClassName + string ("Data *data;\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, AFTER);

                sClassName.clear ();
                sClassName = toName ();
                sCode = UniqueUtils::getUniqueStruct (sClassName, "%s %s %s %s %s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str(), \
                        sDatatypeName[6].c_str(), \
                        sDatatypeName[7].c_str(), \
                        sDatatypeName[8].c_str(), \
                        sDatatypeName[9].c_str());
                sReplace = string ("class Sheet") + toName () + string (" : public SheetBase\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);

                sClassName.clear ();
                sClassName = toName ();
                sCode = UniqueUtils::getFindByUniqueINH (sClassName, "%s %s %s %s %s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str(), \
                        sDatatypeName[6].c_str(), \
                        sDatatypeName[7].c_str(), \
                        sDatatypeName[8].c_str(), \
                        sDatatypeName[9].c_str());
                sReplace = string ("\tbool forEach (Sheet") + toName () + string ("Data& item);\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);
            }
            sDatatypeName.clear ();
        }
    }

    return (sCode);
}

string ExcelSheet::productUnique (string& sMainCode)
{
    string sCode = "";
    string sFields = "";
    string sField = "";
    string sClassName = toName ();

    //std::map<string, string> datatypeName_;
    vector<string> sDatatypeName;

    vector<ExcelField>::iterator itField;
    for (itField = Fields.begin(); itField != Fields.end(); itField++) {
        if ((itField->isIndexField) && \
            (itField->type() == "UNIQUE") && \
            (itField->fields().find (',') != string::npos)) {
            // find multikey fields.
            sFields = itField->fields ();
            while (1) {
                int pos = sFields.find (',');
                if (pos == 0) {
                    sFields = sFields.substr (1);
                    continue;
                }
                if (pos < 0) {
                    ExcelStringUtils::trim (sFields);
                    sField = sFields;
                    sFields = "";
                    goto success;
                    break;
                }
                sField = sFields.substr (0, pos);
                sFields= sFields.substr (pos+1);
success:
                ExcelStringUtils::trim (sField);
                //printf ("[DEBUG2]:'%s'\n", sField.c_str ());

                vector<ExcelField>::iterator itf;
                for (itf = Fields.begin(); itf != Fields.end(); itf++) {
                    if (itf->isIndexField)  continue;

                    if (itf->toName () == sField) {
                        // TODO:
                        //printf ("[MULTIKEY]: datatype=%s, name=%s\n", itf->dataType ().c_str(), itf->toName ().c_str());
                        sDatatypeName.push_back (itf->dataType ());
                        sDatatypeName.push_back (itf->toName ());
                    }
                }

                if (sFields.empty ()) {
                    break;
                }
            }
            // TODO:      bool forEach (SheetPlayerData& item);
            /*
            printf ("sDatatypeName.size() = %ld\n", sDatatypeName.size());
            for (unsigned int i=0; i<sDatatypeName.size(); i++) {
                printf ("%s\n", sDatatypeName[i].c_str());
            }
            */
            if (sDatatypeName.size () == 4) {
                sClassName.clear ();
                sClassName = toName ();
                sCode = UniqueUtils::getFindByUnique (sClassName, "%s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str());
                sMainCode += sCode;
                //sReplace = string ("class Sheet") + toName () + string (" : public SheetBase\n");
                //sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);
            }
            else if (sDatatypeName.size () == 6) {
                sClassName.clear ();
                sClassName = toName ();
                sCode = UniqueUtils::getFindByUnique (sClassName, "%s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str());
                sMainCode += sCode;
                //sReplace = string ("\tbool forEach (Sheet") + toName () + string ("Data& item);\n");
                //sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);
            }
            else if (sDatatypeName.size () == 8) {
                sClassName.clear ();
                sClassName = toName ();
                sCode = UniqueUtils::getFindByUnique (sClassName, "%s %s %s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str(), \
                        sDatatypeName[6].c_str(), \
                        sDatatypeName[7].c_str());
                sMainCode += sCode;
                //sReplace = string ("\tbool forEach (Sheet") + toName () + string ("Data& item);\n");
                //sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);
            }
            else if (sDatatypeName.size () == 10) {
                sClassName.clear ();
                sClassName = toName ();
                sCode = UniqueUtils::getFindByUnique (sClassName, "%s %s %s %s %s %s %s %s %s %s", \
                        sDatatypeName[0].c_str(), \
                        sDatatypeName[1].c_str(), \
                        sDatatypeName[2].c_str(), \
                        sDatatypeName[3].c_str(), \
                        sDatatypeName[4].c_str(), \
                        sDatatypeName[5].c_str(), \
                        sDatatypeName[6].c_str(), \
                        sDatatypeName[7].c_str(), \
                        sDatatypeName[8].c_str(), \
                        sDatatypeName[9].c_str());
                sMainCode += sCode;
                //sReplace = string ("\tbool forEach (Sheet") + toName () + string ("Data& item);\n");
                //sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, BEFORE);
            }
            sDatatypeName.clear ();
        }
    }

    return (sCode);
}

string ExcelSheet::productAssignInFunction (string& sMainCode)
{
    string sCode = "";
    string sFields = "";
    string sField = "";
    string sClassName = toName ();

    vector<string> sDatatypeName;

    vector<ExcelField>::iterator itField;
    for (itField = Fields.begin(); itField != Fields.end(); itField++) {
#if 0
        if ((itField->isIndexField) && \
            (itField->type() == "UNIQUE") && \
            (itField->fields().find (',') != string::npos)) {
#else
        if (itField->isIndexField) {
#endif
            // find fields.
            sFields = itField->fields ();
            while (1) {
                int pos = sFields.find (',');
                if (pos == 0) {
                    sFields = sFields.substr (1);
                    continue;
                }
                if (pos < 0) {
                    ExcelStringUtils::trim (sFields);
                    sField = sFields;
                    sFields = "";
                    goto success;
                    break;
                }
                sField = sFields.substr (0, pos);
                sFields= sFields.substr (pos+1);
success:
                ExcelStringUtils::trim (sField);
                //printf ("[DEBUG2]:'%s'\n", sField.c_str ());

                vector<ExcelField>::iterator itf;
                for (itf = Fields.begin(); itf != Fields.end(); itf++) {
                    if (itf->isIndexField)  continue;

                    if (itf->toName () == sField) {
                        // TODO:
                        //printf ("[FIELDS]: datatype=%s, name=%s\n", itf->dataType ().c_str(), itf->toName ().c_str());
                        sDatatypeName.push_back (itf->dataType ());
                        sDatatypeName.push_back (itf->toName ());
                    }
                }

                if (sFields.empty ()) {
                    break;
                }
            }

            // TODO: output
            /*
            printf ("sDatatypeName.size() = %ld\n", sDatatypeName.size());
            for (unsigned int i=0; i<sDatatypeName.size(); i++) {
                printf ("%s\n", sDatatypeName[i].c_str());
            }
            */
            string sReplace;
            /*
            if (sDatatypeName.size() > 0) {
                sReplace = string ("\t\tdata[i] = d[i]; // Sheet") + toName () + string ("\n\n");
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, STRUCTURE_INIT_FOR_END, AFTER);
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, STRUCTURE_INIT_FOR_BEGIN, AFTER);
            }
            */
#if 1
            sReplace = string ("\t\tdata[i] = d[i]; // Sheet") + toName () + string ("\n\n") +
                STRUCTURE_INIT_FOR_BEGIN;

            if (itField->type() == "PK") {
                sClassName.clear ();
                sClassName = toName ();
                sCode = AssignUtils::getInitPK (sClassName, "%s %s", \
                        sDatatypeName[0].c_str (), \
                        sDatatypeName[1].c_str ());
                sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, AFTER);
            }
            else if (itField->type() == "UNIQUE") {
                if (sDatatypeName.size() == 4) {
                    sClassName.clear ();
                    sClassName = toName ();
                    sCode = AssignUtils::getInitUnique (sClassName, "%s %s %s %s", \
                            sDatatypeName[0].c_str (), \
                            sDatatypeName[1].c_str (), \
                            sDatatypeName[2].c_str (), \
                            sDatatypeName[3].c_str ());
                    sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, AFTER);
                }
                else if (sDatatypeName.size() == 6) {
                    sClassName.clear ();
                    sClassName = toName ();
                    sCode = AssignUtils::getInitUnique (sClassName, "%s %s %s %s %s %s", \
                            sDatatypeName[0].c_str (), \
                            sDatatypeName[1].c_str (), \
                            sDatatypeName[2].c_str (), \
                            sDatatypeName[3].c_str (), \
                            sDatatypeName[4].c_str (), \
                            sDatatypeName[5].c_str ());
                    sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, AFTER);
                }
                else if (sDatatypeName.size() == 8) {
                    sClassName.clear ();
                    sClassName = toName ();
                    sCode = AssignUtils::getInitUnique (sClassName, "%s %s %s %s %s %s %s %s", \
                            sDatatypeName[0].c_str (), \
                            sDatatypeName[1].c_str (), \
                            sDatatypeName[2].c_str (), \
                            sDatatypeName[3].c_str (), \
                            sDatatypeName[4].c_str (), \
                            sDatatypeName[5].c_str (), \
                            sDatatypeName[6].c_str (), \
                            sDatatypeName[7].c_str ());
                    sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, AFTER);
                }
                else if (sDatatypeName.size() ==10) {
                    sClassName.clear ();
                    sClassName = toName ();
                    sCode = AssignUtils::getInitUnique (sClassName, "%s %s %s %s %s %s %s %s %s %s", \
                            sDatatypeName[0].c_str (), \
                            sDatatypeName[1].c_str (), \
                            sDatatypeName[2].c_str (), \
                            sDatatypeName[3].c_str (), \
                            sDatatypeName[4].c_str (), \
                            sDatatypeName[5].c_str (), \
                            sDatatypeName[6].c_str (), \
                            sDatatypeName[7].c_str (), \
                            sDatatypeName[8].c_str (), \
                            sDatatypeName[9].c_str ());
                    sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, AFTER);
                }
            }
            else if (itField->type() == "KEY") {
                // only one key
                if (sDatatypeName.size() == 2) {
                    sClassName.clear ();
                    sClassName = toName ();
                    sCode = AssignUtils::getInitKey (sClassName, "%s %s", \
                            sDatatypeName[0].c_str (), \
                            sDatatypeName[1].c_str ());
                    sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, AFTER);
                }

                // multi-key
                else if (sDatatypeName.size() == 4) {
                    sClassName.clear ();
                    sClassName = toName ();
                    sCode = AssignUtils::getInitMultiKey (sClassName, "%s %s %s %s", \
                            sDatatypeName[0].c_str (), \
                            sDatatypeName[1].c_str (), \
                            sDatatypeName[2].c_str (), \
                            sDatatypeName[3].c_str ());
                    sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, AFTER);
                }
                else if (sDatatypeName.size() == 6) {
                    sClassName.clear ();
                    sClassName = toName ();
                    sCode = AssignUtils::getInitMultiKey (sClassName, "%s %s %s %s %s %s", \
                            sDatatypeName[0].c_str (), \
                            sDatatypeName[1].c_str (), \
                            sDatatypeName[2].c_str (), \
                            sDatatypeName[3].c_str (), \
                            sDatatypeName[4].c_str (), \
                            sDatatypeName[5].c_str ());
                    sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, AFTER);
                }
                else if (sDatatypeName.size() == 8) {
                    sClassName.clear ();
                    sClassName = toName ();
                    sCode = AssignUtils::getInitMultiKey (sClassName, "%s %s %s %s %s %s %s %s", \
                            sDatatypeName[0].c_str (), \
                            sDatatypeName[1].c_str (), \
                            sDatatypeName[2].c_str (), \
                            sDatatypeName[3].c_str (), \
                            sDatatypeName[4].c_str (), \
                            sDatatypeName[5].c_str (), \
                            sDatatypeName[6].c_str (), \
                            sDatatypeName[7].c_str ());
                    sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, AFTER);
                }
                else if (sDatatypeName.size() ==10) {
                    sClassName.clear ();
                    sClassName = toName ();
                    sCode = AssignUtils::getInitMultiKey (sClassName, "%s %s %s %s %s %s %s %s %s %s", \
                            sDatatypeName[0].c_str (), \
                            sDatatypeName[1].c_str (), \
                            sDatatypeName[2].c_str (), \
                            sDatatypeName[3].c_str (), \
                            sDatatypeName[4].c_str (), \
                            sDatatypeName[5].c_str (), \
                            sDatatypeName[6].c_str (), \
                            sDatatypeName[7].c_str (), \
                            sDatatypeName[8].c_str (), \
                            sDatatypeName[9].c_str ());
                    sMainCode = ExcelUtils::findAndInsert (sMainCode, sReplace, sCode, AFTER);
                }
            }
#endif
            sDatatypeName.clear ();
        }
    }

    return (sCode);
}
