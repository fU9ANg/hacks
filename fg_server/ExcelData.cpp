
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

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
        cout << " " << itPro->first << "=" <<itPro->second;
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
        printf ("\n---------------product-------------\n");
        sCode = itSheet->productSheetDataInH ();
        sIncludeFile += sCode;
        //printf ("%s", sCode.c_str());
        sCode = itSheet->productSheetInH ();
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
    printf ("---------------------------------------------------\n");
    printf ("%s", sIncludeFile.c_str ());
    printf ("+++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf ("%s", sSourceFile.c_str ());
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
    if (dataType () == "int")
        sInsert = TAB + toName () + " = 0;" + ENTER;
    else if (dataType () == "string")
        sInsert = TAB + toName () + " = \"\";" + ENTER;

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
