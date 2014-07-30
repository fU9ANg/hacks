

#include "SheetBase.h"
#include "Sheet.h"

using namespace std;


SheetTest* shTest = NULL;
SheetTest2* shTest2 = NULL;
SheetPlayer* shPlayer = NULL;
SheetMonster* shMonster = NULL;
SheetNPC* shNPC = NULL;
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
		data[i] = d[i]; // SheetTest

	for (int i=0; i<row_num; i++) {
		if (!index_Type_Name.insert ( 
			std::pair <_SheetIndexTypeTestTypeName, int> (_SheetIndexTypeTestTypeName (d[i].Type,d[i].Name), d[i]._row_id)).second) {
				printf ("Index repeat Sheet[Test](Type=%d,Name=%s)",
					d[i].Type,d[i].Name.c_str());
		}
		if (!index_ID.insert (std::pair<int, int> (d[i].ID, d[i]._row_id)).second) {
			printf ("Index repeat Sheet[Test] (ID=%d)", d[i].ID);
		}
	}
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
SheetTestData* SheetTest::tryFindByTypeName (int _Type,string _Name)
{
	map<_SheetIndexTypeTestTypeName, int>::iterator itor;
	itor = index_Type_Name.find (_SheetIndexTypeTestTypeName(_Type,_Name));
	if (itor != index_Type_Name.end ()) {
		return (&data[itor->second]);
	}
	else {
		return (NULL);
	}
}

