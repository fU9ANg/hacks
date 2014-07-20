
#ifndef __SHEET_H__
#define __SHEET_H__

#include "SheetBase.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;
class SheetTestData : public SheetBaseData
{
public:
	int ID;	//ID
	int Type;	//编号
	string Name;	//名称
	SheetTestData ();
};

class SheetTest : public SheetBase
{
private:
	SheetTestData *data;
	std::map<int, int> index_ID;
public:
	vector<SheetTestData*> getAll ();
	SheetTestData* getRow (int n);
	bool forEach (SheetTestData& item);
	virtual int init ();
	virtual int initLink ();
	SheetTestData* findByID (int _ID);
	SheetTestData* tryFindByID (int _ID);
	void dump (void);
};
extern SheetTest* shTest;
class SheetTest2Data : public SheetBaseData
{
public:
	int ID2;	//ID
	int Type2;	//编号
	string Name2;	//名称
	SheetTest2Data ();
};

class SheetTest2 : public SheetBase
{
private:
	SheetTest2Data *data;
public:
	vector<SheetTest2Data*> getAll ();
	SheetTest2Data* getRow (int n);
	bool forEach (SheetTest2Data& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetTest2* shTest2;
class SheetPlayerData : public SheetBaseData
{
public:
	int ID;	//ID
	string Name;	//名称
	int Quality;	//品质
	int Level;	//等级
	SheetPlayerData ();
};

class SheetPlayer : public SheetBase
{
private:
	SheetPlayerData *data;
public:
	vector<SheetPlayerData*> getAll ();
	SheetPlayerData* getRow (int n);
	bool forEach (SheetPlayerData& item);
	virtual int init ();
	virtual int initLink ();
	void dump (void);
};
extern SheetPlayer* shPlayer;
class SheetMonsterData : public SheetBaseData
{
public:
	int ID;	//怪物表ID
	string MonsterName;	//怪物表名称
	int MonsterQuality;	//怪物表品质
	int MonsterLevel;	//怪物表等级
	SheetMonsterData ();
};

class SheetMonster : public SheetBase
{
private:
	SheetMonsterData *data;
	std::map<int, int> index_ID;
public:
	vector<SheetMonsterData*> getAll ();
	SheetMonsterData* getRow (int n);
	bool forEach (SheetMonsterData& item);
	virtual int init ();
	virtual int initLink ();
	SheetMonsterData* findByID (int _ID);
	SheetMonsterData* tryFindByID (int _ID);
	void dump (void);
};
extern SheetMonster* shMonster;
#endif // __SHEET_H__
