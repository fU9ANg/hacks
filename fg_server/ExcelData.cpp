
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
        sCode = itSheet->productSheetDataInH ();
        sIncludeFile += sCode;
        //printf ("%s", sCode.c_str());
        sCode = itSheet->productSheetInH ();
        sCode = itSheet->productTryFindByPKInH (sCode);
        sCode = itSheet->productFindByPKInH (sCode);
        sIncludeFile += sCode;
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
}




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

string ExcelField::productTryFindByPKInH ()
{
    string sCode;

    if (type() == "PK")
        sCode = STRUCTURE_TRY_FIND_BY_PK_INH;
    else if (type() == "KEY")
        sCode = STRUCTURE_TRY_FIND_BY_KEY_INH;

    sCode = ExcelUtils::findAndReplace (sCode, "yyyyy", dataType ());
    sCode = ExcelUtils::findAndReplace (sCode, "zzzzz", fields());

    return (sCode);
}

string ExcelSheet::productTryFindByPKInH (string sCode)
{
    string sResult = sCode;
    string sFind = "Data *data;\n";


    vector<ExcelField>::iterator itField;
    for (itField = Fields.begin(); itField != Fields.end(); itField++) {
        if (itField->isIndexField) {
            sResult = ExcelUtils::findAndInsert (sResult, sFind, \
                    itField->productTryFindByPKInH(), AFTER);
        }
    }

    if (sResult == sCode)
        return (sCode);
    else
        return (sResult);
}
string ExcelField::productFindByPKInH ()
{
    string sCode;

    if (type() == "PK")
        sCode = STRUCTURE_FIND_BY_PK_INH;
    else if (type() == "KEY")
        sCode = STRUCTURE_FIND_BY_KEY_INH;

    sCode = ExcelUtils::findAndReplace (sCode, "yyyyy", dataType ());
    sCode = ExcelUtils::findAndReplace (sCode, "zzzzz", fields());


    return (sCode);
}
string ExcelSheet::productFindByPKInH   (string sCode)
{
    string sResult = sCode;
    string sFind = "\tvoid dump (void);";

    vector<ExcelField>::iterator itField;
    for (itField = Fields.begin(); itField != Fields.end(); itField++) {
        if (itField->isIndexField) {
            sResult = ExcelUtils::findAndInsert (sResult, sFind, \
                    itField->productFindByPKInH(), BEFORE);
        }
    }

    sResult = ExcelUtils::findAndReplace (sResult, "xxxxx", toName ());


    if (sResult == sCode)
        return (sCode);
    else
        return (sResult);
}

string ExcelField::productTryFindByPK   (void)
{
    string sCode = "";

    if (type() == "PK") {
        sCode = STRUCTURE_TRY_FIND_BY_PK;
        sCode = ExcelUtils::findAndReplace (sCode, "yyyyy", dataType ());
        sCode = ExcelUtils::findAndReplace (sCode, "zzzzz", fields());
    }

    return (sCode);
}

string ExcelSheet::productTryFindByPK   (void)
{
    string sCode = "";


    vector<ExcelField>::iterator itField;
    for (itField = Fields.begin(); itField != Fields.end(); itField++) {
        if (itField->isIndexField) {
            sCode+= itField->productTryFindByPK ();
            sCode = ExcelUtils::findAndReplace (sCode, "xxxxx", toName ());
        }
    }

    return (sCode);
}

string ExcelField::productFindByPK   (void)
{
    string sCode;

    if (type() == "PK")
        sCode = STRUCTURE_FIND_BY_PK;
    else if (type() == "KEY")
        sCode = STRUCTURE_FIND_BY_KEY;

    sCode = ExcelUtils::findAndReplace (sCode, "yyyyy", dataType ());
    sCode = ExcelUtils::findAndReplace (sCode, "zzzzz", fields());

    return (sCode);
}

string ExcelSheet::productFindByPK (void)
{
    string sCode = "";


    vector<ExcelField>::iterator itField;
    for (itField = Fields.begin(); itField != Fields.end(); itField++) {
        if (itField->isIndexField) {
            sCode+= itField->productFindByPK ();
            sCode = ExcelUtils::findAndReplace (sCode, "xxxxx", toName ());
        }
    }

    return (sCode);
}
