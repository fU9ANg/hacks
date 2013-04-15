//
// Convert Tool (between .txt and .csv file format)
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

typedef struct sFlags
{
	int iBegin;
	string sArrayName;		// ArrayName
	string sBracketsLeft;	// [
	string sBracketsRight;	// ]
	string sBracesLeft;		// {
	string sBracesRight;	// }
} sFlags;

sFlags flags;

void outTitleVector (void);
void outKvMap (map<string,string>* pMap);
void outKvTable (void);
void outCommon  (void);
int  getLine (FILE* f, string& line);
bool ConvertCsvToTxt (string line);
bool ConvertTxtToCsv (string line);
void createEnChMap (string file);

typedef vector<string> TitleVector;
typedef map<int, map<string, string> > KeyValueTable;

string STR_IMPORT("import flash.utils.Dictionary;\n");
string STR_VAR1("var ");
string STR_VAR2(":Dictionary = new Dictionary();\n");

TitleVector titleVector;
TitleVector titleVector2;
TitleVector* pTitleVector = &titleVector;
map<string, string> kvMap;
KeyValueTable kvTable;
int isUpdateTitle = 1;
string strIndex = "";
FILE* fo = NULL;
map<string, string> nameEnChMap;

#define ISCSVFILE  strstr (strArgv.c_str(), ".csv")
#define ISTXTFILE  strstr (strArgv.c_str(), ".txt")
#define BUFF_SIZE  1024

string strArgv, dstName;

int isFirstLine  = 1;
int isArrayName  = 1;
int iRecord = 0;
int idxArray = 0;

bool ConvertCsvToTxt (string line)
{
	char Line[BUFF_SIZE];
	unsigned int idex = 0;

	(void) memset (Line, 0x00, sizeof (Line));
#ifdef _WIN32
	(void) strncpy_s (Line, line.c_str(), line.size());
#else
	(void) strncpy (Line, line.c_str(), line.size());
#endif

	if (isArrayName == 1)
	{
		flags.sArrayName = "";
		unsigned int i;
		if ((i = line.find(',')) <= line.size())
			flags.sArrayName += line.substr(0, i);
		else
			flags.sArrayName += line;
		isArrayName = 0;
		return (true);
	}
	// process format "'xxkjdfk,skdfjksdkfjskf', 1, 100" ->
	// "'xxkjdfk skdfjksdkfjskf', 1, 100"
	unsigned int ii;
	unsigned int inTheString = 0;
	unsigned int iflags = 0;
	char         cChar;
	for (ii=0; ii<line.size(); ii++)
	{
		if (inTheString == 0)
		{
			if (line[ii] == '\'' ||\
				line[ii] == '\"' ||\
				line[ii] == '('  ||\
				line[ii] == '{'  ||\
				line[ii] == '[')
			{
				if (iflags == 0) {
					cChar = line[ii];
					inTheString = 1;
					iflags = 1;
				}
			}
		}
		else
		{
			if (line[ii] == '\'' ||\
				line[ii] == '\"' ||\
				line[ii] == ')'  ||\
				line[ii] == '}'  ||\
				line[ii] == ']')
			{
				if ((cChar == '(' && line[ii] == ')') ||\
					(cChar == '[' && line[ii] == ']') ||\
					(cChar == '{' && line[ii] == '}') ||\
					(cChar == line[ii])) {
						inTheString = 0;
						iflags = 0;
				}
			}
		}

		if (line[ii] == ',' && inTheString == 1)
			line[ii] = ' ';
	}
// 	cout << "process: line - " << line << endl;
// 	getchar();
	// split string format is "xxx,xxx,xxx,xxxxx"
	char token[BUFF_SIZE];
	unsigned int i = 0;
	int  j = 0;
	(void) memset (token, 0x00, sizeof (token));
	for (i=0; i<line.size(); )
	{
		if (line[i] == ',')
		{
			if (token[0] == 0x00) {
				idex++;
				i++;
				j = 0;
				continue;
			}
			if (isFirstLine == 1)
				titleVector.push_back(token);
			else
			{
				// set field id to index of array
				if (titleVector[idex] == "id")
					idxArray = atoi (token);
				kvMap.insert(pair<string,string>(titleVector[idex++], token));
			}
			(void) memset (token, 0x00, sizeof (token));
			j = -1;
		}
		else
		{
			token[j] = line[i];
		}

		i++;
		j++;
	}
	if (token[0] != 0x00)
	{
		if (isFirstLine == 1)
			titleVector.push_back(token);
		else
		{
			// set field id to index of array
			if (titleVector[idex] == "id")
				idxArray = atoi (token);
			kvMap.insert(pair<string,string>(titleVector[idex++], token));
		}
	}


	if (isFirstLine == 1)
	{
		isFirstLine = 0;
	}
	else
	{
		iRecord++;
		kvTable.insert (pair<int, map<string, string> > \
			(idxArray ? idxArray : iRecord, kvMap));
		kvMap.clear ();
	}

//
	return (true);
}

