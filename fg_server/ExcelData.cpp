
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
    vector<ExcelSheet>::iterator itSheet;
    for (itSheet = Sheets.begin(); itSheet != Sheets.end(); itSheet++) {
        string sCode = "";
        printf ("\n---------------product-------------\n");
        sCode = itSheet->productSheetDataInH ();
        printf ("%s", sCode.c_str());
        sCode = itSheet->productSheetInH ();
        printf ("%s", sCode.c_str());
        sCode = itSheet->productSheetData ();
        printf ("%s", sCode.c_str());

        sCode = itSheet->productSheetGetRow ();
        printf ("%s", sCode.c_str());
        sCode = itSheet->productSheetGetAll ();
        printf ("%s", sCode.c_str());
        sCode = itSheet->productSheetInit ();
        printf ("%s", sCode.c_str());
        sCode = itSheet->productSheetInitLink ();
        printf ("%s", sCode.c_str());
    }
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
