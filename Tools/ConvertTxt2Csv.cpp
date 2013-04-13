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

void printTitleVector (void);
void printKVMap (void);
void clearKVMap (void);
void outKvTable (void);

typedef vector<string> TitleVector;
//typedef map<string, string>* KeyValueMap;
typedef map<int, map<string, string>> KeyValueTable;

TitleVector titleVector;
TitleVector titleVector2;
TitleVector* pTitleVector;
//KeyValueMap kvMap;
map<string, string> kvMap;
KeyValueTable kvTable;
int isUpdateTitle = 1;
string strIndex;
FILE* fo = NULL;

#define ISCSVFILE  strstr (strArgv.c_str(), ".csv")
#define ISTXTFILE  strstr (strArgv.c_str(), ".txt")

int isFirstLine  = 1;
int iRecord = 1;
bool ConvertCsvToTxt (string line)
{
	cout << "in ConvertCsvToTxt" << endl;
	getchar();
	char Line[1024];
	unsigned int idex = 0;

	memset (Line, 0x00, sizeof (Line));
	strncpy (Line, line.c_str(), line.size());

// 	if (isFirstLine == 1)
// 	{
		char* tokenPtr = strtok (Line, ",");
		while (tokenPtr != NULL)
		{
			cout << "tokenPtr: " << tokenPtr << endl;
			string sName(tokenPtr);
			if (isFirstLine == 1)
			{
				titleVector.push_back (sName);
			}
			else
				kvMap.insert(pair<string, string>(titleVector[idex++], tokenPtr));
			tokenPtr = strtok (NULL, ",");
		}

		if (isFirstLine == 1)
		{
			isFirstLine = 0;
		}
		else
		{
			kvTable.insert (pair<int, map<string, string>>(iRecord, kvMap));
			kvMap.clear ();
		}
		
		return true;
		getchar();
// 	}
// 	else
// 	{
// 		// TODO:
// 		return false;
// 	}
}

bool ConvertTxtToCsv (string line)
{
	string strName;
	string strValue;

	unsigned int iPos;

// 	cout << "ConvertTxtToCsv\n" << line << endl;
// 	getchar();

	//flags.iBegin = 1;
	if ((flags.iBegin == 0) && (!flags.sArrayName.empty()))
	{
		cout << "here: " << line << endl;
		/*
		cout << "[: " << line.find ('[') << " " << line.size() << endl;
		cout << "]: " << line.find (']') << " " << line.size() << endl;
		cout << "=: " << line.find ('=') << " " << line.size() << endl;
		cout << "{: " << line.find ('{') << " " << line.size() << endl;
		*/
		if ((line.find ('[') < line.size()) &&
			(line.find (']') < line.size()) &&
			(line.find ('=') < line.size()) &&
			(line.find ('{') < line.size()))
		{
			strIndex = line.substr(line.find('[')+1, line.find(']')-line.find('[')-1);
			cout << "HRER" << " strIndex= " << strIndex <<":"<< endl;
			//kvMap = new map<string, string>;
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
			cout << "--------------------" << endl;
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
			cout << "insert_index:" << atoi(strIndex.c_str()) << endl;
			kvTable.insert(pair<int, map<string, string>>(atoi(strIndex.c_str()), kvMap));
			kvMap.clear();
			strIndex.clear();
			//printTitleVector();
			//printKVMap();
			//clearKVMap();
			return (true);
		}

		if ((iPos = line.find (':')) > line.size())
		{
			return (true);
		}

		strName = line.substr(0, iPos);
		if ((iPos = line.find (':') + 1) > line.size())
		{
			return (true);
		}
		strValue = line.substr(iPos, line.size() - iPos);

		if ((iPos = strValue.find(',')+1) == strValue.size())
		{
			cout << "size:" << strValue.size()<< endl;
			strValue[strValue.size()-1] = 0x00;
			strValue.resize(strValue.size()-1);
			cout << "size:" << strValue.size()<< endl;
		}
		
		//cout << "Name:" << strName << endl;
		//cout << "Value:" << strValue << endl;
		
		if (isUpdateTitle == 1)
		{
			titleVector.push_back(strName);
		}
		else
		{
			titleVector2.push_back(strName);
		}
		//kvMap->insert (pair<string, string>(strName, strValue));
		kvMap.insert(pair<string,string>(strName,strValue));
		//cout << "insert Map " << "Name: " << strName << "Value: " << strValue << endl;
		

		return (true);
	}
	else
	{
		//
		if ((iPos = line.find (':')) > line.size())
		{
			return (true);
		}

		strName = line.substr(4, iPos - 4);
		if (!strName.empty())
		{
			flags.sArrayName = strName;
			cout << flags.sArrayName << " ,,,,, " \
				<< strName << endl;
			return (true);
		}
	}

	return (false);
}
#if 1
void outKvMap (map<string,string>* pMap)
{
	TitleVector::iterator itVec;
	map<string,string>::iterator itMap;
	string sName;
	//for (itVec = titleVector.begin(); itVec != titleVector.end(); itVec++)
	for (itVec = pTitleVector->begin(); itVec != pTitleVector->end(); itVec++)
	{
#if 1
		itMap = pMap->find (*itVec);
		if (itMap != pMap->end())
		{
			sName = itMap->second;
			if (ISTXTFILE)
				fwrite (sName.c_str(), sName.size(), 1, fo);
			cout << itMap->second;
			if ((itVec+1) != pTitleVector->end())
			{
				cout << ",";
				if (ISTXTFILE)
					fwrite (",", 1, 1, fo);
			}
		}
		else
		{
			cout << "-";
			if ((itVec+1) != pTitleVector->end())
			{
				cout << ",";
				if (ISTXTFILE)
					fwrite (",", 1, 1, fo);
			}
		}

#else
		cout << (*itVec) << endl;
		for (itMap = pMap->begin(); itMap != pMap->end(); itMap++)
		{
			cout << endl << itMap->first << ":" << itMap->second << endl;
		}
#endif
	}
	cout << endl;
	if (ISTXTFILE)
		fwrite ("\n", 1, 1, fo);

}
#endif
void outKvTable (void)
{
	KeyValueTable::iterator ittab;
	map<string, string> ::iterator it;
	for (ittab = kvTable.begin(); ittab != kvTable.end(); ittab++)
	{
		outKvMap (&(ittab->second));
#if 0
		cout << "----" << endl << "index:" << ittab->first << endl;
		for (it = ittab->second.begin(); it!=ittab->second.end(); it++)
		{
			cout << it->first << ":" << it->second << endl;
		}
#endif
	}
}

