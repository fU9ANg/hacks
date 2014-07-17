
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

#define SheetFile   "DataSheet.xml"

int main (int argc, char** argv)
{
    xml_document doc;

    if (!doc.load_file (SheetFile))
    {
        printf ("can't load sheet file: %s\n", SheetFile);
        return (-1);
    }

    xml_node sheets = doc.child ("DataSheet");


    ExcelTable table;
    for (xml_node sheet = sheets.first_child(); sheet; sheet = sheet.next_sibling ()) {
        //std::cout << "Sheet:";

        ExcelSheet es;


        // child of Sheet
        for (xml_node field = sheet.first_child (); field; field = field.next_sibling ()) {
            //std::cout << "\tFiled:";
            ExcelField ef;
            // property
            for (xml_attribute attr = field.first_attribute (); attr; attr = attr.next_attribute ()) {
                //std::cout << " " << attr.name () << "=" << attr.value ();

                nameValue nv = nameValue (attr.name(), attr.value ());
                ef.Properties.push_back (nv);
            }
            std::cout << std::endl;
            es.Fields.push_back (ef);
        }


        // property
        for (xml_attribute attr = sheet.first_attribute (); attr; attr = attr.next_attribute ()) {
            //std::cout << " " << attr.name () << "=" << attr.value ();
            nameValue nv = nameValue (attr.name(), attr.value ());
            es.Properties.push_back (nv);
        }
        std::cout << std::endl;

        table.Sheets.push_back (es);

    }

    std::cout << "----------------DUMP SHEETS--------------------\n";
    //table.dumpSheets ();

    // TODO:
#if 0
    table.convertSheets ();
    table.Product ();
#else
    ExcelField f;
    string s;
    f.ProductSheetInH (s);

#endif
    return (0);
}
