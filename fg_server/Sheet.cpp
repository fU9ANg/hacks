

#include "SheetBase.h"
#include "Sheet.h"

using namespace std;


SheetTest* shTest = NULL;
SheetTest2* shTest2 = NULL;
SheetPlayer* shPlayer = NULL;
SheetMonster* shMonster = NULL;
SheetTestData::SheetTestData ()
{
	ID = 0;
	Type = 0;
	Name = "";
}

SheetTestData* SheetTest::getRow (int n)
{
	if (n<0 || n>row_num)
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
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Type = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Name = value;
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetTestData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetTest::initLink ()
{
	return (0);
}

SheetTestData* SheetTest::tryFindByID (int _ID)
{
	map<int, int>::iterator itor = index_ID.find (_ID);
	if (itor != index_ID.end()) {
		return (&data[itor->second]);
	}
	else {
		return (NULL);
	}
}

SheetTestData* SheetTest::findByID (int _ID)
{
	SheetTestData* retVal = tryFindByID (_ID);
	if (NULL == retVal)
		cout << "Sheet [Test] Key [" << _ID << "] not exists\n";
	return (retVal);
}

void SheetTest::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetTest" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetTest" << "[" << i << "] :: data." << "Type" << " = " << data[i].Type << endl;
		cout << "SheetTest" << "[" << i << "] :: data." << "Name" << " = " << data[i].Name << endl;
	}
}
SheetTest2Data::SheetTest2Data ()
{
	ID2 = 0;
	Type2 = 0;
	Name2 = "";
}

