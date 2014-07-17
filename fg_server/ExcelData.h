
#ifndef __EXCELDATA_H
#define __EXCELDATA_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include "pugixml.hpp"
#include "pugiconfig.hpp"

using namespace pugi;
using namespace std;

enum InstFlag
{
    BEFORE = 1,
    AFTER  = 2,
};

#define     SHEETBASEDATA   "SheetBaseData"
#define     SHEETBASE       "SheetBase"
#define     TAB             "\t"
#define     ENTER           "\n"

#define     STRUCTURE_SHEETDATA \
    "class SheetxxxxxData : public SheetBaseData\n"     \
    "{\n"                                               \
    "public:\n"                                         \
    "\tSheetxxxxxData ();\n"                            \
    "};\n\n"

#define     STRUCTURE_SHEET     \
    "class Sheetxxxxx : public SheetBase\n"              \
    "{\n"                                               \
    "private:\n"                                        \
    "\tSheetxxxxxData *data;\n"                         \
    "public:\n"                                         \
    "\tvector<SheetxxxxxData*> getAll ();\n"            \
    "\tSheetxxxxxData* getRow (int n);\n"               \
    "\tbool forEach (SheetxxxxxData& item);\n"          \
    "\tvirtual int init ();\n"                          \
    "\tvirtual int initLink ();\n"                      \
    "};\n\n"

#define     STRUCTURE_SHEETDATA_SHEETDATA \
    "SheetxxxxxData::SheetxxxxxData ()\n"               \
    "{\n"                                               \
    "};\n\n"

#define     STRUCTURE_SHEET_GETROW \
    "SheetxxxxxData* Sheetxxxxx::getRow (int n)\n"        \
    "{\n"                                               \
    "\tif (n<0 || n>row_num)\n"                         \
    "\t\treturn (NULL);\n"                              \
    "\telse\n"                                          \
    "\t\treturn (&data[n]);\n"                          \
    "};\n\n"

#define     STRUCTURE_SHEET_GETALL \
    "vector<SheetxxxxxData*> Sheetxxxxx::getAll ()\n"    \
    "{\n"                                               \
    "\tvector<SheetxxxxxData*> res;\n"                  \
    "\tfor (int i=0; i<row_num; i++) {\n"               \
    "\t\tres.push_back (&data[i]);\n"                   \
    "\t}\n\n"                                           \
    "\treturn (res);\n"                                 \
    "};\n\n"

#define     STRUCTURE_SHEET_INIT \
    "int Sheetxxxxx::init ()\n"                         \
    "{\n"                                               \
    "\tFILE *fp;\n"                                     \
    "\tfp = fopen (\"./Test.txt\", \"rb\");\n"          \
    "\tif (fp == NULL) {\n"                             \
    "\t\tprintf (\"no sheet file [%s]\\n\", \"Test.txt\");\n" \
    "\t\treturn (-1);\n"                                \
    "\t}\n\n"                                           \
    \
    "\tSheetUtils::skipBom (fp);\n"                     \
    "\tstring value = \"\";\n"                          \
    "\trow_num = 0;\n"                                  \
    "\tname = \"Test.txt\";\n"                          \
    "\tvector<SheetxxxxxData> d;\n"                     \
    "\twhile (1) {\n"                                   \
    "\t\tSheetxxxxxData oneData;\n"                     \
    "\t\toneData._row_id = row_num++;\n"                \
    "\t\td.push_back (oneData);\n"                      \
    "\t\tif (!SheetUtils::skipChar (fp, '\\n')) break;\n"\
    "\t}\n\n"                                           \
    "\tdata = new SheetxxxxxData[d.size()];\n"          \
    "\tfor (size_t i=0; i<d.size(); i++)\n"             \
    "\t\tdata[i] = d[i];\n\n"                           \
    \
    "\tif (fp) fclose (fp);\n\n"                        \
    \
    "\treturn (0);\n"                                   \
    "};\n\n"

#define     STRUCTURE_SHEET_INITLINK \
    "int Sheetxxxxx::initLink ()\n"                     \
    "{\n"                                               \
    "};\n\n"

typedef pair<string, string> nameValue;

namespace ExcelUtils
{
    string findAndReplace (string sCode, string subStr, string repStr);
    string findAndInsert  (string sCode, string subStr, string repStr, enum InstFlag);
};

class ExcelField
{
private:
    string  _name;
    string  _toName;
    string  _dataType;
    string  _defaultValue;
    string  _localizable;
    string  _useTip;

public:
    // gets
    string  name () {
        return (_name);
    }
    string  toName () {
        return (_toName);
    }
    string  dataType () {
        return (_dataType);
    }
    string  defaultValue () {
        return (_defaultValue);
    }
    string  localizable () {
        return (_localizable);
    }
    string  useTip () {
        return (_useTip);
    }

    // gets
    void  name (string& s) {
        _name = s;
    }
    void  toName (string& s) {
        _toName = s;
    }
    void  dataType (string& s) {
        _dataType = s;
    }
    void  defaultValue (string& s) {
        _defaultValue = s;
    }
    void  localizable (string& s) {
        _localizable = s;
    }
    void  useTip (string& s) {
        _useTip = s;
    }


    int convert ();
public:
    vector<nameValue> Properties;

    void dump ();

    string productSheetDataInH (string sCode);
    string productSheetData (string sCode);
};

class ExcelSheet
{
private:
    string  _excelName;
    string  _name;
    string  _toName;
    string  _useTip;

public:
    // gets.
    string excelName () {
        return (_excelName);
    }
    string name () {
        return (_name);
    }
    string toName () {
        return (_toName);
    }
    string  useTip () {
        return (_useTip);
    }

    // sets
    void excelName (string& s) {
        _excelName = s;
    }
    void name (string& s) {
        _name = s;
    }
    void toName (string& s) {
        _toName = s;
    }
    void useTip (string& s) {
        _useTip = s;
    }

    int convert (); public:
    vector<ExcelField> Fields;
    vector<nameValue> Properties;

    void dump ();

    string productSheetData     (void);
    string productSheetDataInH  (void);
    string productSheetInH      (void);
    string productSheetGetRow   (void);
    string productSheetGetAll   (void);
    string productSheetInit     (void);
    string productSheetInitLink (void);
};

class ExcelTable
{
public:
    vector<ExcelSheet> Sheets;

    void dumpSheets ();
    int convertSheets ();
    int product ();
};

#endif  // __EXCELDATA_H
