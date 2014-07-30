
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include "SheetBase.h"
#include "Sheet.h"

void dump_test_data (SheetTestData* pdata)
{
    if (pdata) {
        printf ("SheetTestData.ID   = %d\n", pdata->ID);
        printf ("SheetTestData.Type = %d\n", pdata->Type);
        printf ("SheetTestData.Name = %s\n", pdata->Name.c_str());
    }
}

int main ()
{
    SheetUtils::initSheets ();
    
#if 0
    SheetTestData* pdata;
    pdata = shTest->getRow (0);
    dump_test_data (pdata);

    vector<SheetTestData*> datas;
    datas = shTest->getAll ();
    printf ("----------------- DUMP VECTOR -----------------\n");
    for (unsigned int i=0; i<datas.size(); i++) {
        printf ("SheetTestDatas[%d].ID   = %d\n", i+1, datas[i]->ID);
        printf ("SheetTestDatas[%d].Type = %d\n", i+1, datas[i]->Type);
        printf ("SheetTestDatas[%d].Name = %s\n", i+1, datas[i]->Name.c_str());
    }

    // test find by PK.
    pdata = shTest->findByID (7);
    dump_test_data (pdata);
#endif

#if 0
    shTest->dump ();
    shTest2->dump ();
    shPlayer->dump ();
    shMonster->dump ();
#endif

    return (0);
}
