
#ifndef __SHEET_H
#define __SHEET_H

#include "SheetBase.h"

class SheetTestData : public SheetBaseData
{
public:
    SheetTestData ();
    int value1;
    int value2;
    int value3;
};

class SheetTest : public SheetBase
{
private:
    SheetTestData* data;
public:
    vector<SheetTestData*> getAll ();
    SheetTestData* getRow (int n);
    bool forEach (SheetTestData& item);
    virtual int init ();
    virtual int initLink ();
};

#endif // __SHEET_H