bool ConvertTxtToCsv (string line)
{
	string strName;
	string strValue;

	unsigned int iPos;

	if ((flags.iBegin == 0) && (!flags.sArrayName.empty()))
	{
		if ((line.find ('[') < line.size()) &&
			(line.find (']') < line.size()) &&
			(line.find ('=') < line.size()) &&
			(line.find ('{') < line.size()))
		{
			strIndex = line.substr(line.find('[')+1, line.find(']')-line.find('[')-1);
			flags.iBegin = 1;
			return (true);
		}
	}
	else if ((flags.iBegin == 1) && (!flags.sArrayName.empty()))
	{
		if ((line.find ('}') < line.size()) &&
			(line.find (';') <=line.size()))
		{
			flags.iBegin = 0;
			if (titleVector.size() > titleVector2.size())
			{
				pTitleVector = &titleVector;
				isUpdateTitle = 0;
				titleVector2.clear();
			}
			else 
			{
				pTitleVector = &titleVector2;
				isUpdateTitle = 1;
				titleVector.clear();
			}
			
			kvTable.insert(pair<int, map<string, string> >(atoi(strIndex.c_str()), kvMap));
// 			cout << "}; kvTable.size(): " << kvTable.size() << endl;
// 			getchar();
			kvMap.clear();
			strIndex.clear();
			return (true);
		}

		if ((iPos = line.find (':')) > line.size()) return (true);

		strName = line.substr(0, iPos);
		if ((iPos = line.find (':') + 1) > line.size()) return (true);

		strValue = line.substr(iPos, line.size() - iPos);

		if ((iPos = strValue.find(',')+1) == strValue.size())
		{
			strValue[strValue.size()-1] = 0x00;
			strValue.resize(strValue.size()-1);
		}
		
		if (isUpdateTitle == 1)
		{
			titleVector.push_back(strName);
		}
		else
		{
			titleVector2.push_back(strName);
		}
		// replace value ',' to ' £¬' of strValue (please fixme)
		string searchString (",");
		string replaceString (" ");

		string::size_type pos = 0;
		while ((pos = strValue.find(searchString, pos)) != string::npos) {
			strValue.replace(pos, searchString.size(), replaceString);
			pos++;
		}
// 		cout << "strName1: " << strName << endl;
// 		cout << "strValue1:" << strValue << endl;
// 		getchar();

		kvMap.insert(pair<string,string>(strName,strValue));
		

		return (true);
	}
	else
	{
		//
		if ((iPos = line.find (':')) > line.size()) return (true);

		strName = line.substr(4, iPos - 4);
		if (!strName.empty())
		{
			flags.sArrayName = strName;
			return (true);
		}
	}

	return (false);
}

