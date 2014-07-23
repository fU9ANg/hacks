
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include "SheetBase.h"
#include "Sheet.h"

int main ()
{
    SheetUtils::initSheets ();
    
#if 0
    SheetTestData* pdata;
    pdata = shTest->getRow (0);
    if (pdata) {
        printf ("SheetTestData.ID   = %d\n", pdata->ID);
        printf ("SheetTestData.Type = %d\n", pdata->Type);
        printf ("SheetTestData.Name = %s\n", pdata->Name.c_str());
    }

    vector<SheetTestData*> datas;
    datas = shTest->getAll ();
    for (int i=0; i<datas.size(); i++) {
        printf ("SheetTestDatas[%d].ID   = %d\n", i+1, datas[i]->ID);
        printf ("SheetTestDatas[%d].Type = %d\n", i+1, datas[i]->Type);
        printf ("SheetTestDatas[%d].Name = %s\n", i+1, datas[i]->Name.c_str());
    }
#endif

    shTest->dump ();
    shTest2->dump ();
    shPlayer->dump ();
    shMonster->dump ();

    return (0);
}