void printTitleVector ()
{
	TitleVector::iterator vit;
	if (pTitleVector == NULL) {
		cout << "out memory" << endl;
		return;
	}
	string sName;
	for (vit = pTitleVector->begin(); vit != pTitleVector->end(); vit++)
	{
		cout << *vit;
		sName = *vit;
		if (ISTXTFILE)
			fwrite (sName.c_str(), sName.size(), 1, fo);
		if ((vit+1) != pTitleVector->end())
		{
			cout << ",";
			if (ISTXTFILE)
				fwrite (",", 1, 1, fo);
		}
	}
	cout << endl;
	if (ISTXTFILE)
		fwrite ("\n", 1, 1, fo);
}
/*
void printKVMap (void)
{
	TitleVector::iterator vit;

	KeyValueMap::iterator it;

	for (vit = titleVector.begin(); vit != titleVector.end(); vit++)
	{
		it =  (kvMap.find (*vit));
		if (it != kvMap.end())
		{
			cout << it->second;
			if ((vit+1) != titleVector.end())
				cout << ",";
		}
		else
		{
			titleVector.push_back(it->first);
			--vit;
		}
	}
	cout << endl;
}

void clearKVMap (void)
{
	KeyValueMap::iterator it;
	for (it = kvMap.begin(); it != kvMap.end(); it)
	{
		kvMap.erase (it++);
	}
}
*/
int getLine(FILE* f, string& line);
int main (int argc, char** argv)
{
	(void) memset (&flags, 0x00, sizeof (sFlags));
#if 0
	if (argc != 2)
	{
		cout << "Usage: " << argv[0] << "<FileName>" << endl;
		return (1);
	}
	cout << "FILENAME: " << argv[1] << endl;

	FILE* fd;
	char sssss[1000];
	memset (sssss, 0x00, 1000);
	char idx = 0;
	int  ii = 0;
	int jj = 0;
	while ((idx = argv[1][jj++]) != 0x00)
	{
		sssss[ii++] = idx;
		if (idx == '\\')
		sssss[ii++] = '\\';
	}

	if ((fd = fopen("outoutout.txt", "r+")) < 0)
	{
		cout << "can't " << endl;
	}
	fwrite (sssss, strlen(sssss), 1, fd);
	if (fd) fclose (fd);
#endif
	int iargc = 1;
	unsigned int iargcPos;
	string strArgv, dstName;
	for (;iargc < argc; iargc++)
	{
		strArgv.append (argv[iargc]);
	}

		iargcPos = strArgv.rfind ('.');
		if (iargcPos < strArgv.size())
		{
			dstName = strArgv.substr(0, iargcPos);
			if (ISTXTFILE)
				dstName.append(".csv");
			else if (ISCSVFILE)
				dstName.append(".txt");
		}

		cout << strArgv << endl << dstName << endl ;
		getchar();
	#if 1
		string line;
		///fstream fin(strArgv.c_str());
		FILE* f = fopen(strArgv.c_str(), "r");
		if (!f) {
			cout << "can't open src file" << endl;
			return 1;
		} 
		while (getLine (f, line))
		{
			//line.c_str[line.size()] = '\n';
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
				cout << "-------------" << endl;
				if (ConvertCsvToTxt(line) == false)
				{
					cout << "ERROR - line: '" << line << "'" << endl;
					return (1);
				}
			}
			line = "";
			//cout << "Size: " << line.size() << "Line: " << line << endl;
		}

		fo = fopen(dstName.c_str(), "w");
		if (!fo) {
			cout << "can't open dst file" << endl;
			getchar();
			return 1;
		}
		printTitleVector();
		outKvTable();
		getchar();
	#endif
		if (f)
			fclose(f);
		if (fo)
			fclose (fo);

	return (0);
}


int getLine(FILE* f, string& line)
{
	int c;
	char buf[1024];
	int i;


	line.clear();
	memset(buf, 0, sizeof(buf));
	i = 0;
	while ((c = fgetc(f)) != EOF && c != '\n') {
		buf[i++] = c;
	}
	buf[i] = '\0';
	line.append(buf);

	if (c == EOF)
		return 0;
	return 1;
}