void outKvMap (map<string,string>* pMap)
{
	TitleVector::iterator itVec;
	map<string,string>::iterator itMap;
	string sName;
	unsigned int iMapCount = 0;

	for (itVec = pTitleVector->begin(); itVec != pTitleVector->end(); itVec++)
	{
		itMap = pMap->find (*itVec);
		if (itMap != pMap->end())
		{
			iMapCount++;
			if (ISTXTFILE)
			{
				sName = itMap->second;
				fwrite (sName.c_str(), sName.size(), 1, fo);
			}

			if (ISCSVFILE)
			{
				sName = itMap->first;
				sName += ":";
				sName += itMap->second;
				fwrite (sName.c_str(), sName.size(), 1, fo);
				
			}
			if ((itVec+1) != pTitleVector->end()) // cout << ",";
			{
				if (ISTXTFILE)
					fwrite (",", 1, 1, fo);
				if (ISCSVFILE) {
					if (iMapCount != pMap->size())
						fwrite (",\n", 2, 1, fo);
				}
			}
		}
		else // cout << "-";
		{
			if ((itVec+1) != pTitleVector->end()) // cout << ",";
			{
				if (ISTXTFILE)
					fwrite (",", 1, 1, fo);
			}
		}

	}
	if (ISCSVFILE) // cout << endl;
		fwrite ("\n};", 3, 1, fo);
	fwrite ("\n", 1, 1, fo);
}

void outKvTable (void)
{
	string STR_ARRAYSIZE = "[";
	char cStr[32];
	memset (cStr, 0x00, sizeof (cStr));
	//int iArrayIndex = 0;

	KeyValueTable::iterator ittab;
	map<string, string> ::iterator it;

	for (ittab = kvTable.begin(); ittab != kvTable.end(); ittab++)
	{
		if (ISCSVFILE)
		{
			STR_ARRAYSIZE = "[";
			memset (cStr, 0x00, sizeof (cStr));
			fwrite (flags.sArrayName.c_str(), flags.sArrayName.size(), 1, fo);
#ifdef _WIN32
			sprintf_s (cStr, "%d", ittab->first);
#else
			sprintf (cStr, "%d", ittab->first);
#endif
			STR_ARRAYSIZE += cStr;
			STR_ARRAYSIZE += "] = {\n";
			fwrite (STR_ARRAYSIZE.c_str(), STR_ARRAYSIZE.size(), 1, fo);
		}
		outKvMap (&(ittab->second));
	}
}

void outTitleVector ()
{
#if 0
	TitleVector::iterator vit;
	if (pTitleVector == NULL) {
		cout << "out memory" << endl;
		return;
	}
	string sName;
	for (vit = pTitleVector->begin(); vit != pTitleVector->end(); vit++)
	{
		sName = *vit;
		if (ISTXTFILE)
			fwrite (sName.c_str(), sName.size(), 1, fo);
		if ((vit+1) != pTitleVector->end())
		{
			if (ISTXTFILE)
				fwrite (",", 1, 1, fo);
		}
	}

	if (ISTXTFILE)
		fwrite ("\n", 1, 1, fo);
#else
	TitleVector::iterator vit;
	if (pTitleVector == NULL) {
		cout << "out memory" << endl;
		return;
	}
	string sName;
	for (vit = pTitleVector->begin(); vit != pTitleVector->end(); vit++)
	{
		sName = *vit;
		if (ISTXTFILE)
			fwrite (sName.c_str(), sName.size(), 1, fo);
		if ((vit+1) != pTitleVector->end())
		{
			if (ISTXTFILE)
				fwrite (",", 1, 1, fo);
		}
	}

	if (ISTXTFILE)
		fwrite ("\n", 1, 1, fo);
#endif
}

void outCommon  (void)
{
	if (flags.sArrayName.size())
	{
		if (ISTXTFILE)
		{
			fwrite (flags.sArrayName.c_str(), flags.sArrayName.size(), 1, fo);
			fwrite ("\n", 1, 1, fo);
		}
		if (ISCSVFILE)
		{
			fwrite (STR_IMPORT.c_str(), STR_IMPORT.size(), 1, fo);
			fwrite (STR_VAR1.c_str(), STR_VAR1.size(), 1, fo);
			fwrite (flags.sArrayName.c_str(), flags.sArrayName.size(), 1, fo);
			fwrite (STR_VAR2.c_str(), STR_VAR2.size(), 1, fo);
		}
	}
}

