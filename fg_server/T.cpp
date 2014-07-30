
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

#define     STRUCTURE_MULTI_KEY_DEFINE \
    "\tstd::multimap<aaaaa, int> index_bbbbb;\n"

#define     STRUCTURE_FIND_BY_MULTI_KEY_INH \
    "\tstd::vector<SheetxxxxxData*> findByaaaaa (bbbbb);\n"

#define     STRUCTURE_FIND_BY_MULTI_KEY \
    "vector<SheetxxxxxData*> Sheetxxxxx::findByaaaaa (bbbbb)\n" \
    "{\n"                                                           \
    "\tpair<multimap<ccccc, int>::iterator, multimap<ccccc, int>::iterator> i_f;\n" \
    "\ti_f = index_ddddd.equal_range (eeeee);\n" \
    "\tvector<SheetxxxxxData*> res;\n\n" \
    "\tfor (multimap<ccccc, int>::iterator itor = i_f.first; itor != i_f.second; itor++) {\n" \
    "\t\tres.push_back (&data[itor->second]);\n" \
    "\t}\n\n" \
    "\treturn (res);\n" \
    "}\n"

string getMultiKeyDefine (string& sClassName, char* fmt, ...) {
    va_list ap;
    int     p;
    int     i;
    string  type;
    string  name;
    string  str1, str2;

    str1 = "_SheetIndexType" + sClassName;

    va_start (ap, fmt);
    while (*fmt) {
        if (*fmt == '%' && *(fmt+1) == 's') {
            if (type.empty ()) {
                type = va_arg (ap, char*);
            }
            else {
                name = va_arg (ap, char*);

                str1 += name;
                str2 += name + "_";
                type.clear ();
            }
        }

        fmt++;
    }
    va_end (ap);

    str2 = str2.substr (0, str2.size() -1);
    string sCode = STRUCTURE_MULTI_KEY_DEFINE;
    sCode = findAndReplace (sCode, "aaaaa", str1);
    sCode = findAndReplace (sCode, "bbbbb", str2);

    printf ("%s", sCode.c_str());

    return ("");
}

string getFindByMultiKeyINH (string& sClassName, char* fmt, ...) {
    va_list ap;
    int     p;
    int     i;
    string  type;
    string  name;
    string  str1, str2;

    va_start (ap, fmt);
    while (*fmt) {
        if (*fmt == '%' && *(fmt+1) == 's') {
            if (type.empty ()) {
                type = va_arg (ap, char*);
            }
            else {
                name = va_arg (ap, char*);

                str1 += name;
                str2 += type + " _" + name + ",";
                type.clear ();
            }
        }

        fmt++;
    }
    va_end (ap);

    str2 = str2.substr (0, str2.size() -1);
    string sCode = STRUCTURE_FIND_BY_MULTI_KEY_INH;
    sCode = findAndReplace (sCode, "xxxxx", sClassName);
    sCode = findAndReplace (sCode, "aaaaa", str1);
    sCode = findAndReplace (sCode, "bbbbb", str2);

    printf ("%s", sCode.c_str());

    return ("");
}

string getFindByMultiKey (string& sClassName, char* fmt, ...) {
    va_list ap;
    int     p;
    int     i;
    string  type;
    string  name;
    string  str1, str2, str3, str4, str5;

    str3 = "_SheetIndexType" + sClassName;

    va_start (ap, fmt);
    while (*fmt) {
        if (*fmt == '%' && *(fmt+1) == 's') {
            if (type.empty ()) {
                type = va_arg (ap, char*);
            }
            else {
                name = va_arg (ap, char*);

                str1 += name;
                str2 += type + " _" + name + ",";
                str3 += name;
                str4 += name + "_";
                str5 += "_" + name + ",";
                type.clear ();
            }
        }

        fmt++;
    }
    va_end (ap);

    str2 = str2.substr (0, str2.size() -1);
    str4 = str4.substr (0, str4.size() -1);
    str5 = str5.substr (0, str5.size() -1);
    string sCode = STRUCTURE_FIND_BY_MULTI_KEY;
    sCode = findAndReplace (sCode, "xxxxx", sClassName);
    sCode = findAndReplace (sCode, "aaaaa", str1);
    sCode = findAndReplace (sCode, "bbbbb", str2);
    sCode = findAndReplace (sCode, "ccccc", str3);
    sCode = findAndReplace (sCode, "ddddd", str4);
    sCode = findAndReplace (sCode, "eeeee", str3 + "(" + str5 + ")");

    printf ("%s", sCode.c_str());

    return ("");
}

string getMultiKeyStruct (string& structName, char* fmt, ...) {
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

    str2 = str2.substr (0, str2.size() -1);
    string sCode = _SheetIndexTypexxxxxArg;
    sCode = findAndReplace (sCode, "aaaaa", structName);
    sCode = findAndReplace (sCode, "bbbbb", str1);
    sCode = findAndReplace (sCode, "ccccc", str2);
    sCode = findAndReplace (sCode, "ddddd", str3);
    sCode = findAndReplace (sCode, "eeeee", str4);

    printf ("%s", sCode.c_str());

    return ("");
}

std::string& trim(std::string &s)   
{  
    if (s.empty()) {  
        return s;
    }

    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1); 
    return s;
}

int main ()
{
#if 0
    string name;
    name = "COMBATMONSTERPLAYER";
    printf ("-------------------------------------------------------------\n");
    getMultiKeyStruct (name, "%s %s %s %s %s %s", "string", "CombatId", "int", "MonsterId", "int", "PlayerId");
    name.clear();
    name = "COMBATMONSTERPLAYER";
    printf ("-------------------------------------------------------------\n");
    getMultiKeyDefine (name, "%s %s %s %s %s %s", "string", "CombatId", "int", "MonsterId", "int", "PlayerId");
    name.clear();
    name = "COMBATMONSTERPLAYER";
    printf ("-------------------------------------------------------------\n");
    getFindByMultiKeyINH (name, "%s %s %s %s %s %s", "string", "CombatId", "int", "MonsterId", "int", "PlayerId");
    name.clear();
    name = "COMBATMONSTERPLAYER";
    printf ("-------------------------------------------------------------\n");
    getFindByMultiKey (name, "%s %s %s %s %s %s", "string", "CombatId", "int", "MonsterId", "int", "PlayerId");
    name.clear();
    name = "COMBATMONSTERPLAYER";
    printf ("-------------------------------------------------------------\n");
    //printf ("name = %s\n", name.c_str());
#else
    //string sFields = "CombatId, PlayerId,   MonsterId";
    string sFields = "CombatId   ";
    string sField = "";
    printf ("sFields=%s\n", sFields.c_str ());

    while (1) {
        int pos = sFields.find (',');
        if (pos == 0) {
            sFields = sFields.substr (1);
            continue;
        }
        if (pos < 0) {
            trim (sFields);
            sField = sFields;
            sFields = "";
            goto success;
            break;
        }
        sField = sFields.substr (0, pos);
        sFields= sFields.substr (pos+1);
success:
        trim (sField);
        printf ("[DEBUG2]:'%s'\n", sField.c_str ());
        if (sFields.empty ()) {
            break;
        }
    }
#endif
}
