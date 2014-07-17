
#include "SheetBase.h"
#include "Sheet.h"

SheetTestData::SheetTestData ()
{
    value1 = 0;
    value2 = 0;
    value3 = 0;
}

SheetTestData* SheetTest::getRow (int n)
{
    if (n < 0 || n > row_num)
        return (NULL);
    else
        return (&data[n]);
}

vector<SheetTestData*> SheetTest::getAll ()
{
    vector<SheetTestData*> res;
    for (int i=0; i<row_num; i++) {
        res.push_back (&data[i]);
    }

    return (res);
}

int SheetTest::init ()
{
    FILE *fp;
    fp = fopen ("./Test.txt", "rb");

    if (fp == NULL) {
        printf ("no sheet file [%s]\n", "Test.txt");
        return (-1);
    }

    SheetUtils::skipBom (fp);
    string value = "";
    row_num = 0;
    name = "Test.txt";
    vector<SheetTestData> d;
    while (1) {
        SheetTestData oneData;
        SheetUtils::readToken (fp, value);
        oneData.value1 = atoi (value.c_str ());
        SheetUtils::readToken (fp, value);
        oneData.value2 = atoi (value.c_str ());
        SheetUtils::readToken (fp, value);
        oneData.value3 = atoi (value.c_str ());

        oneData._row_id = row_num++;
        d.push_back (oneData);

        if (!SheetUtils::skipChar (fp, '\n')) break;
    }

    data = new SheetTestData[d.size()];
    for (size_t i=0; i<d.size(); i++)
        data[i] = d[i];

    if (fp)
        fclose (fp);

    return (0);
}

int SheetTest::initLink ()
{
    // TODO:
}