int main (int argc, char** argv)
{
	(void) memset (&flags, 0x00, sizeof (sFlags));

	int iargc = 1;
	unsigned int iargcPos;
	
	for (;iargc < argc; iargc++)
	{
		strArgv.append (argv[iargc]);
	}

	iargcPos = strArgv.rfind ('.');
	if (iargcPos < strArgv.size())
	{
		dstName = strArgv.substr(0, iargcPos);
		if (ISTXTFILE)
		{
			createEnChMap(dstName);
			dstName.append(".csv");
		}
		else if (ISCSVFILE)
		{
			dstName.append(".txt");
		}
	}

#if 1
	string line;
#ifdef _WIN32
	FILE* f;
	fopen_s(&f, strArgv.c_str(), "r");
#else
	FILE* f = fopen(strArgv.c_str(), "r");
#endif
	if (!f) {
		cout << "can't open src file: '" << strArgv.c_str() << "'" << endl;
		return 1;
	} 
	while (getLine (f, line))
	{
		if (line == "\r\n" || line == "\r" || line =="\n")
			continue;

		//delete '\n' of end of line
		if (line[line.size()-1] == '\n')
		{
			line[line.size()-1] = 0x00;
			line.resize(line.size()-1);
		}

		if (ISTXTFILE)
		{
			if (ConvertTxtToCsv(line) == false)
			{
				cout << "ERROR - line: '" << line << "'" << endl;
				return (1);
			}
		}
		else
		{
			if (ConvertCsvToTxt(line) == false)
			{
				cout << "ERROR - line: '" << line << "'" << endl;
				return (1);
			}
		}
		line = "";
	}

#ifdef _WIN32
	fopen_s (&fo, dstName.c_str(), "w");
#else
	fo = fopen (dstName.c_str(), "w");
#endif
	if (!fo) {
		cout << "can't open dst file: '" << dstName.c_str() << "'" << endl;
		getchar();
		return 1;
	}
	outCommon ();
	outTitleVector ();
	outKvTable ();

#endif
	if (f)
		fclose(f);
	if (fo)
		fclose (fo);

	return (0);
}

void createEnChMap (string file)
{
	file.append ("_Config.csv");
	string line;
	string nameEn, nameCh;
	unsigned int iPos = 0;
#ifdef _WIN32
	FILE* f;
	fopen_s(&f, file.c_str(), "r");
#else
	FILE* f = fopen(file.c_str(), "r");
#endif
	if (!f) {
		cout << "can't open config file: '" << file.c_str() << "'" << endl;
		return;
	}
	while (getLine (f, line))
	{
		if (line == "\r\n" || line == "\r" || line =="\n")
			continue;

		//delete '\n' of end of line
		if (line[line.size()-1] == '\n')
		{
			line[line.size()-1] = 0x00;
			line.resize(line.size()-1);
		}

		iPos = line.find (',');
		if (iPos > line.size())
		{
			cout << "ERROR: ipos > line.size()\n";
			goto OUT;
		}
		nameEn = line.substr (0, iPos);
		nameCh = line.substr (iPos, line.size() - iPos);
		nameEnChMap.insert(pair<string, string>(nameEn, nameCh));
		cout << "en:" << nameEn << "ch:" << nameCh << endl;
	}

// 	cout << "HRERE";
// 	getchar();
OUT:
	if (f)
		fclose (f);
	
}
int getLine(FILE* f, string& line)
{
	int  c;
	int  i;
	char buf[BUFF_SIZE];

	line.clear();
	memset(buf, 0, sizeof(buf));
	i = 0;
	while ((c = fgetc(f)) != EOF && c != '\n') {
		buf[i++] = c;
	}

	if (c == '\n')
		buf[i++] = '\n';
	buf[i] = '\0';
	
	line.append(buf);

	return (i);
}
