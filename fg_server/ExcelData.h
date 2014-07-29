
#ifndef __EXCELDATA_H
#define __EXCELDATA_H 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stdarg.h>

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
    "\tvoid dump (void);\n"                             \
    "};\n"                                              \
    "extern Sheetxxxxx* shxxxxx;\n"

#define     STRUCTURE_SHEETDATA_SHEETDATA \
    "SheetxxxxxData::SheetxxxxxData ()\n"               \
    "{\n"                                               \
    "}\n\n"

#define     STRUCTURE_SHEET_GETROW \
    "SheetxxxxxData* Sheetxxxxx::getRow (int n)\n"        \
    "{\n"                                               \
    "\tif (n<0 || n>row_num)\n"                         \
    "\t\treturn (NULL);\n"                              \
    "\telse\n"                                          \
    "\t\treturn (&data[n]);\n"                          \
    "}\n\n"

#define     STRUCTURE_SHEET_GETALL \
    "vector<SheetxxxxxData*> Sheetxxxxx::getAll ()\n"    \
    "{\n"                                               \
    "\tvector<SheetxxxxxData*> res;\n"                  \
    "\tfor (int i=0; i<row_num; i++) {\n"               \
    "\t\tres.push_back (&data[i]);\n"                   \
    "\t}\n\n"                                           \
    "\treturn (res);\n"                                 \
    "}\n\n"

#define     STRUCTURE_SHEET_INIT \
    "int Sheetxxxxx::init ()\n"                         \
    "{\n"                                               \
    "\tFILE *fp;\n"                                     \
    "\tfp = fopen (\"./xxxxx.txt\", \"rb\");\n"          \
    "\tif (fp == NULL) {\n"                             \
    "\t\tprintf (\"no sheet file [%s]\\n\", \"xxxxx.txt\");\n" \
    "\t\treturn (-1);\n"                                \
    "\t}\n\n"                                           \
    \
    "\tSheetUtils::skipBom (fp);\n"                     \
    "\tstring value = \"\";\n"                          \
    "\trow_num = 0;\n"                                  \
    "\tname = \"xxxxx.txt\";\n"                          \
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
    "}\n\n"

#define     STRUCTURE_SHEET_INITLINK \
    "int Sheetxxxxx::initLink ()\n"                     \
    "{\n"                                               \
    "\treturn (0);\n"                                   \
    "}\n\n"

#define     STRUCTURE_INITSHEETS_BEGIN \
    "int SheetUtils::initSheets ()\n"                 \
    "{\n"

#define     STRUCTURE_INITSHEETS_END   \
    "\treturn (0);\n"                                   \
    "}\n"

#define     STRUCTURE_INITSHEETS_CONTENT   \
    "\tshxxxxx = new Sheetxxxxx;\n"                     \
    "\tif (shxxxxx->init() != 0) return (-1);\n"        \
    "\tif (shxxxxx->initLink() != 0) return (-1);\n"

#define     STRUCTURE_INCLUDES  \
    "\n\n"                                                \
    "#include \"SheetBase.h\"\n"                           \
    "#include \"Sheet.h\"\n"                           \
    "\n"                                                \
    "using namespace std;\n\n\n"

#define     STRUCTURE_SHEETS_DEFINE     "Sheetxxxxx* shxxxxx = NULL;\n"


#define     STRUCTURE_IFNDEF_DEFINE \
    "\n"                                                \
    "#ifndef __SHEET_H__\n"                             \
    "#define __SHEET_H__\n"                             \
    "\n"                                                \
    "#include \"SheetBase.h\"\n"                        \
    "#include <iostream>\n" \
    "#include <vector>\n" \
    "#include <map>\n" \
    "\n"                                                \
    "using namespace std;\n"

    

#define     STRUCTURE_ENDIF \
    "#endif // __SHEET_H__\n"


#define     STRUCTURE_DUMP_BEGIN \
    "void Sheetxxxxx::dump ()\n"                        \
    "{\n"                                               \
    "\tfor (int i=0; i<row_num; i++) {\n"

#define     STRUCTURE_DUMP_CONTENT \
    "\t\tcout << \"Sheetxxxxx\" << \"[\" << i << \"] :: data.\" << \"yyyyy\" << \" = \" << zzzzz << endl;\n"

#define     STRUCTURE_DUMP_END \
    "\t}\n" \
    "}\n"


#define     STRUCTURE_TRY_FIND_BY_PK_INH \
    "\tstd::map<yyyyy, int> index_zzzzz;\n"

#define     STRUCTURE_FIND_BY_PK_INH \
    "\tSheetxxxxxData* findByzzzzz (yyyyy _zzzzz);\n" \
    "\tSheetxxxxxData* tryFindByzzzzz (yyyyy _zzzzz);\n"

