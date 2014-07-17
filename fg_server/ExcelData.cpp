
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

int ExcelTable::Product ()
{
    vector<ExcelSheet>::iterator itSheet;
    for (itSheet = Sheets.begin(); itSheet != Sheets.end(); itSheet++) {
        string sCode = "";
        printf ("\n---------------product-------------\n");
        sCode = itSheet->ProductSheetDataInH ();
        printf ("%s", sCode.c_str());
        sCode = itSheet->ProductSheetInH ();
        printf ("%s", sCode.c_str());
    }
}

string ExcelSheet::ProductSheetDataInH ()
{
    string sCode = "";
    string sSheetData = "";
    string sSheet = "";

    sSheetData = "Sheet" + _toName + "Data";
    sCode  = "class " + sSheetData + " : public " + SHEETBASEDATA + ENTER;
    sCode += string("{") + ENTER;
    sCode += string("public:") + ENTER;
    sCode += TAB + sSheetData + "();" + ENTER + ENTER;
    
    vector<ExcelField>::iterator itField;
    for (itField = Fields.begin(); itField != Fields.end(); itField++) {
        sCode = itField->ProductSheetDataInH (sCode);
    }
    sCode += string("};") + ENTER;

    //printf ("%s code is: %s", sSheetData.c_str(), sCode.c_str());
    return (sCode);

    // TODO: write code to file.
}

string ExcelField::ProductSheetDataInH (string sCode)
{
    sCode += TAB + dataType() + " " + toName () + ";"+ TAB + "//" + name () + ENTER;
    return (sCode);
}

string ExcelSheet::ProductSheetInH ()
{
    string sCode = "";
    string sSheetData = "";
    string sSheet = "";

    sSheetData = "Sheet" + _toName + "Data";
    sSheet = "Sheet" + _toName;

    sCode = "class " + sSheet + " : public " + SHEETBASE + ENTER;
    sCode += string("{") + ENTER;
    sCode += string("private:") + ENTER;
    sCode += TAB + sSheetData + " *data" + ENTER;
    sCode += string("public:") + ENTER;
    sCode += TAB + string("vector<") + sSheetData + "*> getAll ();" + ENTER;
    sCode += TAB + sSheetData + "* getRow (int n);" + ENTER;
    sCode += TAB + string("bool forEach (") + sSheetData + "& item);" + ENTER;
    sCode += TAB + string("virtual int init ();") + ENTER;
    sCode += TAB + string("virtual int initLink ();") + ENTER;
    sCode += string ("};") + ENTER;

    return (sCode);
    // TODO: write code to file.
}

string ExcelField::ProductSheetInH (string s)
{
#if 0
    // find and replace

    string sCode = "SheetTestxxxxx123456Data::Sheetxxxxx123456TestData ()\n";
    string subStr = "xxxxx123456";
    string repStr = "Reward";

    size_t pos, len;
    len = subStr.size ();
    while ((pos = sCode.find (subStr)) != string::npos) {
        sCode.replace (pos, len, repStr);
    }
    printf ("str=%s\n", sCode.c_str());
    return (sCode);
#else
    // find and insert

    string subStr = "public:\n";
    string insStr = "\tint value0;\n";
    string sCode = "SheetTestxxxxx123456Data::Sheetxxxxx123456TestData ()\n";
    sCode += "{\n";
    sCode += "public:\n";
    sCode += "\tint value1;\n";
    sCode += "};\n";
    
    size_t pos, len;
    len = subStr.size();
    if ((pos = sCode.find (subStr)) != string::npos) {
#if 0
        sCode.insert (pos    , insStr); // before insert
#else
        sCode.insert (pos+len, insStr); // after  insert
#endif
    }
    printf ("str=%s\n", sCode.c_str());

    printf ("%s\n", STRUCTURE_SHEETDATA);
    printf ("%s\n", STRUCTURE_SHEET);
    printf ("%s\n", STRUCTURE_SHEETDATA_SHEETDATA);
    printf ("%s\n", STRUCTURE_SHEET_GETALL);
    printf ("%s\n", STRUCTURE_SHEET_GETROW);
    printf ("%s\n", STRUCTURE_SHEET_INIT);
    printf ("%s\n", STRUCTURE_SHEET_INITLINK);

    return (sCode);
#endif
}
