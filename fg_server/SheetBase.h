
#ifndef __SHEETBASE_H
#define __SHEETBASE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

namespace SheetUtils {
    bool readToken (FILE* fp, string& value);
    bool skipChar (FILE* fp, char ch);
    void skipBom (FILE* fp);
    int initSheets (void);
};

class SheetBase {
public:
    const char* name;
    int row_num;
    virtual int init () = 0;
    virtual int initLink () = 0;
    void for_each_begin () { _idx = 0; }
protected:
    int _idx;
};

class SheetBaseData {
public:
    SheetBaseData () { _row_id = 0; _isok = true; }
    bool     isOK () { return (_isok); }
    int      _row_id;
    bool       _isok;
};

#endif // __SHEETBASE_H