SheetTestData* SheetTest::findByTypeName (int _Type,string _Name)
{
	SheetTestData* retVal = tryFindByTypeName (_Type,_Name);
	if (NULL == retVal)
		printf ("Sheet [Test] Key [Type_Name] not exists (%d,%s)", _Type,_Name.c_str());
	return (retVal);
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
		data[i] = d[i]; // SheetTest2

	for (int i=0; i<row_num; i++) {
		if (!index_ID2_Type2.insert ( 
			std::pair <_SheetIndexTypeTest2ID2Type2, int> (_SheetIndexTypeTest2ID2Type2 (d[i].ID2,d[i].Type2), d[i]._row_id)).second) {
				printf ("Index repeat Sheet[Test2](ID2=%d,Type2=%d)",
					d[i].ID2,d[i].Type2);
		}
		if (!index_ID2_Name2.insert ( 
			std::pair <_SheetIndexTypeTest2ID2Name2, int> (_SheetIndexTypeTest2ID2Name2 (d[i].ID2,d[i].Name2), d[i]._row_id)).second) {
				printf ("Index repeat Sheet[Test2](ID2=%d,Name2=%s)",
					d[i].ID2,d[i].Name2.c_str());
		}
	}
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
SheetTest2Data* SheetTest2::tryFindByID2Name2 (int _ID2,string _Name2)
{
	map<_SheetIndexTypeTest2ID2Name2, int>::iterator itor;
	itor = index_ID2_Name2.find (_SheetIndexTypeTest2ID2Name2(_ID2,_Name2));
	if (itor != index_ID2_Name2.end ()) {
		return (&data[itor->second]);
	}
	else {
		return (NULL);
	}
}

SheetTest2Data* SheetTest2::findByID2Name2 (int _ID2,string _Name2)
{
	SheetTest2Data* retVal = tryFindByID2Name2 (_ID2,_Name2);
	if (NULL == retVal)
		printf ("Sheet [Test2] Key [ID2_Name2] not exists (%d,%s)", _ID2,_Name2.c_str());
	return (retVal);
}
SheetTest2Data* SheetTest2::tryFindByID2Type2 (int _ID2,int _Type2)
{
	map<_SheetIndexTypeTest2ID2Type2, int>::iterator itor;
	itor = index_ID2_Type2.find (_SheetIndexTypeTest2ID2Type2(_ID2,_Type2));
	if (itor != index_ID2_Type2.end ()) {
		return (&data[itor->second]);
	}
	else {
		return (NULL);
	}
}

SheetTest2Data* SheetTest2::findByID2Type2 (int _ID2,int _Type2)
{
	SheetTest2Data* retVal = tryFindByID2Type2 (_ID2,_Type2);
	if (NULL == retVal)
		printf ("Sheet [Test2] Key [ID2_Type2] not exists (%d,%d)", _ID2,_Type2);
	return (retVal);
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
		data[i] = d[i]; // SheetPlayer

	for (int i=0; i<row_num; i++) {
		if (!index_ID.insert (std::pair<int, int> (d[i].ID, d[i]._row_id)).second) {
			printf ("Index repeat Sheet[Player] (ID=%d)", d[i].ID);
		}
		if (!index_ID_Name.insert ( 
			std::pair <_SheetIndexTypePlayerIDName, int> (_SheetIndexTypePlayerIDName (d[i].ID,d[i].Name), d[i]._row_id)).second) {
				printf ("Index repeat Sheet[Player](ID=%d,Name=%s)",
					d[i].ID,d[i].Name.c_str());
		}
		index_Name_Level.insert ( 
			std::pair <_SheetIndexTypePlayerNameLevel, int> 				(_SheetIndexTypePlayerNameLevel (d[i].Name,d[i].Level), d[i]._row_id));
	}
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
vector<SheetPlayerData*> SheetPlayer::findByNameLevel (string _Name,int _Level)
{
	pair<multimap<_SheetIndexTypePlayerNameLevel, int>::iterator, multimap<_SheetIndexTypePlayerNameLevel, int>::iterator> i_f;
	i_f = index_Name_Level.equal_range (_SheetIndexTypePlayerNameLevel(_Name,_Level));
	vector<SheetPlayerData*> res;

	for (multimap<_SheetIndexTypePlayerNameLevel, int>::iterator itor = i_f.first; itor != i_f.second; itor++) {
		res.push_back (&data[itor->second]);
	}

	return (res);
}
SheetPlayerData* SheetPlayer::tryFindByIDName (int _ID,string _Name)
{
	map<_SheetIndexTypePlayerIDName, int>::iterator itor;
	itor = index_ID_Name.find (_SheetIndexTypePlayerIDName(_ID,_Name));
	if (itor != index_ID_Name.end ()) {
		return (&data[itor->second]);
	}
	else {
		return (NULL);
	}
}

SheetPlayerData* SheetPlayer::findByIDName (int _ID,string _Name)
{
	SheetPlayerData* retVal = tryFindByIDName (_ID,_Name);
	if (NULL == retVal)
		printf ("Sheet [Player] Key [ID_Name] not exists (%d,%s)", _ID,_Name.c_str());
	return (retVal);
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
		data[i] = d[i]; // SheetMonster

	for (int i=0; i<row_num; i++) {
		if (!index_ID.insert (std::pair<int, int> (d[i].ID, d[i]._row_id)).second) {
			printf ("Index repeat Sheet[Monster] (ID=%d)", d[i].ID);
		}
		index_MonsterQuality_MonsterLevel.insert ( 
			std::pair <_SheetIndexTypeMonsterMonsterQualityMonsterLevel, int> 				(_SheetIndexTypeMonsterMonsterQualityMonsterLevel (d[i].MonsterQuality,d[i].MonsterLevel), d[i]._row_id));
	}
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
vector<SheetMonsterData*> SheetMonster::findByMonsterQualityMonsterLevel (int _MonsterQuality,int _MonsterLevel)
{
	pair<multimap<_SheetIndexTypeMonsterMonsterQualityMonsterLevel, int>::iterator, multimap<_SheetIndexTypeMonsterMonsterQualityMonsterLevel, int>::iterator> i_f;
	i_f = index_MonsterQuality_MonsterLevel.equal_range (_SheetIndexTypeMonsterMonsterQualityMonsterLevel(_MonsterQuality,_MonsterLevel));
	vector<SheetMonsterData*> res;

	for (multimap<_SheetIndexTypeMonsterMonsterQualityMonsterLevel, int>::iterator itor = i_f.first; itor != i_f.second; itor++) {
		res.push_back (&data[itor->second]);
	}

	return (res);
}
SheetNPCData::SheetNPCData ()
{
	ID = 0;
	NPCID = 0;
	NPCName = "";
	NPCQuality = 0;
	NPCPosX = 0;
	NPCPosY = 0;
	NPCPosZ = 0;
	NPCLevel = 0;
}

SheetNPCData* SheetNPC::getRow (int n)
{
	if (n<0 || n>row_num)
		return (NULL);
	else
		return (&data[n]);
}

vector<SheetNPCData*> SheetNPC::getAll ()
{
	vector<SheetNPCData*> res;
	for (int i=0; i<row_num; i++) {
		res.push_back (&data[i]);
	}

	return (res);
}

int SheetNPC::init ()
{
	FILE *fp;
	fp = fopen ("./NPC.txt", "rb");
	if (fp == NULL) {
		printf ("no sheet file [%s]\n", "NPC.txt");
		return (-1);
	}

	SheetUtils::skipBom (fp);
	string value = "";
	row_num = 0;
	name = "NPC.txt";
	vector<SheetNPCData> d;
	while (1) {
		SheetNPCData oneData;
		SheetUtils::readToken (fp, value);
		oneData.ID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.NPCID = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.NPCName = value;
		SheetUtils::readToken (fp, value);
		oneData.NPCQuality = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.NPCPosX = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.NPCPosY = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.NPCPosZ = atoi (value.c_str ());
		SheetUtils::readToken (fp, value);
		oneData.NPCLevel = atoi (value.c_str ());
		oneData._row_id = row_num++;
		d.push_back (oneData);
		if (!SheetUtils::skipChar (fp, '\n')) break;
	}

	data = new SheetNPCData[d.size()];
	for (size_t i=0; i<d.size(); i++)
		data[i] = d[i]; // SheetNPC

	for (int i=0; i<row_num; i++) {
		if (!index_ID.insert (std::pair<int, int> (d[i].ID, d[i]._row_id)).second) {
			printf ("Index repeat Sheet[NPC] (ID=%d)", d[i].ID);
		}
		index_NPCPosX_NPCPosY.insert ( 
			std::pair <_SheetIndexTypeNPCNPCPosXNPCPosY, int> 				(_SheetIndexTypeNPCNPCPosXNPCPosY (d[i].NPCPosX,d[i].NPCPosY), d[i]._row_id));
	}
	if (fp) fclose (fp);

	return (0);
}

int SheetNPC::initLink ()
{
	return (0);
}

SheetNPCData* SheetNPC::tryFindByID (int _ID)
{
	map<int, int>::iterator itor = index_ID.find (_ID);
	if (itor != index_ID.end()) {
		return (&data[itor->second]);
	}
	else {
		return (NULL);
	}
}

SheetNPCData* SheetNPC::findByID (int _ID)
{
	SheetNPCData* retVal = tryFindByID (_ID);
	if (NULL == retVal)
		cout << "Sheet [NPC] Key [" << _ID << "] not exists\n";
	return (retVal);
}

void SheetNPC::dump ()
{
	for (int i=0; i<row_num; i++) {
		cout << "SheetNPC" << "[" << i << "] :: data." << "ID" << " = " << data[i].ID << endl;
		cout << "SheetNPC" << "[" << i << "] :: data." << "NPCID" << " = " << data[i].NPCID << endl;
		cout << "SheetNPC" << "[" << i << "] :: data." << "NPCName" << " = " << data[i].NPCName << endl;
		cout << "SheetNPC" << "[" << i << "] :: data." << "NPCQuality" << " = " << data[i].NPCQuality << endl;
		cout << "SheetNPC" << "[" << i << "] :: data." << "NPCPosX" << " = " << data[i].NPCPosX << endl;
		cout << "SheetNPC" << "[" << i << "] :: data." << "NPCPosY" << " = " << data[i].NPCPosY << endl;
		cout << "SheetNPC" << "[" << i << "] :: data." << "NPCPosZ" << " = " << data[i].NPCPosZ << endl;
		cout << "SheetNPC" << "[" << i << "] :: data." << "NPCLevel" << " = " << data[i].NPCLevel << endl;
	}
}
vector<SheetNPCData*> SheetNPC::findByNPCPosXNPCPosY (int _NPCPosX,int _NPCPosY)
{
	pair<multimap<_SheetIndexTypeNPCNPCPosXNPCPosY, int>::iterator, multimap<_SheetIndexTypeNPCNPCPosXNPCPosY, int>::iterator> i_f;
	i_f = index_NPCPosX_NPCPosY.equal_range (_SheetIndexTypeNPCNPCPosXNPCPosY(_NPCPosX,_NPCPosY));
	vector<SheetNPCData*> res;

	for (multimap<_SheetIndexTypeNPCNPCPosXNPCPosY, int>::iterator itor = i_f.first; itor != i_f.second; itor++) {
		res.push_back (&data[itor->second]);
	}

	return (res);
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
	shNPC = new SheetNPC;
	if (shNPC->init() != 0) return (-1);
	if (shNPC->initLink() != 0) return (-1);
	return (0);
}