SheetTest2Data* SheetTest2::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetTest2Data*> SheetTest2::getAll ()
{
	vector<SheetTest2Data*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetTest2::init ()
{
	FILE *fp;
	fp = fopen ("./Test2.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "Test2.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "Test2.txt";
	vector<SheetTest2Data> d;
	while (1) {
		SheetTest2Data oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Type2 = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Name2 = value;
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetTest2Data[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetTest2::initLink ()
{
	return (0);
}

void SheetTest2::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetTest2" << "[" << i << "] :: data." << "ID2" << " = " << data[i].ID2 << endl;
		cout << "SheetTest2" << "[" << i << "] :: data." << "Type2" << " = " << data[i].Type2 << endl;
		cout << "SheetTest2" << "[" << i << "] :: data." << "Name2" << " = " << data[i].Name2 << endl;
	}
}
SheetPlayerData::SheetPlayerData ()
{
	ID = 0;
	Name = "";
	Quality = 0;
	Level = 0;
}

SheetPlayerData* SheetPlayer::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetPlayerData*> SheetPlayer::getAll ()
{
	vector<SheetPlayerData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetPlayer::init ()
{
	FILE *fp;
	fp = fopen ("./Player.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "Player.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "Player.txt";
	vector<SheetPlayerData> d;
	while (1) {
		SheetPlayerData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Name = value;
		SheetUtils::readToken (fp, value);
		oneData.Quality = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.Level = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetPlayerData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetPlayer::initLink ()
{
	return (0);
}

SheetPlayerData* SheetPlayer::tryFindByID (int _ID)
{
	map<int, int>::iterator itor = index_ID.find (_ID);
	if (itor != index_ID.end()) {
		return (&data[itor->second]);
	}
	else {
		return (NULL);
	}
}

SheetPlayerData* SheetPlayer::findByID (int _ID)
{
	SheetPlayerData* retVal = tryFindByID (_ID);
	if (NULL == retVal)
		cout << "Sheet [Player] Key [" << _ID << "] not exists\n";
	return (retVal);
}

void SheetPlayer::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetPlayer" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetPlayer" << "[" << i << "] :: data." << "Name" << " = " << data[i].Name << endl;
		cout << "SheetPlayer" << "[" << i << "] :: data." << "Quality" << " = " << data[i].Quality << endl;
		cout << "SheetPlayer" << "[" << i << "] :: data." << "Level" << " = " << data[i].Level << endl;
	}
}
vector<SheetPlayerData*> SheetPlayer::findByIDNameQualityLevel (int _ID,string _Name,int _Quality,int _Level)
{
	pair<multimap<_SheetIndexTypePlayerIDNameQualityLevel, int>::iterator, multimap<_SheetIndexTypePlayerIDNameQualityLevel, int>::iterator> i_f;
	i_f = index_ID_Name_Quality_Level.equal_range (_SheetIndexTypePlayerIDNameQualityLevel(_ID,_Name,_Quality,_Level));
	vector<SheetPlayerData*> res;

	for (multimap<_SheetIndexTypePlayerIDNameQualityLevel, int>::iterator itor = i_f.first; itor != i_f.second; itor++) {
		res.push_back (&data[itor->second]);
	}

	return (res);
}
vector<SheetPlayerData*> SheetPlayer::findByIDNameQuality (int _ID,string _Name,int _Quality)
{
	pair<multimap<_SheetIndexTypePlayerIDNameQuality, int>::iterator, multimap<_SheetIndexTypePlayerIDNameQuality, int>::iterator> i_f;
	i_f = index_ID_Name_Quality.equal_range (_SheetIndexTypePlayerIDNameQuality(_ID,_Name,_Quality));
	vector<SheetPlayerData*> res;

	for (multimap<_SheetIndexTypePlayerIDNameQuality, int>::iterator itor = i_f.first; itor != i_f.second; itor++) {
		res.push_back (&data[itor->second]);
	}

	return (res);
}
vector<SheetPlayerData*> SheetPlayer::findByIDName (int _ID,string _Name)
{
	pair<multimap<_SheetIndexTypePlayerIDName, int>::iterator, multimap<_SheetIndexTypePlayerIDName, int>::iterator> i_f;
	i_f = index_ID_Name.equal_range (_SheetIndexTypePlayerIDName(_ID,_Name));
	vector<SheetPlayerData*> res;

	for (multimap<_SheetIndexTypePlayerIDName, int>::iterator itor = i_f.first; itor != i_f.second; itor++) {
		res.push_back (&data[itor->second]);
	}

	return (res);
}
SheetMonsterData::SheetMonsterData ()
{
	ID = 0;
	MonsterID = 0;
	MonsterName = "";
	MonsterQuality = 0;
	MonsterLevel = 0;
}

SheetMonsterData* SheetMonster::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetMonsterData*> SheetMonster::getAll ()
{
	vector<SheetMonsterData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetMonster::init ()
{
	FILE *fp;
	fp = fopen ("./Monster.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "Monster.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "Monster.txt";
	vector<SheetMonsterData> d;
	while (1) {
		SheetMonsterData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MonsterID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MonsterName = value;
		SheetUtils::readToken (fp, value);
		oneData.MonsterQuality = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.MonsterLevel = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetMonsterData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i];

	if (fp) fclose (fp);

	return (0);
}

int SheetMonster::initLink ()
{
	return (0);
}

SheetMonsterData* SheetMonster::tryFindByID (int _ID)
{
	map<int, int>::iterator itor = index_ID.find (_ID);
	if (itor != index_ID.end()) {
		return (&data[itor->second]);
	}
	else {
		return (NULL);
	}
}

SheetMonsterData* SheetMonster::findByID (int _ID)
{
	SheetMonsterData* retVal = tryFindByID (_ID);
	if (NULL == retVal)
		cout << "Sheet [Monster] Key [" << _ID << "] not exists\n";
	return (retVal);
}

vector<SheetMonsterData*> SheetMonster::findByMonsterID (int _MonsterID)
{
	pair<multimap<int, int>::iterator, multimap<int, int>::iterator> i_f;
	i_f = index_MonsterID.equal_range (_MonsterID);
	vector<SheetMonsterData*> res;

	for (multimap<int, int>::iterator itor = i_f.first; itor != i_f.second; itor++) {
		res.push_back (&data[itor->second]);
	}

	return (res);
}
void SheetMonster::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetMonster" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetMonster" << "[" << i << "] :: data." << "MonsterID" << " = " << data[i].MonsterID << endl;
		cout << "SheetMonster" << "[" << i << "] :: data." << "MonsterName" << " = " << data[i].MonsterName << endl;
		cout << "SheetMonster" << "[" << i << "] :: data." << "MonsterQuality" << " = " << data[i].MonsterQuality << endl;
		cout << "SheetMonster" << "[" << i << "] :: data." << "MonsterLevel" << " = " << data[i].MonsterLevel << endl;
	}
}
int SheetUtils::initSheets ()
{
	shTest = new SheetTest;
	if (shTest->init() != 0) return (-1);
	if (shTest->initLink() != 0) return (-1);
	shTest2 = new SheetTest2;
	if (shTest2->init() != 0) return (-1);
	if (shTest2->initLink() != 0) return (-1);
	shPlayer = new SheetPlayer;
	if (shPlayer->init() != 0) return (-1);
	if (shPlayer->initLink() != 0) return (-1);
	shMonster = new SheetMonster;
	if (shMonster->init() != 0) return (-1);
	if (shMonster->initLink() != 0) return (-1);
	return (0);
}
