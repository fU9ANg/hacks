
#include <iostream>
#include <string>
#include <stdlib.h>

#include "xml_parser.h"

#define TEST_FOR    1

using namespace std;

int main ()
{

    if (TEST_FOR == 1)
    {
        XMLPARSER->Dump ();
    }
    
    else if (TEST_FOR == 2)
    {
        cout << "found: " << XMLPARSER->getResourceByEncoding ("001", "02", "101") << endl;
        cout << "found: " << XMLPARSER->getResourceByName ("动物", "昆虫", "100") << endl;
    }
    
    else if (TEST_FOR == 3)
    {
        string s1, s2, s3;
        if (XMLPARSER->getEncodingByResource ("buildhouse/小蝴蝶.png", s1, s2, s3))
        {
            cout << "resouce coding = " << s1 << endl;
            cout << "type coding = " << s2 << endl;
            cout << "reference coding = " << s3 << endl;
        }
    }

}