#define     STRUCTURE_TRY_FIND_BY_PK \
    "SheetxxxxxData* Sheetxxxxx::tryFindByzzzzz (yyyyy _zzzzz)\n"          \
    "{\n" \
    "\tmap<yyyyy, int>::iterator itor = index_zzzzz.find (_zzzzz);\n"   \
    "\tif (itor != index_zzzzz.end()) {\n" \
    "\t\treturn (&data[itor->second]);\n"   \
    "\t}\n" \
    "\telse {\n" \
    "\t\treturn (NULL);\n" \
    "\t}\n}\n\n"

#define     STRUCTURE_FIND_BY_PK \
    "SheetxxxxxData* Sheetxxxxx::findByzzzzz (yyyyy _zzzzz)\n" \
    "{\n" \
    "\tSheetxxxxxData* retVal = tryFindByzzzzz (_zzzzz);\n" \
    "\tif (NULL == retVal)\n" \
    "\t\tcout << \"Sheet [xxxxx] Key [\" << _zzzzz << \"] not exists\\n\";\n" \
    "\treturn (retVal);\n" \
    "}\n\n"


// Key
#define     STRUCTURE_TRY_FIND_BY_KEY_INH \
    "\tstd::multimap<yyyyy, int> index_zzzzz;\n"

#define     STRUCTURE_FIND_BY_KEY_INH \
    "\tstd::vector<SheetxxxxxData*> findByzzzzz (yyyyy _zzzzz);\n"

#define     STRUCTURE_FIND_BY_KEY \
    "vector<SheetxxxxxData*> Sheetxxxxx::findByzzzzz (yyyyy _zzzzz)\n" \
    "{\n"                                                           \
    "\tpair<multimap<yyyyy, int>::iterator, multimap<yyyyy, int>::iterator> i_f;\n" \
    "\ti_f = index_zzzzz.equal_range (_zzzzz);\n" \
    "\tvector<SheetxxxxxData*> res;\n\n" \
    "\tfor (multimap<yyyyy, int>::iterator itor = i_f.first; itor != i_f.second; itor++) {\n" \
    "\t\tres.push_back (&data[itor->second]);\n" \
    "\t}\n\n" \
    "\treturn (res);\n" \
    "}\n"

// Multi-Key
#define     STRUCTURE_MULTI_KEY_STRUCT \
    "struct aaaaa {\n"    \
    "bbbbb" \
    "\taaaaa();\n" \
    "\taaaaa(ccccc) {\n" \
    "ddddd" \
    "\t}\n" \
    "\tbool operator<(const aaaaa& s) const {\n" \
    "eeeee" \
    "\t\treturn (false);\n" \
    "\t}\n};\n"

#define     STRUCTURE_MULTI_KEY_DEFINE \
    "\tstd::multimap<aaaaa, int> index_bbbbb;\n"

#define     STRUCTURE_FIND_BY_MULTI_KEY_INH \
    "\tstd::vector<SheetxxxxxData*> findByaaaaa (bbbbb);\n"

#define     STRUCTURE_FIND_BY_MULTI_KEY \
    "vector<SheetxxxxxData*> Sheetxxxxx::findByaaaaa (bbbbb)\n" \
    "{\n"                                                           \
    "\tpair<multimap<ccccc, int>::iterator, multimap<ccccc, int>::iterator> i_f;\n" \
    "\ti_f = index_ddddd.equal_range (eeeee);\n" \
    "\tvector<SheetxxxxxData*> res;\n\n" \
    "\tfor (multimap<ccccc, int>::iterator itor = i_f.first; itor != i_f.second; itor++) {\n" \
    "\t\tres.push_back (&data[itor->second]);\n" \
    "\t}\n\n" \
    "\treturn (res);\n" \
    "}\n"


typedef pair<string, string> nameValue;

namespace MultiKeyUtils
{
    string getMultiKeyStruct (string& structName, char* fmt, ...);
    string getFindByMultiKey (string& sClassName, char* fmt, ...);
    string getFindByMultiKeyINH (string& sClassName, char* fmt, ...);
    string getMultiKeyDefine (string& sClassName, char* fmt, ...);
};

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

    // for index
    string  _fields;
    string  _type;

public:
    ExcelField () {
        _name = "";
        _toName = "";
        _dataType = "";
        _defaultValue = "";
        _localizable = "";
        _useTip = "";
        _fields = "";
        _type = "";

        isIndexField = false;
    }
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
    string  fields () {
        return (_fields);
    }
    string  type () {
        return (_type);
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
    void fields (string& s) {
        _fields = s;
    }
    void type (string& s) {
        _type = s;
    }


    int convert ();
public:
    bool isIndexField;
    vector<nameValue> Properties;

    void dump ();

    string productSheetDataInH (string sCode);
    string productSheetData (string sCode);

    string productSheetInit (string sCode);
    string productSheetDump     (void);

    string productFindByPK    (string, string);
    string productTryFindByPK (string, string);
    string productTryFindByPKInH (string, string);
    string productFindByPKInH (string, string);
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
    string productInitSheets    (void);
    string productSheetDefine   (void);
    string productSheetDump     (void);

    // PK
    string productTryFindByPKInH(string);
    string productFindByPKInH   (string);
    string productTryFindByPK   (void);
    string productFindByPK      (void);
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
