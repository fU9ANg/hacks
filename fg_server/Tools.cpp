
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
                //printf ("attr.name() = %s\n", attr.name ());
                if (string(attr.name()) == "fields") {
                    ef.isIndexField = true;
                    //printf ("222222222 attr.name() = %s\n", attr.name ());
                }
                if (string(attr.name()) == "type") {
                    string attr_value = attr.value ();
                    ef.type (attr_value);
                    printf ("222222222 attr.name() = %s, attr.value() = %s\n", \
                            attr.name (), \
                            attr.value ());
                }
            }
            //std::cout << std::endl;
            es.Fields.push_back (ef);
        }


        // property
        for (xml_attribute attr = sheet.first_attribute (); attr; attr = attr.next_attribute ()) {
            //std::cout << " " << attr.name () << "=" << attr.value ();
            nameValue nv = nameValue (attr.name(), attr.value ());
            es.Properties.push_back (nv);
        }
        //std::cout << std::endl;

        table.Sheets.push_back (es);

    }

    std::cout << "----------------DUMP SHEETS--------------------\n";
    //table.dumpSheets ();

    // TODO:
#if 1
    table.convertSheets ();
    table.product ();
#else

#endif
    return (0);
}
