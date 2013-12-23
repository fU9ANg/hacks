
/*
<xml>
    <Protocol name="CT_LOGIN" number="auto/N" handler="HandleLogin" return_protocol="Y/N" file="auto/HandleLogin.cpp" note="这里添加相应的注释。">
         <Structure name="sLogin" constructor="Y/N" operator="Y/N" note="这里添加相应的注释。">
             <Member name="m_clientType" type="enum" note="这里添加相应的注释。">
                 <Enumeration name="eLOGIN_TEACHER" number="auto/N" note="这里添加相应的注释。" />
                 <Enumeration name="eLOGIN_STUDENT" number="auto/N" note="这里添加相应的注释。" />
             </Member>
             <Member name="m_username" type="char" size="40" note="这里添加相应的注释。"/>
             <Member name="m_password" type="char" size="50" note="这里添加相应的注释。"/>
             <Member name="m_playerid" type="int" note="这里添加相应的注释。"/>
             <Member name="m_posx" type="float" note="这里添加相应的注释。"/>
             <Member name="m_posy" type="float" note="这里添加相应的注释。"/>
             <Member name="m_dirx" type="unsigned int" note="这里添加相应的注释。"/>
             <Member name="m_diry" type="unsigned int" note="这里添加相应的注释。"/>
             <Member name="m_speed" type="long" note="这里添加相应的注释。"/>
             <Member name="m_speed" type="unsigned long" note="这里添加相应的注释。"/>
         </Structure>
     </Protocol>

</xml>
*/

#include <vector>
#include <iostream>
#include <string>

using namespace std;

#define SPACE0  ""
#define SPACE1  " "
#define SPACE2  "  "
#define SPACE3  "   "
#define TAB1    "    "
#define TAB2    "        "
#define TAB3    "            "
#define TAB4    "                "

class CEnum;
class CMember;
class CStructure;
class CProtocol;

typedef vector<CProtocol>  VECTORPROTOCOL;
typedef vector<CMember>    VECTORMEMBER;
typedef vector<CEnum>      VECTORENUM;


class CEnum
{
public:
    string          name;
    string          number;
    string          note;
};

class CMember
{
public:
    string          name;
    string          type;
    string          typen;
    string          size;
    string          note;
    VECTORENUM      vec_enum;
};

class CStructure
{
public:
    string          name;
    string          ishas_cons;
    string          ishas_op;
    string          note;
    VECTORMEMBER    vec_member;
};

class CProtocol
{
public:
    string          name;
    string          number;
    string          handler;
    string          return_protocol;
    string          file;
    string          note;
    CStructure      structure;
};


// PROTOTYPES.
bool checkcontent (string sFile, string chkcontent);
bool LoadXml (VECTORPROTOCOL* vProtocol, string& fName);
void dumpNodes (VECTORPROTOCOL* vProtocol);
void cleanNodes (VECTORPROTOCOL* vProtocol);
bool replace (string sFile, string sFlag, string content, string chkcontent, bool iscontinue, bool seek);
bool autoBuildProtocol (string& sName, string& sNumber, bool return_protocol, string& sNote);
bool autoBuildHandler (string& pName, string& sFile, string& sHandler);
bool autoBuildMakefile (string& sFile);
bool checkcontent (string sFile, string content);
bool autoBuildMethod (string& members, string member_name, string member_type, string member_typen);
bool autoBuildCons (string& members, string structure_name, VECTORMEMBER* vec_member);
bool autoBuild (VECTORPROTOCOL* vProtocol);

