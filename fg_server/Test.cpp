
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include "SheetBase.h"
#include "Sheet.h"

int main ()
{
    SheetTest st;
    st.init ();

    SheetTestData* pdata;
    pdata = st.getRow (0);
    if (pdata) {
        printf ("SheetTestData.value1 = %d\n", pdata->value1);
        printf ("SheetTestData.value2 = %d\n", pdata->value2);
        printf ("SheetTestData.value3 = %d\n", pdata->value3);
    }

    vector<SheetTestData*> datas;
    datas = st.getAll ();
    for (int i=0; i<datas.size(); i++) {
        printf ("SheetTestDatas[%d].value1 = %d\n", i+1, datas[i]->value1);
        printf ("SheetTestDatas[%d].value2 = %d\n", i+1, datas[i]->value2);
        printf ("SheetTestDatas[%d].value3 = %d\n", i+1, datas[i]->value3);
    }

    return (0);
}
