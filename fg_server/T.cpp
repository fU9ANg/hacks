
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

using namespace std;

#define D(fmt, ...) \
    printf (fmt, ##__VA_ARGS__)

enum InstFlag
{
    BEFORE = 1,
    AFTER  = 2,
};

string findAndReplace (string sCode, string subStr, string repStr)
{
    // find and replace

    size_t pos, len;
    len = subStr.size ();
    while ((pos = sCode.find (subStr)) != string::npos) {
        sCode.replace (pos, len, repStr);
    }
    return (sCode);
}

string findAndInsert (string sCode, string subStr, string instStr, enum InstFlag flag)
{
    // find and insert

    size_t pos, len;
    len = subStr.size();
    if ((pos = sCode.find (subStr)) != string::npos) {
    
        if (flag == BEFORE)
            sCode.insert (pos    , instStr); // before insert
        else if (flag == AFTER)
            sCode.insert (pos+len, instStr); // after  insert
    }

    return (sCode);
}

#define _SheetIndexTypexxxxxArg \
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

string getsCode (string& structName, char* fmt, ...) {
    va_list ap;
    int     p;
    int     i;
    string  type;
    string  name;
    string  str1, str2, str3, str4;

    structName = "_SheetIndexType" + structName;

    va_start (ap, fmt);
    while (*fmt) {
        if (*fmt == '%' && *(fmt+1) == 's') {
            if (type.empty ()) {
                type = va_arg (ap, char*);
            }
            else {
                name = va_arg (ap, char*);

                structName += name;

                str1 += "\t" + type + " " + name + ";\n";
                str2 += type + " _" + name + ",";
                str3 += "\t\t" + name + " = _" + name + ";\n";
                str4 += "\t\tif (this->" + name + "<s." + name + ") return (true);\n";
                str4 += "\t\tif (this->" + name + ">s." + name + ") return (false);\n";

                type.clear ();
            }
        }

        fmt++;
    }
    va_end (ap);

    string sCode = _SheetIndexTypexxxxxArg;
    sCode = findAndReplace (sCode, "aaaaa", structName);
    sCode = findAndReplace (sCode, "bbbbb", str1);
    sCode = findAndReplace (sCode, "ccccc", str2);
    sCode = findAndReplace (sCode, "ddddd", str3);
    sCode = findAndReplace (sCode, "eeeee", str4);

    printf ("%s", sCode.c_str());

    return ("");
}

int main ()
{
    string name = "CombatMonster";
    getsCode (name, "%s %s, %s %s", "string", "CombatId", "int", "MonsterId");
    printf ("name = %s\n", name.c_str());
}
